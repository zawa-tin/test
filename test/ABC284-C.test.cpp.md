---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Graph.hpp
    title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc284/tasks/abc284_c
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC284-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/connectedComponents.hpp\"\n\n#include <vector>\n\
    #include <stack>\n\nnamespace zawa {\n\nclass connectedComponents {\nprivate:\n\
    \tstd::vector<int> ids;\n\tstd::vector<std::vector<int>> groups;    \n\n\tvoid\
    \ build(const std::vector<std::vector<int>>& G) {\n\t\tint id = 0;\n\t\tfor (int\
    \ i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i] == -1) {\n\t\t\t\tids[i]\
    \ = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\t\twhile (stk.size()) {\n\
    \t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\t\t\t\t\tfor (auto x : G[v])\
    \ {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\tids[x] = id;\n\t\t\t\t\t\t\
    \tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tid++;\n\t\t\t}\n\
    \t\t}\n\t\tgroups = std::vector(id, std::vector(0, 0));\n\t\tfor (int i = 0 ;\
    \ i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\t\t}\n\t\
    }\n\npublic:\n\n\tconnectedComponents(const std::vector<std::vector<int>>& G)\
    \ : ids(G.size(), -1) {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\t\
    connectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\t\
    inline int operator [](int i) const {\n\t\treturn ids[i];\n\t}\n\n\tinline std::size_t\
    \ size() const {\n\t\treturn groups.size();\n\t}\n\n\tinline std::size_t size(int\
    \ x) const {\n\t\treturn groups[ids[x]].size();\n\t}\n\n\tinline std::vector<std::vector<int>>\
    \ comps() const {\n\t\treturn groups;\n\t}\n\n\tinline std::vector<int> comp(int\
    \ id) const {\n\t\treturn groups[id];\n\t}\n\n\tbool same(int i, int j) const\
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n#line 2 \"\
    src/graph/Read-Graph.hpp\"\n\n#line 4 \"src/graph/Read-Graph.hpp\"\n#include <iostream>\n\
    \nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int n, int m, bool\
    \ undirect = true, bool minus = true) {\n    std::vector<std::vector<int>> res(n,\
    \ std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n\
    \        if (undirect) {\n            res[v - minus].emplace_back(u - minus);\n\
    \        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>> read_tree(int\
    \ n, bool undirect = true, bool minus = true) {\n    return read_graph(n, n -\
    \ 1, undirect, minus);\n}\n\n}\n#line 5 \"test/ABC284-C.test.cpp\"\n\n#line 7\
    \ \"test/ABC284-C.test.cpp\"\n\nint main() {\n\t// int n, m; std::cin >> n >>\
    \ m;\n\t// std::size_t ans = zawa::connectedComponents(zawa::read_graph(n, m)).size();\n\
    \t// std::cout << ans << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 284-C Count Connected Components\n * https://atcoder.jp/contests/abc284/tasks/abc284_c\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/connectedComponents.hpp\"\n#include \"../src/graph/Read-Graph.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\t// int n, m; std::cin >> n >> m;\n\t\
    // std::size_t ans = zawa::connectedComponents(zawa::read_graph(n, m)).size();\n\
    \t// std::cout << ans << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 284-C Count Connected Components\n * https://atcoder.jp/contests/abc284/tasks/abc284_c\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/connectedComponents.hpp
  - src/graph/Read-Graph.hpp
  isVerificationFile: true
  path: test/ABC284-C.test.cpp
  requiredBy: []
  timestamp: '2023-02-15 00:30:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC284-C.test.cpp
layout: document
redirect_from:
- /verify/test/ABC284-C.test.cpp
- /verify/test/ABC284-C.test.cpp.html
title: test/ABC284-C.test.cpp
---
