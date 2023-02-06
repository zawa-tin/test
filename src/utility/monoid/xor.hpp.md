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
  bundledCode: "#line 2 \"src/utility/monoid/xor.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nstruct xor_monoid {\n\tusing value_type = T;\n\tstatic constexpr\
    \ T identity{};\n\tstatic T operation(const T& a, const T& b) {\n\t\treturn (a\
    \ ^ b);\n\t}\n};\n\n};\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct xor_monoid\
    \ {\n\tusing value_type = T;\n\tstatic constexpr T identity{};\n\tstatic T operation(const\
    \ T& a, const T& b) {\n\t\treturn (a ^ b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/xor.hpp
  requiredBy: []
  timestamp: '2023-02-06 18:33:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/monoid/xor.hpp
layout: document
title: "\u6392\u4ED6\u7684\u8AD6\u7406\u548C\u30E2\u30CE\u30A4\u30C9"
---

## 概要

xor演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::xor_monoid<T>`
- `T`: `int` `long long` など`operator ^`が定義されているもの、0が代入できるもの

**メンバなど**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr T identity`
- 単位元、0

`static value_type operation(const value_type& a, const value_type& b)`
- `a ^ b`
