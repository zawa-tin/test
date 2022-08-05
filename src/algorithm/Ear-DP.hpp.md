---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Ear-DP.test.cpp
    title: test/Ear-DP.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Ear-DP.hpp\"\n\n#include <vector>\n#line 1\
    \ \"src/math/modint.hpp\"\nnamespace zawa {\n\n    template<long long mod>\n \
    \   class modint {\n    private:\n        long long x;\n\n    public:\n      \
    \  modint() : x(0) {}\n        \n        modint(long long x) : x((x % mod + mod)\
    \ % mod) {}\n\n        modint& operator+=(modint p) {\n            x += p.x;\n\
    \            if (x >= mod) x -= mod;\n            return *this;\n        }\n\n\
    \        modint& operator-=(modint p) {\n            x += mod - p.x;\n       \
    \     if (x >= mod) x -= mod;\n            return *this;\n        }\n\n      \
    \  modint& operator*=(modint p) {\n            x = (1LL * x * p.x % mod);\n  \
    \          return *this;\n        }\n\n        modint& operator/=(modint p) {\n\
    \            *this *= p.inv();\n            return *this;\n        }\n\n     \
    \   modint operator-() const {\n            return modint(-x);\n        }\n\n\
    \        modint operator+(const modint& p) const {\n            return modint(*this)\
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
    \n        return dp.back().back();\n    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include \"../math/modint.hpp\"\n\nnamespace\
    \ zawa {\n\n    using mint = zawa::modint<1000000007>;\n    \n    template<typename\
    \ T>\n    mint ear_dp(std::vector<T> as, std::vector<T> bs) {\n        std::vector\
    \ dp(as.size() + 1, std::vector<mint>(bs.size() + 1));\n        for (int i = 0\
    \ ; i < as.size() + 1 ; i++) dp[i][0] = 1;\n\n        for (int i = 1 ; i < as.size()\
    \ + 1 ; i++) {\n            for (int j = 1 ; j < bs.size() + 1 ; j++) {\n    \
    \            dp[i][j] += dp[i - 1][j];\n                if (as[i - 1] == bs[j\
    \ - 1]) dp[i][j] += dp[i][j - 1];\n            }\n        }\n\n        return\
    \ dp.back().back();\n    }\n\n} // namespace zawa\n"
  dependsOn:
  - src/math/modint.hpp
  isVerificationFile: false
  path: src/algorithm/Ear-DP.hpp
  requiredBy: []
  timestamp: '2022-08-06 00:49:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Ear-DP.test.cpp
documentation_of: src/algorithm/Ear-DP.hpp
layout: document
title: "Ear-DP (\u8033DP)"
---

## 概要
```
zawa::modint<1000000007> ear_dp(std::vector<T> as, std::vector<T> bs)
```


列asに対して、列bsと一致する部分列の取り出し方の数mod 1e9 + 7を求めます。


### 機能
modを変えたいなら実装の
`using mint = zawa::modint<1000000007>`を書き換えてください

### 計算量
asの長さを $N$ 、bsの長さを $M$ として $O(NM)$
