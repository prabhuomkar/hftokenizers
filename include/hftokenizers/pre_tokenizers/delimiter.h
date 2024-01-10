// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class CharDelimiterSplit : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit CharDelimiterSplit(wchar_t delimiter);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  wchar_t delimiter;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
