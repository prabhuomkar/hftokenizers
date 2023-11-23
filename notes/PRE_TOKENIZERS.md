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

### CharDelimiterSplit
Splits the string into words based on the given character delimiter.   
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/delimiter.rs)  
Implementation Source: [C++](../src/pre_tokenizers/delimiter.cpp)

### Whitespace
Splits on word boundaries (using the following regular expression: `\w+|[^\w\s]+`) or whitespace characters.   
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/whitespace.rs)  
Implementation Source: [C++](../src/pre_tokenizers/whitespace.cpp)

### Punctuation
Will isolate all punctuation characters.   
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/punctuation.rs)  
Implementation Source: [C++](../src/pre_tokenizers/punctuation.cpp)

## Metaspace
Splits on whitespaces and replaces them with a special char `▁` (U+2581).	
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/metaspace.rs)  
Implementation Source: [C++](../src/pre_tokenizers/metaspace.cpp)

## Digits
Splits the numbers from any other characters.	
Original Source: [Rust](https://github.com/huggingface/tokenizers/blob/main/tokenizers/src/pre_tokenizers/digits.rs)  
Implementation Source: [C++](../src/pre_tokenizers/digits.cpp)