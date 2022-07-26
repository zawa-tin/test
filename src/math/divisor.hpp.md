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
  bundledCode: "#line 2 \"src/math/divisor.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\n    std::vector<int> divisor(int x) {\n        std::vector<int>\
    \ res;\n\n        for (int i = 1 ; i*i <= x ; i++) {\n            if (x % i) continue;\n\
    \            res.emplace_back(i);\n            if (i*i != x) res.emplace_back(x\
    \ / i);\n        }\n        std::sort(res.begin(), res.end());\n\n        return\
    \ res;\n    }\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\n    std::vector<int> divisor(int x) {\n        std::vector<int> res;\n\n\
    \        for (int i = 1 ; i*i <= x ; i++) {\n            if (x % i) continue;\n\
    \            res.emplace_back(i);\n            if (i*i != x) res.emplace_back(x\
    \ / i);\n        }\n        std::sort(res.begin(), res.end());\n\n        return\
    \ res;\n    }\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor.hpp
  requiredBy: []
  timestamp: '2022-07-24 02:03:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_itp1_3_d.test.cpp
documentation_of: src/math/divisor.hpp
layout: document
title: Divisor
---

## 関数
```
std::vector<int> divisor(int x)
```


試し割りを用いた素朴な約数列挙


### 制約
- $x \le 10^9$

### 計算量
- $O(\sqrt(x))$ 
