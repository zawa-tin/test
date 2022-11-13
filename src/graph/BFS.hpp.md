---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BFS.test.cpp
    title: test/BFS.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/BFS.hpp\"\n\n#include <queue>\n#include <vector>\n\
    #include <limits>\n#include <utility>\n\nnamespace zawa {\n\nclass BFS {\npublic:\n\
    \n    BFS(std::size_t n)\n        : G(n)\n        , dist(n, _inf)\n        , prevs(n,\
    \ -1)\n        , route(n, -1) {}\n\n    int add_edge(int from, int to) {\n   \
    \     int res = (int)edges.size();\n        edges.push_back({ from, to });\n \
    \       G[from].emplace_back(res);\n        return res;\n    }\n\n    std::pair<int,\
    \ int> get_edge(int id) {\n        return edges[id];\n    }\n\n    void build(int\
    \ s) {\n        dist[s] = 0;\n        std::queue<int> que({ s });\n        while\
    \ (que.size()) {\n            int v = que.front();\n            que.pop();\n \
    \           for (auto x : G[v]) {\n                auto [_, t] = edges[x];\n \
    \               if (dist[t] > dist[v] + 1) {\n                    dist[t] = dist[v]\
    \ + 1;\n                    prevs[t] = v;\n                    route[t] = x;\n\
    \                    que.emplace(t);\n                }\n            }\n     \
    \   }\n    }\n\n    int inf() {\n        return _inf;\n    }\n\n    int get_dist(int\
    \ v) {\n        return dist[v];\n    }\n\n    int get_prev(int v) {\n        return\
    \ prevs[v];\n    }\n\n    int get_route(int v) {\n        return route[v];\n \
    \   }\n\nprivate:\n    static constexpr int _inf = std::numeric_limits<int>::max();\n\
    \    std::vector<std::pair<int, int>> edges;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> dist;\n    std::vector<int> prevs;\n    std::vector<int>\
    \ route;\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <queue>\n#include <vector>\n#include <limits>\n\
    #include <utility>\n\nnamespace zawa {\n\nclass BFS {\npublic:\n\n    BFS(std::size_t\
    \ n)\n        : G(n)\n        , dist(n, _inf)\n        , prevs(n, -1)\n      \
    \  , route(n, -1) {}\n\n    int add_edge(int from, int to) {\n        int res\
    \ = (int)edges.size();\n        edges.push_back({ from, to });\n        G[from].emplace_back(res);\n\
    \        return res;\n    }\n\n    std::pair<int, int> get_edge(int id) {\n  \
    \      return edges[id];\n    }\n\n    void build(int s) {\n        dist[s] =\
    \ 0;\n        std::queue<int> que({ s });\n        while (que.size()) {\n    \
    \        int v = que.front();\n            que.pop();\n            for (auto x\
    \ : G[v]) {\n                auto [_, t] = edges[x];\n                if (dist[t]\
    \ > dist[v] + 1) {\n                    dist[t] = dist[v] + 1;\n             \
    \       prevs[t] = v;\n                    route[t] = x;\n                   \
    \ que.emplace(t);\n                }\n            }\n        }\n    }\n\n    int\
    \ inf() {\n        return _inf;\n    }\n\n    int get_dist(int v) {\n        return\
    \ dist[v];\n    }\n\n    int get_prev(int v) {\n        return prevs[v];\n   \
    \ }\n\n    int get_route(int v) {\n        return route[v];\n    }\n\nprivate:\n\
    \    static constexpr int _inf = std::numeric_limits<int>::max();\n    std::vector<std::pair<int,\
    \ int>> edges;\n    std::vector<std::vector<int>> G;\n    std::vector<int> dist;\n\
    \    std::vector<int> prevs;\n    std::vector<int> route;\n};\n\n}// namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/BFS.hpp
  requiredBy: []
  timestamp: '2022-11-13 19:29:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BFS.test.cpp
documentation_of: src/graph/BFS.hpp
layout: document
title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
---

## 概要

```
zawa::BFS(std::size_t n)
```

重み無しグラフにおいて幅優先探索を行い、単一始点最短経路を求めます。

## 機能

- `コンストラクタ`: 頂点数を引数に取ります。負でない整数を入れてください

$0\ \le\ N\ \le\ 2^{31} - 1$

- `int add_edge(int from, int to)`: `from`から`to`への有向辺を追加します。追加された辺の番号を返します(0-indexed)。

$0\ \le\ \text{from},\ \text{to}\ \le\ N - 1$

- `std::pair<int, int> get_edge(int id)`: `id`番目に追加された辺の情報を返します(境界値チェックが無いことに注意)。`{ from, to }`です。
- `void build(int s)`: 頂点`s`からの単一始点最短経路を求めます。
- `int inf()`: コストの初期値を返します。（すなわち、頂点`s`から到達できな頂点の距離に`inf()`が記録されています。
- `int get_dist(int v)`:  頂点`s`から頂点`v`への最短距離を返します。
- `int get_prev(int v)`: 頂点`s`を根としたグラフの最短経路木を生成した時、頂点`v`の親を返します。
- `int get_route(int v)`: 頂点`s`を根としたグラフの最短経路木を生成した時、頂点`v`の親と`v`自身をつないでいる辺の番号を返します。


## 計算量
`build`は $O(N + M)$ ( $M$ は辺数)
