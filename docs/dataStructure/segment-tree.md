---
title: segment tree (一点変更・区間演算)
documentation_of: //src/dataStructure/segment-tree.hpp
---

## 概要

何の変哲も無いただのセグ木です。

 数列 $A$ に対する以下のクエリを処理できます。

- $A$ の単一要素を変更する
- $1\ \le\ l\ <\ r\ \le\ \mid A\mid$ に対して $A_l \oplus A_{l + 1} \oplus \dots \oplus A_{r - 1}$

ただし、 $A$ の各要素を含む集合 $S$ とクエリで飛んでくる演算 $\oplus$ について、組 $(S, \oplus)$ は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります。


## 機能

- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(std::size_t n)`
- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(const std::vector<T>& as)`
	-	`コンストラクタ`
	-	`T` は $A$ の型
	-	`op`は 二項演算(`T` 型の変数二つを引数にとり、その演算結果を`T`型で返す関数)
	-	`e` は単位元(引数を取らず、単位元を`T`型で返す関数)
	- `n`は $A$ の要素数、こちらで宣言した場合、 $A$ の全ての要素が`e()`で初期化される
	- `as` は $A$ を表す`vector`
	- **計算量**: $O(n)$

- `void seg.set(int pos, T val)`
	- $A_{\text{pos}}$ に `val` を代入する
	- $0\ \le\ \text{pos}\ <\ n$
	- **計算量** $O(\log n)$

- `void seg.apply(int pos, T val)`
	- $A_{\text{pos}}$ に $A_{\text{pos}} \oplus \text{val}$ を代入する。
	- $0\ \le\ \text{pos}\ <\ n$
	- **計算量** : $O(\log n)$

- `T query(int l, int r)`
	- $A_l \oplus A_{l + 1} \oplus \dots \oplus A_{r - 1}$ を計算します。
	- $0\ \le\ l\ <\ r\ \le\ n$
	- **計算量** $O(\log n)$

## 参考
[非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
