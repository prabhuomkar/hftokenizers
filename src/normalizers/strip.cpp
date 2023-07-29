// Copyright 2023 Omkar Prabhu
#include <unicode/uchar.h>
#include <unicode/putil.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <codecvt>
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

void hftokenizers::normalizers::Strip::normalize(std::wstring& input) {
  if (stripLeft && stripRight) {
    stripWhitespaces(input, true);
    stripWhitespaces(input, false);
  } else {
    if (stripLeft) {
      stripWhitespaces(input, true);
    }
    if (stripRight) {
      stripWhitespaces(input, false);
    }
  }
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(input);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::StripAccents::StripAccents() {}

bool hftokenizers::normalizers::StripAccents::isCombiningMark(wchar_t c) {
  UChar32 uChar32 = static_cast<UChar32>(c);
  int32_t combiningClass = u_getCombiningClass(uChar32);
  return combiningClass > 0;
}

void hftokenizers::normalizers::StripAccents::normalize(std::wstring& input) {
  std::wstring normalizedInput;
  for (wchar_t c : input) {
    if (!isCombiningMark(c)) {
      normalizedInput += c;
    }
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}
