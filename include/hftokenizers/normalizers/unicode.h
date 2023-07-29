// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class NFC : public Normalizer {
 public:
  NFC();
  void normalize(std::wstring& input) override;
};

class NFKC : public Normalizer {
 public:
  NFKC();
  void normalize(std::wstring& input) override;
};

class NFD : public Normalizer {
 public:
  NFD();
  void normalize(std::wstring& input) override;
};

class NFKD : public Normalizer {
 public:
  NFKD();
  void normalize(std::wstring& input) override;
};

class Nmt : public Normalizer {
 public:
  Nmt();
  void normalize(std::wstring& input) override;
};

}  // namespace normalizers

}  // namespace hftokenizers
