---
title: mobiusFunction (メビウス関数値の列挙)
documentation_of: //src/math/mobiusFunction.hpp
---

## 概要

正整数 $n$ 以下の正整数についてメビウス関数値 $\mu$ を列挙する

メビウス関数とは以下に定義される関数(参考: [wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0)）

- 平方数で割り切れるなら0
- 偶数個の素因数の積で表現されるなら1
- 奇数個の素因数の積で表現されるなら-1

## 機能

#### コンストラクタ

```
(1) zawa::mobiusFunction()
(2) zawa::mobiusFunction(std::size_t n)
```

**(1)**

デフォルトコンストラクタ

**(2)**

$n$ 以下のメビウス関数値を列挙する

**計算量**

$O(n\log (\log n))$

<br />

#### operator

**[]**

```
inline int operator[](std::size_t i) const
```

$\mu(i)$ を返す

**制約**

$1\ \le\ i\ \le\ n$

**計算量**

$O(1)$
