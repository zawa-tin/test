---
title: sq-decomp (平方分割による区間クエリ)
documentation_of: //src/dataStructure/sq-decomp.hpp
---

## 概要

平方分割によって区間クエリに答えます。

モノイド $(S, \oplus)$ に対して、 列 $A\ =\ \{ A_1, A_2, \dots,\ A_n\}$ について ( $A_i\ \in S$ ) 以下の二種類のクエリ

- $A_i\ \leftarrow\ x\ (x\in S)$
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

に回答することができます。


## 機能

`zawa::sq_decomp<monoid>(std::size_t n)`
- $A$ をサイズ $n$ で各要素が `monoid::id` の列で初期化します。
- `monoid`: 以下の要素を持つ構造体、モノイドを表現する
	- `using T`: $S$ となる型
	- `static constexpr T id`: $\oplus$ の単位元
	- `static T add(const T& a, const T& b)`: $a\  \oplus\ b$ を返り値とする関数
	- 実装例はsrc/utility/monoid/を確認ください
- **計算量** : $O(n)$

`zawa::sq_decomp<monoid>(const std::vector<monoid::T>& as)`
- $A$ を `as`で初期化します。
- **計算量** : $O(n)$

`void zawa::sq_decomp<monoid>::update(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::T zawa::sq_decomp<monoid>::action(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ A_i\ \oplus\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::T zawa::sq_decomp<monoid>::prod(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます。
- **計算量** : $O(\sqrt{n})$
