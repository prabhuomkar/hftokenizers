// Copyright 2023 Omkar Prabhu
#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>
#include <iostream>
#include <string>
#include <codecvt>
#include "hftokenizers/normalizers/unicode.h"

hftokenizers::normalizers::NFC::NFC() {}

std::wstring unicodeNormalization(std::wstring& input, UNormalizationMode mode) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF32(
    reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, mode, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  return normalizedInput;
}

void hftokenizers::normalizers::NFC::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput = unicodeNormalization(input.getNormalized(), UNORM_NFC);
  input.setNormalized(normalizedInput);
}

hftokenizers::normalizers::NFKC::NFKC() {}

void hftokenizers::normalizers::NFKC::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput = unicodeNormalization(input.getNormalized(), UNORM_NFKC);
  input.setNormalized(normalizedInput);
}

hftokenizers::normalizers::NFD::NFD() {}

void hftokenizers::normalizers::NFD::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput = unicodeNormalization(input.getNormalized(), UNORM_NFD);
  input.setNormalized(normalizedInput);
}

hftokenizers::normalizers::NFKD::NFKD() {}

void hftokenizers::normalizers::NFKD::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput = unicodeNormalization(input.getNormalized(), UNORM_NFKD);
  input.setNormalized(normalizedInput);
}

hftokenizers::normalizers::Nmt::Nmt() {}

void hftokenizers::normalizers::Nmt::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::wstring normalizedInput;
  for (unsigned char c : input.getNormalized()) {
    if ((c >= 0x0001 && c <= 0x0008) || (c >= 0x000E && c <= 0x001F) ||
      c == 0x000B || c == 0x007F || c == 0x008F || c == 0x009F
    ) {
      normalizedInput += ' ';
    } else {
      normalizedInput += c;
    }
  }
  input.setNormalized(normalizedInput);
  normalizedInput.clear();
  for (unsigned char c : input.getNormalized()) {
    switch (c) {
      case 0x0009:
      case 0x000A:
      case 0x000C:
      case 0x000D:
      case 0x1680:
      case 0x2028:
      case 0x2029:
      case 0x2581:
      case 0xFEFF:
      case 0xFFFD:
        normalizedInput += ' ';
        break;
      default:
        normalizedInput += c;
        break;
    }
  }
  input.setNormalized(normalizedInput);
}
