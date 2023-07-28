#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class NFC : public Normalizer {
    public:
      NFC();
      virtual void normalize(std::wstring& input) override;
    };

    class NFKC : public Normalizer {
    public:
      NFKC();
      virtual void normalize(std::wstring& input) override;
    };

    class NFD : public Normalizer {
    public:
      NFD();
      virtual void normalize(std::wstring& input) override;
    };

    class NFKD : public Normalizer {
    public:
      NFKD();
      virtual void normalize(std::wstring& input) override;
    };

    class Nmt : public Normalizer {
    public:
      Nmt();
      virtual void normalize(std::wstring& input) override;
    };
  } // namespace normalizers
} // namespace hftokenizers
