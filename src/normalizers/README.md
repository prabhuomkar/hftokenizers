# Normalizers

## About
- [Reference Video](https://www.youtube.com/watch?v=4IIC2jI9CaU)
- One of the first step in tokenizers. It converts the input with varied fonts, casing, accents, punctuations and spaces into lowercase list of words which can then be fed into a model without losing its meaning.
- Depending on the type of input dataset one might need to choose an appropriate normalizer.

## Types

### Sequence 
Allows concatenating multiple other Normalizer as a Sequence which run in the given order.

### Lowercase
Converts all the words into lowercase.

### Strip
Strips whitespaces from left and right side. 

### Replace
Replaces all the matching occurences of regex pattern with the new content.

### Prepend
Adds given prepend content at the start of the string.

### Unicode
TBD

### Bert
TBD

### Precompiled
TBD
