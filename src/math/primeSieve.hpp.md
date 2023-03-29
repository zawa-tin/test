---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/gcdConvolution.hpp
    title: "gcdConvlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u30FB\u7D04\u6570\
      \u7CFB\u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\
      )"
  - icon: ':heavy_check_mark:'
    path: src/math/mobiusFunction.hpp
    title: "mobiusFunction (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570\u5024\u306E\u5217\
      \u6319)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CF856-D.test.cpp
    title: test/CF856-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/gcdConvolution.test.cpp
    title: test/gcdConvolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mobiusFunction.test.cpp
    title: test/mobiusFunction.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/primeSieve.test.cpp
    title: test/primeSieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/primeSieve.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\nclass primeSieve {\nprivate:\n\tstd::vector<bool> sieve;\n\npublic:\n\
    \tprimeSieve() {}\n\tprimeSieve(std::size_t n) : sieve(n + 1, true) {\n\t\tif\
    \ (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t}\n\t\tif (n >= 1) {\n\t\t\tsieve[1]\
    \ = false;\n\t\t}\n\t\tfor (std::size_t i = 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i])\
    \ {\n\t\t\t\tfor (std::size_t j = i * 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j]\
    \ = false;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\tinline bool operator[](std::size_t\
    \ i) const {\n\t\treturn sieve[i];\n\t}\n\n\tinline std::size_t size() const {\n\
    \t\treturn sieve.size();\n\t}\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\nclass primeSieve\
    \ {\nprivate:\n\tstd::vector<bool> sieve;\n\npublic:\n\tprimeSieve() {}\n\tprimeSieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline bool operator[](std::size_t i) const {\n\t\treturn sieve[i];\n\
    \t}\n\n\tinline std::size_t size() const {\n\t\treturn sieve.size();\n\t}\n};\n\
    \n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/primeSieve.hpp
  requiredBy:
  - src/math/gcdConvolution.hpp
  - src/math/mobiusFunction.hpp
  timestamp: '2023-03-05 22:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/gcdConvolution.test.cpp
  - test/mobiusFunction.test.cpp
  - test/primeSieve.test.cpp
  - test/CF856-D.test.cpp
documentation_of: src/math/primeSieve.hpp
layout: document
title: "primeSieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\uFF09"
---

## 概要

[エラトステネスの篩](https://ja.wikipedia.org/wiki/%E3%82%A8%E3%83%A9%E3%83%88%E3%82%B9%E3%83%86%E3%83%8D%E3%82%B9%E3%81%AE%E7%AF%A9) アルゴリズムによりある正整数 $n$ 以下の正整数についてそれが素数かそうでないかの是非を保持します。

osa-k法等の高速素因数分解、高速約数列挙をしたい場合は線形篩の方をお使いください


## 機能

#### コンストラクタ

```
(1) zawa::primeSieve() 
(2) zawa::primeSieve(std::size_t n)
```

**(1)**

デフォルトコンストラクタ

**(2)**

`n`以下の正整数について素数判定を行う

**計算量**

$O(n\log (\log n))$

<br />

#### operator

**[]**
```
inline bool operator[](std::size_t i) const
```
$i$ が素数かどうかを`bool`値で返す

**制約**

$0\ <\ i\ \le\ n$

**計算量**

$O(1)$


## メモ

今までテーブルの構築を
```
for (usize i = 2 ; i <= n ; i++) 
	if (table[i])
		for (usize j = i * i ; j <= n ; j += i)
			table[j] = false;
```

とやっていたが、なぜかコドフォで壊れた(LCやAtCでは普通に大丈夫）

ので

```
for (usize i = 2 ; i <= n ; i++)
	if (table[i])
		for (usize j = i * 2 ; j <= n ; j += i)
			table[j] = false;
```

としている。個人的な予想では`usize (=std::size_t)`がなんか悪さしとる

## 参考


[エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
