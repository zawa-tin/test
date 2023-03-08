---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/potentialized_unionfind1.test.cpp
    title: test/potentialized_unionfind1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/potentialized_unionfind2.test.cpp
    title: test/potentialized_unionfind2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/potentialized_unionfind3.test.cpp
    title: test/potentialized_unionfind3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/potentialized_unionfind.hpp\"\n\n#include\
    \ <vector>\n#include <utility>\n\nnamespace zawa {\n\ntemplate <class cost_type>\n\
    class potentialized_unionfind {\nprivate:\n    std::vector<int> parents;\n   \
    \ std::vector<int> sizes;\n    std::vector<cost_type> weights;\n\n    int rooting(int\
    \ x) {\n        if (parents[x] == x) {\n            return x;\n        }\n   \
    \     else {\n            int root = rooting(parents[x]);\n            weights[x]\
    \ += weights[parents[x]];\n            return parents[x] = root;\n        }\n\
    \    }\n\n    cost_type get_weight(int x) {\n        rooting(x);\n        return\
    \ weights[x];\n    }\n\npublic:\n\n    potentialized_unionfind(std::size_t n)\
    \ : parents(n, 0), sizes(n, 1), weights(n) {\n        for (std::size_t i = 0 ;\
    \ i < n ; i++) {\n            parents[i] = i;\n        }\n    }\n\n    int leader(int\
    \ x) {\n        return rooting(x);\n    }\n\n    bool same(int x, int y) {\n \
    \       return rooting(x) == rooting(y);\n    }\n\n    bool merge(int x, int y,\
    \ cost_type w) {\n        w += get_weight(x);\n        w -= get_weight(y);\n \
    \       int rx = rooting(x), ry = rooting(y);\n        if (rx == ry) {\n     \
    \       return false;\n        }\n        if (sizes[rx] < sizes[ry]) {\n     \
    \       std::swap(rx, ry);\n            w *= -1;\n        }\n        sizes[rx]\
    \ += sizes[ry];\n        parents[ry] = rx;\n        weights[ry] = w;\n       \
    \ return true;\n    }\n\n    cost_type diff(int y, int x) {\n        return get_weight(y)\
    \ - get_weight(x);\n    }\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n\nnamespace zawa {\n\
    \ntemplate <class cost_type>\nclass potentialized_unionfind {\nprivate:\n    std::vector<int>\
    \ parents;\n    std::vector<int> sizes;\n    std::vector<cost_type> weights;\n\
    \n    int rooting(int x) {\n        if (parents[x] == x) {\n            return\
    \ x;\n        }\n        else {\n            int root = rooting(parents[x]);\n\
    \            weights[x] += weights[parents[x]];\n            return parents[x]\
    \ = root;\n        }\n    }\n\n    cost_type get_weight(int x) {\n        rooting(x);\n\
    \        return weights[x];\n    }\n\npublic:\n\n    potentialized_unionfind(std::size_t\
    \ n) : parents(n, 0), sizes(n, 1), weights(n) {\n        for (std::size_t i =\
    \ 0 ; i < n ; i++) {\n            parents[i] = i;\n        }\n    }\n\n    int\
    \ leader(int x) {\n        return rooting(x);\n    }\n\n    bool same(int x, int\
    \ y) {\n        return rooting(x) == rooting(y);\n    }\n\n    bool merge(int\
    \ x, int y, cost_type w) {\n        w += get_weight(x);\n        w -= get_weight(y);\n\
    \        int rx = rooting(x), ry = rooting(y);\n        if (rx == ry) {\n    \
    \        return false;\n        }\n        if (sizes[rx] < sizes[ry]) {\n    \
    \        std::swap(rx, ry);\n            w *= -1;\n        }\n        sizes[rx]\
    \ += sizes[ry];\n        parents[ry] = rx;\n        weights[ry] = w;\n       \
    \ return true;\n    }\n\n    cost_type diff(int y, int x) {\n        return get_weight(y)\
    \ - get_weight(x);\n    }\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-05 12:46:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/potentialized_unionfind3.test.cpp
  - test/potentialized_unionfind1.test.cpp
  - test/potentialized_unionfind2.test.cpp
documentation_of: src/dataStructure/potentialized_unionfind.hpp
layout: document
title: "potentialized_unionfind (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
  Union Find\u6728)"
---

## 概要
直線上の`N`個の点について、点`A`が点`B`より正方向に`d`だけ離れているといった情報を保持できるデータ構造です。

UnionFindアルゴリズムを応用することで実装しています。

## 機能
- `potentialized_unionfind<cost_type> (std::size_t n)`
	- コンストラクタ
	- `cost_type`: `d`の型
		- 加法単位元と加法逆元が存在する必要があります
		- 0 と *= -1があればコンパイルは通るはず（？）
	- `n`:点数`N`
	- **計算量**: $O(n)$

- `int leader(int x)`
	- 点`x`が属する根付き木の根を返します
	- `x`: $0\ \le\ x\ \le\ n$
	- **計算量**: 

- `bool same(int x, int y)`
	- 点`x`と点`y`が連結かを返します
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- **計算量**: 

- `bool merge(int x, int y, cost_type w)`
	- 「点`x`から正方向に`w`離れた所に点`y`がある」という情報を追加します。
		- 矛盾した情報を与えた場合の動作は未定義です。
		- クエリに矛盾する情報があるかもしれない時は`test/potentialized_unionfind3.test.cpp`みたいな感じで別途処理してください
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- `same(x, y) == false`の時この関数は`true`を返します
	- **計算量**: 

- `cost_type diff(int y, int x)`
	- 点`x`から点`y`へ正方向にどれだけ離れているかを返します。
		- `same(x, y) == false`の時の動作は未定義です。
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- **計算量**: 

## 参考

[重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
