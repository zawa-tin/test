---
title : connectedComponents (連結成分分解 simple ver)
documentation_of: //src/graph/simple/connectedComponents.hpp
---

## 概要

与えられた無向グラフ $G(V, E)$ を連結成分に分解します。

ある頂点の二つ組 $(u, v)$ $u \in V, v \in V$ について、 $u$ から $v$ へのパスが存在する時またその時に限り $u$ と $v$ は同じ連結成分に属します。

## 機能

**コンストラクタ**

`zawa::connectedComponents(const std::vector<std::vector<int>>& G)`

`zawa::connectedComponents<cost_type> cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- `G`: グラフの隣接リストを表す`std::vector<std::vector<int>>`
	- `zawa::read_graph`を用いるとAtCoderの入力形式から対応する`G`を作ることができます
	- 重み付きグラフの場合は`std::vector<std::vector<std::pair<int, cost_type>>>`です。
- ***計算量***: $O(\mid V\mid + \mid E\mid)$

**オペレータ**

 `inline std::vector<int> operator[](int i) const`
 - 頂点 $i$ が含まれる連結成分の`id`を返します。
 - $0\ \le\ i\ <\ \mid V\mid$

**メンバ関数**

`inline std::size_t size() const`
- 連結成分の個数を返します

`inline std::size_t size(int x) const`
- 頂点`x`が属する連結成分の頂点数を返します。
- **単体テストをまだしていません**
	
`inline std::vector<std::vector<int>> comps() const`
- 連結成分の分解状況を返します。
	- [AC Library dsu](https://atcoder.github.io/ac-library/production/document_ja/dsu.html) の`groups`と同じノリです
	- 頂点番号に対して昇順に並んでいます

`inline std::vector<int> comp(int id) const`
- `id` が振られた連結成分の頂点集合を返します。
	- `cc.comps()[id]`と等価です。
	- **単体テストをまだしていません**

`bool same(int i, int j) const`
- 頂点 $i$ と頂点 $j$ が同じ連結成分に属するかを判定します。
	- `cc[i] == cc[j]`と等価です。
- **計算量** $O(1)$
