// Copyright 2023 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/punctuation.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

Punctuation::Punctuation() {}

void Punctuation::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    PredicatePattern pattern = PredicatePattern(std::iswpunct);
    return normalized.split(pattern, SplitDelimiterBehavior::Isolated);
  });
}
