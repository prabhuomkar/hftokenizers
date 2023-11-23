// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Punctuation : public hftokenizers::tokenizer::PreTokenizer {
 public:
  Punctuation();
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
