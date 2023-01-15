---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/max.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct max_monoid\
    \ {\n\tusing T = dat_type;\n\tstatic constexpr T id = std::numeric_limits<T>::min();\n\
    \tstatic T op(const T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\
    \n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class dat_type>\nstruct max_monoid {\n\tusing T = dat_type;\n\
    \tstatic constexpr T id = std::numeric_limits<T>::min();\n\tstatic T op(const\
    \ T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/max.hpp
  requiredBy: []
  timestamp: '2023-01-16 02:41:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/monoid/max.hpp
layout: document
title: "max\u30E2\u30CE\u30A4\u30C9"
---

## 概要

max演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::max_monoid<dat_type>`
- `dat_type`: `int` `long long` など`std::numeric_limits`が定義されているもの

`static constexpr dat_type zawa::max_monoid<dat_type>::id`
- 単位元、`std::numeric_limits<T>::min()`

`static dat_type zawa::max_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- `std::max(a, b)`
