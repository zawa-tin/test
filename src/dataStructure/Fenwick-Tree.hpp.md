---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Fenwick-Tree.test.cpp
    title: test/Fenwick-Tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Fenwick-Tree_lower_bound.test.cpp
    title: test/Fenwick-Tree_lower_bound.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Fenwick-Tree.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass Fenwick_Tree {\nprivate:\n   \
    \ std::vector<T> container;\n    int size;\n    int pow_two;\n\n    inline int\
    \ lsb(int x) {\n        return x & -x;\n    }\n\n    T sum(int id) {\n       \
    \ T res = 0;\n        for (int x = id ; x > 0 ; x -= lsb(x)) {\n            res\
    \ += container[x];\n        }\n\n        return res;\n    }\n\npublic:\n    Fenwick_Tree(int\
    \ n)\n        : container(n + 1, T())\n        , size(n + 1)\n        , pow_two(1\
    \ << (std::__lg(n) + 1)) {}\n\n    void add(int id, T val) {\n        for (int\
    \ x = id + 1 ; x <= size ; x += lsb(x)) {\n            container[x] += val;\n\
    \        }\n    }\n    \n    T query(int l, int r) {\n        return sum(r) -\
    \ sum(l); \n    }\n\n    int lower_bound(T val) {\n        int res = 0;\n    \
    \    for (int x = pow_two ; x > 0 ; x >>= 1) {\n            if (res + x <= size\
    \ and container[res + x] < val) {\n                val -= container[res + x];\n\
    \                res += x;\n            }\n        }\n\n        return res;\n\
    \    }\n\n    T get(int id) {\n        return container[id];\n    }\n\n};\n\n\
    }// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass Fenwick_Tree {\nprivate:\n    std::vector<T> container;\n    int size;\n\
    \    int pow_two;\n\n    inline int lsb(int x) {\n        return x & -x;\n   \
    \ }\n\n    T sum(int id) {\n        T res = 0;\n        for (int x = id ; x >\
    \ 0 ; x -= lsb(x)) {\n            res += container[x];\n        }\n\n        return\
    \ res;\n    }\n\npublic:\n    Fenwick_Tree(int n)\n        : container(n + 1,\
    \ T())\n        , size(n + 1)\n        , pow_two(1 << (std::__lg(n) + 1)) {}\n\
    \n    void add(int id, T val) {\n        for (int x = id + 1 ; x <= size ; x +=\
    \ lsb(x)) {\n            container[x] += val;\n        }\n    }\n    \n    T query(int\
    \ l, int r) {\n        return sum(r) - sum(l); \n    }\n\n    int lower_bound(T\
    \ val) {\n        int res = 0;\n        for (int x = pow_two ; x > 0 ; x >>= 1)\
    \ {\n            if (res + x <= size and container[res + x] < val) {\n       \
    \         val -= container[res + x];\n                res += x;\n            }\n\
    \        }\n\n        return res;\n    }\n\n    T get(int id) {\n        return\
    \ container[id];\n    }\n\n};\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Fenwick-Tree.hpp
  requiredBy: []
  timestamp: '2022-09-06 00:26:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Fenwick-Tree.test.cpp
  - test/Fenwick-Tree_lower_bound.test.cpp
documentation_of: src/dataStructure/Fenwick-Tree.hpp
layout: document
title: "Fenwick Tree (\u4E00\u70B9\u53EF\u7B97\u30FB\u533A\u9593\u548C\u53D6\u5F97\
  )"
---

## 概要
```
Fenwick_Tree<T>(int n)
```

Fenwick Treeです。Binary Indexed Tree ともいいます。

累積和に対して値の変更が来た場合でも高速に部分和を正しく取り出せます。

## 機能
- `コンストラクタ`: 配列の要素数を引数に入れてください。

- `add(int id, T val)`: `id`番目の要素に`val`を可算します。
	- `0-indexed`で入れてください

- `query(int l, int r)`: `l`番目の要素から`r`番目の要素までの総和を取得します。
	- `0-indexed`で入れてください

- `lower_bound(T val)`: `query(0, i) >= w`となる最小の`i`を返します。


## 計算量
-	`add, query, lower_bound`:  要素数 $N$ に対して $O(logN)$
