---
title: Compression (座標圧縮)
documentation_of: //src/algorithm/Compression.hpp
---

## 概要
```
Compression<T>(const std::vector<T>& in)
```
座標圧縮します。

配列`A`からなる集合から集合 $\{\ 0,\ 1,\ 2,\ \cdots,\ K - 1\}$ ( $K$ は`A`に出現する要素の種類数) への全射 $F$ を構築します。
-	`A_i`が`A`の中で $p$ 番目に小さいなら $F(A_i)\ =\ p - 1$ 

## 機能

- `コンストラクタ`: 座標圧縮します。

- `get(T val)`: $F(val)$ を取得します。
	- `val` は`A`に出現する値である必要があります。そうじゃない値を入れる使い方があるかもしれない？

## 計算量
- `コンストラクタ`: 配列の要素数を $N$ として $O(N log N)$
- `get`: $O(logK)$
