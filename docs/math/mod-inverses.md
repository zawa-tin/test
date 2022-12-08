---
title: mod-inverses (mod逆元列挙、二項係数)
documentation_of: //src/math/mod-inverses.hpp
---

## 概要
```
zawa::Binary_Coeff<mod>(int n)
```

サイズ $n$ の階乗テーブルと逆元の階乗テーブルを作成します。


## 機能
- `mod_inverses<mod> mi(std::size_t size)`
	- コンストラクタ
	- `mod`: テンプレート引数、 $\pmod{P}$ の $P$ を入れてください
		- `mod` は素数である必要があります。
	- `size`: 取得する最大サイズ
	- **計算量** : $O(\text{size})$

- `inline long long mi.inv(int x)`
	- $ax \equiv 1\pmod{P}$ を満たす $a$ を返します。
	- **単体テストをしていません** (TODO)
	- $1\ \le\ x\ \le\ \text{size}$
	- **計算量** : $O(1)$

- `inline long long mi.inv_fac(int x)`
	- $a(x!)\ \equiv\ \pmod{P}$ を満たす $a$ を返します。
	- **単体テストをしていません** (TODO)
	- $1\ \le\ x\ \le\ \text{size}$
	- **計算量** : $O(1)$

- `long long mi.comb(int n, int r, bool check = true)`
	- $\binom{n}{r}$ を $P$ で割った余りを返します。
	- `check`: `true`だと境界値チェックをはさみ、失敗すると`-1`を返すようになります。デバッグ用
	- $0\ \le\ r\ \le\ n\ \le\ \text{size}$
	- **計算量** : $O(1)$

## 参考

[Tweet by @catupper](https://twitter.com/catupper/status/1340573042204844035)
