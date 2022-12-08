---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mod-inverses.test.cpp
    title: test/mod-inverses.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/mod-inverses.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <long long mod>\nclass mod_inverses {\nprivate:\n    std::vector<long\
    \ long> factorial;\n    std::vector<long long> inversion;\n    std::vector<long\
    \ long> inv_factorial;\n\npublic:\n    mod_inverses(std::size_t size) \n     \
    \   : factorial(size + 1, 1)\n        , inversion(size + 1, 1)\n        , inv_factorial(size\
    \ + 1, 1) {\n        for (int i = 1 ; i <= (int)size ; i++) {\n            factorial[i]\
    \ = factorial[i - 1] * i % mod;\n        }\n        for (int i = 2 ; i <= (int)size\
    \ ; i++) {\n            inversion[i] = (mod - mod / i) * inversion[mod % i] %\
    \ mod;\n        }\n        for (int i = 1 ; i <= (int)size ; i++) {\n        \
    \    inv_factorial[i] = inv_factorial[i - 1] * inversion[i] % mod;\n        }\n\
    \    }\n\n    inline long long inv(int x) {\n        return inversion[x];\n  \
    \  }\n\n    inline long long inv_fac(int x) {\n        return inv_factorial[x];\n\
    \    }\n\n    long long comb(int n, int r, bool check = true) {\n        if (check)\
    \ {\n            if (n < 0 or n - r < 0 or r < 0) {\n                return -1LL;\n\
    \            }\n            if (n >= (int)factorial.size() or r >= (int)factorial.size()\
    \ or (n - r) >= (int)factorial.size()) {\n                return -1LL;\n     \
    \       }\n        }\n        return (((factorial[n] * inv_factorial[n - r]) %\
    \ mod) * inv_factorial[r]) % mod;\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <long long\
    \ mod>\nclass mod_inverses {\nprivate:\n    std::vector<long long> factorial;\n\
    \    std::vector<long long> inversion;\n    std::vector<long long> inv_factorial;\n\
    \npublic:\n    mod_inverses(std::size_t size) \n        : factorial(size + 1,\
    \ 1)\n        , inversion(size + 1, 1)\n        , inv_factorial(size + 1, 1) {\n\
    \        for (int i = 1 ; i <= (int)size ; i++) {\n            factorial[i] =\
    \ factorial[i - 1] * i % mod;\n        }\n        for (int i = 2 ; i <= (int)size\
    \ ; i++) {\n            inversion[i] = (mod - mod / i) * inversion[mod % i] %\
    \ mod;\n        }\n        for (int i = 1 ; i <= (int)size ; i++) {\n        \
    \    inv_factorial[i] = inv_factorial[i - 1] * inversion[i] % mod;\n        }\n\
    \    }\n\n    inline long long inv(int x) {\n        return inversion[x];\n  \
    \  }\n\n    inline long long inv_fac(int x) {\n        return inv_factorial[x];\n\
    \    }\n\n    long long comb(int n, int r, bool check = true) {\n        if (check)\
    \ {\n            if (n < 0 or n - r < 0 or r < 0) {\n                return -1LL;\n\
    \            }\n            if (n >= (int)factorial.size() or r >= (int)factorial.size()\
    \ or (n - r) >= (int)factorial.size()) {\n                return -1LL;\n     \
    \       }\n        }\n        return (((factorial[n] * inv_factorial[n - r]) %\
    \ mod) * inv_factorial[r]) % mod;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/mod-inverses.hpp
  requiredBy: []
  timestamp: '2022-12-08 15:19:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mod-inverses.test.cpp
documentation_of: src/math/mod-inverses.hpp
layout: document
title: "mod-inverses (mod\u9006\u5143\u5217\u6319\u3001\u4E8C\u9805\u4FC2\u6570)"
---

## 概要
```
zawa::Binary_Coeff<mod>(int n)
```

サイズ $n$ の階乗テーブルと逆元の階乗テーブルを作成します。


## 機能
- `mod_inverses<mod> mi(std::size_t size)`
	- コンストラクタ
	- `mod`: テンプレート引数、 $\pmod{P}$ の $P$ を入れてください
		- `mod` は素数である必要があります。
	- `size`: 取得する最大サイズ
	- **計算量** : $O(\text{size})$

- `inline long long mi.inv(int x)`
	- $ax \equiv 1\pmod{P}$ を満たす $a$ を返します。
	- **単体テストをしていません** (TODO)
	- $1\ \le\ x\ \le\ \text{size}$
	- **計算量** : $O(1)$

- `inline long long mi.inv_fac(int x)`
	- $a(x!)\ \equiv\ \pmod{P}$ を満たす $a$ を返します。
	- **単体テストをしていません** (TODO)
	- $1\ \le\ x\ \le\ \text{size}$
	- **計算量** : $O(1)$

- `long long mi.comb(int n, int r, bool check = true)`
	- $\binom{n}{r}$ を $P$ で割った余りを返します。
	- `check`: `true`だと境界値チェックをはさみ、失敗すると`-1`を返すようになります。デバッグ用
	- $0\ \le\ r\ \le\ n\ \le\ \text{size}$
	- **計算量** : $O(1)$

## 参考

[Tweet by @catupper](https://twitter.com/catupper/status/1340573042204844035)
