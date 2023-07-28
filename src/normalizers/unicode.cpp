#include "unicode.h"
#include <iostream>
#include <string>
#include <unicode/normlzr.h>

hftokenizers::normalizers::NFC::NFC() {}

void hftokenizers::normalizers::NFC::normalize(std::string& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF8(input.c_str());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFC, 0, uNormalizedInput, status);
  std::string normalizedInput;
  normalizedInput.reserve(uNormalizedInput.length() * 3);
  uNormalizedInput.toUTF8String(normalizedInput);
  std::cout << normalizedInput << '\n';
}

hftokenizers::normalizers::NFKC::NFKC() {}

void hftokenizers::normalizers::NFKC::normalize(std::string& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF8(input.c_str());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFKC, 0, uNormalizedInput, status);
  std::string normalizedInput;
  normalizedInput.reserve(uNormalizedInput.length() * 3);
  uNormalizedInput.toUTF8String(normalizedInput);
  std::cout << normalizedInput << '\n';
}

hftokenizers::normalizers::NFD::NFD() {}

void hftokenizers::normalizers::NFD::normalize(std::string& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF8(input.c_str());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFD, 0, uNormalizedInput, status);
  std::string normalizedInput;
  normalizedInput.reserve(uNormalizedInput.length() * 3);
  uNormalizedInput.toUTF8String(normalizedInput);
  std::cout << normalizedInput << '\n';
}

hftokenizers::normalizers::NFKD::NFKD() {}

void hftokenizers::normalizers::NFKD::normalize(std::string& input) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput = icu::UnicodeString::fromUTF8(input.c_str());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, UNORM_NFKD, 0, uNormalizedInput, status);
  std::string normalizedInput;
  normalizedInput.reserve(uNormalizedInput.length() * 3);
  uNormalizedInput.toUTF8String(normalizedInput);
  std::cout << normalizedInput << '\n';
}

hftokenizers::normalizers::Nmt::Nmt() {}

void hftokenizers::normalizers::Nmt::normalize(std::string& input) {
  std::string normalizedInput;
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
  std::cout << normalizedInput << '\n';
}
