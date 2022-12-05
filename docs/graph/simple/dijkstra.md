---
title: dijkstra (simple ver)
documentation_of: //src/graph/simple/dijkstra.hpp
---

## 概要
辺の重みが非負数であるグラフ $G(V, E)$ の最短経路問題を解きます。

最短経路木の情報が欲しい場合はsrc/graph/Dijkstra.hppを使ってください。

## 機能

```
std::vector<cost_type> dijkstra(const std::vector<std::vector<std::pair<int, cost_type>>>& G, 
int s, cost_type inf = std::numeric_limits<cost_type>::max())
```
- `テンプレート引数`: 辺の重みの型
	- `int`、`long`、`long long`以外での使用を想定していません

- `G`: グラフの隣接リストを表す二次元`vector`
	- `G[i][j] (std::pair<int, cost_type>)`: 頂点`i`から`G[i][j].first`にコスト`G[i][j].second`の有向辺が存在する。
	- AtCoderだったら`zawa::read_weighted_graph<cost_type>`で標準入力から対応する隣接リストを作れます。（有向・無向に注意）

- `s`: 最短経路を求めたい始点

- `inf`: テーブルの初期値
	- 基本自分で指定してください。`std::numeric_limits<cost_type>::max()`がデフォルトで指定されていますが、そのまま使うのはオーバーフローが怖かったり、非連結の時の処理にだるかったりすると思います。

- `返り値`: `res[i]`には始点`s`から頂点`i`への最短経路の総コストが入っています。`s` から`i`に到達不可能な場合、`inf`が入っています。

- `計算量`: $O((\mid V \mid + \mid E \mid)\log (\mid V \mid))$
