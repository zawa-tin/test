---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/DSU.hpp
    title: "DSU (\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u306E\u68EE\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A
  bundledCode: "#line 1 \"test/DSU1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#line 2 \"src/dataStructure/DSU.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n\nnamespace zawa {\n\nclass DSU {\nprivate:\n    std::vector<int>\
    \ parents;\n    std::vector<int> sizes;\n\npublic:\n    DSU(std::size_t n) : parents(n,\
    \ 0), sizes(n, 1) {\n        for (std::size_t i = 0 ; i < n ; i++) {\n       \
    \     parents[i] = i;\n        }\n    }\n\n    int leader(int x) {\n        if\
    \ (x == parents[x]) {\n            return x;\n        }\n        else {\n    \
    \        return parents[x] = leader(parents[x]);\n        }\n    }\n\n    bool\
    \ same(int x, int y) {\n        return leader(x) == leader(y);\n    }\n\n    void\
    \ merge(int x, int y) {\n        if (leader(x) == leader(y)) {\n            return;\n\
    \        }\n        if (sizes[leader(x)] < sizes[leader(y)]) {\n            std::swap(x,\
    \ y);\n        }\n        sizes[leader(x)] += sizes[leader(y)]; \n        parents[leader(y)]\
    \ = leader(x);\n    }\n\n    inline int size(int x) {\n        return sizes[leader(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector res(parents.size(),\
    \ std::vector(0, 0));\n        for (int i = 0 ; i < (int)parents.size() ; i++)\
    \ {\n            res[leader(i)].push_back(i);\n        }\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), \n                    [](std::vector<int> x) { return x.empty();\
    \ }), res.end());\n        return res;\n    }\n};\n\n}// namespace zawa\n#line\
    \ 4 \"test/DSU1.test.cpp\"\n\n#include <iostream>\n\nint main() {\n    int n,\
    \ q; std::cin >> n >> q;\n    zawa::DSU uf(n);\n    for (int _ = 0 ; _ < q ; _++)\
    \ {\n        int com, x, y; std::cin >> com >> x >> y;\n        if (com == 0)\
    \ {\n            uf.merge(x, y);\n        }\n        if (com == 1) {\n       \
    \     std::cout << uf.same(x, y) << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A\"\
    \n\n#include \"../src/dataStructure/DSU.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    int n, q; std::cin >> n >> q;\n    zawa::DSU uf(n);\n    for (int _ =\
    \ 0 ; _ < q ; _++) {\n        int com, x, y; std::cin >> com >> x >> y;\n    \
    \    if (com == 0) {\n            uf.merge(x, y);\n        }\n        if (com\
    \ == 1) {\n            std::cout << uf.same(x, y) << std::endl;\n        }\n \
    \   }\n}\n"
  dependsOn:
  - src/dataStructure/DSU.hpp
  isVerificationFile: true
  path: test/DSU1.test.cpp
  requiredBy: []
  timestamp: '2022-11-24 06:24:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/DSU1.test.cpp
layout: document
redirect_from:
- /verify/test/DSU1.test.cpp
- /verify/test/DSU1.test.cpp.html
title: test/DSU1.test.cpp
---
