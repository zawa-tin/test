---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Binary-Coeff-Mod.hpp
    title: "Binary-Coeff (\u4E8C\u9805\u4FC2\u6570 Mod)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc262/submissions/36149562
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Binary-Coeff.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/Binary-Coeff-Mod.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <long long mod>\nclass Binary_Coeff {\nprivate:\n    std::vector<long\
    \ long> factorial;\n    std::vector<long long> inversion;\n    std::vector<long\
    \ long> inv_factorial;\n\npublic:\n    Binary_Coeff(std::size_t size) \n     \
    \   : factorial(size + 1, 1)\n        , inversion(size + 1, 1)\n        , inv_factorial(size\
    \ + 1, 1) {\n        for (int i = 1 ; i <= size ; i++) {\n            factorial[i]\
    \ = factorial[i - 1] * i % mod;\n        }\n        for (int i = 2 ; i <= size\
    \ ; i++) {\n            inversion[i] = (mod - mod / i) * inversion[mod % i] %\
    \ mod;\n        }\n        for (int i = 1 ; i <= size ; i++) {\n            inv_factorial[i]\
    \ = inv_factorial[i - 1] * inversion[i] % mod;\n        }\n    }\n\n    long long\
    \ query(int n, int r, bool check = true) {\n        if (check) {\n           \
    \ if (n < 0 or n - r < 0 or r < 0) {\n                return -1LL;\n         \
    \   }\n            if (n >= (int)factorial.size() or r >= (int)factorial.size()\
    \ or (n - r) >= (int)factorial.size()) {\n                return -1LL;\n     \
    \       }\n        }\n        return (((factorial[n] * inv_factorial[n - r]) %\
    \ mod) * inv_factorial[r]) % mod;\n    }\n};\n\n} // namespace zawa\n#line 4 \"\
    test/Binary-Coeff.test.cpp\"\n\n#include <iostream>\n\nint main() {\n    // int\
    \ n, m, k; std::cin >> n >> m >> k;\n    // std::vector digs(n, 0);\n    // for\
    \ (int _ = 0 ; _ < m ; _++) {\n    //     int u, v; std::cin >> u >> v;\n    //\
    \     digs[u - 1]++;\n    //     digs[v - 1]++;\n    // }\n    // int odd = 0,\
    \ even = 0;\n    // for (auto dig : digs) {\n    //     (dig & 1 ? odd : even)++;\n\
    \    // }\n    // const long long mod = 998244353;\n    // zawa::Binary_Coeff<mod>\
    \ bc(n);\n    // long long ans = 0;\n    // for (int i = 0 ; i <= odd ; i += 2)\
    \ {\n    //     if (!(0 <= k - i and k - i <= even)) {\n    //         continue;\n\
    \    //     }\n    //     long long val = bc.query(odd, i) * bc.query(even, k\
    \ - i);\n    //     ans += val;\n    //     ans = (ans + mod) % mod;\n    // }\n\
    \    // std::cout << ans << std::endl;\n\n    std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n\n/*\n * AtCoder Biginner Contest 262-E Red and Blue Graph\n\
    \ * https://atcoder.jp/contests/abc262/submissions/36149562\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/Binary-Coeff-Mod.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    // int n, m, k; std::cin >> n >> m >> k;\n    // std::vector digs(n,\
    \ 0);\n    // for (int _ = 0 ; _ < m ; _++) {\n    //     int u, v; std::cin >>\
    \ u >> v;\n    //     digs[u - 1]++;\n    //     digs[v - 1]++;\n    // }\n  \
    \  // int odd = 0, even = 0;\n    // for (auto dig : digs) {\n    //     (dig\
    \ & 1 ? odd : even)++;\n    // }\n    // const long long mod = 998244353;\n  \
    \  // zawa::Binary_Coeff<mod> bc(n);\n    // long long ans = 0;\n    // for (int\
    \ i = 0 ; i <= odd ; i += 2) {\n    //     if (!(0 <= k - i and k - i <= even))\
    \ {\n    //         continue;\n    //     }\n    //     long long val = bc.query(odd,\
    \ i) * bc.query(even, k - i);\n    //     ans += val;\n    //     ans = (ans +\
    \ mod) % mod;\n    // }\n    // std::cout << ans << std::endl;\n\n    std::cout\
    \ << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Biginner Contest 262-E\
    \ Red and Blue Graph\n * https://atcoder.jp/contests/abc262/submissions/36149562\n\
    \ */\n"
  dependsOn:
  - src/math/Binary-Coeff-Mod.hpp
  isVerificationFile: true
  path: test/Binary-Coeff.test.cpp
  requiredBy: []
  timestamp: '2022-11-02 12:58:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Binary-Coeff.test.cpp
layout: document
redirect_from:
- /verify/test/Binary-Coeff.test.cpp
- /verify/test/Binary-Coeff.test.cpp.html
title: test/Binary-Coeff.test.cpp
---
