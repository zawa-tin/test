---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Euler-Function.hpp
    title: "Euler Function(\u30AA\u30A4\u30E9\u30FC\u95A2\u6570)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/aoj_ntl_1_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#include <iostream>\n#line 2 \"src/math/Euler-Function.hpp\"\n\n#line 2 \"\
    src/math/factorize.hpp\"\n\n#include <vector>\n\nnamespace zawa {\n\n    std::vector<std::pair<long\
    \ long, int>> factorize(long long x) {\n        std::vector<std::pair<long long,\
    \ int>> res;\n\n        for (long long i = 2 ; i * i <= x ; i++) {\n         \
    \   if (x % i) continue;\n            int cnt = 0;\n            while (!(x % i))\
    \ {\n                cnt++;\n                x /= i;\n            }\n        \
    \    res.emplace_back(i, cnt);\n        }\n        if (x != 1) res.emplace_back(x,\
    \ 1);\n\n        return res;\n    }\n\n} // namespace zawa\n#line 4 \"src/math/Euler-Function.hpp\"\
    \n\nnamespace zawa {\n    \n    long long euler_function(long long x) {\n    \
    \    long long res = x;\n\n        for (auto v : zawa::factorize(x)) {\n     \
    \       res /= v.first;\n            res *= v.first - 1;\n        }\n\n      \
    \  return res;\n    }\n\n}// namespace zawa\n#line 5 \"test/aoj_ntl_1_d.test.cpp\"\
    \n\nint main() {\n    long long n;\n    std::cin >> n;\n    std::cout << zawa::euler_function(n)\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#include <iostream>\n#include \"../src/math/Euler-Function.hpp\"\n\nint main()\
    \ {\n    long long n;\n    std::cin >> n;\n    std::cout << zawa::euler_function(n)\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/math/Euler-Function.hpp
  - src/math/factorize.hpp
  isVerificationFile: true
  path: test/aoj_ntl_1_d.test.cpp
  requiredBy: []
  timestamp: '2022-08-12 22:25:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_ntl_1_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_ntl_1_d.test.cpp
- /verify/test/aoj_ntl_1_d.test.cpp.html
title: test/aoj_ntl_1_d.test.cpp
---
