---
title: Kadane's Algorithm (最大連続部分和)
documentation_of: //src/algorithm/Kadane.hpp
---

## 概要
```
Kadane(std::vector<T>& arr, T init)
```

一次元配列に対して最大連続部分和を求めます。

サイズ$N$の数列$A$の最大連続部分和とは$1 \le l \le N$と$i \le r \le N$を満たす$(l, r)$の組の中で$\displaystyle \sum_{i=l}^{r} A_i$の最大値を指します。


### 機能
* `コンストラクタ`: 最大連続部分和を求めたい配列の参照と下限値を引数にとります。下限値は配列の最小値より小さい数をとるようにしてください

* `build()`: 最大連続部分和を計算し、 `res`に和を、`segment`に最大連続部分和をとる区間（半開区間）を代入します。

* `get()`: `res`を得ます

* `get_seg()`: `segment`を得ます


### 計算量
* `build()`・・・$O(N)$
