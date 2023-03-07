---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc280/tasks/abc280_a
    links:
    - https://atcoder.jp/contests/abc280/tasks/abc280_a
  bundledCode: "#line 1 \"test/ABC280-A.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_a\"\
    \n\n#include <iostream>\n#include <string>\n#include <algorithm>\n\nint main()\
    \ {\n\tint H, W; std::cin >> H >> W;\n\tint ans = 0;\n\tfor (int _ = 0 ; _ < H\
    \ ; _++) {\n\t\tstd::string s; std::cin >> s;\n\t\tans += std::count(s.begin(),\
    \ s.end(), '#');\n\t}\n\tstd::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_a\"\n\n\
    #include <iostream>\n#include <string>\n#include <algorithm>\n\nint main() {\n\
    \tint H, W; std::cin >> H >> W;\n\tint ans = 0;\n\tfor (int _ = 0 ; _ < H ; _++)\
    \ {\n\t\tstd::string s; std::cin >> s;\n\t\tans += std::count(s.begin(), s.end(),\
    \ '#');\n\t}\n\tstd::cout << ans << std::endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/ABC280-A.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 04:15:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC280-A.test.cpp
layout: document
redirect_from:
- /verify/test/ABC280-A.test.cpp
- /verify/test/ABC280-A.test.cpp.html
title: test/ABC280-A.test.cpp
---
