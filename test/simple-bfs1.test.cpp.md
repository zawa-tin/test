---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/bfs.hpp
    title: bfs (simple ver)
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
  bundledCode: "#line 1 \"test/simple-bfs1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n#line 2 \"src/graph/simple/bfs.hpp\"\n\n#include <vector>\n#include <queue>\n\
    \nnamespace zawa {\n\nstd::vector<int> bfs(const std::vector<std::vector<int>>&\
    \ G, int s, int inf = 2e9) {\n    std::vector<int> res(G.size(), inf);\n    res[s]\
    \ = 0;\n    std::queue<int> que({ s });\n    while (que.size()) {\n        int\
    \ v = que.front();\n        que.pop();\n        for (auto x : G[v]) {\n      \
    \      if (res[x] > res[v] + 1) {\n                res[x] = res[v] + 1;\n    \
    \            que.push(x);\n            }\n        }\n    }\n    return res;\n\
    }\n\n} // namespace zawa\n#line 4 \"test/simple-bfs1.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    int n; std::cin >> n;\n    std::vector G(n, std::vector(0,\
    \ 0));\n    for (int _ = 0 ; _ < n ; _++) {\n        int id; std::cin >> id;\n\
    \        int k; std::cin >> k;\n        for (int __ = 0 ; __ < k ; __++) {\n \
    \           int v; std::cin >> v;\n            G[id - 1].push_back(v - 1);\n \
    \       }\n    }\n    const int inf = 1e9;\n    auto table = zawa::bfs(G, 0, inf);\n\
    \    for (int i = 0 ; i < n ; i++) {\n        std::cout << i + 1 << ' ';\n   \
    \     std::cout << (table[i] == inf ? -1 : table[i]) << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C\"\
    \n\n#include \"../src/graph/simple/bfs.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    int n; std::cin >> n;\n    std::vector G(n, std::vector(0, 0));\n   \
    \ for (int _ = 0 ; _ < n ; _++) {\n        int id; std::cin >> id;\n        int\
    \ k; std::cin >> k;\n        for (int __ = 0 ; __ < k ; __++) {\n            int\
    \ v; std::cin >> v;\n            G[id - 1].push_back(v - 1);\n        }\n    }\n\
    \    const int inf = 1e9;\n    auto table = zawa::bfs(G, 0, inf);\n    for (int\
    \ i = 0 ; i < n ; i++) {\n        std::cout << i + 1 << ' ';\n        std::cout\
    \ << (table[i] == inf ? -1 : table[i]) << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/simple/bfs.hpp
  isVerificationFile: true
  path: test/simple-bfs1.test.cpp
  requiredBy: []
  timestamp: '2022-12-06 05:52:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-bfs1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-bfs1.test.cpp
- /verify/test/simple-bfs1.test.cpp.html
title: test/simple-bfs1.test.cpp
---
