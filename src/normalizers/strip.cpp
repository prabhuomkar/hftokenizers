// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/strip.h"

#include <unicode/putil.h>
#include <unicode/uchar.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

Strip::Strip(bool strip_left, bool strip_right) : strip_left(strip_left), strip_right(strip_right) {}

void Strip::strip_whitespaces(std::wstring& str, bool strip_left) {
  if (strip_left) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) { return !std::iswspace(ch); }));
  } else {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !std::iswspace(ch); }).base(),
              str.end());
  }
}

void Strip::normalize(NormalizedString& input) {
  if (strip_left && strip_right) {
    strip_whitespaces(input.get_normalized(), true);
    strip_whitespaces(input.get_normalized(), false);
  } else {
    if (strip_left) {
      strip_whitespaces(input.get_normalized(), true);
    }
    if (strip_right) {
      strip_whitespaces(input.get_normalized(), false);
    }
  }
}

StripAccents::StripAccents() {}

bool StripAccents::is_combining_mark(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  int32_t combiningClass = u_getCombiningClass(uChar32);
  return combiningClass > 0;
}

void StripAccents::normalize(NormalizedString& input) {
  std::wstring normalizedInput;
  for (wchar_t c : input.get_normalized()) {
    if (!is_combining_mark(c)) {
      normalizedInput += c;
    }
  }
  input.set_normalized(normalizedInput);
}
