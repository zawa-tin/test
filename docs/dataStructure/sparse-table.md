---
title: sparse-table ( $x \oplus x\ =\ x$ の区間クエリ解答 )
documentation_of: //src/dataStructure/sparse-table.hpp
---

## 概要

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

例: `min`、`max`、`gcd`

## 機能
`sparse_table<structure>(const std::vector<structure::T>& as)`
- コンストラクタ
- `structure`
	- 以下の条件を満たす構造体
		- `using T = OOO`が存在する(演算の型)
		- ２つの`T`型の変数`a, b`を引数にとり、 $a\ \oplus\ b$ を返す`static`メンバ関数`T op(T a, T b)`を持つ
	- 実装例は`test/sparse-table.test.cpp`を確認ください
- `as`
	- クエリを処理したい`structure::T`型の列
- **計算量**: $O(\mid A\mid\log \mid A\mid)$

`structure::T sparse_table::query(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める
- **制約**: $0\ \le\ l\ <\ r\ \le\ \mid A\mid$
- **計算量**: $O(1)$

`const std::vector<std::vector<structure::T>>& sparse_table::get()`
- `private`にある`dat`を返します。
- デバッグ用
