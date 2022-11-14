---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/01BFS.test.cpp
    title: test/01BFS.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/01BFS.hpp\"\n\n#include <vector>\n#include <deque>\n\
    #include <limits>\n#include <utility>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\nclass Zero_One_BFS {\npublic:\n\n    struct edge {\n        int from, to;\n\
    \        bool cost;\n    };\n\n    Zero_One_BFS(std::size_t n)\n        : G(n,\
    \ std::vector(0, 0))\n        , edges(0, edge())\n        , dist(n, _inf)\n  \
    \      , prevs(n, -1)\n        , route(n, -1) {}\n\n    int add_zero_edge(int\
    \ from, int to) {\n        return add_edge(from, to, false);\n    }\n\n    int\
    \ add_one_edge(int from, int to) {\n        return add_edge(from, to, true);\n\
    \    }\n\n    inline edge get_edge(int id) {\n        return edges[id];\n    }\n\
    \n    void build(int s) {\n        std::fill(dist.begin(), dist.end(), _inf);\n\
    \        std::fill(prevs.begin(), prevs.end(), -1);\n        std::fill(route.begin(),\
    \ route.end(), -1);\n        dist[s] = 0;\n        std::deque<int> deq({ s });\n\
    \        while (deq.size()) {\n            int v = deq.front();\n            deq.pop_front();\n\
    \            for (auto x : G[v]) {\n                auto [_, t, cost] = edges[x];\n\
    \                if (dist[t] > dist[v] + (int)cost) {\n                    dist[t]\
    \ = dist[v] + (int)cost;\n                    prevs[t] = v;\n                \
    \    route[t] = x;\n                    if (cost) {\n                        deq.push_back(t);\n\
    \                    }\n                    else {\n                        deq.push_front(t);\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    int inf() {\n        return _inf;\n    }\n\n    int get_dist(int v) {\n \
    \       return dist[v];\n    }\n\n    int get_prev(int v) {\n        return prevs[v];\n\
    \    }\n\n    int get_route(int v) {\n        return route[v];\n    }\n\nprivate:\n\
    \    static constexpr int _inf = std::numeric_limits<int>::max();\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n    std::vector<int> dist;\n    std::vector<int>\
    \ prevs;\n    std::vector<int> route;\n    \n    int add_edge(int from, int to,\
    \ bool cost) {\n        int res = (int)edges.size();\n        edges.push_back({\
    \ from, to, cost });\n        G[from].push_back(res);\n        return res;\n \
    \   }\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <deque>\n#include <limits>\n\
    #include <utility>\n#include <algorithm>\n\nnamespace zawa {\n\nclass Zero_One_BFS\
    \ {\npublic:\n\n    struct edge {\n        int from, to;\n        bool cost;\n\
    \    };\n\n    Zero_One_BFS(std::size_t n)\n        : G(n, std::vector(0, 0))\n\
    \        , edges(0, edge())\n        , dist(n, _inf)\n        , prevs(n, -1)\n\
    \        , route(n, -1) {}\n\n    int add_zero_edge(int from, int to) {\n    \
    \    return add_edge(from, to, false);\n    }\n\n    int add_one_edge(int from,\
    \ int to) {\n        return add_edge(from, to, true);\n    }\n\n    inline edge\
    \ get_edge(int id) {\n        return edges[id];\n    }\n\n    void build(int s)\
    \ {\n        std::fill(dist.begin(), dist.end(), _inf);\n        std::fill(prevs.begin(),\
    \ prevs.end(), -1);\n        std::fill(route.begin(), route.end(), -1);\n    \
    \    dist[s] = 0;\n        std::deque<int> deq({ s });\n        while (deq.size())\
    \ {\n            int v = deq.front();\n            deq.pop_front();\n        \
    \    for (auto x : G[v]) {\n                auto [_, t, cost] = edges[x];\n  \
    \              if (dist[t] > dist[v] + (int)cost) {\n                    dist[t]\
    \ = dist[v] + (int)cost;\n                    prevs[t] = v;\n                \
    \    route[t] = x;\n                    if (cost) {\n                        deq.push_back(t);\n\
    \                    }\n                    else {\n                        deq.push_front(t);\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    int inf() {\n        return _inf;\n    }\n\n    int get_dist(int v) {\n \
    \       return dist[v];\n    }\n\n    int get_prev(int v) {\n        return prevs[v];\n\
    \    }\n\n    int get_route(int v) {\n        return route[v];\n    }\n\nprivate:\n\
    \    static constexpr int _inf = std::numeric_limits<int>::max();\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n    std::vector<int> dist;\n    std::vector<int>\
    \ prevs;\n    std::vector<int> route;\n    \n    int add_edge(int from, int to,\
    \ bool cost) {\n        int res = (int)edges.size();\n        edges.push_back({\
    \ from, to, cost });\n        G[from].push_back(res);\n        return res;\n \
    \   }\n};\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/01BFS.hpp
  requiredBy: []
  timestamp: '2022-11-14 21:43:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/01BFS.test.cpp
documentation_of: src/graph/01BFS.hpp
layout: document
title: "01BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
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
