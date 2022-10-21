---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Pascal-Triangle.hpp
    title: "Pascal's Triangle (\u30CA\u30A4\u30FC\u30D6\u306A\u4E8C\u9805\u4FC2\u6570\
      \u30C6\u30FC\u30D6\u30EB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc254/submissions/35829847
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Pascal-Triangle.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/Pascal-Triangle.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nclass Pascal_Triangle {\nprivate:\n    std::vector<std::vector<T>>\
    \ table;\npublic:\n    Pascal_Triangle(int max_n, int max_r)\n        : table(max_n\
    \ + 1, std::vector<T>(max_r + 1)) {\n        table[0][0] = 1;\n        for (int\
    \ i = 1 ; i <= max_n ; i++) {\n            for (int j = 1 ; j <= max_r ; j++)\
    \ {\n                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];\n  \
    \          }\n        }\n    }\n\n    T ncr(int n, int r) {\n        return table.at(n).at(r);\n\
    \    }\n};\n\n} // namespace zawa\n#line 4 \"test/Pascal-Triangle.test.cpp\"\n\
    #include <iostream>\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * ABC254-B Practical Computing\n * https://atcoder.jp/contests/abc254/submissions/35829847\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/Pascal-Triangle.hpp\"\n#include <iostream>\n\nint main()\
    \ {\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * ABC254-B Practical\
    \ Computing\n * https://atcoder.jp/contests/abc254/submissions/35829847\n */\n"
  dependsOn:
  - src/math/Pascal-Triangle.hpp
  isVerificationFile: true
  path: test/Pascal-Triangle.test.cpp
  requiredBy: []
  timestamp: '2022-10-21 17:48:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Pascal-Triangle.test.cpp
layout: document
redirect_from:
- /verify/test/Pascal-Triangle.test.cpp
- /verify/test/Pascal-Triangle.test.cpp.html
title: test/Pascal-Triangle.test.cpp
---
