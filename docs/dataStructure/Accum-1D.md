---
title: Accum 1D (1次元累積和)
documentation_of: //src/dataStructure/Accum-1D.hpp
---

## 概要
```
Accum_1D(const std::vector<T>& arr)
```

一次元配列に対して累積和を構築します。数列`A`の累積和`S`とは、 $\displaystyle S_i\ =\ \sum_{i = 1}^{i - 1} A_i$ を満たす数列のことです。

~正直自分で書いたほうが早いです~


### 機能
* `コンストラクタ`: 累積和を構築したい配列`A`を引数に取ります。第二引数に初期値 $S_0$ を指定することも可能です。

* `get(int idx)`: 元の列の`idx`番目の要素を取得します。

* `query(int l, int r)`: $\displaystyle \sum_{i = l}^{r - 1} A_i$ を返します。


### 計算量
* `コンストラクタ`・・・ 配列の長さを $N$ として、 $O(N)$

* `get()`・・・定数時間

* `query()`・・・定数時間
