---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/DSU-unitTest.test.cpp
    title: test/DSU-unitTest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DSU1.test.cpp
    title: test/DSU1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/DSU2.test.cpp
    title: test/DSU2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/abc282_d.test.cpp
    title: test/abc282_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/DSU.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n#include <algorithm>\n\nnamespace zawa {\n\nclass DSU {\nprivate:\n\
    \    std::vector<int> parents;\n    std::vector<int> sizes;\n\npublic:\n    DSU(std::size_t\
    \ n) : parents(n, 0), sizes(n, 1) {\n        for (std::size_t i = 0 ; i < n ;\
    \ i++) {\n            parents[i] = i;\n        }\n    }\n\n    int leader(int\
    \ x) {\n        if (x == parents[x]) {\n            return x;\n        }\n   \
    \     else {\n            return parents[x] = leader(parents[x]);\n        }\n\
    \    }\n\n    bool same(int x, int y) {\n        return leader(x) == leader(y);\n\
    \    }\n\n    void merge(int x, int y) {\n        if (leader(x) == leader(y))\
    \ {\n            return;\n        }\n        if (sizes[leader(x)] < sizes[leader(y)])\
    \ {\n            std::swap(x, y);\n        }\n        sizes[leader(x)] += sizes[leader(y)];\
    \ \n        parents[leader(y)] = leader(x);\n    }\n\n    inline int size(int\
    \ x) {\n        return sizes[leader(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector res(parents.size(), std::vector(0, 0));\n  \
    \      for (int i = 0 ; i < (int)parents.size() ; i++) {\n            res[leader(i)].push_back(i);\n\
    \        }\n        res.erase(std::remove_if(res.begin(), res.end(), \n      \
    \              [](std::vector<int> x) { return x.empty(); }), res.end());\n  \
    \      return res;\n    }\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    \nnamespace zawa {\n\nclass DSU {\nprivate:\n    std::vector<int> parents;\n \
    \   std::vector<int> sizes;\n\npublic:\n    DSU(std::size_t n) : parents(n, 0),\
    \ sizes(n, 1) {\n        for (std::size_t i = 0 ; i < n ; i++) {\n           \
    \ parents[i] = i;\n        }\n    }\n\n    int leader(int x) {\n        if (x\
    \ == parents[x]) {\n            return x;\n        }\n        else {\n       \
    \     return parents[x] = leader(parents[x]);\n        }\n    }\n\n    bool same(int\
    \ x, int y) {\n        return leader(x) == leader(y);\n    }\n\n    void merge(int\
    \ x, int y) {\n        if (leader(x) == leader(y)) {\n            return;\n  \
    \      }\n        if (sizes[leader(x)] < sizes[leader(y)]) {\n            std::swap(x,\
    \ y);\n        }\n        sizes[leader(x)] += sizes[leader(y)]; \n        parents[leader(y)]\
    \ = leader(x);\n    }\n\n    inline int size(int x) {\n        return sizes[leader(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector res(parents.size(),\
    \ std::vector(0, 0));\n        for (int i = 0 ; i < (int)parents.size() ; i++)\
    \ {\n            res[leader(i)].push_back(i);\n        }\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), \n                    [](std::vector<int> x) { return x.empty();\
    \ }), res.end());\n        return res;\n    }\n};\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/DSU.hpp
  requiredBy: []
  timestamp: '2022-11-24 06:24:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/DSU-unitTest.test.cpp
  - test/DSU1.test.cpp
  - test/abc282_d.test.cpp
  - test/DSU2.test.cpp
documentation_of: src/dataStructure/DSU.hpp
layout: document
title: "DSU (\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u306E\u68EE\uFF09"
---

## 概要
```
zawa::DSU(std::size_t n)
```

 互いに素な集合の属 $\{S_1,\ S_2,\ \dots ,\ S_k\}$ に対し以下のクエリを処理することができるデータ構造
 - $x$ を含む集合と $y$ を含む集合を合併して和集合を生成する
 - $x$ と $y$ が同じ集合に含まれているかを確認する

集合に含まれる元を一つ、代表元とすることでそれぞれの集合を識別する。互いに素(どの集合の組も和集合が空集合)なので、代表元のとり方は重要ではない。

## 機能

- `DSU(int n)`: コンストラクタ、 $S_0 = \{ 0 \},\ S_1 = \{ 1 \},\ \dots ,\ S_{n - 1} = \{ n - 1 \}$ となるように集合属を生成する

- `int leader(int x)`: 元 $x$ が含まれる集合の代表元を返す

- `void merge(int x, int y)`: 元 $x$ を含む集合と元 $y$ を含む集合を合併し、和集合を生成する

- `bool same(int x, int y)`:  元 $x$　、 $y$ が同じ集合に含まれているかを判定する

- `int size(int x)`: 元 $x$ を含む集合の要素数を返す

- `std::vector<std::vector<int>> groups()`: 現在の集合属を返す。元に対して昇順とは限らない

## 計算量

TODO: 書く

## 参考

[AC Library](https://atcoder.github.io/ac-library/document_ja/dsu.html)
- メソッドの名前等はこちらに揃えています

[アルゴリズムイントロダクション 第二巻](https://www.kindaikagaku.co.jp/book_list/detail/9784764904071/)
- ドキュメントの文言はこちらを参考にしました
