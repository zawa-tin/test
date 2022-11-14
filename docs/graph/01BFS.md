---
title: 01BFS (幅優先探索)
documentation_of: //src/graph/01BFS.hpp
---

## 概要

```
zawa::Zero_One_BFS(std::size_t n)
```

辺の重みが0又は1のグラフにおいて幅優先探索を行い、単一始点最短経路を求めます。

## 機能

- `コンストラクタ`: 頂点数を引数に取ります。負でない整数を入れてください
$0\ \le\ N\ \le\ 2^{31} - 1$
- `int add_zero_edge(int from, int to)`: `from`から`to`へ重み0の有向辺を追加します。追加された辺の番号を返します(0-indexed)。
- `int add_one_edge(int from, int to)`: `from`から`to`へ重み1の有向辺を追加します。追加された辺の番号を返します(0-indexed)。

$0\ \le\ \text{from},\ \text{to}\ \le\ N - 1$

- `edge構造体`: `from`、`to`が`int`型、`cost`が`bool`型

- `edge get_edge(int id)`: `id`番目に追加された辺の情報を返します(境界値チェックが無いことに注意)。
- `void build(int s)`: 頂点`s`からの単一始点最短経路を求めます。それ以前のbuildの情報が失われることに注意してください
- `int inf()`: コストの初期値を返します。（すなわち、頂点`s`から到達できない頂点の距離に`inf()`が記録されています。
- `int get_dist(int v)`:  頂点`s`から頂点`v`への最短距離を返します。
- `int get_prev(int v)`: 頂点`s`を根としたグラフの最短経路木を生成した時、頂点`v`の親を返します。
- `int get_route(int v)`: 頂点`s`を根としたグラフの最短経路木を生成した時、頂点`v`の親と`v`自身をつないでいる辺の番号を返します。


## 計算量
`build`は $O(N + M)$ ($M$ は辺数)
