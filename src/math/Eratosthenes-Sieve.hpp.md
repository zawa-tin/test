---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Eratosthenes-Sieve.test.cpp
    title: test/Eratosthenes-Sieve.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\n    class Eratosthenes_Sieve {\n    private:\n        std::vector<bool>\
    \ table;\n\n    public:\n        Eratosthenes_Sieve(int n) : table(std::vector<bool>(n\
    \ + 1, true)) {\n            if (n >= 0) table[0] = false;\n            if (n\
    \ >= 1) table[1] = false;\n            \n            for (long long i = 2 ; i\
    \ <= n ; i++) {\n                if (!table[i]) continue;\n                for\
    \ (long long j = i * i ; j <= n ; j += i) {\n                    table[j] = false;\n\
    \                }\n            }\n        }\n\n        bool is_prime(int x) {\n\
    \            return 0 <= x and x < (int)table.size() and table[x];\n        }\n\
    \    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    class Eratosthenes_Sieve\
    \ {\n    private:\n        std::vector<bool> table;\n\n    public:\n        Eratosthenes_Sieve(int\
    \ n) : table(std::vector<bool>(n + 1, true)) {\n            if (n >= 0) table[0]\
    \ = false;\n            if (n >= 1) table[1] = false;\n            \n        \
    \    for (long long i = 2 ; i <= n ; i++) {\n                if (!table[i]) continue;\n\
    \                for (long long j = i * i ; j <= n ; j += i) {\n             \
    \       table[j] = false;\n                }\n            }\n        }\n\n   \
    \     bool is_prime(int x) {\n            return 0 <= x and x < (int)table.size()\
    \ and table[x];\n        }\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Eratosthenes-Sieve.hpp
  requiredBy: []
  timestamp: '2022-08-20 16:08:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Eratosthenes-Sieve.test.cpp
documentation_of: src/math/Eratosthenes-Sieve.hpp
layout: document
title: "Etatosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
---

## 概要
```
Eratosthenes_Sieve(int n)
```

 $N$ 以下の正の整数全てについて素数であるかの是非を求めます。

## 機能
* `コンストラクタ`: $N$ を引数に入れます。素数テーブルを構築します。

* `is_prime(int x)`: $x$ が素数であるかを`bool`値で返します。


## 計算量
* `コンストラクタ`: $O(Nlog(log\ N))$

* `is_prime`: 定数
