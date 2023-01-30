---
title: fenwick_set (動的集合)
documentation_of: //src/dataStructure/fenwick_set.hpp
---

## 概要

`fenwick_tree`による集合 $S$ の管理を提供します。ただし、集合の各要素は $0\ \le\ i\ <\ n$ という制約があります。

以下の手続きが行えます。
- `insert x`: $S\ \leftarrow\ x$
- `erase x`: $S$ から $x$ を削除する
- `count l r`: $S$ 内で $l$ 以上 $r$ 未満である要素の数を数える
- `contain x`: $S$ に $x$ が含まれるか判定する
- `kth_element`: $S$ で $k$ 番目に大きい要素を報告する

## 機能

**コンストラクタ**

`zawa::fenwick_set(std::size_t n)`
- `n`: $n$
- 空集合で初期化します

**メンバ関数**

`void insert(int x)`
- $x$ を挿入します。
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`bool erase(x)`
- $x$ を $S$ から削除します
- もともと要素が存在しなかった場合、`false`を返します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`bool contain(x)`
- $x$ が $S$ に含まれているかを判定します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(1)$

`int count(int l, int r)`
- $l$ 以上 $r$ 未満の要素の数を数えます
- **制約** : $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int kth_elemnt(int k)`
- $S$ で $k$ 番目に大きい要素を報告します
- $\mid S\mid\ < k$ の場合、 $n$ が返されます
- **計算量** : $O(\log n)$
