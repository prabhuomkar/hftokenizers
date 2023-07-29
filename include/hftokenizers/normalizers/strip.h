// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Strip : public Normalizer {
 public:
  Strip(bool stripLeft, bool stripRight);
  void normalize(std::wstring& input) override;
 private:
  bool stripLeft;
  bool stripRight;
  void stripWhitespaces(std::wstring& str, bool stripLeft);
};

class StripAccents : public Normalizer {
 public:
  StripAccents();
  void normalize(std::wstring& input) override;
 private:
  bool isCombiningMark(wchar_t c);
};

}  // namespace normalizers

}  // namespace hftokenizers
