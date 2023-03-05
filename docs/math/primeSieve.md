---
title: primeSieve (エラトステネスの篩）
documentation_of: //src/math/primeSieve.hpp
---

## 概要

[エラトステネスの篩](https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9) アルゴリズムによりある正整数 $n$ 以下の正整数についてそれが素数かそうでないかの是非を保持します。

osa-k法等の高速素因数分解、高速約数列挙をしたい場合は線形篩の方をお使いください


## 機能

#### コンストラクタ

```
(1) zawa::primeSieve() 
(2) zawa::primeSieve(std::size_t n)
```

**(1)**

デフォルトコンストラクタ

**(2)**

`n`以下の正整数について素数判定を行う

**計算量**

$O(n\log (\log n))$

<br />

#### operator

**[]**
```
inline bool operator[](std::size_t i) const
```
$i$ が素数かどうかを`bool`値で返す

**制約**

$0\ <\ i\ \le\ n$

**計算量**

$O(1)$


## メモ

今までテーブルの構築を
```
for (usize i = 2 ; i <= n ; i++) 
	if (table[i])
		for (usize j = i * i ; j <= n ; j += i)
			table[j] = false;
```

とやっていたが、なぜかコドフォで壊れた(LCやAtCでは普通に大丈夫）

ので

```
for (usize i = 2 ; i <= n ; i++)
	if (table[i])
		for (usize j = i * 2 ; j <= n ; j += i)
			table[j] = false;
```

としている。個人的な予想では`usize (=std::size_t)`がなんか悪さしとる

## 参考


[エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
