// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pattern.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Split : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit Split(hftokenizers::tokenizer::Pattern& pattern, hftokenizers::tokenizer::SplitDelimiterBehavior behavior);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  hftokenizers::tokenizer::Pattern& pattern;
  hftokenizers::tokenizer::SplitDelimiterBehavior behavior;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
