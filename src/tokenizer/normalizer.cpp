// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/normalizer.h"
#include <iostream>
#include <string>
#include <codecvt>

hftokenizers::tokenizer::NormalizedString::NormalizedString(std::wstring& original) :
                                                            original(original),
                                                            normalized(original) {}

std::string hftokenizers::tokenizer::NormalizedString::get() {
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  return converter.to_bytes(original);
}

std::wstring& hftokenizers::tokenizer::NormalizedString::getOriginal() {
  return original;
}

std::wstring& hftokenizers::tokenizer::NormalizedString::getNormalized() {
  return normalized;
}

void hftokenizers::tokenizer::NormalizedString::setNormalized(std::wstring& newNormalized) {
  normalized = newNormalized;
}

void hftokenizers::tokenizer::Normalizer::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::cout << input.get() << std::endl;
}
