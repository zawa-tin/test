---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse-table.test.cpp
    title: test/sparse-table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/sparse-table/min.hpp\"\n\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class dat_type>\nstruct min_structure {\n\tusing\
    \ T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn std::min(a, b);\n\t}\n\
    };\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ dat_type>\nstruct min_structure {\n\tusing T = dat_type;\n\tstatic T op(T a,\
    \ T b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparse-table/min.hpp
  requiredBy: []
  timestamp: '2023-01-12 13:36:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse-table.test.cpp
documentation_of: src/utility/sparse-table/min.hpp
layout: document
title: sparsetable min-structure
---

## 概要

Sparse Tableで区間最小値クエリを処理したい時に、`zawa::sparse_table<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::min_structure<dat_type>`
- `dat_type`
	- `int`や`long long`など、`std::min`に突っ込むことができる型

