---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Graph.hpp
    title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D
  bundledCode: "#line 1 \"test/Read-Graph.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#line 2 \"src/graph/Read-Graph.hpp\"\n\n#include <vector>\n#include <iostream>\n\
    \nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int n, int m, bool\
    \ undirect = true, bool minus = true) {\n    std::vector<std::vector<int>> res(n,\
    \ std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n\
    \        if (undirect) {\n            res[v - minus].emplace_back(u - minus);\n\
    \        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>> read_tree(int\
    \ n, bool undirect = true, bool minus = true) {\n    return read_graph(n, n -\
    \ 1, undirect, minus);\n}\n\n}\n#line 4 \"test/Read-Graph.test.cpp\"\n\n#include\
    \ <set>\n\nvoid dfs(const std::vector<std::vector<int>>& G, std::set<int>& st,\
    \ std::vector<bool>& used, int v) {\n    used[v] = true;\n    st.emplace(v);\n\
    \    for (auto x : G[v]) {\n        if (used[x]) {\n            continue;\n  \
    \      }\n        dfs(G, st, used, x);\n    }\n}\n\nint main() {\n    int n, m;\n\
    \    std::cin >> n >> m;\n    auto G = zawa::read_graph(n, m, true, false);\n\
    \    std::vector group(0, std::set<int>());\n    std::vector used(n, false);\n\
    \    for (int i = 0 ; i < n ; i++) {\n        if (used[i]) {\n            continue;\n\
    \        }\n        std::set<int> st;\n        dfs(G, st, used, i);\n        group.emplace_back(st);\n\
    \    }\n    std::vector place(n, 0);\n    for (int i = 0 ; i < (int)group.size()\
    \ ; i++) {\n        for (auto x : group[i]) {\n            place[x] = i; \n  \
    \      }\n    }\n    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++)\
    \ {\n        int u, v; std::cin >> u >> v;\n        std::cout << (place[u] ==\
    \ place[v] ? \"yes\" : \"no\") << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#include \"../src/graph/Read-Graph.hpp\"\n\n#include <set>\n\nvoid dfs(const\
    \ std::vector<std::vector<int>>& G, std::set<int>& st, std::vector<bool>& used,\
    \ int v) {\n    used[v] = true;\n    st.emplace(v);\n    for (auto x : G[v]) {\n\
    \        if (used[x]) {\n            continue;\n        }\n        dfs(G, st,\
    \ used, x);\n    }\n}\n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n\
    \    auto G = zawa::read_graph(n, m, true, false);\n    std::vector group(0, std::set<int>());\n\
    \    std::vector used(n, false);\n    for (int i = 0 ; i < n ; i++) {\n      \
    \  if (used[i]) {\n            continue;\n        }\n        std::set<int> st;\n\
    \        dfs(G, st, used, i);\n        group.emplace_back(st);\n    }\n    std::vector\
    \ place(n, 0);\n    for (int i = 0 ; i < (int)group.size() ; i++) {\n        for\
    \ (auto x : group[i]) {\n            place[x] = i; \n        }\n    }\n    int\
    \ q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        int u, v; std::cin\
    \ >> u >> v;\n        std::cout << (place[u] == place[v] ? \"yes\" : \"no\") <<\
    \ std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/Read-Graph.hpp
  isVerificationFile: true
  path: test/Read-Graph.test.cpp
  requiredBy: []
  timestamp: '2022-10-26 15:07:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Read-Graph.test.cpp
layout: document
redirect_from:
- /verify/test/Read-Graph.test.cpp
- /verify/test/Read-Graph.test.cpp.html
title: test/Read-Graph.test.cpp
---