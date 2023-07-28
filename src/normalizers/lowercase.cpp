#include "lowercase.h"
#include <iostream>
#include <string>

hftokenizers::normalizers::Lowercase::Lowercase() {}

void hftokenizers::normalizers::Lowercase::normalize(std::wstring& input) {
  for (int i = 0; i < input.length(); i++) {
    input[i] = tolower(input[i]);
  }
  std::wcout << input << std::endl;
}
