---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Miller-Rabin.hpp
    title: "Miller-Rabin (\u7D20\u6570\u5224\u5B9A\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
    links:
    - https://algo-method.com/submissions/629135
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
  bundledCode: "#line 1 \"test/Miller-Rabin.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#line 2 \"src/math/Miller-Rabin.hpp\"\n#include <vector>\n\nnamespace zawa::impl\
    \ {\n\nlong long modpow(__int128_t a, __int128_t n, __int128_t mod) {\n    long\
    \ long res = 1;\n    a %= mod;\n    while (n) {\n        if (n & 1) {\n      \
    \      res = __int128_t(res) * a % mod;\n        }\n        n >>= 1;\n       \
    \ a = a * a % mod;\n    }\n    return res;\n}\n\nconst std::vector<long long>\
    \ small = { 2, 7, 61 };\nconst std::vector<long long> big = { 2, 3, 5, 7, 11,\
    \ 13, 17, 19, 23, 29, 31, 37 };\n\n} // namespace zawa::impl\n\nnamespace zawa\
    \ {\n\nbool miller_isprime(long long n) {\n    if (n == 1) {\n        return false;\n\
    \    }\n    if (n == 2) {\n        return true;\n    }\n    if (!(n & 1)) {\n\
    \        return false;\n    }\n    long long d = n - 1;\n    long long s = 0;\n\
    \    while (!(d & 1)) {\n        d >>= 1;\n        s++;\n    }\n    for (long\
    \ long a : (n < (1LL << 32) ? impl::small : impl::big)) {\n        if (a == n)\
    \ {\n            return true;\n        }\n        if (impl::modpow(a, d, n) ==\
    \ 1) {\n            continue;\n        }\n        bool ok = false;\n        for\
    \ (long long r = 0 ; r < s ; r++) {\n            if (impl::modpow(a, d * (1LL\
    \ << r), n) == n - 1) { // == -1\n                ok = true;\n               \
    \ break;\n            }\n        }\n        if (!ok) {\n            return false;\n\
    \        }\n    }\n    return true;\n}\n\n} // namespace zawa\n#line 4 \"test/Miller-Rabin.test.cpp\"\
    \n\n#include <iostream>\n#include <cassert>\n\nbool isprime(int x) {\n    for\
    \ (int i = 2 ; i * i <= x ; i++) {\n        if (x % i == 0) {\n            return\
    \ false;\n        }\n    }\n    return x != 1;\n}\n\nint main() {\n    // https://algo-method.com/submissions/629135\n\
    \    // \u3053\u308C\u306F10^18\u5236\u7D04\u306Everify\n    int n;\n    std::cin\
    \ >> n;\n    int ans = 0;\n    for (int _ = 0 ; _ < n ; _++) {\n        int k;\
    \ \n        std::cin >> k;\n        bool p = zawa::miller_isprime(k); \n     \
    \   assert(p == isprime(k));\n        ans += p;\n    }\n    std::cout << ans <<\
    \ std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C\"\
    \n\n#include \"../src/math/Miller-Rabin.hpp\"\n\n#include <iostream>\n#include\
    \ <cassert>\n\nbool isprime(int x) {\n    for (int i = 2 ; i * i <= x ; i++) {\n\
    \        if (x % i == 0) {\n            return false;\n        }\n    }\n    return\
    \ x != 1;\n}\n\nint main() {\n    // https://algo-method.com/submissions/629135\n\
    \    // \u3053\u308C\u306F10^18\u5236\u7D04\u306Everify\n    int n;\n    std::cin\
    \ >> n;\n    int ans = 0;\n    for (int _ = 0 ; _ < n ; _++) {\n        int k;\
    \ \n        std::cin >> k;\n        bool p = zawa::miller_isprime(k); \n     \
    \   assert(p == isprime(k));\n        ans += p;\n    }\n    std::cout << ans <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/math/Miller-Rabin.hpp
  isVerificationFile: true
  path: test/Miller-Rabin.test.cpp
  requiredBy: []
  timestamp: '2022-10-06 11:58:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Miller-Rabin.test.cpp
layout: document
redirect_from:
- /verify/test/Miller-Rabin.test.cpp
- /verify/test/Miller-Rabin.test.cpp.html
title: test/Miller-Rabin.test.cpp
---
