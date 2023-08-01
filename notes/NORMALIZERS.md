# Normalizers

## About
- [Reference Video](https://www.youtube.com/watch?v=4IIC2jI9CaU)
- The first step in tokenization is converting the input, with varied fonts,
casings, accents, punctuations, and spaces, into a lowercase list of words. This list
can then be fed into a model without losing its meaning.
- Depending on the type of input dataset, one might need to choose an appropriate set of normalizers.

## Types

### Sequence
Allows defining multiple normalizers as a sequence which runs in the given order.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/utils.rs)  
Implementation Source: [C++](../src/normalizers/utils.cpp)

### Lowercase
Converts all the uppercase characters to lowercase.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/utils.rs)  
Implementation Source: [C++](../src/normalizers/utils.cpp)

### Strip
Removes whitespaces from specific sides i.e. left, right or both.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/strip.rs)  
Implementation Source: [C++](../src/normalizers/strip.cpp)

### StripAccents
Removes all accent symbols in unicode to be used with NFD for consistency.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/strip.rs)  
Implementation Source: [C++](../src/normalizers/strip.cpp)

### Replace
Replaces all the matching occurences of regex pattern with the new content.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/replace.rs)  
Implementation Source: [C++](../src/normalizers/replace.cpp)

### Prepend
Adds given prepend content at the start of the string.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/prepend.rs)  
Implementation Source: [C++](../src/normalizers/prepend.cpp)

### NFC, NFKC, NFD, NFKD, Nmt
Support for handling unicode characters.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/unicode.rs)  
Implementation Source: [C++](../src/normalizers/unicode.cpp)

### Bert
Supporting normalization for BERT-like models with lowercasing, punctuation and 
unicode normalization, stripping accents and special character handling.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/normalizers/bert.rs)  
Implementation Source: [C++](../src/normalizers/bert.cpp)

### Precompiled
TBD
