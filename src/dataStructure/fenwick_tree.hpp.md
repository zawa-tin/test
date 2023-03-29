---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_multiset.hpp
    title: "fenwick_multiset (\u52D5\u7684\u591A\u91CD\u96C6\u5408)"
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_set.hpp
    title: "fenwick_set (\u52D5\u7684\u96C6\u5408)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC185-E.test.cpp
    title: test/ABC185-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC186-F.test.cpp
    title: test/ABC186-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ARC033-C.test.cpp
    title: test/ARC033-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ARC075-E.test.cpp
    title: test/ARC075-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree2.test.cpp
    title: test/fenwick_tree2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/fenwick_tree.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class structure>\nclass fenwick_tree {\nprivate:\n\
    \tusing T = typename structure::T;\n\tstd::vector<T> dat;\n\tint pow_two;\n\n\t\
    inline int lsb(int x) {\n\t\treturn x & -x;\n\t}\n\n\tT sum(int r) {\n\t\tT res\
    \ = 0;\n\t\twhile (r > 0) {\n\t\t\tres = structure::add(res, dat[r]);\n\t\t\t\
    r -= lsb(r);\n\t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\n\tfenwick_tree(std::size_t\
    \ n) : dat(n + 1, structure::id), pow_two(std::__lg(n) + 1) {}\n\t\n\tfenwick_tree(const\
    \ std::vector<T>& A) : dat(A.size() + 1, structure::id), pow_two(std::__lg(A.size())\
    \ + 1) {\n\t\tfor (int i = 0 ; i < (int)A.size() ; i++) {\n\t\t\tadd(i, A[i]);\n\
    \t\t}\n\t}\n\n\n\tT sum(int l, int r) {\n\t\treturn structure::add(sum(r), structure::inverse(sum(l)));\n\
    \t}\n\n\tvoid add(int pos, const T& v) {\n\t\tpos++;\n\t\twhile (pos < (int)dat.size())\
    \ {\n\t\t\tdat[pos] = structure::add(dat[pos], v);\n\t\t\tpos += lsb(pos);\n\t\
    \t}\n\t}\n\n\tint lower_bound(T val) {\n\t\tint res = 0;\n\t\tT now = structure::id;\n\
    \t\tfor (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {\n\t\t\tif (res + x < (int)dat.size())\
    \ {\n\t\t\t\tT nxt = structure::add(now, dat[res + x]);\n\t\t\t\tif (nxt < val)\
    \ {\n\t\t\t\t\tres += x;\n\t\t\t\t\tnow = nxt;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ structure>\nclass fenwick_tree {\nprivate:\n\tusing T = typename structure::T;\n\
    \tstd::vector<T> dat;\n\tint pow_two;\n\n\tinline int lsb(int x) {\n\t\treturn\
    \ x & -x;\n\t}\n\n\tT sum(int r) {\n\t\tT res = 0;\n\t\twhile (r > 0) {\n\t\t\t\
    res = structure::add(res, dat[r]);\n\t\t\tr -= lsb(r);\n\t\t}\n\t\treturn res;\n\
    \t}\n\t\npublic:\n\n\tfenwick_tree(std::size_t n) : dat(n + 1, structure::id),\
    \ pow_two(std::__lg(n) + 1) {}\n\t\n\tfenwick_tree(const std::vector<T>& A) :\
    \ dat(A.size() + 1, structure::id), pow_two(std::__lg(A.size()) + 1) {\n\t\tfor\
    \ (int i = 0 ; i < (int)A.size() ; i++) {\n\t\t\tadd(i, A[i]);\n\t\t}\n\t}\n\n\
    \n\tT sum(int l, int r) {\n\t\treturn structure::add(sum(r), structure::inverse(sum(l)));\n\
    \t}\n\n\tvoid add(int pos, const T& v) {\n\t\tpos++;\n\t\twhile (pos < (int)dat.size())\
    \ {\n\t\t\tdat[pos] = structure::add(dat[pos], v);\n\t\t\tpos += lsb(pos);\n\t\
    \t}\n\t}\n\n\tint lower_bound(T val) {\n\t\tint res = 0;\n\t\tT now = structure::id;\n\
    \t\tfor (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {\n\t\t\tif (res + x < (int)dat.size())\
    \ {\n\t\t\t\tT nxt = structure::add(now, dat[res + x]);\n\t\t\t\tif (nxt < val)\
    \ {\n\t\t\t\t\tres += x;\n\t\t\t\t\tnow = nxt;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/fenwick_tree.hpp
  requiredBy:
  - src/dataStructure/fenwick_multiset.hpp
  - src/dataStructure/fenwick_set.hpp
  timestamp: '2023-01-29 05:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ARC075-E.test.cpp
  - test/fenwick_tree.test.cpp
  - test/ARC033-C.test.cpp
  - test/ABC185-E.test.cpp
  - test/fenwick_tree2.test.cpp
  - test/ABC186-F.test.cpp
documentation_of: src/dataStructure/fenwick_tree.hpp
layout: document
title: "fenwick_tree (\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u548C\u53D6\u5F97\
  )"
---

## 概要

[フェニック木](https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A7%E3%83%8B%E3%83%83%E3%82%AF%E6%9C%A8) です。

集合と演算の組 $(S, \oplus)$ について
- 結合則
- 交換則
- 単位元の存在
- 逆元の存在

を満たす時、$x\ \in S$ からなる列 $A$ に対して以下のクエリに答えることができます。
- $A_i\ \leftarrow\ A_i\ \oplus\ x$
-  $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

## 機能

**コンストラクタ**

`zawa::fenwick_tree<structure> fen(std::size_t n)`
- $A$ を 長さ $n$ の各要素を `structure::id` で初期化する
- `structure`
	- 以下の要素を持つ構造体
	- `typename T`: 型
	- `static constexpr T id`: 単位元
	- `static T add(const T& a, const t& b)`: 演算
	- `static T inverse(const T& a)`: 逆元を返す
	- 例は`src/utility/fenwick_tree`を確認ください
- **計算量** : $O(n)$

`zawa::fenwick_tree<structure> fen(const std::vector<structure::T>& A)`
- $A$ を`A`で初期化する
- **計算量** : $O(\mid A\mid \log \mid A \mid)$

**メンバ関数**

`void add(int pos, const T& v)`
- $A_{\text{pos}}\ \leftarrow\ A_{\text{pos}}\ \oplus v$ とする
- **制約**: $0\ \le\ \text{pos}\ <\ n$
- **計算量** : $O(\log n)$

`T sum(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます
- **制約**: $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int lower_bound(T val)`
- `sum(0, r) >= val` を満たす最小の`r`を返します。
- **計算量** : $O(\log n)$
