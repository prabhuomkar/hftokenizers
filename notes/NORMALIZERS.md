# Normalizers

## About
- [Reference Video](https://www.youtube.com/watch?v=4IIC2jI9CaU)
- One of the first steps in tokenization is converting the input, with varied fonts,
casings, accents, punctuations, and spaces, into a lowercase list of words. This list
can then be fed into a model without losing its meaning.
- Depending on the type of input dataset, one might need to choose an appropriate set of normalizers.

## Types

### Sequence
Allows defining multiple normalizers as a sequence which runs in the given order.

### Lowercase
Converts all the uppercase characters to lowercase.

### Strip
Removes whitespaces from specific sides i.e. left, right or both.

## StripAccents
Removes all accent symbols in unicode to be used with NFD for consistency.

### Replace
Replaces all the matching occurences of regex pattern with the new content.

### Prepend
Adds given prepend content at the start of the string.

### NFC, NFKC, NFD, NFKD, Nmt
Support for handling unicode characters

### Bert
Supporting normalization for BERT-like models with lowercasing, punctuation and
unicode normalization, stripping accents and special character handling.

### Precompiled
TBD
