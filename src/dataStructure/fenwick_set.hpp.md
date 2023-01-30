---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_tree.hpp
    title: "fenwick_tree (\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u548C\u53D6\u5F97\
      )"
  - icon: ':heavy_check_mark:'
    path: src/utility/fenwick_tree/add.hpp
    title: fenwick tree add structure
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC186-F.test.cpp
    title: test/ABC186-F.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/fenwick_set.hpp\"\n\n#line 2 \"src/utility/fenwick_tree/add.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct add_structure {\n\t\
    using T = dat_type;\n\tstatic constexpr T id = T{};\n\tstatic T add(const T& a,\
    \ const T& b) {\n\t\treturn a + b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\t\
    return -a;\n\t}\n};\n\n} // namespace zawa\n#line 2 \"src/dataStructure/fenwick_tree.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass\
    \ fenwick_tree {\nprivate:\n\tusing T = typename structure::T;\n\tstd::vector<T>\
    \ dat;\n\tint pow_two;\n\n\tinline int lsb(int x) {\n\t\treturn x & -x;\n\t}\n\
    \n\tT sum(int r) {\n\t\tT res = 0;\n\t\twhile (r > 0) {\n\t\t\tres = structure::add(res,\
    \ dat[r]);\n\t\t\tr -= lsb(r);\n\t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\n\t\
    fenwick_tree(std::size_t n) : dat(n + 1, structure::id), pow_two(std::__lg(n)\
    \ + 1) {}\n\t\n\tfenwick_tree(const std::vector<T>& A) : dat(A.size() + 1, structure::id),\
    \ pow_two(std::__lg(A.size()) + 1) {\n\t\tfor (int i = 0 ; i < (int)A.size() ;\
    \ i++) {\n\t\t\tadd(i, A[i]);\n\t\t}\n\t}\n\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ structure::add(sum(r), structure::inverse(sum(l)));\n\t}\n\n\tvoid add(int pos,\
    \ const T& v) {\n\t\tpos++;\n\t\twhile (pos < (int)dat.size()) {\n\t\t\tdat[pos]\
    \ = structure::add(dat[pos], v);\n\t\t\tpos += lsb(pos);\n\t\t}\n\t}\n\n\tint\
    \ lower_bound(T val) {\n\t\tint res = 0;\n\t\tT now = structure::id;\n\t\tfor\
    \ (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {\n\t\t\tif (res + x < (int)dat.size())\
    \ {\n\t\t\t\tT nxt = structure::add(now, dat[res + x]);\n\t\t\t\tif (nxt < val)\
    \ {\n\t\t\t\t\tres += x;\n\t\t\t\t\tnow = nxt;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"src/dataStructure/fenwick_set.hpp\"\
    \n\n#line 7 \"src/dataStructure/fenwick_set.hpp\"\n\nnamespace zawa {\n\nclass\
    \ fenwick_set {\nprivate:\n\tstd::vector<bool> dat;\n\tfenwick_tree<add_structure<int>>\
    \ fen;\n\npublic:\n\tfenwick_set(std::size_t n) : dat(n, false), fen(n) {}\n\n\
    \tbool contain(int x) {\n\t\treturn dat[x];\n\t}\n\n\tvoid insert(int x) {\n\t\
    \tif (!dat[x]) {\n\t\t\tdat[x] = true;\n\t\t\tfen.add(x, 1);\n\t\t}\n\t}\n\n\t\
    int count(int l, int r) {\n\t\treturn fen.sum(l, r);\n\t}\n\n\tbool erase(int\
    \ x) {\n\t\tif (dat[x]) {\n\t\t\tdat[x] = false;\n\t\t\tfen.add(x, -1);\n\t\t\t\
    return true;\n\t\t}\n\t\telse {\n\t\t\treturn false;\n\t\t}\n\t}\t\n\n\tint kth_element(int\
    \ k) {\n\t\treturn fen.lower_bound(k);\n\t}\n};\n\n};\n"
  code: "#pragma once\n\n#include \"../utility/fenwick_tree/add.hpp\"\n#include \"\
    fenwick_tree.hpp\"\n\n#include <vector>\n\nnamespace zawa {\n\nclass fenwick_set\
    \ {\nprivate:\n\tstd::vector<bool> dat;\n\tfenwick_tree<add_structure<int>> fen;\n\
    \npublic:\n\tfenwick_set(std::size_t n) : dat(n, false), fen(n) {}\n\n\tbool contain(int\
    \ x) {\n\t\treturn dat[x];\n\t}\n\n\tvoid insert(int x) {\n\t\tif (!dat[x]) {\n\
    \t\t\tdat[x] = true;\n\t\t\tfen.add(x, 1);\n\t\t}\n\t}\n\n\tint count(int l, int\
    \ r) {\n\t\treturn fen.sum(l, r);\n\t}\n\n\tbool erase(int x) {\n\t\tif (dat[x])\
    \ {\n\t\t\tdat[x] = false;\n\t\t\tfen.add(x, -1);\n\t\t\treturn true;\n\t\t}\n\
    \t\telse {\n\t\t\treturn false;\n\t\t}\n\t}\t\n\n\tint kth_element(int k) {\n\t\
    \treturn fen.lower_bound(k);\n\t}\n};\n\n};\n"
  dependsOn:
  - src/utility/fenwick_tree/add.hpp
  - src/dataStructure/fenwick_tree.hpp
  isVerificationFile: false
  path: src/dataStructure/fenwick_set.hpp
  requiredBy: []
  timestamp: '2023-01-30 10:01:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC186-F.test.cpp
documentation_of: src/dataStructure/fenwick_set.hpp
layout: document
title: "fenwick_set (\u52D5\u7684\u96C6\u5408)"
---

## 概要

`fenwick_tree`による集合 $S$ の管理を提供します。ただし、集合の各要素は $0\ \le\ i\ <\ n$ という制約があります。

以下の手続きが行えます。
- `insert x`: $S\ \leftarrow\ x$
- `erase x`: $S$ から $x$ を削除する
- `count l r`: $S$ 内で $l$ 以上 $r$ 未満である要素の数を数える
- `contain x`: $S$ に $x$ が含まれるか判定する
- `kth_element`: $S$ で $k$ 番目に大きい要素を報告する

## 機能

**コンストラクタ**

`zawa::fenwick_set(std::size_t n)`
- `n`: $n$
- 空集合で初期化します

**メンバ関数**

`void insert(int x)`
- $x$ を挿入します。
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`bool erase(x)`
- $x$ を $S$ から削除します
- もともと要素が存在しなかった場合、`false`を返します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`bool contain(x)`
- $x$ が $S$ に含まれているかを判定します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(1)$

`int count(int l, int r)`
- $l$ 以上 $r$ 未満の要素の数を数えます
- **制約** : $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int kth_elemnt(int k)`
- $S$ で $k$ 番目に大きい要素を報告します
- $\mid S\mid\ < k$ の場合、 $n$ が返されます
- **計算量** : $O(\log n)$
