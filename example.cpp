#include <iostream>
#include <vector>
#include <hftokenizers/tokenizer/normalizer.h>
#include <hftokenizers/normalizers/utils.h>
#include <hftokenizers/normalizers/prepend.h>
#include <hftokenizers/normalizers/strip.h>
#include <hftokenizers/normalizers/replace.h>
#include <hftokenizers/normalizers/unicode.h>
#include <hftokenizers/normalizers/bert.h>

int main() {
  // lowercase
  std::wstring original = L"HUGGINGFACE TOKENIZERS";
  hftokenizers::tokenizer::NormalizedString normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::Lowercase lowercase;
  lowercase.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // prepend
  original = L"HUGGINGFACE TOKENIZERS";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  std::wstring prepender = L"_";
  hftokenizers::normalizers::Prepend prepend(prepender);
  prepend.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // strip
  original = L"  HUGGINGFACE TOKENIZERS   ";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::Strip strip(true, true);
  strip.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // replace
  original = L"HUGGINGFACE 'TOKEN'IZERS";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  std::wstring replaceWhat = L"'";
  std::wstring replaceWith = L"\"";
  hftokenizers::normalizers::Replace replace(replaceWhat, replaceWith);
  replace.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // unicode
  original = L"\ufb01";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::NFC nfc;
  nfc.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::NFD nfd;
  nfd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::NFKC nfkc;
  nfkc.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"\ufb01";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::NFKD nfkd;
  nfkd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  original = L"Me llamó";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  nfkd.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  hftokenizers::normalizers::StripAccents sa;
  sa.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // sequence
  original = L"Cụ thể, bạn sẽ tham gia một nhóm các giám đốc điều hành tổ chức, các nhà lãnh đạo doanh nghiệp, các học giả, chuyên gia phát triển và tình nguyện viên riêng biệt trong lĩnh vực phi lợi nhuận…";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  std::vector<hftokenizers::tokenizer::Normalizer*> normalizers;
  normalizers.push_back(&nfkd);
  normalizers.push_back(&sa);
  normalizers.push_back(&lowercase);
  hftokenizers::normalizers::Sequence seq(normalizers);
  seq.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  // bert
  original = L"Héllò hôw are ü?";
  normalized = hftokenizers::tokenizer::NormalizedString(original);
  hftokenizers::normalizers::BertNormalizer bert(true, true, true, true);
  bert.normalize(normalized);
  std::cout << normalized.get() << std::endl;
  return 0;
}
