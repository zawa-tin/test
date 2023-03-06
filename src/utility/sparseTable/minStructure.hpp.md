---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparseTable.test.cpp
    title: test/sparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/sparseTable/minStructure.hpp\"\n\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct minStructure {\n\tusing valueType\
    \ = T;\n\tstatic valueType operation(const valueType& a, const valueType& b) {\n\
    \t\treturn std::min(a, b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct minStructure {\n\tusing valueType = T;\n\tstatic valueType operation(const\
    \ valueType& a, const valueType& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\n\
    } // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparseTable/minStructure.hpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparseTable.test.cpp
documentation_of: src/utility/sparseTable/minStructure.hpp
layout: document
title: minStructure (Sparse Table)
---

## 概要

Sparse Tableで区間最小値クエリを処理したい時に、`zawa::sparseTable<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::minStructure<T>`
- `T`
	- `int`や`long long`など、`std::min`に突っ込むことができる型
