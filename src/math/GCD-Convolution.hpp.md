---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Eratosthenes-Sieve.hpp
    title: "Eratosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/GCD-Convolution.test.cpp
    title: test/GCD-Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/GCD-Convolution.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\n\n#line 4 \"src/math/Eratosthenes-Sieve.hpp\"\
    \n\nnamespace zawa {\n\n    class Eratosthenes_Sieve {\n    private:\n       \
    \ std::vector<bool> table;\n\n    public:\n        Eratosthenes_Sieve(int n) :\
    \ table(std::vector<bool>(n + 1, true)) {\n            if (n >= 0) table[0] =\
    \ false;\n            if (n >= 1) table[1] = false;\n            \n          \
    \  for (long long i = 2 ; i <= n ; i++) {\n                if (!table[i]) continue;\n\
    \                for (long long j = i * i ; j <= n ; j += i) {\n             \
    \       table[j] = false;\n                }\n            }\n        }\n\n   \
    \     bool is_prime(int x) {\n            return 0 <= x and x < (int)table.size()\
    \ and table[x];\n        }\n    };\n\n}// namespace zawa\n#line 6 \"src/math/GCD-Convolution.hpp\"\
    \n\nnamespace zawa {\n\n    template <typename T>\n    class GCD_Convolution {\n\
    \    private: \n        Eratosthenes_Sieve sieve;\n\n    public:\n        GCD_Convolution(int\
    \ n) : sieve(Eratosthenes_Sieve(n)) {}\n        \n        std::vector<T> fast_zeta_transform(const\
    \ std::vector<T>& f) {\n            std::vector<T> res(f.begin(), f.end());\n\n\
    \            for (int i = 1 ; i <= (int)(f.size()) ; i++) {\n                if\
    \ (!sieve.is_prime(i)) continue;\n\n                for (int j = (int)res.size()\
    \ / i ; j >= 1 ; j--) {\n                    res[j - 1] += res[j * i - 1];\n \
    \               }\n            }\n\n            return res;\n        }\n\n   \
    \     std::vector<T> fast_mobius_transform(const std::vector<T>& F) {\n      \
    \      std::vector<T> res(F.begin(), F.end());\n\n            for (int i = 1 ;\
    \ i <= (int)(F.size()) ; i++) {\n                if (!sieve.is_prime(i)) continue;\n\
    \n                for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {\n       \
    \             res[j - 1] -= res[j * i - 1];\n                }\n            }\n\
    \n            return res;\n        }\n\n        std::vector<T> convolution(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n            std::vector<T> F\
    \ = fast_zeta_transform(f);\n            std::vector<T> G = fast_zeta_transform(g);\n\
    \            \n            std::vector<T> H(std::min(F.size(), G.size()));\n \
    \           for (int i = 0 ; i < (int)(H.size()) ; i++) {\n                H[i]\
    \ = F[i] * G[i];\n            }\n\n            return fast_mobius_transform(H);\n\
    \        }\n    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include \"Eratosthenes-Sieve.hpp\"\
    \n\nnamespace zawa {\n\n    template <typename T>\n    class GCD_Convolution {\n\
    \    private: \n        Eratosthenes_Sieve sieve;\n\n    public:\n        GCD_Convolution(int\
    \ n) : sieve(Eratosthenes_Sieve(n)) {}\n        \n        std::vector<T> fast_zeta_transform(const\
    \ std::vector<T>& f) {\n            std::vector<T> res(f.begin(), f.end());\n\n\
    \            for (int i = 1 ; i <= (int)(f.size()) ; i++) {\n                if\
    \ (!sieve.is_prime(i)) continue;\n\n                for (int j = (int)res.size()\
    \ / i ; j >= 1 ; j--) {\n                    res[j - 1] += res[j * i - 1];\n \
    \               }\n            }\n\n            return res;\n        }\n\n   \
    \     std::vector<T> fast_mobius_transform(const std::vector<T>& F) {\n      \
    \      std::vector<T> res(F.begin(), F.end());\n\n            for (int i = 1 ;\
    \ i <= (int)(F.size()) ; i++) {\n                if (!sieve.is_prime(i)) continue;\n\
    \n                for (int j = 1 ; j * i <= (int)(F.size()) ; j++) {\n       \
    \             res[j - 1] -= res[j * i - 1];\n                }\n            }\n\
    \n            return res;\n        }\n\n        std::vector<T> convolution(const\
    \ std::vector<T>& f, const std::vector<T>& g) {\n            std::vector<T> F\
    \ = fast_zeta_transform(f);\n            std::vector<T> G = fast_zeta_transform(g);\n\
    \            \n            std::vector<T> H(std::min(F.size(), G.size()));\n \
    \           for (int i = 0 ; i < (int)(H.size()) ; i++) {\n                H[i]\
    \ = F[i] * G[i];\n            }\n\n            return fast_mobius_transform(H);\n\
    \        }\n    };\n\n}// namespace zawa\n"
  dependsOn:
  - src/math/Eratosthenes-Sieve.hpp
  isVerificationFile: false
  path: src/math/GCD-Convolution.hpp
  requiredBy: []
  timestamp: '2022-08-22 15:45:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/GCD-Convolution.test.cpp
documentation_of: src/math/GCD-Convolution.hpp
layout: document
title: "GCD Convlution (\u6DFB\u5B57gcd\u7573\u307F\u8FBC\u307F\u3001\u7D04\u6570\u96C6\
  \u5408\u306E\u9AD8\u901F\u30BC\u30FC\u30BF/\u30E1\u30D3\u30A6\u30B9\u5909\u63DB)"
---

## 概要
```
GCD_Convolution<T>
```

列`f`、`g`に対して $\displaystyle h_i\ =\ \sum_{gcd(j, k)=i} f_j\times g_k$ を満たす列 $h$ を求めます。

内部で約数集合の高速ゼータ変換、約数集合における高速メビウス変換をしているのでそちらを使いたい際もこれをincludeしてください。

約数集合の高速ゼータ変換とは列`f`に対して $\displaystyle F_i\ =\ \sum_{i\mid j} f_j$ を満たす`F`を求めることです。

約数集合の高速メビウス変換とは列`F`に対して $f_i\ =\ \sum_{i\mid j} \mu (\frac{j}{i}) F_j$ を求めることです。 $\mu$ はメビウス関数を表します。この操作は約数集合の高速ゼータ変換の逆変換です。


## 機能

- `コンストラクタ`: 内部で使用するエラトステネスの篩を初期化します。変換したい列のサイズの最大数を超える値を引数に入れてください(32bit)

- `fast_zeta_transform`: 約数集合の高速ゼータ変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

- `fast_mobius_transform`: 約数集合の高速メビウス変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

- `convolution`: 添字gcd畳み込みを行います。結果を`std::vector<T>`の型で返します。畳み込みを行いたい二つの列の参照を引数にとります。

## 計算量

- `コンストラクタ`: 引数 $N$ に対して $O(N log(log\ N))$
- `fast_zeta_transform、fast_mobius_transform`: 列の長さを $N$ として $O(Nlog(log\ N))$
- `convolution`: 列の長さをそれぞれ $N, M$ として $O(min(N, M) log (log\ min(N, M)))$

## これは結局なんなの
TODO:: NOTE


## 参考
[https://qiita.com/drken/items/3beb679e54266f20ab63]
