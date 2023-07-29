// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Replace : public hftokenizers::tokenizer::Normalizer {
 public:
  Replace(std::wstring& pattern, std::wstring& content);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
 private:
  std::wstring& pattern;
  std::wstring& content;
};

}  // namespace normalizers

}  // namespace hftokenizers
