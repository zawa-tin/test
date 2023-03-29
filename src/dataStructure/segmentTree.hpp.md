---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AGC005-B.test.cpp
    title: test/AGC005-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ALPC-J.test.cpp
    title: test/ALPC-J.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-AOJ-RSQ.test.cpp
    title: test/segmentTree-AOJ-RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-AOJ-RmQ.test.cpp
    title: test/segmentTree-AOJ-RmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segmentTree-RXQ.test.cpp
    title: test/segmentTree-RXQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/segmentTree.hpp\"\n\n#include <vector>\n\
    #include <functional>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass segmentTree\
    \ {\nprivate:\n\tusing V = typename monoid::valueType;\n\tstd::size_t N;\n\tstd::vector<V>\
    \ dat;\n\npublic:\n\tsegmentTree() {}\n\tsegmentTree(int _N) : N(_N), dat(2 *\
    \ _N, monoid::identity) {}\n\tsegmentTree(const std::vector<V>& A) : N(A.size()),\
    \ dat(2 * N, monoid::identity) {\n\t\tfor (std::size_t i = 0 ; i < A.size() ;\
    \ i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t\tfor (std::size_t i = N - 1 ; i\
    \ > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i << 1], dat[i << 1 | 1]);\t\
    \t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const V& value) {\n\t\tpos += N;\n\
    \t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\t\t\tdat[pos] = monoid::operation(dat[pos\
    \ << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\tV update(std::size_t pos, const\
    \ V& value) {\n\t\tpos += N;\n\t\tdo {\n\t\t\tdat[pos] = monoid::operation(dat[pos],\
    \ value);\n\t\t} while (pos >>= 1);\n\t\treturn dat[pos];\n\t}\n\n\tV prod(std::size_t\
    \ l, std::size_t r) const {\n\t\tV left = monoid::identity, right = monoid::identity;\n\
    \t\tfor (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tleft = monoid::operation(left, dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\
    \t\t\t\tright = monoid::operation(dat[--r], right);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ monoid::operation(left, right);\n\t}\n\n\ttemplate <class functionType>\n\t\
    int maxRight(int l, const functionType& f) const {\n\t\tint L = l + N, w = 1;\n\
    \t\tV v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\
    \t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\
    \tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile (L <<= 1, w >>=\
    \ 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {\n\t\t\
    \t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\t}\n\t\t\
    return l;\n\t}\n\n\ttemplate <class functionType>\n\tint minLeft(int r, const\
    \ functionType& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tV v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n\nnamespace zawa\
    \ {\n\ntemplate <class monoid>\nclass segmentTree {\nprivate:\n\tusing V = typename\
    \ monoid::valueType;\n\tstd::size_t N;\n\tstd::vector<V> dat;\n\npublic:\n\tsegmentTree()\
    \ {}\n\tsegmentTree(int _N) : N(_N), dat(2 * _N, monoid::identity) {}\n\tsegmentTree(const\
    \ std::vector<V>& A) : N(A.size()), dat(2 * N, monoid::identity) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t\tfor (std::size_t\
    \ i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i << 1], dat[i\
    \ << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const V& value) {\n\
    \t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\t\t\tdat[pos]\
    \ = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\tV update(std::size_t\
    \ pos, const V& value) {\n\t\tpos += N;\n\t\tdo {\n\t\t\tdat[pos] = monoid::operation(dat[pos],\
    \ value);\n\t\t} while (pos >>= 1);\n\t\treturn dat[pos];\n\t}\n\n\tV prod(std::size_t\
    \ l, std::size_t r) const {\n\t\tV left = monoid::identity, right = monoid::identity;\n\
    \t\tfor (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tleft = monoid::operation(left, dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\
    \t\t\t\tright = monoid::operation(dat[--r], right);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ monoid::operation(left, right);\n\t}\n\n\ttemplate <class functionType>\n\t\
    int maxRight(int l, const functionType& f) const {\n\t\tint L = l + N, w = 1;\n\
    \t\tV v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\
    \t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\
    \tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile (L <<= 1, w >>=\
    \ 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {\n\t\t\
    \t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\t}\n\t\t\
    return l;\n\t}\n\n\ttemplate <class functionType>\n\tint minLeft(int r, const\
    \ functionType& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tV v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/segmentTree.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AGC005-B.test.cpp
  - test/segmentTree-AOJ-RmQ.test.cpp
  - test/segmentTree-RXQ.test.cpp
  - test/ALPC-J.test.cpp
  - test/segmentTree-AOJ-RSQ.test.cpp
documentation_of: src/dataStructure/segmentTree.hpp
layout: document
title: "segmentTree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u6F14\u7B97\u30BB\u30B0\
  \u6728)"
---

## 概要

セグメント木を用いて列上のクエリを高速を処理します。

#### セグメント木について

2冪の区間についての区間和を保持することで要素の更新に $\log$ かけるかわりに任意の区間和を $\log$ にする。
- 詳しくはTODO?

#### クエリについて

[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) $(S, \oplus, \text{id})$ と $S$ の要素からなる長さ $N$ の数列 $A$ について

- `set i p`: $A_i\ \leftarrow\ p$
- `action i p`: $A_i\ \leftarrow A_i \oplus p$
- `prod l r` : get $\displaystyle \bigoplus_{i = l}^r A_i$

のクエリを処理することができる

## 機能

#### コンストラクタ

```
(1) zawa::segmentTree<monoid>()
(2) zawa::segmentTree<monoid>(int _N)
(3) zawa::segmentTree<monoid>(const std::vector<monoid::valueType>& A)
```

テンプレート引数`monoid`について
- 以下の機能をもたせた`struct`を用意してください
	- `using value_type`: $S$ の型
	- `static constexpr value_type identity` : モノイドの単位元 $\text{id}$
	- `static value_type operation(const value_type& a, const value_type& b)`: $a\oplus b$ を返す関数

**(1)**
デフォルトコンストラクタ

<br />

**(2)**

$A$ を長さ $N$ で各要素を`monoid::identity`で初期化する

**計算量**

$O(N)$

<br />

**(3)**

$A$ を引数に与えた `std::vector`で初期化する

**計算量**

$O(\mid A\mid)$

以降、 $\mid A \mid\ =\ N$ とする

<br />

#### メンバ関数

**set**
```
void set(std::size_t pos, const monoid::value_type& value)
```

$A_{\text{pos}}\ \leftarrow\ \text{value}$ とする

**制約**

$0\ \le\ \text{pos}\ <\ N$

**計算量**

$O(\log N)$

<br />

**update**
```
T update(std::size_t pos, const monoid::value_type& value)
```

$A_{\text{pos}}\ \leftarrow\ A_{\text{pos}} \oplus \text{value}$ とする

**制約**

$0\ \le\ \text{pos}\ <\ N$

**計算量**

$O(\log N)$

<br />

**prod**
```
T prod(std::size_t l, std::size_t r) const
```
$\displaystyle \bigoplus_{i = l}^r A_i$  を返す

**制約**

$0\ \le\ l\ <\ N$

$l\ \le\ r\ \le\ N$

**計算量**

$O(\log N)$

<br />

**maxRight**
```
int maxRight<functionType>(int l, const function_type& f) const
```

単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最小の $r$ を返す。


`functionType`は`std::function<bool(monoid::value_type)>`

**制約**

$0\ \le\ l\ <\ N$

**計算量**

$O(\log N)$

<br />

**minLeft**
```
int min_left<functionType>(int r, const function_type& f) const
```

単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最大の $l$ を返す。

`functionType`は`std::function<bool(monoid::value_type)>`

**制約**

$0\ \le\ r\ <\ N$

**計算量** 

$O(\log N)$

<br />

##  参考

- [お手軽非再帰 Segment Tree の書き方](https://hackmd.io/@tatyam-prime/rkA5wJMdo)
- [非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
