---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment_tree-RXORQ.test.cpp
    title: test/segment_tree-RXORQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/xorMonoid.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct xorMonoid {\n\tusing value_type = T;\n\tstatic constexpr\
    \ value_type identity{};\n\tstatic value_type operation(const value_type& a, const\
    \ value_type& b) {\n\t\treturn (a ^ b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct xorMonoid\
    \ {\n\tusing value_type = T;\n\tstatic constexpr value_type identity{};\n\tstatic\
    \ value_type operation(const value_type& a, const value_type& b) {\n\t\treturn\
    \ (a ^ b);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/xorMonoid.hpp
  requiredBy: []
  timestamp: '2023-03-06 14:24:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree-RXORQ.test.cpp
documentation_of: src/utility/monoid/xorMonoid.hpp
layout: document
title: "xorMonoid (\u6392\u4ED6\u7684\u8AD6\u7406\u548C\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

xor演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::xorMonoid<T>`
- `T`: `int` `long long` など`operator ^`が定義されているもの、0が代入できるもの

**メンバ**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr T identity`
- 単位元、0

`static value_type operation(const value_type& a, const value_type& b)`
- `a ^ b`
