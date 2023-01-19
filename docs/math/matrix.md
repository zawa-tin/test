---
title: matrix (行列)
documentation_of: //src/math/matrix.hpp
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
