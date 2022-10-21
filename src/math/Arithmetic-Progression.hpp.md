---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Arithmetic-Progression.test.cpp
    title: test/Arithmetic-Progression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/Arithmetic-Progression.hpp\"\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass Arithmetic_Progression {\nprivate:\n    T first_term;\n\
    \    T common_difference;\n\n    T term(T n) {\n        return first_term + (n\
    \ - 1) * common_difference;\n    }\n    \n    T sum(T n) {\n        T end_term\
    \ = term(n);\n        if (n & 1) {\n            return ((first_term + end_term)\
    \ / 2) * n;\n        }\n        else {\n            return (n / 2) * (first_term\
    \ + end_term);\n        }\n    }\n\npublic:\n    Arithmetic_Progression(T s, T\
    \ d)\n        : first_term(s), common_difference(d) {}\n\n    T get(T n) {\n \
    \       if (n <= 0) {\n            return 0;\n        }\n        return term(n);\n\
    \    }\n\n    T accumulate(T l, T r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class T>\nclass Arithmetic_Progression\
    \ {\nprivate:\n    T first_term;\n    T common_difference;\n\n    T term(T n)\
    \ {\n        return first_term + (n - 1) * common_difference;\n    }\n    \n \
    \   T sum(T n) {\n        T end_term = term(n);\n        if (n & 1) {\n      \
    \      return ((first_term + end_term) / 2) * n;\n        }\n        else {\n\
    \            return (n / 2) * (first_term + end_term);\n        }\n    }\n\npublic:\n\
    \    Arithmetic_Progression(T s, T d)\n        : first_term(s), common_difference(d)\
    \ {}\n\n    T get(T n) {\n        if (n <= 0) {\n            return 0;\n     \
    \   }\n        return term(n);\n    }\n\n    T accumulate(T l, T r) {\n      \
    \  return sum(r) - sum(l - 1);\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/Arithmetic-Progression.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:30:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Arithmetic-Progression.test.cpp
documentation_of: src/math/Arithmetic-Progression.hpp
layout: document
title: "Arithmetic Progression (\u7B49\u5DEE\u6570\u5217)"
---

## 概要
```
Arithmetic_Progression<T>(T first_term, T common_difference)
```

等差数列を扱います
- 初項と公差から一般項と区間和をだします

## 機能
- `コンストラクタ`: 初項と公差を引数に入れてください
- `get(T n)`: 第 $n$ 項を返します(1-indexed)
    - 0以下の数に対しては0を返します
- `accumulate(T l, T r)`: 第 $l$ 項目から第 $r$ 項目までの和を返します

## 計算量

$O(1)$
