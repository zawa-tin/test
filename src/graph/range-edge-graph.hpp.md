---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/range-edge-graph1.test.cpp
    title: test/range-edge-graph1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/range-edge-graph2.test.cpp
    title: test/range-edge-graph2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/range-edge-graph.hpp\"\n\n#include <vector>\n\
    #include <queue>\n#include <utility>\n#include <limits>\n\nnamespace zawa {\n\n\
    template <class cost_type>\nclass range_edge_graph {\nprivate:\n    int n;\n \
    \   std::vector<std::vector<std::pair<int, cost_type>>> G;\n\n    void add_edge(int\
    \ u, int v, cost_type cost) {\n        if (u >= 3 * n) {\n            u -= 2 *\
    \ n;\n        }\n        G[u].emplace_back(v, cost);\n    }\n\npublic:\n    range_edge_graph(int\
    \ n) : n(n), G(3 * n) {\n        for (int i = 1 ; i < n ; i++) {\n           \
    \ int child_l = ((i << 1) | 0), child_r = ((i << 1 | 1));\n            add_edge(i,\
    \ child_l, 0);\n            add_edge(i, child_r, 0);\n            add_edge(child_l\
    \ + 2 * n, i + 2 * n, 0);\n            add_edge(child_r + 2 * n, i + 2 * n, 0);\n\
    \        }\n    }\n\n    void add_edge(int ul, int ur, int vl, int vr, cost_type\
    \ cost) {\n        int id = G.size();\n        for (int l = ul + n, r = ur + n\
    \ ; l < r ; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                add_edge(l\
    \ + 2 * n, id, 0);\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                add_edge(r + 2 * n, id, 0);\n     \
    \       }\n        }\n        std::vector<std::pair<int, cost_type>> node;\n \
    \       for (int l = vl + n, r = vr + n ; l < r ; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) {\n                node.emplace_back(l, cost);\n           \
    \     l++;\n            }\n            if (r & 1) {\n                r--;\n  \
    \              node.emplace_back(r, cost);\n            }\n        }\n       \
    \ G.push_back(node);\n    }\n\n    std::vector<cost_type> dijkstra(int s, cost_type\
    \ sup = std::numeric_limits<cost_type>::max()) {\n        std::priority_queue<\n\
    \            std::pair<cost_type, int>, \n            std::vector<std::pair<cost_type,\
    \ int>>, \n            std::greater<std::pair<cost_type, int>>\n             \
    \   > que;\n        que.emplace((cost_type)0, s + n);\n        std::vector<cost_type>\
    \ dist(G.size(), sup);\n        dist[s + n] = (cost_type)0;\n        while (que.size())\
    \ {\n            auto [d, v] = que.top();\n            que.pop();\n          \
    \  if (d > dist[v]) {\n                continue;\n            }\n            for\
    \ (auto [x, cost] : G[v]) {\n                if (dist[x] > d + cost) {\n     \
    \               dist[x] = d + cost;\n                    que.emplace(d + cost,\
    \ x);\n                }\n            }\n        }\n        return std::vector<cost_type>(dist.begin()\
    \ + n, dist.begin() + 2 * n);\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <utility>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class cost_type>\nclass range_edge_graph\
    \ {\nprivate:\n    int n;\n    std::vector<std::vector<std::pair<int, cost_type>>>\
    \ G;\n\n    void add_edge(int u, int v, cost_type cost) {\n        if (u >= 3\
    \ * n) {\n            u -= 2 * n;\n        }\n        G[u].emplace_back(v, cost);\n\
    \    }\n\npublic:\n    range_edge_graph(int n) : n(n), G(3 * n) {\n        for\
    \ (int i = 1 ; i < n ; i++) {\n            int child_l = ((i << 1) | 0), child_r\
    \ = ((i << 1 | 1));\n            add_edge(i, child_l, 0);\n            add_edge(i,\
    \ child_r, 0);\n            add_edge(child_l + 2 * n, i + 2 * n, 0);\n       \
    \     add_edge(child_r + 2 * n, i + 2 * n, 0);\n        }\n    }\n\n    void add_edge(int\
    \ ul, int ur, int vl, int vr, cost_type cost) {\n        int id = G.size();\n\
    \        for (int l = ul + n, r = ur + n ; l < r ; l >>= 1, r >>= 1) {\n     \
    \       if (l & 1) {\n                add_edge(l + 2 * n, id, 0);\n          \
    \      l++;\n            }\n            if (r & 1) {\n                r--;\n \
    \               add_edge(r + 2 * n, id, 0);\n            }\n        }\n      \
    \  std::vector<std::pair<int, cost_type>> node;\n        for (int l = vl + n,\
    \ r = vr + n ; l < r ; l >>= 1, r >>= 1) {\n            if (l & 1) {\n       \
    \         node.emplace_back(l, cost);\n                l++;\n            }\n \
    \           if (r & 1) {\n                r--;\n                node.emplace_back(r,\
    \ cost);\n            }\n        }\n        G.push_back(node);\n    }\n\n    std::vector<cost_type>\
    \ dijkstra(int s, cost_type sup = std::numeric_limits<cost_type>::max()) {\n \
    \       std::priority_queue<\n            std::pair<cost_type, int>, \n      \
    \      std::vector<std::pair<cost_type, int>>, \n            std::greater<std::pair<cost_type,\
    \ int>>\n                > que;\n        que.emplace((cost_type)0, s + n);\n \
    \       std::vector<cost_type> dist(G.size(), sup);\n        dist[s + n] = (cost_type)0;\n\
    \        while (que.size()) {\n            auto [d, v] = que.top();\n        \
    \    que.pop();\n            if (d > dist[v]) {\n                continue;\n \
    \           }\n            for (auto [x, cost] : G[v]) {\n                if (dist[x]\
    \ > d + cost) {\n                    dist[x] = d + cost;\n                   \
    \ que.emplace(d + cost, x);\n                }\n            }\n        }\n   \
    \     return std::vector<cost_type>(dist.begin() + n, dist.begin() + 2 * n);\n\
    \    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/range-edge-graph.hpp
  requiredBy: []
  timestamp: '2022-12-14 06:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/range-edge-graph1.test.cpp
  - test/range-edge-graph2.test.cpp
documentation_of: src/graph/range-edge-graph.hpp
layout: document
title: "range edge graph (\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF)"
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
