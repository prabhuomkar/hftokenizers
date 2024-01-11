// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class ByteLevel : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit ByteLevel(bool add_prefix_space = true, bool use_regex = true);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  bool add_prefix_space;
  bool use_regex;
  std::unordered_map<int, char> bytes_char();
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
