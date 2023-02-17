---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazy_sqdecomp-AOJ-RUQRSQ.test.cpp
    title: test/lazy_sqdecomp-AOJ-RUQRSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/monoid/range_add_monoid.hpp\"\n\n#include <cstddef>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct dat {\n\tT value;\n\tstd::size_t\
    \ size;\n\tconstexpr dat(const T& value = 0, const std::size_t& size = 0ULL) :\
    \ value(value), size(size) {}\n};\n\ntemplate <class T>\nstruct range_add_monoid\
    \ {\n\tusing value_type = dat<T>;\n\tstatic constexpr value_type identity{};\n\
    \tstatic value_type operation(const value_type& a, const value_type& b) {\n\t\t\
    return value_type(a.value + b.value, a.size + b.size);\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <cstddef>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct dat {\n\tT value;\n\tstd::size_t size;\n\tconstexpr dat(const T&\
    \ value = 0, const std::size_t& size = 0ULL) : value(value), size(size) {}\n};\n\
    \ntemplate <class T>\nstruct range_add_monoid {\n\tusing value_type = dat<T>;\n\
    \tstatic constexpr value_type identity{};\n\tstatic value_type operation(const\
    \ value_type& a, const value_type& b) {\n\t\treturn value_type(a.value + b.value,\
    \ a.size + b.size);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/range_add_monoid.hpp
  requiredBy: []
  timestamp: '2023-02-18 05:16:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazy_sqdecomp-AOJ-RUQRSQ.test.cpp
  - test/lazy_sqdecomp-AOJ-RAQRSQ.test.cpp
documentation_of: src/utility/monoid/range_add_monoid.hpp
layout: document
title: "range_add_monoid (\u533A\u9593\u548C\u30E2\u30CE\u30A4\u30C9)"
---

## 概要

加法のモノイドを表現した構造体です。RAQで利用できます

作用を表現する構造体で`a.value + a.size * hoge`とするといい感じになります。

## 機能


#### dat

`テンプレート引数 T`: 型、`operator +`が定義されているもの

`T value`: 保持している値

`std::size_t size`: 保持している区間の長さ


#### range_add_monoid

`テンプレート引数 T` : `dat`の`T`に利用される

`using value_type = dat<T>`
- データ構造で利用するために必要なエイリアス

`static constexpr value_type identity`
- 単位元、 `value = 0`、`size = 0ULL`

`static value_type opration(const value_type& a, const value_type& b)`
- 加法
- `value = a.value + b.value`
- `size = a.size + b.size`
