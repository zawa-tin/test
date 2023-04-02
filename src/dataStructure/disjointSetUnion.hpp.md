---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/disjointSetUnion-test1.test.cpp
    title: test/disjointSetUnion-test1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/disjointSetUnion-test2.test.cpp
    title: test/disjointSetUnion-test2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/disjointSetUnion-unitTest.test.cpp
    title: test/disjointSetUnion-unitTest.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/disjointSetUnion.hpp\"\n\n#include <vector>\n\
    #include <utility>\n#include <algorithm>\n#include <numeric>\n#include <cassert>\n\
    \nnamespace zawa {\n\nclass disjointSetUnion {\nprivate:\n\tstd::vector<int> parents;\n\
    \tstd::vector<int> sizes;\n\npublic:\n\tdisjointSetUnion(std::size_t n) : parents(n,\
    \ 0), sizes(n, 1) {\n\t\tstd::iota(parents.begin(), parents.end(), 0);\n\t}\n\n\
    \tint leader(int x) {\n\t\tassert(0 <= x and x < (int)parents.size());\n\t\treturn\
    \ (parents[x] == x ? x : parents[x] = leader(parents[x]));\n\t}\n\n\tbool same(int\
    \ x, int y) {\n\t\treturn leader(x) == leader(y);\n\t}\n\n\tvoid merge(int x,\
    \ int y) {\n\t\tint lx = leader(x), ly = leader(y);\n\t\tif (lx == ly) return;\n\
    \t\tif (sizes[lx] < sizes[ly]) std::swap(lx, ly);\n\t\tsizes[lx] += sizes[ly];\
    \ \n\t\tparents[ly] = lx;\n\t}\n\n\tint size(int x) {\n\t\treturn sizes[leader(x)];\n\
    \t}\n\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector res(parents.size(),\
    \ std::vector(0, 0));\n\t\tfor (int i = 0 ; i < (int)parents.size() ; i++) {\n\
    \t\t\tres[leader(i)].push_back(i);\n\t\t}\n\t\tres.erase(std::remove_if(res.begin(),\
    \ res.end(), \n\t\t\t\t\t[](std::vector<int> x) { return x.empty(); }), res.end());\n\
    \t\treturn res;\n\t}\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <numeric>\n#include <cassert>\n\nnamespace zawa {\n\nclass disjointSetUnion\
    \ {\nprivate:\n\tstd::vector<int> parents;\n\tstd::vector<int> sizes;\n\npublic:\n\
    \tdisjointSetUnion(std::size_t n) : parents(n, 0), sizes(n, 1) {\n\t\tstd::iota(parents.begin(),\
    \ parents.end(), 0);\n\t}\n\n\tint leader(int x) {\n\t\tassert(0 <= x and x <\
    \ (int)parents.size());\n\t\treturn (parents[x] == x ? x : parents[x] = leader(parents[x]));\n\
    \t}\n\n\tbool same(int x, int y) {\n\t\treturn leader(x) == leader(y);\n\t}\n\n\
    \tvoid merge(int x, int y) {\n\t\tint lx = leader(x), ly = leader(y);\n\t\tif\
    \ (lx == ly) return;\n\t\tif (sizes[lx] < sizes[ly]) std::swap(lx, ly);\n\t\t\
    sizes[lx] += sizes[ly]; \n\t\tparents[ly] = lx;\n\t}\n\n\tint size(int x) {\n\t\
    \treturn sizes[leader(x)];\n\t}\n\n\tstd::vector<std::vector<int>> groups() {\n\
    \t\tstd::vector res(parents.size(), std::vector(0, 0));\n\t\tfor (int i = 0 ;\
    \ i < (int)parents.size() ; i++) {\n\t\t\tres[leader(i)].push_back(i);\n\t\t}\n\
    \t\tres.erase(std::remove_if(res.begin(), res.end(), \n\t\t\t\t\t[](std::vector<int>\
    \ x) { return x.empty(); }), res.end());\n\t\treturn res;\n\t}\n};\n\n}// namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/disjointSetUnion.hpp
  requiredBy: []
  timestamp: '2023-04-03 07:50:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/disjointSetUnion-test2.test.cpp
  - test/disjointSetUnion-unitTest.test.cpp
  - test/disjointSetUnion-test1.test.cpp
documentation_of: src/dataStructure/disjointSetUnion.hpp
layout: document
title: "disjointSetUnion (\u4E92\u3044\u306B\u7D20\u306A\u96C6\u5408\u306E\u68EE\uFF09"
---

## 概要
```
zawa::disjointSetUnion(std::size_t n)
```

 Union-Findアルゴリズムを使用し、互いに素な集合の属 $\{S_1,\ S_2,\ \dots ,\ S_k\}$ に対し以下のクエリを処理することができるデータ構造
 - $x$ を含む集合と $y$ を含む集合を合併して和集合を生成する
 - $x$ と $y$ が同じ集合に含まれているかを確認する

集合に含まれる元を一つ、代表元とすることでそれぞれの集合を識別する。互いに素(どの集合の組も和集合が空集合)なので、代表元のとり方は重要ではない。

## 機能

#### コンストラクタ

```
zawa::disjointSetUnion(std::size_t n)
```

$S_0 = \\{ 0 \\}, S_1 = \\{ 1 \\}, \dots, S_{n - 1} = \\{ n - 1 \\}$ と集合族を生成、初期化する

#### メンバ

**leader**
```
int leader(int x)
```

元 $x$ が含まれる集合の代表元を返す

<br/>

**merge**
```
void merge(int x, int y)
```

元 $x$ を含む集合と元 $y$ を含む集合を合併する

<br/>

**same**
```
bool same(int x, int y)
```

元 $x$ と $y$ が同じ集合族に含まれているかを判定する

<br/>

**size**
```
int size(int x)
```

元 $x$ を含む集合の要素数を返す

<br/>

**groups**
```
std::vector<std::vector<int>> groups()
```

現在の集合属を返す。元に対して昇順とは限らない

<br/>

## 計算量

TODO: 書く

## 参考

[AC Library](https://atcoder.github.io/ac-library/document_ja/dsu.html)
- メンバの名前等はこちらに揃えています

[アルゴリズムイントロダクション 第二巻](https://www.kindaikagaku.co.jp/book_list/detail/9784764904071/)
- ドキュメントの文言はこちらを参考にしました
