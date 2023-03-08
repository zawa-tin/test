---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC282-D.test.cpp
    title: test/ABC282-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC284-C.test.cpp
    title: test/ABC284-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Read-Graph-AtCoder.test.cpp
    title: test/Read-Graph-AtCoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Read-Graph.test.cpp
    title: test/Read-Graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-bfs2.test.cpp
    title: test/simple-bfs2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/Read-Graph.hpp\"\n\n#include <vector>\n#include\
    \ <iostream>\n\nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int\
    \ n, int m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<int>>\
    \ res(n, std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        res[u - minus].emplace_back(v -\
    \ minus);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus);\n        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>>\
    \ read_tree(int n, bool undirect = true, bool minus = true) {\n    return read_graph(n,\
    \ n - 1, undirect, minus);\n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <iostream>\n\nnamespace zawa\
    \ {\n\nstd::vector<std::vector<int>> read_graph(int n, int m, bool undirect =\
    \ true, bool minus = true) {\n    std::vector<std::vector<int>> res(n, std::vector(0,\
    \ 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n        if (undirect)\
    \ {\n            res[v - minus].emplace_back(u - minus);\n        }\n    }\n \
    \   return res;\n}\n\nstd::vector<std::vector<int>> read_tree(int n, bool undirect\
    \ = true, bool minus = true) {\n    return read_graph(n, n - 1, undirect, minus);\n\
    }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/Read-Graph.hpp
  requiredBy: []
  timestamp: '2022-10-26 15:07:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-bfs2.test.cpp
  - test/Read-Graph-AtCoder.test.cpp
  - test/ABC282-D.test.cpp
  - test/Read-Graph.test.cpp
  - test/ABC284-C.test.cpp
documentation_of: src/graph/Read-Graph.hpp
layout: document
title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
---

## 概要
```
std::vector<std::vector<int>> read_graph(int n, int m, bool undirect = true, bool minus = true)
```
グラフを隣接リスト表現で受け取ります

## 機能
- `n`: 頂点数
- `m`: 辺数
- `undirect`: 無向グラフか否か（デフォルトでtrue)
- `minus`: 1-indexedか否か(デフォルトでtrue)
- `返り値`: `std::vector<std::vector<int>>`

- `read_tree`:  $m = n - 1$ の`read_graph`を呼び出します。(つまり木)
