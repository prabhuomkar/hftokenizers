// Copyright 2023 Omkar Prabhu
#pragma once

#include <unicode/unorm.h>

#include <string>
#include <vector>

namespace hftokenizers {

namespace tokenizer {

class NormalizedString {
 public:
  explicit NormalizedString(std::wstring& original);
  std::string get();
  std::wstring& get_original();
  std::wstring& get_normalized();
  void set_normalized(std::wstring& normalized);
  void nfc();
  void nfd();
  void nfkc();
  void nfkd();
  void lowercase();
  friend std::wstring unicode_normalization(std::wstring& input, UNormalizationMode mode);
  NormalizedString& operator=(const NormalizedString& other) {
    if (this == &other) {
      return *this;
    }
    return *this;
  }

 private:
  std::wstring& original;
  std::wstring& normalized;
};

class Normalizer {
 public:
  virtual ~Normalizer() {}
  virtual void normalize(NormalizedString& input) = 0;
};

}   // namespace tokenizer

}   // namespace hftokenizers
