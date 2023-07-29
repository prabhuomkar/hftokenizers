// Copyright 2023 Omkar Prabhu
#include <iostream>
#include <string>
#include <regex>
#include <codecvt>
#include "hftokenizers/normalizers/replace.h"

hftokenizers::normalizers::Replace::Replace(std::wstring& pattern, std::wstring& content) :
                                            pattern(pattern), content(content) {}

void hftokenizers::normalizers::Replace::normalize(std::wstring& input) {
  std::wregex regexPattern(pattern);
  std::wstring normalizedInput = std::regex_replace(input, regexPattern, content);
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}
