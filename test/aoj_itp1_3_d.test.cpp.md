---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor.hpp
    title: "Divisor(\u7D04\u6570\u5217\u6319)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
  bundledCode: "#line 1 \"test/aoj_itp1_3_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#line 2 \"src/math/divisor.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\n    std::vector<int> divisor(int x) {\n        std::vector<int>\
    \ res;\n\n        for (int i = 1 ; i * i <= x ; i++) {\n            if (x % i)\
    \ continue;\n            res.emplace_back(i);\n            if (i * i != x) res.emplace_back(x\
    \ / i);\n        }\n        std::sort(res.begin(), res.end());\n\n        return\
    \ res;\n    }\n\n}// namespace zawa\n#line 4 \"test/aoj_itp1_3_d.test.cpp\"\n\
    #include <iostream>\n\nint main() {\n    int a, b, c;\n    std::cin >> a >> b\
    \ >> c;\n    int ans = 0;\n    for (auto div : zawa::divisor(c)) {\n        ans\
    \ += a <= div and div <= b;\n    }\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include \"../src/math/divisor.hpp\"\n#include <iostream>\n\nint main() {\n\
    \    int a, b, c;\n    std::cin >> a >> b >> c;\n    int ans = 0;\n    for (auto\
    \ div : zawa::divisor(c)) {\n        ans += a <= div and div <= b;\n    }\n  \
    \  std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/math/divisor.hpp
  isVerificationFile: true
  path: test/aoj_itp1_3_d.test.cpp
  requiredBy: []
  timestamp: '2022-07-31 01:03:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_itp1_3_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_itp1_3_d.test.cpp
- /verify/test/aoj_itp1_3_d.test.cpp.html
title: test/aoj_itp1_3_d.test.cpp
---
