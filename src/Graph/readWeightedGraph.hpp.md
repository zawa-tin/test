---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/readWeightedGraph.test.cpp
    title: test/readWeightedGraph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/readWeightedGraph.hpp\"\n\n#include <utility>\n\
    #include <vector>\n#include <iostream>\n\nnamespace zawa {\n\ntemplate <typename\
    \ T>\nstd::vector<std::vector<std::pair<int, T>>> readWeightedGraph(int n, int\
    \ m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<std::pair<int,\
    \ T>>> res(n, std::vector(0, std::pair<int, T>()));\n    for (int _ = 0 ; _ <\
    \ m ; _++) {\n        int u, v; std::cin >> u >> v;\n        T c; std::cin >>\
    \ c;\n        res[u - minus].emplace_back(v - minus, c);\n        if (undirect)\
    \ {\n            res[v - minus].emplace_back(u - minus, c);\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> readWeightedTree(int n, bool undirect = true) {\n    return readWeightedGraph<T>(n,\
    \ n - 1, undirect);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\n#include <iostream>\n\
    \nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> readWeightedGraph(int n, int m, bool undirect = true, bool minus = true)\
    \ {\n    std::vector<std::vector<std::pair<int, T>>> res(n, std::vector(0, std::pair<int,\
    \ T>()));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v; std::cin >>\
    \ u >> v;\n        T c; std::cin >> c;\n        res[u - minus].emplace_back(v\
    \ - minus, c);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus, c);\n        }\n    }\n    return res;\n}\n\ntemplate <typename T>\n\
    std::vector<std::vector<std::pair<int, T>>> readWeightedTree(int n, bool undirect\
    \ = true) {\n    return readWeightedGraph<T>(n, n - 1, undirect);\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/readWeightedGraph.hpp
  requiredBy: []
  timestamp: '2022-10-26 14:59:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/readWeightedGraph.test.cpp
documentation_of: src/Graph/readWeightedGraph.hpp
layout: document
redirect_from:
- /library/src/Graph/readWeightedGraph.hpp
- /library/src/Graph/readWeightedGraph.hpp.html
title: src/Graph/readWeightedGraph.hpp
---
