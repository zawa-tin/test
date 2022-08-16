---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/Euler-Function.hpp
    title: "Euler Function(\u30AA\u30A4\u30E9\u30FC\u95A2\u6570)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_ntl_1_a.test.cpp
    title: test/aoj_ntl_1_a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj_ntl_1_d.test.cpp
    title: test/aoj_ntl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/factorize.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\n    std::vector<std::pair<long long, int>> factorize(long long x)\
    \ {\n        std::vector<std::pair<long long, int>> res;\n\n        for (long\
    \ long i = 2 ; i * i <= x ; i++) {\n            if (x % i) continue;\n       \
    \     int cnt = 0;\n            while (!(x % i)) {\n                cnt++;\n \
    \               x /= i;\n            }\n            res.emplace_back(i, cnt);\n\
    \        }\n        if (x != 1) res.emplace_back(x, 1);\n\n        return res;\n\
    \    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    std::vector<std::pair<long\
    \ long, int>> factorize(long long x) {\n        std::vector<std::pair<long long,\
    \ int>> res;\n\n        for (long long i = 2 ; i * i <= x ; i++) {\n         \
    \   if (x % i) continue;\n            int cnt = 0;\n            while (!(x % i))\
    \ {\n                cnt++;\n                x /= i;\n            }\n        \
    \    res.emplace_back(i, cnt);\n        }\n        if (x != 1) res.emplace_back(x,\
    \ 1);\n\n        return res;\n    }\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/factorize.hpp
  requiredBy:
  - src/math/Euler-Function.hpp
  timestamp: '2022-07-25 23:24:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_ntl_1_a.test.cpp
  - test/aoj_ntl_1_d.test.cpp
documentation_of: src/math/factorize.hpp
layout: document
title: "Factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
---

## 概要
```
std::vector<std::pair<long long, int>> factorize(long long x)
```

試し割りを用いた素朴な素因素分解を行います。

### 機能
* `std::vector<std::pair<long long, int>> factorize(long long x)`: 素因素分解をします。

* 返り値はfirstが素因数、secondが次数です

### 制約
$0\ \le\ x$  (上限は$10^{12}$くらいが適切です。多分)

### 計算量
$O(\sqrt{x})$
