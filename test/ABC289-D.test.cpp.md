---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/reachablity.hpp
    title: "reachablity (\u5230\u9054\u53EF\u80FD\u6027)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc289/submissions/38853951
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC289-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/reachablity.hpp\"\n\n#include <vector>\n#include\
    \ <stack>\n#include <utility>\n\nnamespace zawa {\n\nbool reachability(const std::vector<std::vector<int>>&\
    \ G, int from, int to) {\n\tstd::stack<int> stk;\n\tstd::vector visited(G.size(),\
    \ false);\n\tvisited[from] = true;\n\tstk.emplace(from);\n\twhile (stk.size())\
    \ {\n\t\tint v = stk.top();\n\t\tstk.pop();\n\t\tif (v == to) {\n\t\t\treturn\
    \ true;\n\t\t}\n\t\tfor (const auto& x : G[v]) {\n\t\t\tif (!visited[x]) {\n\t\
    \t\t\tvisited[x] = true;\n\t\t\t\tstk.emplace(x);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ false;\n}\n\ntemplate <class cost_type>\nbool reachability(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, int from, int to) {\n\tstd::vector tmp(G.size(), std::vector(0,\
    \ 0));\n\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\tfor (auto [x, _] :\
    \ G[i]) {\n\t\t\ttmp[i].emplace(x);\n\t\t}\n\t}\n\treturn reachability(tmp, from,\
    \ to);\n}\n\n} // namespace zawa\n#line 4 \"test/ABC289-D.test.cpp\"\n\n#include\
    \ <iostream>\n#line 7 \"test/ABC289-D.test.cpp\"\n#include <set>\n\nint main()\
    \ {\n\t// int N; std::cin >> N;\n\t// std::vector A(N, 0);\n\t// for (auto& a\
    \ : A) {\n\t// \tstd::cin >> a;\n\t// }\n\t// int M; std::cin >> M;\n\t// std::set<int>\
    \ B;\n\t// for (int _ = 0 ; _ < M ; _++) {\n\t// \tint b; std::cin >> b;\n\t//\
    \ \tB.insert(b);\n\t// }\n\t// int X; std::cin >> X;\n\t// std::vector G(X + 1,\
    \ std::vector(0, 0));\n\t// for (int i = 0 ; i < X + 1 ; i++) {\n\t// \tif (!B.count(i))\
    \ {\n\t// \t\tfor (const auto& a : A) {\n\t// \t\t\tif (i + a < X + 1) {\n\t//\
    \ \t\t\t\tG[i].push_back(i + a);\n\t// \t\t\t}\n\t// \t\t}\n\t// \t}\n\t// }\n\
    \t// std::cout << (zawa::reachability(G, 0, X) ? \"Yes\" : \"No\") << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 289-D Step Up Robot\n * https://atcoder.jp/contests/abc289/submissions/38853951\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/reachablity.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n#include <set>\n\nint main() {\n\t// int N; std::cin >> N;\n\
    \t// std::vector A(N, 0);\n\t// for (auto& a : A) {\n\t// \tstd::cin >> a;\n\t\
    // }\n\t// int M; std::cin >> M;\n\t// std::set<int> B;\n\t// for (int _ = 0 ;\
    \ _ < M ; _++) {\n\t// \tint b; std::cin >> b;\n\t// \tB.insert(b);\n\t// }\n\t\
    // int X; std::cin >> X;\n\t// std::vector G(X + 1, std::vector(0, 0));\n\t//\
    \ for (int i = 0 ; i < X + 1 ; i++) {\n\t// \tif (!B.count(i)) {\n\t// \t\tfor\
    \ (const auto& a : A) {\n\t// \t\t\tif (i + a < X + 1) {\n\t// \t\t\t\tG[i].push_back(i\
    \ + a);\n\t// \t\t\t}\n\t// \t\t}\n\t// \t}\n\t// }\n\t// std::cout << (zawa::reachability(G,\
    \ 0, X) ? \"Yes\" : \"No\") << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 289-D Step Up Robot\n * https://atcoder.jp/contests/abc289/submissions/38853951\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/reachablity.hpp
  isVerificationFile: true
  path: test/ABC289-D.test.cpp
  requiredBy: []
  timestamp: '2023-02-13 09:19:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC289-D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC289-D.test.cpp
- /verify/test/ABC289-D.test.cpp.html
title: test/ABC289-D.test.cpp
---
