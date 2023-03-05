---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/primeSieve.hpp
    title: "primeSieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mobiusFunction.test.cpp
    title: test/mobiusFunction.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/mobiusFunction.hpp\"\n\n#line 2 \"src/math/primeSieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass primeSieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprimeSieve() {}\n\tprimeSieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline bool operator[](std::size_t i) const {\n\t\treturn sieve[i];\n\
    \t}\n\n\tinline std::size_t size() const {\n\t\treturn sieve.size();\n\t}\n};\n\
    \n}// namespace zawa\n#line 4 \"src/math/mobiusFunction.hpp\"\n\n#line 6 \"src/math/mobiusFunction.hpp\"\
    \n\nnamespace zawa {\n\nclass mobiusFunction {\nprivate:\n\tstd::vector<int> table;\n\
    \npublic:\n\tmobiusFunction() {}\n\tmobiusFunction(std::size_t n) : table(std::vector(n\
    \ + 1, 1)) {\n\t\tprimeSieve siv(n);\n\t\tfor (std::size_t i = 2 ; i <= n ; i++)\
    \ {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i ; j <= n ; j += i) {\n\
    \t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j] = 0;\n\t\t\t\t\t}\n\t\t\t\
    \t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline int operator[](int i) const {\n\t\treturn table[i];\n\t}\n\
    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include \"./primeSieve.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass mobiusFunction {\nprivate:\n\tstd::vector<int> table;\n\npublic:\n\
    \tmobiusFunction() {}\n\tmobiusFunction(std::size_t n) : table(std::vector(n +\
    \ 1, 1)) {\n\t\tprimeSieve siv(n);\n\t\tfor (std::size_t i = 2 ; i <= n ; i++)\
    \ {\n\t\t\tif (siv[i]) {\n\t\t\t\tfor (std::size_t j = i ; j <= n ; j += i) {\n\
    \t\t\t\t\tif (!(j % (i * i))) {\n\t\t\t\t\t\ttable[j] = 0;\n\t\t\t\t\t}\n\t\t\t\
    \t\telse {\n\t\t\t\t\t\ttable[j] *= -1;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline int operator[](int i) const {\n\t\treturn table[i];\n\t}\n\
    };\n\n}// namespace zawa\n"
  dependsOn:
  - src/math/primeSieve.hpp
  isVerificationFile: false
  path: src/math/mobiusFunction.hpp
  requiredBy: []
  timestamp: '2023-03-05 22:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mobiusFunction.test.cpp
documentation_of: src/math/mobiusFunction.hpp
layout: document
title: "mobiusFunction (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u5024\u306E\u5217\u6319\
  )"
---

## 概要

正整数 $n$ 以下の正整数についてメビウス関数値 $\mu$ を列挙する

メビウス関数とは以下に定義される関数(参考: [wikipedia](https://ja.wikipedia.org/wiki/%E3%83%A1%E3%83%93%E3%82%A6%E3%82%B9%E9%96%A2%E6%95%B0)）

- 平方数で割り切れるなら0
- 偶数個の素因数の積で表現されるなら1
- 奇数個の素因数の積で表現されるなら-1

## 機能

#### コンストラクタ

```
(1) zawa::mobiusFunction()
(2) zawa::mobiusFunction(std::size_t n)
```

**(1)**

デフォルトコンストラクタ

**(2)**

$n$ 以下のメビウス関数値を列挙する

**計算量**

$O(n\log (\log n))$

<br />

#### operator

**[]**

```
inline int operator[](std::size_t i) const
```

$\mu(i)$ を返す

**制約**

$1\ \le\ i\ \le\ n$

**計算量**

$O(1)$
