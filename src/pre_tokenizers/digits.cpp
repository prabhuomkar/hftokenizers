// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/digits.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

Digits::Digits(bool individual_digits) : individual_digits(individual_digits) {}

void Digits::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    PredicatePattern pattern = PredicatePattern(std::iswdigit);
    return normalized.split(pattern,
                            individual_digits ? SplitDelimiterBehavior::Isolated : SplitDelimiterBehavior::Contiguous);
  });
}
