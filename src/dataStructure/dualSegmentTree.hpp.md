---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC179-F.test.cpp
    title: test/ABC179-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC291-F.test.cpp
    title: test/ABC291-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/dualSegmentTree-AOJRAQ.test.cpp
    title: test/dualSegmentTree-AOJRAQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/practice90-037.test.cpp
    title: test/practice90-037.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/dualSegmentTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass dualSegmentTree\
    \ {\nprivate:\n\tusing O = typename monoid::value_type;\n\tint N;\n\tstd::vector<O>\
    \ dat;\n\n\tconstexpr int left(int v) const {\n\t\treturn v << 1;\n\t}\n\n\tconstexpr\
    \ int right(int v) const {\n\t\treturn v << 1 | 1;\n\t}\n\n\tconstexpr int parent(int\
    \ v) const {\n\t\treturn v >> 1;\n\t}\n\n\tinline void propagate(int v) {\n\t\t\
    if (left(v) < (int)dat.size()) {\n\t\t\tdat[left(v)] = monoid::operation(dat[left(v)],\
    \ dat[v]);\n\t\t}\n\t\tif (right(v) < (int)dat.size()) {\n\t\t\tdat[right(v)]\
    \ = monoid::operation(dat[right(v)], dat[v]);\n\t\t}\n\t\tdat[v] = monoid::identity;\n\
    \t}\n\n\tvoid push(int v) {\n\t\tint height = 31 - __builtin_clz(v);\n\t\tfor\
    \ (int i = height ; i >= 1 ; i--) {\n\t\t\tpropagate(v >> i);\n\t\t}\n\t}\n\n\
    public:\n\tdualSegmentTree() {}\n\tdualSegmentTree(int _N) : N(_N), dat(_N <<\
    \ 1, monoid::identity) {}\n\tdualSegmentTree(const std::vector<O>& A) : N((int)A.size()),\
    \ dat(A.size() << 1, monoid::identity) {\n\t\tfor (int i = 0 ; i < (int)A.size()\
    \ ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t}\n\n\tO operator[](int i) {\n\t\
    \tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\treturn dat[i];\n\t\
    }\n\n\tvoid set(int i, const O& value) {\n\t\tassert(0 <= i and i < N);\n\t\t\
    i += N;\n\t\tpush(i);\n\t\tdat[i] = value;\n\t}\n\n\tvoid update(int i, const\
    \ O& value) {\n\t\tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\t\
    dat[i] = monoid::operation(dat[i], value);\n\t}\n\n\tvoid update(int l, int r,\
    \ const O& value) {\n\t\tassert(0 <= l and l < N);\n\t\tassert(l <= r and r <=\
    \ N);\n\t\tif (l == r) {\n\t\t\treturn;\n\t\t}\n\t\tl += N; r += N;\n\t\tpush(l);\
    \ push(r - 1);\n\t\tfor ( ; l < r ; l = parent(l), r = parent(r)) {\n\t\t\tif\
    \ (l & 1) {\n\t\t\t\tdat[l] = monoid::operation(dat[l], value);\n\t\t\t\tl++;\n\
    \t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tdat[r] = monoid::operation(dat[r],\
    \ value);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline std::vector<O> _dat() const {\n\t\t\
    return dat;\n\t}\n};\n\n} // namespace \n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\
    \ntemplate <class monoid>\nclass dualSegmentTree {\nprivate:\n\tusing O = typename\
    \ monoid::value_type;\n\tint N;\n\tstd::vector<O> dat;\n\n\tconstexpr int left(int\
    \ v) const {\n\t\treturn v << 1;\n\t}\n\n\tconstexpr int right(int v) const {\n\
    \t\treturn v << 1 | 1;\n\t}\n\n\tconstexpr int parent(int v) const {\n\t\treturn\
    \ v >> 1;\n\t}\n\n\tinline void propagate(int v) {\n\t\tif (left(v) < (int)dat.size())\
    \ {\n\t\t\tdat[left(v)] = monoid::operation(dat[left(v)], dat[v]);\n\t\t}\n\t\t\
    if (right(v) < (int)dat.size()) {\n\t\t\tdat[right(v)] = monoid::operation(dat[right(v)],\
    \ dat[v]);\n\t\t}\n\t\tdat[v] = monoid::identity;\n\t}\n\n\tvoid push(int v) {\n\
    \t\tint height = 31 - __builtin_clz(v);\n\t\tfor (int i = height ; i >= 1 ; i--)\
    \ {\n\t\t\tpropagate(v >> i);\n\t\t}\n\t}\n\npublic:\n\tdualSegmentTree() {}\n\
    \tdualSegmentTree(int _N) : N(_N), dat(_N << 1, monoid::identity) {}\n\tdualSegmentTree(const\
    \ std::vector<O>& A) : N((int)A.size()), dat(A.size() << 1, monoid::identity)\
    \ {\n\t\tfor (int i = 0 ; i < (int)A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\
    \t\t}\n\t}\n\n\tO operator[](int i) {\n\t\tassert(0 <= i and i < N);\n\t\ti +=\
    \ N;\n\t\tpush(i);\n\t\treturn dat[i];\n\t}\n\n\tvoid set(int i, const O& value)\
    \ {\n\t\tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\tdat[i] = value;\n\
    \t}\n\n\tvoid update(int i, const O& value) {\n\t\tassert(0 <= i and i < N);\n\
    \t\ti += N;\n\t\tpush(i);\n\t\tdat[i] = monoid::operation(dat[i], value);\n\t\
    }\n\n\tvoid update(int l, int r, const O& value) {\n\t\tassert(0 <= l and l <\
    \ N);\n\t\tassert(l <= r and r <= N);\n\t\tif (l == r) {\n\t\t\treturn;\n\t\t\
    }\n\t\tl += N; r += N;\n\t\tpush(l); push(r - 1);\n\t\tfor ( ; l < r ; l = parent(l),\
    \ r = parent(r)) {\n\t\t\tif (l & 1) {\n\t\t\t\tdat[l] = monoid::operation(dat[l],\
    \ value);\n\t\t\t\tl++;\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tdat[r]\
    \ = monoid::operation(dat[r], value);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline std::vector<O>\
    \ _dat() const {\n\t\treturn dat;\n\t}\n};\n\n} // namespace \n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/dualSegmentTree.hpp
  requiredBy: []
  timestamp: '2023-03-06 03:03:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC291-F.test.cpp
  - test/dualSegmentTree-AOJRAQ.test.cpp
  - test/practice90-037.test.cpp
  - test/ABC179-F.test.cpp
documentation_of: src/dataStructure/dualSegmentTree.hpp
layout: document
title: "dualSegmentTree (\u533A\u9593\u66F4\u65B0\u4E00\u70B9\u53D6\u5F97\u30BB\u30B0\
  \u6728)"
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
