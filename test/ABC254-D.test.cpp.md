---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/linear-sieve.hpp
    title: "linear-sieve (\u7DDA\u5F62\u7BE9\u30FB\u7D20\u56E0\u6570\u5206\u89E3/\u7D04\
      \u6570\u5217\u6319)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc254/submissions/38277309
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC254-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/linear-sieve.hpp\"\n\n#include <vector>\n#include <utility>\n\
    \nnamespace zawa {\n\nclass linear_sieve {\nprivate:\n\tstd::vector<int> divs;\n\
    \tstd::vector<int> primes;\n\npublic:\n\tlinear_sieve() {}\n\tlinear_sieve(std::size_t\
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
    }\n\n\tstd::vector<int> enumprime() {\n\t\treturn primes;\n\t}\n\n\tbool isprime(int\
    \ x) {\n\t\treturn (x != 0 and x != 1 and divs[x] == x);\n\t}\n\n\tint operator[](int\
    \ x) {\n\t\treturn divs[x];\n\t}\n};\n\n}\n#line 4 \"test/ABC254-D.test.cpp\"\n\
    \n#include <iostream>\n\nint main() {\n\t// int N; std::cin >> N;\n\t// zawa::linear_sieve\
    \ siv(N);\n\t// std::vector<int> dp(N + 1, 1);\n\t// for (int i = 2 ; i < N +\
    \ 1 ; i++) {\n\t// \tint lpf = siv[i];\n\t// \tdp[i] = dp[i / lpf];\n\t// \tif\
    \ (dp[i] % lpf == 0) {\n\t// \t\tdp[i] /= lpf;\n\t// \t}\n\t// \telse {\n\t//\
    \ \t\tdp[i] *= lpf;\n\t// \t}\n\t// }\n\t// std::vector bucket(N + 1, 0);\n\t\
    // for (int i = 1 ; i < N + 1 ; i++) {\n\t// \tbucket[dp[i]]++;\n\t// }\n\t//\
    \ long long ans = 0LL;\n\t// for (int i = 0 ; i < N + 1 ; i++) {\n\t// \tans +=\
    \ (long long)bucket[i] * bucket[i];\n\t// }\n\t// std::cout << ans << std::endl;\n\
    \t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner\
    \ Contest 254 - D Together Square\n * https://atcoder.jp/contests/abc254/submissions/38277309\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/linear-sieve.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\t// int N; std::cin >> N;\n\t// zawa::linear_sieve siv(N);\n\t// std::vector<int>\
    \ dp(N + 1, 1);\n\t// for (int i = 2 ; i < N + 1 ; i++) {\n\t// \tint lpf = siv[i];\n\
    \t// \tdp[i] = dp[i / lpf];\n\t// \tif (dp[i] % lpf == 0) {\n\t// \t\tdp[i] /=\
    \ lpf;\n\t// \t}\n\t// \telse {\n\t// \t\tdp[i] *= lpf;\n\t// \t}\n\t// }\n\t\
    // std::vector bucket(N + 1, 0);\n\t// for (int i = 1 ; i < N + 1 ; i++) {\n\t\
    // \tbucket[dp[i]]++;\n\t// }\n\t// long long ans = 0LL;\n\t// for (int i = 0\
    \ ; i < N + 1 ; i++) {\n\t// \tans += (long long)bucket[i] * bucket[i];\n\t//\
    \ }\n\t// std::cout << ans << std::endl;\n\t\n\tstd::cout << \"Hello World\" <<\
    \ std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 254 - D Together Square\n *\
    \ https://atcoder.jp/contests/abc254/submissions/38277309\n */\n"
  dependsOn:
  - src/math/linear-sieve.hpp
  isVerificationFile: true
  path: test/ABC254-D.test.cpp
  requiredBy: []
  timestamp: '2023-01-23 14:32:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC254-D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC254-D.test.cpp
- /verify/test/ABC254-D.test.cpp.html
title: test/ABC254-D.test.cpp
---
