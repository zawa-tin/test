---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/readWeightedGraph.hpp
    title: src/Graph/readWeightedGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"test/readWeightedGraph.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"src/Graph/readWeightedGraph.hpp\"\n\n#include <utility>\n#include\
    \ <vector>\n#include <iostream>\n\nnamespace zawa {\n\ntemplate <typename T>\n\
    std::vector<std::vector<std::pair<int, T>>> readWeightedGraph(int n, int m, bool\
    \ undirect = true, bool minus = true) {\n    std::vector<std::vector<std::pair<int,\
    \ T>>> res(n, std::vector(0, std::pair<int, T>()));\n    for (int _ = 0 ; _ <\
    \ m ; _++) {\n        int u, v; std::cin >> u >> v;\n        T c; std::cin >>\
    \ c;\n        res[u - minus].emplace_back(v - minus, c);\n        if (undirect)\
    \ {\n            res[v - minus].emplace_back(u - minus, c);\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> readWeightedTree(int n, bool undirect = true) {\n    return readWeightedGraph<T>(n,\
    \ n - 1, undirect);\n}\n\n} // namespace zawa\n#line 4 \"test/readWeightedGraph.test.cpp\"\
    \n\n#include <queue>\n\nint main() {\n    int n, m, r; std::cin >> n >> m >> r;\n\
    \    auto G = zawa::readWeightedGraph<int>(n, m, false, false); \n    std::vector\
    \ dists(n, (1LL << 60));\n    dists[r] = 0;\n    std::priority_queue<std::pair<long\
    \ long, int>> que;\n    que.emplace(0LL, r);\n    while (que.size()) {\n     \
    \   auto [d, v] = que.top();\n        d *= -1;\n        que.pop();\n        if\
    \ (d > dists[v]) {\n            continue;\n        }\n        for (auto [x, w]\
    \ : G[v]) {\n            if (d + w < dists[x]) {\n                dists[x] = d\
    \ + w;\n                que.emplace(-dists[x], x);\n            }\n        }\n\
    \    }\n    for (auto d : dists) {\n        if (d == (1LL << 60)) {\n        \
    \    std::cout << \"INF\" << std::endl;\n        }\n        else {\n         \
    \   std::cout << d << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../src/Graph/readWeightedGraph.hpp\"\n\n#include <queue>\n\nint\
    \ main() {\n    int n, m, r; std::cin >> n >> m >> r;\n    auto G = zawa::readWeightedGraph<int>(n,\
    \ m, false, false); \n    std::vector dists(n, (1LL << 60));\n    dists[r] = 0;\n\
    \    std::priority_queue<std::pair<long long, int>> que;\n    que.emplace(0LL,\
    \ r);\n    while (que.size()) {\n        auto [d, v] = que.top();\n        d *=\
    \ -1;\n        que.pop();\n        if (d > dists[v]) {\n            continue;\n\
    \        }\n        for (auto [x, w] : G[v]) {\n            if (d + w < dists[x])\
    \ {\n                dists[x] = d + w;\n                que.emplace(-dists[x],\
    \ x);\n            }\n        }\n    }\n    for (auto d : dists) {\n        if\
    \ (d == (1LL << 60)) {\n            std::cout << \"INF\" << std::endl;\n     \
    \   }\n        else {\n            std::cout << d << std::endl;\n        }\n \
    \   }\n}\n"
  dependsOn:
  - src/Graph/readWeightedGraph.hpp
  isVerificationFile: true
  path: test/readWeightedGraph.test.cpp
  requiredBy: []
  timestamp: '2022-10-26 15:00:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/readWeightedGraph.test.cpp
layout: document
redirect_from:
- /verify/test/readWeightedGraph.test.cpp
- /verify/test/readWeightedGraph.test.cpp.html
title: test/readWeightedGraph.test.cpp
---
