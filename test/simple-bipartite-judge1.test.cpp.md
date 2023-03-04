---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/bipartiteJudge.hpp
    title: "bipartiteJudge (\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://algo-method.com/submissions/873881
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/simple-bipartite-judge1.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line\
    \ 2 \"src/graph/simple/bipartiteJudge.hpp\"\n\n#include <vector>\n#include <stack>\n\
    #include <utility>\n\nnamespace zawa {\n\nclass bipartiteJudge {\nprivate:\n\t\
    std::vector<bool> colors;\n\tbool isBipartiteGraph;\n\n\tvoid build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tif (G.empty()) {\n\t\t\treturn;\n\t\t}\n\t\tstd::stack<std::pair<int,\
    \ bool>> S;\n\t\tstd::vector<bool> used(G.size(), false);\n\t\tfor (int i = 0\
    \ ; i < (int)G.size() ; i++) {\n\t\t\tif (!used[i]) {\n\t\t\t\tS.emplace(i, true);\n\
    \t\t\t\tused[i] = true;\n\t\t\t\tcolors[i] = true;\n\t\t\t\twhile (S.size()) {\n\
    \t\t\t\t\tauto [v, col] = S.top();\n\t\t\t\t\tS.pop();\n\t\t\t\t\tfor (const auto&\
    \ x : G[v]) {\n\t\t\t\t\t\tif (used[x]) {\n\t\t\t\t\t\t\tisBipartiteGraph &= colors[x]\
    \ != col;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse {\n\t\t\t\t\t\t\tused[x] = true;\n\t\
    \t\t\t\t\t\tcolors[x] = !col;\n\t\t\t\t\t\t\tS.emplace(x, !col);\n\t\t\t\t\t\t\
    }\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\t\n\tbipartiteJudge(const\
    \ std::vector<std::vector<int>>& G) : colors(G.size()), isBipartiteGraph(true)\
    \ {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\tbipartiteJudge(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) : colors(G.size()),\
    \ isBipartiteGraph(true) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tfor (const auto& [x,\
    \ _] : G[i]) {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\
    \t}\n\n\tinline const bool ok() const {\n\t\treturn isBipartiteGraph;\n\t}\n\n\
    \tinline bool operator[](int i) const {\n\t\treturn colors[i];\n\t}\n};\n\n} //\
    \ namespace zawa\n#line 4 \"test/simple-bipartite-judge1.test.cpp\"\n\n#include\
    \ <iostream>\n#include <cassert>\n\nint main() {\n //    int n, m; std::cin >>\
    \ n >> m;\n //    std::vector G1(n, std::vector(0, 0));\n //    std::vector G2(n,\
    \ std::vector(0, std::pair(0, 0)));\n //    for (int _ = 0 ; _ < m ; _++) {\n\
    \ //        int a, b; std::cin >> a >> b;\n //        G1[a].push_back(b);\n //\
    \        G1[b].push_back(a);\n //        G2[a].push_back({ b, 1 });\n //     \
    \   G2[b].push_back({ a, 1 });\n //    }\n\t// zawa::bipartiteJudge c1(G1);\n\t\
    // zawa::bipartiteJudge c2(G2);\n //    assert(c1.ok() == c2.ok());\n\t// std::cout\
    \ << (c1.ok() ? \"Yes\" : \"No\") << std::endl;\n    \n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n\n/*\n * \u30A2\u30EB\u30B4\u5F0F \u30B0\u30E9\u30D5\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E05\u7AE0Q4. \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\
    \u5B9A(D)\n * https://algo-method.com/submissions/873881\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/bipartiteJudge.hpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nint main() {\n //    int n, m; std::cin >> n >> m;\n //\
    \    std::vector G1(n, std::vector(0, 0));\n //    std::vector G2(n, std::vector(0,\
    \ std::pair(0, 0)));\n //    for (int _ = 0 ; _ < m ; _++) {\n //        int a,\
    \ b; std::cin >> a >> b;\n //        G1[a].push_back(b);\n //        G1[b].push_back(a);\n\
    \ //        G2[a].push_back({ b, 1 });\n //        G2[b].push_back({ a, 1 });\n\
    \ //    }\n\t// zawa::bipartiteJudge c1(G1);\n\t// zawa::bipartiteJudge c2(G2);\n\
    \ //    assert(c1.ok() == c2.ok());\n\t// std::cout << (c1.ok() ? \"Yes\" : \"\
    No\") << std::endl;\n    \n    std::cout << \"Hello World\" << std::endl;\n}\n\
    \n/*\n * \u30A2\u30EB\u30B4\u5F0F \u30B0\u30E9\u30D5\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E05\u7AE0Q4. \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A(D)\n * https://algo-method.com/submissions/873881\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/bipartiteJudge.hpp
  isVerificationFile: true
  path: test/simple-bipartite-judge1.test.cpp
  requiredBy: []
  timestamp: '2023-03-04 20:28:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-bipartite-judge1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-bipartite-judge1.test.cpp
- /verify/test/simple-bipartite-judge1.test.cpp.html
title: test/simple-bipartite-judge1.test.cpp
---
