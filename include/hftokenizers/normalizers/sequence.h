// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Sequence : public hftokenizers::tokenizer::Normalizer {
 public:
  explicit Sequence(std::vector<hftokenizers::tokenizer::Normalizer*>& normalizers);
  std::vector<hftokenizers::tokenizer::Normalizer*> get_normalizers();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;

 private:
  std::vector<hftokenizers::tokenizer::Normalizer*> normalizers;
};

}   // namespace normalizers

}   // namespace hftokenizers
