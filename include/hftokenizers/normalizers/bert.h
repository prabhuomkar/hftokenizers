// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>

#include "hftokenizers/tokenizer/normalizer.h"

namespace hftokenizers {

namespace normalizers {

class BertNormalizer : public hftokenizers::tokenizer::Normalizer {
 public:
  BertNormalizer(bool clean_text, bool handle_chinese_chars, bool strip_accents, bool lowercase);
  void normalize(hftokenizers::tokenizer::NormalizedString& input) override;
  friend bool is_whitespace(wchar_t c);
  friend bool is_control(wchar_t c);
  friend bool is_chinese_char(wchar_t c);

 private:
  bool clean_text = true;
  bool handle_chinese_chars = true;
  bool strip_accents = true;
  bool lowercase = true;
  void do_clean_text(hftokenizers::tokenizer::NormalizedString& input);
  void do_handle_chinese_chars(hftokenizers::tokenizer::NormalizedString& input);
};

}   // namespace normalizers

}   // namespace hftokenizers
