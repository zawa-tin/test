---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Ear-DP.hpp
    title: "Ear-DP (\u8033DP)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc211/submissions/35826346
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Ear-DP.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/algorithm/Ear-DP.hpp\"\n\n#include <vector>\n#include <string>\n\
    \nnamespace zawa::impl {\n\ntemplate<typename T, typename RES>\nRES ear_dp(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    std::vector<std::vector<RES>>\
    \ dp(a.size() + 1, std::vector<RES>(b.size() + 1));\n    for (std::size_t i =\
    \ 0 ; i < a.size() + 1 ; i++) {\n        dp[i][0] = 1;\n    }\n\n    for (size_t\
    \ i = 1 ; i < a.size() + 1 ; i++) {\n        for (size_t j = 1 ; j < b.size()\
    \ + 1 ; j++) {\n            dp[i][j] += dp[i - 1][j];\n            if (a[i - 1]\
    \ == b[j - 1]) {\n                dp[i][j] += dp[i][j - 1];\n            }\n \
    \       }\n    }\n\n    return dp.back().back();\n}\n\n} // namespace zawa::impl\n\
    \nnamespace zawa {\n\ntemplate<typename T, typename RES>\nRES ear_dp(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    return impl::ear_dp<T, RES>(a, b);\n}\n\n\
    template<typename RES>\nRES ear_dp(const std::string& a, const std::string& b)\
    \ {\n    std::vector<char> newa(a.begin(), a.end()), newb(b.begin(), b.end());\n\
    \    return impl::ear_dp<char, RES>(newa, newb);\n}\n\n}\n#line 4 \"test/Ear-DP.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * ABC211-C chokudai\n * https://atcoder.jp/contests/abc211/submissions/35826346\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/Ear-DP.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * ABC211-C chokudai\n\
    \ * https://atcoder.jp/contests/abc211/submissions/35826346\n */\n"
  dependsOn:
  - src/algorithm/Ear-DP.hpp
  isVerificationFile: true
  path: test/Ear-DP.test.cpp
  requiredBy: []
  timestamp: '2022-10-21 15:36:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Ear-DP.test.cpp
layout: document
redirect_from:
- /verify/test/Ear-DP.test.cpp
- /verify/test/Ear-DP.test.cpp.html
title: test/Ear-DP.test.cpp
---
