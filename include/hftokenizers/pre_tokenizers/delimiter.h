// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Delimiter : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit Delimiter(wchar_t char_delimiter);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  wchar_t char_delimiter;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
