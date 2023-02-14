---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/connectedComponents.hpp
    title: "connectedComponents (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
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
  bundledCode: "#line 1 \"test/connectedComponents1.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\n\n#line\
    \ 2 \"src/graph/simple/connectedComponents.hpp\"\n\n#include <vector>\n#include\
    \ <stack>\n\nnamespace zawa {\n\nclass connectedComponents {\nprivate:\n\tstd::vector<int>\
    \ ids;\n\tstd::vector<std::vector<int>> groups;    \n\n\tvoid build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tint id = 0;\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\
    \tif (ids[i] == -1) {\n\t\t\t\tids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\
    \t\n\t\t\t\twhile (stk.size()) {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\
    \t\t\t\t\tfor (auto x : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\
    \tids[x] = id;\n\t\t\t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tid++;\n\t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0,\
    \ 0));\n\t\tfor (int i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\
    \t\t}\n\t}\n\npublic:\n\n\tconnectedComponents(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\
    \tconnectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\t\
    inline int operator [](int i) const {\n\t\treturn ids[i];\n\t}\n\n\tinline std::size_t\
    \ size() const {\n\t\treturn groups.size();\n\t}\n\n\tinline std::size_t size(int\
    \ x) const {\n\t\treturn groups[ids[x]].size();\n\t}\n\n\tinline std::vector<std::vector<int>>\
    \ comps() const {\n\t\treturn groups;\n\t}\n\n\tinline std::vector<int> comp(int\
    \ id) const {\n\t\treturn groups[id];\n\t}\n\n\tbool same(int i, int j) const\
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n#line 4 \"\
    test/connectedComponents1.test.cpp\"\n\n#include <cassert>\n#line 7 \"test/connectedComponents1.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    int n, m; std::cin >> n >> m;\n   \
    \ std::vector G1(n, std::vector(0, 0));\n    std::vector G2(n, std::vector(0,\
    \ std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n        int s, t; std::cin\
    \ >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n     \
    \   G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n    zawa::connectedComponents\
    \ cc1(G1);\n\tzawa::connectedComponents cc2(G2);\n    int q; std::cin >> q;\n\
    \    for (int _ = 0 ; _ < q ; _++) {\n        int s, t; std::cin >> s >> t;\n\
    \        assert(cc1.same(s, t) == cc2.same(s, t));\n        assert(cc1.same(s,\
    \ t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s, t) == (cc2[s] == cc2[t]));\n\
    \        std::cout << (cc1.same(s, t) ? \"yes\" : \"no\") << std::endl;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#include \"../src/graph/simple/connectedComponents.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#include <iostream>\n\nint main() {\n    int n, m; std::cin\
    \ >> n >> m;\n    std::vector G1(n, std::vector(0, 0));\n    std::vector G2(n,\
    \ std::vector(0, std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n   \
    \     int s, t; std::cin >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n\
    \        G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n\
    \    zawa::connectedComponents cc1(G1);\n\tzawa::connectedComponents cc2(G2);\n\
    \    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        int s,\
    \ t; std::cin >> s >> t;\n        assert(cc1.same(s, t) == cc2.same(s, t));\n\
    \        assert(cc1.same(s, t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s,\
    \ t) == (cc2[s] == cc2[t]));\n        std::cout << (cc1.same(s, t) ? \"yes\" :\
    \ \"no\") << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/simple/connectedComponents.hpp
  isVerificationFile: true
  path: test/connectedComponents1.test.cpp
  requiredBy: []
  timestamp: '2023-02-15 00:30:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/connectedComponents1.test.cpp
layout: document
redirect_from:
- /verify/test/connectedComponents1.test.cpp
- /verify/test/connectedComponents1.test.cpp.html
title: test/connectedComponents1.test.cpp
---
