---
title: mobius-function (メビウス関数)
documentation_of: //src/math/mobius-function.hpp
---

## 概要

入力で与える非負整数 $n$ 以下の[メビウス関数](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0)値を列挙します。

メビウス関数 $\mu(i)$ とは以下で定義されます。( $i > 0$ )

- $i$ が平方数( $k^2$ で表される数) で割り切れるなら 0
- $i$ が異なる $k$ 個の素数の積表せるなら $(-1)^k$
- $i$ が1なら $1$

約数系で包除原理をする時に、この関数の値が出現する。

## 機能

**コンストラクタ**

`zawa::mobius_function()`
- デフォルトコンストラクタ、なにもしない

`zawa::mobius_function(std::size_t n)`
- `n` 以下のメビウス関数値を列挙する
- **計算量**: $O(n\log (\log n))$

**operator**

`int [](int i)`
- $\mu(i)$ を返します
- **計算量** : $O(1)$

## 参考

[# エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
