// Copyright 2023 Omkar Prabhu
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "hftokenizers/normalizers/precompiled.h"

hftokenizers::normalizers::Precompiled::Precompiled(std::wstring& precompiledCharsmap) :
                                                    precompiledCharsmap(precompiledCharsmap) {}

void hftokenizers::normalizers::Precompiled::normalize(hftokenizers::tokenizer::NormalizedString& input) {
  std::vector<std::pair<wchar_t, int>> transformations;
  // TODO(omkar): implement Precompiled normalizer
}
