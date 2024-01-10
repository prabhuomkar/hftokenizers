#include <hftokenizers/normalizers/bert.h>
#include <hftokenizers/normalizers/prepend.h>
#include <hftokenizers/normalizers/replace.h>
#include <hftokenizers/normalizers/strip.h>
#include <hftokenizers/normalizers/unicode.h>
#include <hftokenizers/normalizers/utils.h>
#include <hftokenizers/pre_tokenizers/bert.h>
#include <hftokenizers/pre_tokenizers/delimiter.h>
#include <hftokenizers/pre_tokenizers/digits.h>
#include <hftokenizers/pre_tokenizers/metaspace.h>
#include <hftokenizers/pre_tokenizers/punctuation.h>
#include <hftokenizers/pre_tokenizers/split.h>
#include <hftokenizers/pre_tokenizers/whitespace.h>
#include <hftokenizers/tokenizer/normalizer.h>
#include <hftokenizers/tokenizer/pattern.h>
#include <hftokenizers/tokenizer/pre_tokenizer.h>

#include <iostream>
#include <vector>

using namespace std;
using namespace hftokenizers::normalizers;
using namespace hftokenizers::pre_tokenizers;

void print_splits(
    std::vector<
        std::tuple<std::wstring, std::pair<int, int>, std::optional<std::vector<hftokenizers::tokenizer::Token>>>>
        result) {
  bool fsplit = true;
  for (auto split : result) {
    auto spair = get<1>(split);
    if (!fsplit) {
      cout << ", ";
    }
    cout << "(" << hftokenizers::tokenizer::NormalizedString(get<0>(split)).get() << ", (" << spair.first << ","
         << spair.second << "))";
    if (fsplit) {
      fsplit = false;
    }
  }
  cout << endl;
}

int main() {
  /*************************************************************/
  /******************* N O R M A L I Z E R S *******************/
  /*************************************************************/
  // lowercase
  hftokenizers::tokenizer::NormalizedString normalized =
      hftokenizers::tokenizer::NormalizedString(L"HUGGINGFACE TOKENIZERS");
  Lowercase lowercase;
  lowercase.normalize(normalized);
  cout << normalized.get() << endl;

  // prepend
  normalized = hftokenizers::tokenizer::NormalizedString(L"HUGGINGFACE TOKENIZERS");
  wstring prepender = L"_";
  Prepend prepend(prepender);
  prepend.normalize(normalized);
  cout << normalized.get() << endl;

  // strip
  normalized = hftokenizers::tokenizer::NormalizedString(L"  HUGGINGFACE TOKENIZERS   ");
  Strip strip(true, true);
  strip.normalize(normalized);
  cout << normalized.get() << endl;

  // strip accents
  normalized = hftokenizers::tokenizer::NormalizedString(L"Me llamó");
  StripAccents sa;
  sa.normalize(normalized);
  cout << normalized.get() << endl;

  // replace
  normalized = hftokenizers::tokenizer::NormalizedString(L"HUGGINGFACE 'TOKEN'IZERS");
  wstring replaceWhat = L"'";
  wstring replaceWith = L"\"";
  Replace replace(replaceWhat, replaceWith);
  replace.normalize(normalized);
  cout << normalized.get() << endl;

  // unicode
  normalized = hftokenizers::tokenizer::NormalizedString(L"\ufb01");
  NFC nfc;
  nfc.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"élégant");
  NFD nfd;
  nfd.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"\ufb01");
  NFKC nfkc;
  nfkc.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"\ufb01");
  NFKD nfkd;
  nfkd.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"Me llamó");
  nfkd.normalize(normalized);
  cout << normalized.get() << endl;

  // sequence
  normalized = hftokenizers::tokenizer::NormalizedString(
      L"Cụ thể, bạn sẽ tham gia một nhóm các giám đốc điều hành tổ chức, các nhà lãnh đạo doanh nghiệp, các học giả,"
      L"chuyên gia phát triển và tình nguyện viên riêng biệt trong lĩnh vực phi lợi nhuận…");
  vector<hftokenizers::tokenizer::Normalizer*> normalizers;
  normalizers.push_back(&nfkd);
  normalizers.push_back(&sa);
  normalizers.push_back(&lowercase);
  Sequence seq(normalizers);
  seq.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"ậ…");
  seq.normalize(normalized);
  cout << normalized.get() << endl;
  normalized = hftokenizers::tokenizer::NormalizedString(L"e\u0304\u0304\u0304o");
  seq.normalize(normalized);
  cout << normalized.get() << endl;

  // bert
  normalized = hftokenizers::tokenizer::NormalizedString(L"Héllò hôw are ü?");
  BertNormalizer bertnorm(true, true, true, true);
  bertnorm.normalize(normalized);
  cout << normalized.get() << endl;

  /*************************************************************/
  /**************** P R E   T O K E N I Z E R S ****************/
  /*************************************************************/
  // delimiter
  hftokenizers::tokenizer::PreTokenizedString pre_tokenized =
      hftokenizers::tokenizer::PreTokenizedString(L"the-final--countdown");
  CharDelimiterSplit delimiter('-');
  delimiter.pre_tokenize(pre_tokenized);
  auto result = pre_tokenized.get_splits();
  print_splits(result);

  // whitespace
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey, man, Good?");
  WhitespaceSplit ws;
  ws.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Whitespace w;
  w.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  // punctuation
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey friend!     How are you?!?");
  Punctuation punc;
  punc.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  // digits
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey 123 friend!");
  Digits dig(false);
  dig.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey 123 friend!");
  dig = Digits(true);
  dig.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  // metaspace
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey   friend!");
  Metaspace ms;
  ms.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  // split
  hftokenizers::tokenizer::RegexPattern split_pattern(L"\\w+|[^\\w\\s]+", true);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Split spr(split_pattern, hftokenizers::tokenizer::SplitDelimiterBehavior::Removed);
  spr.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Split spi(split_pattern, hftokenizers::tokenizer::SplitDelimiterBehavior::Isolated);
  spi.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Split spmwp(split_pattern, hftokenizers::tokenizer::SplitDelimiterBehavior::MergedWithPrevious);
  spmwp.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Split spmwn(split_pattern, hftokenizers::tokenizer::SplitDelimiterBehavior::MergedWithNext);
  spmwn.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"How are you doing?");
  Split spc(split_pattern, hftokenizers::tokenizer::SplitDelimiterBehavior::Contiguous);
  spc.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  // bert
  pre_tokenized = hftokenizers::tokenizer::PreTokenizedString(L"Hey friend!     How are you?!?");
  BertPreTokenizer bertpre;
  bertpre.pre_tokenize(pre_tokenized);
  result = pre_tokenized.get_splits();
  print_splits(result);

  return 0;
}