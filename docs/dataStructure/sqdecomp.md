---
title: sqdecomp (平方分割による区間クエリ)
documentation_of: //src/dataStructure/sqdecomp.hpp
---

## 概要

平方分割によって区間クエリに答えます。

モノイド $(S, \oplus)$ に対して、 列 $A\ =\ \{ A_1, A_2, \dots,\ A_n\}$ について ( $A_i\ \in S$ ) 以下の二種類のクエリ

- $A_i\ \leftarrow\ x\ (x\in S)$
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

に回答することができます。


## 機能

**コンストラクタ**

`zawa::sqdecomp<monoid>(std::size_t n)`
- $A$ をサイズ $n$ で各要素が `monoid::identity` の列で初期化します。
- `monoid`: 以下の要素を持つ構造体、モノイドを表現する
	- `テンプレート引数`: `S`となる型
	- `using value_type`: $S$ となる型(`T`と同じ)
	- `static constexpr value_type identity`: $\oplus$ の単位元
	- `static T operation(const T& a, const T& b)`: $a\  \oplus\ b$ を返り値とする関数
	- 実装例はsrc/utility/monoid/を確認ください
- **計算量** : $O(n)$

`zawa::sqdecomp<monoid>(const std::vector<monoid::T>& as)`
- $A$ を `as`で初期化します。
- **計算量** : $O(n)$

**メンバ関数**

`void update(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::value_type action(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ A_i\ \oplus\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::value_type prod(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます。
- **計算量** : $O(\sqrt{n})$
