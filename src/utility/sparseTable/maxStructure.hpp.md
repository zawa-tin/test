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
  bundledCode: "#line 2 \"src/utility/sparseTable/maxStructure.hpp\"\n\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct maxStructure {\n\tusing valueType\
    \ = T;\n\tstatic valueType operation(const valueType& a, const valueType& b) {\n\
    \t\treturn std::max(a, b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct maxStructure {\n\tusing valueType = T;\n\tstatic valueType operation(const\
    \ valueType& a, const valueType& b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\n\
    } // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparseTable/maxStructure.hpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/sparseTable/maxStructure.hpp
layout: document
title: maxStructure (Sparse Table)
---

## 概要

Sparse Tableで区間最大値クエリを処理したい時に、`zawa::sparseTable<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::maxStructure<T>`
- `T`
	- `int`や`long long`など、`std::max`に突っ込むことができる型
- **単体テストをまだしていません**
