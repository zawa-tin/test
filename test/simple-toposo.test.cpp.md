---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/topo-sort.hpp
    title: "topo-sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 simple\
      \ ver)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    - https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/GRL_4_B/judge/7308361/C++17
  bundledCode: "#line 1 \"test/simple-toposo.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/topo-sort.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n\nnamespace zawa {\n\nclass topo_sort {\nprivate:\n\tstd::vector<int>\
    \ sorted;\n\tbool is_dag;\n\n\tbool build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tstd::vector<int> ins(G.size(), 0);\n\t\tfor (const auto& g : G) {\n\
    \t\t\tfor (auto x : g) {\n\t\t\t\tins[x]++;\n\t\t\t}\n\t\t}\n\t\tstd::queue<int>\
    \ que;\n\t\tfor (int i = 0 ; i < (int)ins.size() ; i++) {\n\t\t\tif (ins[i] ==\
    \ 0) {\n\t\t\t\tque.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (que.size()) {\n\t\t\t\
    int v = que.front();\n\t\t\tque.pop();\n\t\t\tsorted.push_back(v);\n\t\t\tfor\
    \ (auto x : G[v]) {\n\t\t\t\tins[x]--;\n\t\t\t\tif (ins[x] == 0) {\n\t\t\t\t\t\
    que.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn sorted.size() == G.size();\n\
    \t}\n\npublic:\n\ttopo_sort(const std::vector<std::vector<int>>& G) {\n\t\tis_dag\
    \ = build(G);\t\n\t}\n\n\ttemplate <class cost_type>\n\ttopo_sort(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\t\t\
    for (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i]) {\n\
    \t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tis_dag = build(tmp_G);\n\t\
    }\n\n\tint operator [](int i) {\n\t\treturn sorted[i];\n\t}\n\t\n\tstd::vector<int>\
    \ get() {\n\t\treturn sorted;\n\t}\n\n\tbool ok() {\n\t\treturn is_dag;\t\n\t\
    }\n};\n\n}// namespace zawa\n#line 4 \"test/simple-toposo.test.cpp\"\n\n#include\
    \ <iostream>\n#line 7 \"test/simple-toposo.test.cpp\"\n#include <cassert>\n\n\
    int main() {\n\t// int n, m; std::cin >> n >> m;\n\t// std::vector G(n, std::vector(0,\
    \ 0));\n\t// std::vector G2(n, std::vector(0, std::pair(0, 0)));\n\t// for (int\
    \ _ = 0 ; _ < m ; _++) {\n\t// \tint s, t; std::cin >> s >> t;\n\t// \tG[s].push_back(t);\n\
    \t// \tG2[s].push_back({ t, 0 });\n\t// }\n\t// zawa::topo_sort t1(G);\n\t// zawa::topo_sort\
    \ t2(G2);\n\t// assert(t1.ok() and t2.ok());\n\t// for (int i = 0 ; i < n ; i++)\
    \ {\n\t// \tassert(t1[i] == t2[i]);\n\t// \tstd::cout << t1[i] << std::endl;\n\
    \t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/* \n * AOJ GRL_4_B\
    \ \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\n * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/GRL_4_B/judge/7308361/C++17\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/topo-sort.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <cassert>\n\nint main() {\n\t// int n, m; std::cin >> n >>\
    \ m;\n\t// std::vector G(n, std::vector(0, 0));\n\t// std::vector G2(n, std::vector(0,\
    \ std::pair(0, 0)));\n\t// for (int _ = 0 ; _ < m ; _++) {\n\t// \tint s, t; std::cin\
    \ >> s >> t;\n\t// \tG[s].push_back(t);\n\t// \tG2[s].push_back({ t, 0 });\n\t\
    // }\n\t// zawa::topo_sort t1(G);\n\t// zawa::topo_sort t2(G2);\n\t// assert(t1.ok()\
    \ and t2.ok());\n\t// for (int i = 0 ; i < n ; i++) {\n\t// \tassert(t1[i] ==\
    \ t2[i]);\n\t// \tstd::cout << t1[i] << std::endl;\n\t// }\n\tstd::cout << \"\
    Hello World\" << std::endl;\n}\n\n/* \n * AOJ GRL_4_B \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\n * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/GRL_4_B/judge/7308361/C++17\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/topo-sort.hpp
  isVerificationFile: true
  path: test/simple-toposo.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 01:45:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-toposo.test.cpp
layout: document
redirect_from:
- /verify/test/simple-toposo.test.cpp
- /verify/test/simple-toposo.test.cpp.html
title: test/simple-toposo.test.cpp
---
