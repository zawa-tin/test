---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_ntl_1_e.test.cpp
    title: test/aoj_ntl_1_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Extend-GCD.hpp\"\n\nnamespace zawa {\n\n    void\
    \ rec(long long a, long long b, long long& x, long long& y) {\n        if (b ==\
    \ 0) {\n            x = 1;\n            y = 0;\n            return;\n        }\n\
    \n        rec(b, a % b, y, x);\n        \n        y -= a / b * x;\n    }\n\n \
    \   std::pair<long long, long long> extend_gcd(long long a, long long b) {\n \
    \       long long resx = 0, resy = 0;\n        rec(a, b, resx, resy);\n      \
    \  return {resx, resy};\n    }\n\n}// namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\n    void rec(long long a, long long b,\
    \ long long& x, long long& y) {\n        if (b == 0) {\n            x = 1;\n \
    \           y = 0;\n            return;\n        }\n\n        rec(b, a % b, y,\
    \ x);\n        \n        y -= a / b * x;\n    }\n\n    std::pair<long long, long\
    \ long> extend_gcd(long long a, long long b) {\n        long long resx = 0, resy\
    \ = 0;\n        rec(a, b, resx, resy);\n        return {resx, resy};\n    }\n\n\
    }// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Extend-GCD.hpp
  requiredBy: []
  timestamp: '2022-08-15 02:42:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_ntl_1_e.test.cpp
documentation_of: src/math/Extend-GCD.hpp
layout: document
title: "Extend GCD (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
  \u6CD5)"
---

## 概要
```
std::pair<long long, long long> extend_gcd(long long a, long long b)
```

$ax + by = gcd(a, b)$の解を`std::pair<long long>`型で返します。

$gcd(a, b)$ は $a$ と $b$ の最大公約数を指します。


## 機能
```
void rec(long long a, long long b, long long& x, long long& y)
```
を呼び出して求めています。返り値がバグっていたらここがバグっています。多分


## 参考
[拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜](https://qiita.com/drken/items/b97ff231e43bce50199a)

## 計算量
$O(log\ max(a, b))$
