// Copyright 2023 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/delimiter.h"

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

Delimiter::Delimiter(wchar_t char_delimiter) : char_delimiter(char_delimiter) {}

void Delimiter::pre_tokenize(PreTokenizedString& pre_tokenized) {
  wchar_t _char_delimiter = char_delimiter;
  pre_tokenized.split([&_char_delimiter](NormalizedString normalized) {
    return normalized.split(_char_delimiter, SplitDelimiterBehavior::Removed);
  });
}
