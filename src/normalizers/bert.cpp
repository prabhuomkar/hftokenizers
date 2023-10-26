// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/bert.h"

#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

BertNormalizer::BertNormalizer(bool clean_text, bool handle_chinese_chars, bool strip_accents, bool lowercase)
    : clean_text(clean_text),
      handle_chinese_chars(handle_chinese_chars),
      strip_accents(strip_accents),
      lowercase(lowercase) {}

bool is_whitespace(wchar_t c) {
  switch (c) {
    case L'\t':
    case L'\n':
    case L'\r':
      return true;
    default:
      return std::iswspace(c);
  }
}

bool is_control(wchar_t c) {
  switch (c) {
    case L'\t':
    case L'\n':
    case L'\r':
      return false;
    default:
      return std::iswcntrl(c);
  }
}

bool is_chinese_char(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  return (uChar32 >= 0x4E00 && uChar32 <= 0x9FFF) || (uChar32 >= 0x3400 && uChar32 <= 0x4DBF) ||
         (uChar32 >= 0x20000 && uChar32 <= 0x2A6DF) || (uChar32 >= 0x2A700 && uChar32 <= 0x2B73F) ||
         (uChar32 >= 0x2B740 && uChar32 <= 0x2B81F) || (uChar32 >= 0x2B920 && uChar32 <= 0x2CEAF) ||
         (uChar32 >= 0xF900 && uChar32 <= 0xFAFF) || (uChar32 >= 0x2F800 && uChar32 <= 0x2FA1F);
}

void BertNormalizer::do_clean_text(NormalizedString &input) {
  input.get_normalized().erase(std::remove_if(input.get_normalized().begin(), input.get_normalized().end(),
                                              [](wchar_t c) { return c == L'\0' || c == L'\uFFFD' || is_control(c); }),
                               input.get_normalized().end());
  std::transform(input.get_normalized().begin(), input.get_normalized().end(), input.get_normalized().begin(),
                 [](wchar_t c) { return is_whitespace(c) ? ' ' : c; });
}

void BertNormalizer::do_handle_chinese_chars(NormalizedString &input) {
  std::vector<std::pair<wchar_t, int>> new_chars;
  for (wchar_t c : input.get_normalized()) {
    if (is_chinese_char(c)) {
      new_chars.emplace_back(L' ', 0);
      new_chars.emplace_back(c, 1);
      new_chars.emplace_back(L' ', 1);
    } else {
      new_chars.emplace_back(c, 0);
    }
  }
  int i = 0;
  for (const auto &change : new_chars) {
    if (change.second > 0) {
      input.get_normalized().insert(i, 1, change.first);
    } else if (change.second < 0) {
      i += change.second;
      input.get_normalized().insert(i, 1, change.first);
    } else {
      input.get_normalized()[i] = change.first;
    }
    i++;
  }
}

void BertNormalizer::normalize(NormalizedString &input) {
  if (clean_text) {
    do_clean_text(input);
  }
  if (handle_chinese_chars) {
    do_handle_chinese_chars(input);
  }
  if (strip_accents) {
    input.nfd();
    std::wstring normalized_input;
    for (wchar_t c : input.get_normalized()) {
      UChar32 uChar32 = static_cast<UChar32>(c);
      if (u_charType(c) != U_NON_SPACING_MARK) {
        normalized_input += c;
      }
    }
    input.set_normalized(normalized_input);
  }
  if (lowercase) {
    input.lowercase();
  }
}
