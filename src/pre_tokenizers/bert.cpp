// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/bert.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

BertPreTokenizer::BertPreTokenizer() {}

void BertPreTokenizer::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    CharPattern pattern = CharPattern(L' ');
    return normalized.split(pattern, SplitDelimiterBehavior::Removed);
  });
  pre_tokenized.split([this](NormalizedString normalized) {
    PredicatePattern pattern = PredicatePattern(std::iswpunct);
    return normalized.split(pattern, SplitDelimiterBehavior::Isolated);
  });
}
