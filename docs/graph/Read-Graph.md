---
title: ReadvGraph (グラフ入力)
documentation_of: //src/graph/Read-Graph.hpp"
---

## 概要
```
std::vector<std::vector<int>> read_graph(int n, int m, bool undirect = true, bool minus = true)
```
グラフを隣接リスト表現で受け取ります

## 機能
- `n`: 頂点数
- `m`: 辺数
- `undirect`: 無向グラフか否か（デフォルトでtrue)
- `minus`: 1-indexedか否か(デフォルトでtrue)
- `返り値`: `std::vector<std::vector<int>>`

- `read_tree`:  $m = n - 1$ の`read_graph`を呼び出します。(つまり木)
