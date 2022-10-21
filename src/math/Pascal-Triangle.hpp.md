---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Pascal-Triangle.test.cpp
    title: test/Pascal-Triangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Pascal-Triangle.hpp\"\n\n#include <vector>\n\n\
    namespace zawa {\n\ntemplate <class T>\nclass Pascal_Triangle {\nprivate:\n  \
    \  std::vector<std::vector<T>> table;\npublic:\n    Pascal_Triangle(int max_n,\
    \ int max_r)\n        : table(max_n + 1, std::vector<T>(max_r + 1)) {\n      \
    \  table[0][0] = 1;\n        for (int i = 1 ; i <= max_n ; i++) {\n          \
    \  for (int j = 1 ; j <= max_r ; j++) {\n                table[i][j] = table[i\
    \ - 1][j - 1] + table[i - 1][j];\n            }\n        }\n    }\n\n    T ncr(int\
    \ n, int r) {\n        return table.at(n).at(r);\n    }\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass Pascal_Triangle {\nprivate:\n    std::vector<std::vector<T>> table;\n\
    public:\n    Pascal_Triangle(int max_n, int max_r)\n        : table(max_n + 1,\
    \ std::vector<T>(max_r + 1)) {\n        table[0][0] = 1;\n        for (int i =\
    \ 1 ; i <= max_n ; i++) {\n            for (int j = 1 ; j <= max_r ; j++) {\n\
    \                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];\n      \
    \      }\n        }\n    }\n\n    T ncr(int n, int r) {\n        return table.at(n).at(r);\n\
    \    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Pascal-Triangle.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:48:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Pascal-Triangle.test.cpp
documentation_of: src/math/Pascal-Triangle.hpp
layout: document
title: "Pascal's Triangle (\u30CA\u30A4\u30FC\u30D6\u306A\u4E8C\u9805\u4FC2\u6570\u30C6\
  \u30FC\u30D6\u30EB)"
---

## 概要
```
Pascal_Triangle<T>(int max_n, int max_r)
```

愚直に二項係数テーブルを構築する

## 機能
- `コンストラクタ`: $\dbinom{n}{r}$ について、使いたい最大の $n$ と $r$  を引数にとる
- `ncr(int n, int r)`: $\dbinom{n}{r}$ を返す

## 計算量
- テーブル構築 $O(NR)$
- 取得 $O(1)$
