#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Lowercase : public Normalizer {
    public:
      Lowercase();
      virtual void normalize(std::string& input) override;
    };
  } // namespace normalizers
} // namespace hftokenizers
