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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/mo.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#line 2 \"src/algorithm/mo.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n#include <algorithm>\n#include <cmath>\n\nnamespace zawa {\n\
    \nstd::vector<std::tuple<int, int, int>> mo(int N, const std::vector<std::pair<int,\
    \ int>>& Q) {\n\tint sq = std::sqrt(Q.size() + 1);\n\tstd::vector tmp((N + sq\
    \ - 1) / sq, std::vector(0, std::tuple(0, 0, 0)));\n\tfor (int i = 0 ; i < (int)Q.size()\
    \ ; i++)\n\t\ttmp[Q[i].first / sq].emplace_back(Q[i].second, Q[i].first, i);\n\
    \tstd::vector res(0, std::tuple(0, 0, 0));\n\tfor (int i = 0 ; i < (int)tmp.size()\
    \ ; i++) {\n\t\tstd::sort(tmp[i].begin(), tmp[i].end());\n\t\tif (i & 1) std::reverse(tmp[i].begin(),\
    \ tmp[i].end());\n\t\tfor (const auto& [r, l, index] : tmp[i]) res.emplace_back(l,\
    \ r, index);\n\t}\n\treturn res;\n}\n\n}// namespace zawa\n#line 4 \"test/mo.test.cpp\"\
    \n\n#include <cstdio>\n#line 8 \"test/mo.test.cpp\"\n\nint main() {\n\tint N,\
    \ Q;\n\tstd::scanf(\"%d%d\", &N, &Q);\n\tstd::vector<int> A(N);\n\tfor (int i\
    \ = 0 ; i < N ; i++)\n\t\tstd::scanf(\"%d\", &A[i]);\n\tstd::vector<std::pair<int,\
    \ int>> Query(Q);\n\tfor (int i = 0 ; i < Q ; i++)\n\t\tstd::scanf(\"%d%d\", &Query[i].first,\
    \ &Query[i].second);\t\n\tstd::vector<long long> Ans(Q);\n\tlong long ans = 0LL;\n\
    \tint nowl = 0, nowr = 0;\n\tfor (auto [l, r, index] : zawa::mo(N, Query)) {\n\
    \t\twhile (nowr < r) ans += A[nowr++];\n\t\twhile (nowl > l) ans += A[--nowl];\n\
    \t\twhile (nowr > r) ans -= A[--nowr];\n\t\twhile (nowl < l) ans -= A[nowl++];\n\
    \t\tAns[index] = ans;\n\t}\n\tfor (int i = 0 ; i < Q ; i++)\n\t\tstd::printf(\"\
    %lld\\n\", Ans[i]);\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../src/algorithm/mo.hpp\"\n\n#include <cstdio>\n#include <vector>\n\
    #include <utility>\n\nint main() {\n\tint N, Q;\n\tstd::scanf(\"%d%d\", &N, &Q);\n\
    \tstd::vector<int> A(N);\n\tfor (int i = 0 ; i < N ; i++)\n\t\tstd::scanf(\"%d\"\
    , &A[i]);\n\tstd::vector<std::pair<int, int>> Query(Q);\n\tfor (int i = 0 ; i\
    \ < Q ; i++)\n\t\tstd::scanf(\"%d%d\", &Query[i].first, &Query[i].second);\t\n\
    \tstd::vector<long long> Ans(Q);\n\tlong long ans = 0LL;\n\tint nowl = 0, nowr\
    \ = 0;\n\tfor (auto [l, r, index] : zawa::mo(N, Query)) {\n\t\twhile (nowr < r)\
    \ ans += A[nowr++];\n\t\twhile (nowl > l) ans += A[--nowl];\n\t\twhile (nowr >\
    \ r) ans -= A[--nowr];\n\t\twhile (nowl < l) ans -= A[nowl++];\n\t\tAns[index]\
    \ = ans;\n\t}\n\tfor (int i = 0 ; i < Q ; i++)\n\t\tstd::printf(\"%lld\\n\", Ans[i]);\n\
    }\n"
  dependsOn:
  - src/algorithm/mo.hpp
  isVerificationFile: true
  path: test/mo.test.cpp
  requiredBy: []
  timestamp: '2023-03-30 00:09:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mo.test.cpp
layout: document
redirect_from:
- /verify/test/mo.test.cpp
- /verify/test/mo.test.cpp.html
title: test/mo.test.cpp
---
