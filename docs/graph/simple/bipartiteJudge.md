---
title: bipartiteJudge (二部グラフ判定)
documentation_of: //src/graph/simple/bipartiteJudge.hpp
---

## 概要

グラフ $G(V, E)$ が二部グラフであるかを判定します。

二部グラフとは、グラフの各頂点を二色で塗り分ける方法であって、どの辺で隣接する頂点の対も同じ色で塗られないものが存在するものを指します。

## 機能

#### コンストラクタ

```
(1) zawa::bipartiteJudge(const std::vector<std::vector<int>>& G)
(2) zawa::bipartiteJudge<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G)
```

**(1)**

`G` $G$ の隣接リスト表現です。正確には以下の条件を満たす `std::vector<std::vector<int>>` です

頂点 $u$ から頂点 $v$ への有向辺が存在する時、その時に限り `G[u][i] = v` なる $i$ が存在する

AtCoder等のグラフの一般的な入力形式

```

N M

u_1 v_1

...

u_M v_M

```

に対して `zawa::read_graph(n, m)` とすることで対応する `G` を作成することが可能です。

<br />

**(2)**

辺重みがある $G$ に対してはこちらを利用します。

頂点 $u$ から頂点 $v$ へのコスト`c`の有向辺が存在する時、その時に限り `G[u][i] = std::pair<int, cost_type>(v, c)` なる $i$ が存在する

ことが`G`の条件です

**計算量**: (1)(2)共に $O(\mid V\mid + \mid E\mid)$

<br />

#### operator

**[]**
```
inline bool operator[](int i)
```

$G$ が二部グラフであった場合、このclassはある条件を満たす二色の塗り分けを行っている。このoperatorはそのような塗り分け方を一つ行ったときの頂点 $i$ の色を返す。
- 条件を満たす塗り分け方が複数存在する場合、そのどれが採用されているかは不明

**制約**

$0\ \le\ i\ <\ \mid V\mid$

$G$ が二部グラフである
- 後述のメンバ関数、`ok`で二部グラフかどうかを判定できます。

**計算量**

$O(1)$


<br />

#### メンバ関数

**ok**
```
inline bool ok() const
```

$G$ が二部グラフであるかを判定します。

**計算量**

$O(1)$
