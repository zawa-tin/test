---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra1.test.cpp
    title: test/Dijkstra1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra2.test.cpp
    title: test/Dijkstra2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Dijkstra3.test.cpp
    title: test/Dijkstra3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/Dijkstra.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n#include <utility>\n#include <limits>\n\nnamespace zawa {\n\ntemplate\
    \ <class COST>\nclass Dijkstra {\npublic:\n    Dijkstra(std::size_t n) \n    \
    \    : G(n) \n        , dist(n, _inf) \n        , prevs(n, -1) \n        , route(n,\
    \ -1) {}\n\n    struct edge {\n        int from, to;\n        COST cost;\n   \
    \ };\n\n    int add_edge(int from, int to, COST cost) {\n        int res = (int)edges.size();\n\
    \        edges.push_back({ from, to, cost });\n        G[from].emplace_back(res);\n\
    \        return res;\n    }\n\n    edge get_edge(int id) {\n        return edges[id];\n\
    \    }\n\n    void build(int s) {\n        using pci = std::pair<COST, int>;\n\
    \        dist[s] = 0;\n        std::priority_queue<pci, std::vector<pci>, std::greater<pci>>\
    \ que;\n        que.emplace(0, s);\n        while (que.size()) {\n           \
    \ auto [d, v] = que.top();\n            que.pop();\n            if (dist[v] <\
    \ d) {\n                continue;\n            }\n            for (auto id : G[v])\
    \ {\n                edge e = edges[id];\n                if (dist[e.to] > d +\
    \ e.cost) {\n                    dist[e.to] = d + e.cost;\n                  \
    \  prevs[e.to] = v;\n                    route[e.to] = id;\n                 \
    \   que.emplace(dist[e.to], e.to);\n                }\n            }\n       \
    \ }\n    }\n\n    COST inf() {\n        return _inf;\n    }\n\n    COST get_dist(int\
    \ v) {\n        return dist[v];\n    }\n\n    int get_prev(int v) {\n        return\
    \ prevs[v];\n    }\n\n    int get_route(int v) {\n        return route[v];\n \
    \   }\n\nprivate:\n    static constexpr COST _inf = std::numeric_limits<COST>::max();\n\
    \    std::vector<edge> edges;\n    std::vector<std::vector<int>> G; \n    std::vector<COST>\
    \ dist;\n    std::vector<int> prevs;\n    std::vector<int> route;\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <utility>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class COST>\nclass Dijkstra\
    \ {\npublic:\n    Dijkstra(std::size_t n) \n        : G(n) \n        , dist(n,\
    \ _inf) \n        , prevs(n, -1) \n        , route(n, -1) {}\n\n    struct edge\
    \ {\n        int from, to;\n        COST cost;\n    };\n\n    int add_edge(int\
    \ from, int to, COST cost) {\n        int res = (int)edges.size();\n        edges.push_back({\
    \ from, to, cost });\n        G[from].emplace_back(res);\n        return res;\n\
    \    }\n\n    edge get_edge(int id) {\n        return edges[id];\n    }\n\n  \
    \  void build(int s) {\n        using pci = std::pair<COST, int>;\n        dist[s]\
    \ = 0;\n        std::priority_queue<pci, std::vector<pci>, std::greater<pci>>\
    \ que;\n        que.emplace(0, s);\n        while (que.size()) {\n           \
    \ auto [d, v] = que.top();\n            que.pop();\n            if (dist[v] <\
    \ d) {\n                continue;\n            }\n            for (auto id : G[v])\
    \ {\n                edge e = edges[id];\n                if (dist[e.to] > d +\
    \ e.cost) {\n                    dist[e.to] = d + e.cost;\n                  \
    \  prevs[e.to] = v;\n                    route[e.to] = id;\n                 \
    \   que.emplace(dist[e.to], e.to);\n                }\n            }\n       \
    \ }\n    }\n\n    COST inf() {\n        return _inf;\n    }\n\n    COST get_dist(int\
    \ v) {\n        return dist[v];\n    }\n\n    int get_prev(int v) {\n        return\
    \ prevs[v];\n    }\n\n    int get_route(int v) {\n        return route[v];\n \
    \   }\n\nprivate:\n    static constexpr COST _inf = std::numeric_limits<COST>::max();\n\
    \    std::vector<edge> edges;\n    std::vector<std::vector<int>> G; \n    std::vector<COST>\
    \ dist;\n    std::vector<int> prevs;\n    std::vector<int> route;\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2022-11-02 17:08:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dijkstra1.test.cpp
  - test/Dijkstra2.test.cpp
  - test/Dijkstra3.test.cpp
documentation_of: src/graph/Dijkstra.hpp
layout: document
title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
