// Copyright 2023 Omkar Prabhu
#pragma once

#include <unicode/unorm.h>
#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class NFC : public hftokenizers::tokenizer::Normalizer {
 public:
  NFC();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
  friend std::wstring unicodeNormalization(std::wstring& input, UNormalizationMode mode);
};

class NFKC : public hftokenizers::tokenizer::Normalizer {
 public:
  NFKC();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
  friend std::wstring unicodeNormalization(std::wstring& input);
};

class NFD : public hftokenizers::tokenizer::Normalizer {
 public:
  NFD();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
  friend std::wstring unicodeNormalization(std::wstring& input);
};

class NFKD : public hftokenizers::tokenizer::Normalizer {
 public:
  NFKD();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
  friend std::wstring unicodeNormalization(std::wstring& input);
};

class Nmt : public hftokenizers::tokenizer::Normalizer {
 public:
  Nmt();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
};

}  // namespace normalizers

}  // namespace hftokenizers
