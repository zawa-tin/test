---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/primeSieve.hpp
    title: "primeSieve (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/gcdConvolution.test.cpp
    title: test/gcdConvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/gcdConvolution.hpp\"\n\n#line 2 \"src/math/primeSieve.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\nclass primeSieve {\nprivate:\n\t\
    std::vector<bool> sieve;\n\npublic:\n\tprimeSieve() {}\n\tprimeSieve(std::size_t\
    \ n) : sieve(n + 1, true) {\n\t\tif (n >= 0) {\n\t\t\tsieve[0] = false;\n\t\t\
    }\n\t\tif (n >= 1) {\n\t\t\tsieve[1] = false;\n\t\t}\n\t\tfor (std::size_t i =\
    \ 2 ; i <= n ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (std::size_t j = i *\
    \ 2 ; j <= n ; j += i) {\n\t\t\t\t\tsieve[j] = false;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tinline bool operator[](std::size_t i) const {\n\t\treturn sieve[i];\n\
    \t}\n\n\tinline std::size_t size() const {\n\t\treturn sieve.size();\n\t}\n};\n\
    \n}// namespace zawa\n#line 4 \"src/math/gcdConvolution.hpp\"\n\n#line 6 \"src/math/gcdConvolution.hpp\"\
    \n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <typename T>\nclass gcdConvolution\
    \ {\nprivate: \n\tprimeSieve sieve;\n\npublic:\n\tgcdConvolution(std::size_t n)\
    \ : sieve(n) {}\n\t\n\tstd::vector<T> fastZetaTransform(const std::vector<T>&\
    \ f) const {\n\t\tstd::vector<T> res(f.begin(), f.end());\n\t\tfor (int i = 1\
    \ ; i <= (int)(f.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (int j =\
    \ (int)res.size() / i ; j >= 1 ; j--) {\n\t\t\t\t\tres[j - 1] += res[j * i - 1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> fastMobiusTransform(const\
    \ std::vector<T>& F) const {\n\t\tstd::vector<T> res(F.begin(), F.end());\n\t\t\
    for (int i = 1 ; i <= (int)(F.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\t\
    for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {\n\t\t\t\t\tres[j - 1] -= res[j\
    \ * i - 1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T>\
    \ convolution(const std::vector<T>& f, const std::vector<T>& g) const {\n\t\t\
    std::vector<T> F = fastZetaTransform(f);\n\t\tstd::vector<T> G = fastZetaTransform(g);\n\
    \t\tstd::vector<T> H(std::min(F.size(), G.size()));\n\t\tfor (int i = 0 ; i <\
    \ (int)(H.size()) ; i++) {\n\t\t\tH[i] = F[i] * G[i];\n\t\t}\n\t\treturn fastMobiusTransform(H);\n\
    \t}\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include \"./primeSieve.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace zawa {\n\ntemplate <typename T>\nclass gcdConvolution\
    \ {\nprivate: \n\tprimeSieve sieve;\n\npublic:\n\tgcdConvolution(std::size_t n)\
    \ : sieve(n) {}\n\t\n\tstd::vector<T> fastZetaTransform(const std::vector<T>&\
    \ f) const {\n\t\tstd::vector<T> res(f.begin(), f.end());\n\t\tfor (int i = 1\
    \ ; i <= (int)(f.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\tfor (int j =\
    \ (int)res.size() / i ; j >= 1 ; j--) {\n\t\t\t\t\tres[j - 1] += res[j * i - 1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> fastMobiusTransform(const\
    \ std::vector<T>& F) const {\n\t\tstd::vector<T> res(F.begin(), F.end());\n\t\t\
    for (int i = 1 ; i <= (int)(F.size()) ; i++) {\n\t\t\tif (sieve[i]) {\n\t\t\t\t\
    for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {\n\t\t\t\t\tres[j - 1] -= res[j\
    \ * i - 1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T>\
    \ convolution(const std::vector<T>& f, const std::vector<T>& g) const {\n\t\t\
    std::vector<T> F = fastZetaTransform(f);\n\t\tstd::vector<T> G = fastZetaTransform(g);\n\
    \t\tstd::vector<T> H(std::min(F.size(), G.size()));\n\t\tfor (int i = 0 ; i <\
    \ (int)(H.size()) ; i++) {\n\t\t\tH[i] = F[i] * G[i];\n\t\t}\n\t\treturn fastMobiusTransform(H);\n\
    \t}\n};\n\n}// namespace zawa\n"
  dependsOn:
  - src/math/primeSieve.hpp
  isVerificationFile: false
  path: src/math/gcdConvolution.hpp
  requiredBy: []
  timestamp: '2023-03-05 22:25:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/gcdConvolution.test.cpp
documentation_of: src/math/gcdConvolution.hpp
layout: document
title: "gcdConvlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u30FB\u7D04\u6570\u7CFB\
  \u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
---

## 概要

列`f`、`g`に対して $\displaystyle h_i\ =\ \sum_{\gcd(j, k)=i} f_j\times g_k$ を満たす列 $h$ を求めます。

内部で約数集合の高速ゼータ変換、約数集合における高速メビウス変換をしているのでそちらを使いたい際もこれをincludeしてください。

約数集合の高速ゼータ変換とは列`f`に対して $\displaystyle F_i\ =\ \sum_{i\mid j} f_j$ を満たす`F`を求めることです。

約数集合の高速メビウス変換とは列`F`に対して $f_i\ =\ \sum_{i\mid j} \mu (\frac{j}{i}) F_j$ を求めることです。 $\mu$ はメビウス関数を表します。この操作は約数集合の高速ゼータ変換の逆変換です。


## 機能

#### コンストラクタ

```
zawa::gcdConvolution<T>(std::size_t n)
```

内部で使用するエラトステネスの篩を初期化します。変換したい列のサイズの最大数を超える値を引数`n`に入れてください

**計算量**

$O(n\log (\log n))$

<br />

#### メンバ

**fastZetaTransform**
```
std::vector<T> fastZetaTransform(const std::vector<T>& f) const
```

約数集合の高速ゼータ変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

**計算量**

 $O(n\log (\log n))$

<br />

**fastMobiusTransform**
```
std::vector<T> fastMobiusTransform(const std::vector<T>& F) const
```
約数集合の高速メビウス変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

**計算量**

$O(n\log (\log n))$

<br />

**convolution**
```
std::vector<T> convolution(const std::vector<T>& f, const std::vector<T>& f) const
```

添字gcd畳み込みを行います。結果を`std::vector<T>`の型で返します。畳み込みを行いたい二つの列の参照を引数にとります。

**計算量**

$O(n\log (\log n))$


## これは結局なんなの
TODO: NOTE

## 参考

[# エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
