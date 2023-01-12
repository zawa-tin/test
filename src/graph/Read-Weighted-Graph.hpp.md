---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Read-Weighted-Graph.test.cpp
    title: test/Read-Weighted-Graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-dijkstra1.test.cpp
    title: test/simple-dijkstra1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-dijkstra2.test.cpp
    title: test/simple-dijkstra2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-wf1.test.cpp
    title: test/simple-wf1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/Read-Weighted-Graph.hpp\"\n\n#include <utility>\n\
    #include <vector>\n#include <iostream>\n\nnamespace zawa {\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<std::pair<int, T>>> read_weighted_graph(int n, int\
    \ m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<std::pair<int,\
    \ T>>> res(n, std::vector(0, std::pair<int, T>()));\n    for (int _ = 0 ; _ <\
    \ m ; _++) {\n        int u, v; std::cin >> u >> v;\n        T c; std::cin >>\
    \ c;\n        res[u - minus].emplace_back(v - minus, c);\n        if (undirect)\
    \ {\n            res[v - minus].emplace_back(u - minus, c);\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> read_weighted_tree(int n, bool undirect = true) {\n    return read_weighted_graph<T>(n,\
    \ n - 1, undirect);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n#include <iostream>\n\
    \nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true)\
    \ {\n    std::vector<std::vector<std::pair<int, T>>> res(n, std::vector(0, std::pair<int,\
    \ T>()));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v; std::cin >>\
    \ u >> v;\n        T c; std::cin >> c;\n        res[u - minus].emplace_back(v\
    \ - minus, c);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus, c);\n        }\n    }\n    return res;\n}\n\ntemplate <typename T>\n\
    std::vector<std::vector<std::pair<int, T>>> read_weighted_tree(int n, bool undirect\
    \ = true) {\n    return read_weighted_graph<T>(n, n - 1, undirect);\n}\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/Read-Weighted-Graph.hpp
  requiredBy: []
  timestamp: '2022-10-26 15:07:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Read-Weighted-Graph.test.cpp
  - test/simple-wf1.test.cpp
  - test/simple-dijkstra1.test.cpp
  - test/simple-dijkstra2.test.cpp
documentation_of: src/graph/Read-Weighted-Graph.hpp
layout: document
title: "Read Weighted Graph (\u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u5165\u529B\
  )"
---

## 概要
```
std::vector<std::vector<std::pair<int, T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true)
```

重み付きグラフの入力に対して隣接リストを作成し、これを返します。


## 機能
- `n`: 頂点数
- `m`: 辺数
- `undirect`: 無向か否か(デフォルトでtrue)
- `minus`: 1-indexedか否か(デフォルトでtrue)
- `返り値`: `std::vector<std::vector<std::pair<int, T>>>`

- `read_weighted_tree`: $m = n - 1$ で`read_weighted_graph`を呼び出します。つまり木
