// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

namespace hftokenizers {

namespace tokenizer {

class NormalizedString {
 public:
  explicit NormalizedString(std::wstring& original);
  ~NormalizedString() {}
  std::string get();
  std::wstring& getOriginal();
 private:
  std::wstring& original;
  std::wstring& normalized;
};

class Normalizer {
 public:
  virtual ~Normalizer() {}
  virtual void normalize(std::wstring& input) = 0;
};

}  // namespace tokenizer

}  // namespace hftokenizers
