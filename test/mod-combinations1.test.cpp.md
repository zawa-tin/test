---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/mod-combinations.hpp
    title: "mod combinations (\u7D44\u307F\u5408\u308F\u305B\u306E\u6570 mod)"
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
    - https://yukicoder.me/submissions/826376
  bundledCode: "#line 1 \"test/mod-combinations1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/math/mod-combinations.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <long long mod>\nclass mod_conbinations {\nprivate:\n   \
    \ std::vector<long long> facs, inv_facs;\n\npublic:\n    mod_conbinations(std::size_t\
    \ n) : facs(2 * n + 1, 1LL), inv_facs(2 * n + 1) {\n        for (std::size_t i\
    \ = 0 ; i + 1 < facs.size() ; i++) {\n            facs[i + 1] = facs[i] * (i +\
    \ 1);\n            facs[i + 1] %= mod;\n        }\n        long long base = facs.back();\n\
    \        long long inv = 1LL;\n        long long p = mod - 2;\n        while (p\
    \ > 0) {\n            if (p & 1) {\n                inv *= base;\n           \
    \     inv %= mod;\n            }\n            base = (base * base) % mod;\n  \
    \          p >>= 1;\n        }\n        inv_facs.back() = inv;\n        for (int\
    \ i = (int)facs.size() - 1 ; i - 1 >= 0 ; i--) {\n            inv_facs[i - 1]\
    \ = inv_facs[i] * i;\n            inv_facs[i - 1] %= mod;\n        }\n    }\n\n\
    \    long long P(std::size_t n, std::size_t r) {\n        if (r > n) {\n     \
    \       return 0LL;\n        }\n        return (facs[n] * inv_facs[(n - r)]) %\
    \ mod;\n    }\n\n    long long C(std::size_t n, std::size_t r) {\n        if (r\
    \ > n) {\n            return 0LL;\n        }\n        return (P(n, r) * inv_facs[r])\
    \ % mod;\n    }\n\n    long long H(std::size_t n, std::size_t r) {\n        if\
    \ (n == 0 and r == 0) {\n            return 1LL;\n        }\n        if (r > n\
    \ + r - 1) {\n            return 0LL;\n        }\n        return C(n + r - 1,\
    \ r);\n    }\n};\n\n} // namespace zawa\n#line 4 \"test/mod-combinations1.test.cpp\"\
    \n\n#include <iostream>\n\n// int read() {\n//     int res = 0;\n//     while\
    \ (1) {\n//         char d; std::cin >> d;\n//         if ('0' <= d and d <= '9')\
    \ {\n//             res *= 10;\n//             res += (d - '0');\n//         }\n\
    //         else {\n//             break;\n//         }\n//     }\n//     return\
    \ res;\n// }\n\nint main() {\n    // zawa::mod_conbinations<1000000007LL> mc(1000000);\n\
    \    // int t; std::cin >> t;\n    // for (int _ = 0 ; _ < t ; _++) {\n    //\
    \     char c; std::cin >> c;\n    //     char __; std::cin >> __;\n    //    \
    \ int n = read();\n    //     int r = read();\n    //     if (c == 'C') {\n  \
    \  //         std::cout << mc.C(n, r) << std::endl;\n    //     }\n    //    \
    \ if (c == 'P') {\n    //         std::cout << mc.P(n, r) << std::endl;\n    //\
    \     }\n    //     if (c == 'H') {\n    //         std::cout << mc.H(n, r) <<\
    \ std::endl;\n    //     }\n    // } \n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * yukicoder No.117 \u7D44\u307F\u5408\u308F\u305B\u306E\u6570\n * https://yukicoder.me/submissions/826376\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/mod-combinations.hpp\"\n\n#include <iostream>\n\n//\
    \ int read() {\n//     int res = 0;\n//     while (1) {\n//         char d; std::cin\
    \ >> d;\n//         if ('0' <= d and d <= '9') {\n//             res *= 10;\n\
    //             res += (d - '0');\n//         }\n//         else {\n//        \
    \     break;\n//         }\n//     }\n//     return res;\n// }\n\nint main() {\n\
    \    // zawa::mod_conbinations<1000000007LL> mc(1000000);\n    // int t; std::cin\
    \ >> t;\n    // for (int _ = 0 ; _ < t ; _++) {\n    //     char c; std::cin >>\
    \ c;\n    //     char __; std::cin >> __;\n    //     int n = read();\n    //\
    \     int r = read();\n    //     if (c == 'C') {\n    //         std::cout <<\
    \ mc.C(n, r) << std::endl;\n    //     }\n    //     if (c == 'P') {\n    // \
    \        std::cout << mc.P(n, r) << std::endl;\n    //     }\n    //     if (c\
    \ == 'H') {\n    //         std::cout << mc.H(n, r) << std::endl;\n    //    \
    \ }\n    // } \n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n *\
    \ yukicoder No.117 \u7D44\u307F\u5408\u308F\u305B\u306E\u6570\n * https://yukicoder.me/submissions/826376\n\
    \ */\n"
  dependsOn:
  - src/math/mod-combinations.hpp
  isVerificationFile: true
  path: test/mod-combinations1.test.cpp
  requiredBy: []
  timestamp: '2022-12-17 09:41:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mod-combinations1.test.cpp
layout: document
redirect_from:
- /verify/test/mod-combinations1.test.cpp
- /verify/test/mod-combinations1.test.cpp.html
title: test/mod-combinations1.test.cpp
---
