---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/disjointSetUnion.hpp
    title: "disjointSetUnion (\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u306E\u68EE\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/disjointSetUnion-test2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"src/dataStructure/disjointSetUnion.hpp\"\
    \n\n#include <vector>\n#include <utility>\n#include <algorithm>\n#include <numeric>\n\
    #include <cassert>\n\nnamespace zawa {\n\nclass disjointSetUnion {\nprivate:\n\
    \tstd::vector<int> parents;\n\tstd::vector<int> sizes;\n\npublic:\n\tdisjointSetUnion(std::size_t\
    \ n) : parents(n, 0), sizes(n, 1) {\n\t\tstd::iota(parents.begin(), parents.end(),\
    \ 0);\n\t}\n\n\tint leader(int x) {\n\t\tassert(0 <= x and x < (int)parents.size());\n\
    \t\treturn (parents[x] == x ? x : parents[x] = leader(parents[x]));\n\t}\n\n\t\
    bool same(int x, int y) {\n\t\treturn leader(x) == leader(y);\n\t}\n\n\tvoid merge(int\
    \ x, int y) {\n\t\tint lx = leader(x), ly = leader(y);\n\t\tif (lx == ly) return;\n\
    \t\tif (sizes[lx] < sizes[ly]) std::swap(lx, ly);\n\t\tsizes[lx] += sizes[ly];\
    \ \n\t\tparents[ly] = lx;\n\t}\n\n\tint size(int x) {\n\t\treturn sizes[leader(x)];\n\
    \t}\n\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector res(parents.size(),\
    \ std::vector(0, 0));\n\t\tfor (int i = 0 ; i < (int)parents.size() ; i++) {\n\
    \t\t\tres[leader(i)].push_back(i);\n\t\t}\n\t\tres.erase(std::remove_if(res.begin(),\
    \ res.end(), \n\t\t\t\t\t[](std::vector<int> x) { return x.empty(); }), res.end());\n\
    \t\treturn res;\n\t}\n};\n\n}// namespace zawa\n#line 4 \"test/disjointSetUnion-test2.test.cpp\"\
    \n\n#include <cstdio>\n\nint main() {\n    int N, Q;\n\tstd::scanf(\"%d%d\", &N,\
    \ &Q);\n    zawa::disjointSetUnion uf(N);\n    for (int _ = 0 ; _ < Q ; _++) {\n\
    \t\tint t, u, v;\n\t\tstd::scanf(\"%d%d%d\", &t, &u, &v);\n        if (t == 0)\
    \ uf.merge(u, v);\n\t\telse std::printf(\"%d\\n\", uf.same(u, v));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../src/dataStructure/disjointSetUnion.hpp\"\n\n#include <cstdio>\n\nint main()\
    \ {\n    int N, Q;\n\tstd::scanf(\"%d%d\", &N, &Q);\n    zawa::disjointSetUnion\
    \ uf(N);\n    for (int _ = 0 ; _ < Q ; _++) {\n\t\tint t, u, v;\n\t\tstd::scanf(\"\
    %d%d%d\", &t, &u, &v);\n        if (t == 0) uf.merge(u, v);\n\t\telse std::printf(\"\
    %d\\n\", uf.same(u, v));\n    }\n}\n"
  dependsOn:
  - src/dataStructure/disjointSetUnion.hpp
  isVerificationFile: true
  path: test/disjointSetUnion-test2.test.cpp
  requiredBy: []
  timestamp: '2023-04-03 07:50:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/disjointSetUnion-test2.test.cpp
layout: document
redirect_from:
- /verify/test/disjointSetUnion-test2.test.cpp
- /verify/test/disjointSetUnion-test2.test.cpp.html
title: test/disjointSetUnion-test2.test.cpp
---
