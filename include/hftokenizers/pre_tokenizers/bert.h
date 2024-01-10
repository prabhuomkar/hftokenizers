// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class BertPreTokenizer : public hftokenizers::tokenizer::PreTokenizer {
 public:
  BertPreTokenizer();
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers