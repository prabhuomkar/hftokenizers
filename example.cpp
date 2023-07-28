#include <iostream>
#include <hftokenizers/normalizers/unicode.h>
#include <hftokenizers/normalizers/strip.h>

int main() {
  std::string original = "\ufb01";
  hftokenizers::normalizers::NFC nfc;
  nfc.normalize(original);
  original = "\ufb01";
  hftokenizers::normalizers::NFD nfd;
  nfd.normalize(original);
  original = "\ufb01";
  hftokenizers::normalizers::NFKC nfkc;
  nfkc.normalize(original);
  original = "\ufb01";
  hftokenizers::normalizers::NFKD nfkd;
  nfkd.normalize(original);
  original = "\ufb01";
  hftokenizers::normalizers::Nmt nmt;
  nmt.normalize(original);
  original = "Me llamó";
  nfkd.normalize(original);
  hftokenizers::normalizers::StripAccents sa;
  sa.normalize(original);
  return 0;
}
