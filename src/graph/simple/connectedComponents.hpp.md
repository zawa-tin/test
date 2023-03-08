---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC199-D.test.cpp
    title: test/ABC199-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC282-D.test.cpp
    title: test/ABC282-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC284-C.test.cpp
    title: test/ABC284-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC289-B.test.cpp
    title: test/ABC289-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/connectedComponents1.test.cpp
    title: test/connectedComponents1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/connectedComponents.hpp\"\n\n#include <vector>\n\
    #include <stack>\n\nnamespace zawa {\n\nclass connectedComponents {\nprivate:\n\
    \tstd::vector<int> ids;\n\tstd::vector<std::vector<int>> groups;    \n\n\tvoid\
    \ build(const std::vector<std::vector<int>>& G) {\n\t\tint id = 0;\n\t\tfor (int\
    \ i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i] == -1) {\n\t\t\t\tids[i]\
    \ = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\t\twhile (stk.size()) {\n\
    \t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\t\t\t\t\tfor (auto x : G[v])\
    \ {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\tids[x] = id;\n\t\t\t\t\t\t\
    \tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tid++;\n\t\t\t}\n\
    \t\t}\n\t\tgroups = std::vector(id, std::vector(0, 0));\n\t\tfor (int i = 0 ;\
    \ i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\t\t}\n\t\
    }\n\npublic:\n\n\tconnectedComponents(const std::vector<std::vector<int>>& G)\
    \ : ids(G.size(), -1) {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\t\
    connectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\t\
    inline int operator [](int i) const {\n\t\treturn ids[i];\n\t}\n\n\tinline std::size_t\
    \ size() const {\n\t\treturn groups.size();\n\t}\n\n\tinline std::size_t size(int\
    \ x) const {\n\t\treturn groups[ids[x]].size();\n\t}\n\n\tinline std::vector<std::vector<int>>\
    \ comps() const {\n\t\treturn groups;\n\t}\n\n\tinline std::vector<int> comp(int\
    \ id) const {\n\t\treturn groups[id];\n\t}\n\n\tbool same(int i, int j) const\
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n\nnamespace zawa {\n\
    \nclass connectedComponents {\nprivate:\n\tstd::vector<int> ids;\n\tstd::vector<std::vector<int>>\
    \ groups;    \n\n\tvoid build(const std::vector<std::vector<int>>& G) {\n\t\t\
    int id = 0;\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i]\
    \ == -1) {\n\t\t\t\tids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\
    \t\twhile (stk.size()) {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\
    \t\t\t\t\tfor (auto x : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\
    \tids[x] = id;\n\t\t\t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tid++;\n\t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0,\
    \ 0));\n\t\tfor (int i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\
    \t\t}\n\t}\n\npublic:\n\n\tconnectedComponents(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\
    \tconnectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\t\
    inline int operator [](int i) const {\n\t\treturn ids[i];\n\t}\n\n\tinline std::size_t\
    \ size() const {\n\t\treturn groups.size();\n\t}\n\n\tinline std::size_t size(int\
    \ x) const {\n\t\treturn groups[ids[x]].size();\n\t}\n\n\tinline std::vector<std::vector<int>>\
    \ comps() const {\n\t\treturn groups;\n\t}\n\n\tinline std::vector<int> comp(int\
    \ id) const {\n\t\treturn groups[id];\n\t}\n\n\tbool same(int i, int j) const\
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/connectedComponents.hpp
  requiredBy: []
  timestamp: '2023-02-15 00:30:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC289-B.test.cpp
  - test/ABC282-D.test.cpp
  - test/ABC199-D.test.cpp
  - test/connectedComponents1.test.cpp
  - test/ABC284-C.test.cpp
documentation_of: src/graph/simple/connectedComponents.hpp
layout: document
title: "connectedComponents (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
---

## 概要

与えられた無向グラフ $G(V, E)$ を連結成分に分解します。

ある頂点の二つ組 $(u, v)$ $u \in V, v \in V$ について、 $u$ から $v$ へのパスが存在する時またその時に限り $u$ と $v$ は同じ連結成分に属します。

## 機能

**コンストラクタ**

`zawa::connectedComponents(const std::vector<std::vector<int>>& G)`

`zawa::connectedComponents<cost_type> cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- `G`: グラフの隣接リストを表す`std::vector<std::vector<int>>`
	- `zawa::read_graph`を用いるとAtCoderの入力形式から対応する`G`を作ることができます
	- 重み付きグラフの場合は`std::vector<std::vector<std::pair<int, cost_type>>>`です。
- ***計算量***: $O(\mid V\mid + \mid E\mid)$

**オペレータ**

 `inline std::vector<int> operator[](int i) const`
 - 頂点 $i$ が含まれる連結成分の`id`を返します。
 - $0\ \le\ i\ <\ \mid V\mid$

**メンバ関数**

`inline std::size_t size() const`
- 連結成分の個数を返します

`inline std::size_t size(int x) const`
- 頂点`x`が属する連結成分の頂点数を返します。
- **単体テストをまだしていません**
	
`inline std::vector<std::vector<int>> comps() const`
- 連結成分の分解状況を返します。
	- [AC Library dsu](https://atcoder.github.io/ac-library/production/document_ja/dsu.html) の`groups`と同じノリです
	- 頂点番号に対して昇順に並んでいます

`inline std::vector<int> comp(int id) const`
- `id` が振られた連結成分の頂点集合を返します。
	- `cc.comps()[id]`と等価です。
	- **単体テストをまだしていません**

`bool same(int i, int j) const`
- 頂点 $i$ と頂点 $j$ が同じ連結成分に属するかを判定します。
	- `cc[i] == cc[j]`と等価です。
- **計算量** $O(1)$
