---
title: bipartite graph judge (二部グラフ判定 simple ver）
documentation_of: //src/graph/simple/bipartite-judge.hpp
---

## 概要
グラフが二部グラフであるかを判定します。

二部グラフとは、どの辺の両端点も同じ集合に属さない様に、頂点集合を二つの集合に分割する方法が存在するグラフです。


## 機能

- `std::vector<int> zawa::bipartite_judge(std::vector<std::vector<int>>& G)`
	- コスト無しグラフ $G(V, E)$ が二部グラフであるかを判定し、二部グラフなら上の条件を満たすような分割を返す。
	- `G`: グラフの隣接リスト表現を表す二次元vector
		- $(u, v)\in E$ ならば $v\in G_i$ となるようにしてください
		- AtCoder等であれば、`zawa::read_graph`を用いて標準入力から対応する`G`を作ることができます
	- **計算量** $O(\mid V\mid\ +\ \mid E\mid)$

- `std::vector<int> zawa::bipartite_judge(std::vector<std::vector<std::pair<int, cost_type>>>& G)`
	- コスト有りver
	- `cost_type`: グラフのコストの型
	- 上と同じ
