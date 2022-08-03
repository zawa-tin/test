---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_dpl_5_a.test.cpp
    title: test/aoj_dpl_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/math/modint.hpp\"\nnamespace zawa {\n\n    template<long\
    \ long mod>\n    class modint {\n    private:\n        long long x;\n\n    public:\n\
    \        modint() : x(0) {}\n        \n        modint(long long x) : x((x % mod\
    \ + mod) % mod) {}\n\n        modint& operator+=(modint p) {\n            x +=\
    \ p.x;\n            if (x >= mod) x -= mod;\n            return *this;\n     \
    \   }\n\n        modint& operator-=(modint p) {\n            x += mod - p.x;\n\
    \            if (x >= mod) x -= mod;\n            return *this;\n        }\n\n\
    \        modint& operator*=(modint p) {\n            x = (1LL * x * p.x % mod);\n\
    \            return *this;\n        }\n\n        modint& operator/=(modint p)\
    \ {\n            *this *= p.inv();\n            return *this;\n        }\n\n \
    \       modint operator-() const {\n            return modint(-x);\n        }\n\
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
    \        }\n    };\n\n}// namespace zawa\n"
  code: "namespace zawa {\n\n    template<long long mod>\n    class modint {\n   \
    \ private:\n        long long x;\n\n    public:\n        modint() : x(0) {}\n\
    \        \n        modint(long long x) : x((x % mod + mod) % mod) {}\n\n     \
    \   modint& operator+=(modint p) {\n            x += p.x;\n            if (x >=\
    \ mod) x -= mod;\n            return *this;\n        }\n\n        modint& operator-=(modint\
    \ p) {\n            x += mod - p.x;\n            if (x >= mod) x -= mod;\n   \
    \         return *this;\n        }\n\n        modint& operator*=(modint p) {\n\
    \            x = (1LL * x * p.x % mod);\n            return *this;\n        }\n\
    \n        modint& operator/=(modint p) {\n            *this *= p.inv();\n    \
    \        return *this;\n        }\n\n        modint operator-() const {\n    \
    \        return modint(-x);\n        }\n\n        modint operator+(const modint&\
    \ p) const {\n            return modint(*this) += p;\n        }\n\n        modint\
    \ operator-(const modint& p) const {\n            return modint(*this) -= p;\n\
    \        }\n\n        modint operator*(const modint& p) const {\n            return\
    \ modint(*this) *= p;\n        }\n\n        modint operator/(const modint& p)\
    \ const {\n            return modint(*this) /= p;\n        }\n\n        long long\
    \ val() {\n            return x;\n        }\n\n        modint pow(long long p)\
    \ {\n            modint res(1), val(x);\n            while(p) {\n            \
    \    if (p & 1) res *= val;\n                val *= val;\n                p >>=\
    \ 1;\n            }\n            return res;\n        }\n\n        modint inv()\
    \ {\n            return pow(mod - 2);\n        }\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/modint.hpp
  requiredBy: []
  timestamp: '2022-08-03 12:30:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_dpl_5_a.test.cpp
documentation_of: src/math/modint.hpp
layout: document
title: modint
---

## 概要
```
modint(int x)
```
素数で割った余りを取り続ける

### 機能
* `using mint = modint<mod>;`とすると便利です
* modは必ず素数を入れるようにしてください
* `コンストラクタ`: 引数をとらないと、0が代入されます
* 四則演算、累乗に対応しています(TODO: 対数、平方剰余)


### 計算量
* たしひきかけが定数、わりが$O(logmod)$
