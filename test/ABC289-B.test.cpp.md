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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc289/submissions/38891547
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC289-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n#line 4 \"\
    test/ABC289-B.test.cpp\"\n\n#include <iostream>\n#line 7 \"test/ABC289-B.test.cpp\"\
    \n\nint main() {\n\t// int N, M; std::cin >> N >> M;\n\t// std::vector G(N, std::vector(0,\
    \ 0));\n\t// for (int _ = 0 ; _ < M ; _++) {\n\t// \tint a; std::cin >> a;\n\t\
    // \tG[a - 1].push_back(a);\n\t// \tG[a].push_back(a - 1);\n\t// }\n\t// zawa::connectedComponents\
    \ cc(G);\n\t// std::vector ans(0, 0);\n\t// auto vec = cc.comps();\n\t// for (const\
    \ auto& arr : cc.comps()) {\n\t// \tfor (int i = (int)arr.size() - 1 ; i >= 0\
    \ ; i--) {\n\t// \t\tans.push_back(arr[i] + 1);\n\t// \t}\n\t// }\n\t// for (int\
    \ i = 0 ; i < N ; i++) {\n\t// \tstd::cout << ans[i] << (i + 1 == N ? '\\n' :\
    \ ' ');\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 289-B \u30EC\n * https://atcoder.jp/contests/abc289/submissions/38891547\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/connectedComponents.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n\t// int N, M; std::cin >> N >> M;\n\t// std::vector\
    \ G(N, std::vector(0, 0));\n\t// for (int _ = 0 ; _ < M ; _++) {\n\t// \tint a;\
    \ std::cin >> a;\n\t// \tG[a - 1].push_back(a);\n\t// \tG[a].push_back(a - 1);\n\
    \t// }\n\t// zawa::connectedComponents cc(G);\n\t// std::vector ans(0, 0);\n\t\
    // auto vec = cc.comps();\n\t// for (const auto& arr : cc.comps()) {\n\t// \t\
    for (int i = (int)arr.size() - 1 ; i >= 0 ; i--) {\n\t// \t\tans.push_back(arr[i]\
    \ + 1);\n\t// \t}\n\t// }\n\t// for (int i = 0 ; i < N ; i++) {\n\t// \tstd::cout\
    \ << ans[i] << (i + 1 == N ? '\\n' : ' ');\n\t// }\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 289-B \u30EC\n * https://atcoder.jp/contests/abc289/submissions/38891547\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/connectedComponents.hpp
  isVerificationFile: true
  path: test/ABC289-B.test.cpp
  requiredBy: []
  timestamp: '2023-02-15 00:30:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC289-B.test.cpp
layout: document
redirect_from:
- /verify/test/ABC289-B.test.cpp
- /verify/test/ABC289-B.test.cpp.html
title: test/ABC289-B.test.cpp
---
