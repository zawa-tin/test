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
  - icon: ':heavy_check_mark:'
    path: test/segment-tree3.test.cpp
    title: test/segment-tree3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree4.test.cpp
    title: test/segment-tree4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/segment-tree5.test.cpp
    title: test/segment-tree5.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/segment-tree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n#include <functional>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)()>\nclass segment_tree {\nprivate:\n    int n;\n  \
    \  std::vector<T> dat;\n\n    void update(int pos) {\n        while (pos > 1)\
    \ {\n            pos >>= 1;\n            dat[pos] = op(dat[(pos << 1) | 0], dat[(pos\
    \ << 1) | 1]);\n        }\n    }\n\npublic:\n\n    segment_tree(int n) : n(n),\
    \ dat(2 * n, e()) {}\n\n    segment_tree(const std::vector<T>& as) : n(as.size()),\
    \ dat(2 * as.size(), e()) {\n        for (int i = 0 ; i < n ; i++) {\n       \
    \     dat[i + n] = as[i];\n        }\n        for (int i = n - 1 ; i >= 1 ; i--)\
    \ {\n            dat[i] = op(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n        }\n\
    \    }\n\n    void set(int pos, T val) {\n        assert(0 <= pos and pos < n);\n\
    \        pos += n;\n        dat[pos] = val;  \n        update(pos);\n    }\n\n\
    \    void apply(int pos, T val) {\n        assert(0 <= pos and pos < n);\n   \
    \     pos += n;\n        dat[pos] = op(dat[pos], val);\n        update(pos);\n\
    \    }\n\n    T query(int l, int r) {\n        assert(0 <= l and l < n);\n   \
    \     assert(l <= r and r <= n);\n        l += n;\n        r += n;\n        T\
    \ ans = e();\n        while (l < r) {\n            if (l & 1) {\n            \
    \    ans = op(ans, dat[l++]);\n            }\n            if (r & 1) {\n     \
    \           ans = op(ans, dat[--r]);\n            }\n            l >>= 1;\n  \
    \          r >>= 1;\n        }\n        return ans;\n    }\n\n    T all_prod()\
    \ {\n        return dat[1];\n    }\n\n    int max_right(int l, const std::function<bool(int)>&\
    \ f) {\n        assert(0 <= l and l < n);\n        int r = 2 * n;\n        l +=\
    \ n;\n        T sum = e();\n        auto down_tree = [&](int v) -> int {\n   \
    \         while (v < n) {\n                if (f(op(sum, dat[(v << 1) | 0])))\
    \ {\n                    sum = op(sum, dat[(v << 1) | 0]);\n                 \
    \   v = ((v << 1) | 1);\n                }\n                else {\n         \
    \           v = ((v << 1) | 0);\n                }\n            }\n          \
    \  return v - n;\n        };\n        int cnt = 0;\n        for ( ; l < r ; cnt++)\
    \ {\n            if (l & 1) {\n                if (!f(op(sum, dat[l]))) {\n  \
    \                  return down_tree(l);\n                }\n                sum\
    \ = op(sum, dat[l++]);\n            }\n            r -= (r & 1);\n           \
    \ l >>= 1;\n            r >>= 1;\n        }\n        while (cnt--) {\n       \
    \     r <<= 1;\n            if (((r | 1) << cnt) <= 2 * n) {\n               \
    \ if (!f(op(sum, dat[r]))) {\n                    return down_tree(r);\n     \
    \           }\n                else {\n                    sum = op(sum, dat[r++]);\n\
    \                }\n            }\n        }\n        return n;\n    }\n\n   \
    \ T debug(int pos) {\n        return dat[pos];\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <functional>\n\
    \nnamespace zawa {\n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nclass segment_tree\
    \ {\nprivate:\n    int n;\n    std::vector<T> dat;\n\n    void update(int pos)\
    \ {\n        while (pos > 1) {\n            pos >>= 1;\n            dat[pos] =\
    \ op(dat[(pos << 1) | 0], dat[(pos << 1) | 1]);\n        }\n    }\n\npublic:\n\
    \n    segment_tree(int n) : n(n), dat(2 * n, e()) {}\n\n    segment_tree(const\
    \ std::vector<T>& as) : n(as.size()), dat(2 * as.size(), e()) {\n        for (int\
    \ i = 0 ; i < n ; i++) {\n            dat[i + n] = as[i];\n        }\n       \
    \ for (int i = n - 1 ; i >= 1 ; i--) {\n            dat[i] = op(dat[(i << 1) |\
    \ 0], dat[(i << 1) | 1]);\n        }\n    }\n\n    void set(int pos, T val) {\n\
    \        assert(0 <= pos and pos < n);\n        pos += n;\n        dat[pos] =\
    \ val;  \n        update(pos);\n    }\n\n    void apply(int pos, T val) {\n  \
    \      assert(0 <= pos and pos < n);\n        pos += n;\n        dat[pos] = op(dat[pos],\
    \ val);\n        update(pos);\n    }\n\n    T query(int l, int r) {\n        assert(0\
    \ <= l and l < n);\n        assert(l <= r and r <= n);\n        l += n;\n    \
    \    r += n;\n        T ans = e();\n        while (l < r) {\n            if (l\
    \ & 1) {\n                ans = op(ans, dat[l++]);\n            }\n          \
    \  if (r & 1) {\n                ans = op(ans, dat[--r]);\n            }\n   \
    \         l >>= 1;\n            r >>= 1;\n        }\n        return ans;\n   \
    \ }\n\n    T all_prod() {\n        return dat[1];\n    }\n\n    int max_right(int\
    \ l, const std::function<bool(int)>& f) {\n        assert(0 <= l and l < n);\n\
    \        int r = 2 * n;\n        l += n;\n        T sum = e();\n        auto down_tree\
    \ = [&](int v) -> int {\n            while (v < n) {\n                if (f(op(sum,\
    \ dat[(v << 1) | 0]))) {\n                    sum = op(sum, dat[(v << 1) | 0]);\n\
    \                    v = ((v << 1) | 1);\n                }\n                else\
    \ {\n                    v = ((v << 1) | 0);\n                }\n            }\n\
    \            return v - n;\n        };\n        int cnt = 0;\n        for ( ;\
    \ l < r ; cnt++) {\n            if (l & 1) {\n                if (!f(op(sum, dat[l])))\
    \ {\n                    return down_tree(l);\n                }\n           \
    \     sum = op(sum, dat[l++]);\n            }\n            r -= (r & 1);\n   \
    \         l >>= 1;\n            r >>= 1;\n        }\n        while (cnt--) {\n\
    \            r <<= 1;\n            if (((r | 1) << cnt) <= 2 * n) {\n        \
    \        if (!f(op(sum, dat[r]))) {\n                    return down_tree(r);\n\
    \                }\n                else {\n                    sum = op(sum,\
    \ dat[r++]);\n                }\n            }\n        }\n        return n;\n\
    \    }\n\n    T debug(int pos) {\n        return dat[pos];\n    }\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-12-12 17:22:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segment-tree4.test.cpp
  - test/segment-tree5.test.cpp
  - test/segment-tree-rmq.test.cpp
  - test/segment-tree2.test.cpp
  - test/segment-tree3.test.cpp
  - test/segment-tree-rsq.test.cpp
  - test/segment-tree1.test.cpp
documentation_of: src/dataStructure/segment-tree.hpp
layout: document
title: "segment tree (\u4E00\u70B9\u5909\u66F4\u30FB\u533A\u9593\u6F14\u7B97)"
---

## 概要

何の変哲も無いただのセグ木です。

 数列 $A$ に対する以下のクエリを処理できます。

- $A$ の単一要素を変更する
- $1\ \le\ l\ <\ r\ \le\ \mid A\mid$ に対して $A_l \oplus A_{l + 1} \oplus \dots \oplus A_{r - 1}$

ただし、$A$ の各要素の集合 $S$ とクエリで飛んでくる演算 $\oplus$ について、組 $(S, \oplus)$ は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)である必要があります。


## 機能

- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(std::size_t n)`
- `zawa::segment_tree<T, T (*op)(T, T), T (*e)()> seg(const std::vector<T>& as)`
	-	`コンストラクタ`
	-	`T` は $A$ の型
	-	`op`は 二項演算(`T` 型の変数二つを引数にとり、その演算結果を`T`型で返す関数)
	-	`e` は単位元(引数を取らず、単位元を`T`型で返す関数)
	- `n`は $A$ の要素数、こちらで宣言した場合、$A$ の全ての要素が`e()`で初期化される
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

- `int max_right(int l, std::function<bool(int)>& f)`
	- $\text{f}(A_1 \oplus A_2 \oplus \dots \oplus A_{r})$ が`false` を返す最小の`r`を返します。 $\text{f}(A_1\oplus A_2 \oplus \dots \oplus A_n)$ が`true`の時は`n`を返します。`f`が単調性を持つことを想定しています。
	- $0\ \le\ l\ <\ n$
		- [AC Library](https://atcoder.github.io/ac-library/document_ja/segtree.html) とは異なり、$l = n$ を許容していないことに注意してください。
	- **計算量**: $O(\log n)$

## 使用例

- $k$ 番目に小さい要素にアクセスできる配列 `test/segment-tree5.test.cpp`

##  修正/機能追加案

- `min_left`
- モノイドを`class`等で管理する。
	- `e()`をコンストラクタ、`op`をoperator


## 参考
[非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
