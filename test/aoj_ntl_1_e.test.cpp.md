---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Extend-GCD.hpp
    title: "Extend GCD (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
      \u9664\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E
  bundledCode: "#line 1 \"test/aoj_ntl_1_e.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n#line 2 \"src/math/Extend-GCD.hpp\"\n\nnamespace zawa\
    \ {\n\n    void rec(long long a, long long b, long long& x, long long& y) {\n\
    \        if (b == 0) {\n            x = 1;\n            y = 0;\n            return;\n\
    \        }\n\n        rec(b, a % b, y, x);\n        \n        y -= a / b * x;\n\
    \    }\n\n    std::pair<long long, long long> extend_gcd(long long a, long long\
    \ b) {\n        long long resx = 0, resy = 0;\n        rec(a, b, resx, resy);\n\
    \        return {resx, resy};\n    }\n\n}// namespace zawa\n#line 5 \"test/aoj_ntl_1_e.test.cpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n    auto [x, y] = zawa::extend_gcd(a,\
    \ b);\n    std::cout << x << ' ' << y << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E\"\
    \n\n#include <iostream>\n#include \"../src/math/Extend-GCD.hpp\"\n\nint main()\
    \ {\n    int a, b;\n    std::cin >> a >> b;\n    auto [x, y] = zawa::extend_gcd(a,\
    \ b);\n    std::cout << x << ' ' << y << std::endl;\n}\n"
  dependsOn:
  - src/math/Extend-GCD.hpp
  isVerificationFile: true
  path: test/aoj_ntl_1_e.test.cpp
  requiredBy: []
  timestamp: '2022-08-15 02:43:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_ntl_1_e.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_ntl_1_e.test.cpp
- /verify/test/aoj_ntl_1_e.test.cpp.html
title: test/aoj_ntl_1_e.test.cpp
---
