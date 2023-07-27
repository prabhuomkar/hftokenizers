#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Replace : public Normalizer {
    public:
      Replace(std::string& pattern, std::string& content);
      virtual void normalize(std::string& input) override;
    private:
      std::string& pattern;
      std::string& content;
    };
  } // namespace normalizers
} // namespace hftokenizers
