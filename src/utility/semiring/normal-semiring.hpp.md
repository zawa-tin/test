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
  bundledCode: "#line 2 \"src/utility/semiring/normal-semiring.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class dat_type>\nstruct normal_semiring {\n\tusing T = dat_type;\n\
    \tstatic constexpr T id_add = 0;\n\tstatic constexpr T id_mul = 1;\n\tstatic T\
    \ add(const T& a, const T& b) {\n\t\treturn a + b;\n\t}\n\tstatic T mul(const\
    \ T& a, const T& b) {\n\t\treturn a * b;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct normal_semiring\
    \ {\n\tusing T = dat_type;\n\tstatic constexpr T id_add = 0;\n\tstatic constexpr\
    \ T id_mul = 1;\n\tstatic T add(const T& a, const T& b) {\n\t\treturn a + b;\n\
    \t}\n\tstatic T mul(const T& a, const T& b) {\n\t\treturn a * b;\n\t}\n};\n\n\
    } // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/semiring/normal-semiring.hpp
  requiredBy: []
  timestamp: '2023-01-15 13:12:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/semiring/normal-semiring.hpp
layout: document
title: normal-semiring (+x)
---

## 概要

整数上の加法と乗法についての[半環](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%92%B0) を扱う構造体。

## 機能

`zawa::normal_semiring<T>`
- `T` 扱いたい集合

`T id_add`
- 0

`T id_mul`
- 1

`T add(const T& a, const T& b)`
- $a + b$

`T mul(const T& a, const T& b)`
- $a\times b$
