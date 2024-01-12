// Copyright 2023-2024 Omkar Prabhu
#include "hftokenizers/normalizers/lowercase.h"

#include <iostream>
#include <string>
#include <vector>

#include "hftokenizers/tokenizer/normalizer.h"

using namespace hftokenizers::normalizers;
using namespace hftokenizers::tokenizer;

Lowercase::Lowercase() {}

void Lowercase::normalize(NormalizedString& input) { input.lowercase(); }
