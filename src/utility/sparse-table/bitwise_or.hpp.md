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
  bundledCode: "#line 2 \"src/utility/sparse-table/bitwise_or.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class dat_type>\nstruct bitwise_or_structure {\n\tusing T = dat_type;\n\
    \tstatic T op(T a, T b) {\n\t\treturn (a | b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct bitwise_or_structure\
    \ {\n\tusing T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn (a | b);\n\t\
    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparse-table/bitwise_or.hpp
  requiredBy: []
  timestamp: '2023-01-12 13:36:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/sparse-table/bitwise_or.hpp
layout: document
title: sparsetable bitwise_or-structure
---

## 概要

Sparse Tableで区間bitwise orクエリを処理したい時に、`zawa::sparse_table<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::bitwise_or_structure<dat_type>`
- `dat_type`
	- `int`や`long long`など、`operator |`が定義されているもの
- **単体テストをまだしていません**
