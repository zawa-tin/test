---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/gcd-convolution.hpp
    title: "gcd-convlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u30FB\u7D04\u6570\
      \u7CFB\u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
      )"
  - icon: ':heavy_check_mark:'
    path: src/math/mobius-function.hpp
    title: "mobius-function (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcd-convolution.test.cpp
    title: test/gcd-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mobius-function.test.cpp
    title: test/mobius-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/prime-sieve.test.cpp
    title: test/prime-sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/prime-sieve.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass prime_sieve {\nprivate:\n\tstd::vector<bool> sieve;\n\npublic:\n\
    \tprime_sieve() {}\n\tprime_sieve(std::size_t n) : sieve(n + 1, true) {\n\t\t\
    if (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t}\n\t\tif (n >= 1) {\n\t\t\tsieve[1]\
    \ = false;\n\t\t}\n\t\tfor (std::size_t i = 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i])\
    \ {\n\t\t\t\tfor (std::size_t j = i * i ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j]\
    \ = false;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\tbool operator[](std::size_t i) {\n\
    \t\treturn sieve[i];\n\t}\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\nclass prime_sieve\
    \ {\nprivate:\n\tstd::vector<bool> sieve;\n\npublic:\n\tprime_sieve() {}\n\tprime_sieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ i ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\tbool operator[](std::size_t i) {\n\t\treturn sieve[i];\n\t}\n};\n\n\
    }// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/prime-sieve.hpp
  requiredBy:
  - src/math/mobius-function.hpp
  - src/math/gcd-convolution.hpp
  timestamp: '2023-01-23 10:31:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mobius-function.test.cpp
  - test/gcd-convolution.test.cpp
  - test/prime-sieve.test.cpp
documentation_of: src/math/prime-sieve.hpp
layout: document
title: "prime-sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
---

## 概要

[エラトステネスの篩](https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9)アルゴリズムによって入力で与えられる非負整数 $n$ 以下の素数を列挙します。

## 機能

**コンストラクタ**

`zawa::prime_sieve()`
- デフォルトコンストラクタ、何もしない

`zawa::prime_sieve(std::size_t n)`
- $n$ を入力で与えます
- **計算量** : $O(n\log (\log n))$

**メンバ関数**

とくになし

**operator**

`bool [](std::size_t i)`:  `i` が素数かを判定します。
- テーブルへの参照はできません
- **計算量** : $O(1)$
