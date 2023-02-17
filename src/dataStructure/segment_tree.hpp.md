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
    path: test/segment_tree-AOJRSQ.test.cpp
    title: test/segment_tree-AOJRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree-AOJRmQ.test.cpp
    title: test/segment_tree-AOJRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment_tree-RXORQ.test.cpp
    title: test/segment_tree-RXORQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/segment_tree.hpp\"\n\n#include <vector>\n\
    #include <functional>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass segment_tree\
    \ {\nprivate:\n\tusing T = typename monoid::value_type;\n\tstd::size_t N;\n\t\
    std::vector<T> dat;\n\npublic:\n\tsegment_tree() {}\n\tsegment_tree(int _N) :\
    \ N(_N), dat(2 * _N, monoid::identity) {}\n\tsegment_tree(const std::vector<T>&\
    \ A) : N(A.size()), dat(2 * N, monoid::identity) {\n\t\tfor (std::size_t i = 0\
    \ ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t\tfor (std::size_t\
    \ i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i << 1], dat[i\
    \ << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const T& value) {\n\
    \t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\t\t\tdat[pos]\
    \ = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\tT action(std::size_t\
    \ pos, const T& value) {\n\t\tpos += N;\n\t\tdo {\n\t\t\tdat[pos] = monoid::operation(dat[pos],\
    \ value);\n\t\t} while (pos >>= 1);\n\t\treturn dat[pos];\n\t}\n\n\tT prod(std::size_t\
    \ l, std::size_t r) const {\n\t\tT left = monoid::identity, right = monoid::identity;\n\
    \t\tfor (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tleft = monoid::operation(left, dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\
    \t\t\t\tright = monoid::operation(dat[--r], right);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ monoid::operation(left, right);\n\t}\n\n\ttemplate <class function_type>\n\t\
    int max_right(int l, const function_type& f) const {\n\t\tint L = l + N, w = 1;\n\
    \t\tT v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\
    \t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\
    \tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile (L <<= 1, w >>=\
    \ 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {\n\t\t\
    \t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\t}\n\t\t\
    return l;\n\t}\n\n\ttemplate <class function_type>\n\tint min_left(int r, const\
    \ function_type& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tT v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n\nnamespace zawa\
    \ {\n\ntemplate <class monoid>\nclass segment_tree {\nprivate:\n\tusing T = typename\
    \ monoid::value_type;\n\tstd::size_t N;\n\tstd::vector<T> dat;\n\npublic:\n\t\
    segment_tree() {}\n\tsegment_tree(int _N) : N(_N), dat(2 * _N, monoid::identity)\
    \ {}\n\tsegment_tree(const std::vector<T>& A) : N(A.size()), dat(2 * N, monoid::identity)\
    \ {\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\
    \t\t}\n\t\tfor (std::size_t i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i\
    \ << 1], dat[i << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const\
    \ T& value) {\n\t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\
    \t\t\tdat[pos] = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\
    \t}\n\n\tT action(std::size_t pos, const T& value) {\n\t\tpos += N;\n\t\tdo {\n\
    \t\t\tdat[pos] = monoid::operation(dat[pos], value);\n\t\t} while (pos >>= 1);\n\
    \t\treturn dat[pos];\n\t}\n\n\tT prod(std::size_t l, std::size_t r) const {\n\t\
    \tT left = monoid::identity, right = monoid::identity;\n\t\tfor (l += N, r +=\
    \ N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\t\tleft = monoid::operation(left,\
    \ dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tright = monoid::operation(dat[--r],\
    \ right);\n\t\t\t}\n\t\t}\n\t\treturn monoid::operation(left, right);\n\t}\n\n\
    \ttemplate <class function_type>\n\tint max_right(int l, const function_type&\
    \ f) const {\n\t\tint L = l + N, w = 1;\n\t\tT v = monoid::identity;\n\t\tfor\
    \ ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\t\t\tif (L & 1) {\n\t\t\t   \tif\
    \ (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\tv = monoid::operation(v, dat[L++]);\n\
    \t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t\twhile (L <<= 1, w >>= 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v,\
    \ dat[L]))) {\n\t\t\t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\
    \t\t}\n\t\t}\n\t\treturn l;\n\t}\n\n\ttemplate <class function_type>\n\tint min_left(int\
    \ r, const function_type& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tT v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/segment_tree.hpp
  requiredBy: []
  timestamp: '2023-02-18 05:16:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment_tree-AOJRSQ.test.cpp
  - test/AGC005-B.test.cpp
  - test/segment_tree-AOJRmQ.test.cpp
  - test/ALPC-J.test.cpp
  - test/segment_tree-RXORQ.test.cpp
documentation_of: src/dataStructure/segment_tree.hpp
layout: document
title: "segment_tree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
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

テンプレート引数`monoid`について
- 以下の機能をもたせた`struct`を用意してください
	- `using value_type`: $S$ の型
	- `static constexpr value_type identity` : モノイドの単位元 $\text{id}$
	- `static value_type operation(const value_type& a, const value_type& b)`: $a\oplus b$ を返す関数

`zawa::segment_tree<monoid>()`:
- 何もしない

`zawa::segment_tree<monoid>(int _N)`:
- $A$ を長さ $N$ で各要素を`monoid::identity`で初期化する
- **計算量** $O(N)$

`zawa::segment_tree<monoid>(const std::vector<monoid::value_type>& A)`
- $A$ を引数に与えた `std::vector`で初期化する

#### メンバ関数

`void set(std::size_t pos, const monoid::value_type& value)`
- $A_{\text{pos}}\ \leftarrow\ \text{value}$ とする
- **制約**
	- $0\ \le\ \text{pos}\ <\ N$
- **計算量**: $O(\log N)$

`T action(std::size_t pos, const monoid::value_type& value)`
- $A_{\text{pos}}\ \leftarrow\ A_{\text{pos}} \oplus \text{value}$ とする
- **制約**
	- $0\ \le\ \text{pos}\ <\ N$
- **計算量** : $O(\log N)$

`T prod(std::size_t l, std::size_t r) const`
- $\displaystyle \bigoplus_{i = l}^r A_i$  を返す
- **制約**
	- $0\ \le\ l\ <\ N$
	- $l\ \le\ r\ \le\ N$
- **計算量**: $O(\log N)$

`int max_right<function_type>(int l, const function_type& f) const`
- 単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最小の $r$ を返す。
- `function_type`は`std::function<bool(monoid::value_type)>`
- **制約**
	- $0\ \le\ l\ <\ N$
- **計算量** : $O(\log N)$

`int min_left<function_type>(int r, const function_type& f) const`
- 単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最大の $l$ を返す。
- `function_type`は`std::function<bool(monoid::value_type)>`
- **制約**
	- $0\ \le\ r\ <\ N$
- **計算量** : $O(\log N)$

##  参考

- [お手軽非再帰 Segment Tree の書き方](https://hackmd.io/@tatyam-prime/rkA5wJMdo)
- [非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
