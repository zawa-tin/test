---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/simple-cc1.test.cpp
    title: test/simple-cc1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/connected-components.hpp\"\n\n#include\
    \ <vector>\n\nnamespace zawa {\n\nclass connected_components {\nprivate:\n   \
    \ std::vector<int> ids;\n    std::vector<std::vector<int>> groups;    \n\n   \
    \ void dfs(std::size_t v, int id, std::vector<bool>& used, const std::vector<std::vector<int>>&\
    \ G) {\n        used[v] = true;\n        ids[v] = id;\n        for (auto x : G[v])\
    \ {\n            if (!used[x]) {\n                dfs(x, id, used, G);\n     \
    \       }\n        }\n    }\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n        std::vector used(G.size(), false);\n     \
    \   int id = -1;\n        for (std::size_t i = 0 ; i < G.size() ; i++) {\n   \
    \         if (!used[i]) {\n                dfs(i, ++id, used, G);\n          \
    \  }\n        }\n        groups = std::vector(id + 1, std::vector(0, 0));\n  \
    \      for (std::size_t i = 0 ; i < G.size() ; i++) {\n            groups[ids[i]].push_back((int)i);\n\
    \        }\n    }\n\n    int &operator [](int i) {\n        return ids[i];\n \
    \   }\n\n    inline std::vector<std::vector<int>> &comps() {\n        return groups;\n\
    \    }\n\n    inline std::vector<int> &comp(int id) {\n        return groups[id];\n\
    \    }\n\n    bool same(int i, int j) {\n        return ids[i] == ids[j];\n  \
    \  }\n};\n\ntemplate <class cost_type>\nconnected_components weighted_cc(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n    std::vector tmp_G(G.size(),\
    \ std::vector(0, 0));\n    for (std::size_t i = 0 ; i < G.size() ; i++) {\n  \
    \      for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n     \
    \   }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\nclass connected_components\
    \ {\nprivate:\n    std::vector<int> ids;\n    std::vector<std::vector<int>> groups;\
    \    \n\n    void dfs(std::size_t v, int id, std::vector<bool>& used, const std::vector<std::vector<int>>&\
    \ G) {\n        used[v] = true;\n        ids[v] = id;\n        for (auto x : G[v])\
    \ {\n            if (!used[x]) {\n                dfs(x, id, used, G);\n     \
    \       }\n        }\n    }\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n        std::vector used(G.size(), false);\n     \
    \   int id = -1;\n        for (std::size_t i = 0 ; i < G.size() ; i++) {\n   \
    \         if (!used[i]) {\n                dfs(i, ++id, used, G);\n          \
    \  }\n        }\n        groups = std::vector(id + 1, std::vector(0, 0));\n  \
    \      for (std::size_t i = 0 ; i < G.size() ; i++) {\n            groups[ids[i]].push_back((int)i);\n\
    \        }\n    }\n\n    int &operator [](int i) {\n        return ids[i];\n \
    \   }\n\n    inline std::vector<std::vector<int>> &comps() {\n        return groups;\n\
    \    }\n\n    inline std::vector<int> &comp(int id) {\n        return groups[id];\n\
    \    }\n\n    bool same(int i, int j) {\n        return ids[i] == ids[j];\n  \
    \  }\n};\n\ntemplate <class cost_type>\nconnected_components weighted_cc(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n    std::vector tmp_G(G.size(),\
    \ std::vector(0, 0));\n    for (std::size_t i = 0 ; i < G.size() ; i++) {\n  \
    \      for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n     \
    \   }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/connected-components.hpp
  requiredBy: []
  timestamp: '2022-12-21 10:50:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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
- コンストラクタ
- `G`: グラフの隣接リストを表す`std::vector<std::vector<int>>`
	- `zawa::read_graph`を用いるとAtCoderの入力形式から対応する`G`を作ることができます
- ***計算量***: $O(\mid V\mid + \mid E\mid)$

 `cc operator[](int i)`
 - 頂点 $i$ が含まれる連結成分の`id`を返します。
 - $0\ \le\ i\ <\ \mid V\mid$
	
`inline std::vector<std::vector<int>> &cc.comps()`
- 連結成分の分解状況を返します。
	- [AC Library dsu](https://atcoder.github.io/ac-library/production/document_ja/dsu.html) の`groups`と同じノリです
	- **単体テストをまだしていません**

`inline std::vector<int> &cc.comp(int id)`
- `id` が振られた連結成分の頂点集合を返します。
	- `cc.comps()[id]`と等価です。
	- **単体テストをまだしていません**

`bool cc.same(int i, int j)`
- 頂点 $i$ と頂点 $j$ が同じ連結成分に属するかを判定します。
	- `cc[i] == cc[j]`と等価です。
- **計算量** $O(1)$

`zawa::connected_components weighted_cc<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G)`
- 重み付きグラフ $G$ から`zawa::connected_components` を得ます。
- **計算量** $O(\mid V\mid + \mid E\mid)$
