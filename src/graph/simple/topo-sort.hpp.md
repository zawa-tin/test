---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC285D.test.cpp
    title: test/ABC285D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-toposo.test.cpp
    title: test/simple-toposo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/topo-sort.hpp\"\n\n#include <vector>\n\
    #include <queue>\n\nnamespace zawa {\n\nclass topo_sort {\nprivate:\n\tstd::vector<int>\
    \ sorted;\n\tbool is_dag;\n\n\tbool build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tstd::vector<int> ins(G.size(), 0);\n\t\tfor (const auto& g : G) {\n\
    \t\t\tfor (auto x : g) {\n\t\t\t\tins[x]++;\n\t\t\t}\n\t\t}\n\t\tstd::queue<int>\
    \ que;\n\t\tfor (int i = 0 ; i < (int)ins.size() ; i++) {\n\t\t\tif (ins[i] ==\
    \ 0) {\n\t\t\t\tque.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (que.size()) {\n\t\t\t\
    int v = que.front();\n\t\t\tque.pop();\n\t\t\tsorted.push_back(v);\n\t\t\tfor\
    \ (auto x : G[v]) {\n\t\t\t\tins[x]--;\n\t\t\t\tif (ins[x] == 0) {\n\t\t\t\t\t\
    que.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn sorted.size() == G.size();\n\
    \t}\n\npublic:\n\ttopo_sort(const std::vector<std::vector<int>>& G) {\n\t\tis_dag\
    \ = build(G);\t\n\t}\n\n\ttemplate <class cost_type>\n\ttopo_sort(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\t\t\
    for (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i]) {\n\
    \t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tis_dag = build(tmp_G);\n\t\
    }\n\n\tint operator [](int i) {\n\t\treturn sorted[i];\n\t}\n\t\n\tstd::vector<int>\
    \ get() {\n\t\treturn sorted;\n\t}\n\n\tbool ok() {\n\t\treturn is_dag;\t\n\t\
    }\n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n\nnamespace zawa {\n\
    \nclass topo_sort {\nprivate:\n\tstd::vector<int> sorted;\n\tbool is_dag;\n\n\t\
    bool build(const std::vector<std::vector<int>>& G) {\n\t\tstd::vector<int> ins(G.size(),\
    \ 0);\n\t\tfor (const auto& g : G) {\n\t\t\tfor (auto x : g) {\n\t\t\t\tins[x]++;\n\
    \t\t\t}\n\t\t}\n\t\tstd::queue<int> que;\n\t\tfor (int i = 0 ; i < (int)ins.size()\
    \ ; i++) {\n\t\t\tif (ins[i] == 0) {\n\t\t\t\tque.push(i);\n\t\t\t}\n\t\t}\n\t\
    \twhile (que.size()) {\n\t\t\tint v = que.front();\n\t\t\tque.pop();\n\t\t\tsorted.push_back(v);\n\
    \t\t\tfor (auto x : G[v]) {\n\t\t\t\tins[x]--;\n\t\t\t\tif (ins[x] == 0) {\n\t\
    \t\t\t\tque.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn sorted.size() == G.size();\n\
    \t}\n\npublic:\n\ttopo_sort(const std::vector<std::vector<int>>& G) {\n\t\tis_dag\
    \ = build(G);\t\n\t}\n\n\ttemplate <class cost_type>\n\ttopo_sort(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\t\t\
    for (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i]) {\n\
    \t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tis_dag = build(tmp_G);\n\t\
    }\n\n\tint operator [](int i) {\n\t\treturn sorted[i];\n\t}\n\t\n\tstd::vector<int>\
    \ get() {\n\t\treturn sorted;\n\t}\n\n\tbool ok() {\n\t\treturn is_dag;\t\n\t\
    }\n};\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/topo-sort.hpp
  requiredBy: []
  timestamp: '2023-01-08 01:45:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-toposo.test.cpp
  - test/ABC285D.test.cpp
documentation_of: src/graph/simple/topo-sort.hpp
layout: document
title: "topo-sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 simple ver)"
---

## 概要
有効グラフ $G(V, E)$ をトポロジカルソートします。

トポロジカルソートについては[Wikipedia](https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88) を確認してください

## 機能

`topo_sort(const std::vector<std::vector<int>>& G)`

`topo_sort<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- コンストラクタ
- (可能ならば) トポロジカルソートした頂点番号の列を一つ構築します。
- `G`: $G$ の隣接リスト
	- $(i, x)\ \in\ E$ なるすべての $x$ について、$x\ \in$ `G[i]`であれば良いです。
	- 辺に重みがあるグラフでは下のコンストラクタ
	- `zawa::read_graph` でAtCoderの入力形式から対応する`G`を作成できます。
- **計算量**: $(O(\mid V\mid\ +\ \mid E\mid))$


`bool topo_sort::ok()`
- $G$ がDAGかどうか（トポロジカルソートができたか）を判定します。
- **単体テストをしていません**
- **計算量** : $O(1)$

`int topo_sort operator[](int i)`
- ソート列における $i$ 番目の頂点を返します。
- 値返しなので書き換えできないことに注意してください

`std::vector<int> topo_sort::get()`
- ソート列を返します。
- **単体テストをしていません**
