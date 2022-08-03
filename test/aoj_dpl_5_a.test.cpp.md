---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
  bundledCode: "#line 1 \"test/aoj_dpl_5_a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n#include <iostream>\n\n#line 1 \"src/math/modint.hpp\"\nnamespace zawa {\n\n\
    \    template<long long mod>\n    class modint {\n    private:\n        long long\
    \ x;\n\n    public:\n        modint() : x(0) {}\n        \n        modint(long\
    \ long x) : x((x % mod + mod) % mod) {}\n\n        modint& operator+=(modint p)\
    \ {\n            x += p.x;\n            if (x >= mod) x -= mod;\n            return\
    \ *this;\n        }\n\n        modint& operator-=(modint p) {\n            x +=\
    \ mod - p.x;\n            if (x >= mod) x -= mod;\n            return *this;\n\
    \        }\n\n        modint& operator*=(modint p) {\n            x = (1LL * x\
    \ * p.x % mod);\n            return *this;\n        }\n\n        modint& operator/=(modint\
    \ p) {\n            *this *= p.inv();\n            return *this;\n        }\n\n\
    \        modint operator-() const {\n            return modint(-x);\n        }\n\
    \n        modint operator+(const modint& p) const {\n            return modint(*this)\
    \ += p;\n        }\n\n        modint operator-(const modint& p) const {\n    \
    \        return modint(*this) -= p;\n        }\n\n        modint operator*(const\
    \ modint& p) const {\n            return modint(*this) *= p;\n        }\n\n  \
    \      modint operator/(const modint& p) const {\n            return modint(*this)\
    \ /= p;\n        }\n\n        long long val() {\n            return x;\n     \
    \   }\n\n        modint pow(long long p) {\n            modint res(1), val(x);\n\
    \            while(p) {\n                if (p & 1) res *= val;\n            \
    \    val *= val;\n                p >>= 1;\n            }\n            return\
    \ res;\n        }\n\n        modint inv() {\n            return pow(mod - 2);\n\
    \        }\n    };\n\n}// namespace zawa\n#line 5 \"test/aoj_dpl_5_a.test.cpp\"\
    \n\nusing mint = zawa::modint<1000000007>;\n\nint main() {\n    int n, k;\n  \
    \  std::cin >> n >> k;\n    std::cout << mint(k).pow(n).val() << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n#include <iostream>\n\n#include \"../src/math/modint.hpp\"\n\nusing mint = zawa::modint<1000000007>;\n\
    \nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    std::cout << mint(k).pow(n).val()\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/aoj_dpl_5_a.test.cpp
  requiredBy: []
  timestamp: '2022-08-03 12:30:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_dpl_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_dpl_5_a.test.cpp
- /verify/test/aoj_dpl_5_a.test.cpp.html
title: test/aoj_dpl_5_a.test.cpp
---
