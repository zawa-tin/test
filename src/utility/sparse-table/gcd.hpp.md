---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC125C.test.cpp
    title: test/ABC125C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/utility/sparse-table/gcd.hpp\"\n#include <numeric>\n\
    \nnamespace zawa {\n\ntemplate <class dat_type>\nstruct gcd_structure {\n\tusing\
    \ T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn std::gcd(a, b);\n\t}\n\
    };\n\n} // namespace zawa\n"
  code: "#include <numeric>\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct\
    \ gcd_structure {\n\tusing T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn\
    \ std::gcd(a, b);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparse-table/gcd.hpp
  requiredBy: []
  timestamp: '2023-01-12 13:36:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC125C.test.cpp
documentation_of: src/utility/sparse-table/gcd.hpp
layout: document
title: sparsetable gcd-structure
---

## 概要

Sparse Tableで区間最小公倍数クエリを処理したい時に、`zawa::sparse_table<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::gcd_structure<dat_type>`
- `dat_type`
	- `int`や`long long`など、`std::gcd`に突っ込むことができる型
