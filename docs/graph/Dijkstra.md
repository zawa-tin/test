---
title: Dijkstra (ダイクストラ法)
documentation_of: //src/graph/Dijkstra.hpp
---

## 概要

```
zawa::Dijkstra<COST>(n)
```
$n$ 頂点のグラフについて単一始点最短経路を求めます。

`std::priority_queue`を利用しています。
- (TODO:フィボナッチヒープ版も作ってみる)

## 機能
- `コンストラクタ`: `COST`には重みの型を入れてください
- `add_edge(int from, int to, COST cost)`: `from` から `to` へ重み`cost`の有向辺を追加します。追加された辺の番号を返します。
- `get_edge(int id)`: `id`番目(0-indexed)に追加された辺を返します。`int from, int to, COST cost`からなる`edge`構造体です。
- `build(int s)`: 始点`s`から他全ての頂点への最短経路を求めます。
- `inf()`: `std::numeric_limits<COST>::max()`を返します。始点`s`から到達できない頂点`v`に対して`dist_v = inf()`です。
- `get_dist(int v)`: 頂点`v`までの最短経路のコストを返します
- `get_prev(int v)`: 最短経路木について、`v`の親を返します。始点（根）`s`は-1が返ります
- `get_route(int v)`: 最短経路木について、`v`の親と自身を繋ぐ辺の番号を返します。`s`に対しては-1が返ります。

## 計算量
- `build`: $O((\mid V\mid + \mid E \mid) \log( \mid V\mid))$
