---
title: Fenwick Tree (一点可算・区間和取得)
documentation_of: //src/dataStructure/Fenwick-Tree.hpp
---

## 概要
```
Fenwick_Tree<T>(int n)
```

Fenwick Treeです。Binary Indexed Tree ともいいます。

累積和に対して値の変更が来た場合でも高速に部分和を正しく取り出せます。

## 機能
- `コンストラクタ`: 配列の要素数を引数に入れてください。

- `add(int id, T val)`: `id`番目の要素に`val`を可算します。
	- `0-indexed`で入れてください

- `query(int l, int r)`: `l`番目の要素から`r`番目の要素までの総和を取得します。
	- `0-indexed`で入れてください

- `lower_bound(T val)`: `query(0, i) >= w`となる最小の`i`を返します。


## 計算量
-	`add, query, lower_bound`:  要素数 $N$ に対して $O(logN)$
