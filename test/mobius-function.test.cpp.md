---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/mobius-function.hpp
    title: "mobius-function (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570)"
  - icon: ':heavy_check_mark:'
    path: src/math/prime-sieve.hpp
    title: "prime-sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/mobius-function.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/mobius-function.hpp\"\n\n#line 2 \"src/math/prime-sieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass prime_sieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprime_sieve() {}\n\tprime_sieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ i ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\tbool operator[](std::size_t i) {\n\t\treturn sieve[i];\n\t}\n};\n\n\
    }// namespace zawa\n#line 4 \"src/math/mobius-function.hpp\"\n\n#line 6 \"src/math/mobius-function.hpp\"\
    \n\nnamespace zawa {\n\nclass mobius_function {\nprivate:\n\tstd::vector<int>\
    \ table;\n\npublic:\n\tmobius_function() {}\n\tmobius_function(std::size_t n)\
    \ : table(std::vector(n + 1, 1)) {\n\t\tprime_sieve siv(n);\n\t\tfor (std::size_t\
    \ i = 2 ; i <= n ; i++) {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i\
    \ ; j <= n ; j += i) {\n\t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j]\
    \ = 0;\n\t\t\t\t\t}\n\t\t\t\t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tint operator[](int i) {\n\t\treturn table[i];\n\
    \t}\n};\n\n}// namespace zawa\n#line 4 \"test/mobius-function.test.cpp\"\n\n#include\
    \ <iostream>\n#include <cassert>\n\nint main() {\n\tzawa::mobius_function mf(10);\n\
    \tstd::vector ans = { 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };\n\tfor (int i = 0 ;\
    \ i < 10 ; i++) {\n\t\tassert(ans[i] == mf[i + 1]);\n\t}\n\tstd::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/mobius-function.hpp\"\n\n#include <iostream>\n#include\
    \ <cassert>\n\nint main() {\n\tzawa::mobius_function mf(10);\n\tstd::vector ans\
    \ = { 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };\n\tfor (int i = 0 ; i < 10 ; i++) {\n\
    \t\tassert(ans[i] == mf[i + 1]);\n\t}\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/math/mobius-function.hpp
  - src/math/prime-sieve.hpp
  isVerificationFile: true
  path: test/mobius-function.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 11:44:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mobius-function.test.cpp
layout: document
redirect_from:
- /verify/test/mobius-function.test.cpp
- /verify/test/mobius-function.test.cpp.html
title: test/mobius-function.test.cpp
---
