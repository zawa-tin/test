---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/abc282_d.test.cpp
    title: test/abc282_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-bipartite-judge1.test.cpp
    title: test/simple-bipartite-judge1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/bipartite-judge.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa::impl {\n    \nbool dfs(const std::vector<std::vector<int>>&\
    \ G, int v,\n        int color, std::vector<int>& colors, std::vector<bool>& used)\
    \ {\n    used[v] = true;\n    colors[v] = color;\n    for (auto x : G[v]) {\n\
    \        if (used[x]) {\n            if (colors[x] == colors[v]) {\n         \
    \       return false;\n            }\n        }\n        else {\n            if\
    \ (!dfs(G, x, 1 - color, colors, used)) {\n                return false;\n   \
    \         }\n        }\n    }\n    return true;\n}\n\n} // namespace zawa::impl\n\
    \nnamespace zawa {\n\nstd::vector<int> bipartite_judge(const std::vector<std::vector<int>>&\
    \ G) {\n    bool ok = true;    \n    std::vector used(G.size(), false);\n    std::vector\
    \ colors(G.size(), -1);\n    for (int i = 0 ; i < (int)G.size() ; i++) {\n   \
    \     if (!used[i]) {\n            ok &= impl::dfs(G, i, 0, colors, used);\n \
    \       }\n    }\n    if (ok) {\n        return colors;\n    }\n    else {\n \
    \       return std::vector<int>(G.size(), -1);\n    }\n}\n\ntemplate <class cost_type>\n\
    std::vector<int> bipartite_judge(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n    std::vector tmp_G(G.size(), std::vector(0, 0));\n  \
    \  for (int i = 0 ; i < (int)G.size() ; i++) {\n        for (auto [x, _] : G[i])\
    \ {\n            tmp_G[i].push_back(x);\n        }\n    }\n    return bipartite_judge(tmp_G);\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa::impl {\n    \nbool dfs(const\
    \ std::vector<std::vector<int>>& G, int v,\n        int color, std::vector<int>&\
    \ colors, std::vector<bool>& used) {\n    used[v] = true;\n    colors[v] = color;\n\
    \    for (auto x : G[v]) {\n        if (used[x]) {\n            if (colors[x]\
    \ == colors[v]) {\n                return false;\n            }\n        }\n \
    \       else {\n            if (!dfs(G, x, 1 - color, colors, used)) {\n     \
    \           return false;\n            }\n        }\n    }\n    return true;\n\
    }\n\n} // namespace zawa::impl\n\nnamespace zawa {\n\nstd::vector<int> bipartite_judge(const\
    \ std::vector<std::vector<int>>& G) {\n    bool ok = true;    \n    std::vector\
    \ used(G.size(), false);\n    std::vector colors(G.size(), -1);\n    for (int\
    \ i = 0 ; i < (int)G.size() ; i++) {\n        if (!used[i]) {\n            ok\
    \ &= impl::dfs(G, i, 0, colors, used);\n        }\n    }\n    if (ok) {\n    \
    \    return colors;\n    }\n    else {\n        return std::vector<int>(G.size(),\
    \ -1);\n    }\n}\n\ntemplate <class cost_type>\nstd::vector<int> bipartite_judge(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n    std::vector tmp_G(G.size(),\
    \ std::vector(0, 0));\n    for (int i = 0 ; i < (int)G.size() ; i++) {\n     \
    \   for (auto [x, _] : G[i]) {\n            tmp_G[i].push_back(x);\n        }\n\
    \    }\n    return bipartite_judge(tmp_G);\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/bipartite-judge.hpp
  requiredBy: []
  timestamp: '2022-12-18 01:00:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-bipartite-judge1.test.cpp
  - test/abc282_d.test.cpp
documentation_of: src/graph/simple/bipartite-judge.hpp
layout: document
title: "bipartite graph judge (\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A simple ver\uFF09"
---

## 概要
グラフが二部グラフであるかを判定します。

二部グラフとは、どの辺の両端点も同じ集合に属さない様に、頂点集合を二つの集合に分割する方法が存在するグラフです。


## 機能

- `std::vector<int> zawa::bipartite_judge(std::vector<std::vector<int>>& G)`
	- コスト無しグラフ $G(V, E)$ が二部グラフであるかを判定し、二部グラフなら上の条件を満たすような分割を返す。
	- `G`: グラフの隣接リスト表現を表す二次元vector
		- $(u, v)\in E$ ならば $v\in G_i$ となるようにしてください
		- AtCoder等であれば、`zawa::read_graph`を用いて標準入力から対応する`G`を作ることができます
	- **計算量** $O(\mid V\mid\ +\ \mid E\mid)$

- `std::vector<int> zawa::bipartite_judge(std::vector<std::vector<std::pair<int, cost_type>>>& G)`
	- コスト有りver
	- `cost_type`: グラフのコストの型
	- 上と同じ
