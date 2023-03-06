---
title: sparseTable ( $x \oplus x\ =\ x$ の区間クエリ解答 )
documentation_of: //src/dataStructure/sparseTable.hpp
---

## 概要

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

例: `min`、`max`、`gcd`

## 機能

**コンストラクタ**

以下、`structure::valueType`を`T`と省略する。
```
sparseTable<structure>(const std::vector<T>& A)
```
$A$ を引数の`std::vector<T>`で初期化する

テンプレート引数`structure`は以下を満たす構造体にしてください
- $A$ の型を`using valueType = `でエイリアスする
- 演算 $\oplus$ を表現する`static valueType operation(const valueType& a, const valueType& b)` 関数

**計算量**

$O(\mid A\mid \log \mid A \mid)$

<br />

**メンバ**

**query**
```
T query(int l, int r)
```

$\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

**制約**

$0\ \le\ l\ <\ r\ \le\ \mid A\mid$

**計算量**

$O(1)$

<br />

**_dat**
```
const std::vector<std::vector<T>>& _dat()
```
- 内部のコンテナを返します。デバッグにでも
