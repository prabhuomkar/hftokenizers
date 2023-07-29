// Copyright 2023 Omkar Prabhu
#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>
#include <iostream>
#include <string>
#include <codecvt>
#include "hftokenizers/normalizers/unicode.h"

hftokenizers::normalizers::NFC::NFC() {}

void hftokenizers::normalizers::NFC::normalize(std::wstring& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF32(
    reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFC, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::NFKC::NFKC() {}

void hftokenizers::normalizers::NFKC::normalize(std::wstring& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF32(
    reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFKC, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::NFD::NFD() {}

void hftokenizers::normalizers::NFD::normalize(std::wstring& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF32(
    reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFD, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::NFKD::NFKD() {}

void hftokenizers::normalizers::NFKD::normalize(std::wstring& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF32(
    reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFKD, 0, uNormalizedInput, status);
  std::wstring normalizedInput;
  for (int32_t i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalizedInput.push_back(static_cast<wchar_t>(c));
  }
  input = normalizedInput;
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(normalizedInput);
  std::cout << sNormalizedInput << std::endl;
}

hftokenizers::normalizers::Nmt::Nmt() {}

void hftokenizers::normalizers::Nmt::normalize(std::wstring& input) {
  std::wstring normalizedInput;
  for (unsigned char c : input) {
    if ((c >= 0x0001 && c <= 0x0008) || (c >= 0x000E && c <= 0x001F) ||
      c == 0x000B || c == 0x007F || c == 0x008F || c == 0x009F
    ) {
      normalizedInput += ' ';
    } else {
      normalizedInput += c;
    }
  }
  input = normalizedInput;
  normalizedInput.clear();
  for (unsigned char c : input) {
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
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  std::string sNormalizedInput = converter.to_bytes(input);
  std::cout << sNormalizedInput << std::endl;
}
