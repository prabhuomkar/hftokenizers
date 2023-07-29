// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Sequence : public Normalizer {
 public:
  explicit Sequence(std::vector<Normalizer*>& normalizers);
  std::vector<Normalizer*> getNormalizers();
  void normalize(std::wstring& input) override;
 private:
  std::vector<Normalizer*> normalizers;
};

class Lowercase : public Normalizer {
 public:
  Lowercase();
  void normalize(std::wstring& input) override;
};

}  // namespace normalizers

}  // namespace hftokenizers
