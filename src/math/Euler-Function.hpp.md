---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/factorize.hpp
    title: "Factorize(\u7D20\u56E0\u6570\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_ntl_1_d.test.cpp
    title: test/aoj_ntl_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Euler-Function.hpp\"\n\n#line 2 \"src/math/factorize.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\n    std::vector<std::pair<long long,\
    \ int>> factorize(long long x) {\n        std::vector<std::pair<long long, int>>\
    \ res;\n\n        for (long long i = 2 ; i * i <= x ; i++) {\n            if (x\
    \ % i) continue;\n            int cnt = 0;\n            while (!(x % i)) {\n \
    \               cnt++;\n                x /= i;\n            }\n            res.emplace_back(i,\
    \ cnt);\n        }\n        if (x != 1) res.emplace_back(x, 1);\n\n        return\
    \ res;\n    }\n\n} // namespace zawa\n#line 4 \"src/math/Euler-Function.hpp\"\n\
    \nnamespace zawa {\n    \n    long long euler_function(long long x) {\n      \
    \  long long res = x;\n\n        for (auto v : zawa::factorize(x)) {\n       \
    \     res /= v.first;\n            res *= v.first - 1;\n        }\n\n        return\
    \ res;\n    }\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include \"factorize.hpp\"\n\nnamespace zawa {\n    \n  \
    \  long long euler_function(long long x) {\n        long long res = x;\n\n   \
    \     for (auto v : zawa::factorize(x)) {\n            res /= v.first;\n     \
    \       res *= v.first - 1;\n        }\n\n        return res;\n    }\n\n}// namespace\
    \ zawa\n"
  dependsOn:
  - src/math/factorize.hpp
  isVerificationFile: false
  path: src/math/Euler-Function.hpp
  requiredBy: []
  timestamp: '2022-08-12 22:24:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_ntl_1_d.test.cpp
documentation_of: src/math/Euler-Function.hpp
layout: document
title: "Euler Function(\u30AA\u30A4\u30E9\u30FC\u95A2\u6570)"
---

## 概要

```
long long euler_function(long long x)
```

引数 $x$ に対して $x$ 以下の正整数の中で $x$ と互いに素なものの個数を返します。


## 機能
64bit整数に収まる正整数をいれてください。

内部で `zawa::factorize(x)`を呼び出しています。

## 計算量
$O(\sqrt{x})$
