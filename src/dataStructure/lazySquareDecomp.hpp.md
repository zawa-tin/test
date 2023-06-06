---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
    title: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/lazySquareDecomp.hpp\"\n\n#include <vector>\n\
    #include <cmath>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ structure>\nclass lazySquareDecomp {\n\tusing V = typename structure::valueMonoid::valueType;\n\
    \tusing O = typename structure::operatorMonoid::valueType;\n\nprivate:\n\tstatic\
    \ constexpr V vId = structure::valueMonoid::identity;\n\tstatic constexpr O oId\
    \ = structure::operatorMonoid::identity;\n\tstruct node {\n\t\tV value;\n\t\t\
    O lazy;\n\t\tnode() : value(vId), lazy(oId) {}\n\t};\n\tint square;\n\tstd::vector<V>\
    \ dat;\n\tstd::vector<node> bucket;\n\n\tvoid propagate(int pos) {\n\t\tint l\
    \ = square * pos;\n\t\tfor (int i = 0 ; i < square ; i++) {\n\t\t\tdat[l + i]\
    \ = structure::mapping(dat[l + i], bucket[pos].lazy);\t\n\t\t}\n\t\tbucket[pos].lazy\
    \ = oId;\n\t}\n\n\tvoid update(int pos) {\n\t\tbucket[pos].value = vId;\n\t\t\
    int l = square * pos;\n\t\tfor (int i = 0 ; i < square and l + i < (int)dat.size()\
    \ ; i++) {\n\t\t\tbucket[pos].value = structure::valueMonoid::operation(bucket[pos].value,\
    \ dat[l + i]);\n\t\t}\n\t}\n\t\npublic:\n\tlazySquareDecomp(int n) : square(std::sqrt(n\
    \ + 1)), dat(n, vId), bucket((n + square - 1) / square) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i / square].value = structure::valueMonoid::operation(bucket[i\
    \ / square].value, dat[i]);\n\t\t}\n\t}\n\tlazySquareDecomp(const std::vector<V>&\
    \ A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1)\
    \ / square) {\n\t\tfor (std::size_t i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i\
    \ / square].value = structure::valueMonoid::operation(bucket[i / square].value,\
    \ dat[i]);\n\t\t}\n\t}\n\n\tvoid update(int pos, const O& value) {\n\t\tif (bucket[pos\
    \ / square].lazy != oId) {\n\t\t\tpropagate(pos / square);\n\t\t}\n\t\tdat[pos]\
    \ = structure::mapping(dat[pos], value);\n\t\tupdate(pos / square);\n\t}\t\n\n\
    \tvoid update(int l, int r, const O& value) {\t\n\t\tfor (int i = 0 ; i < (int)bucket.size()\
    \ ; i++) {\n\t\t\tint p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p\
    \ or q <= l) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\
    \t\t\tbucket[i].lazy = structure::operatorMonoid::operation(bucket[i].lazy, value);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy != oId) {\n\t\t\t\t\tpropagate(i);\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size()\
    \ }) ; j++) {\n\t\t\t\t\tdat[j] = structure::mapping(dat[j], value);\n\t\t\t\t\
    }\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\t}\n\n\tV prod(int l, int r) {\n\t\tV\
    \ res = vId;\n\t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint\
    \ p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p or q <= l) {\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tres = structure::valueMonoid::operation(res, structure::mapping(bucket[i].value,\
    \ bucket[i].lazy));\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres = structure::valueMonoid::operation(res,\
    \ bucket[i].value);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tpropagate(i);\n\t\t\t\t\tupdate(i);\n\t\t\t\t}\n\t\t\t\t\
    for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {\n\
    \t\t\t\t\tres = structure::valueMonoid::operation(res, dat[j]);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class structure>\nclass lazySquareDecomp {\n\t\
    using V = typename structure::valueMonoid::valueType;\n\tusing O = typename structure::operatorMonoid::valueType;\n\
    \nprivate:\n\tstatic constexpr V vId = structure::valueMonoid::identity;\n\tstatic\
    \ constexpr O oId = structure::operatorMonoid::identity;\n\tstruct node {\n\t\t\
    V value;\n\t\tO lazy;\n\t\tnode() : value(vId), lazy(oId) {}\n\t};\n\tint square;\n\
    \tstd::vector<V> dat;\n\tstd::vector<node> bucket;\n\n\tvoid propagate(int pos)\
    \ {\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ; i < square ; i++) {\n\t\t\
    \tdat[l + i] = structure::mapping(dat[l + i], bucket[pos].lazy);\t\n\t\t}\n\t\t\
    bucket[pos].lazy = oId;\n\t}\n\n\tvoid update(int pos) {\n\t\tbucket[pos].value\
    \ = vId;\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ; i < square and l + i\
    \ < (int)dat.size() ; i++) {\n\t\t\tbucket[pos].value = structure::valueMonoid::operation(bucket[pos].value,\
    \ dat[l + i]);\n\t\t}\n\t}\n\t\npublic:\n\tlazySquareDecomp(int n) : square(std::sqrt(n\
    \ + 1)), dat(n, vId), bucket((n + square - 1) / square) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i / square].value = structure::valueMonoid::operation(bucket[i\
    \ / square].value, dat[i]);\n\t\t}\n\t}\n\tlazySquareDecomp(const std::vector<V>&\
    \ A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1)\
    \ / square) {\n\t\tfor (std::size_t i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i\
    \ / square].value = structure::valueMonoid::operation(bucket[i / square].value,\
    \ dat[i]);\n\t\t}\n\t}\n\n\tvoid update(int pos, const O& value) {\n\t\tif (bucket[pos\
    \ / square].lazy != oId) {\n\t\t\tpropagate(pos / square);\n\t\t}\n\t\tdat[pos]\
    \ = structure::mapping(dat[pos], value);\n\t\tupdate(pos / square);\n\t}\t\n\n\
    \tvoid update(int l, int r, const O& value) {\t\n\t\tfor (int i = 0 ; i < (int)bucket.size()\
    \ ; i++) {\n\t\t\tint p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p\
    \ or q <= l) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\
    \t\t\tbucket[i].lazy = structure::operatorMonoid::operation(bucket[i].lazy, value);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy != oId) {\n\t\t\t\t\tpropagate(i);\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size()\
    \ }) ; j++) {\n\t\t\t\t\tdat[j] = structure::mapping(dat[j], value);\n\t\t\t\t\
    }\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\t}\n\n\tV prod(int l, int r) {\n\t\tV\
    \ res = vId;\n\t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint\
    \ p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p or q <= l) {\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tres = structure::valueMonoid::operation(res, structure::mapping(bucket[i].value,\
    \ bucket[i].lazy));\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres = structure::valueMonoid::operation(res,\
    \ bucket[i].value);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tpropagate(i);\n\t\t\t\t\tupdate(i);\n\t\t\t\t}\n\t\t\t\t\
    for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {\n\
    \t\t\t\t\tres = structure::valueMonoid::operation(res, dat[j]);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/lazySquareDecomp.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazySquareDecomp-AOJ-RAQRmQ.test.cpp
  - test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
  - test/lazySquareDecomp-AOJ-RUQRSQ.test.cpp
  - test/lazySquareDecomp-AOJ-RAQRSQ.test.cpp
documentation_of: src/dataStructure/lazySquareDecomp.hpp
layout: document
title: "lazySquareDecomp (\u533A\u9593\u66F4\u65B0\u53EF\u80FD\u5E73\u65B9\u5206\u5272\
  )"
---

## 前置き
`lazySegmentTree`で同様の処理がより高速にできます。そちらをお使いください。ドキュメントの更新も止まってます。

## 概要

平方分割の手法を用いて列上のクエリを高速に処理するデータ構造です。遅延評価可能であるため、`src/dataStructure/sqdecomp.hpp` と比較して、区間更新が可能となっています

#### 平方分割について

$N$ 要素の列に対して $\sqrt{N}$ の大きさのバケットを $\sqrt{N}$ 個保持し、要素の更新や演算処理に対してバケットを利用する。(詳細: TODO?)

#### クエリについて

**言葉の定義**
- $N$ : 非負整数
- $A$ : 長さ $N$ の列、 $A$ 上でクエリを処理する
- $T$ : $A$ の各要素 $A_i (0\ \le\ i\ <\ n)$ が属する集合
- $\oplus$ : $T$ 上の演算
- $\text{id}_T$ : $T$ の要素、 $\oplus$ の単位元
- $S$ : ある集合
- $f_x\ :\ T\ \rightarrow\ T$ : $x\ \in\ S$ で定義される写像
- $\times$ : $S$ 上で定義される演算
- $\text{id}_S$ : $S$ の要素、 $\times$ の単位元

**要件**
- $(T, \oplus, \text{id}_T)$  は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) を成す
- $(S, \times, \text{id}_S)$ はモノイドを成す
- $f_{\text{id}_S} (v)\ =\ v$ $(v\ \in\ T)$
- $f_x(v_1\oplus v_2)\ =\ f_x(v_1)\ \oplus\ f_x(v_2)$ を満たす(自己準同型)
- $f_{x_1}(f_{x_2}(v))\ =\ f_{x_1\times x_2} (v)$ を満たす

**処理できるクエリ**
- `update l r x` : $l\ \le\ i\ <\ r$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_x(A_i)$
- `prod l r`: $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

## 機能

計算量の表記について、 $\oplus$ や $\times$ の計算量が $O(1)$ であることを仮定しています。 (例えば $\oplus$ や $\times$ が $O(\text{hoge})$ なら計算量が $\text{hoge}$ 倍されます)

**コンストラクタ**

`テンプレート引数 structure`について
- 以下の機能をもたせた`struct`を用意してください
	- `using valueMonoid`: $(T, \oplus, \text{id}_T)$ を表現したモノイド構造体(後述)
	- `using operatorMonoid`: $(S, \times, \text{id}_S)$ を表現したモノイド構造体
	- `static valueMonoid::valueType mapping(const value_monoid::valye_type& v, const operator_monoid::value_type& x)` : $f_x(v)$ を返す関数、`const`参照や値渡しなどを用いること(引数の中身を変更しないように)
- モノイド構造体は以下の機能を持たせてください
	- `using value_type` : $T$ や $S$ の型
	- `static constexpr value_type identity` : $\text{id}_T$ や $\text{id}_S$ といった単位元
	- `static value_type operation(const value_type& a, const value_type& b)`: $a\oplus b$ や $a\times b$ を返す関数。こちらも引数の中身を変更しないように


`zawa::lazy_sqdecomp<structure>(std::size_t n)`:
- $A$ を長さ $N$ 、 各要素を `structure::value_monoid::identity`で初期化する
- **計算量** : $O(N)$

`zawa::lazy_sqdecomp<structure>(const std::vector<structure::value_monoid::value_type>& A)`
- $A$ を `A` で初期化する
- **計算量** : $O(N)$

**メンバ関数**

`structure::value_monoid::value_type`を`T`、`structure::operator_monoid::value_type`を`S`と表記します（長いので）

`void update(int pos, const S& value)`
- $A_{\text{pos}}\ \leftarrow\ f_{\text{value}} (A_{\text{pos}})$ とする
- **テストをしていません**
- **計算量** : $O(\sqrt{N})$

`void update(int l, int r, const S value)`
- $l\ \le\ i\ <\ r$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_{\text{value}}(A_i)$ とする
- **計算量** : $O(\sqrt{N})$

`T prod(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める
- **計算量** : $O(\sqrt{N})$

## 参考

[SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)


[セグメント木をあきらめた人のための平方分割](https://kujira16.hateblo.jp/entry/2016/12/15/000000)
