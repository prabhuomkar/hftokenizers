// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Prepend : public hftokenizers::tokenizer::Normalizer {
 public:
  explicit Prepend(std::wstring& prepend);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
 private:
  std::wstring& prepend;
};

}  // namespace normalizers

}  // namespace hftokenizers
