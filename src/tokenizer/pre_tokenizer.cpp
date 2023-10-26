// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/pre_tokenizer.h"

#include <codecvt>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

using namespace hftokenizers::tokenizer;

Split::Split(NormalizedString& normalized) : normalized(normalized) {}

PreTokenizedString::PreTokenizedString(const std::wstring& original) : original(original) {
  NormalizedString normalized = NormalizedString(original);
  std::vector<Split> new_splits;
  new_splits.push_back(Split(normalized));
  splits = new_splits;
}

void PreTokenizedString::split(std::function<std::vector<NormalizedString>(NormalizedString)> split_fn) {
  std::vector<Split> new_splits;
  for (int i = 0; i < splits.size(); i++) {
    Split original_split = splits[i];
    if (original_split.tokens.has_value()) {
      new_splits.push_back(original_split);
      continue;
    }
    std::vector<NormalizedString> normalized_str_splits = split_fn(original_split.normalized);
    for (auto normalized_str : normalized_str_splits) {
      if (!normalized_str.get_normalized().empty()) {
        new_splits.push_back(Split(normalized_str));
      }
    }
  }
  splits = new_splits;
}

std::vector<std::tuple<std::wstring, std::pair<int, int>, std::optional<std::vector<Token>>>>
PreTokenizedString::get_splits() {
  std::vector<std::tuple<std::wstring, std::pair<int, int>, std::optional<std::vector<Token>>>> result;
  for (auto split : splits) {
    result.push_back(std::make_tuple(split.normalized.get_normalized(), std::make_pair(0, 0), split.tokens));
  }
  return result;
};

void PreTokenizer::pre_tokenize(PreTokenizedString& input) {}
