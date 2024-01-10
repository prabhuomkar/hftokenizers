// Copyright 2023-2024 Omkar Prabhu
#pragma once

#include <string>
#include <utility>

namespace hftokenizers {

namespace tokenizer {

class Token {
 private:
  int id;
  std::wstring value;
  std::pair<int, int> offsets;
};

}   // namespace tokenizer

}   // namespace hftokenizers
