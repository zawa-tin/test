---
title: range edge graph (区間に辺を貼るテク)
documentation_of: //src/graph/range-edge-graph.hpp
---

## 概要

$l_1\ \le\ u\ <\ r_1, l_2\ \le\ v\ <\ r_2$ について、 $u$ から $v$ に有向辺を貼るという操作を行うことができる。


## 機能

- `range_edge_graph<cost_type> reg(int n)`
	- コンストラクタ
	- `cost_type`: 辺の重みの型（テンプレート引数）
		- `int`、`long`、`long long`のいずれかでの使用を想定しています。
	- `n`: 頂点数（int）
	- **計算量** : $O(N)$

- `void add_edge(int ul, int ur, int vl, int vr, cost_type w)`
	- 区間 $[ \text{ul},\ \text{ur})$ から区間 $[ \text{vl},\ \text{vr})$ にコスト $\text{w}$ の有向辺を貼る
	- $0\ \le\ \text{ul},\ \text{vl}\ <\ n$
	- $\text{ul}\ \le\ \text{ur}\ \le\ n$
	- $\text{vl}\ \le\ \text{vr}\ \le\ n$
	- **計算量**: $O(\log n)$

- `std::vector<cost_type> dijkstra(int s, cost_type sup = std::numeric_limits<cost_type>::max()`
	- 頂点`s`からの最短経路表を返す。
	- `sup` はデフォルトで値が設定されていますが、自分で指定することを強く推奨します。
	- $0\ \le\ s\ <\ n$
	- `返り値`: 始点`s`から頂点`i`への最短コストが`res[i]`に入る。要素数`n`の`std::vector<cost_type>`
	- **計算量** : 辺の追加回数を $E$ として $O((n + E\log n)\log n)$

## 参考
[tweet by @noshi91](https://twitter.com/noshi91/status/1193177214453338113)

[区間に辺を貼るテクの実装例（Dijkstra法セット）と使用例](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
