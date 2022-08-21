---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Eratosthenes-Sieve.hpp
    title: "Eratosthenes Sieve (\u7D20\u6570\u30C6\u30FC\u30D6\u30EB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Mobius-Function.test.cpp
    title: test/Mobius-Function.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Mobius-Function.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n#line 2 \"src/math/Eratosthenes-Sieve.hpp\"\n\n#line 4 \"src/math/Eratosthenes-Sieve.hpp\"\
    \n\nnamespace zawa {\n\n    class Eratosthenes_Sieve {\n    private:\n       \
    \ std::vector<bool> table;\n\n    public:\n        Eratosthenes_Sieve(int n) :\
    \ table(std::vector<bool>(n + 1, true)) {\n            if (n >= 0) table[0] =\
    \ false;\n            if (n >= 1) table[1] = false;\n            \n          \
    \  for (long long i = 2 ; i <= n ; i++) {\n                if (!table[i]) continue;\n\
    \                for (long long j = i * i ; j <= n ; j += i) {\n             \
    \       table[j] = false;\n                }\n            }\n        }\n\n   \
    \     bool is_prime(int x) {\n            return 0 <= x and x < (int)table.size()\
    \ and table[x];\n        }\n    };\n\n}// namespace zawa\n#line 6 \"src/math/Mobius-Function.hpp\"\
    \n\nnamespace zawa {\n\n    class Mobius_Function {\n    private:\n        std::vector<int_fast8_t>\
    \ table;\n\n    public:\n        Mobius_Function(int n) : table(std::vector<int_fast8_t>(n\
    \ + 1, 1)) {\n            Eratosthenes_Sieve siv(n);\n\n            for (int i\
    \ = 2 ; i <= n ; i++) {\n                if (!siv.is_prime(i)) continue;\n\n \
    \               for (long long j = i ; j <= n ; j += i) {\n                  \
    \  if (!(j % ((long long)i * i))) {\n                        table[j] = 0;\n \
    \                   }\n                    else {\n                        table[j]\
    \ *= -1;\n                    }\n                }\n            }\n        }\n\
    \n        int get(int x) {\n            return table[x];\n        }\n    };\n\n\
    }// namespace zawa\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n#include \"Eratosthenes-Sieve.hpp\"\
    \n\nnamespace zawa {\n\n    class Mobius_Function {\n    private:\n        std::vector<int_fast8_t>\
    \ table;\n\n    public:\n        Mobius_Function(int n) : table(std::vector<int_fast8_t>(n\
    \ + 1, 1)) {\n            Eratosthenes_Sieve siv(n);\n\n            for (int i\
    \ = 2 ; i <= n ; i++) {\n                if (!siv.is_prime(i)) continue;\n\n \
    \               for (long long j = i ; j <= n ; j += i) {\n                  \
    \  if (!(j % ((long long)i * i))) {\n                        table[j] = 0;\n \
    \                   }\n                    else {\n                        table[j]\
    \ *= -1;\n                    }\n                }\n            }\n        }\n\
    \n        int get(int x) {\n            return table[x];\n        }\n    };\n\n\
    }// namespace zawa\n"
  dependsOn:
  - src/math/Eratosthenes-Sieve.hpp
  isVerificationFile: false
  path: src/math/Mobius-Function.hpp
  requiredBy: []
  timestamp: '2022-08-21 19:26:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Mobius-Function.test.cpp
documentation_of: src/math/Mobius-Function.hpp
layout: document
title: "Mobius Function (\u30E1\u30D3\u30A6\u30B9\u95A2\u6570)"
---

## 概要
```
Mobius_Function(int n)
```

1から $N$ についてメビウス関数 $\mu (i)$ の値を求めます。

メビウス関数は値域が $\{\ -1,\ 0,\ 1\ \}$ である以下の定義に従う関数です。
-	$\mu (1)\ =\ 1$
-	$i$ を素因数分解した際、指数が2以上の素因数が出現するなら $\mu(i)\ =\ 0$
-	以上以外の $i$ について素因数分解した際、 出現する素因数の種類が $K$ 種類なら $mu(i)\ =\ (-1)^K$

## 機能

* `コンストラクタ`: 1 以上 $N$ 以下のメビウス関数の値を求め、プライベート変数`table`に記録します。 0には1が入っています。(本来は未定義)
* `get(int x)`: $\mu(i)$ を返します。 $N$ 以下の正の整数である必要があります。


試験的に`table`変数の型に`int_fast8_t`を用いてみました。`get`メソッドは`int`のままですが。
* 直接`std::cout`等をすると正しく出力されないことを確認しています。注意してください。未来の自分。

## 計算量
* `コンストラクタ`: $O(N log(log\ N))$
* `get`: 定数

## 使いどころ

高速メビウス変換やそれを用いる添字GCD畳み込み等でメビウス関数が利用されます。

また、約数に関して包除原理を行う際に便利です。
* TOOO: ライブラリノートを書く
