#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Prepend : public Normalizer {
    public:
      Prepend(std::wstring& prepend);
      virtual void normalize(std::wstring& input) override;
    private:
      std::wstring& prepend;
    };
  } // namespace normalizers
} // namespace hftokenizers
