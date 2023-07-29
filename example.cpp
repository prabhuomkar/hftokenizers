#include <iostream>
#include <vector>
#include <hftokenizers/normalizers/utils.h>
#include <hftokenizers/normalizers/prepend.h>
#include <hftokenizers/normalizers/strip.h>
#include <hftokenizers/normalizers/replace.h>
#include <hftokenizers/normalizers/unicode.h>
#include <hftokenizers/normalizers/bert.h>

int main() {
  // lowercase
  std::wstring original = L"HUGGINGFACE TOKENIZERS";
  hftokenizers::normalizers::Lowercase lowercase;
  lowercase.normalize(original);
  // prepend
  original = L"HUGGINGFACE TOKENIZERS";
  std::wstring prepender = L"_";
  hftokenizers::normalizers::Prepend prepend(prepender);
  prepend.normalize(original);
  // strip
  original = L"  HUGGINGFACE TOKENIZERS   ";
  hftokenizers::normalizers::Strip strip(true, true);
  strip.normalize(original);
  // replace
  original = L"HUGGINGFACE 'TOKEN'IZERS";
  std::wstring replaceWhat = L"'";
  std::wstring replaceWith = L"\"";
  hftokenizers::normalizers::Replace replace(replaceWhat, replaceWith);
  replace.normalize(original);
  // unicode
  original = L"\ufb01";
  hftokenizers::normalizers::NFC nfc;
  nfc.normalize(original);
  original = L"\ufb01";
  hftokenizers::normalizers::NFD nfd;
  nfd.normalize(original);
  original = L"\ufb01";
  hftokenizers::normalizers::NFKC nfkc;
  nfkc.normalize(original);
  original = L"\ufb01";
  hftokenizers::normalizers::NFKD nfkd;
  nfkd.normalize(original);
  original = L"Me llamó";
  nfkd.normalize(original);
  hftokenizers::normalizers::StripAccents sa;
  sa.normalize(original);
  original = L"Cụ thể, bạn sẽ tham gia một nhóm các giám đốc điều hành tổ chức, các nhà lãnh đạo doanh nghiệp, các học giả, chuyên gia phát triển và tình nguyện viên riêng biệt trong lĩnh vực phi lợi nhuận…";
  // sequence
  std::vector<hftokenizers::tokenizer::Normalizer*> normalizers;
  normalizers.push_back(&nfkd);
  normalizers.push_back(&sa);
  normalizers.push_back(&lowercase);
  hftokenizers::normalizers::Sequence seq(normalizers);
  seq.normalize(original);
  // bert
  original = L"Héllò hôw are ü?";
  hftokenizers::normalizers::BertNormalizer bert(true, true, true, true);
  bert.normalize(original);
  return 0;
}
