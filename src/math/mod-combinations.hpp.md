---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/CF856-D.test.cpp
    title: test/CF856-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mod-combinations1.test.cpp
    title: test/mod-combinations1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/mod-combinations.hpp\"\n\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <long long mod>\nclass mod_combinations {\nprivate:\n\
    \    std::vector<long long> facs, inv_facs;\n\npublic:\n    mod_combinations(std::size_t\
    \ n) : facs(2 * n + 1, 1LL), inv_facs(2 * n + 1) {\n        for (std::size_t i\
    \ = 0 ; i + 1 < facs.size() ; i++) {\n            facs[i + 1] = facs[i] * (i +\
    \ 1);\n            facs[i + 1] %= mod;\n        }\n        long long base = facs.back();\n\
    \        long long inv = 1LL;\n        long long p = mod - 2;\n        while (p\
    \ > 0) {\n            if (p & 1) {\n                inv *= base;\n           \
    \     inv %= mod;\n            }\n            base = (base * base) % mod;\n  \
    \          p >>= 1;\n        }\n        inv_facs.back() = inv;\n        for (int\
    \ i = (int)facs.size() - 1 ; i - 1 >= 0 ; i--) {\n            inv_facs[i - 1]\
    \ = inv_facs[i] * i;\n            inv_facs[i - 1] %= mod;\n        }\n    }\n\n\
    \    long long P(std::size_t n, std::size_t r) {\n        if (r > n) {\n     \
    \       return 0LL;\n        }\n        return (facs[n] * inv_facs[(n - r)]) %\
    \ mod;\n    }\n\n    long long C(std::size_t n, std::size_t r) {\n        if (r\
    \ > n) {\n            return 0LL;\n        }\n        return (P(n, r) * inv_facs[r])\
    \ % mod;\n    }\n\n    long long H(std::size_t n, std::size_t r) {\n        if\
    \ (n == 0 and r == 0) {\n            return 1LL;\n        }\n        if (r > n\
    \ + r - 1) {\n            return 0LL;\n        }\n        return C(n + r - 1,\
    \ r);\n    }\n\n    long long F(std::size_t n) {\n        return facs[n];\n  \
    \  }\n\n    long long invF(std::size_t n) {\n        return inv_facs[n];\n   \
    \ }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <long long\
    \ mod>\nclass mod_combinations {\nprivate:\n    std::vector<long long> facs, inv_facs;\n\
    \npublic:\n    mod_combinations(std::size_t n) : facs(2 * n + 1, 1LL), inv_facs(2\
    \ * n + 1) {\n        for (std::size_t i = 0 ; i + 1 < facs.size() ; i++) {\n\
    \            facs[i + 1] = facs[i] * (i + 1);\n            facs[i + 1] %= mod;\n\
    \        }\n        long long base = facs.back();\n        long long inv = 1LL;\n\
    \        long long p = mod - 2;\n        while (p > 0) {\n            if (p &\
    \ 1) {\n                inv *= base;\n                inv %= mod;\n          \
    \  }\n            base = (base * base) % mod;\n            p >>= 1;\n        }\n\
    \        inv_facs.back() = inv;\n        for (int i = (int)facs.size() - 1 ; i\
    \ - 1 >= 0 ; i--) {\n            inv_facs[i - 1] = inv_facs[i] * i;\n        \
    \    inv_facs[i - 1] %= mod;\n        }\n    }\n\n    long long P(std::size_t\
    \ n, std::size_t r) {\n        if (r > n) {\n            return 0LL;\n       \
    \ }\n        return (facs[n] * inv_facs[(n - r)]) % mod;\n    }\n\n    long long\
    \ C(std::size_t n, std::size_t r) {\n        if (r > n) {\n            return\
    \ 0LL;\n        }\n        return (P(n, r) * inv_facs[r]) % mod;\n    }\n\n  \
    \  long long H(std::size_t n, std::size_t r) {\n        if (n == 0 and r == 0)\
    \ {\n            return 1LL;\n        }\n        if (r > n + r - 1) {\n      \
    \      return 0LL;\n        }\n        return C(n + r - 1, r);\n    }\n\n    long\
    \ long F(std::size_t n) {\n        return facs[n];\n    }\n\n    long long invF(std::size_t\
    \ n) {\n        return inv_facs[n];\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod-combinations.hpp
  requiredBy: []
  timestamp: '2022-12-24 00:05:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mod-combinations1.test.cpp
  - test/CF856-D.test.cpp
documentation_of: src/math/mod-combinations.hpp
layout: document
title: "mod combinations (\u7D44\u307F\u5408\u308F\u305B\u306E\u6570 mod)"
---

## 概要

順列の数、組み合わせの数、重複組み合わせの数 それぞれについて、素数で割った余りを提供します


> 順列の数 $_nP_r$
>
> $n$ 個の区別がつく要素から $r$ 個選択して一列に並べる通り数
>
> 例: $_5P_3\ =\ 20$

> 組み合わせの数 $_nC_r$
>
> $\binom{n}{r}$ の方が一般的な言い方？
>
> $n$ 個の区別がつく要素から $r$ 個選択する通り数
>
> 例: $_6C_2\ =\ 15$

> 重複組み合わせの数 $_nH_r$
>
> $n$ 種類の要素（同じ種類の要素は区別がつかない）がそれぞれ無数にあるなかで、 $r$ 個選択する通り数
>
> （ボールと仕切りのやつ）
>
> 例: $_3H_4\ =\ 15$

## 機能

- `zawa::mod_combinations<mod> mc(std::size_t n)`
	- コンストラクタ
		- `mod`: テンプレート引数
			- `mod`は`n`に対して十分大きい素数である必要があります
		- `n`: 配列の大きさ			
			- 求めたい $_n\text{hoge}_r$ のどの $n$ や $r$ より大きいものを指定してください
	- **計算量** : $O(n\ +\ \log \text{mod})$

- `long long mc.P(std::size_t n, std::size_t r)`
	- $_nP_r$ を`mod`で割った余りを返します 
		- $n < r$ は0を返します
	- **計算量**: $O(1)$

- `long long mc.C(std::size_t n, std::size_t r)`
	- $_nC_r$ を`mod`で割った余りを返します
		- $n < r$ は0を返します
	- **計算量** : $O(1)$

- `long long mc.H(std::size_t n, std::size_t r)`
	- $_nH_r$ を`mod`で割った余りを返します
		- $n < r$ は0を返します
		- $_0H_0$ は配列外参照 ですが、これは1を返します
	- **計算量** : $O(1)$

- `long long mc.F(std::size_t n)`
    - $n!$ 、すなわち $_nP_n$ を返します
    - **単体テストをしていません**
    - **計算量** : $O(1)$

- `long long mc.invF(std::size_t n)`
    - $a*_nP_n\ \equiv\ 1\ \pmod{\text{mod}}$ なる $a$ を返します。
    - **単体テストをしていません**
    - **計算量** : $O(1)$
