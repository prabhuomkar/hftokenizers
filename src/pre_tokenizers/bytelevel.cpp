// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/bytelevel.h"

#include <cmath>
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

std::unordered_map<uint8_t, char> ByteLevel::bytes_char() {
  std::vector<uint8_t> bs;
  bs.reserve(94);
  bs.insert(bs.end(), '!', '~' + 1);
  bs.insert(bs.end(), 0xA1, 0xAC + 1);
  bs.insert(bs.end(), static_cast<unsigned char>(0xAE), static_cast<unsigned char>(0xFF + 1));
  std::vector<uint32_t> cs;
  cs.reserve(bs.size());
  int n = 0;
  for (uint8_t b = 0; b <= 255; ++b) {
    if (std::find(bs.begin(), bs.end(), b) == bs.end()) {
      bs.push_back(b);
      cs.push_back(static_cast<uint32_t>(pow(2, 8) + n));
      n++;
    }
  }
  std::unordered_map<uint8_t, char> result;
  for (size_t i = 0; i < bs.size(); ++i) {
    result.emplace(bs[i], static_cast<char>(cs[i]));
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
  pre_tokenized.normalize([this](NormalizedString normalized) {
    auto BYTES_CHAR = bytes_char();
    auto s = normalized.get_normalized();
    std::vector<std::pair<wchar_t, int>> transformations;
    int i = 0;
    for (wchar_t cur_char : s) {
      int size;
      if (cur_char <= 0x7F) {
        size = 1;
      } else if (cur_char <= 0x7FF) {
        size = 2;
      } else if (cur_char <= 0xFFFF) {
        size = 3;
      } else {
        size = 4;
      }
      const wchar_t* bytes = s.c_str() + i;
      i += size;
      for (int j = 0; j < size; ++j) {
        transformations.emplace_back(BYTES_CHAR[static_cast<unsigned char>(bytes[j])], j > 0 ? 1 : 0);
      }
    }
    normalized.transform_range(transformations, 0);
  });
}
