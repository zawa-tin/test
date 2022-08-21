---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Eratosthenes-Sieve.hpp
    title: "Eratosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
  - icon: ':heavy_check_mark:'
    path: src/math/Mobius-Function.hpp
    title: "Mobius Function (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc206/submissions/34197189
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Mobius-Function.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#line 2 \"src/math/Mobius-Function.hpp\"\
    \n\n#line 4 \"src/math/Mobius-Function.hpp\"\n#include <vector>\n#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\
    \n\n#line 4 \"src/math/Eratosthenes-Sieve.hpp\"\n\nnamespace zawa {\n\n    class\
    \ Eratosthenes_Sieve {\n    private:\n        std::vector<bool> table;\n\n   \
    \ public:\n        Eratosthenes_Sieve(int n) : table(std::vector<bool>(n + 1,\
    \ true)) {\n            if (n >= 0) table[0] = false;\n            if (n >= 1)\
    \ table[1] = false;\n            \n            for (long long i = 2 ; i <= n ;\
    \ i++) {\n                if (!table[i]) continue;\n                for (long\
    \ long j = i * i ; j <= n ; j += i) {\n                    table[j] = false;\n\
    \                }\n            }\n        }\n\n        bool is_prime(int x) {\n\
    \            return 0 <= x and x < (int)table.size() and table[x];\n        }\n\
    \    };\n\n}// namespace zawa\n#line 6 \"src/math/Mobius-Function.hpp\"\n\nnamespace\
    \ zawa {\n\n    class Mobius_Function {\n    private:\n        std::vector<int_fast8_t>\
    \ table;\n\n    public:\n        Mobius_Function(int n) : table(std::vector<int_fast8_t>(n\
    \ + 1, 1)) {\n            Eratosthenes_Sieve siv(n);\n\n            for (int i\
    \ = 2 ; i <= n ; i++) {\n                if (!siv.is_prime(i)) continue;\n\n \
    \               for (long long j = i ; j <= n ; j += i) {\n                  \
    \  if (!(j % ((long long)i * i))) {\n                        table[j] = 0;\n \
    \                   }\n                    else {\n                        table[j]\
    \ *= -1;\n                    }\n                }\n            }\n        }\n\
    \n        int get(int x) {\n            return table[x];\n        }\n    };\n\n\
    }// namespace zawa\n#line 6 \"test/Mobius-Function.test.cpp\"\n\nint main() {\n\
    \    // https://atcoder.jp/contests/abc206/submissions/34197189\n    zawa::Mobius_Function\
    \ mob(10);\n    assert(mob.get(1) == 1);\n    assert(mob.get(2) == -1);\n    assert(mob.get(4)\
    \ == mob.get(9) and mob.get(8) == mob.get(9) and mob.get(8) == 0);\n    assert(mob.get(6)\
    \ == 1);\n\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include \"../src/math/Mobius-Function.hpp\"\
    \n\nint main() {\n    // https://atcoder.jp/contests/abc206/submissions/34197189\n\
    \    zawa::Mobius_Function mob(10);\n    assert(mob.get(1) == 1);\n    assert(mob.get(2)\
    \ == -1);\n    assert(mob.get(4) == mob.get(9) and mob.get(8) == mob.get(9) and\
    \ mob.get(8) == 0);\n    assert(mob.get(6) == 1);\n\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/Mobius-Function.hpp
  - src/math/Eratosthenes-Sieve.hpp
  isVerificationFile: true
  path: test/Mobius-Function.test.cpp
  requiredBy: []
  timestamp: '2022-08-21 19:26:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Mobius-Function.test.cpp
layout: document
redirect_from:
- /verify/test/Mobius-Function.test.cpp
- /verify/test/Mobius-Function.test.cpp.html
title: test/Mobius-Function.test.cpp
---
