---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Eratosthenes-Sieve.hpp
    title: "Etatosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
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
  bundledCode: "#line 1 \"test/Eratosthenes-Sieve.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\n\n#include\
    \ <vector>\n\nnamespace zawa {\n\n    class Eratosthenes_Sieve {\n    private:\n\
    \        std::vector<bool> table;\n\n    public:\n        Eratosthenes_Sieve(int\
    \ n) : table(std::vector<bool>(n + 1, true)) {\n            if (n >= 0) table[0]\
    \ = false;\n            if (n >= 1) table[1] = false;\n            \n        \
    \    for (long long i = 2 ; i <= n ; i++) {\n                if (!table[i]) continue;\n\
    \                for (long long j = i * i ; j <= n ; j += i) {\n             \
    \       table[j] = false;\n                }\n            }\n        }\n\n   \
    \     bool is_prime(int x) {\n            return 0 <= x and x < (int)table.size()\
    \ and table[x];\n        }\n    };\n\n}// namespace zawa\n#line 5 \"test/Eratosthenes-Sieve.test.cpp\"\
    \n\nconst int size = 100000000;\n\nint main() {\n    zawa::Eratosthenes_Sieve\
    \ siv(size);\n    int n;\n    std::cin >> n;\n    int ans = 0;\n    for (int _\
    \ = 0 ; _ < n ; _++) {\n        int a;\n        std::cin >> a;\n        ans +=\
    \ siv.is_prime(a);\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include <iostream>\n#include \"../src/math/Eratosthenes-Sieve.hpp\"\n\nconst\
    \ int size = 100000000;\n\nint main() {\n    zawa::Eratosthenes_Sieve siv(size);\n\
    \    int n;\n    std::cin >> n;\n    int ans = 0;\n    for (int _ = 0 ; _ < n\
    \ ; _++) {\n        int a;\n        std::cin >> a;\n        ans += siv.is_prime(a);\n\
    \    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/math/Eratosthenes-Sieve.hpp
  isVerificationFile: true
  path: test/Eratosthenes-Sieve.test.cpp
  requiredBy: []
  timestamp: '2022-08-20 16:09:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Eratosthenes-Sieve.test.cpp
layout: document
redirect_from:
- /verify/test/Eratosthenes-Sieve.test.cpp
- /verify/test/Eratosthenes-Sieve.test.cpp.html
title: test/Eratosthenes-Sieve.test.cpp
---
