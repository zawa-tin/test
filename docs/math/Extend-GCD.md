---
title: Extend GCD (拡張ユークリッドの互除法)
documentation_of: //src/math/Extend-GCD.hpp
---

## 概要
```
std::pair<long long, long long> extend_gcd(long long a, long long b)
```

$ax + by = gcd(a, b)$の解を`std::pair<long long>`型で返します。

$gcd(a, b)$ は $a$ と $b$ の最大公約数を指します。

[もっと詳しく(ライブラリノート)](../../notes/Extend-GCD-note.md)


## 機能
```
void rec(long long a, long long b, long long& x, long long& y)
```
を呼び出して求めています。返り値がバグっていたらここがバグっています。多分


## 参考
[拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜](https://qiita.com/drken/items/b97ff231e43bce50199a)

## 計算量
$O(log\ max(a, b))$
