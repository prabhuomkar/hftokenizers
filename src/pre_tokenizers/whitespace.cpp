// Copyright 2023 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/whitespace.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

Whitespace::Whitespace() {}

void Whitespace::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    RegexPattern pattern = RegexPattern(L"\\w+|[^\\w\\s]+", true);
    return normalized.split(pattern, SplitDelimiterBehavior::Removed);
  });
}

WhitespaceSplit::WhitespaceSplit() {}

void WhitespaceSplit::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    CharPattern pattern = CharPattern(L' ');
    return normalized.split(pattern, SplitDelimiterBehavior::Removed);
  });
}
