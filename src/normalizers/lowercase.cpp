#include "lowercase.h"
#include <iostream>
#include <string>
#include <codecvt>

hftokenizers::normalizers::Lowercase::Lowercase() {}

void hftokenizers::normalizers::Lowercase::normalize(std::wstring& input) {
  for (int i = 0; i < input.length(); i++) {
    input[i] = tolower(input[i]);
  }
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(input);
  std::cout << sNormalizedInput << std::endl;
}
