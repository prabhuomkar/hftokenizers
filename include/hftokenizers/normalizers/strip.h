// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Strip : public hftokenizers::tokenizer::Normalizer {
 public:
  Strip(bool stripLeft, bool stripRight);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
 private:
  bool stripLeft;
  bool stripRight;
  void stripWhitespaces(std::wstring& str, bool stripLeft);
};

class StripAccents : public hftokenizers::tokenizer::Normalizer {
 public:
  StripAccents();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
 private:
  bool isCombiningMark(wchar_t c);
};

}  // namespace normalizers

}  // namespace hftokenizers
