// Copyright 2023 Omkar Prabhu
#include <iostream>
#include <string>
#include <regex>
#include <codecvt>
#include "hftokenizers/normalizers/prepend.h"

hftokenizers::normalizers::Prepend::Prepend(std::wstring& prepend) : prepend(prepend) {}

void hftokenizers::normalizers::Prepend::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput;
  std::wstring currentWord;
  size_t startPos = 0;
  size_t endPos = 0;
  while (endPos != std::wstring::npos) {
    endPos = input.getNormalized().find(L' ', startPos);
    if (endPos == std::wstring::npos) {
      currentWord = input.getNormalized().substr(startPos);
    } else {
      currentWord = input.getNormalized().substr(startPos, endPos - startPos);
    }
    normalizedInput += prepend + currentWord + L" ";
    startPos = endPos + 1;
  }
  input.setNormalized(normalizedInput);
}
