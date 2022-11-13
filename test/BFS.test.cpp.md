---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/BFS.hpp
    title: "BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C
  bundledCode: "#line 1 \"test/BFS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n#line 2 \"src/graph/BFS.hpp\"\n\n#include <queue>\n#include <vector>\n#include\
    \ <limits>\n#include <utility>\n\nnamespace zawa {\n\nclass BFS {\npublic:\n\n\
    \    BFS(std::size_t n)\n        : G(n)\n        , dist(n, _inf)\n        , prevs(n,\
    \ -1)\n        , route(n, -1) {}\n\n    int add_edge(int from, int to) {\n   \
    \     int res = (int)edges.size();\n        edges.push_back({ from, to });\n \
    \       G[from].emplace_back(res);\n        return res;\n    }\n\n    std::pair<int,\
    \ int> get_edge(int id) {\n        return edges[id];\n    }\n\n    void build(int\
    \ s) {\n        dist[s] = 0;\n        std::queue<int> que({ s });\n        while\
    \ (que.size()) {\n            int v = que.front();\n            que.pop();\n \
    \           for (auto x : G[v]) {\n                auto [_, t] = edges[x];\n \
    \               if (dist[t] > dist[v] + 1) {\n                    dist[t] = dist[v]\
    \ + 1;\n                    prevs[t] = v;\n                    route[t] = x;\n\
    \                    que.emplace(t);\n                }\n            }\n     \
    \   }\n    }\n\n    int inf() {\n        return _inf;\n    }\n\n    int get_dist(int\
    \ v) {\n        return dist[v];\n    }\n\n    int get_prev(int v) {\n        return\
    \ prevs[v];\n    }\n\n    int get_route(int v) {\n        return route[v];\n \
    \   }\n\nprivate:\n    static constexpr int _inf = std::numeric_limits<int>::max();\n\
    \    std::vector<std::pair<int, int>> edges;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> dist;\n    std::vector<int> prevs;\n    std::vector<int>\
    \ route;\n};\n\n}// namespace zawa\n#line 4 \"test/BFS.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    int n; std::cin >> n;\n    zawa::BFS bfs(n);\n\
    \    for (int _ = 0 ; _ < n ; _++) {\n        int u; std::cin >> u;\n        int\
    \ k; std::cin >> k;\n        for (int __ = 0 ; __ < k ; __++) {\n            int\
    \ v; std::cin >> v;\n            bfs.add_edge(u - 1, v - 1);\n        }\n    }\n\
    \    bfs.build(0);\n    for (int i = 0 ; i < n ; i++) {\n        int ans = bfs.get_dist(i);\n\
    \        std::cout << i + 1 << ' ' << (ans == bfs.inf() ? -1 : ans) << std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n#include \"../src/graph/BFS.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    int n; std::cin >> n;\n    zawa::BFS bfs(n);\n    for (int _ = 0 ; _ < n\
    \ ; _++) {\n        int u; std::cin >> u;\n        int k; std::cin >> k;\n   \
    \     for (int __ = 0 ; __ < k ; __++) {\n            int v; std::cin >> v;\n\
    \            bfs.add_edge(u - 1, v - 1);\n        }\n    }\n    bfs.build(0);\n\
    \    for (int i = 0 ; i < n ; i++) {\n        int ans = bfs.get_dist(i);\n   \
    \     std::cout << i + 1 << ' ' << (ans == bfs.inf() ? -1 : ans) << std::endl;\n\
    \    }\n}\n"
  dependsOn:
  - src/graph/BFS.hpp
  isVerificationFile: true
  path: test/BFS.test.cpp
  requiredBy: []
  timestamp: '2022-11-13 19:29:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BFS.test.cpp
layout: document
redirect_from:
- /verify/test/BFS.test.cpp
- /verify/test/BFS.test.cpp.html
title: test/BFS.test.cpp
---
