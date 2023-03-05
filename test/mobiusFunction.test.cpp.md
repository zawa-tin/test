---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/mobiusFunction.hpp
    title: "mobiusFunction (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u5024\u306E\u5217\
      \u6319)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/mobiusFunction.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/mobiusFunction.hpp\"\n\n#line 2 \"src/math/primeSieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass primeSieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprimeSieve() {}\n\tprimeSieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline bool operator[](std::size_t i) const {\n\t\treturn sieve[i];\n\
    \t}\n\n\tinline std::size_t size() const {\n\t\treturn sieve.size();\n\t}\n};\n\
    \n}// namespace zawa\n#line 4 \"src/math/mobiusFunction.hpp\"\n\n#line 6 \"src/math/mobiusFunction.hpp\"\
    \n\nnamespace zawa {\n\nclass mobiusFunction {\nprivate:\n\tstd::vector<int> table;\n\
    \npublic:\n\tmobiusFunction() {}\n\tmobiusFunction(std::size_t n) : table(std::vector(n\
    \ + 1, 1)) {\n\t\tprimeSieve siv(n);\n\t\tfor (std::size_t i = 2 ; i <= n ; i++)\
    \ {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i ; j <= n ; j += i) {\n\
    \t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j] = 0;\n\t\t\t\t\t}\n\t\t\t\
    \t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline int operator[](int i) const {\n\t\treturn table[i];\n\t}\n\
    };\n\n}// namespace zawa\n#line 4 \"test/mobiusFunction.test.cpp\"\n\n#include\
    \ <iostream>\n#include <cassert>\n\nint main() {\n\tzawa::mobiusFunction mf(10);\n\
    \tstd::vector ans = { 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };\n\tfor (int i = 0 ;\
    \ i < 10 ; i++) {\n\t\tassert(ans[i] == mf[i + 1]);\n\t}\n\tstd::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/mobiusFunction.hpp\"\n\n#include <iostream>\n#include\
    \ <cassert>\n\nint main() {\n\tzawa::mobiusFunction mf(10);\n\tstd::vector ans\
    \ = { 1, -1, -1, 0, -1, 1, -1, 0, 0, 1 };\n\tfor (int i = 0 ; i < 10 ; i++) {\n\
    \t\tassert(ans[i] == mf[i + 1]);\n\t}\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/math/mobiusFunction.hpp
  - src/math/primeSieve.hpp
  isVerificationFile: true
  path: test/mobiusFunction.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 22:25:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mobiusFunction.test.cpp
layout: document
redirect_from:
- /verify/test/mobiusFunction.test.cpp
- /verify/test/mobiusFunction.test.cpp.html
title: test/mobiusFunction.test.cpp
---
