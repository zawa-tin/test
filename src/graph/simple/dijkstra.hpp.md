---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/simple-dijkstra1.test.cpp
    title: test/simple-dijkstra1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-dijkstra2.test.cpp
    title: test/simple-dijkstra2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/dijkstra.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n#include <utility>\n#include <limits>\n\nnamespace zawa {\n\ntemplate\
    \ <class cost_type>\nstd::vector<cost_type> dijkstra(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, \n        int s, cost_type inf = std::numeric_limits<cost_type>::max())\
    \ {\n    std::vector<cost_type> res(G.size(), inf);\n    res[s] = 0;\n    std::priority_queue<\n\
    \        std::pair<cost_type, int>, \n        std::vector<std::pair<cost_type,\
    \ int>>, \n        std::greater<std::pair<cost_type, int>>\n            > que;\n\
    \    que.push({ 0, s }); \n    while (que.size()) {\n        auto [d, v] = que.top();\n\
    \        que.pop();\n        if (d > res[v]) {\n            continue;\n      \
    \  }\n        for (auto [x, w] : G[v]) {\n            if (res[x] > d + w) {\n\
    \                res[x] = d + w;\n                que.push({ d + w, x });\n  \
    \          }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <utility>\n\
    #include <limits>\n\nnamespace zawa {\n\ntemplate <class cost_type>\nstd::vector<cost_type>\
    \ dijkstra(const std::vector<std::vector<std::pair<int, cost_type>>>& G, \n  \
    \      int s, cost_type inf = std::numeric_limits<cost_type>::max()) {\n    std::vector<cost_type>\
    \ res(G.size(), inf);\n    res[s] = 0;\n    std::priority_queue<\n        std::pair<cost_type,\
    \ int>, \n        std::vector<std::pair<cost_type, int>>, \n        std::greater<std::pair<cost_type,\
    \ int>>\n            > que;\n    que.push({ 0, s }); \n    while (que.size())\
    \ {\n        auto [d, v] = que.top();\n        que.pop();\n        if (d > res[v])\
    \ {\n            continue;\n        }\n        for (auto [x, w] : G[v]) {\n  \
    \          if (res[x] > d + w) {\n                res[x] = d + w;\n          \
    \      que.push({ d + w, x });\n            }\n        }\n    }\n    return res;\n\
    }\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-12-06 04:57:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-dijkstra2.test.cpp
  - test/simple-dijkstra1.test.cpp
documentation_of: src/graph/simple/dijkstra.hpp
layout: document
title: dijkstra (simple ver)
---

## 概要
辺の重みが非負数であるグラフ $G(V, E)$ の最短経路問題を解きます。

最短経路木の情報が欲しい場合はsrc/graph/Dijkstra.hppを使ってください。

## 機能

```
std::vector<cost_type> dijkstra(const std::vector<std::vector<std::pair<int, cost_type>>>& G, 
int s, cost_type inf = std::numeric_limits<cost_type>::max())
```
- `テンプレート引数`: 辺の重みの型
	- `int`、`long`、`long long`以外での使用を想定していません

- `G`: グラフの隣接リストを表す二次元`vector`
	- `G[i][j] (std::pair<int, cost_type>)`: 頂点`i`から`G[i][j].first`にコスト`G[i][j].second`の有向辺が存在する。
	- AtCoderだったら`zawa::read_weighted_graph<cost_type>`で標準入力から対応する隣接リストを作れます。（有向・無向に注意）

- `s`: 最短経路を求めたい始点

- `inf`: テーブルの初期値
	- 基本自分で指定してください。`std::numeric_limits<cost_type>::max()`がデフォルトで指定されていますが、そのまま使うのはオーバーフローが怖かったり、非連結の時の処理にだるかったりすると思います。

- `返り値`: `res[i]`には始点`s`から頂点`i`への最短経路の総コストが入っています。`s` から`i`に到達不可能な場合、`inf`が入っています。

- `計算量`: $O((\mid V \mid + \mid E \mid)\log (\mid V \mid))$
