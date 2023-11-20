// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/normalizer.h"

#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>

#include <codecvt>
#include <iostream>
#include <string>
#include <locale>

using namespace hftokenizers::tokenizer;

NormalizedString::NormalizedString(std::wstring& original) : original(original), normalized(original) {}

std::string NormalizedString::get() {
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  return converter.to_bytes(original);
}

std::wstring& NormalizedString::get_original() { return original; }

std::wstring& NormalizedString::get_normalized() { return normalized; }

void NormalizedString::set_normalized(std::wstring& new_normalized) { normalized = new_normalized; }

std::wstring unicode_normalization(std::wstring& input, UNormalizationMode mode) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput =
      icu::UnicodeString::fromUTF32(reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, mode, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  return normalizedInput;
}

void NormalizedString::nfc() { normalized = unicode_normalization(normalized, UNORM_NFC); }

void NormalizedString::nfkc() { normalized = unicode_normalization(normalized, UNORM_NFKC); }

void NormalizedString::nfd() { normalized = unicode_normalization(normalized, UNORM_NFD); }

void NormalizedString::nfkd() { normalized = unicode_normalization(normalized, UNORM_NFKD); }

void NormalizedString::lowercase() {
  for (int i = 0; i < normalized.length(); i++) {
    normalized[i] = tolower(normalized[i]);
  }
}

void Normalizer::normalize(NormalizedString& input) { std::cout << input.get() << std::endl; }
