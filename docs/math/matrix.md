---
title: matrix (行列)
documentation_of: //src/math/matrix.hpp
---

## 概要

行列の演算をサポートします。

## 機能

`matrix<T>(const std::vector<std::vector<T>>& dat)`

`matrix<T>(std::size_t r, std::size_t c)`

`matrix<T>(const matrix<T>& mat)`
- コンストラクタ
- `T`: 行列の型、`int`や`long long`、`modint`など
- `dat`: 扱いたい行列を表す二次元`std::vector`
- `r`、`c`: 行列の行数と列数、こちらのコンストラクタは各成分を0で初期化します。
- ３つ目のコンストラクタはコピーコンストラクタ

`std::size_t matrix<T>::h`
- 行数をもつpublic変数

`std::size_t matrix<T>::w`
- 列数をもつprivate変数

`std::vector<T> matrix<T>::operator[](std::size_t i)`
- `i`行目を`std::vector<T>`の型で返します。

`+`、`+=`、`-`、`-=`、`*`、`*=`の`operator`を整備してあります。
- **`-`は未verifyなので注意**
- `assert`をかけてないので、行数、列数には注意してください


`matrix<T> id_mul<T>(std::size_t n)`
- `n`行`n`列の単位行列を返します。

`matrix<T> matrix<T>::pow(long long p)`
- `p`を返します。
- **計算量**: `n`行`n`列の行列なら $O(n^3\log p)$
