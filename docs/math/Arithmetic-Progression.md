---
title: Arithmetic Progression (等差数列)
documentation_of: //src/math/Arithmetic-Progression.hpp
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
