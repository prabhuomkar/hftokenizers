// Copyright 2023 Omkar Prabhu
#pragma once

#include <string>
#include <vector>

namespace hftokenizers {

namespace normalizers {

class Normalizer {
 public:
  virtual ~Normalizer() {}
  virtual void normalize(std::wstring& input) = 0;
};

}  // namespace normalizers

}  // namespace hftokenizers
