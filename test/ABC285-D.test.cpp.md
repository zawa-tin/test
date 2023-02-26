---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/compression.hpp
    title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/topological_sort.hpp
    title: "topological_sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc285/submissions/39274306
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC285-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/simple/topological_sort.hpp\"\n\n#include <vector>\n#include\
    \ <stack>\n\nnamespace zawa {\n\nclass topological_sort {\nprivate:\n\tstd::vector<std::vector<int>>\
    \ G;\n\tstd::vector<int> Ord;\n\tbool is_dag;\n\n\tbool build() {\n\t\tstd::vector<int>\
    \ In(G.size(), 0);\n\t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\t\
    for (const auto& v : G[i]) {\n\t\t\t\tIn[v]++;\n\t\t\t}\n\t\t}\n\t\tstd::stack<int>\
    \ S;\n\t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tif (!In[i]) {\n\
    \t\t\t\tS.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (S.size()) {\n\t\t\tint v = S.top();\n\
    \t\t\tS.pop();\n\t\t\tOrd.push_back(v);\n\t\t\tfor (auto x : G[v]) {\n\t\t\t\t\
    In[x]--;\n\t\t\t\tif (!In[x]) {\n\t\t\t\t\tS.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t\treturn Ord.size() == G.size();\n\t}\n\npublic:\n\ttopological_sort(const\
    \ std::vector<std::vector<int>>& _G) : G(_G), is_dag(build()) {}\t\n\n\ttemplate\
    \ <class cost_type>\n\ttopological_sort(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& _G) :  G(_G.size()) {\n\t\tfor (std::size_t i = 0 ; i < _G.size()\
    \ ; i++) {\n\t\t\tfor (auto [v, _] : _G[i]) {\n\t\t\t\tG[i].push_back(v);\n\t\t\
    \t}\n\t\t}\t\n\t\tis_dag = build();\n\t}\n\n\tinline bool ok() const {\n\t\treturn\
    \ is_dag;\n\t}\n\n\tint operator[](int i) {\n\t\treturn Ord[i];\n\t}\n\n\tinline\
    \ std::vector<int> get() const {\n\t\treturn Ord;\n\t}\n\n\tbool unique() const\
    \ {\n\t\tif (!is_dag) {\n\t\t\treturn false;\n\t\t}\n\t\tbool res = true;\n\t\t\
    for (std::size_t i = 0 ; i + 1 < G.size() ; i++) {\n\t\t\tbool ok = false;\n\t\
    \t\tfor (const auto& v : G[Ord[i]]) {\n\t\t\t\tok |= v == Ord[i + 1];\n\t\t\t\
    }\n\t\t\tres &= ok;\n\t\t}\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n\
    #line 2 \"src/algorithm/compression.hpp\"\n\n#line 4 \"src/algorithm/compression.hpp\"\
    \n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass compression\
    \ {\nprivate:\n\tstd::vector<T> as;\n\tstd::vector<T> uniqued;\n\npublic:\n\t\
    compression(const std::vector<T>& as) : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(),\
    \ uniqued.end());\n\t\tuniqued.erase(std::unique(uniqued.begin(), uniqued.end()),\
    \ uniqued.end());\n\t}\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n#line 5 \"test/ABC285-D.test.cpp\"\n\n#include\
    \ <iostream>\n#line 8 \"test/ABC285-D.test.cpp\"\n#include <utility>\n#include\
    \ <string>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector<std::string>\
    \ buc;\n\t// std::vector<std::pair<std::string, std::string>> ps(n);\n\t// for\
    \ (auto& [s, t] : ps) {\n\t// \tstd::cin >> s >> t;\n\t// \tbuc.push_back(s);\n\
    \t// \tbuc.push_back(t);\n\t// }\n\t// zawa::compression comp(buc);\n\t// std::vector<std::vector<int>>\
    \ G(comp.size());\n\t// for (const auto& [s, t] : ps) {\n\t// \tG[comp[s]].emplace_back(comp[t]);\n\
    \t// }\n\t// std::cout << (zawa::topological_sort(G).ok() ? \"Yes\" : \"No\")\
    \ << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 285 - D Change Usernames\n * https://atcoder.jp/contests/abc285/submissions/39274306\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/simple/topological_sort.hpp\"\n#include \"../src/algorithm/compression.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <utility>\n#include <string>\n\
    \nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector<std::string> buc;\n\
    \t// std::vector<std::pair<std::string, std::string>> ps(n);\n\t// for (auto&\
    \ [s, t] : ps) {\n\t// \tstd::cin >> s >> t;\n\t// \tbuc.push_back(s);\n\t// \t\
    buc.push_back(t);\n\t// }\n\t// zawa::compression comp(buc);\n\t// std::vector<std::vector<int>>\
    \ G(comp.size());\n\t// for (const auto& [s, t] : ps) {\n\t// \tG[comp[s]].emplace_back(comp[t]);\n\
    \t// }\n\t// std::cout << (zawa::topological_sort(G).ok() ? \"Yes\" : \"No\")\
    \ << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 285 - D Change Usernames\n * https://atcoder.jp/contests/abc285/submissions/39274306\n\
    \ */\n"
  dependsOn:
  - src/graph/simple/topological_sort.hpp
  - src/algorithm/compression.hpp
  isVerificationFile: true
  path: test/ABC285-D.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 01:26:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC285-D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC285-D.test.cpp
- /verify/test/ABC285-D.test.cpp.html
title: test/ABC285-D.test.cpp
---
