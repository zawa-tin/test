---
title: Read Weighted Graph (重み付きグラフ入力)
documentation_of: //src/graph/Read-Weighted-Graph.hpp
---

## 概要
```
std::vector<std::vector<std::pair<int, T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true)
```

重み付きグラフの入力に対して隣接リストを作成し、これを返します。


## 機能
- `n`: 頂点数
- `m`: 辺数
- `undirect`: 無向か否か(デフォルトでtrue)
- `minus`: 1-indexedか否か(デフォルトでtrue)
- `返り値`: `std::vector<std::vector<std::pair<int, T>>>`

- `read_weighted_tree`: $m = n - 1$ で`read_weighted_graph`を呼び出します。つまり木
