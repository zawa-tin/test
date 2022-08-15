---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_itp1_3_d.test.cpp
    title: test/aoj_itp1_3_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Divisor.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\n    std::vector<long long> divisor(long long x) {\n    \
    \    std::vector<long long> res;\n\n        for (long long i = 1 ; i * i <= x\
    \ ; i++) {\n            if (x % i) continue;\n            res.emplace_back(i);\n\
    \            if (i * i != x) res.emplace_back(x / i);\n        }\n        std::sort(res.begin(),\
    \ res.end());\n\n        return res;\n    }\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\n    std::vector<long long> divisor(long long x) {\n        std::vector<long\
    \ long> res;\n\n        for (long long i = 1 ; i * i <= x ; i++) {\n         \
    \   if (x % i) continue;\n            res.emplace_back(i);\n            if (i\
    \ * i != x) res.emplace_back(x / i);\n        }\n        std::sort(res.begin(),\
    \ res.end());\n\n        return res;\n    }\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Divisor.hpp
  requiredBy: []
  timestamp: '2022-08-15 18:33:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_itp1_3_d.test.cpp
documentation_of: src/math/Divisor.hpp
layout: document
title: "Divisor(\u7D04\u6570\u5217\u6319)"
---

## 概要
```
std::vector<long long> divisor(long long x)
```

試し割りを用いた素朴な約数列挙


### 機能
* `divisor(long long x)`: xを約数列挙します。xは64ビットに収まる0以上の整数である必要があります。


### 計算量
- $O(\sqrt(x))$ 
