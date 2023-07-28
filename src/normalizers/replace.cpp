#include "replace.h"
#include <iostream>
#include <string>
#include <regex>

hftokenizers::normalizers::Replace::Replace(std::wstring& pattern, std::wstring& content) : pattern(pattern), content(content) {}

void hftokenizers::normalizers::Replace::normalize(std::wstring& input) {
  std::wregex regexPattern(pattern);
  input = std::regex_replace(input, regexPattern, content);
  std::wcout << input << std::endl;
}
