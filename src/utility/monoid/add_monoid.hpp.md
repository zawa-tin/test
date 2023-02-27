---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_segtree-AOJ-RAQRSQ.test.cpp
    title: test/lazy_segtree-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_segtree-AOJ-RAQRmQ.test.cpp
    title: test/lazy_segtree-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree-AOJRSQ.test.cpp
    title: test/segment_tree-AOJRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-AOJRSQ.test.cpp
    title: test/sqdecomp-AOJRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-LCRSQ.test.cpp
    title: test/sqdecomp-LCRSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/add_monoid.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct add_monoid {\n\tusing value_type = T;\n\tstatic constexpr\
    \ T identity{};\n\tstatic T operation(const T& a, const T& b) {\n\t\treturn a\
    \ + b;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct add_monoid\
    \ {\n\tusing value_type = T;\n\tstatic constexpr T identity{};\n\tstatic T operation(const\
    \ T& a, const T& b) {\n\t\treturn a + b;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/add_monoid.hpp
  requiredBy: []
  timestamp: '2023-02-18 05:16:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sqdecomp-LCRSQ.test.cpp
  - test/segment_tree-AOJRSQ.test.cpp
  - test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
  - test/lazy_segtree-AOJ-RAQRSQ.test.cpp
  - test/sqdecomp-AOJRSQ.test.cpp
  - test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
  - test/lazy_segtree-AOJ-RAQRmQ.test.cpp
documentation_of: src/utility/monoid/add_monoid.hpp
layout: document
title: "add_monoid (\u52A0\u6CD5\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

加法の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RSQの時にでもどうぞ

## 機能

`zawa::add_monoid<T>`
- `T`: `int` `long long` `modint`など0が単位元で加法が定義できるもの

`using value_type = T`
- データ構造で使うために必要なやつ

**メンバ**

`static constexpr value_type identity
- 加法単位元、0

`static value_type operation(const value_type& a, const value_type& b)`
- 加法、a + bを返す
