// Copyright 2023 Omkar Prabhu
#pragma once

#include <unicode/unorm.h>

#include <string>
#include <vector>

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
  NormalizedString& operator=(const NormalizedString& other) {
    if (this == &other) {
      return *this;
    }
    original = other.original;
    normalized = other.normalized;
    return *this;
  }
  std::string get();
  std::wstring& get_original();
  std::wstring& get_normalized();
  void set_normalized(std::wstring& normalized);
  void nfc();
  void nfd();
  void nfkc();
  void nfkd();
  void lowercase();
  friend std::wstring unicode_normalization(std::wstring& input, UNormalizationMode mode);
  std::vector<NormalizedString> split(wchar_t char_delimiter, SplitDelimiterBehavior split_delimiter_behavior);
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
