// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/split.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pattern.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;

Split::Split(hftokenizers::tokenizer::Pattern& pattern, hftokenizers::tokenizer::SplitDelimiterBehavior behavior)
    : pattern(pattern), behavior(behavior) {}

void Split::pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& pre_tokenized) {
  pre_tokenized.split(
      [this](hftokenizers::tokenizer::NormalizedString normalized) { return normalized.split(pattern, behavior); });
}
