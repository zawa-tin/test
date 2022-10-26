---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/readGraph-atcoder.test.cpp
    title: test/readGraph-atcoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/readGraph.test.cpp
    title: test/readGraph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/Graph/readGraph.hpp\"\n\n#include <vector>\n#include\
    \ <iostream>\n\nnamespace zawa {\n\nstd::vector<std::vector<int>> readGraph(int\
    \ n, int m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<int>>\
    \ res(n, std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        res[u - minus].emplace_back(v -\
    \ minus);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus);\n        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>>\
    \ readTree(int n, bool undirect = true, bool minus = true) {\n    return readGraph(n,\
    \ n - 1, undirect, minus);\n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <iostream>\n\nnamespace zawa\
    \ {\n\nstd::vector<std::vector<int>> readGraph(int n, int m, bool undirect = true,\
    \ bool minus = true) {\n    std::vector<std::vector<int>> res(n, std::vector(0,\
    \ 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n        if (undirect)\
    \ {\n            res[v - minus].emplace_back(u - minus);\n        }\n    }\n \
    \   return res;\n}\n\nstd::vector<std::vector<int>> readTree(int n, bool undirect\
    \ = true, bool minus = true) {\n    return readGraph(n, n - 1, undirect, minus);\n\
    }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/readGraph.hpp
  requiredBy: []
  timestamp: '2022-10-26 14:59:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/readGraph-atcoder.test.cpp
  - test/readGraph.test.cpp
documentation_of: src/Graph/readGraph.hpp
layout: document
redirect_from:
- /library/src/Graph/readGraph.hpp
- /library/src/Graph/readGraph.hpp.html
title: src/Graph/readGraph.hpp
---
