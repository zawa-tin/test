---
title: fenwick_multiset (動的多重集合)
documentation_of: //src/dataStructure/fenwick_multiset.hpp
---

## 概要

`fenwick_tree`による多重集合 $S$ の管理を提供します。ただし、集合の各要素は $0\ \le\ i\ <\ n$ という制約があります。

以下の手続きが行えます。
- `insert x cnt`: $S\ \leftarrow\ x$ を `cnt`回行う
- `erase x cnt`: $S$ から $x$ を`cnt`個削除する
- `count l r`: $S$ 内で $l$ 以上 $r$ 未満である要素の数を数える
- `contain x`: $S$ に $x$ が含まれるか判定する
- `kth_element`: $S$ で $k$ 番目に大きい要素を報告する

## 機能

**コンストラクタ**

`zawa::fenwick_multiset<T>(std::size_t n)`
- `n`: $n$
- 空集合で初期化します
- `T`は`int`や`long long`など挿入する要素に対してオーバーフローしないように指定する

**メンバ関数**

`void insert(int x)`
- $x$ を挿入します。
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`void insert(int x, const T& cnt)`
- $x$ を `cnt`個挿入する
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T erase(int x)`
- $x$ を $S$ から1つ削除します
- もともと要素が存在しなかった場合、`0`を、そうでない場合`1`を返します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T erase(int x, const T& cnt)`
- $x$ を最大 `cnt`個削除する
- 削除した個数を返します
- **まだテストをしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T count(int x)`:
- $S$ に含まれる $x$ の個数を返します
- **まだテストをしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(1)$

`T count(int l, int r)`
- $l$ 以上 $r$ 未満の要素の数を数えます
- **制約** : $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int kth_elemnt(int k)`
- $S$ で $k$ 番目に大きい要素を報告します
- $\mid S\mid\ < k$ の場合、 $n$ が返されます
- **まだテストをしていません**
- **計算量** : $O(\log n)$
