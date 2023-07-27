#include "prepend.h"
#include <iostream>
#include <string>
#include <regex>

hftokenizers::normalizers::Prepend::Prepend(std::string& prepend) : prepend(prepend) {}

void hftokenizers::normalizers::Prepend::normalize(std::string& input) {
  std::string newInput = "";
  for (std::string::iterator it = input.begin(); it != input.end(); it++) {
    if (*it == ' ') {
      newInput += "_";
    }
    newInput += *it;
  }
  std::cout << newInput << '\n';
}
