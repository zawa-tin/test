---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segment-tree-rmq.test.cpp
    title: test/segment-tree-rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree-rsq.test.cpp
    title: test/segment-tree-rsq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree1.test.cpp
    title: test/segment-tree1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree2.test.cpp
    title: test/segment-tree2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/segment-tree.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nclass segment_tree\
    \ {\nprivate:\n    std::size_t n;\n    std::vector<T> dat;\n\n    void update(int\
    \ pos) {\n        while (pos > 1) {\n            pos >>= 1;\n            dat[pos]\
    \ = op(dat[(pos << 1) | 0], dat[(pos << 1) | 1]);\n        }\n    }\n\npublic:\n\
    \n    segment_tree(std::size_t n) : n(n), dat(2 * n, e()) {}\n\n    segment_tree(const\
    \ std::vector<T>& as) : n(as.size()), dat(2 * as.size(), e()) {\n        for (std::size_t\
    \ i = 0 ; i < n ; i++) {\n            dat[i + n] = as[i];\n        }\n       \
    \ for (int i = n - 1 ; i >= 1 ; i--) {\n            dat[i] = op(dat[(i << 1) |\
    \ 0], dat[(i << 1) | 1]);\n        }\n    }\n\n    void set(int pos, T val) {\n\
    \        pos += (int)n;\n        dat[pos] = val;  \n        update(pos);\n   \
    \ }\n\n    void apply(int pos, T val) {\n        pos += (int)n;\n        dat[pos]\
    \ = op(dat[pos], val);\n        update(pos);\n    }\n\n    T query(int l, int\
    \ r) {\n        l += n;\n        r += n;\n        T ans = e();\n        while\
    \ (l < r) {\n            if (l & 1) {\n                ans = op(ans, dat[l++]);\n\
    \            }\n            if (r & 1) {\n                ans = op(ans, dat[--r]);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return ans;\n    }\n\n    T debug(int pos) {\n        return dat[pos];\n  \
    \  }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)()>\nclass segment_tree {\nprivate:\n    std::size_t\
    \ n;\n    std::vector<T> dat;\n\n    void update(int pos) {\n        while (pos\
    \ > 1) {\n            pos >>= 1;\n            dat[pos] = op(dat[(pos << 1) | 0],\
    \ dat[(pos << 1) | 1]);\n        }\n    }\n\npublic:\n\n    segment_tree(std::size_t\
    \ n) : n(n), dat(2 * n, e()) {}\n\n    segment_tree(const std::vector<T>& as)\
    \ : n(as.size()), dat(2 * as.size(), e()) {\n        for (std::size_t i = 0 ;\
    \ i < n ; i++) {\n            dat[i + n] = as[i];\n        }\n        for (int\
    \ i = n - 1 ; i >= 1 ; i--) {\n            dat[i] = op(dat[(i << 1) | 0], dat[(i\
    \ << 1) | 1]);\n        }\n    }\n\n    void set(int pos, T val) {\n        pos\
    \ += (int)n;\n        dat[pos] = val;  \n        update(pos);\n    }\n\n    void\
    \ apply(int pos, T val) {\n        pos += (int)n;\n        dat[pos] = op(dat[pos],\
    \ val);\n        update(pos);\n    }\n\n    T query(int l, int r) {\n        l\
    \ += n;\n        r += n;\n        T ans = e();\n        while (l < r) {\n    \
    \        if (l & 1) {\n                ans = op(ans, dat[l++]);\n            }\n\
    \            if (r & 1) {\n                ans = op(ans, dat[--r]);\n        \
    \    }\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ ans;\n    }\n\n    T debug(int pos) {\n        return dat[pos];\n    }\n};\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-12-09 18:30:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree1.test.cpp
  - test/segment-tree-rsq.test.cpp
  - test/segment-tree-rmq.test.cpp
  - test/segment-tree2.test.cpp
documentation_of: src/dataStructure/segment-tree.hpp
layout: document
title: "segment tree (\u4E00\u70B9\u5909\u66F4\u30FB\u533A\u9593\u6F14\u7B97)"
---

## 概要

何の変哲も無いただのセグ木です。

 数列 $A$ に対する以下のクエリを処理できます。

- $A$ の単一要素を変更する
- $1\ \le\ l\ <\ r\ \le\ \mid A\mid$ に対して $A_l \oplus A_{l + 1} \oplus \dots \oplus A_{r - 1}$

ただし、 $A$ の各要素を含む集合 $S$ とクエリで飛んでくる演算 $\oplus$ について、組 $(S, \oplus)$ は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります。


## 機能

- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(std::size_t n)`
- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(const std::vector<T>& as)`
	-	`コンストラクタ`
	-	`T` は $A$ の型
	-	`op`は 二項演算(`T` 型の変数二つを引数にとり、その演算結果を`T`型で返す関数)
	-	`e` は単位元(引数を取らず、単位元を`T`型で返す関数)
	- `n`は $A$ の要素数、こちらで宣言した場合、 $A$ の全ての要素が`e()`で初期化される
	- `as` は $A$ を表す`vector`
	- **計算量**: $O(n)$

- `void seg.set(int pos, T val)`
	- $A_{\text{pos}}$ に `val` を代入する
	- $0\ \le\ \text{pos}\ <\ n$
	- **計算量** $O(\log n)$

- `void seg.apply(int pos, T val)`
	- $A_{\text{pos}}$ に $A_{\text{pos}} \oplus \text{val}$ を代入する。
	- $0\ \le\ \text{pos}\ <\ n$
	- **計算量** : $O(\log n)$

- `T query(int l, int r)`
	- $A_l \oplus A_{l + 1} \oplus \dots \oplus A_{r - 1}$ を計算します。
	- $0\ \le\ l\ <\ r\ \le\ n$
	- **計算量** $O(\log n)$

## 参考
[非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
