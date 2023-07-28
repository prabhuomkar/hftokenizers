#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class Strip : public Normalizer {
    public:
      Strip(bool stripLeft, bool stripRight);
      virtual void normalize(std::wstring& input) override;
    private:
      bool stripLeft;
      bool stripRight;
      void stripWhitespaces(std::wstring& str, bool stripLeft);
    };

    class StripAccents : public Normalizer {
    public:
      StripAccents();
      virtual void normalize(std::wstring& input) override;
    private:
      bool isCombiningMark(char c);
    };
  } // namespace normalizers
} // namespace hftokenizers
