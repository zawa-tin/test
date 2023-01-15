---
title: compression (座標圧縮)
documentation_of: //src/algorithm/compression.hpp
---

## 概要
長さ $N$ の列 $A$ について以下の情報を管理します
- 要素 $v$ が $A$ の中で何番目に小さいか。

## 機能

`zawa::compression<T>(const std::vector<T>& as)`
- コンストラクタ
- `as` 入力
- **計算量** : $O(N\log N)$

`int zawa::compression<T>::operator[](const T& val)`
- `val`が $A$ の要素で何番目に小さいかを返す。0-indexed
- **計算量** : $O(\log N)$

`int zawa::compression<T>::get(std::size_t i)`
- $A_i$ が $A$ の要素で何番目に小さいかを返す。0-indexed
- **計算量** : $O(\log N)$

`std::size_t zawa::compression<T>::size()`
- $A$ に含まれる要素の種類数を返す
- **計算量** : $O(1)$
