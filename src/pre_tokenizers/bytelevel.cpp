// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/bytelevel.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

ByteLevel::ByteLevel(bool add_prefix_space, bool use_regex)
    : add_prefix_space(add_prefix_space), use_regex(use_regex) {}

std::unordered_map<int, char> ByteLevel::bytes_char() {
  std::vector<int> bs;
  bs.reserve(128);
  for (int i = '!'; i <= '~'; ++i) {
    bs.push_back(i);
  }
  for (int i = 0xA1; i <= 0xAC; ++i) {
    bs.push_back(i);
  }
  for (int i = 0xAE; i <= 0xFF; ++i) {
    bs.push_back(i);
  }
  std::unordered_map<int, char> result;
  std::vector<int> cs;
  cs.reserve(bs.size());
  int n = 0;
  for (int b = 0; b <= 255; ++b) {
    auto it = std::find(bs.begin(), bs.end(), b);
    if (it == bs.end()) {
      bs.push_back(b);
      cs.push_back(std::pow(2, 8) + n);
      n += 1;
    }
  }
  for (size_t i = 0; i < bs.size(); ++i) {
    result[bs[i]] = static_cast<char>(cs[i]);
  }
  return result;
}

void ByteLevel::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    RegexPattern pattern =
        RegexPattern(L"'s|'t|'re|'ve|'m|'ll|'d| ?[\\pL]+| ?[\\pN]+| ?[^\\s\\pL\\pN]+|\\s+(?!\\S)|\\s+", true);
    if (normalized.get_normalized()[0] != L' ') {
      std::wstring space = std::wstring(1, L' ');
      normalized.prepend(space);
    }
    if (use_regex) {
      return normalized.split(pattern, SplitDelimiterBehavior::Isolated);
    }
    std::vector<NormalizedString> result = {normalized};
    return result;
  });
  // TODO(omkar)
}
