---
title: fenwick_tree (一点加算、区間和取得)
documentation_of: //src/dataStructure/fenwick_tree.hpp
---

## 概要

[フェニック木](https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A7%E3%83%8B%E3%83%83%E3%82%AF%E6%9C%A8) です。

集合と演算の組 $(S, \oplus)$ について
- 結合則
- 交換則
- 単位元の存在
- 逆元の存在

を満たす時、$x\ \in S$ からなる列 $A$ に対して以下のクエリに答えることができます。
- $A_i\ \leftarrow\ A_i\ \oplus\ x$
-  $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

## 機能

**コンストラクタ**

`zawa::fenwick_tree<structure> fen(std::size_t n)`
- $A$ を 長さ $n$ の各要素を `structure::id` で初期化する
- `structure`
	- 以下の要素を持つ構造体
	- `typename T`: 型
	- `static constexpr T id`: 単位元
	- `static T add(const T& a, const t& b)`: 演算
	- `static T inverse(const T& a)`: 逆元を返す
	- 例は`src/utility/fenwick_tree`を確認ください
- **計算量** : $O(n)$

`zawa::fenwick_tree<structure> fen(const std::vector<structure::T>& A)`
- $A$ を`A`で初期化する
- **計算量** : $O(\mid A\mid \log \mid A \mid)$

**メンバ関数**

`void add(int pos, const T& v)`
- $A_{\text{pos}}\ \leftarrow\ A_{\text{pos}}\ \oplus v$ とする
- **制約**: $0\ \le\ \text{pos}\ <\ n$
- **計算量** : $O(\log n)$

`T sum(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます
- **制約**: $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int lower_bound(T val)`
- `sum(0, r) >= val` を満たす最小の`r`を返します。
- **計算量** : $O(\log n)$
