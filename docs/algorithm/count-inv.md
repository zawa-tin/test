---
title: count-inv (転倒数)
documentation_of: //src/algorithm/count-inv.hpp
---

## 概要

列に対して転倒数を求めます。配列$A$の転倒数とは$i < j$かつ$A_i > A_j$を満たす順序対$(i, j)$の総数を指します。

内部実装にマージソートを用いています。


### 機能
`long long count_inv<T>(const std::vector<T>& ins)`
- `ins`の転倒数を求めます。
- **計算量** : $O(N\log N)$
	- (`ins`の長さを $N$ とする)
