// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/delimiter.h"

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

CharDelimiterSplit::CharDelimiterSplit(wchar_t delimiter) : delimiter(delimiter) {}

void CharDelimiterSplit::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    CharPattern pattern = CharPattern(delimiter);
    return normalized.split(pattern, SplitDelimiterBehavior::Removed);
  });
}
