cmake_minimum_required(VERSION 3.27)

project(hftokenizers)

set(CMAKE_CXX_STANDARD 17)

set(ICU_DEBUG ON)
set(ICU_ROOT /usr/local/opt/icu4c)
set(ICU_INCLUDE_DIR /usr/local/opt/icu4c/include)
find_package(ICU COMPONENTS uc i18n)

include_directories(
  include
  include/hftokenizers
)

add_library(hftokenizers SHARED
  src/tokenizer/normalizer.cpp
  src/normalizers/bert.cpp
  src/normalizers/prepend.cpp
  src/normalizers/replace.cpp
  src/normalizers/strip.cpp
  src/normalizers/unicode.cpp
  src/normalizers/utils.cpp
)

target_link_libraries(hftokenizers PRIVATE ICU::uc ICU::i18n)

install(TARGETS hftokenizers
  DESTINATION lib
)
