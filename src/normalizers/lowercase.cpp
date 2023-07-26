#include "lowercase.h"
#include <iostream>
#include <string>

Lowercase::Lowercase() {}

void Lowercase::normalize(std::string& input) {
    for (int i = 0; i < input.length(); i++) {
        input[i] = tolower(input[i]);
    }
    std::cout << input << '\n';
}
