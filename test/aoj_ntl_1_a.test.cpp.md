---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/factorize.hpp
    title: "Factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A
  bundledCode: "#line 1 \"test/aoj_ntl_1_a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include <iostream>\n\n#line 2 \"src/math/factorize.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\n    std::vector<std::pair<long long, int>> factorize(long\
    \ long x) {\n        std::vector<std::pair<long long, int>> res;\n\n        for\
    \ (long long i = 2 ; i * i <= x ; i++) {\n            if (x % i) continue;\n \
    \           int cnt = 0;\n            while (!(x % i)) {\n                cnt++;\n\
    \                x /= i;\n            }\n            res.emplace_back(i, cnt);\n\
    \        }\n        if (x != 1) res.emplace_back(x, 1);\n\n        return res;\n\
    \    }\n\n} // namespace zawa\n#line 5 \"test/aoj_ntl_1_a.test.cpp\"\n\nint main()\
    \ {\n    int n; std::cin >> n;\n    std::cout << n << ':';\n    for (auto [x,\
    \ cnt] : zawa::factorize(n)) {\n        for (int i = 0 ; i < cnt ; i++) {\n  \
    \          std::cout << ' ' << x;\n        }\n    }\n    std::cout << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A\"\
    \n#include <iostream>\n\n#include \"../src/math/factorize.hpp\"\n\nint main()\
    \ {\n    int n; std::cin >> n;\n    std::cout << n << ':';\n    for (auto [x,\
    \ cnt] : zawa::factorize(n)) {\n        for (int i = 0 ; i < cnt ; i++) {\n  \
    \          std::cout << ' ' << x;\n        }\n    }\n    std::cout << std::endl;\n\
    }\n"
  dependsOn:
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/aoj_ntl_1_a.test.cpp
  requiredBy: []
  timestamp: '2022-07-25 23:24:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_ntl_1_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_ntl_1_a.test.cpp
- /verify/test/aoj_ntl_1_a.test.cpp.html
title: test/aoj_ntl_1_a.test.cpp
---
