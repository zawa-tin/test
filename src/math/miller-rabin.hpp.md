---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/miller-rabin.test.cpp
    title: test/miller-rabin.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/miller-rabin.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa::impl {\n\nlong long modpow(__int128_t a, __int128_t b, long long mod)\
    \ {\n\tlong long res = 1LL;\n\ta %= mod;\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\
    \tres = ((__int128_t)res * a) % mod;\n\t\t}\n\t\ta = (a * a) % mod;\n\t\tb >>=\
    \ 1;\n\t}\n\treturn res;\n}\n\nstd::vector<long long> cond = { 2, 325, 9375, 28178,\
    \ 450775, 978504, 1795265022 };\n\n} // namespace zawa::impl\n\nnamespace zawa\
    \ {\n\nbool isprime(long long n) {\n\tif (n <= 1) {\n\t\treturn false;\n\t}\n\t\
    if (n == 2 or n == 3) {\n\t\treturn true;\n\t}\n\tif (!(n & 1)) {\n\t\treturn\
    \ false;\n\t}\n\tlong long s = 0LL, d = n - 1;\n\twhile (d % 2 == 0) {\n\t\ts++;\n\
    \t\td >>= 1;\n\t}\n\tfor (auto c : impl::cond) {\n\t\tif (c % n == 0) {\n\t\t\t\
    return true;\n\t\t}\n\t\tlong long x = impl::modpow(c, d, n);\n\t\tif (x != 1)\
    \ {\n\t\t\tlong long t = 0;\n\t\t\tfor ( ; t < s ; t++) {\n\t\t\t\tif (x == n\
    \ - 1) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tx = ((__int128_t)x * x) % n;\n\t\
    \t\t}\n\t\t\tif (t == s) {\n\t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ true;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa::impl {\n\nlong long\
    \ modpow(__int128_t a, __int128_t b, long long mod) {\n\tlong long res = 1LL;\n\
    \ta %= mod;\n\twhile (b) {\n\t\tif (b & 1) {\n\t\t\tres = ((__int128_t)res * a)\
    \ % mod;\n\t\t}\n\t\ta = (a * a) % mod;\n\t\tb >>= 1;\n\t}\n\treturn res;\n}\n\
    \nstd::vector<long long> cond = { 2, 325, 9375, 28178, 450775, 978504, 1795265022\
    \ };\n\n} // namespace zawa::impl\n\nnamespace zawa {\n\nbool isprime(long long\
    \ n) {\n\tif (n <= 1) {\n\t\treturn false;\n\t}\n\tif (n == 2 or n == 3) {\n\t\
    \treturn true;\n\t}\n\tif (!(n & 1)) {\n\t\treturn false;\n\t}\n\tlong long s\
    \ = 0LL, d = n - 1;\n\twhile (d % 2 == 0) {\n\t\ts++;\n\t\td >>= 1;\n\t}\n\tfor\
    \ (auto c : impl::cond) {\n\t\tif (c % n == 0) {\n\t\t\treturn true;\n\t\t}\n\t\
    \tlong long x = impl::modpow(c, d, n);\n\t\tif (x != 1) {\n\t\t\tlong long t =\
    \ 0;\n\t\t\tfor ( ; t < s ; t++) {\n\t\t\t\tif (x == n - 1) {\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t\tx = ((__int128_t)x * x) % n;\n\t\t\t}\n\t\t\tif (t == s) {\n\
    \t\t\t\treturn false;\n\t\t\t}\n\t\t}\n\t}\n\treturn true;\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/miller-rabin.hpp
  requiredBy: []
  timestamp: '2023-01-09 22:06:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/miller-rabin.test.cpp
documentation_of: src/math/miller-rabin.hpp
layout: document
title: "miller-rabin (\u7D20\u6570\u5224\u5B9A\u6CD5)"
---

## 概要
正整数`n`にが素数かどうかを判定する

##  機能
`bool isprime(long long n)`
- $n$ が素数かどうかを判定します
- **計算量** $O(\log ^ 2 n)$

## 計算量

## 参考

- [wikipedia-ja](https://ja.wikipedia.org/wiki/%E3%83%9F%E3%83%A9%E3%83%BC%E2%80%93%E3%83%A9%E3%83%93%E3%83%B3%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A%E6%B3%95)
- [wikipedia-en](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)
- [C++の実装で参考にしました](https://algo-method.com/tasks/513/editorial)
- [アルゴリズムの理解で参考にしました](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)
