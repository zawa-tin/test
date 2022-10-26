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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/tessoku-book/submissions/35974231
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Read-Graph-AtCoder.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/Read-Graph.hpp\"\n\n#include <vector>\n#include <iostream>\n\
    \nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int n, int m, bool\
    \ undirect = true, bool minus = true) {\n    std::vector<std::vector<int>> res(n,\
    \ std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n\
    \        if (undirect) {\n            res[v - minus].emplace_back(u - minus);\n\
    \        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>> read_tree(int\
    \ n, bool undirect = true, bool minus = true) {\n    return read_graph(n, n -\
    \ 1, undirect, minus);\n}\n\n}\n#line 4 \"test/Read-Graph-AtCoder.test.cpp\"\n\
    \nint main() {\n    // int n, m; std::cin >> n >> m;\n    // auto G = zawa::read_graph(n,\
    \ m);\n    // for (int i = 0 ; i < n ; i++) {\n    //     std::cout << i + 1 <<\
    \ \": {\";\n    //     for (size_t j = 0 ; j < G[i].size() ; j++) {\n    //  \
    \       std::cout << G[i][j] + 1;\n    //         if (j < G[i].size() - 1) {\n\
    \    //             std::cout << \", \";\n    //         }\n    //     }\n   \
    \ //     std::cout << \"}\" << std::endl;\n    // }\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n\n/*\n * \u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\u30DF\
    \u30F3\u30B0\u306E\u9244\u5247 \u6F14\u7FD2\u554F\u984C\u96C6\n * A61 -Adjacent\
    \ Vertices\n * https://atcoder.jp/contests/tessoku-book/submissions/35974231\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/Read-Graph.hpp\"\n\nint main() {\n    // int n, m;\
    \ std::cin >> n >> m;\n    // auto G = zawa::read_graph(n, m);\n    // for (int\
    \ i = 0 ; i < n ; i++) {\n    //     std::cout << i + 1 << \": {\";\n    //  \
    \   for (size_t j = 0 ; j < G[i].size() ; j++) {\n    //         std::cout <<\
    \ G[i][j] + 1;\n    //         if (j < G[i].size() - 1) {\n    //            \
    \ std::cout << \", \";\n    //         }\n    //     }\n    //     std::cout <<\
    \ \"}\" << std::endl;\n    // }\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * \u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u306E\u9244\
    \u5247 \u6F14\u7FD2\u554F\u984C\u96C6\n * A61 -Adjacent Vertices\n * https://atcoder.jp/contests/tessoku-book/submissions/35974231\n\
    \ */\n"
  dependsOn:
  - src/graph/Read-Graph.hpp
  isVerificationFile: true
  path: test/Read-Graph-AtCoder.test.cpp
  requiredBy: []
  timestamp: '2022-10-26 15:07:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Read-Graph-AtCoder.test.cpp
layout: document
redirect_from:
- /verify/test/Read-Graph-AtCoder.test.cpp
- /verify/test/Read-Graph-AtCoder.test.cpp.html
title: test/Read-Graph-AtCoder.test.cpp
---
