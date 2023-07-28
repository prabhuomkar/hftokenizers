#include "strip.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <unicode/uchar.h>
#include <unicode/putil.h>

hftokenizers::normalizers::Strip::Strip(bool stripLeft, bool stripRight) : stripLeft(stripLeft), stripRight(stripRight) {}

void hftokenizers::normalizers::Strip::stripWhitespaces(std::string& str, bool stripLeft) {
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

void hftokenizers::normalizers::Strip::normalize(std::string& input) {
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
  std::cout << input << '\n';
}

hftokenizers::normalizers::StripAccents::StripAccents() {}

bool hftokenizers::normalizers::StripAccents::isCombiningMark(char c) {
  UChar uChar;
  u_charsToUChars(&c, &uChar, 1);
  int32_t combiningClass = u_getCombiningClass(uChar);
  return combiningClass > 0;
}

void hftokenizers::normalizers::StripAccents::normalize(std::string& input) {
  std::string normalizedInput;
  for (char c: input) {
    if (!isCombiningMark(c)) {
      normalizedInput += c;
    }
  }
  std::cout << normalizedInput << '\n';
}
