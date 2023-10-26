// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/prepend.h"

#include <iostream>
#include <regex>
#include <string>

using namespace hftokenizers::tokenizer;
using namespace hftokenizers::normalizers;

Prepend::Prepend(std::wstring& prepend) : prepend(prepend) {}

void Prepend::normalize(NormalizedString& input) {
  std::wstring normalized_input;
  std::wstring currentWord;
  int startPos = 0;
  int endPos = 0;
  while (endPos != std::wstring::npos) {
    endPos = input.get_normalized().find(L' ', startPos);
    if (endPos == std::wstring::npos) {
      currentWord = input.get_normalized().substr(startPos);
    } else {
      currentWord = input.get_normalized().substr(startPos, endPos - startPos);
    }
    normalized_input += prepend + currentWord + L" ";
    startPos = endPos + 1;
  }
  input.set_normalized(normalized_input);
}
