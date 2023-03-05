---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALPC-J.test.cpp
    title: test/ALPC-J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/practice90-037.test.cpp
    title: test/practice90-037.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/max_monoid.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct max_monoid\
    \ {\n\tusing value_type = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::min();\n\
    \tstatic T operation(const T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t\
    }\n};\n\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstruct max_monoid {\n\tusing value_type = T;\n\tstatic\
    \ constexpr T identity = std::numeric_limits<T>::min();\n\tstatic T operation(const\
    \ T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/max_monoid.hpp
  requiredBy: []
  timestamp: '2023-02-18 05:16:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/practice90-037.test.cpp
  - test/ALPC-J.test.cpp
documentation_of: src/utility/monoid/max_monoid.hpp
layout: document
title: "max_monoid (\u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

max演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RMQでどうぞ

## 機能

`zawa::max_monoid<T>`
- `T`: `int` `long long` など`std::numeric_limits`が定義されているもの

**メンバなど**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr value_type identity`
- 単位元、`std::numeric_limits<T>::min()`

`static value_type operation(const value_type& a, const value_type& b)`
- `std::max(a, b)`
