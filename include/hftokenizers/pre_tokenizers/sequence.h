// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Sequence : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit Sequence(std::vector<hftokenizers::tokenizer::PreTokenizer*>& pre_tokenizers);
  std::vector<hftokenizers::tokenizer::PreTokenizer*> get_pre_tokenizers();
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  std::vector<hftokenizers::tokenizer::PreTokenizer*> pre_tokenizers;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
