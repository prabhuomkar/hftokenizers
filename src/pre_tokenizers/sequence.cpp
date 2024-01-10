// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/pre_tokenizers/sequence.h"

#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pre_tokenizer.h"

using namespace hftokenizers::pre_tokenizers;
using namespace hftokenizers::tokenizer;

Sequence::Sequence(std::vector<PreTokenizer*>& pre_tokenizers) : pre_tokenizers(pre_tokenizers) {}

std::vector<PreTokenizer*> Sequence::get_pre_tokenizers() { return pre_tokenizers; }

void Sequence::pre_tokenize(PreTokenizedString& input) {
  for (PreTokenizer* pre_tokenizer : pre_tokenizers) {
    pre_tokenizer->pre_tokenize(input);
  }
}
