---
title: wf (ワーシャルフロイド simple ver)
documentation_of: //src/graph/simple/wf.hpp
---

## 概要

辺重み付きグラフ $G(V, E)$ の全対間最短経路を計算します。

## 機能

`std::vector<std::vector<cost_type>> wf<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G, cost_type inf = std::numeric_limits<cost_type>::max() / 3)`

- `cost_type`: 辺の重みの型(テンプレート引数)
	- `int`、`long`、`long long`以外での使用を想定していません。

- `G`: グラフの隣接リストを表す二次元`vector`
	- `u`から`v`へのコスト`w`の有向辺 $(u, v, w) \in E$ について、`G[u]`に`std::pair(v, w)`が存在するようにしてください
	- AtCoder等では、`zawa::read_weighted_graph`を用いて標準入力から対応する`G`を生成できます。

- `inf`: テーブル更新の初期値
	- デフォルトで`std::numeric_limits<cost_type>::max() / 3`が定められていますが、自分で指定することを強く推奨します。

- `返り値`: 全対間最短経路を表す二次元`vector`
	- `res[i][j]`に頂点`i`から頂点`j`への最短経路の総コストが入ります。
	- 頂点`i`から頂点`j`に到達できない時に、`res[i][j] == inf`とは**限らない**ことに注意してください(チェックの仕方は例えば`test/simple-wf1.test.cpp`を確認してください)

- **計算量**: $O(\mid V \mid^3)$
	- $O(\mid V \mid^3\ +\ \mid E \mid)$ なのかなと思ったけど、そもそも $\mid E\mid < \mid V \mid^2$ なので....
		- 多重辺？知らない子ですね....
