---
title: Miller-Rabin (素数判定法)
documentation_of: //src/math/Miller-Rabin.hpp
---

## 概要
```
miller_isprime(long long n)
```
正整数`n`にが素数かどうかを判定する

##  機能

- 第一引数に素数かどうか判定したいものを入れてください

## 計算量

$O(klog^3 n)$

- `n`が32bit整数だったら`k = 3`、そうでないなら`k = 12`
	- この言い方は多分正しくない・・・・

- 実際は下からmodpowを見ていくことでlogを一つ落とすことが可能
	- TODO: 実装

## 参考

- [wikipedia-ja](https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95)
- [wikipedia-en](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
- [C++の実装で参考にしました](https://joisino.hatenablog.com/entry/2017/08/03/210000)
- [アルゴリズムの理解で参考にしました](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)
