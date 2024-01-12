// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/normalizers/sequence.h"

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
