#pragma once

#include "normalizer.h"
#include <string>

namespace hftokenizers {
  namespace normalizers {
    class BertNormalizer : public Normalizer {
    public:
      BertNormalizer(bool cleanText, bool handleChineseChars, bool stripAccents, bool lowercase);
      virtual void normalize(std::wstring& input) override;
      friend bool isWhitespace(wchar_t c);
      friend bool isControl(wchar_t c);
      friend bool isChineseChar(wchar_t c);
    private:
      bool cleanText = true;
      bool handleChineseChars = true;
      bool stripAccents = true;
      bool lowercase = true;
      void doCleanText(std::wstring& input);
      void doHandleChineseChars(std::wstring& input);
    };
  } // namespace normalizers
} // namespace hftokenizers
