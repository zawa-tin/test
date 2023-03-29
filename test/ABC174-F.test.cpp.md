---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/mo.hpp
    title: mo (Mo's Algorithm)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc174/tasks/abc174_f
    links:
    - https://atcoder.jp/contests/abc174/tasks/abc174_f
  bundledCode: "#line 1 \"test/ABC174-F.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc174/tasks/abc174_f\"\
    \n\n#line 2 \"src/algorithm/mo.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n#include <algorithm>\n#include <cmath>\n\nnamespace zawa {\n\
    \nstd::vector<std::tuple<int, int, int>> mo(int N, const std::vector<std::pair<int,\
    \ int>>& Q) {\n\tint sq = std::sqrt(Q.size() + 1);\n\tstd::vector tmp((N + sq\
    \ - 1) / sq, std::vector(0, std::tuple(0, 0, 0)));\n\tfor (int i = 0 ; i < (int)Q.size()\
    \ ; i++)\n\t\ttmp[Q[i].first / sq].emplace_back(Q[i].second, Q[i].first, i);\n\
    \tstd::vector res(0, std::tuple(0, 0, 0));\n\tfor (int i = 0 ; i < (int)tmp.size()\
    \ ; i++) {\n\t\tstd::sort(tmp[i].begin(), tmp[i].end());\n\t\tif (i & 1) std::reverse(tmp[i].begin(),\
    \ tmp[i].end());\n\t\tfor (const auto& [r, l, index] : tmp[i]) res.emplace_back(l,\
    \ r, index);\n\t}\n\treturn res;\n}\n\n}// namespace zawa\n#line 4 \"test/ABC174-F.test.cpp\"\
    \n\n#include <cstdio>\n#line 9 \"test/ABC174-F.test.cpp\"\n\nint main() {\n\t\
    int N, Q;\n\tstd::scanf(\"%d%d\", &N, &Q);\n\tstd::vector<int> C(N);\n\tfor (int\
    \ i = 0 ; i < N ; i++)\n\t\tstd::scanf(\"%d\", &C[i]);\n\tstd::vector<std::pair<int,\
    \ int>> Query(Q);\n\tfor (auto& [l, r] : Query) {\n\t\tstd::scanf(\"%d%d\", &l,\
    \ &r);\n\t\tl--;\n\t}\n\tint ans = 0;\n\tstd::vector<int> Ans(Q);\n\tstd::vector<int>\
    \ State(*std::max_element(C.begin(), C.end()) + 1);\n\tint nowl = 0, nowr = 0;\n\
    \tfor (auto [l, r, index] : zawa::mo(N, Query)) {\n\t\twhile (nowr < r) {\n\t\t\
    \tif (State[C[nowr]] == 0) ans++;\n\t\t\tState[C[nowr]]++;\n\t\t\tnowr++;\n\t\t\
    }\t\n\t\twhile (nowl > l) {\n\t\t\tnowl--;\n\t\t\tif (State[C[nowl]] == 0) ans++;\n\
    \t\t\tState[C[nowl]]++;\n\t\t}\n\t\twhile (nowr > r) {\n\t\t\tnowr--;\n\t\t\t\
    State[C[nowr]]--;\n\t\t\tif (State[C[nowr]] == 0) ans--;\n\t\t}\n\t\twhile (nowl\
    \ < l) {\n\t\t\tState[C[nowl]]--;\n\t\t\tif (State[C[nowl]] == 0) ans--;\n\t\t\
    \tnowl++;\n\t\t}\n\t\tAns[index] = ans;\n\t}\n\tfor (int i = 0 ; i < Q ; i++)\n\
    \t\tstd::printf(\"%d\\n\", Ans[i]);\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc174/tasks/abc174_f\"\n\n\
    #include \"../src/algorithm/mo.hpp\"\n\n#include <cstdio>\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n\nint main() {\n\tint N, Q;\n\tstd::scanf(\"\
    %d%d\", &N, &Q);\n\tstd::vector<int> C(N);\n\tfor (int i = 0 ; i < N ; i++)\n\t\
    \tstd::scanf(\"%d\", &C[i]);\n\tstd::vector<std::pair<int, int>> Query(Q);\n\t\
    for (auto& [l, r] : Query) {\n\t\tstd::scanf(\"%d%d\", &l, &r);\n\t\tl--;\n\t\
    }\n\tint ans = 0;\n\tstd::vector<int> Ans(Q);\n\tstd::vector<int> State(*std::max_element(C.begin(),\
    \ C.end()) + 1);\n\tint nowl = 0, nowr = 0;\n\tfor (auto [l, r, index] : zawa::mo(N,\
    \ Query)) {\n\t\twhile (nowr < r) {\n\t\t\tif (State[C[nowr]] == 0) ans++;\n\t\
    \t\tState[C[nowr]]++;\n\t\t\tnowr++;\n\t\t}\t\n\t\twhile (nowl > l) {\n\t\t\t\
    nowl--;\n\t\t\tif (State[C[nowl]] == 0) ans++;\n\t\t\tState[C[nowl]]++;\n\t\t\
    }\n\t\twhile (nowr > r) {\n\t\t\tnowr--;\n\t\t\tState[C[nowr]]--;\n\t\t\tif (State[C[nowr]]\
    \ == 0) ans--;\n\t\t}\n\t\twhile (nowl < l) {\n\t\t\tState[C[nowl]]--;\n\t\t\t\
    if (State[C[nowl]] == 0) ans--;\n\t\t\tnowl++;\n\t\t}\n\t\tAns[index] = ans;\n\
    \t}\n\tfor (int i = 0 ; i < Q ; i++)\n\t\tstd::printf(\"%d\\n\", Ans[i]);\n}\n"
  dependsOn:
  - src/algorithm/mo.hpp
  isVerificationFile: true
  path: test/ABC174-F.test.cpp
  requiredBy: []
  timestamp: '2023-03-30 00:09:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC174-F.test.cpp
layout: document
redirect_from:
- /verify/test/ABC174-F.test.cpp
- /verify/test/ABC174-F.test.cpp.html
title: test/ABC174-F.test.cpp
---
