---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Read-Graph-AtCoder.test.cpp
    title: test/Read-Graph-AtCoder.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Read-Graph.test.cpp
    title: test/Read-Graph.test.cpp
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
  - test/Read-Graph.test.cpp
  - test/Read-Graph-AtCoder.test.cpp
documentation_of: src/graph/Read-Graph.hpp
layout: document
redirect_from:
- /library/src/graph/Read-Graph.hpp
- /library/src/graph/Read-Graph.hpp.html
title: src/graph/Read-Graph.hpp
---
