---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/connected-components.hpp
    title: "connected components (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
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
  bundledCode: "#line 1 \"test/simple-cc1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#line 2 \"src/graph/simple/connected-components.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\nclass connected_components {\nprivate:\n    std::vector<int>\
    \ ids;\n    std::vector<std::vector<int>> groups;    \n\n    void dfs(std::size_t\
    \ v, int id, std::vector<bool>& used, const std::vector<std::vector<int>>& G)\
    \ {\n        used[v] = true;\n        ids[v] = id;\n        for (auto x : G[v])\
    \ {\n            if (!used[x]) {\n                dfs(x, id, used, G);\n     \
    \       }\n        }\n    }\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n        std::vector used(G.size(), false);\n     \
    \   int id = -1;\n        for (std::size_t i = 0 ; i < G.size() ; i++) {\n   \
    \         if (!used[i]) {\n                dfs(i, ++id, used, G);\n          \
    \  }\n        }\n        groups = std::vector(id + 1, std::vector(0, 0));\n  \
    \      for (std::size_t i = 0 ; i < G.size() ; i++) {\n            groups[ids[i]].push_back((int)i);\n\
    \        }\n    }\n\n    int &operator [](int i) {\n        return ids[i];\n \
    \   }\n\n    inline std::vector<std::vector<int>> &comps() {\n        return groups;\n\
    \    }\n\n    inline std::vector<int> &comp(int id) {\n        return groups[id];\n\
    \    }\n\n    bool same(int i, int j) {\n        return ids[i] == ids[j];\n  \
    \  }\n};\n\ntemplate <class cost_type>\nconnected_components weighted_cc(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n    std::vector tmp_G(G.size(),\
    \ std::vector(0, 0));\n    for (std::size_t i = 0 ; i < G.size() ; i++) {\n  \
    \      for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n     \
    \   }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace zawa\n\
    #line 4 \"test/simple-cc1.test.cpp\"\n\n#include <cassert>\n#line 7 \"test/simple-cc1.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    int n, m; std::cin >> n >> m;\n   \
    \ std::vector G1(n, std::vector(0, 0));\n    std::vector G2(n, std::vector(0,\
    \ std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n        int s, t; std::cin\
    \ >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n     \
    \   G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n    zawa::connected_components\
    \ cc1(G1);\n    auto cc2 = zawa::weighted_cc(G2);\n    int q; std::cin >> q;\n\
    \    for (int _ = 0 ; _ < q ; _++) {\n        int s, t; std::cin >> s >> t;\n\
    \        assert(cc1.same(s, t) == cc2.same(s, t));\n        assert(cc1.same(s,\
    \ t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s, t) == (cc2[s] == cc2[t]));\n\
    \        std::cout << (cc1.same(s, t) ? \"yes\" : \"no\") << std::endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#include \"../src/graph/simple/connected-components.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#include <iostream>\n\nint main() {\n    int n, m; std::cin\
    \ >> n >> m;\n    std::vector G1(n, std::vector(0, 0));\n    std::vector G2(n,\
    \ std::vector(0, std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n   \
    \     int s, t; std::cin >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n\
    \        G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n\
    \    zawa::connected_components cc1(G1);\n    auto cc2 = zawa::weighted_cc(G2);\n\
    \    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        int s,\
    \ t; std::cin >> s >> t;\n        assert(cc1.same(s, t) == cc2.same(s, t));\n\
    \        assert(cc1.same(s, t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s,\
    \ t) == (cc2[s] == cc2[t]));\n        std::cout << (cc1.same(s, t) ? \"yes\" :\
    \ \"no\") << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/simple/connected-components.hpp
  isVerificationFile: true
  path: test/simple-cc1.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 10:50:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-cc1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-cc1.test.cpp
- /verify/test/simple-cc1.test.cpp.html
title: test/simple-cc1.test.cpp
---
