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
    path: test/ARC075-E.test.cpp
    title: test/ARC075-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/fenwick_multiset.hpp\"\n\n#line 2 \"src/utility/fenwick_tree/add.hpp\"\
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
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"src/dataStructure/fenwick_multiset.hpp\"\
    \n\n#line 7 \"src/dataStructure/fenwick_multiset.hpp\"\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass fenwick_multiset {\nprivate:\n\
    \tstd::vector<T> dat;\n\tfenwick_tree<add_structure<T>> fen;\n\npublic:\n\n\t\
    fenwick_multiset(std::size_t n) : dat(n), fen(n) {}\n\n\tT count(int x) {\n\t\t\
    return dat[x];\n\t}\n\n\tT count(int l, int r) {\n\t\treturn fen.sum(l, r);\n\t\
    }\n\n\tvoid insert(int x) {\n\t\tdat[x] += 1;\n\t\tfen.add(x, 1);\n\t}\n\n\tvoid\
    \ insert(int x, const T& cnt) {\n\t\tdat[x] += cnt;\n\t\tfen.add(x, cnt);\n\t\
    }\n\n\tT erase(int x) {\n\t\tif (dat[x]) {\n\t\t\tdat[x] -= 1;\n\t\t\tfen.add(x,\
    \ -1);\n\t\t\treturn 1;\n\t\t}\n\t\telse {\n\t\t\treturn 0;\n\t\t}\n\t}\n\n\t\
    T erase(int x, const T& cnt) {\n\t\tT res = std::min(dat[x], cnt);\t\n\t\tdat[x]\
    \ -= res;\n\t\tfen.add(x, -res);\n\t\treturn res;\n\t}\n\n\tint kth_element(const\
    \ T& k) {\n\t\treturn fen.lower_bound(k);\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include \"../utility/fenwick_tree/add.hpp\"\n#include \"\
    fenwick_tree.hpp\"\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass fenwick_multiset {\nprivate:\n\tstd::vector<T>\
    \ dat;\n\tfenwick_tree<add_structure<T>> fen;\n\npublic:\n\n\tfenwick_multiset(std::size_t\
    \ n) : dat(n), fen(n) {}\n\n\tT count(int x) {\n\t\treturn dat[x];\n\t}\n\n\t\
    T count(int l, int r) {\n\t\treturn fen.sum(l, r);\n\t}\n\n\tvoid insert(int x)\
    \ {\n\t\tdat[x] += 1;\n\t\tfen.add(x, 1);\n\t}\n\n\tvoid insert(int x, const T&\
    \ cnt) {\n\t\tdat[x] += cnt;\n\t\tfen.add(x, cnt);\n\t}\n\n\tT erase(int x) {\n\
    \t\tif (dat[x]) {\n\t\t\tdat[x] -= 1;\n\t\t\tfen.add(x, -1);\n\t\t\treturn 1;\n\
    \t\t}\n\t\telse {\n\t\t\treturn 0;\n\t\t}\n\t}\n\n\tT erase(int x, const T& cnt)\
    \ {\n\t\tT res = std::min(dat[x], cnt);\t\n\t\tdat[x] -= res;\n\t\tfen.add(x,\
    \ -res);\n\t\treturn res;\n\t}\n\n\tint kth_element(const T& k) {\n\t\treturn\
    \ fen.lower_bound(k);\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn:
  - src/utility/fenwick_tree/add.hpp
  - src/dataStructure/fenwick_tree.hpp
  isVerificationFile: false
  path: src/dataStructure/fenwick_multiset.hpp
  requiredBy: []
  timestamp: '2023-01-30 11:07:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ARC075-E.test.cpp
documentation_of: src/dataStructure/fenwick_multiset.hpp
layout: document
title: "fenwick_multiset (\u52D5\u7684\u591A\u91CD\u96C6\u5408)"
---

## 概要

`fenwick_tree`による多重集合 $S$ の管理を提供します。ただし、集合の各要素は $0\ \le\ i\ <\ n$ という制約があります。

以下の手続きが行えます。
- `insert x cnt`: $S\ \leftarrow\ x$ を `cnt`回行う
- `erase x cnt`: $S$ から $x$ を`cnt`個削除する
- `count l r`: $S$ 内で $l$ 以上 $r$ 未満である要素の数を数える
- `contain x`: $S$ に $x$ が含まれるか判定する
- `kth_element`: $S$ で $k$ 番目に大きい要素を報告する

## 機能

**コンストラクタ**

`zawa::fenwick_multiset<T>(std::size_t n)`
- `n`: $n$
- 空集合で初期化します
- `T`は`int`や`long long`など挿入する要素に対してオーバーフローしないように指定する

**メンバ関数**

`void insert(int x)`
- $x$ を挿入します。
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`void insert(int x, const T& cnt)`
- $x$ を `cnt`個挿入する
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T erase(int x)`
- $x$ を $S$ から1つ削除します
- もともと要素が存在しなかった場合、`0`を、そうでない場合`1`を返します
- **テストをまだしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T erase(int x, const T& cnt)`
- $x$ を最大 `cnt`個削除する
- 削除した個数を返します
- **まだテストをしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(\log n)$

`T count(int x)`:
- $S$ に含まれる $x$ の個数を返します
- **まだテストをしていません**
- **制約** : $0\ \le\ x\ <\ n$
- **計算量** : $O(1)$

`T count(int l, int r)`
- $l$ 以上 $r$ 未満の要素の数を数えます
- **制約** : $0\ \le\ l\ \le\ r\ \le\ n$
- **計算量** : $O(\log n)$

`int kth_elemnt(int k)`
- $S$ で $k$ 番目に大きい要素を報告します
- $\mid S\mid\ < k$ の場合、 $n$ が返されます
- **まだテストをしていません**
- **計算量** : $O(\log n)$
