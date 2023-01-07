---
title: topo-sort (トポロジカルソート simple ver)
documentation_of: //src/graph/simple/topo-sort.hpp
---

## 概要
有効グラフ $G(V, E)$ をトポロジカルソートします。

トポロジカルソートについては[Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88) を確認してください

## 機能

`topo_sort(const std::vector<std::vector<int>>& G)`

`topo_sort<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- コンストラクタ
- (可能ならば) トポロジカルソートした頂点番号の列を一つ構築します。
- `G`: $G$ の隣接リスト
	- $(i, x)\ \in\ E$ なるすべての $x$ について、$x\ \in$ `G[i]`であれば良いです。
	- 辺に重みがあるグラフでは下のコンストラクタ
	- `zawa::read_graph` でAtCoderの入力形式から対応する`G`を作成できます。
- **計算量**: $(O(\mid V\mid\ +\ \mid E\mid))$


`bool topo_sort::ok()`
- $G$ がDAGかどうか（トポロジカルソートができたか）を判定します。
- **単体テストをしていません**
- **計算量** : $O(1)$

`int topo_sort operator[](int i)`
- ソート列における $i$ 番目の頂点を返します。
- 値返しなので書き換えできないことに注意してください

`std::vector<int> topo_sort::get()`
- ソート列を返します。
- **単体テストをしていません**
