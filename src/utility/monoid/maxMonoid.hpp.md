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
  bundledCode: "#line 2 \"src/utility/monoid/maxMonoid.hpp\"\n\n#include <algorithm>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct maxMonoid\
    \ {\n\tusing valueType = T;\n\tstatic constexpr valueType identity = std::numeric_limits<valueType>::min();\n\
    \tstatic valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ std::max(a, b);\n\t}\n};\n\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nstruct maxMonoid {\n\tusing valueType = T;\n\tstatic\
    \ constexpr valueType identity = std::numeric_limits<valueType>::min();\n\tstatic\
    \ valueType operation(const valueType& a, const valueType& b) {\n\t\treturn std::max(a,\
    \ b);\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/maxMonoid.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/practice90-037.test.cpp
  - test/ALPC-J.test.cpp
documentation_of: src/utility/monoid/maxMonoid.hpp
layout: document
title: "maxMonoid (\u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

max演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RMQでどうぞ

## 機能

```
zawa::maxMonoid<T>
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
static constexpr value_type identity
```

単位元、`std::numeric_limits<T>::min()`

**operation**
```
static value_type operation(const value_type& a, const value_type& b)
```
 `std::max(a, b)`
