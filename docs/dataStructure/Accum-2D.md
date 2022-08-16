---
title: Accum 2D (二次元累積和)
documentation_of: //src/dataStructure/Accum-2D.hpp
---

## 概要
```
Accum_2D(const std::vector<std::vector<T>>& arr)
```

二次元配列(行列)に対して累積和を構築します。行列`A`の累積和`S`とは、 $\displaystyle S_{ij}\ =\ \sum_{p = 1}^{i - 1} \sum_{q = 1}^{j - 1} A_{pq}$ を満たす行列のことです。


### 機能
* `コンストラクタ`: 累積和を取りたい配列 $A$ の参照をとる。もしくはサイズのみを指定する。第二引数に32bit整数を入れると $S_{00}$ を指定するることが可能です。

* `set(int y, int x, T val)`: $A_{yx}$ に`val`を代入します。

* `add(int y, int x, T val)`: $A_{yx}$ に`val` を可算します。

  * `set, add`は`build`前に行ってください。
 
* `build()` 累積和を`S`構築します。

* `get(int y, int x)`: $A_{yx}$ を取得します。

* `query(int y1, int x1, int y2, int x2)`: $\displaystyle \sum_{i = y_1}^{y_2 - 1} \sum_{j = x_1}^{x_2 - 1} A_{ij}$ を得ます。


### 計算量
* `build`・・・行列のサイズを $N \times M$ として $O(NM)$
* 他・・・定数時間
