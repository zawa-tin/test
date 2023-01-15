---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sq-decomp-RmQ.test.cpp
    title: test/sq-decomp-RmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/min.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct min_monoid\
    \ {\n\tusing T = dat_type;\n\tstatic constexpr T id = std::numeric_limits<T>::max();\n\
    \tstatic T op(const T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\
    \n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class dat_type>\nstruct min_monoid {\n\tusing T = dat_type;\n\
    \tstatic constexpr T id = std::numeric_limits<T>::max();\n\tstatic T op(const\
    \ T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/min.hpp
  requiredBy: []
  timestamp: '2023-01-16 02:41:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sq-decomp-RmQ.test.cpp
documentation_of: src/utility/monoid/min.hpp
layout: document
title: "min\u30E2\u30CE\u30A4\u30C9"
---

## 概要

min演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::min_monoid<dat_type>`
- `dat_type`: `int` `long long` など`std::numeric_limits`が定義されているもの

`static constexpr dat_type zawa::min_monoid<dat_type>::id`
- 単位元、`std::numeric_limits<T>::max()`

`static dat_type zawa::min_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- `std::min(a, b)`
