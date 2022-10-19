---
title: Sparse-Table ( $x \oplus x\ =\ x$ の区間クエリ解答 )
documentation_of: //src/dataStructure/Sparse-Table.hpp
---

## 概要

```
template<class T, T (*op)(T, T)>
Sparse_Table(std::vector<T>)
```

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

## 機能
 - `コンストラクタ`: テンプレート引数に型と演算 $\oplus$ を入れてくだださい（関数ポインタってやつ？、ACLのsegtreeと同じノリ)
- `query(int int)`:  半開区間で入れてください

## 計算量

- `コンストラクタ`: $O(N \log N)$
- `query`: $O(\log N)$ <-は？
	- TODO: $O(1)$ にする
