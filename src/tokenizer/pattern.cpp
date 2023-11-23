// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/pattern.h"

#include <codecvt>
#include <functional>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <vector>

using namespace hftokenizers::tokenizer;

CharPattern::CharPattern(wchar_t ch) : ch(ch) {}

std::vector<std::pair<std::pair<int, int>, bool>> CharPattern::find_matches(const std::wstring& inside,
                                                                            std::function<bool(wchar_t)> predicate) {
  std::vector<std::pair<std::pair<int, int>, bool>> matches;
  int start = 0, end = 0;
  while (start < inside.size()) {
    end = start;
    while (end < inside.size() && !predicate(inside[end])) {
      ++end;
    }
    if (start != end) {
      matches.emplace_back(std::make_pair(std::make_pair(start, end), false));
      start = end;
    } else {
      matches.emplace_back(std::make_pair(std::make_pair(start, end), true));
      ++start;
    }
  }
  return matches;
}

std::vector<std::pair<std::pair<int, int>, bool>> CharPattern::find_matches(const std::wstring& inside) {
  auto is_char = [this](wchar_t c) -> bool { return c == ch; };
  return find_matches(inside, is_char);
}

RegexPattern::RegexPattern(std::wregex regex, bool invert) : regex(regex), invert(invert) {}

std::vector<std::pair<std::pair<int, int>, bool>> RegexPattern::find_matches(const std::wstring& inside) {
  std::vector<std::pair<std::pair<int, int>, bool>> matches;
  if (inside.empty()) {
    matches.emplace_back(std::make_pair(std::make_pair(0, 0), false));
    return matches;
  }
  int prev = 0;
  for (std::wsregex_iterator it = std::wsregex_iterator(inside.begin(), inside.end(), regex);
       it != std::wsregex_iterator(); ++it) {
    int start = it->position();
    int end = it->position() + it->length();
    if (prev != start) {
      matches.emplace_back(std::make_pair(std::make_pair(prev, start), invert ? true : false));
    }
    matches.emplace_back(std::make_pair(std::make_pair(start, end), invert ? false : true));
    prev = end - 1;
  }
  if (prev != inside.size()) {
    matches.emplace_back(std::make_pair(std::make_pair(prev, inside.size()), invert ? true : false));
  }
  return matches;
}
