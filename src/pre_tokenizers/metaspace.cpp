// Copyright 2023 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/metaspace.h"

#include <functional>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/normalizers/replace.h"
#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

Metaspace::Metaspace(wchar_t replacement, bool add_prefix_space)
    : replacement(replacement), add_prefix_space(add_prefix_space) {}

void Metaspace::pre_tokenize(PreTokenizedString& pre_tokenized) {
  pre_tokenized.split([this](NormalizedString normalized) {
    std::wstring replace_pattern = std::wstring(1, L' ');
    std::wstring content = std::wstring(1, replacement);
    Replace replace(replace_pattern, content);
    replace.normalize(normalized);
    if (!normalized.get_normalized()[0] != replacement) {
      normalized.prepend(content);
    }
    CharPattern pattern = CharPattern(replacement);
    return normalized.split(pattern, SplitDelimiterBehavior::MergedWithNext);
  });
}
