---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC125-C.test.cpp
    title: test/ABC125-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/utility/sparseTable/gcdStructure.hpp\"\n#include <numeric>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct gcdStructure {\n\tusing valueType\
    \ = T;\n\tstatic valueType operation(const valueType& a, const valueType& b) {\n\
    \t\treturn std::gcd(a, b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#include <numeric>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct gcdStructure\
    \ {\n\tusing valueType = T;\n\tstatic valueType operation(const valueType& a,\
    \ const valueType& b) {\n\t\treturn std::gcd(a, b);\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparseTable/gcdStructure.hpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC125-C.test.cpp
documentation_of: src/utility/sparseTable/gcdStructure.hpp
layout: document
title: gcdStructure (Sparse Table)
---

## 概要

Sparse Tableで区間最小公倍数クエリを処理したい時に、`zawa::sparseTable<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::gcdStructure<T>`
- `T`
	- `int`や`long long`など、`std::gcd`に突っ込むことができる型
