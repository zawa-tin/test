---
title: reachability (到達可能性)
documentation_of: //src/graph/simple/reachability.hpp
---

## 概要

有向グラフ $G(V, E)$ 上での頂点 $\text{from}$ から頂点 $\text{to}$ へ到達可能かを判定します。

DFSによる愚直な実装です。

無向グラフに関しては連結成分分解 (`zawa::connected_components::same`) で全く同じことができる上、クエリ回答が可能です。


## 機能

**関数**

`bool zawa::reachability(std::vector<std::vector<int>>& G, int from, int to)`
- `G`: $G$ の隣接リスト表現
	- `G`: $u$ から $v$ への有向辺が存在する時、またその時に限り `G[u][i] = v`なる`i`が存在するようにする
	- AtCoderなどでは`zawa::read_graph(n, m)`とすることで入力から対応する`G`を作成することが可能です。 ( $n\ =\ \mid V\mid, m\ =\ \mid E\mid$ )
- `from`: $\text{from}$
- `to`: $\text{to}$
- 返り値: 到達可能なら`true`、そうでないなら`false`
- **計算量** : $O(\mid V\mid + \mid E\mid)$

`bool zawa::reachability(std::vector<std::vector<std::pair<int, cost_type>>>& G, int from, int to)`
- $E$ に重みがついている場合はこちらをお使いください
	- 最短経路等は求めません。(ダイクストラとか書いて)
- **未テスト**

## 余談

到達可能性問題がクエリとしてたくさん飛んでくる場合
- scc + bitset高速化
- 平面グラフならもっと早いのがあるっぽい？
