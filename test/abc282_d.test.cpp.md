---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/DSU.hpp
    title: "DSU (\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u306E\u68EE\uFF09"
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
    - https://atcoder.jp/contests/abc282/submissions/37363564
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/abc282_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/DSU.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n\nnamespace zawa {\n\nclass DSU {\nprivate:\n    std::vector<int>\
    \ parents;\n    std::vector<int> sizes;\n\npublic:\n    DSU(std::size_t n) : parents(n,\
    \ 0), sizes(n, 1) {\n        for (std::size_t i = 0 ; i < n ; i++) {\n       \
    \     parents[i] = i;\n        }\n    }\n\n    int leader(int x) {\n        if\
    \ (x == parents[x]) {\n            return x;\n        }\n        else {\n    \
    \        return parents[x] = leader(parents[x]);\n        }\n    }\n\n    bool\
    \ same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\n    void\
    \ merge(int x, int y) {\n        if (leader(x) == leader(y)) {\n            return;\n\
    \        }\n        if (sizes[leader(x)] < sizes[leader(y)]) {\n            std::swap(x,\
    \ y);\n        }\n        sizes[leader(x)] += sizes[leader(y)]; \n        parents[leader(y)]\
    \ = leader(x);\n    }\n\n    inline int size(int x) {\n        return sizes[leader(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector res(parents.size(),\
    \ std::vector(0, 0));\n        for (int i = 0 ; i < (int)parents.size() ; i++)\
    \ {\n            res[leader(i)].push_back(i);\n        }\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), \n                    [](std::vector<int> x) { return x.empty();\
    \ }), res.end());\n        return res;\n    }\n};\n\n}// namespace zawa\n#line\
    \ 2 \"src/graph/simple/bipartite-judge.hpp\"\n\n#line 4 \"src/graph/simple/bipartite-judge.hpp\"\
    \n\nnamespace zawa::impl {\n    \nbool dfs(const std::vector<std::vector<int>>&\
    \ G, int v,\n        int color, std::vector<int>& colors, std::vector<bool>& used)\
    \ {\n    used[v] = true;\n    colors[v] = color;\n    for (auto x : G[v]) {\n\
    \        if (used[x]) {\n            if (colors[x] == colors[v]) {\n         \
    \       return false;\n            }\n        }\n        else {\n            if\
    \ (!dfs(G, x, 1 - color, colors, used)) {\n                return false;\n   \
    \         }\n        }\n    }\n    return true;\n}\n\n} // namespace zawa::impl\n\
    \nnamespace zawa {\n\nstd::vector<int> bipartite_judge(const std::vector<std::vector<int>>&\
    \ G) {\n    bool ok = true;    \n    std::vector used(G.size(), false);\n    std::vector\
    \ colors(G.size(), -1);\n    for (int i = 0 ; i < (int)G.size() ; i++) {\n   \
    \     if (!used[i]) {\n            ok &= impl::dfs(G, i, 0, colors, used);\n \
    \       }\n    }\n    if (ok) {\n        return colors;\n    }\n    else {\n \
    \       return std::vector<int>(G.size(), -1);\n    }\n}\n\ntemplate <class cost_type>\n\
    std::vector<int> bipartite_judge(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n    std::vector tmp_G(G.size(), std::vector(0, 0));\n  \
    \  for (int i = 0 ; i < (int)G.size() ; i++) {\n        for (auto [x, _] : G[i])\
    \ {\n            tmp_G[i].push_back(x);\n        }\n    }\n    return bipartite_judge(tmp_G);\n\
    }\n\n} // namespace zawa\n#line 5 \"test/abc282_d.test.cpp\"\n\n#include <iostream>\n\
    #line 8 \"test/abc282_d.test.cpp\"\n\nint main() {\n    // int n, m; std::cin\
    \ >> n >> m;\n    // std::vector G(n, std::vector(0, 0));\n    // zawa::DSU uf(n);\n\
    \    // for (int _ = 0 ; _ < m ; _++) {\n    //     int u, v; std::cin >> u >>\
    \ v;\n    //     u--; v--;\n    //     G[u].push_back(v);\n    //     G[v].push_back(u);\n\
    \    //     uf.merge(u, v);\n    // }\n    // auto cs = zawa::bipartite_judge(G);\n\
    \    // if (cs[0] == -1) {\n    //     std::cout << 0 << std::endl;\n    // }\n\
    \    // else {\n    //     long long ans = (long long)n * (n - 1) / 2;\n    //\
    \     auto gs = uf.groups();\n    //     for (auto g : gs) {\n    //         int\
    \ c0 = 0; \n    //         for (auto x : g) {\n    //             c0 += cs[x]\
    \ == 0;\n    //         }\n    //         ans -= (long long)c0 * (c0 - 1) / 2;\n\
    \    //         ans -= (long long)((int)g.size() - c0) * ((int)g.size() - c0 -\
    \ 1) / 2;\n    //     }\n    //     ans -= m;\n    //     std::cout << ans <<\
    \ std::endl;\n    // }\n    \n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 282 D- Make Bipartite 2\n * https://atcoder.jp/contests/abc282/submissions/37363564\n\
    \ */\n\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/DSU.hpp\"\n#include \"../src/graph/simple/bipartite-judge.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n    // int n, m; std::cin\
    \ >> n >> m;\n    // std::vector G(n, std::vector(0, 0));\n    // zawa::DSU uf(n);\n\
    \    // for (int _ = 0 ; _ < m ; _++) {\n    //     int u, v; std::cin >> u >>\
    \ v;\n    //     u--; v--;\n    //     G[u].push_back(v);\n    //     G[v].push_back(u);\n\
    \    //     uf.merge(u, v);\n    // }\n    // auto cs = zawa::bipartite_judge(G);\n\
    \    // if (cs[0] == -1) {\n    //     std::cout << 0 << std::endl;\n    // }\n\
    \    // else {\n    //     long long ans = (long long)n * (n - 1) / 2;\n    //\
    \     auto gs = uf.groups();\n    //     for (auto g : gs) {\n    //         int\
    \ c0 = 0; \n    //         for (auto x : g) {\n    //             c0 += cs[x]\
    \ == 0;\n    //         }\n    //         ans -= (long long)c0 * (c0 - 1) / 2;\n\
    \    //         ans -= (long long)((int)g.size() - c0) * ((int)g.size() - c0 -\
    \ 1) / 2;\n    //     }\n    //     ans -= m;\n    //     std::cout << ans <<\
    \ std::endl;\n    // }\n    \n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 282 D- Make Bipartite 2\n * https://atcoder.jp/contests/abc282/submissions/37363564\n\
    \ */\n\n\n"
  dependsOn:
  - src/dataStructure/DSU.hpp
  - src/graph/simple/bipartite-judge.hpp
  isVerificationFile: true
  path: test/abc282_d.test.cpp
  requiredBy: []
  timestamp: '2022-12-18 01:01:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/abc282_d.test.cpp
layout: document
redirect_from:
- /verify/test/abc282_d.test.cpp
- /verify/test/abc282_d.test.cpp.html
title: test/abc282_d.test.cpp
---
