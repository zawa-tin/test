---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Binary-Coeff.test.cpp
    title: test/Binary-Coeff.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Binary-Coeff-Mod.hpp\"\n\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <long long mod>\nclass Binary_Coeff {\nprivate:\n\
    \    std::vector<long long> factorial;\n    std::vector<long long> inversion;\n\
    \    std::vector<long long> inv_factorial;\n\npublic:\n    Binary_Coeff(std::size_t\
    \ size) \n        : factorial(size + 1, 1)\n        , inversion(size + 1, 1)\n\
    \        , inv_factorial(size + 1, 1) {\n        for (int i = 1 ; i <= size ;\
    \ i++) {\n            factorial[i] = factorial[i - 1] * i % mod;\n        }\n\
    \        for (int i = 2 ; i <= size ; i++) {\n            inversion[i] = (mod\
    \ - mod / i) * inversion[mod % i] % mod;\n        }\n        for (int i = 1 ;\
    \ i <= size ; i++) {\n            inv_factorial[i] = inv_factorial[i - 1] * inversion[i]\
    \ % mod;\n        }\n    }\n\n    long long query(int n, int r, bool check = true)\
    \ {\n        if (check) {\n            if (n < 0 or n - r < 0 or r < 0) {\n  \
    \              return -1LL;\n            }\n            if (n >= (int)factorial.size()\
    \ or r >= (int)factorial.size() or (n - r) >= (int)factorial.size()) {\n     \
    \           return -1LL;\n            }\n        }\n        return (((factorial[n]\
    \ * inv_factorial[n - r]) % mod) * inv_factorial[r]) % mod;\n    }\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <long long\
    \ mod>\nclass Binary_Coeff {\nprivate:\n    std::vector<long long> factorial;\n\
    \    std::vector<long long> inversion;\n    std::vector<long long> inv_factorial;\n\
    \npublic:\n    Binary_Coeff(std::size_t size) \n        : factorial(size + 1,\
    \ 1)\n        , inversion(size + 1, 1)\n        , inv_factorial(size + 1, 1) {\n\
    \        for (int i = 1 ; i <= size ; i++) {\n            factorial[i] = factorial[i\
    \ - 1] * i % mod;\n        }\n        for (int i = 2 ; i <= size ; i++) {\n  \
    \          inversion[i] = (mod - mod / i) * inversion[mod % i] % mod;\n      \
    \  }\n        for (int i = 1 ; i <= size ; i++) {\n            inv_factorial[i]\
    \ = inv_factorial[i - 1] * inversion[i] % mod;\n        }\n    }\n\n    long long\
    \ query(int n, int r, bool check = true) {\n        if (check) {\n           \
    \ if (n < 0 or n - r < 0 or r < 0) {\n                return -1LL;\n         \
    \   }\n            if (n >= (int)factorial.size() or r >= (int)factorial.size()\
    \ or (n - r) >= (int)factorial.size()) {\n                return -1LL;\n     \
    \       }\n        }\n        return (((factorial[n] * inv_factorial[n - r]) %\
    \ mod) * inv_factorial[r]) % mod;\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Binary-Coeff-Mod.hpp
  requiredBy: []
  timestamp: '2022-11-02 12:58:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Binary-Coeff.test.cpp
documentation_of: src/math/Binary-Coeff-Mod.hpp
layout: document
title: "Binary-Coeff (\u4E8C\u9805\u4FC2\u6570 Mod)"
---

## 概要
```
zawa::Binary_Coeff<mod>(int n)
```

サイズ $n$ の階乗テーブルと逆元の階乗テーブルを作成します。


## 機能
- `コンストラクタ`: 最大サイズを入れてください。
- `query(int n, int r, bool check = true)`: $\binom{n}{r}$ を計算します。
	- `check`を`true`にしていると範囲外参照時に-1を返します


## 計算量
- `コンストラクタ` : $O(N)$
- `query`: $O(1)$
