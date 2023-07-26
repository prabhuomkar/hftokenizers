#include "prepend.h"
#include <iostream>
#include <string>
#include <regex>

Prepend::Prepend(std::string& prepend) : prepend(prepend) {}

void Prepend::normalize(std::string& input) {
    if (!input.empty()) {
        input.insert(0, prepend);
    }
    std::cout << input << '\n';
}
