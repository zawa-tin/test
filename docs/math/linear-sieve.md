---
title: linear-sieve (線形篩・素因数分解/約数列挙)
documentation_of: //src/math/linear-sieve.hpp
---

## 概要

線形篩のアルゴリズムにより、 入力で与えた非負整数 $n$ 以下の最小素因数を列挙します。

素因数分解や約数列挙のクエリがたくさん飛んでくる場合や、素因数で小さいサイズにしていくタイプの動的計画法で利用できたりします。

## 機能

**コンストラクタ**

`zawa::linear_sieve()`
- デフォルトコンストラクタ

`zawa::linear_sieve(std::size_t n)`
- 入力に $n$ を与えて、 $n$ 以下の最小素因数を列挙する。
- **計算量** : $O(n)$

**メンバ関数**

`std::vector<std::pair<int, int>> factorize(int x)`
- $x$ を素因数分解する。
- `(first, second) = 素因数、次数`である
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(\log x)$ (多分 <- カス!)

`std::vector<int> divisor(int x)`
- $x$ の約数を列挙する
	- **昇順に並んでいないことに注意！**
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(\log^2 x)$ (多分 <- カス!)
	- 実装がカス！なのでlogが一個多めについてます。多分(カス！)

`std::vector<int> enumprime()`
- $n$ 以下の素数を昇順に列挙したものを返します。

`bool isprime(int x)`
- $x$ が素数かを判定します。
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(1)$

**operator**

`int [](int x)`
- $x$ の最小素因数を返します。
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(1)$


## 参考

[線形篩](https://37zigen.com/linear-sieve/)
