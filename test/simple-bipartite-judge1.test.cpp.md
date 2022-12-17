---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/bipartite-judge.hpp
    title: "bipartite graph judge (\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A simple\
      \ ver\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://algo-method.com/submissions/723796
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/simple-bipartite-judge1.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line\
    \ 2 \"src/graph/simple/bipartite-judge.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa::impl {\n    \nbool dfs(const std::vector<std::vector<int>>& G, int v,\n\
    \        int color, std::vector<int>& colors, std::vector<bool>& used) {\n   \
    \ used[v] = true;\n    colors[v] = color;\n    for (auto x : G[v]) {\n       \
    \ if (used[x]) {\n            if (colors[x] == colors[v]) {\n                return\
    \ false;\n            }\n        }\n        else {\n            if (!dfs(G, x,\
    \ 1 - color, colors, used)) {\n                return false;\n            }\n\
    \        }\n    }\n    return true;\n}\n\n} // namespace zawa::impl\n\nnamespace\
    \ zawa {\n\nstd::vector<int> bipartite_judge(const std::vector<std::vector<int>>&\
    \ G) {\n    bool ok = true;    \n    std::vector used(G.size(), false);\n    std::vector\
    \ colors(G.size(), -1);\n    for (int i = 0 ; i < (int)G.size() ; i++) {\n   \
    \     if (!used[i]) {\n            ok &= impl::dfs(G, i, 0, colors, used);\n \
    \       }\n    }\n    if (ok) {\n        return colors;\n    }\n    else {\n \
    \       return std::vector<int>(G.size(), -1);\n    }\n}\n\ntemplate <class cost_type>\n\
    std::vector<int> bipartite_judge(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n    std::vector tmp_G(G.size(), std::vector(0, 0));\n  \
    \  for (int i = 0 ; i < (int)G.size() ; i++) {\n        for (auto [x, _] : G[i])\
    \ {\n            tmp_G[i].push_back(x);\n        }\n    }\n    return bipartite_judge(tmp_G);\n\
    }\n\n} // namespace zawa\n#line 4 \"test/simple-bipartite-judge1.test.cpp\"\n\n\
    #include <iostream>\n#include <cassert>\n\nint main() {\n    // int n, m; std::cin\
    \ >> n >> m;\n    // std::vector G1(n, std::vector(0, 0));\n    // std::vector\
    \ G2(n, std::vector(0, std::pair(0, 0)));\n    // for (int _ = 0 ; _ < m ; _++)\
    \ {\n    //     int a, b; std::cin >> a >> b;\n    //     G1[a].push_back(b);\n\
    \    //     G1[b].push_back(a);\n    //     G2[a].push_back({ b, 1 });\n    //\
    \     G2[b].push_back({ a, 1 });\n    // }\n    // auto c1 = zawa::bipartite_judge(G1);\n\
    \    // auto c2 = zawa::bipartite_judge(G2);\n    // assert(c1 == c2);\n    //\
    \ if (c1[0] != -1) {\n    //     std::cout << \"Yes\" << std::endl;\n    // }\n\
    \    // else {\n    //     std::cout << \"No\" << std::endl;\n    // }\n    \n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * \u30A2\u30EB\u30B4\
    \u5F0F \u30B0\u30E9\u30D5\u30A2\u30EB\u30B4\u30EA\u30BA\u30E05\u7AE0Q4. \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u5224\u5B9A(D)\n * https://algo-method.com/submissions/723796\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/bipartite-judge.hpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nint main() {\n    // int n, m; std::cin >> n >> m;\n   \
    \ // std::vector G1(n, std::vector(0, 0));\n    // std::vector G2(n, std::vector(0,\
    \ std::pair(0, 0)));\n    // for (int _ = 0 ; _ < m ; _++) {\n    //     int a,\
    \ b; std::cin >> a >> b;\n    //     G1[a].push_back(b);\n    //     G1[b].push_back(a);\n\
    \    //     G2[a].push_back({ b, 1 });\n    //     G2[b].push_back({ a, 1 });\n\
    \    // }\n    // auto c1 = zawa::bipartite_judge(G1);\n    // auto c2 = zawa::bipartite_judge(G2);\n\
    \    // assert(c1 == c2);\n    // if (c1[0] != -1) {\n    //     std::cout <<\
    \ \"Yes\" << std::endl;\n    // }\n    // else {\n    //     std::cout << \"No\"\
    \ << std::endl;\n    // }\n    \n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * \u30A2\u30EB\u30B4\u5F0F \u30B0\u30E9\u30D5\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E05\u7AE0Q4. \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A(D)\n * https://algo-method.com/submissions/723796\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/bipartite-judge.hpp
  isVerificationFile: true
  path: test/simple-bipartite-judge1.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 01:01:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-bipartite-judge1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-bipartite-judge1.test.cpp
- /verify/test/simple-bipartite-judge1.test.cpp.html
title: test/simple-bipartite-judge1.test.cpp
---
