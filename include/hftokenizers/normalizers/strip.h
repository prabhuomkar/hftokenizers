// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>

#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class Strip : public hftokenizers::tokenizer::Normalizer {
 public:
  Strip(bool strip_left, bool strip_right);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;

 private:
  bool strip_left;
  bool strip_right;
  void strip_whitespaces(std::wstring& str, bool strip_left);
};

class StripAccents : public hftokenizers::tokenizer::Normalizer {
 public:
  StripAccents();
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;

 private:
  bool is_combining_mark(wchar_t c);
};

}   // namespace normalizers

}   // namespace hftokenizers
