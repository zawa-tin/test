---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/prime-sieve.hpp
    title: "prime-sieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mobius-function.test.cpp
    title: test/mobius-function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/mobius-function.hpp\"\n\n#line 2 \"src/math/prime-sieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass prime_sieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprime_sieve() {}\n\tprime_sieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ i ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\tbool operator[](std::size_t i) {\n\t\treturn sieve[i];\n\t}\n};\n\n\
    }// namespace zawa\n#line 4 \"src/math/mobius-function.hpp\"\n\n#line 6 \"src/math/mobius-function.hpp\"\
    \n\nnamespace zawa {\n\nclass mobius_function {\nprivate:\n\tstd::vector<int>\
    \ table;\n\npublic:\n\tmobius_function() {}\n\tmobius_function(std::size_t n)\
    \ : table(std::vector(n + 1, 1)) {\n\t\tprime_sieve siv(n);\n\t\tfor (std::size_t\
    \ i = 2 ; i <= n ; i++) {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i\
    \ ; j <= n ; j += i) {\n\t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j]\
    \ = 0;\n\t\t\t\t\t}\n\t\t\t\t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tint operator[](int i) {\n\t\treturn table[i];\n\
    \t}\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include \"./prime-sieve.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass mobius_function {\nprivate:\n\tstd::vector<int> table;\n\npublic:\n\
    \tmobius_function() {}\n\tmobius_function(std::size_t n) : table(std::vector(n\
    \ + 1, 1)) {\n\t\tprime_sieve siv(n);\n\t\tfor (std::size_t i = 2 ; i <= n ; i++)\
    \ {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i ; j <= n ; j += i) {\n\
    \t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j] = 0;\n\t\t\t\t\t}\n\t\t\t\
    \t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tint operator[](int i) {\n\t\treturn table[i];\n\t}\n};\n\n}// namespace\
    \ zawa\n"
  dependsOn:
  - src/math/prime-sieve.hpp
  isVerificationFile: false
  path: src/math/mobius-function.hpp
  requiredBy: []
  timestamp: '2023-01-23 11:44:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mobius-function.test.cpp
documentation_of: src/math/mobius-function.hpp
layout: document
title: "mobius-function (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570)"
---

## 概要

入力で与える非負整数 $n$ 以下の[メビウス関数](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0)値を列挙します。

メビウス関数 $\mu(i)$ とは以下で定義されます。( $i > 0$ )

- $i$ が平方数( $k^2$ で表される数) で割り切れるなら 0
- $i$ が異なる $k$ 個の素数の積表せるなら $(-1)^k$
- $i$ が1なら $1$

約数系で包除原理をする時に、この関数の値が出現する。

## 機能

**コンストラクタ**

`zawa::mobius_function()`
- デフォルトコンストラクタ、なにもしない

`zawa::mobius_function(std::size_t n)`
- `n` 以下のメビウス関数値を列挙する
- **計算量**: $O(n\log (\log n))$

**operator**

`int [](int i)`
- $\mu(i)$ を返します
- **計算量** : $O(1)$

## 参考

[# エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
