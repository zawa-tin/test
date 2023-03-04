---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC170-D.test.cpp
    title: test/ABC170-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC177-E.test.cpp
    title: test/ABC177-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC250-D.test.cpp
    title: test/ABC250-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC254-D.test.cpp
    title: test/ABC254-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC292-C.test.cpp
    title: test/ABC292-C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/linearSieve.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n\nnamespace zawa {\n\nclass linearSieve {\nprivate:\n\tstd::vector<int>\
    \ divs;\n\tstd::vector<int> primes;\n\npublic:\n\tlinearSieve() {}\n\tlinearSieve(std::size_t\
    \ n) : divs(n + 1, 1) {\n\t\tfor (std::size_t i = 2 ; i < n + 1 ; i++) {\n\t\t\
    \tif (divs[i] == 1) {\n\t\t\t\tdivs[i] = i;\n\t\t\t\tprimes.push_back((int)i);\n\
    \t\t\t}\n\t\t\tfor (const auto& p : primes) {\n\t\t\t\tif (p * i > n or p > divs[i])\
    \ {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tdivs[p * i] = p;\n\t\t\t}\n\t\t}\n\t\
    }\n\n\tstd::vector<std::pair<int, int>> factorize(int x) {\n\t\tstd::vector res(0,\
    \ std::pair(0, 0));\n\t\twhile (x > 1) {\n\t\t\tres.emplace_back(divs[x], 0);\n\
    \t\t\twhile (divs[x] == res.back().first) {\n\t\t\t\tx /= divs[x];\n\t\t\t\tres.back().second++;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int x) {\n\t\
    \tstd::vector res(1, 1);\n\t\tfor (const auto& [p, q] : factorize(x)) {\n\t\t\t\
    std::size_t now = res.size();\n\t\t\tfor (std::size_t i = 0 ; i < now ; i++) {\n\
    \t\t\t\tint mul = p;\n\t\t\t\tfor (int _ = 0 ; _ < q ; _++) {\n\t\t\t\t\tres.emplace_back(res[i]\
    \ * mul);\n\t\t\t\t\tmul *= p;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\tstd::vector<int> enumPrime() {\n\t\treturn primes;\n\t}\n\n\tint numPrime()\
    \ {\n\t\treturn (int)primes.size();\n\t}\n\n\tbool isPrime(int x) {\n\t\treturn\
    \ (x != 0 and x != 1 and divs[x] == x);\n\t}\n\n\tint operator[](int x) {\n\t\t\
    return divs[x];\n\t}\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n\nnamespace zawa {\n\
    \nclass linearSieve {\nprivate:\n\tstd::vector<int> divs;\n\tstd::vector<int>\
    \ primes;\n\npublic:\n\tlinearSieve() {}\n\tlinearSieve(std::size_t n) : divs(n\
    \ + 1, 1) {\n\t\tfor (std::size_t i = 2 ; i < n + 1 ; i++) {\n\t\t\tif (divs[i]\
    \ == 1) {\n\t\t\t\tdivs[i] = i;\n\t\t\t\tprimes.push_back((int)i);\n\t\t\t}\n\t\
    \t\tfor (const auto& p : primes) {\n\t\t\t\tif (p * i > n or p > divs[i]) {\n\t\
    \t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tdivs[p * i] = p;\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    std::vector<std::pair<int, int>> factorize(int x) {\n\t\tstd::vector res(0, std::pair(0,\
    \ 0));\n\t\twhile (x > 1) {\n\t\t\tres.emplace_back(divs[x], 0);\n\t\t\twhile\
    \ (divs[x] == res.back().first) {\n\t\t\t\tx /= divs[x];\n\t\t\t\tres.back().second++;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int x) {\n\t\
    \tstd::vector res(1, 1);\n\t\tfor (const auto& [p, q] : factorize(x)) {\n\t\t\t\
    std::size_t now = res.size();\n\t\t\tfor (std::size_t i = 0 ; i < now ; i++) {\n\
    \t\t\t\tint mul = p;\n\t\t\t\tfor (int _ = 0 ; _ < q ; _++) {\n\t\t\t\t\tres.emplace_back(res[i]\
    \ * mul);\n\t\t\t\t\tmul *= p;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\tstd::vector<int> enumPrime() {\n\t\treturn primes;\n\t}\n\n\tint numPrime()\
    \ {\n\t\treturn (int)primes.size();\n\t}\n\n\tbool isPrime(int x) {\n\t\treturn\
    \ (x != 0 and x != 1 and divs[x] == x);\n\t}\n\n\tint operator[](int x) {\n\t\t\
    return divs[x];\n\t}\n};\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/linearSieve.hpp
  requiredBy: []
  timestamp: '2023-03-04 23:54:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC254-D.test.cpp
  - test/ABC250-D.test.cpp
  - test/ABC177-E.test.cpp
  - test/ABC170-D.test.cpp
  - test/ABC292-C.test.cpp
documentation_of: src/math/linearSieve.hpp
layout: document
redirect_from:
- /library/src/math/linearSieve.hpp
- /library/src/math/linearSieve.hpp.html
title: src/math/linearSieve.hpp
---
