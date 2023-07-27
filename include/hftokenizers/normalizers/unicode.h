#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class NFC : public Normalizer {
    public:
      NFC();
      virtual void normalize(std::string& input) override;
    };

    class NFKC : public Normalizer {
    public:
      NFKC();
      virtual void normalize(std::string& input) override;
    };

    class NFD : public Normalizer {
    public:
      NFD();
      virtual void normalize(std::string& input) override;
    };

    class NFKD : public Normalizer {
    public:
      NFKD();
      virtual void normalize(std::string& input) override;
    };
  } // namespace normalizers
} // namespace hftokenizers
