// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/normalizer.h"

#include <codecvt>
#include <iostream>
#include <string>

using namespace hftokenizers::tokenizer;

NormalizedString::NormalizedString(std::wstring& original) : original(original), normalized(original) {}

std::string NormalizedString::get() {
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  return converter.to_bytes(original);
}

std::wstring& NormalizedString::getOriginal() { return original; }

std::wstring& NormalizedString::getNormalized() { return normalized; }

void NormalizedString::setNormalized(std::wstring& newNormalized) { normalized = newNormalized; }

void Normalizer::normalize(NormalizedString& input) { std::cout << input.get() << std::endl; }
