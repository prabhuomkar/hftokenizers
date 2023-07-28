#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Lowercase : public Normalizer {
    public:
      Lowercase();
      virtual void normalize(std::wstring& input) override;
    };
  } // namespace normalizers
} // namespace hftokenizers
