// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/normalizers/replace.h"

#include <iostream>
#include <regex>
#include <string>

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

Replace::Replace(std::wstring& pattern, std::wstring& content) : pattern(pattern), content(content) {}

void Replace::normalize(NormalizedString& input) {
  std::wregex regex_pattern(pattern);
  std::wstring normalized_input = std::regex_replace(input.get_normalized(), regex_pattern, content);
  input.set_normalized(normalized_input);
}
