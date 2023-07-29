// Copyright 2023 Omkar Prabhu
#include <iostream>
#include <string>
#include <codecvt>
#include <vector>
#include "hftokenizers/tokenizer/normalizer.h"
#include "hftokenizers/normalizers/utils.h"

hftokenizers::normalizers::Sequence::Sequence(
  std::vector<hftokenizers::tokenizer::Normalizer*>& normalizers
) : normalizers(normalizers) {}

std::vector<hftokenizers::tokenizer::Normalizer*>
  hftokenizers::normalizers::Sequence::getNormalizers() {
  return normalizers;
}

void hftokenizers::normalizers::Sequence::normalize(std::wstring& input) {
  for (hftokenizers::tokenizer::Normalizer* normalizer : normalizers) {
    normalizer->normalize(input);
  }
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(input);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::Lowercase::Lowercase() {}

void hftokenizers::normalizers::Lowercase::normalize(std::wstring& input) {
  std::wstring normalizedInput;
  for (int i = 0; i < input.length(); i++) {
    normalizedInput.push_back(tolower(input[i]));
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}
