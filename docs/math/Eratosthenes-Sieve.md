---
title: Eratosthenes Sieve (素数テーブル)
documentation_of: //src/math/Eratosthenes-Sieve.hpp
---

## 概要
```
Eratosthenes_Sieve(int n)
```

 $N$ 以下の正の整数全てについて素数であるかの正否を求めます。

## 機能
* `コンストラクタ`: $N$ を引数に入れます。素数テーブルを構築します。

* `is_prime(int x)`: $x$ が素数であるかを`bool`値で返します。


## 計算量
* `コンストラクタ`: $O(Nlog(log\ N))$

* `is_prime`: 定数
