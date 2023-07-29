// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class NFC : public hftokenizers::tokenizer::Normalizer {
 public:
  NFC();
  void normalize(std::wstring& input) override;
};

class NFKC : public hftokenizers::tokenizer::Normalizer {
 public:
  NFKC();
  void normalize(std::wstring& input) override;
};

class NFD : public hftokenizers::tokenizer::Normalizer {
 public:
  NFD();
  void normalize(std::wstring& input) override;
};

class NFKD : public hftokenizers::tokenizer::Normalizer {
 public:
  NFKD();
  void normalize(std::wstring& input) override;
};

class Nmt : public hftokenizers::tokenizer::Normalizer {
 public:
  Nmt();
  void normalize(std::wstring& input) override;
};

}  // namespace normalizers

}  // namespace hftokenizers
