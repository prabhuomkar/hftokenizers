// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/replace.h"

#include <iostream>
#include <regex>
#include <string>

hftokenizers::normalizers::Replace::Replace(std::wstring& pattern, std::wstring& content)
    : pattern(pattern), content(content) {}

void hftokenizers::normalizers::Replace::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wregex regexPattern(pattern);
  std::wstring normalizedInput = std::regex_replace(input.getNormalized(), regexPattern, content);
  input.setNormalized(normalizedInput);
}
