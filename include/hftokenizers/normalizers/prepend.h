#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Prepend : public Normalizer {
    public:
      Prepend(std::string& prepend);
      virtual void normalize(std::string& input) override;
    private:
      std::string& prepend;
    };
  } // namespace normalizers
} // namespace hftokenizers
