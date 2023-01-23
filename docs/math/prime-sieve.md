---
title: prime-sieve (エラトステネスの篩)
documentation_of: //src/math/prime-sieve.hpp
---

## 概要

[エラトステネスの篩](https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9)アルゴリズムによって入力で与えられる非負整数 $n$ 以下の素数を列挙します。

## 機能

**コンストラクタ**

`zawa::prime_sieve()`
- デフォルトコンストラクタ、何もしない

`zawa::prime_sieve(std::size_t n)`
- $n$ を入力で与えます
- **計算量** : $O(n\log (\log n))$

**メンバ関数**

とくになし

**operator**

`bool [](std::size_t i)`:  `i` が素数かを判定します。
- テーブルへの参照はできません
- **計算量** : $O(1)$
