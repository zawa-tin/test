---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/simple-cc1.test.cpp
    title: test/simple-cc1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-cc2.test.cpp
    title: test/simple-cc2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/connected-components.hpp\"\n\n#include\
    \ <vector>\n#include <stack>\n\nnamespace zawa {\n\nclass connected_components\
    \ {\nprivate:\n    std::vector<int> ids;\n    std::vector<std::vector<int>> groups;\
    \    \n\n\tvoid build(const std::vector<std::vector<int>>& G) {\n\t\tint id =\
    \ 0;\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i] == -1)\
    \ {\n\t\t\t\tids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\t\twhile\
    \ (stk.size()) {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\t\t\t\t\
    \tfor (auto x : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\tids[x]\
    \ = id;\n\t\t\t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\
    \t\t\tid++;\n\t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\
    \t\t}\n\t}\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n    }\n\n\ttemplate <class cost_type>\n\
    \tconnected_components(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmp_G);\n\t}\n\n\
    \    int &operator [](int i) {\n        return ids[i];\n    }\n\n\tstd::size_t\
    \ size() {\n\t\treturn groups.size();\n\t}\n\n\tstd::size_t size(int x) {\n\t\t\
    return groups[ids[x]].size();\n\t}\n\n    const std::vector<std::vector<int>>\
    \ &comps() {\n        return groups;\n    }\n\n    const std::vector<int> &comp(int\
    \ id) {\n        return groups[id];\n    }\n\n    bool same(int i, int j) {\n\
    \        return ids[i] == ids[j];\n    }\n};\n\ntemplate <class cost_type>\nconnected_components\
    \ weighted_cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n\
    \    std::vector tmp_G(G.size(), std::vector(0, 0));\n    for (std::size_t i =\
    \ 0 ; i < G.size() ; i++) {\n        for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n\
    \        }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n\nnamespace zawa {\n\
    \nclass connected_components {\nprivate:\n    std::vector<int> ids;\n    std::vector<std::vector<int>>\
    \ groups;    \n\n\tvoid build(const std::vector<std::vector<int>>& G) {\n\t\t\
    int id = 0;\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i]\
    \ == -1) {\n\t\t\t\tids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\
    \t\twhile (stk.size()) {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\
    \t\t\t\t\tfor (auto x : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\
    \tids[x] = id;\n\t\t\t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tid++;\n\t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0,\
    \ 0));\n\t\tfor (int i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\
    \t\t}\n\t}\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n    }\n\n\ttemplate <class cost_type>\n\
    \tconnected_components(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmp_G);\n\t}\n\n\
    \    int &operator [](int i) {\n        return ids[i];\n    }\n\n\tstd::size_t\
    \ size() {\n\t\treturn groups.size();\n\t}\n\n\tstd::size_t size(int x) {\n\t\t\
    return groups[ids[x]].size();\n\t}\n\n    const std::vector<std::vector<int>>\
    \ &comps() {\n        return groups;\n    }\n\n    const std::vector<int> &comp(int\
    \ id) {\n        return groups[id];\n    }\n\n    bool same(int i, int j) {\n\
    \        return ids[i] == ids[j];\n    }\n};\n\ntemplate <class cost_type>\nconnected_components\
    \ weighted_cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n\
    \    std::vector tmp_G(G.size(), std::vector(0, 0));\n    for (std::size_t i =\
    \ 0 ; i < G.size() ; i++) {\n        for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n\
    \        }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/connected-components.hpp
  requiredBy: []
  timestamp: '2023-01-08 00:30:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-cc2.test.cpp
  - test/simple-cc1.test.cpp
documentation_of: src/graph/simple/connected-components.hpp
layout: document
title: "connected components (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
---

## 概要

与えられた無向グラフ $G(V, E)$ を連結成分に分解します。

ある頂点の二つ組 $(u, v)$ $u \in V, v \in V$ について、 $u$ から $v$ へのパスが存在する時またその時に限り $u$ と $v$ は同じ連結成分に属します。

## 機能

`zawa::connected_components cc(const std::vector<std::vector<int>>& G)`

`zawa::connected_components<cost_type> cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- コンストラクタ
- `G`: グラフの隣接リストを表す`std::vector<std::vector<int>>`
	- `zawa::read_graph`を用いるとAtCoderの入力形式から対応する`G`を作ることができます
	- 重み付きグラフの場合は`std::vector<std::vector<std::pair<int, cost_type>>>`です。
- ***計算量***: $O(\mid V\mid + \mid E\mid)$

 `cc operator[](int i)`
 - 頂点 $i$ が含まれる連結成分の`id`を返します。
 - $0\ \le\ i\ <\ \mid V\mid$

`std::size_t cc.size()`
- 連結成分の個数を返します

`std::size_t cc.size(int x)`
- 頂点`x`が属する連結成分の頂点数を返します。
- **単体テストをまだしていません**
	
`const std::vector<std::vector<int>> &cc.comps()`
- 連結成分の分解状況を返します。
	- [AC Library dsu](https://atcoder.github.io/ac-library/production/document_ja/dsu.html) の`groups`と同じノリです
	- **単体テストをまだしていません**

`const std::vector<int> &cc.comp(int id)`
- `id` が振られた連結成分の頂点集合を返します。
	- `cc.comps()[id]`と等価です。
	- **単体テストをまだしていません**

`bool cc.same(int i, int j)`
- 頂点 $i$ と頂点 $j$ が同じ連結成分に属するかを判定します。
	- `cc[i] == cc[j]`と等価です。
- **計算量** $O(1)$
