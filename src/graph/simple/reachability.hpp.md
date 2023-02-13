---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC289-D.test.cpp
    title: test/ABC289-D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/reachability.hpp\"\n\n#include <vector>\n\
    #include <stack>\n#include <utility>\n\nnamespace zawa {\n\nbool reachability(const\
    \ std::vector<std::vector<int>>& G, int from, int to) {\n\tstd::stack<int> stk;\n\
    \tstd::vector visited(G.size(), false);\n\tvisited[from] = true;\n\tstk.emplace(from);\n\
    \twhile (stk.size()) {\n\t\tint v = stk.top();\n\t\tstk.pop();\n\t\tif (v == to)\
    \ {\n\t\t\treturn true;\n\t\t}\n\t\tfor (const auto& x : G[v]) {\n\t\t\tif (!visited[x])\
    \ {\n\t\t\t\tvisited[x] = true;\n\t\t\t\tstk.emplace(x);\n\t\t\t}\n\t\t}\n\t}\n\
    \treturn false;\n}\n\ntemplate <class cost_type>\nbool reachability(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, int from, int to) {\n\tstd::vector tmp(G.size(), std::vector(0,\
    \ 0));\n\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\tfor (auto [x, _] :\
    \ G[i]) {\n\t\t\ttmp[i].emplace(x);\n\t\t}\n\t}\n\treturn reachability(tmp, from,\
    \ to);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n#include <utility>\n\
    \nnamespace zawa {\n\nbool reachability(const std::vector<std::vector<int>>& G,\
    \ int from, int to) {\n\tstd::stack<int> stk;\n\tstd::vector visited(G.size(),\
    \ false);\n\tvisited[from] = true;\n\tstk.emplace(from);\n\twhile (stk.size())\
    \ {\n\t\tint v = stk.top();\n\t\tstk.pop();\n\t\tif (v == to) {\n\t\t\treturn\
    \ true;\n\t\t}\n\t\tfor (const auto& x : G[v]) {\n\t\t\tif (!visited[x]) {\n\t\
    \t\t\tvisited[x] = true;\n\t\t\t\tstk.emplace(x);\n\t\t\t}\n\t\t}\n\t}\n\treturn\
    \ false;\n}\n\ntemplate <class cost_type>\nbool reachability(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, int from, int to) {\n\tstd::vector tmp(G.size(), std::vector(0,\
    \ 0));\n\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\tfor (auto [x, _] :\
    \ G[i]) {\n\t\t\ttmp[i].emplace(x);\n\t\t}\n\t}\n\treturn reachability(tmp, from,\
    \ to);\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/reachability.hpp
  requiredBy: []
  timestamp: '2023-02-13 09:43:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC289-D.test.cpp
documentation_of: src/graph/simple/reachability.hpp
layout: document
title: "reachability (\u5230\u9054\u53EF\u80FD\u6027)"
---

## 概要

有向グラフ $G(V, E)$ 上での頂点 $\text{from}$ から頂点 $\text{to}$ へ到達可能かを判定します。

DFSによる愚直な実装です。

無向グラフに関しては連結成分分解 (`zawa::connected_components::same`) で全く同じことができる上、クエリ回答が可能です。


## 機能

**関数**

`bool zawa::reachability(std::vector<std::vector<int>>& G, int from, int to)`
- `G`: $G$ の隣接リスト表現
	- `G`: $u$ から $v$ への有向辺が存在する時、またその時に限り `G[u][i] = v`なる`i`が存在するようにする
	- AtCoderなどでは`zawa::read_graph(n, m)`とすることで入力から対応する`G`を作成することが可能です。 ( $n\ =\ \mid V\mid, m\ =\ \mid E\mid$ )
- `from`: $\text{from}$
- `to`: $\text{to}$
- 返り値: 到達可能なら`true`、そうでないなら`false`
- **計算量** : $O(\mid V\mid + \mid E\mid)$

`bool zawa::reachability(std::vector<std::vector<std::pair<int, cost_type>>>& G, int from, int to)`
- $E$ に重みがついている場合はこちらをお使いください
	- 最短経路等は求めません。(ダイクストラとか書いて)
- **未テスト**

## 余談

到達可能性問題がクエリとしてたくさん飛んでくる場合
- scc + bitset高速化
- 平面グラフならもっと早いのがあるっぽい？
