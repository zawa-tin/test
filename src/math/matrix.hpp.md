---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/EDPC-R.test.cpp
    title: test/EDPC-R.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/matrix.test.cpp
    title: test/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/matrix.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class T = long long>\nclass matrix {\nprivate:\n\tstd::vector<std::vector<T>>\
    \ dat;\n\npublic:\n\tstd::size_t r, c;\n\n\tmatrix(const std::vector<T>& dat)\
    \ : dat(dat), r(dat.size()), c(dat[0].size())  {}\n\tmatrix(std::size_t r, std::size_t\
    \ c) : dat(r, std::vector<T>(c)), r(r), c(c) {}\n\tmatrix(const matrix<T>& mat)\
    \ : dat(mat.r, std::vector<T>(mat.c)), r(mat.r), c(mat.c) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] = mat[i][j];\n\t\t\t}\n\t\t}\t\n\t}\n\n\tstd::vector<T>& operator[](std::size_t\
    \ i) {\n\t\treturn dat[i];\n\t}\n\tconst std::vector<T>& operator[](std::size_t\
    \ i) const {\n\t\treturn dat[i];\n\t}\n\n\tmatrix& operator+=(const matrix<T>&\
    \ mat) {\n\t\tfor (std::size_t i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < c ; j++) {\n\t\t\t\tdat[i][j] += mat[i][j];\n\t\t\t}\n\t\t}\n\t\t\
    return *this;\n\t}\n\tmatrix operator+(const matrix<T>& mat) {\n\t\treturn matrix(*this)\
    \ += mat;\n\t}\n\n\tmatrix& operator-=(const matrix<T>& mat) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] -= mat[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix& operator-(const\
    \ matrix<T>& mat) {\n\t\treturn matrix(*this) -= mat;\t\n\t}\n\n\tmatrix operator*(const\
    \ matrix<T>& mat) {\n\t\tmatrix res(r, mat.c);\n\t\tfor (std::size_t i = 0 ; i\
    \ < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < mat.c ; j++) {\n\t\t\t\tfor\
    \ (std::size_t k = 0 ; k < c ; k++) {\n\t\t\t\t\tres[i][j] += dat[i][k] * mat[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tmatrix operator*=(const matrix<T>&\
    \ mat) {\n\t\treturn (*this) = (*this) * mat;\n\t}\n\n\tmatrix pow(long long p);\n\
    };\n\ntemplate <class T>\nmatrix<T> id_mul(std::size_t n) {\n\tmatrix<T> res(n,\
    \ n);\n\tfor (std::size_t i = 0 ; i < n ; i++) {\n\t\tres[i][i] = 1;\n\t}\n\t\
    return res;\n}\n\ntemplate <class T>\nmatrix<T> matrix<T>::pow(long long p) {\n\
    \tmatrix<T> res = id_mul<T>(this->r);\n\tmatrix<T> base(*this);\n\twhile (p >\
    \ 0) {\n\t\tif (p & 1) {\n\t\t\tres *= base;\n\t\t}\n\t\tbase *= base;\n\t\tp\
    \ >>= 1;\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ T = long long>\nclass matrix {\nprivate:\n\tstd::vector<std::vector<T>> dat;\n\
    \npublic:\n\tstd::size_t r, c;\n\n\tmatrix(const std::vector<T>& dat) : dat(dat),\
    \ r(dat.size()), c(dat[0].size())  {}\n\tmatrix(std::size_t r, std::size_t c)\
    \ : dat(r, std::vector<T>(c)), r(r), c(c) {}\n\tmatrix(const matrix<T>& mat) :\
    \ dat(mat.r, std::vector<T>(mat.c)), r(mat.r), c(mat.c) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] = mat[i][j];\n\t\t\t}\n\t\t}\t\n\t}\n\n\tstd::vector<T>& operator[](std::size_t\
    \ i) {\n\t\treturn dat[i];\n\t}\n\tconst std::vector<T>& operator[](std::size_t\
    \ i) const {\n\t\treturn dat[i];\n\t}\n\n\tmatrix& operator+=(const matrix<T>&\
    \ mat) {\n\t\tfor (std::size_t i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < c ; j++) {\n\t\t\t\tdat[i][j] += mat[i][j];\n\t\t\t}\n\t\t}\n\t\t\
    return *this;\n\t}\n\tmatrix operator+(const matrix<T>& mat) {\n\t\treturn matrix(*this)\
    \ += mat;\n\t}\n\n\tmatrix& operator-=(const matrix<T>& mat) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < c ; j++) {\n\t\t\t\
    \tdat[i][j] -= mat[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\tmatrix& operator-(const\
    \ matrix<T>& mat) {\n\t\treturn matrix(*this) -= mat;\t\n\t}\n\n\tmatrix operator*(const\
    \ matrix<T>& mat) {\n\t\tmatrix res(r, mat.c);\n\t\tfor (std::size_t i = 0 ; i\
    \ < r ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < mat.c ; j++) {\n\t\t\t\tfor\
    \ (std::size_t k = 0 ; k < c ; k++) {\n\t\t\t\t\tres[i][j] += dat[i][k] * mat[k][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\tmatrix operator*=(const matrix<T>&\
    \ mat) {\n\t\treturn (*this) = (*this) * mat;\n\t}\n\n\tmatrix pow(long long p);\n\
    };\n\ntemplate <class T>\nmatrix<T> id_mul(std::size_t n) {\n\tmatrix<T> res(n,\
    \ n);\n\tfor (std::size_t i = 0 ; i < n ; i++) {\n\t\tres[i][i] = 1;\n\t}\n\t\
    return res;\n}\n\ntemplate <class T>\nmatrix<T> matrix<T>::pow(long long p) {\n\
    \tmatrix<T> res = id_mul<T>(this->r);\n\tmatrix<T> base(*this);\n\twhile (p >\
    \ 0) {\n\t\tif (p & 1) {\n\t\t\tres *= base;\n\t\t}\n\t\tbase *= base;\n\t\tp\
    \ >>= 1;\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/matrix.hpp
  requiredBy: []
  timestamp: '2023-01-19 10:12:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/EDPC-R.test.cpp
  - test/matrix.test.cpp
documentation_of: src/math/matrix.hpp
layout: document
title: "matrix (\u884C\u5217)"
---

## 概要

行列の演算をサポートします。

## 機能

**コンストラクタ**

`matrix<T>(const std::vector<std::vector<T>>& dat)`
- `T`: 行列の型、`int`や`long long`、`modint`など
- `dat`:  行列を`dat`で初期化する

`matrix<T>(std::size_t r, std::size_t c)`
- $r\times c$ 行列を各要素 $0$ で初期化する

`matrix<T>(const matrix<T>& mat)`
- コピーコンストラクタ

**メンバ変数**

`std::size_t h`
- 行数

`std::size_t w`
- 列数

`r`と`c`のほうがよかったな。すみません.....

**operator**

`std::vector<T> operator[](std::size_t i)`
- `i`行目を`std::vector<T>`の型で返します。

`matrix<T> operator+(const matrix<T>& mat)`
- $A + B$

`matrix<T>& operator+=(const matrix<T>& mat)`
- $A\ \leftarrow\  A + B$

`matrix<T> operator-(const matrix<T>& mat)`
- $A - B$
- **未テスト**

`matrix<T>& operator-=(const matrix<T>& mat)`
- $A\ \leftarrow\ A - B$
- **未テスト**

`matrix<T> operator*(const matrix<T>& mat)`
- $A\times B$
- **計算量** : $O(NMK)$
	- $N\ =$ `(*this).w`
	- $M\ =$ `(*this).h == mat.w` 
	- $K\ =$ `mat.h`

`matrix<T>& operator*=(const matrix<T>& mat)`
- $A\ \leftarrow\ A\times B$

**メンバ関数**

`matrix<T> matrix<T>::pow(long long p)`
- $A^p$ を返します。
- **計算量**: `n`行`n`列の行列なら $O(n^3\log p)$

**その他関数**

`matrix<T> id_mul<T>(std::size_t n)`
- `n`行`n`列の単位行列を返します。
