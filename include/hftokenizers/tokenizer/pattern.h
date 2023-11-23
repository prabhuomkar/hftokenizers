// Copyright 2023 Omkar Prabhu
#pragma once

#include <functional>
#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace hftokenizers {

namespace tokenizer {

class Pattern {
 public:
  virtual ~Pattern() {}
  virtual std::vector<std::pair<std::pair<int, int>, bool>> find_matches(const std::wstring& inside) = 0;
};

class CharPattern : public Pattern {
 public:
  explicit CharPattern(wchar_t ch);
  std::vector<std::pair<std::pair<int, int>, bool>> find_matches(const std::wstring& inside);

 private:
  wchar_t ch;
  std::vector<std::pair<std::pair<int, int>, bool>> find_matches(const std::wstring& inside,
                                                                 std::function<bool(wchar_t)> predicate);
};

class RegexPattern : public Pattern {
 public:
  explicit RegexPattern(std::wregex regex, bool invert = false);
  std::vector<std::pair<std::pair<int, int>, bool>> find_matches(const std::wstring& inside);

 private:
  std::wregex regex;
  bool invert;
};

class PredicatePattern : public Pattern {
 public:
  explicit PredicatePattern(std::function<bool(wchar_t)> predicate);
  std::vector<std::pair<std::pair<int, int>, bool>> find_matches(const std::wstring& inside);

 private:
  std::function<bool(wchar_t)> predicate;
};

}   // namespace tokenizer

}   // namespace hftokenizers
