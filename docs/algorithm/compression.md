---
title: compression (座標圧縮)
documentation_of: //src/algorithm/compression.hpp
---

## 概要
長さ $N$ の数列 $A$ について以下の条件を満たす長さ $N$ の数列 $B$ を生成します。
- $A_i$ が $A$ の中で $p$ 番目に小さいなら $B_i\ =\ p - 1$

## 機能

`zawa::compression<T> (const std::vector<T>& arr)`
- `arr`を $A$ として $B$ を生成します（コンストラクタ）。
	- `T` は`std::sort`や`std::lower_bound`などが使える型である必要があります。
- **計算量** : $O(N\log N)$

`compression operator[]`
- $B_i$ を返します
- 書き換え不可です

`T compression::inv(int i)`
- $A_{B_i}$ を返します
- **単体テストをまだしていません**

`std::vector<int> compression::get()`
- $B$ を返します
- **単体テストをまだしていません**
