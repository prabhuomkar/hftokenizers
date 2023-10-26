# Pre tokenizers

## About
- [Reference Video](https://www.youtube.com/watch?v=grlLV8AIXug)
- The second step in tokenization is converting the normalized input into words with start and end indexes for the word.
- Depending on the type of input dataset, one might need to choose an appropriate set of pre tokenizer.

## Types

### Sequence
Allows defining multiple pre tokenizers as a sequence which runs in the given order.  
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/sequence.rs)  
Implementation Source: [C++](../src/pre_tokenizers/sequence.cpp)

### Delimiter
Splits the string into words based on the given character delimiter.   
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/delimiter.rs)  
Implementation Source: [C++](../src/pre_tokenizers/delimiter.cpp)