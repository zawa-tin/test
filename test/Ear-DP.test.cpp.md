---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Ear-DP.hpp
    title: "Ear-DP (\u8033DP)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc211/submissions/33787349
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Ear-DP.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <string>\n#line 2 \"src/algorithm/Ear-DP.hpp\"\
    \n\n#include <vector>\n#line 1 \"src/math/modint.hpp\"\nnamespace zawa {\n\n \
    \   template<long long mod>\n    class modint {\n    private:\n        long long\
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
    \        }\n    };\n\n}// namespace zawa\n#line 5 \"src/algorithm/Ear-DP.hpp\"\
    \n\nnamespace zawa {\n\n    using mint = zawa::modint<1000000007>;\n    \n   \
    \ template<typename T>\n    mint ear_dp(std::vector<T> as, std::vector<T> bs)\
    \ {\n        std::vector dp(as.size() + 1, std::vector<mint>(bs.size() + 1));\n\
    \        for (int i = 0 ; i < as.size() + 1 ; i++) dp[i][0] = 1;\n\n        for\
    \ (int i = 1 ; i < as.size() + 1 ; i++) {\n            for (int j = 1 ; j < bs.size()\
    \ + 1 ; j++) {\n                dp[i][j] += dp[i - 1][j];\n                if\
    \ (as[i - 1] == bs[j - 1]) dp[i][j] += dp[i][j - 1];\n            }\n        }\n\
    \n        return dp.back().back();\n    }\n\n} // namespace zawa\n#line 6 \"test/Ear-DP.test.cpp\"\
    \n\nint main() {\n    // https://atcoder.jp/contests/abc211/submissions/33787349\n\
    \    // std::string s;\n    // std::cin >> s;\n    // std::vector<char> as(s.size());\n\
    \    // for (int i = 0 ; i < s.size() ; i++) as[i] = s[i];\n    // std::vector<char>\
    \ bs = {'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};\n    // \n    // std::cout <<\
    \ (zawa::ear_dp(as, bs)).val() << std::endl;\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n#include <string>\n#include \"../src/algorithm/Ear-DP.hpp\"\
    \n\nint main() {\n    // https://atcoder.jp/contests/abc211/submissions/33787349\n\
    \    // std::string s;\n    // std::cin >> s;\n    // std::vector<char> as(s.size());\n\
    \    // for (int i = 0 ; i < s.size() ; i++) as[i] = s[i];\n    // std::vector<char>\
    \ bs = {'c', 'h', 'o', 'k', 'u', 'd', 'a', 'i'};\n    // \n    // std::cout <<\
    \ (zawa::ear_dp(as, bs)).val() << std::endl;\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Ear-DP.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/Ear-DP.test.cpp
  requiredBy: []
  timestamp: '2022-08-06 00:49:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Ear-DP.test.cpp
layout: document
redirect_from:
- /verify/test/Ear-DP.test.cpp
- /verify/test/Ear-DP.test.cpp.html
title: test/Ear-DP.test.cpp
---
