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
  bundledCode: "#line 2 \"src/utility/monoid/add.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class dat_type>\nclass add_monoid {\n\tusing T = dat_type\n\tstatic constexpr\
    \ T id = 0;\n\tstatic T op(const T& a, const T& b) {\n\t\treturn a + b;\n\t}\n\
    };\n\n};\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class dat_type>\nclass add_monoid\
    \ {\n\tusing T = dat_type\n\tstatic constexpr T id = 0;\n\tstatic T op(const T&\
    \ a, const T& b) {\n\t\treturn a + b;\n\t}\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/monoid/add.hpp
  requiredBy: []
  timestamp: '2023-01-16 01:23:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/monoid/add.hpp
layout: document
title: "\u52A0\u6CD5\u30E2\u30CE\u30A4\u30C9"
---

## 概要

加法の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::add_monoid<dat_type>`
- `dat_type`: `int` `long long` `modint`など0が代入できるもの

`static constexpr dat_type zawa::add_monoid<dat_type>::id`
- 加法単位元、0

`static dat_type zawa::add_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- 加法 a + bを返す
