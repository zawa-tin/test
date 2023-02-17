---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC170-D.test.cpp
    title: test/ABC170-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC177-E.test.cpp
    title: test/ABC177-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC250.test.cpp
    title: test/ABC250.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC254-D.test.cpp
    title: test/ABC254-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/linear-sieve.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n\nnamespace zawa {\n\nclass linear_sieve {\nprivate:\n\tstd::vector<int>\
    \ divs;\n\tstd::vector<int> primes;\n\npublic:\n\tlinear_sieve() {}\n\tlinear_sieve(std::size_t\
    \ n) : divs(n + 1, 1) {\n\t\tfor (std::size_t i = 2 ; i < n + 1 ; i++) {\n\t\t\
    \tif (divs[i] == 1) {\n\t\t\t\tdivs[i] = i;\n\t\t\t\tprimes.push_back((int)i);\n\
    \t\t\t}\n\t\t\tfor (const auto& p : primes) {\n\t\t\t\tif (p * i > n or p > divs[i])\
    \ {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tdivs[p * i] = p;\n\t\t\t}\n\t\t}\n\t\
    }\n\n\tstd::vector<std::pair<int, int>> factorize(int x) {\n\t\tstd::vector res(0,\
    \ std::pair(0, 0));\n\t\twhile (x > 1) {\n\t\t\tres.emplace_back(divs[x], 0);\n\
    \t\t\twhile (divs[x] == res.back().first) {\n\t\t\t\tx /= divs[x];\n\t\t\t\tres.back().second++;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int x) {\n\t\
    \tstd::vector res(1, 1);\n\t\tfor (const auto& [p, q] : factorize(x)) {\n\t\t\t\
    std::size_t now = res.size();\n\t\t\tfor (std::size_t i = 0 ; i < now ; i++) {\n\
    \t\t\t\tint mul = p;\n\t\t\t\tfor (int _ = 0 ; _ < q ; _++) {\n\t\t\t\t\tres.emplace_back(res[i]\
    \ * mul);\n\t\t\t\t\tmul *= p;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\tstd::vector<int> enumprime() {\n\t\treturn primes;\n\t}\n\n\tbool isprime(int\
    \ x) {\n\t\treturn (x != 0 and x != 1 and divs[x] == x);\n\t}\n\n\tint operator[](int\
    \ x) {\n\t\treturn divs[x];\n\t}\n};\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n\nnamespace zawa {\n\
    \nclass linear_sieve {\nprivate:\n\tstd::vector<int> divs;\n\tstd::vector<int>\
    \ primes;\n\npublic:\n\tlinear_sieve() {}\n\tlinear_sieve(std::size_t n) : divs(n\
    \ + 1, 1) {\n\t\tfor (std::size_t i = 2 ; i < n + 1 ; i++) {\n\t\t\tif (divs[i]\
    \ == 1) {\n\t\t\t\tdivs[i] = i;\n\t\t\t\tprimes.push_back((int)i);\n\t\t\t}\n\t\
    \t\tfor (const auto& p : primes) {\n\t\t\t\tif (p * i > n or p > divs[i]) {\n\t\
    \t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t\tdivs[p * i] = p;\n\t\t\t}\n\t\t}\n\t}\n\n\t\
    std::vector<std::pair<int, int>> factorize(int x) {\n\t\tstd::vector res(0, std::pair(0,\
    \ 0));\n\t\twhile (x > 1) {\n\t\t\tres.emplace_back(divs[x], 0);\n\t\t\twhile\
    \ (divs[x] == res.back().first) {\n\t\t\t\tx /= divs[x];\n\t\t\t\tres.back().second++;\n\
    \t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<int> divisor(int x) {\n\t\
    \tstd::vector res(1, 1);\n\t\tfor (const auto& [p, q] : factorize(x)) {\n\t\t\t\
    std::size_t now = res.size();\n\t\t\tfor (std::size_t i = 0 ; i < now ; i++) {\n\
    \t\t\t\tint mul = p;\n\t\t\t\tfor (int _ = 0 ; _ < q ; _++) {\n\t\t\t\t\tres.emplace_back(res[i]\
    \ * mul);\n\t\t\t\t\tmul *= p;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t\
    }\n\n\tstd::vector<int> enumprime() {\n\t\treturn primes;\n\t}\n\n\tbool isprime(int\
    \ x) {\n\t\treturn (x != 0 and x != 1 and divs[x] == x);\n\t}\n\n\tint operator[](int\
    \ x) {\n\t\treturn divs[x];\n\t}\n};\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/linear-sieve.hpp
  requiredBy: []
  timestamp: '2023-01-23 14:32:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC254-D.test.cpp
  - test/ABC177-E.test.cpp
  - test/ABC170-D.test.cpp
  - test/ABC250.test.cpp
documentation_of: src/math/linear-sieve.hpp
layout: document
title: "linear-sieve (\u7DDA\u5F62\u7BE9\u30FB\u7D20\u56E0\u6570\u5206\u89E3/\u7D04\
  \u6570\u5217\u6319)"
---

## 概要

線形篩のアルゴリズムにより、 入力で与えた非負整数 $n$ 以下の最小素因数を列挙します。

素因数分解や約数列挙のクエリがたくさん飛んでくる場合や、素因数で小さいサイズにしていくタイプの動的計画法で利用できたりします。

## 機能

**コンストラクタ**

`zawa::linear_sieve()`
- デフォルトコンストラクタ

`zawa::linear_sieve(std::size_t n)`
- 入力に $n$ を与えて、 $n$ 以下の最小素因数を列挙する。
- **計算量** : $O(n)$

**メンバ関数**

`std::vector<std::pair<int, int>> factorize(int x)`
- $x$ を素因数分解する。
- `(first, second) = 素因数、次数`である
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(\log x)$ (多分 <- カス!)

`std::vector<int> divisor(int x)`
- $x$ の約数を列挙する
	- **昇順に並んでいないことに注意！**
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(\log^2 x)$ (多分 <- カス!)
	- 実装がカス！なのでlogが一個多めについてます。多分(カス！)

`std::vector<int> enumprime()`
- $n$ 以下の素数を昇順に列挙したものを返します。

`bool isprime(int x)`
- $x$ が素数かを判定します。
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(1)$

**operator**

`int [](int x)`
- $x$ の最小素因数を返します。
- **制約** : $1\ \le\ x\ \le\ n$
- **計算量** : $O(1)$


## 参考

[線形篩](https://37zigen.com/linear-sieve/)
