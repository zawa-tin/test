---
title: Binary-Coeff (二項係数 Mod)
documentation_of: //src/math/Binary-Coeff-Mod.hpp
---

## 概要
```
zawa::Binary_Coeff<mod>(int n)
```

サイズ $n$ の階乗テーブルと逆元の階乗テーブルを作成します。


## 機能
- `コンストラクタ`: 最大サイズを入れてください。
- `query(int n, int r, bool check = true)`: $\binom{n}{r}$ を計算します。
	- `check`を`true`にしていると範囲外参照時に-1を返します


## 計算量
- `コンストラクタ` : $O(N)$
- `query`: $O(1)$
