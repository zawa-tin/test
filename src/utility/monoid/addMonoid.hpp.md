---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/dualSegmentTree-AOJRAQ.test.cpp
    title: test/dualSegmentTree-AOJRAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-AOJ-RSQ.test.cpp
    title: test/segmentTree-AOJ-RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/squareDecomp-AOJ-RSQ.test.cpp
    title: test/squareDecomp-AOJ-RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/squareDecomp-LC-RSQ.test.cpp
    title: test/squareDecomp-LC-RSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/addMonoid.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct addMonoid {\n\tusing valueType = T;\n\tstatic constexpr\
    \ valueType identity{};\n\tstatic valueType operation(const valueType& a, const\
    \ valueType& b) {\n\t\treturn a + b;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct addMonoid\
    \ {\n\tusing valueType = T;\n\tstatic constexpr valueType identity{};\n\tstatic\
    \ valueType operation(const valueType& a, const valueType& b) {\n\t\treturn a\
    \ + b;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/addMonoid.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/dualSegmentTree-AOJRAQ.test.cpp
  - test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - test/squareDecomp-AOJ-RSQ.test.cpp
  - test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - test/squareDecomp-LC-RSQ.test.cpp
  - test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
  - test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
  - test/segmentTree-AOJ-RSQ.test.cpp
documentation_of: src/utility/monoid/addMonoid.hpp
layout: document
title: "addMonoid (\u52A0\u6CD5\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

加法の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RSQの時にでもどうぞ

## 機能

```
zawa::addMonoid<T>
```
`T`: `int` `long long` など0が単位元で加法が定義できるもの

```
using valueType = T
```
 データ構造で使うために必要なやつ

**メンバ**

```
static constexpr valueType identity
```
加法単位元、0

```
static value_type operation(const value_type& a, const value_type& b)
```

加法、a + bを返す
