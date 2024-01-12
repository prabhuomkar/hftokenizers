// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Lowercase : public hftokenizers::tokenizer::Normalizer {
 public:
  Lowercase();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
};

}   // namespace normalizers

}   // namespace hftokenizers
