// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Digits : public hftokenizers::tokenizer::PreTokenizer {
 public:
  Digits(bool individual_digits);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  bool individual_digits;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
