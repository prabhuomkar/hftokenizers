#pragma once

#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Normalizer {
    public:
      virtual ~Normalizer() {};
      virtual void normalize(std::wstring& input) = 0;
    };
  } // namespace normalizers
} // namespace hftokenizers
