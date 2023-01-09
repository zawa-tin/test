---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/miller-rabin.hpp
    title: "miller-rabin (\u7D20\u6570\u5224\u5B9A\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://algo-method.com/submissions/760056
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/miller-rabin.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/miller-rabin.hpp\"\n\n#include <vector>\n\nnamespace zawa::impl\
    \ {\n\nlong long modpow(__int128_t a, __int128_t b, long long mod) {\n\tlong long\
    \ res = 1LL;\n\ta %= mod;\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres = ((__int128_t)res\
    \ * a) % mod;\n\t\t}\n\t\ta = (a * a) % mod;\n\t\tb >>= 1;\n\t}\n\treturn res;\n\
    }\n\nstd::vector<long long> cond = { 2, 325, 9375, 28178, 450775, 978504, 1795265022\
    \ };\n\n} // namespace zawa::impl\n\nnamespace zawa {\n\nbool isprime(long long\
    \ n) {\n\tif (n <= 1) {\n\t\treturn false;\n\t}\n\tif (n == 2 or n == 3) {\n\t\
    \treturn true;\n\t}\n\tif (!(n & 1)) {\n\t\treturn false;\n\t}\n\tlong long s\
    \ = 0LL, d = n - 1;\n\twhile (d % 2 == 0) {\n\t\ts++;\n\t\td >>= 1;\n\t}\n\tfor\
    \ (auto c : impl::cond) {\n\t\tif (c % n == 0) {\n\t\t\treturn true;\n\t\t}\n\t\
    \tlong long x = impl::modpow(c, d, n);\n\t\tif (x != 1) {\n\t\t\tlong long t =\
    \ 0;\n\t\t\tfor ( ; t < s ; t++) {\n\t\t\t\tif (x == n - 1) {\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t\tx = ((__int128_t)x * x) % n;\n\t\t\t}\n\t\t\tif (t == s) {\n\
    \t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t}\n\treturn true;\n}\n\n} // namespace\
    \ zawa\n#line 4 \"test/miller-rabin.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\t// int n; std::cin >> n;\n\t// for (int _ = 0 ; _ < n ; _++) {\n\t// \t\
    long long a; std::cin >> a;\n\t// \tstd::cout << (zawa::isprime(a) ? \"Yes\" :\
    \ \"No\") << std::endl;\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/* \n * \u30A2\u30EB\u30B4\u5F0F \u30DF\u30E9\u30FC-\u30E9\u30D3\u30F3\u306E\
    \u7D20\u6570\u5224\u5B9A\u6CD5\n * https://algo-method.com/submissions/760056\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/miller-rabin.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\t// int n; std::cin >> n;\n\t// for (int _ = 0 ; _ < n ; _++) {\n\t// \t\
    long long a; std::cin >> a;\n\t// \tstd::cout << (zawa::isprime(a) ? \"Yes\" :\
    \ \"No\") << std::endl;\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/* \n * \u30A2\u30EB\u30B4\u5F0F \u30DF\u30E9\u30FC-\u30E9\u30D3\u30F3\u306E\
    \u7D20\u6570\u5224\u5B9A\u6CD5\n * https://algo-method.com/submissions/760056\n\
    \ */\n"
  dependsOn:
  - src/math/miller-rabin.hpp
  isVerificationFile: true
  path: test/miller-rabin.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 22:14:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/miller-rabin.test.cpp
layout: document
redirect_from:
- /verify/test/miller-rabin.test.cpp
- /verify/test/miller-rabin.test.cpp.html
title: test/miller-rabin.test.cpp
---
