---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC291-F.test.cpp
    title: test/ABC291-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-bfs1.test.cpp
    title: test/simple-bfs1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-bfs2.test.cpp
    title: test/simple-bfs2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/bfs.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n\nnamespace zawa {\n\nstd::vector<int> bfs(const std::vector<std::vector<int>>&\
    \ G, int s, int inf = 2e9) {\n    std::vector<int> res(G.size(), inf);\n    res[s]\
    \ = 0;\n    std::queue<int> que({ s });\n    while (que.size()) {\n        int\
    \ v = que.front();\n        que.pop();\n        for (auto x : G[v]) {\n      \
    \      if (res[x] > res[v] + 1) {\n                res[x] = res[v] + 1;\n    \
    \            que.push(x);\n            }\n        }\n    }\n    return res;\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n\nnamespace zawa {\n\
    \nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int s, int inf\
    \ = 2e9) {\n    std::vector<int> res(G.size(), inf);\n    res[s] = 0;\n    std::queue<int>\
    \ que({ s });\n    while (que.size()) {\n        int v = que.front();\n      \
    \  que.pop();\n        for (auto x : G[v]) {\n            if (res[x] > res[v]\
    \ + 1) {\n                res[x] = res[v] + 1;\n                que.push(x);\n\
    \            }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/bfs.hpp
  requiredBy: []
  timestamp: '2022-12-06 05:52:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-bfs1.test.cpp
  - test/simple-bfs2.test.cpp
  - test/ABC291-F.test.cpp
documentation_of: src/graph/simple/bfs.hpp
layout: document
title: bfs (simple ver)
---

## 概要
コストなしグラフ $G(V, E)$ の単一始点最短経路問題を解きます。

最短経路木の情報が欲しい場合はsrc/graph/BFS.hppを使ってください

## 機能

`std::vector<int> bfs(const std::vector<std::vector<int>>& G, int s, int inf = 2e9)`
- `G`: グラフの隣接リストを表す二次元`vector`
	- 頂点`i`から頂点`G[i][j]`に有向辺が存在するようにする。
	- AtCoderなら、`zawa::read_graph`で標準入力から対応する`G`を生成できます。

- `s`: 始点

- `inf`: 最短経路テーブルの初期値
	- デフォルトで $2\times 10^9$ ですが、基本自分で指定したほうが良いです。

- `返り値`: `res[i]`には、頂点`s`から頂点`i`へ行くために通る最小辺数が入っています。
	- `s`から`i`へ到達不可能である場合、`inf`が入ります。

- **計算量**: $O(\mid V \mid + \mid E \mid)$
