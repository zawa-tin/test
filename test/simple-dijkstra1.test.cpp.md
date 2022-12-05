---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Weighted-Graph.hpp
    title: "Read Weighted Graph (\u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u5165\u529B\
      )"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/dijkstra.hpp
    title: dijkstra (simple ver)
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
  bundledCode: "#line 1 \"test/simple-dijkstra1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"src/graph/simple/dijkstra.hpp\"\n\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class cost_type>\n\
    std::vector<cost_type> dijkstra(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G, \n        int s, cost_type inf = std::numeric_limits<cost_type>::max()) {\n\
    \    std::vector<cost_type> res(G.size(), inf);\n    res[s] = 0;\n    std::priority_queue<\n\
    \        std::pair<cost_type, int>, \n        std::vector<std::pair<cost_type,\
    \ int>>, \n        std::greater<std::pair<cost_type, int>>\n            > que;\n\
    \    que.push({ 0, s }); \n    while (que.size()) {\n        auto [d, v] = que.top();\n\
    \        que.pop();\n        if (d > res[v]) {\n            continue;\n      \
    \  }\n        for (auto [x, w] : G[v]) {\n            if (res[x] > d + w) {\n\
    \                res[x] = d + w;\n                que.push({ d + w, x });\n  \
    \          }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n#line\
    \ 2 \"src/graph/Read-Weighted-Graph.hpp\"\n\n#line 5 \"src/graph/Read-Weighted-Graph.hpp\"\
    \n#include <iostream>\n\nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true)\
    \ {\n    std::vector<std::vector<std::pair<int, T>>> res(n, std::vector(0, std::pair<int,\
    \ T>()));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v; std::cin >>\
    \ u >> v;\n        T c; std::cin >> c;\n        res[u - minus].emplace_back(v\
    \ - minus, c);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus, c);\n        }\n    }\n    return res;\n}\n\ntemplate <typename T>\n\
    std::vector<std::vector<std::pair<int, T>>> read_weighted_tree(int n, bool undirect\
    \ = true) {\n    return read_weighted_graph<T>(n, n - 1, undirect);\n}\n\n} //\
    \ namespace zawa\n#line 5 \"test/simple-dijkstra1.test.cpp\"\n\nint main() {\n\
    \    int v, e, r; std::cin >> v >> e >> r;\n    const long long inf = 1e15;\n\
    \    auto G = zawa::read_weighted_graph<long long>(v, e, false, false);\n    auto\
    \ table = zawa::dijkstra<long long>(G, r, inf);\n    for (auto ans : table) {\n\
    \        if (ans == inf) {\n            std::cout << \"INF\" << std::endl;\n \
    \       }\n        else {\n            std::cout << ans << std::endl;\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../src/graph/simple/dijkstra.hpp\"\n#include \"../src/graph/Read-Weighted-Graph.hpp\"\
    \n\nint main() {\n    int v, e, r; std::cin >> v >> e >> r;\n    const long long\
    \ inf = 1e15;\n    auto G = zawa::read_weighted_graph<long long>(v, e, false,\
    \ false);\n    auto table = zawa::dijkstra<long long>(G, r, inf);\n    for (auto\
    \ ans : table) {\n        if (ans == inf) {\n            std::cout << \"INF\"\
    \ << std::endl;\n        }\n        else {\n            std::cout << ans << std::endl;\n\
    \        }\n    }\n}\n"
  dependsOn:
  - src/graph/simple/dijkstra.hpp
  - src/graph/Read-Weighted-Graph.hpp
  isVerificationFile: true
  path: test/simple-dijkstra1.test.cpp
  requiredBy: []
  timestamp: '2022-12-06 04:57:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-dijkstra1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-dijkstra1.test.cpp
- /verify/test/simple-dijkstra1.test.cpp.html
title: test/simple-dijkstra1.test.cpp
---
