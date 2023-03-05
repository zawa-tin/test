---
title: dualSegmentTree (区間更新一点取得セグ木)
documentation_of: //src/dataStructure/dualSegmentTree.hpp
---

## 概要

セグメント木を用いて列上のクエリを高速に処理する

**セグメント木とは？**
- TODO


**どのようなクエリを処理できますか？**

[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) $(S, \oplus, \text{id})$ と $S$ 上で定義される列 $A$ について

- $A$ の連続する区間 $[l, r)$ に属する値に $\oplus$ を適用する
- $A$ のある値を取得する

が可能

## 機能

#### コンストラクタ

以下`monoid::value_type`を`O`と呼ぶ

```
(1) zawa::dualSegmentTree<monoid>()
(2) zawa::dualSegmentTree<monoid>(int _N)
(3) zawa::dualSegmentTree<monoid>(const std::vector<monoid::value_type>& A)
```

**(1)**

デフォルトコンストラクタ

**(2)**

$A$ を $\text{id}$ で初期化する

**(3)**

$A$ を引数に与える

テンプレート引数`monoid`について、以下の要件を満たす構造体を用意してください
- `using value_type = Sの型`がある
- `statc constexpr value_type identity` が定義されている $(\text{id})$
- `static value_type operation(const value_type& a, const value_type& b)` が定義されている $(\oplus)$

**制約**

$\mid A\mid\ >\ 0$

**計算量**

(2)、(3)ともに $O(\mid A\mid)$

<br />

#### operator

**[]**
```
O operator[] (int i)
```

$A_i$ を取得する

**制約**

$0\ \le\ i\ <\ \mid A\mid$


**計算量**

$O(\log \mid A\mid)$

<br />

#### メンバ

**set**
```
void set(int i, const O& value)
```
 $A_i$ に `value`を代入する

**未テスト**

**制約**

$0\ \le\ i\ <\ \mid A\mid$

**計算量**

$O(\log \mid A\mid)$

<br />

**update**
```
(1) void update(int i, const O& value)
(2) void update(int l, int r, const O& value)
```

(1) $A_i$ に $A_i\oplus \text{value}$ を代入する
- **未テスト**

(2) $l\ \le\ i\ <\ r$ について $A_i$ に $A_i\oplus \text{value}$ を代入する

**制約**

- $0\ \le\ i, l\ <\ \mid A\mid$
- $l\ \le\ r\ \le\ \mid A\mid$


**計算量**

$O(\log \mid A\mid)$
