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
    PROBLEM: https://atcoder.jp/contests/abc242/tasks/abc242_g
    links:
    - https://atcoder.jp/contests/abc242/tasks/abc242_g
  bundledCode: "#line 1 \"test/ABC242-G.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc242/tasks/abc242_g\"\
    \n\n#line 2 \"src/algorithm/mo.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n#include <algorithm>\n#include <cmath>\n\nnamespace zawa {\n\
    \nstd::vector<std::tuple<int, int, int>> mo(int N, const std::vector<std::pair<int,\
    \ int>>& Q) {\n\tint sq = std::sqrt(Q.size() + 1);\n\tstd::vector tmp((N + sq\
    \ - 1) / sq, std::vector(0, std::tuple(0, 0, 0)));\n\tfor (int i = 0 ; i < (int)Q.size()\
    \ ; i++)\n\t\ttmp[Q[i].first / sq].emplace_back(Q[i].second, Q[i].first, i);\n\
    \tstd::vector res(0, std::tuple(0, 0, 0));\n\tfor (int i = 0 ; i < (int)tmp.size()\
    \ ; i++) {\n\t\tstd::sort(tmp[i].begin(), tmp[i].end());\n\t\tif (i & 1) std::reverse(tmp[i].begin(),\
    \ tmp[i].end());\n\t\tfor (const auto& [r, l, index] : tmp[i]) res.emplace_back(l,\
    \ r, index);\n\t}\n\treturn res;\n}\n\n}// namespace zawa\n#line 4 \"test/ABC242-G.test.cpp\"\
    \n\n#include <cstdio>\n#line 9 \"test/ABC242-G.test.cpp\"\n\nint main() {\n\t\
    int N;\n\tstd::scanf(\"%d\", &N);\n\tint A[N];\n\tfor (int i = 0 ; i < N ; i++)\n\
    \t\tstd::scanf(\"%d\", A + i);\n\tint Q;\n\tstd::scanf(\"%d\", &Q);\n\tstd::vector<std::pair<int,\
    \ int>> Query(Q);\n\tfor (auto& [l, r] : Query) {\n\t\tstd::scanf(\"%d%d\", &l,\
    \ &r);\n\t\t--l;\n\t}\n\tint mx = *std::max_element(A, A + N) + 1;\n\tint S[mx];\n\
    \tstd::fill(S, S + mx, 0);\n\tint ans = 0;\n\tint Ans[Q];\n\tint L = 0, R = 0;\n\
    \tfor (const auto& [l, r, index] : zawa::mo(N, Query)) {\n\t\twhile (R < r) {\n\
    \t\t\tS[A[R]]++;\n\t\t\tif (!(S[A[R]] & 1)) ans++;\n\t\t\tR++;\n\t\t}\n\t\twhile\
    \ (L > l) {\n\t\t\tL--;\n\t\t\tS[A[L]]++;\n\t\t\tif (!(S[A[L]] & 1)) ans++;\n\t\
    \t}\n\t\twhile (R > r) {\n\t\t\tR--;\n\t\t\tS[A[R]]--;\n\t\t\tif (S[A[R]] & 1)\
    \ ans--;\n\t\t}\n\t\twhile (L < l) {\n\t\t\tS[A[L]]--;\n\t\t\tif (S[A[L]] & 1)\
    \ ans--;\n\t\t\tL++;\n\t\t}\n\t\tAns[index] = ans;\n\t}\n\tfor (int i = 0 ; i\
    \ < Q ; i++)\n\t\tstd::printf(\"%d\\n\", Ans[i]);\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc242/tasks/abc242_g\"\n\n\
    #include \"../src/algorithm/mo.hpp\"\n\n#include <cstdio>\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n\nint main() {\n\tint N;\n\tstd::scanf(\"\
    %d\", &N);\n\tint A[N];\n\tfor (int i = 0 ; i < N ; i++)\n\t\tstd::scanf(\"%d\"\
    , A + i);\n\tint Q;\n\tstd::scanf(\"%d\", &Q);\n\tstd::vector<std::pair<int, int>>\
    \ Query(Q);\n\tfor (auto& [l, r] : Query) {\n\t\tstd::scanf(\"%d%d\", &l, &r);\n\
    \t\t--l;\n\t}\n\tint mx = *std::max_element(A, A + N) + 1;\n\tint S[mx];\n\tstd::fill(S,\
    \ S + mx, 0);\n\tint ans = 0;\n\tint Ans[Q];\n\tint L = 0, R = 0;\n\tfor (const\
    \ auto& [l, r, index] : zawa::mo(N, Query)) {\n\t\twhile (R < r) {\n\t\t\tS[A[R]]++;\n\
    \t\t\tif (!(S[A[R]] & 1)) ans++;\n\t\t\tR++;\n\t\t}\n\t\twhile (L > l) {\n\t\t\
    \tL--;\n\t\t\tS[A[L]]++;\n\t\t\tif (!(S[A[L]] & 1)) ans++;\n\t\t}\n\t\twhile (R\
    \ > r) {\n\t\t\tR--;\n\t\t\tS[A[R]]--;\n\t\t\tif (S[A[R]] & 1) ans--;\n\t\t}\n\
    \t\twhile (L < l) {\n\t\t\tS[A[L]]--;\n\t\t\tif (S[A[L]] & 1) ans--;\n\t\t\tL++;\n\
    \t\t}\n\t\tAns[index] = ans;\n\t}\n\tfor (int i = 0 ; i < Q ; i++)\n\t\tstd::printf(\"\
    %d\\n\", Ans[i]);\n}\n"
  dependsOn:
  - src/algorithm/mo.hpp
  isVerificationFile: true
  path: test/ABC242-G.test.cpp
  requiredBy: []
  timestamp: '2023-03-30 00:09:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC242-G.test.cpp
layout: document
redirect_from:
- /verify/test/ABC242-G.test.cpp
- /verify/test/ABC242-G.test.cpp.html
title: test/ABC242-G.test.cpp
---
