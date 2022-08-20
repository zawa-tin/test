---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/osa_k.hpp
    title: "osa_k (\u8907\u6570\u8981\u7D20\u306E\u7D04\u6570\u5217\u6319\u30FB\u7D20\
      \u56E0\u6570\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D
  bundledCode: "#line 1 \"test/osa_k.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include <iostream>\n#line 2 \"src/math/osa_k.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\n    class osa_k {\n    private:\n        std::vector<int>\
    \ factors;\n\n    public:\n        osa_k(int n) : factors(std::vector<int>(n +\
    \ 1)) {\n            if (n >= 1) factors[1] = 1;\n\n            for (long long\
    \ i = 2 ; i <= n ; i++) {\n                if (factors[i]) continue;\n       \
    \         factors[i] = i;\n\n                for (long long j = i * i ; j <= n\
    \ ; j += i) {\n                    if (!factors[j]) {\n                      \
    \  factors[j] = i;\n                    }\n                }\n            }\n\
    \        }\n\n        std::vector<std::pair<int, int>> factorize(int x) {\n  \
    \          std::vector<std::pair<int, int>> res;\n            if (x <= 0 or x\
    \ >= (int)factors.size()) {\n                return res;\n            }\n\n  \
    \          while (x > 1) {\n                res.emplace_back(factors[x], 0);\n\
    \                while (factors[x] == res.back().first) {\n                  \
    \  x /= res.back().first;\n                    res.back().second++;\n        \
    \        }\n            }\n\n            return res;\n        }\n\n        std::vector<int>\
    \ divisor(int x) {\n            std::vector<int> res;\n\n            if (x <=\
    \ 0 or x > (int)factors.size()) {\n                return res;\n            }\n\
    \n            auto facs = factorize(x);\n\n            res.emplace_back(1);\n\n\
    \            for (auto [p, e] : facs) {\n                int sz = (int)res.size();\n\
    \                for (int i = 0 ; i < sz ; i++) {\n                    int v =\
    \ 1;\n                    for (int j = 0 ; j < e ; j++) {\n                  \
    \      v *= p;\n                        res.emplace_back(res[i] * v);\n      \
    \              }\n                }\n            }\n\n            return res;\n\
    \        }\n    };\n\n}// namespace zawa\n#line 5 \"test/osa_k.test.cpp\"\n\n\
    int main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n    zawa::osa_k\
    \ osa(c);\n    int ans = 0;\n    for (auto d : osa.divisor(c)) {\n        ans\
    \ += (a <= d and d <= b);\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/3/ITP1_3_D\"\
    \n\n#include <iostream>\n#include \"../src/math/osa_k.hpp\"\n\nint main() {\n\
    \    int a, b, c;\n    std::cin >> a >> b >> c;\n    zawa::osa_k osa(c);\n   \
    \ int ans = 0;\n    for (auto d : osa.divisor(c)) {\n        ans += (a <= d and\
    \ d <= b);\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/math/osa_k.hpp
  isVerificationFile: true
  path: test/osa_k.test.cpp
  requiredBy: []
  timestamp: '2022-08-20 22:48:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/osa_k.test.cpp
layout: document
redirect_from:
- /verify/test/osa_k.test.cpp
- /verify/test/osa_k.test.cpp.html
title: test/osa_k.test.cpp
---
