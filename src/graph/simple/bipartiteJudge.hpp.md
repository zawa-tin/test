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
    path: test/simple-bipartite-judge1.test.cpp
    title: test/simple-bipartite-judge1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/bipartiteJudge.hpp\"\n\n#include <vector>\n\
    #include <stack>\n#include <utility>\n\nnamespace zawa {\n\nclass bipartiteJudge\
    \ {\nprivate:\n\tstd::vector<bool> colors;\n\tbool isBipartiteGraph;\n\n\tvoid\
    \ build(const std::vector<std::vector<int>>& G) {\n\t\tif (G.empty()) {\n\t\t\t\
    return;\n\t\t}\n\t\tstd::stack<std::pair<int, bool>> S;\n\t\tstd::vector<bool>\
    \ used(G.size(), false);\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\
    \tif (!used[i]) {\n\t\t\t\tS.emplace(i, true);\n\t\t\t\tused[i] = true;\n\t\t\t\
    \tcolors[i] = true;\n\t\t\t\twhile (S.size()) {\n\t\t\t\t\tauto [v, col] = S.top();\n\
    \t\t\t\t\tS.pop();\n\t\t\t\t\tfor (const auto& x : G[v]) {\n\t\t\t\t\t\tif (used[x])\
    \ {\n\t\t\t\t\t\t\tisBipartiteGraph &= colors[x] != col;\n\t\t\t\t\t\t}\n\t\t\t\
    \t\t\telse {\n\t\t\t\t\t\t\tused[x] = true;\n\t\t\t\t\t\t\tcolors[x] = !col;\n\
    \t\t\t\t\t\t\tS.emplace(x, !col);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\
    \t}\n\t\t}\n\t}\n\npublic:\n\t\n\tbipartiteJudge(const std::vector<std::vector<int>>&\
    \ G) : colors(G.size()), isBipartiteGraph(true) {\n\t\tbuild(G);\n\t}\n\n\ttemplate\
    \ <class cost_type>\n\tbipartiteJudge(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G) : colors(G.size()), isBipartiteGraph(true) {\n\t\tstd::vector\
    \ tmpG(G.size(), std::vector(0, 0));\n\t\tfor (std::size_t i = 0 ; i < G.size()\
    \ ; i++) {\n\t\t\tfor (const auto& [x, _] : G[i]) {\n\t\t\t\ttmpG[i].push_back(x);\n\
    \t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\tinline const bool ok() const {\n\t\t\
    return isBipartiteGraph;\n\t}\n\n\tinline bool operator[](int i) const {\n\t\t\
    return colors[i];\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n#include <utility>\n\
    \nnamespace zawa {\n\nclass bipartiteJudge {\nprivate:\n\tstd::vector<bool> colors;\n\
    \tbool isBipartiteGraph;\n\n\tvoid build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tif (G.empty()) {\n\t\t\treturn;\n\t\t}\n\t\tstd::stack<std::pair<int,\
    \ bool>> S;\n\t\tstd::vector<bool> used(G.size(), false);\n\t\tfor (int i = 0\
    \ ; i < (int)G.size() ; i++) {\n\t\t\tif (!used[i]) {\n\t\t\t\tS.emplace(i, true);\n\
    \t\t\t\tused[i] = true;\n\t\t\t\tcolors[i] = true;\n\t\t\t\twhile (S.size()) {\n\
    \t\t\t\t\tauto [v, col] = S.top();\n\t\t\t\t\tS.pop();\n\t\t\t\t\tfor (const auto&\
    \ x : G[v]) {\n\t\t\t\t\t\tif (used[x]) {\n\t\t\t\t\t\t\tisBipartiteGraph &= colors[x]\
    \ != col;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse {\n\t\t\t\t\t\t\tused[x] = true;\n\t\
    \t\t\t\t\t\tcolors[x] = !col;\n\t\t\t\t\t\t\tS.emplace(x, !col);\n\t\t\t\t\t\t\
    }\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\t\n\tbipartiteJudge(const\
    \ std::vector<std::vector<int>>& G) : colors(G.size()), isBipartiteGraph(true)\
    \ {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\tbipartiteJudge(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) : colors(G.size()),\
    \ isBipartiteGraph(true) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tfor (const auto& [x,\
    \ _] : G[i]) {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\
    \t}\n\n\tinline const bool ok() const {\n\t\treturn isBipartiteGraph;\n\t}\n\n\
    \tinline bool operator[](int i) const {\n\t\treturn colors[i];\n\t}\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/bipartiteJudge.hpp
  requiredBy: []
  timestamp: '2023-03-04 20:28:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC282-D.test.cpp
  - test/simple-bipartite-judge1.test.cpp
  - test/ABC199-D.test.cpp
documentation_of: src/graph/simple/bipartiteJudge.hpp
layout: document
title: "bipartiteJudge (\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A)"
---

## 概要

グラフ $G(V, E)$ が二部グラフであるかを判定します。

二部グラフとは、グラフの各頂点を二色で塗り分ける方法であって、どの辺で隣接する頂点の対も同じ色で塗られないものが存在するものを指します。

## 機能

#### コンストラクタ

```
(1) zawa::bipartiteJudge(const std::vector<std::vector<int>>& G)
(2) zawa::bipartiteJudge<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G)
```

**(1)**

`G` $G$ の隣接リスト表現です。正確には以下の条件を満たす `std::vector<std::vector<int>>` です

頂点 $u$ から頂点 $v$ への有向辺が存在する時、その時に限り `G[u][i] = v` なる $i$ が存在する

AtCoder等のグラフの一般的な入力形式

```

N M

u_1 v_1

...

u_M v_M

```

に対して `zawa::read_graph(n, m)` とすることで対応する `G` を作成することが可能です。

<br />

**(2)**

辺重みがある $G$ に対してはこちらを利用します。

頂点 $u$ から頂点 $v$ へのコスト`c`の有向辺が存在する時、その時に限り `G[u][i] = std::pair<int, cost_type>(v, c)` なる $i$ が存在する

ことが`G`の条件です

**計算量**: (1)(2)共に $O(\mid V\mid + \mid E\mid)$

<br />

#### operator

**[]**
```
inline bool operator[](int i)
```

$G$ が二部グラフであった場合、このclassはある条件を満たす二色の塗り分けを行っている。このoperatorはそのような塗り分け方を一つ行ったときの頂点 $i$ の色を返す。
- 条件を満たす塗り分け方が複数存在する場合、そのどれが採用されているかは不明

**制約**

$0\ \le\ i\ <\ \mid V\mid$

$G$ が二部グラフである
- 後述のメンバ関数、`ok`で二部グラフかどうかを判定できます。

**計算量**

$O(1)$


<br />

#### メンバ関数

**ok**
```
inline bool ok() const
```

$G$ が二部グラフであるかを判定します。

**計算量**

$O(1)$
