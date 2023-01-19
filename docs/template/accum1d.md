---
title: accum1d (累積和)
documentation_of: //src/template/accum1d.hpp
---

## 概要

1次元列の累積和をとります。

詳しくいうと、与えられた列 $A$ に対して、 $\displaystyle S_0\ =\ 0\land S_i\ =\ \sum_{j = 0}^{i - 1} A_j (i > 0)$ を満たす列 $S$ を構築します。

## 機能

**コンストラクタ**
`zawa::accum1d<T>()`
- `T()`**1要素のみの列を構築します**。
- 累積和そのものを考えると0があったほうがいいかなって。困ったら消す。

`zawa::accum1d<T>(const std::vector<T>& A)`
- `A` から $S$ を構築します。
- `std::partial_sum`を内部で利用しています。

`zawa::accum1d<T>(InputIterator begin, InputIterator end)`
- `begin`から`end`までの要素から`S`を構築します。

それぞれ**計算量は**: $O(\mid A\mid)$

**メンバ関数**

`T sum(std::size_t l, std::size_t r)`
- $\displaystyle \sum_{i = l}^{r - i} A_i$ を返す
- $S_r - S_l$ と同義です
- **計算量** : $O(1)$

`std::vector<T>`を継承しているので、`std::vector`の機能がそのまま使えます。

## メモ
- 区間で考えると頭が壊れるので、「左端」と「要素数」を利用して`sum`を呼び出そう。ex) `sum(l, l + p)`

## TODO

- `int`型の列から`long long`型の`accum1d`を構築できるようにする
