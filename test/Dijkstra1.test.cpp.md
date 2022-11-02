---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Dijkstra.hpp
    title: "Dijkstra (\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5)"
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
  bundledCode: "#line 1 \"test/Dijkstra1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"src/graph/Dijkstra.hpp\"\n\n#include <vector>\n#include <queue>\n\
    #include <utility>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class COST>\n\
    class Dijkstra {\npublic:\n    Dijkstra(std::size_t n) \n        : G(n) \n   \
    \     , dist(n, _inf) \n        , prevs(n, -1) \n        , route(n, -1) {}\n\n\
    \    struct edge {\n        int from, to;\n        COST cost;\n    };\n\n    int\
    \ add_edge(int from, int to, COST cost) {\n        int res = (int)edges.size();\n\
    \        edges.push_back({ from, to, cost });\n        G[from].emplace_back(res);\n\
    \        return res;\n    }\n\n    edge get_edge(int id) {\n        return edges[id];\n\
    \    }\n\n    void build(int s) {\n        using pci = std::pair<COST, int>;\n\
    \        dist[s] = 0;\n        std::priority_queue<pci, std::vector<pci>, std::greater<pci>>\
    \ que;\n        que.emplace(0, s);\n        while (que.size()) {\n           \
    \ auto [d, v] = que.top();\n            que.pop();\n            if (dist[v] <\
    \ d) {\n                continue;\n            }\n            for (auto id : G[v])\
    \ {\n                edge e = edges[id];\n                if (dist[e.to] > d +\
    \ e.cost) {\n                    dist[e.to] = d + e.cost;\n                  \
    \  prevs[e.to] = v;\n                    route[e.to] = id;\n                 \
    \   que.emplace(dist[e.to], e.to);\n                }\n            }\n       \
    \ }\n    }\n\n    COST inf() {\n        return _inf;\n    }\n\n    COST get_dist(int\
    \ v) {\n        return dist[v];\n    }\n\n    int get_prev(int v) {\n        return\
    \ prevs[v];\n    }\n\n    int get_route(int v) {\n        return route[v];\n \
    \   }\n\nprivate:\n    static constexpr COST _inf = std::numeric_limits<COST>::max();\n\
    \    std::vector<edge> edges;\n    std::vector<std::vector<int>> G; \n    std::vector<COST>\
    \ dist;\n    std::vector<int> prevs;\n    std::vector<int> route;\n};\n\n} //\
    \ namespace zawa\n#line 4 \"test/Dijkstra1.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int v, e, r;\n    std::cin >> v >> e >> r;\n    zawa::Dijkstra<long\
    \ long> da(v);\n    for (int _ = 0 ; _ < e ; _++) {\n        int s, t; std::cin\
    \ >> s >> t;\n        long long d; std::cin >> d;\n        da.add_edge(s, t, d);\n\
    \    }\n    da.build(r);\n    for (int i = 0 ; i < v ; i++) {\n        auto ans\
    \ = da.get_dist(i);\n        if (ans == da.inf()) {\n            std::cout <<\
    \ \"INF\" << std::endl;\n        }\n        else {\n            std::cout << ans\
    \ << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../src/graph/Dijkstra.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    int v, e, r;\n    std::cin >> v >> e >> r;\n    zawa::Dijkstra<long long>\
    \ da(v);\n    for (int _ = 0 ; _ < e ; _++) {\n        int s, t; std::cin >> s\
    \ >> t;\n        long long d; std::cin >> d;\n        da.add_edge(s, t, d);\n\
    \    }\n    da.build(r);\n    for (int i = 0 ; i < v ; i++) {\n        auto ans\
    \ = da.get_dist(i);\n        if (ans == da.inf()) {\n            std::cout <<\
    \ \"INF\" << std::endl;\n        }\n        else {\n            std::cout << ans\
    \ << std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/graph/Dijkstra.hpp
  isVerificationFile: true
  path: test/Dijkstra1.test.cpp
  requiredBy: []
  timestamp: '2022-11-02 17:08:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Dijkstra1.test.cpp
layout: document
redirect_from:
- /verify/test/Dijkstra1.test.cpp
- /verify/test/Dijkstra1.test.cpp.html
title: test/Dijkstra1.test.cpp
---
