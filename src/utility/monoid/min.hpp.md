---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AGC005-B.test.cpp
    title: test/AGC005-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RUQRmQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RUQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-AOJRmQ.test.cpp
    title: test/segmentTree-AOJRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-AOJRmQ.test.cpp
    title: test/sqdecomp-AOJRmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/min.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct min_monoid {\n\t\
    using value_type = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::max();\n\
    \tstatic T operation(const T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t\
    }\n};\n\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstruct min_monoid {\n\tusing value_type = T;\n\tstatic\
    \ constexpr T identity = std::numeric_limits<T>::max();\n\tstatic T operation(const\
    \ T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/min.hpp
  requiredBy: []
  timestamp: '2023-02-06 18:33:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmentTree-AOJRmQ.test.cpp
  - test/sqdecomp-AOJRmQ.test.cpp
  - test/lazy_sqdecomp-AOJ-RUQRmQ.test.cpp
  - test/AGC005-B.test.cpp
  - test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
documentation_of: src/utility/monoid/min.hpp
layout: document
title: "min\u30E2\u30CE\u30A4\u30C9"
---

## 概要

min演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RmQの時にでもどうぞ

## 機能

`zawa::min_monoid<T>`
- `T`: `int` `long long` など`std::numeric_limits`が定義されているもの

**メンバなど**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr value_type identity`
- 単位元、`std::numeric_limits<T>::max()`

`static value_type operation(const value_type& a, const value_type& b)`
- `std::min(a, b)`
