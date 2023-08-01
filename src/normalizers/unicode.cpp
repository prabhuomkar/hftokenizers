// Copyright 2023 Omkar Prabhu
#include "hftokenizers/normalizers/unicode.h"

#include <codecvt>
#include <iostream>
#include <string>

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

NFC::NFC() {}

void NFC::normalize(NormalizedString& input) { input.nfc(); }

NFKC::NFKC() {}

void NFKC::normalize(NormalizedString& input) { input.nfkc(); }

NFD::NFD() {}

void NFD::normalize(NormalizedString& input) { input.nfd(); }

NFKD::NFKD() {}

void NFKD::normalize(NormalizedString& input) { input.nfkd(); }

Nmt::Nmt() {}

void Nmt::normalize(NormalizedString& input) {
  std::wstring normalizedInput;
  for (unsigned char c : input.get_normalized()) {
    if ((c >= 0x0001 && c <= 0x0008) || (c >= 0x000E && c <= 0x001F) || c == 0x000B || c == 0x007F || c == 0x008F ||
        c == 0x009F) {
      normalizedInput += ' ';
    } else {
      normalizedInput += c;
    }
  }
  input.set_normalized(normalizedInput);
  normalizedInput.clear();
  for (unsigned char c : input.get_normalized()) {
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
  input.set_normalized(normalizedInput);
}
