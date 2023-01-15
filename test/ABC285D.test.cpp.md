---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/compression.hpp
    title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
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
    - https://atcoder.jp/contests/abc285/submissions/38081790
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC285D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    }\n};\n\n}// namespace zawa\n#line 2 \"src/algorithm/compression.hpp\"\n\n#line\
    \ 4 \"src/algorithm/compression.hpp\"\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass compression {\nprivate:\n\tstd::vector<T> as;\n\
    \tstd::vector<T> uniqued;\n\npublic:\n\tcompression(const std::vector<T>& as)\
    \ : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(), uniqued.end());\n\t\t\
    uniqued.erase(std::unique(uniqued.begin(), uniqued.end()), uniqued.end());\n\t\
    }\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n#line 5 \"test/ABC285D.test.cpp\"\n\n#include\
    \ <iostream>\n#line 8 \"test/ABC285D.test.cpp\"\n#include <utility>\n#include\
    \ <string>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector<std::string>\
    \ buc;\n\t// std::vector<std::pair<std::string, std::string>> ps(n);\n\t// for\
    \ (auto& [s, t] : ps) {\n\t// \tstd::cin >> s >> t;\n\t// \tbuc.push_back(s);\n\
    \t// \tbuc.push_back(t);\n\t// }\n\t// zawa::compression comp(buc);\n\t// std::vector<std::vector<int>>\
    \ G(comp.size());\n\t// for (const auto& [s, t] : ps) {\n\t// \tG[comp[s]].emplace_back(comp[t]);\n\
    \t// }\n\t// std::cout << (zawa::topo_sort(G).ok() ? \"Yes\" : \"No\") << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 285 - D Change Usernames\n * https://atcoder.jp/contests/abc285/submissions/38081790\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/topo-sort.hpp\"\n#include \"../src/algorithm/compression.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <string>\n\
    \nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector<std::string> buc;\n\
    \t// std::vector<std::pair<std::string, std::string>> ps(n);\n\t// for (auto&\
    \ [s, t] : ps) {\n\t// \tstd::cin >> s >> t;\n\t// \tbuc.push_back(s);\n\t// \t\
    buc.push_back(t);\n\t// }\n\t// zawa::compression comp(buc);\n\t// std::vector<std::vector<int>>\
    \ G(comp.size());\n\t// for (const auto& [s, t] : ps) {\n\t// \tG[comp[s]].emplace_back(comp[t]);\n\
    \t// }\n\t// std::cout << (zawa::topo_sort(G).ok() ? \"Yes\" : \"No\") << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 285 - D Change Usernames\n * https://atcoder.jp/contests/abc285/submissions/38081790\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/topo-sort.hpp
  - src/algorithm/compression.hpp
  isVerificationFile: true
  path: test/ABC285D.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 00:45:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC285D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC285D.test.cpp
- /verify/test/ABC285D.test.cpp.html
title: test/ABC285D.test.cpp
---
