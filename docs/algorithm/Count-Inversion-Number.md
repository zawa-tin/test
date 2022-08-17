---
title: Count-Inversion-Number(マージソートによる転倒数の数え上げ)
documentation_of: //src/algorithm/Count-Inversion-Number.hpp
---

## 概要
```
Count_Inversion_Number(std::vector< T >& as)
```


一次元配列に対して転倒数を求めます。配列$A$の転倒数とは$i < j$かつ$A_i > A_j$を満たす順序対$(i, j)$の総数を指します。


### 機能
* `コンストラクタ`: 転倒数を求めたい配列の参照を引数にとります。

* `build()`: 転倒数を計算し、`count_inversion_number`に計算結果を代入します

* `get()`: 転倒数を返します。事前に`build()`を実行してください

* `get_sorted()`: ソートした配列を返します。使いどころが多分無いです


### 計算量
* `build()`・・・ $O(NlogN)$ ( $N$ は配列の要素数)
