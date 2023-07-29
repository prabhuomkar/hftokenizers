// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

namespace hftokenizers {

namespace tokenizer {

class NormalizedString {
 public:
  explicit NormalizedString(std::wstring& original);
  std::string get();
  std::wstring& getOriginal();
  std::wstring& getNormalized();
  void setNormalized(std::wstring& normalized);
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

}  // namespace tokenizer

}  // namespace hftokenizers
