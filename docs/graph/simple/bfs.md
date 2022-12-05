---
title: bfs (simple ver)
documentation_of: //src/graph/simple/bfs.hpp
---

## 概要
コストなしグラフ $G(V, E)$ の単一始点最短経路問題を解きます。

最短経路木の情報が欲しい場合はsrc/graph/BFS.hppを使ってください

## 機能

`std::vector<int> bfs(const std::vector<std::vector<int>>& G, int s, int inf = 2e9)`
- `G`: グラフの隣接リストを表す二次元`vector`
	- 頂点`i`から頂点`G[i][j]`に有向辺が存在するようにする。
	- AtCoderなら、`zawa::read_graph`で標準入力から対応する`G`を生成できます。

- `s`: 始点

- `inf`: 最短経路テーブルの初期値
	- デフォルトで $2\times 10^9$ ですが、基本自分で指定したほうが良いです。

- `返り値`: `res[i]`には、頂点`s`から頂点`i`へ行くために通る最小辺数が入っています。
	- `s`から`i`へ到達不可能である場合、`inf`が入ります。

- **計算量**: $O(\mid V \mid + \mid E \mid)$
