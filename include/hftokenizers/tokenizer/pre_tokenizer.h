// Copyright 2023 Omkar Prabhu
#pragma once

#include <functional>
#include <optional>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/tokenizer.h"

namespace hftokenizers {

namespace tokenizer {

class Split {
 public:
  explicit Split(NormalizedString& normalized);
  Split& operator=(const Split& other) { return *this; }
  NormalizedString normalized;
  std::optional<std::vector<Token>> tokens;
};

class PreTokenizedString {
 public:
  explicit PreTokenizedString(const std::wstring& original);
  void split(std::function<std::vector<NormalizedString>(NormalizedString)> split_fn);
  std::vector<std::tuple<std::wstring, std::pair<int, int>, std::optional<std::vector<Token>>>> get_splits();

 private:
  std::wstring original;
  std::vector<Split> splits;
};

class PreTokenizer {
 public:
  virtual ~PreTokenizer() {}
  virtual void pre_tokenize(PreTokenizedString& input) = 0;
};

}   // namespace tokenizer

}   // namespace hftokenizers
