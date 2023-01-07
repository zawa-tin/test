---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Graph.hpp
    title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc284/submissions/37857219
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/simple-cc2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/connected-components.hpp\"\n\n#include <vector>\n\
    #include <stack>\n\nnamespace zawa {\n\nclass connected_components {\nprivate:\n\
    \    std::vector<int> ids;\n    std::vector<std::vector<int>> groups;    \n\n\t\
    void build(const std::vector<std::vector<int>>& G) {\n\t\tint id = 0;\n\t\tfor\
    \ (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i] == -1) {\n\t\t\t\t\
    ids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\t\twhile (stk.size())\
    \ {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\t\t\t\t\tfor (auto x\
    \ : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\tids[x] = id;\n\t\t\
    \t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tid++;\n\
    \t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0, 0));\n\t\tfor (int\
    \ i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\t\
    \t}\n\t}\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n    }\n\n\ttemplate <class cost_type>\n\
    \tconnected_components(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmp_G);\n\t}\n\n\
    \    int &operator [](int i) {\n        return ids[i];\n    }\n\n\tstd::size_t\
    \ size() {\n\t\treturn groups.size();\n\t}\n\n\tstd::size_t size(int x) {\n\t\t\
    return groups[ids[x]].size();\n\t}\n\n    const std::vector<std::vector<int>>\
    \ &comps() {\n        return groups;\n    }\n\n    const std::vector<int> &comp(int\
    \ id) {\n        return groups[id];\n    }\n\n    bool same(int i, int j) {\n\
    \        return ids[i] == ids[j];\n    }\n};\n\ntemplate <class cost_type>\nconnected_components\
    \ weighted_cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n\
    \    std::vector tmp_G(G.size(), std::vector(0, 0));\n    for (std::size_t i =\
    \ 0 ; i < G.size() ; i++) {\n        for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n\
    \        }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace\
    \ zawa\n#line 2 \"src/graph/Read-Graph.hpp\"\n\n#line 4 \"src/graph/Read-Graph.hpp\"\
    \n#include <iostream>\n\nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int\
    \ n, int m, bool undirect = true, bool minus = true) {\n    std::vector<std::vector<int>>\
    \ res(n, std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        res[u - minus].emplace_back(v -\
    \ minus);\n        if (undirect) {\n            res[v - minus].emplace_back(u\
    \ - minus);\n        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>>\
    \ read_tree(int n, bool undirect = true, bool minus = true) {\n    return read_graph(n,\
    \ n - 1, undirect, minus);\n}\n\n}\n#line 5 \"test/simple-cc2.test.cpp\"\n\n#line\
    \ 7 \"test/simple-cc2.test.cpp\"\n\nint main() {\n\t// int n, m; std::cin >> n\
    \ >> m;\n\t// std::size_t ans = zawa::connected_components(zawa::read_graph(n,\
    \ m)).size();\n\t// std::cout << ans << std::endl;\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 284 - C Count Connected\
    \ Components\n * https://atcoder.jp/contests/abc284/submissions/37857219\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/connected-components.hpp\"\n#include \"../src/graph/Read-Graph.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\t// int n, m; std::cin >> n >> m;\n\t\
    // std::size_t ans = zawa::connected_components(zawa::read_graph(n, m)).size();\n\
    \t// std::cout << ans << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 284 - C Count Connected Components\n * https://atcoder.jp/contests/abc284/submissions/37857219\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/connected-components.hpp
  - src/graph/Read-Graph.hpp
  isVerificationFile: true
  path: test/simple-cc2.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 00:36:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-cc2.test.cpp
layout: document
redirect_from:
- /verify/test/simple-cc2.test.cpp
- /verify/test/simple-cc2.test.cpp.html
title: test/simple-cc2.test.cpp
---
