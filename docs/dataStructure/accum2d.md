---
title: accum2d (二次元累積和)
documentation_of: //src/dataStructure/accum2d.hpp
---

## 概要

与えられた行列 $A$ の二次元累積和 $S$ をとります。

詳しく言うと、 $\displaystyle S_{00}\ =\ 0\ \land\ S_{yx}\ =\ \sum_{i = 0}^{y - 1} \sum_{j = 0}^{x - 1} A_{yx}$ を満たす行列 $S$ を構築します。

## 機能

**コンストラクタ**

`zawa::accum2d<T>(const std::vector<std::vector<T>>& A)`
- 二次元`std::vector<T>` `A`から $S$ を構築します。
- `A` の行数、列数は共に1以上である必要があります。
- **計算量** : `A`の行数を $H$ 、列数を $W$ として $O(HW)$

`zawa::accum2d<T>()`
- 1 x 1の `T()`のみの `std::vector<std::vector<T>>`を構築します。
- 空でないことに注意

**メンバ関数**

`T sum(int y1, int x1, int y2, int x2)`
- $\displaystyle \sum_{i = \text{y1}}^{\text{y2} - 1} \sum_{j = \text{x1}}^{\text{x2} - 1} A_{ij}$ を返します。
- **計算量** $O(1)$

`std::vector<std::vector<T>>`を継承しているので、STLの機能が使えます。
