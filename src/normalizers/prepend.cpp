// Copyright 2023 Omkar Prabhu
#include <iostream>
#include <string>
#include <regex>
#include <codecvt>
#include "hftokenizers/normalizers/prepend.h"

hftokenizers::normalizers::Prepend::Prepend(std::wstring& prepend) : prepend(prepend) {}

void hftokenizers::normalizers::Prepend::normalize(std::wstring& input) {
  std::wstring normalizedInput;
  std::wstring currentWord;
  size_t startPos = 0;
  size_t endPos = 0;
  while (endPos != std::wstring::npos) {
    endPos = input.find(L' ', startPos);
    if (endPos == std::wstring::npos) {
      currentWord = input.substr(startPos);
    } else {
      currentWord = input.substr(startPos, endPos - startPos);
    }
    normalizedInput += prepend + currentWord + L" ";
    startPos = endPos + 1;
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}
