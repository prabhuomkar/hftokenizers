#include "replace.h"
#include <iostream>
#include <string>
#include <regex>

Replace::Replace(std::string& pattern, std::string& content) : pattern(pattern), content(content) {}

void Replace::normalize(std::string& input) {
    std::regex regexPattern(pattern);
    input = std::regex_replace(input, regexPattern, content);
    std::cout << input << '\n';
}
