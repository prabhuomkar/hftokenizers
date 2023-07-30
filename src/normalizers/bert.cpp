// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/bert.h"

#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/normalizers/unicode.h"
#include "hftokenizers/normalizers/utils.h"

hftokenizers::normalizers::BertNormalizer::BertNormalizer(bool cleanText, bool handleChineseChars, bool stripAccents,
                                                          bool lowercase)
    : cleanText(cleanText), handleChineseChars(handleChineseChars), stripAccents(stripAccents), lowercase(lowercase) {}

bool isWhitespace(wchar_t c) {
  switch (c) {
    case L'\t':
    case L'\n':
    case L'\r':
      return true;
    default:
      return std::iswspace(c);
  }
}

bool isControl(wchar_t c) {
  switch (c) {
    case L'\t':
    case L'\n':
    case L'\r':
      return false;
    default:
      return std::iswcntrl(c);
  }
}

bool isChineseChar(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  return (uChar32 >= 0x4E00 && uChar32 <= 0x9FFF) || (uChar32 >= 0x3400 && uChar32 <= 0x4DBF) ||
         (uChar32 >= 0x20000 && uChar32 <= 0x2A6DF) || (uChar32 >= 0x2A700 && uChar32 <= 0x2B73F) ||
         (uChar32 >= 0x2B740 && uChar32 <= 0x2B81F) || (uChar32 >= 0x2B920 && uChar32 <= 0x2CEAF) ||
         (uChar32 >= 0xF900 && uChar32 <= 0xFAFF) || (uChar32 >= 0x2F800 && uChar32 <= 0x2FA1F);
}

void hftokenizers::normalizers::BertNormalizer::doCleanText(hftokenizers::tokenizer::NormalizedString &input) {
  input.getNormalized().erase(std::remove_if(input.getNormalized().begin(), input.getNormalized().end(),
                                             [](wchar_t c) { return c == L'\0' || c == L'\uFFFD' || isControl(c); }),
                              input.getNormalized().end());
  std::transform(input.getNormalized().begin(), input.getNormalized().end(), input.getNormalized().begin(),
                 [](wchar_t c) { return isWhitespace(c) ? ' ' : c; });
}

void hftokenizers::normalizers::BertNormalizer::doHandleChineseChars(hftokenizers::tokenizer::NormalizedString &input) {
  std::vector<std::pair<wchar_t, int>> newChars;
  for (wchar_t c : input.getNormalized()) {
    if (isChineseChar(c)) {
      newChars.emplace_back(L' ', 0);
      newChars.emplace_back(c, 1);
      newChars.emplace_back(L' ', 1);
    } else {
      newChars.emplace_back(c, 0);
    }
  }
  size_t i = 0;
  for (const auto &change : newChars) {
    if (change.second > 0) {
      input.getNormalized().insert(i, 1, change.first);
    } else if (change.second < 0) {
      i += change.second;
      input.getNormalized().insert(i, 1, change.first);
    } else {
      input.getNormalized()[i] = change.first;
    }
    i++;
  }
}

void hftokenizers::normalizers::BertNormalizer::normalize(hftokenizers::tokenizer::NormalizedString &input) {
  if (cleanText) {
    doCleanText(input);
  }
  if (handleChineseChars) {
    doHandleChineseChars(input);
  }
  if (stripAccents) {
    hftokenizers::normalizers::NFD nfd;
    nfd.normalize(input);
    std::wstring normalizedInput;
    for (wchar_t c : input.getNormalized()) {
      UChar32 uChar32 = static_cast<UChar32>(c);
      if (u_charType(c) != U_NON_SPACING_MARK) {
        normalizedInput += c;
      }
    }
    input.setNormalized(normalizedInput);
  }
  if (lowercase) {
    hftokenizers::normalizers::Lowercase lowercase;
    lowercase.normalize(input);
  }
}
