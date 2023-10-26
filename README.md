# hftokenizers
Demystifying HuggingFace Tokenizers in C++

## Components
- [Normalizers](src/normalizers/)
- [Pre tokenizers](src/pre_tokenizers/)
- [Models](src/models/)
- [PostProcessor](src/post_processors/)
- [Decoders](src/decoders/)

## Getting Started
- Build the library
```
cmake .
make
```
- Build the example program to run bunch of normalizers currently supported:
```
g++ --std=c++17 -o example example.cpp -Iinclude/ -I<icu include directory> -L. -lhftokenizers
```
- Build and run the example
```
export DYLD_LIBRARY_PATH=$PWD
g++ --std=c++17 -o example example.cpp -Iinclude/ -I<icu4c include directory> -L. -lhftokenizers
./example
```

## Goals
- Not intended to be a tutorial/course of Huggingface Tokenizers 
- Will not provide Training API but just `tokenizer.json` based tokenization  
- Build a portable C++ version of Huggingface Tokenizers which can run with PyTorch's LibTorch C++ API
- Demonstrate an example of running a traced/scripted HuggingFace model with tokenizer and 
run in a C++ environment without any Python dependencies.
- Run some benchmarks to compare performance with Rust version and improve C++ version (_I see you FastTokenizer_)

## License
This project is licensed under [Apache License 2.0](LICENSE).