---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/linearSieve.hpp
    title: src/math/linearSieve.hpp
  - icon: ':heavy_check_mark:'
    path: src/template/binary-search.hpp
    title: "binary-seach (\u6574\u6570\u4E8C\u5206\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc250/submissions/39448263
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC250-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/linearSieve.hpp\"\n\n#include <vector>\n#include <utility>\n\
    \nnamespace zawa {\n\nclass linearSieve {\nprivate:\n\tstd::vector<int> divs;\n\
    \tstd::vector<int> primes;\n\npublic:\n\tlinearSieve() {}\n\tlinearSieve(std::size_t\
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
    return divs[x];\n\t}\n};\n\n}\n#line 2 \"src/template/binary-search.hpp\"\n\n\
    #include <cmath>\n\nnamespace zawa {\n\ntemplate <class T, class F>\nT binary_search(T\
    \ ok, T ng, const F& f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok\
    \ + ng) >> 1);\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\t\
    ng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n#line 5 \"test/ABC250-D.test.cpp\"\
    \n\n#include <iostream>\n#line 8 \"test/ABC250-D.test.cpp\"\n#include <functional>\n\
    \nint main() {\n\t// std::vector primes = zawa::linearSieve(1000000).enumPrime();\n\
    \t// long long N; std::cin >> N;\n\t// std::size_t ans = 0;\n\t// for (std::size_t\
    \ i = 0 ; i < primes.size() ; i++) {\n\t// \tauto f = [&](int p) -> bool {\n\t\
    // \t\tlong long v = 1LL;\n\t// \t\tfor (int _ = 0 ; _ < 3 ; _++) {\n\t// \t\t\
    \tif (v > N) {\n\t// \t\t\t\treturn false;\n\t// \t\t\t}\n\t// \t\t\tv *= primes[p];\n\
    \t// \t\t}\n\t// \t\treturn v <= N / primes[i];\n\t// \t};\n\t// \tif (f(i) ==\
    \ false) {\n\t// \t\tbreak;\n\t// \t}\n\t// \tans += zawa::binary_search((int)i,\
    \ (int)primes.size() - 1, f) - i;\n\t// }\n\t// std::cout << ans << std::endl;\n\
    \t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner\
    \ Contest 250 - D 250-like Number\n * https://atcoder.jp/contests/abc250/submissions/39448263\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/linearSieve.hpp\"\n#include \"../src/template/binary-search.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n\nint main()\
    \ {\n\t// std::vector primes = zawa::linearSieve(1000000).enumPrime();\n\t// long\
    \ long N; std::cin >> N;\n\t// std::size_t ans = 0;\n\t// for (std::size_t i =\
    \ 0 ; i < primes.size() ; i++) {\n\t// \tauto f = [&](int p) -> bool {\n\t// \t\
    \tlong long v = 1LL;\n\t// \t\tfor (int _ = 0 ; _ < 3 ; _++) {\n\t// \t\t\tif\
    \ (v > N) {\n\t// \t\t\t\treturn false;\n\t// \t\t\t}\n\t// \t\t\tv *= primes[p];\n\
    \t// \t\t}\n\t// \t\treturn v <= N / primes[i];\n\t// \t};\n\t// \tif (f(i) ==\
    \ false) {\n\t// \t\tbreak;\n\t// \t}\n\t// \tans += zawa::binary_search((int)i,\
    \ (int)primes.size() - 1, f) - i;\n\t// }\n\t// std::cout << ans << std::endl;\n\
    \t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner\
    \ Contest 250 - D 250-like Number\n * https://atcoder.jp/contests/abc250/submissions/39448263\n\
    \ */\n"
  dependsOn:
  - src/math/linearSieve.hpp
  - src/template/binary-search.hpp
  isVerificationFile: true
  path: test/ABC250-D.test.cpp
  requiredBy: []
  timestamp: '2023-03-04 23:54:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC250-D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC250-D.test.cpp
- /verify/test/ABC250-D.test.cpp.html
title: test/ABC250-D.test.cpp
---
