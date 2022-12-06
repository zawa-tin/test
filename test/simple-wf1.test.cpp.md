---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Weighted-Graph.hpp
    title: "Read Weighted Graph (\u91CD\u307F\u4ED8\u304D\u30B0\u30E9\u30D5\u5165\u529B\
      )"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/wf.hpp
    title: "wf (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9 simple ver)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/simple-wf1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#line 2 \"src/graph/simple/wf.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <limits>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ cost_type>\nstd::vector<std::vector<cost_type>> wf(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, cost_type inf = std::numeric_limits<cost_type>::max() / 3)\
    \ {\n    std::vector res(G.size(), std::vector(G.size(), inf));\n    for (std::size_t\
    \ i = 0 ; i < G.size() ; i++) {\n        res[i][i] = 0;\n    }\n    for (std::size_t\
    \ i = 0 ; i < G.size() ; i++) {\n        for (auto [x, w] : G[i]) {\n        \
    \    res[i][x] = std::min(res[i][x], w);\n        }\n    }\n    for (std::size_t\
    \ k = 0 ; k < G.size() ; k++) {\n        for (std::size_t i = 0 ; i < G.size()\
    \ ; i++) {\n            for (std::size_t j = 0 ; j < G.size() ; j++) {\n     \
    \           res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);\n        \
    \    }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n#line 2 \"\
    src/graph/Read-Weighted-Graph.hpp\"\n\n#line 5 \"src/graph/Read-Weighted-Graph.hpp\"\
    \n#include <iostream>\n\nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::vector<std::pair<int,\
    \ T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true)\
    \ {\n    std::vector<std::vector<std::pair<int, T>>> res(n, std::vector(0, std::pair<int,\
    \ T>()));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v; std::cin >>\
    \ u >> v;\n        T c; std::cin >> c;\n        res[u - minus].emplace_back(v\
    \ - minus, c);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus, c);\n        }\n    }\n    return res;\n}\n\ntemplate <typename T>\n\
    std::vector<std::vector<std::pair<int, T>>> read_weighted_tree(int n, bool undirect\
    \ = true) {\n    return read_weighted_graph<T>(n, n - 1, undirect);\n}\n\n} //\
    \ namespace zawa\n#line 5 \"test/simple-wf1.test.cpp\"\n\n#line 7 \"test/simple-wf1.test.cpp\"\
    \n\nint main() {\n    int n, m; std::cin >> n >> m;\n    const long long inf =\
    \ 1e15;\n    auto G = zawa::wf<long long>(zawa::read_weighted_graph<long long>(n,\
    \ m, false, false), inf);\n    bool neg = false;\n    for (int i = 0 ; i < n ;\
    \ i++) {\n        neg |= G[i][i] < 0;\n    }\n    if (neg) {\n        std::cout\
    \ << \"NEGATIVE CYCLE\" << std::endl;\n    }\n    else {\n        for (int i =\
    \ 0 ; i < n ; i++) {\n            for (int j = 0 ; j < n ; j++) {\n          \
    \      if (G[i][j] > 1e12) {\n                    std::cout << \"INF\";\n    \
    \            }\n                else {\n                    std::cout << G[i][j];\n\
    \                }\n                std::cout << (j == n - 1 ? '\\n' : ' ');\n\
    \            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../src/graph/simple/wf.hpp\"\n#include \"../src/graph/Read-Weighted-Graph.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    int n, m; std::cin >> n >> m;\n \
    \   const long long inf = 1e15;\n    auto G = zawa::wf<long long>(zawa::read_weighted_graph<long\
    \ long>(n, m, false, false), inf);\n    bool neg = false;\n    for (int i = 0\
    \ ; i < n ; i++) {\n        neg |= G[i][i] < 0;\n    }\n    if (neg) {\n     \
    \   std::cout << \"NEGATIVE CYCLE\" << std::endl;\n    }\n    else {\n       \
    \ for (int i = 0 ; i < n ; i++) {\n            for (int j = 0 ; j < n ; j++) {\n\
    \                if (G[i][j] > 1e12) {\n                    std::cout << \"INF\"\
    ;\n                }\n                else {\n                    std::cout <<\
    \ G[i][j];\n                }\n                std::cout << (j == n - 1 ? '\\\
    n' : ' ');\n            }\n        }\n    }\n}\n"
  dependsOn:
  - src/graph/simple/wf.hpp
  - src/graph/Read-Weighted-Graph.hpp
  isVerificationFile: true
  path: test/simple-wf1.test.cpp
  requiredBy: []
  timestamp: '2022-12-07 03:14:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-wf1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-wf1.test.cpp
- /verify/test/simple-wf1.test.cpp.html
title: test/simple-wf1.test.cpp
---
