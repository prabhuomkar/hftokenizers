// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/utils.h"

#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

Sequence::Sequence(std::vector<Normalizer*>& normalizers) : normalizers(normalizers) {}

std::vector<Normalizer*> Sequence::get_normalizers() { return normalizers; }

void Sequence::normalize(NormalizedString& input) {
  for (Normalizer* normalizer : normalizers) {
    normalizer->normalize(input);
  }
}

Lowercase::Lowercase() {}

void Lowercase::normalize(NormalizedString& input) { input.lowercase(); }
