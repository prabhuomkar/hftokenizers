// Copyright 2023 Omkar Prabhu
#include "hftokenizers/tokenizer/normalizer.h"

#include <unicode/normlzr.h>
#include <unicode/uchar.h>
#include <unicode/unistr.h>

#include <codecvt>
#include <iostream>
#include <locale>
#include <regex>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/pattern.h"

using namespace hftokenizers::tokenizer;

NormalizedString::NormalizedString(const std::wstring& original) : original(original), normalized(original) {}

std::string NormalizedString::get() {
  std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
  return converter.to_bytes(normalized);
}

std::wstring& NormalizedString::get_original() { return original; }

std::wstring& NormalizedString::get_normalized() { return normalized; }

void NormalizedString::set_normalized(std::wstring& new_normalized) { normalized = new_normalized; }

std::wstring unicode_normalization(std::wstring& input, UNormalizationMode split_delimiter_behaviorer_split_delimit) {
  UErrorCode status = U_ZERO_ERROR;
  icu::UnicodeString uInput =
      icu::UnicodeString::fromUTF32(reinterpret_cast<const UChar32*>(input.c_str()), input.length());
  icu::UnicodeString uNormalizedInput;
  icu::Normalizer::normalize(uInput, split_delimiter_behaviorer_split_delimit, 0, uNormalizedInput, status);
  std::wstring normalized_input;
  for (int i = 0; i < uNormalizedInput.length(); ++i) {
    UChar32 c = uNormalizedInput.char32At(i);
    normalized_input.push_back(static_cast<wchar_t>(c));
  }
  return normalized_input;
}

void NormalizedString::nfc() { normalized = unicode_normalization(normalized, UNORM_NFC); }

void NormalizedString::nfkc() { normalized = unicode_normalization(normalized, UNORM_NFKC); }

void NormalizedString::nfd() { normalized = unicode_normalization(normalized, UNORM_NFD); }

void NormalizedString::nfkd() { normalized = unicode_normalization(normalized, UNORM_NFKD); }

void NormalizedString::lowercase() {
  for (int i = 0; i < normalized.length(); i++) {
    normalized[i] = tolower(normalized[i]);
  }
}

/// When splitting on `'-'` for example, with input `the-final--countdown`:
///  - Removed => `[ "the", "", "final", "", "", "countdown" ]`
///  - Isolated => `[ "the", "-", "final", "-", "-", "countdown" ]`
///  - Contiguous => `[ "the", "-", "final", "--", "countdown" ]`
///  - MergedWithPrevious => `[ "the-", "final-", "-", "countdown" ]`
///  - MergedWithNext => `[ "the", "-final", "-", "-countdown" ]`
std::vector<NormalizedString> NormalizedString::split(Pattern& pattern,
                                                      SplitDelimiterBehavior split_delimiter_behavior) {
  std::vector<NormalizedString> result;
  std::vector<std::pair<std::pair<int, int>, bool>> splits = pattern.find_matches(normalized);
  if (split_delimiter_behavior == SplitDelimiterBehavior::Isolated) {
    for (auto& split : splits) {
      split.second = false;
    }
  } else if (split_delimiter_behavior == SplitDelimiterBehavior::Removed) {
    // do nothing
  } else if (split_delimiter_behavior == SplitDelimiterBehavior::MergedWithPrevious) {
    // TODO(omkar)
  } else if (split_delimiter_behavior == SplitDelimiterBehavior::MergedWithNext) {
    // TODO(omkar)
  } else if (split_delimiter_behavior == SplitDelimiterBehavior::Contiguous) {
    std::vector<std::pair<std::pair<int, int>, bool>> new_splits;
    bool prev_match = false;
    int start = splits[0].first.first, end = splits[0].first.second;
    for (auto split : splits) {
      auto length = split.first.first == split.first.second ? 1 : split.first.second - split.first.first;
      if (split.second) {
        if (!prev_match) {
          start = split.first.first;
          end = split.first.second;
          prev_match = true;
        } else {
          end = split.first.first != split.first.second ? split.first.second : split.first.second + 1;
        }
      } else {
        if (prev_match) {
          new_splits.emplace_back(std::make_pair(std::make_pair(start, end), false));
        }
        new_splits.emplace_back(std::make_pair(std::make_pair(split.first.first, split.first.second), false));
        prev_match = false;
      }
    }
    splits = new_splits;
  }
  for (auto split : splits) {
    if (!split.second) {
      auto length = split.first.first == split.first.second ? 1 : split.first.second - split.first.first;
      std::wstring slice = normalized.substr(split.first.first, length);
      result.push_back(NormalizedString(slice));
    } else {
      result.push_back(NormalizedString(L""));
    }
  }
  return result;
}

void Normalizer::normalize(NormalizedString& input) {}
