#include "strip.h"
#include <iostream>
#include <string>
#include <algorithm>

Strip::Strip(bool stripLeft, bool stripRight) : stripLeft(stripLeft), stripRight(stripRight) {}

void Strip::normalize(std::string& input) {
    if (stripLeft && stripRight) {
        stripWhitespaces(input, true);
        stripWhitespaces(input, false);
    } else {
        if (stripLeft) stripWhitespaces(input, true);
        if (stripRight) stripWhitespaces(input, false);
    }
    std::cout << input << '\n';
}

void Strip::stripWhitespaces(std::string& str, bool stripLeft) {
    if (stripLeft) {
        str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
    } else {
        str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), str.end());
    }
}