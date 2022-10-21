---
title: Pascal's Triangle (ナイーブな二項係数テーブル)
documentation_of: //src/math/Pascal-Triangle.hpp
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
