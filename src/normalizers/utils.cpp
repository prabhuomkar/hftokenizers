// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/utils.h"

#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

hftokenizers::normalizers::Sequence::Sequence(std::vector<hftokenizers::tokenizer::Normalizer*>& normalizers)
    : normalizers(normalizers) {}

std::vector<hftokenizers::tokenizer::Normalizer*> hftokenizers::normalizers::Sequence::getNormalizers() {
  return normalizers;
}

void hftokenizers::normalizers::Sequence::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  for (hftokenizers::tokenizer::Normalizer* normalizer : normalizers) {
    normalizer->normalize(input);
  }
}

hftokenizers::normalizers::Lowercase::Lowercase() {}

void hftokenizers::normalizers::Lowercase::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput;
  for (int i = 0; i < input.getNormalized().length(); i++) {
    normalizedInput.push_back(tolower(input.getNormalized()[i]));
  }
  input.setNormalized(normalizedInput);
}
