---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC203-E.test.cpp
    title: test/ABC203-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC278-E.test.cpp
    title: test/ABC278-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/accum2d.test.cpp
    title: test/accum2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/accum2d.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct accum2d : std::vector<std::vector<T>>\
    \ {\n\taccum2d() {\n\t\t(*this).push_back({ T() });\n\t}\n\taccum2d(const std::vector<std::vector<T>>&\
    \ A) : std::vector<std::vector<T>>(A.size() + 1, std::vector<T>(A[0].size() +\
    \ 1, T())) {\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < A[i].size() ; j++) {\n\t\t\t\t(*this)[i + 1][j + 1] = (*this)[i][j\
    \ + 1] + (*this)[i + 1][j] - (*this)[i][j] + A[i][j];\n\t\t\t}\n\t\t}\n\t}\n\t\
    T sum(std::size_t y1, std::size_t x1, std::size_t y2, std::size_t x2) {\n\t\t\
    return (*this)[y2][x2] - (*this)[y1][x2] - (*this)[y2][x1] + (*this)[y1][x1];\n\
    \t}\n\tT sum(std::pair<std::size_t, std::size_t> p1, std::pair<std::size_t, std::size_t>\
    \ p2) {\n\t\treturn sum(p1.first, p1.second, p2.first, p2.second);\n\t}\n};\n\n\
    } // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct accum2d : std::vector<std::vector<T>> {\n\taccum2d()\
    \ {\n\t\t(*this).push_back({ T() });\n\t}\n\taccum2d(const std::vector<std::vector<T>>&\
    \ A) : std::vector<std::vector<T>>(A.size() + 1, std::vector<T>(A[0].size() +\
    \ 1, T())) {\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < A[i].size() ; j++) {\n\t\t\t\t(*this)[i + 1][j + 1] = (*this)[i][j\
    \ + 1] + (*this)[i + 1][j] - (*this)[i][j] + A[i][j];\n\t\t\t}\n\t\t}\n\t}\n\t\
    T sum(std::size_t y1, std::size_t x1, std::size_t y2, std::size_t x2) {\n\t\t\
    return (*this)[y2][x2] - (*this)[y1][x2] - (*this)[y2][x1] + (*this)[y1][x1];\n\
    \t}\n\tT sum(std::pair<std::size_t, std::size_t> p1, std::pair<std::size_t, std::size_t>\
    \ p2) {\n\t\treturn sum(p1.first, p1.second, p2.first, p2.second);\n\t}\n};\n\n\
    } // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/accum2d.hpp
  requiredBy: []
  timestamp: '2023-01-20 10:34:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC203-E.test.cpp
  - test/accum2d.test.cpp
  - test/ABC278-E.test.cpp
documentation_of: src/dataStructure/accum2d.hpp
layout: document
title: "accum2d (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
---

## 概要

与えられた行列 $A$ の二次元累積和 $S$ をとります。

詳しく言うと、 $\displaystyle S_{00}\ =\ 0\ \land\ S_{yx}\ =\ \sum_{i = 0}^{y - 1} \sum_{j = 0}^{x - 1} A_{yx}$ を満たす行列 $S$ を構築します。

## 機能

**コンストラクタ**

`zawa::accum2d<T>(const std::vector<std::vector<T>>& A)`
- 二次元`std::vector<T>` `A`から $S$ を構築します。
- `A` の行数、列数は共に1以上である必要があります。
- **計算量** : `A`の行数を $H$ 、列数を $W$ として $O(HW)$

`zawa::accum2d<T>()`
- 1 x 1の `T()`のみの `std::vector<std::vector<T>>`を構築します。
- 空でないことに注意

**メンバ関数**

`T sum(int y1, int x1, int y2, int x2)`
- $\displaystyle \sum_{i = \text{y1}}^{\text{y2} - 1} \sum_{j = \text{x1}}^{\text{x2} - 1} A_{ij}$ を返します。
- **計算量** $O(1)$

`std::vector<std::vector<T>>`を継承しているので、STLの機能が使えます。
