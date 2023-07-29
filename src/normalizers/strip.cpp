// Copyright 2023 Omkar Prabhu
#include <unicode/uchar.h>
#include <unicode/putil.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "hftokenizers/normalizers/strip.h"

hftokenizers::normalizers::Strip::Strip(bool stripLeft, bool stripRight) :
                                        stripLeft(stripLeft), stripRight(stripRight) {}

void hftokenizers::normalizers::Strip::stripWhitespaces(std::wstring& str, bool stripLeft) {
  if (stripLeft) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
      return !std::isspace(ch);
    }));
  } else {
    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
      return !std::isspace(ch);
    }).base(), str.end());
  }
}

void hftokenizers::normalizers::Strip::normalize(hftokenizers::tokenizer::NormalizedString& input) {
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

hftokenizers::normalizers::StripAccents::StripAccents() {}

bool hftokenizers::normalizers::StripAccents::isCombiningMark(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  int32_t combiningClass = u_getCombiningClass(uChar32);
  return combiningClass > 0;
}

void hftokenizers::normalizers::StripAccents::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput;
  for (wchar_t c : input.getNormalized()) {
    if (!isCombiningMark(c)) {
      normalizedInput += c;
    }
  }
  input.setNormalized(normalizedInput);
}
