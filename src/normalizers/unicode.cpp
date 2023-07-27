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
