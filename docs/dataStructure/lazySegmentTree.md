---
title: lazySegmentTree (区間更新・区間和セグ木)
documentation_of: //src/dataStructure/lazySegmentTree.hpp
---

## 概要

セグメント木を用いて列上のクエリを処理します。

#### セグメント木について

2冪の区間についての総積を常に保持して置くことで更新に $\log$ かけるかわりに区間総積取得も $\log$ で可能にする
- 詳しくはTODO？

#### クエリについて

**言葉の定義**

- $N$ : 正整数

- $A$ : 長さ $N$ の列、 $A$ 上でクエリを処理する

- $V$ : $A$ の各要素 $A_i (0\ \le\ i\ <\ n)$ が属する集合

- $\oplus$ : $V$ 上の演算

- $\text{id}_V$ : $V$ の要素、 $\oplus$ の単位元

- $O$ : ある集合

- $f_x\ :\ V\ \rightarrow\ V$ : $x\ \in\ O$ で定義される写像

- $\times$ : $O$ 上で定義される演算

- $\text{id}_O$ : $O$ の要素、 $\times$ の単位元

**要件**

- $(V, \oplus, \text{id}_V)$ は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) を成す

- $(O, \times, \text{id}_O)$ はモノイドを成す

- $f_{\text{id}_O} (v)\ =\ v$ $(v\ \in\ V)$

- $f_x(v_1\oplus v_2)\ =\ f_x(v_1)\ \oplus\ f_x(v_2)$ を満たす(自己準同型)

- $f_{x_1}(f_{x_2}(v))\ =\ f_{x_1\times x_2} (v)$ を満たす

**処理できるクエリ**

- `update l r x` : $l\ \le\ i\ <\ r$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_x(A_i)$

- `prod l r`: $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

##  機能

計算量の表記について、 $\oplus$ や $\times$ が定数時間で計算できることを仮定しています。 (例えば $\oplus$ や $\times$ が $O(\text{hoge})$ なら計算量が $\text{hoge}$ 倍されます)

以下の略称を使います
```
structure::value_monoid -> VM
structure::value_monoid::value_type -> Vtype
structure::operator_monoid -> OM
structure::operator_monoid::value_type -> Otype
```

#### コンストラクタ

```
(1) lazySegmentTree<structure>(std::size_t _N)
(2) lazySegmentTree<structure>(const std::vector<Vtype>& A)
```

(1) $A$ を長さ $N$ の各要素が`VM::identity`である列で初期化します

**制約**: $0\ <\ N$

**計算量** : $O(N)$

(2) $A$ を引数の列`A`で初期化します。

**制約**: `A.empty()`が`false`

**計算量** : $O(N)$

<br />

#### テンプレート引数structureについて

以下の要件を満たす構造体を入れてください
- `using valueMonoid`: $(V, \oplus, \text{id}_V)$ を表現した構造体(後述)
- `using operatorMonoid`:  $(O, \times, \text{id}_O)$ を表現した構造体(後述)
- `static VM mapping(const VM& a, const OM& b)`: $f_b (a)$ を返す関数

`valueMonoid`や`operatorMonoid`を表現する構造体として以下の機能を要求します。
- `using vale_type`: $V$ や $O$ の型
- `static constexpr valueType identity`: $\text{id}_V$ や $\text{id}_O$
- `static valueType operation(const valueType& a, const valueType& b)`: $a \oplus b$ や $a \times b$ を返す関数

実装例はテスト等を確認ください

<br />

#### メンバ

**update**
```
void update(std::size_t L, std::size_t R, const Otype& value)
```

$L\ \le\ i\ <\ R$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_{\text{value}}(A_i)$ とする

**制約** : $0\ \le\ L\ <\ R\ \le\ N$

**計算量** : $O(\log N)$

<br />

**prod**
```
Vtype prod(std::size_t L, std:;size_t R)
```

$\displaystyle \bigoplus_{i = L}^{R - 1} A_i$ を求める

**制約**: 

$0\ \le\ L\ <\ N$

$L\ \le\ R\ \le\ N$

**計算量**: $O(\log N)$

<br />

**maxRight**

TODO

<br />

**minLeft**

TODO

<br />

## 参考

[SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)

[遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)

[AC Library](https://atcoder.github.io/ac-library/document_ja/lazysegtree.html)
