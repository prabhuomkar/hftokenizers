// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <utility>
#include <vector>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Precompiled : public hftokenizers::tokenizer::Normalizer {
 public:
  explicit Precompiled(std::wstring& precompiledCharsmap);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
 private:
  std::wstring& precompiledCharsmap;
};

}  // namespace normalizers

}  // namespace hftokenizers
