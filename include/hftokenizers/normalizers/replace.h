#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Replace : public Normalizer {
    public:
      Replace(std::wstring& pattern, std::wstring& content);
      virtual void normalize(std::wstring& input) override;
    private:
      std::wstring& pattern;
      std::wstring& content;
    };
  } // namespace normalizers
} // namespace hftokenizers
