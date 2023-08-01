// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/strip.h"

#include <unicode/putil.h>
#include <unicode/uchar.h>

#include <algorithm>
#include <iostream>
#include <string>

using namespace hftokenizers::tokenizer;
using namespace hftokenizers::normalizers;

Strip::Strip(bool stripLeft, bool stripRight) : stripLeft(stripLeft), stripRight(stripRight) {}

void Strip::stripWhitespaces(std::wstring& str, bool stripLeft) {
  if (stripLeft) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) { return !std::iswspace(ch); }));
  } else {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) { return !std::iswspace(ch); }).base(),
              str.end());
  }
}

void Strip::normalize(NormalizedString& input) {
  if (stripLeft && stripRight) {
    stripWhitespaces(input.getNormalized(), true);
    stripWhitespaces(input.getNormalized(), false);
  } else {
    if (stripLeft) {
      stripWhitespaces(input.getNormalized(), true);
    }
    if (stripRight) {
      stripWhitespaces(input.getNormalized(), false);
    }
  }
}

StripAccents::StripAccents() {}

bool StripAccents::isCombiningMark(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  int32_t combiningClass = u_getCombiningClass(uChar32);
  return combiningClass > 0;
}

void StripAccents::normalize(NormalizedString& input) {
  std::wstring normalizedInput;
  for (wchar_t c : input.getNormalized()) {
    if (!isCombiningMark(c)) {
      normalizedInput += c;
    }
  }
  input.setNormalized(normalizedInput);
}
