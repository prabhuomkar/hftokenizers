// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Whitespace : public hftokenizers::tokenizer::PreTokenizer {
 public:
  Whitespace();
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;
};

class WhitespaceSplit : public hftokenizers::tokenizer::PreTokenizer {
 public:
  WhitespaceSplit();
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
