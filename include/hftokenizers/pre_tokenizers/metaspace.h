// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

namespace hftokenizers {

namespace pre_tokenizers {

class Metaspace : public hftokenizers::tokenizer::PreTokenizer {
 public:
  explicit Metaspace(wchar_t replacement = L'\u2581', bool add_prefix_space = true);
  void pre_tokenize(hftokenizers::tokenizer::PreTokenizedString& input) override;

 private:
  wchar_t replacement;
  bool add_prefix_space;
};

}   // namespace pre_tokenizers

}   // namespace hftokenizers
