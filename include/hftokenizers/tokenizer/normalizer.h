// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <unicode/unorm.h>

#include <string>
#include <utility>
#include <vector>

#include "hftokenizers/tokenizer/pattern.h"

namespace hftokenizers {

namespace tokenizer {

enum SplitDelimiterBehavior {
  Removed,
  Isolated,
  MergedWithPrevious,
  MergedWithNext,
  Contiguous,
};

class NormalizedString {
 public:
  explicit NormalizedString(const std::wstring& original);
  std::string get();
  std::wstring& get_original();
  std::wstring& get_normalized();
  void set_normalized(std::wstring& normalized);
  void nfc();
  void nfd();
  void nfkc();
  void nfkd();
  void lowercase();
  void prepend(std::wstring& str);
  void transform_range(std::vector<std::pair<wchar_t, int>> transformations, int initial_offset);
  friend std::wstring unicode_normalization(std::wstring& input, UNormalizationMode mode);
  std::vector<NormalizedString> split(Pattern& pattern, SplitDelimiterBehavior split_delimiter_behavior);

 private:
  std::wstring original;
  std::wstring normalized;
  int original_shift;
};

class Normalizer {
 public:
  virtual ~Normalizer() {}
  virtual void normalize(NormalizedString& input) = 0;
};

}   // namespace tokenizer

}   // namespace hftokenizers
