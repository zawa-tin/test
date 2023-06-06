---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
    title: test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/rangeAddMonoid.hpp\"\n\n#include <cstddef>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct dat {\n\tT value;\n\tstd::size_t\
    \ size;\n\tconstexpr dat(const T& value = 0, const std::size_t& size = 0ULL) :\
    \ value(value), size(size) {}\n};\n\ntemplate <class T>\nstruct rangeAddMonoid\
    \ {\n\tusing valueType = dat<T>;\n\tstatic constexpr valueType identity{};\n\t\
    static valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ valueType(a.value + b.value, a.size + b.size);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <cstddef>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct dat {\n\tT value;\n\tstd::size_t size;\n\tconstexpr dat(const T&\
    \ value = 0, const std::size_t& size = 0ULL) : value(value), size(size) {}\n};\n\
    \ntemplate <class T>\nstruct rangeAddMonoid {\n\tusing valueType = dat<T>;\n\t\
    static constexpr valueType identity{};\n\tstatic valueType operation(const valueType&\
    \ a, const valueType& b) {\n\t\treturn valueType(a.value + b.value, a.size + b.size);\n\
    \t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/rangeAddMonoid.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
  - test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
  - test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
  - test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
documentation_of: src/utility/monoid/rangeAddMonoid.hpp
layout: document
title: "rangeAddMonoid (\u533A\u9593\u548C\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

加法のモノイドを表現した構造体です。RAQで利用できます

作用を表現する構造体で`a.value + a.size * hoge`とするといい感じになります。

## 機能


#### dat

`テンプレート引数 T`: 型、`operator +`が定義されているもの

`T value`: 保持している値

`std::size_t size`: 保持している区間の長さ


#### rangeAddMonoid

`テンプレート引数 T` : `dat`の`T`に利用される

`using valueType = dat<T>`
- データ構造で利用するために必要なエイリアス

`static constexpr valueType identity`
- 単位元、 `value = 0`、`size = 0ULL`

`static valueType opration(const valueType& a, const valueType& b)`
- 加法
- `value = a.value + b.value`
- `size = a.size + b.size`
