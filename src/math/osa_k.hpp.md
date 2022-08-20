---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/osa_k.test.cpp
    title: test/osa_k.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/osa_k2.test.cpp
    title: test/osa_k2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/osa_k.hpp\"\n\n#include <vector>\n\nnamespace zawa\
    \ {\n\n    class osa_k {\n    private:\n        std::vector<int> factors;\n\n\
    \    public:\n        osa_k(int n) : factors(std::vector<int>(n + 1)) {\n    \
    \        if (n >= 1) factors[1] = 1;\n\n            for (long long i = 2 ; i <=\
    \ n ; i++) {\n                if (factors[i]) continue;\n                factors[i]\
    \ = i;\n\n                for (long long j = i * i ; j <= n ; j += i) {\n    \
    \                if (!factors[j]) {\n                        factors[j] = i;\n\
    \                    }\n                }\n            }\n        }\n\n      \
    \  std::vector<std::pair<int, int>> factorize(int x) {\n            std::vector<std::pair<int,\
    \ int>> res;\n            if (x <= 0 or x >= (int)factors.size()) {\n        \
    \        return res;\n            }\n\n            while (x > 1) {\n         \
    \       res.emplace_back(factors[x], 0);\n                while (factors[x] ==\
    \ res.back().first) {\n                    x /= res.back().first;\n          \
    \          res.back().second++;\n                }\n            }\n\n        \
    \    return res;\n        }\n\n        std::vector<int> divisor(int x) {\n   \
    \         std::vector<int> res;\n\n            if (x <= 0 or x > (int)factors.size())\
    \ {\n                return res;\n            }\n\n            auto facs = factorize(x);\n\
    \n            res.emplace_back(1);\n\n            for (auto [p, e] : facs) {\n\
    \                int sz = (int)res.size();\n                for (int i = 0 ; i\
    \ < sz ; i++) {\n                    int v = 1;\n                    for (int\
    \ j = 0 ; j < e ; j++) {\n                        v *= p;\n                  \
    \      res.emplace_back(res[i] * v);\n                    }\n                }\n\
    \            }\n\n            return res;\n        }\n    };\n\n}// namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    class osa_k\
    \ {\n    private:\n        std::vector<int> factors;\n\n    public:\n        osa_k(int\
    \ n) : factors(std::vector<int>(n + 1)) {\n            if (n >= 1) factors[1]\
    \ = 1;\n\n            for (long long i = 2 ; i <= n ; i++) {\n               \
    \ if (factors[i]) continue;\n                factors[i] = i;\n\n             \
    \   for (long long j = i * i ; j <= n ; j += i) {\n                    if (!factors[j])\
    \ {\n                        factors[j] = i;\n                    }\n        \
    \        }\n            }\n        }\n\n        std::vector<std::pair<int, int>>\
    \ factorize(int x) {\n            std::vector<std::pair<int, int>> res;\n    \
    \        if (x <= 0 or x >= (int)factors.size()) {\n                return res;\n\
    \            }\n\n            while (x > 1) {\n                res.emplace_back(factors[x],\
    \ 0);\n                while (factors[x] == res.back().first) {\n            \
    \        x /= res.back().first;\n                    res.back().second++;\n  \
    \              }\n            }\n\n            return res;\n        }\n\n    \
    \    std::vector<int> divisor(int x) {\n            std::vector<int> res;\n\n\
    \            if (x <= 0 or x > (int)factors.size()) {\n                return\
    \ res;\n            }\n\n            auto facs = factorize(x);\n\n           \
    \ res.emplace_back(1);\n\n            for (auto [p, e] : facs) {\n           \
    \     int sz = (int)res.size();\n                for (int i = 0 ; i < sz ; i++)\
    \ {\n                    int v = 1;\n                    for (int j = 0 ; j <\
    \ e ; j++) {\n                        v *= p;\n                        res.emplace_back(res[i]\
    \ * v);\n                    }\n                }\n            }\n\n         \
    \   return res;\n        }\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/osa_k.hpp
  requiredBy: []
  timestamp: '2022-08-20 22:48:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/osa_k2.test.cpp
  - test/osa_k.test.cpp
documentation_of: src/math/osa_k.hpp
layout: document
title: "osa_k (\u8907\u6570\u8981\u7D20\u306E\u7D04\u6570\u5217\u6319\u30FB\u7D20\u56E0\
  \u6570\u5206\u89E3)"
---

## 概要
```
osa_k(int n)
```

エラトステネスの篩のアルゴリズムを用いた前準備を行うことで $N$ 以下の要素の約数列挙・素因数分解を（試し割りを用いたアルゴリズムより）高速に行う。

エラトステネスの篩を行うと同時にそれぞれの数の最小素因数を記録することで実現している。

## 機能
* `コンストラクタ`: 最小素因数を記録するテーブルを構築する

* `factorize(int x)`: 素因数分解を`std::vector<std::pair<int, int>>`の型で返す。`first`が素因数、`second`が次数です。

* `divisor(int x)`: 約数列挙を`std::vector<int>`の型で返す。

$0 \ \le\ x\ \le\ N$ を満たさない数は空列を返すように実装している。（実装した後に思ったけどバグってもらったほうが良い気がしてきた)

## 計算量

* `コンストラクタ`: $O(Nlog(log\ N))$

* `factorize`、`divisor`: $O(log\ x)$

## 参考
 
https://qiita.com/drken/items/3beb679e54266f20ab63

https://osak.jp/diary/diary_201310.html#20131017
