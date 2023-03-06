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
  bundledCode: "#line 2 \"src/utility/sparseTable/bitwiseAndStructure.hpp\"\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nstruct bitwiseAndStructure {\n\tusing valueType\
    \ = T;\n\tstatic valueType operation(const valueType& a, const valueType& b) {\n\
    \t\treturn (a & b);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nstruct bitwiseAndStructure\
    \ {\n\tusing valueType = T;\n\tstatic valueType operation(const valueType& a,\
    \ const valueType& b) {\n\t\treturn (a & b);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/sparseTable/bitwiseAndStructure.hpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/sparseTable/bitwiseAndStructure.hpp
layout: document
title: bitwiseAndStructure (Sparse Table)
---

## 概要

Sparse Tableで区間bitwise andクエリを処理したい時に、`zawa::sparseTable<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::bitwiseAndStructure<T>`
- `T`
	- `int`や`long long`など、`operator &`が定義されているもの
- **単体テストをまだしていません**
