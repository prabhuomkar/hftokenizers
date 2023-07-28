#include "prepend.h"
#include <iostream>
#include <string>
#include <regex>

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
  std::wcout << normalizedInput << std::endl;
}
