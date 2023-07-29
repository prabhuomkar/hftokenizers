#include <iostream>
#include <vector>
#include <hftokenizers/tokenizer/normalizer.h>
#include <hftokenizers/normalizers/utils.h>
#include <hftokenizers/normalizers/prepend.h>
#include <hftokenizers/normalizers/strip.h>
#include <hftokenizers/normalizers/replace.h>
#include <hftokenizers/normalizers/unicode.h>
#include <hftokenizers/normalizers/bert.h>

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

int main() {
  // lowercase
  std::wstring original = L"HUGGINGFACE TOKENIZERS";
  NormalizedString normalized = NormalizedString(original);
  Lowercase lowercase;
  lowercase.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // prepend
  original = L"HUGGINGFACE TOKENIZERS";
  normalized = NormalizedString(original);
  std::wstring prepender = L"_";
  Prepend prepend(prepender);
  prepend.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // strip
  original = L"  HUGGINGFACE TOKENIZERS   ";
  normalized = NormalizedString(original);
  Strip strip(true, true);
  strip.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // replace
  original = L"HUGGINGFACE 'TOKEN'IZERS";
  normalized = NormalizedString(original);
  std::wstring replaceWhat = L"'";
  std::wstring replaceWith = L"\"";
  Replace replace(replaceWhat, replaceWith);
  replace.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // unicode
  original = L"\ufb01";
  normalized = NormalizedString(original);
  NFC nfc;
  nfc.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = NormalizedString(original);
  NFD nfd;
  nfd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = NormalizedString(original);
  NFKC nfkc;
  nfkc.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = NormalizedString(original);
  NFKD nfkd;
  nfkd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"Me llamó";
  normalized = NormalizedString(original);
  nfkd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  StripAccents sa;
  sa.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // sequence
  original = L"Cụ thể, bạn sẽ tham gia một nhóm các giám đốc điều hành tổ chức, các nhà lãnh đạo doanh nghiệp, các học giả, chuyên gia phát triển và tình nguyện viên riêng biệt trong lĩnh vực phi lợi nhuận…";
  normalized = NormalizedString(original);
  std::vector<Normalizer*> normalizers;
  normalizers.push_back(&nfkd);
  normalizers.push_back(&sa);
  normalizers.push_back(&lowercase);
  Sequence seq(normalizers);
  seq.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // bert
  original = L"Héllò hôw are ü?";
  normalized = NormalizedString(original);
  BertNormalizer bert(true, true, true, true);
  bert.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  return 0;
}
