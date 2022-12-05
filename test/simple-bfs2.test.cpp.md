---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Graph.hpp
    title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc148/submissions/37049186
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/simple-bfs2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/bfs.hpp\"\n\n#include <vector>\n#include <queue>\n\
    \nnamespace zawa {\n\nstd::vector<int> bfs(const std::vector<std::vector<int>>&\
    \ G, int s, int inf = 2e9) {\n    std::vector<int> res(G.size(), inf);\n    res[s]\
    \ = 0;\n    std::queue<int> que({ s });\n    while (que.size()) {\n        int\
    \ v = que.front();\n        que.pop();\n        for (auto x : G[v]) {\n      \
    \      if (res[x] > res[v] + 1) {\n                res[x] = res[v] + 1;\n    \
    \            que.push(x);\n            }\n        }\n    }\n    return res;\n\
    }\n\n} // namespace zawa\n#line 2 \"src/graph/Read-Graph.hpp\"\n\n#line 4 \"src/graph/Read-Graph.hpp\"\
    \n#include <iostream>\n\nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int\
    \ n, int m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<int>>\
    \ res(n, std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        res[u - minus].emplace_back(v -\
    \ minus);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus);\n        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>>\
    \ read_tree(int n, bool undirect = true, bool minus = true) {\n    return read_graph(n,\
    \ n - 1, undirect, minus);\n}\n\n}\n#line 5 \"test/simple-bfs2.test.cpp\"\n\n\
    #line 8 \"test/simple-bfs2.test.cpp\"\n#include <algorithm>\n\nint main() {\n\
    \    // int n, u, v; std::cin >> n >> u >> v;\n    // u--; v--;\n    // auto G\
    \ = zawa::read_tree(n);\n    // auto distT = zawa::bfs(G, u);\n    // auto distA\
    \ = zawa::bfs(G, v);\n    // std::vector oks(0, 0);\n    // for (int i = 0 ; i\
    \ < n ; i++) {\n    //     if (distT[i] < distA[i]) {\n    //         oks.push_back(distA[i]);\n\
    \    //     }\n    // }\n    // std::cout << *std::max_element(oks.begin(), oks.end())\
    \ - 1 << std::endl;\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 148 - F Playing Tag on Tree\n * https://atcoder.jp/contests/abc148/submissions/37049186\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/bfs.hpp\"\n#include \"../src/graph/Read-Graph.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n\nint main()\
    \ {\n    // int n, u, v; std::cin >> n >> u >> v;\n    // u--; v--;\n    // auto\
    \ G = zawa::read_tree(n);\n    // auto distT = zawa::bfs(G, u);\n    // auto distA\
    \ = zawa::bfs(G, v);\n    // std::vector oks(0, 0);\n    // for (int i = 0 ; i\
    \ < n ; i++) {\n    //     if (distT[i] < distA[i]) {\n    //         oks.push_back(distA[i]);\n\
    \    //     }\n    // }\n    // std::cout << *std::max_element(oks.begin(), oks.end())\
    \ - 1 << std::endl;\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 148 - F Playing Tag on Tree\n * https://atcoder.jp/contests/abc148/submissions/37049186\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/bfs.hpp
  - src/graph/Read-Graph.hpp
  isVerificationFile: true
  path: test/simple-bfs2.test.cpp
  requiredBy: []
  timestamp: '2022-12-06 05:52:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-bfs2.test.cpp
layout: document
redirect_from:
- /verify/test/simple-bfs2.test.cpp
- /verify/test/simple-bfs2.test.cpp.html
title: test/simple-bfs2.test.cpp
---
