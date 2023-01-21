---
title: binary-seach-ld (浮動小数点数二分探索)
documentation_of: //src/template/binary-search-ld.hpp
---

## 概要

与えられた範囲 $l, r$ と単調性関数 $f\ :\ \{\ p\ \mid\ p\ \in\ \mathbb{R},\ l\ \le\ p\ \le\ r\ \} \rightarrow\ \{\ \text{false},\ \text{true}\ \}$ について $f(p)$ の値が変化する境界値を発見します。


## 機能

**関数**

`T zawa::binary_search<T, F, up = 80>(T ok, T ng, const F& f)`
- `T`: $l, r$ の型、`double`、`long double` などの整数型以外での使用を想定していない
- `F`: `std::function<bool(T)>` が入ることになる。 $p$ を引数にとり、`false`か`true`を返す関数。以下の条件を満たす必要がある。
	- $\text{ok}\ <\ \text{ng}$ の場合、 $\text{ok}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{true}$ が成り立つかつ $x\ <\ p\ \le\ \text{ng}$ なる $p$ について $f(p)\ =\ \text{false}$ となる $x$ が存在する
	- $\text{ok}\ >\ \text{ng}$ の場合、 $\text{ng}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{false}$ となりかつ、 $x\ <\ p\ \le\ \text{ok}$ となる $p$ について $f(p)\ =\ \text{true}$ となる $x$ が存在する
- `up`: $f$ を呼び出す回数。デフォルトで80回となっている。呼び出すほど精度が上がるが、必要以上に呼び出しても無駄なだけなので注意
- `ok`: $f(p)\ =\ \text{true}$ となる値なら良い
- `ng`: $f(p)\ =\ \text{false}$ となる値なら良い
- `f` : $f$
- 上の条件式にでてくる $x$ の値を返します。
- **計算量** : $f(p)$ を`up`回呼び出す。

## 参考

[tweet by @meguru_comp](https://twitter.com/meguru_comp/status/697008509376835584)
