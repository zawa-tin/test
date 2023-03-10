---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC179-F.test.cpp
    title: test/ABC179-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC291-F.test.cpp
    title: test/ABC291-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AGC005-B.test.cpp
    title: test/AGC005-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
    title: test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-AOJ-RmQ.test.cpp
    title: test/segmentTree-AOJ-RmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/squareDecomp-AOJ-RmQ.test.cpp
    title: test/squareDecomp-AOJ-RmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/minMonoid.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct minMonoid\
    \ {\n\tusing valueType = T;\n\tstatic constexpr valueType identity = std::numeric_limits<valueType>::max();\n\
    \tstatic valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ std::min(a, b);\n\t}\n};\n\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstruct minMonoid {\n\tusing valueType = T;\n\tstatic\
    \ constexpr valueType identity = std::numeric_limits<valueType>::max();\n\tstatic\
    \ valueType operation(const valueType& a, const valueType& b) {\n\t\treturn std::min(a,\
    \ b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/minMonoid.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC179-F.test.cpp
  - test/ABC291-F.test.cpp
  - test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - test/segmentTree-AOJ-RmQ.test.cpp
  - test/AGC005-B.test.cpp
  - test/squareDecomp-AOJ-RmQ.test.cpp
  - test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
  - test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
documentation_of: src/utility/monoid/minMonoid.hpp
layout: document
title: "minMonoid (\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

min演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RmQの時にでもどうぞ

## 機能

```
zawa::min_monoid<T>
```
`T`: `int` `long long` など`std::numeric_limits`が定義されているもの

**メンバなど**

**valueType**
```
using valueType = T
```

データ構造で利用するために必要なエイリアス

**identity**
```
static constexpr valueType identity
```
単位元、`std::numeric_limits<T>::max()`

**operation**
```
static valueType operation(const valueType& a, const valueType& b)
```
`std::min(a, b)`
