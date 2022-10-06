---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Miller-Rabin.test.cpp
    title: test/Miller-Rabin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Miller-Rabin.hpp\"\n#include <vector>\n\nnamespace\
    \ zawa::impl {\n\nlong long modpow(__int128_t a, __int128_t n, __int128_t mod)\
    \ {\n    long long res = 1;\n    a %= mod;\n    while (n) {\n        if (n & 1)\
    \ {\n            res = __int128_t(res) * a % mod;\n        }\n        n >>= 1;\n\
    \        a = a * a % mod;\n    }\n    return res;\n}\n\nconst std::vector<long\
    \ long> small = { 2, 7, 61 };\nconst std::vector<long long> big = { 2, 3, 5, 7,\
    \ 11, 13, 17, 19, 23, 29, 31, 37 };\n\n} // namespace zawa::impl\n\nnamespace\
    \ zawa {\n\nbool miller_isprime(long long n) {\n    if (n == 1) {\n        return\
    \ false;\n    }\n    if (n == 2) {\n        return true;\n    }\n    if (!(n &\
    \ 1)) {\n        return false;\n    }\n    long long d = n - 1;\n    long long\
    \ s = 0;\n    while (!(d & 1)) {\n        d >>= 1;\n        s++;\n    }\n    for\
    \ (long long a : (n < (1LL << 32) ? impl::small : impl::big)) {\n        if (a\
    \ == n) {\n            return true;\n        }\n        if (impl::modpow(a, d,\
    \ n) == 1) {\n            continue;\n        }\n        bool ok = false;\n   \
    \     for (long long r = 0 ; r < s ; r++) {\n            if (impl::modpow(a, d\
    \ * (1LL << r), n) == n - 1) { // == -1\n                ok = true;\n        \
    \        break;\n            }\n        }\n        if (!ok) {\n            return\
    \ false;\n        }\n    }\n    return true;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n#include <vector>\n\nnamespace zawa::impl {\n\nlong long modpow(__int128_t\
    \ a, __int128_t n, __int128_t mod) {\n    long long res = 1;\n    a %= mod;\n\
    \    while (n) {\n        if (n & 1) {\n            res = __int128_t(res) * a\
    \ % mod;\n        }\n        n >>= 1;\n        a = a * a % mod;\n    }\n    return\
    \ res;\n}\n\nconst std::vector<long long> small = { 2, 7, 61 };\nconst std::vector<long\
    \ long> big = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };\n\n} // namespace\
    \ zawa::impl\n\nnamespace zawa {\n\nbool miller_isprime(long long n) {\n    if\
    \ (n == 1) {\n        return false;\n    }\n    if (n == 2) {\n        return\
    \ true;\n    }\n    if (!(n & 1)) {\n        return false;\n    }\n    long long\
    \ d = n - 1;\n    long long s = 0;\n    while (!(d & 1)) {\n        d >>= 1;\n\
    \        s++;\n    }\n    for (long long a : (n < (1LL << 32) ? impl::small :\
    \ impl::big)) {\n        if (a == n) {\n            return true;\n        }\n\
    \        if (impl::modpow(a, d, n) == 1) {\n            continue;\n        }\n\
    \        bool ok = false;\n        for (long long r = 0 ; r < s ; r++) {\n   \
    \         if (impl::modpow(a, d * (1LL << r), n) == n - 1) { // == -1\n      \
    \          ok = true;\n                break;\n            }\n        }\n    \
    \    if (!ok) {\n            return false;\n        }\n    }\n    return true;\n\
    }\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Miller-Rabin.hpp
  requiredBy: []
  timestamp: '2022-10-06 11:58:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Miller-Rabin.test.cpp
documentation_of: src/math/Miller-Rabin.hpp
layout: document
title: "Miller-Rabin (\u7D20\u6570\u5224\u5B9A\u6CD5)"
---

## 概要
```
miller_isprime(long long n)
```
正整数`n`にが素数かどうかを判定する

##  機能

- 第一引数に素数かどうか判定したいものを入れてください

## 計算量

$O(klog^3 n)$

- `n`が32bit整数だったら`k = 3`、そうでないなら`k = 12`
	- この言い方は多分正しくない・・・・

- 実際は下からmodpowを見ていくことでlogを一つ落とすことが可能
	- TODO: 実装

## 参考

- [wikipedia-ja](https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95)
- [wikipedia-en](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
- [C++の実装で参考にしました](https://joisino.hatenablog.com/entry/2017/08/03/210000)
- [アルゴリズムの理解で参考にしました](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)
