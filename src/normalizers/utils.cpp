// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/utils.h"

#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

using namespace hftokenizers::tokenizer;
using namespace hftokenizers::normalizers;

Sequence::Sequence(std::vector<Normalizer*>& normalizers) : normalizers(normalizers) {}

std::vector<Normalizer*> Sequence::getNormalizers() { return normalizers; }

void Sequence::normalize(NormalizedString& input) {
  for (Normalizer* normalizer : normalizers) {
    normalizer->normalize(input);
  }
}

Lowercase::Lowercase() {}

void Lowercase::normalize(NormalizedString& input) {
  std::wstring normalizedInput;
  for (int i = 0; i < input.getNormalized().length(); i++) {
    normalizedInput.push_back(tolower(input.getNormalized()[i]));
  }
  input.setNormalized(normalizedInput);
}
