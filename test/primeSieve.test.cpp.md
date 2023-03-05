---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/primeSieve.hpp
    title: "primeSieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/primeSieve.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#line 2 \"src/math/primeSieve.hpp\"\n\n#include <vector>\n\nnamespace zawa\
    \ {\n\nclass primeSieve {\nprivate:\n\tstd::vector<bool> sieve;\n\npublic:\n\t\
    primeSieve() {}\n\tprimeSieve(std::size_t n) : sieve(n + 1, true) {\n\t\tif (n\
    \ >= 0) {\n\t\t\tsieve[0] = false;\n\t\t}\n\t\tif (n >= 1) {\n\t\t\tsieve[1] =\
    \ false;\n\t\t}\n\t\tfor (std::size_t i = 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i])\
    \ {\n\t\t\t\tfor (std::size_t j = i * 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j]\
    \ = false;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tinline bool operator[](std::size_t\
    \ i) const {\n\t\treturn sieve[i];\n\t}\n\n\tinline std::size_t size() const {\n\
    \t\treturn sieve.size();\n\t}\n};\n\n}// namespace zawa\n#line 4 \"test/primeSieve.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tzawa::primeSieve siv(100000000);\n\t\
    int n; std::cin >> n;\n\tint ans = 0;\n\tfor (int _ = 0 ; _ < n ; _++) {\n\t\t\
    int v; std::cin >> v;\n\t\tans += siv[v];\n\t}\n\tstd::cout << ans << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include \"../src/math/primeSieve.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\tzawa::primeSieve siv(100000000);\n\tint n; std::cin >> n;\n\tint ans =\
    \ 0;\n\tfor (int _ = 0 ; _ < n ; _++) {\n\t\tint v; std::cin >> v;\n\t\tans +=\
    \ siv[v];\n\t}\n\tstd::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/math/primeSieve.hpp
  isVerificationFile: true
  path: test/primeSieve.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 22:25:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/primeSieve.test.cpp
layout: document
redirect_from:
- /verify/test/primeSieve.test.cpp
- /verify/test/primeSieve.test.cpp.html
title: test/primeSieve.test.cpp
---
