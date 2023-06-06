---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC220-F.test.cpp
    title: test/ABC220-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC222-F.test.cpp
    title: test/ABC222-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ1595.test.cpp
    title: test/AOJ1595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rerooting.test.cpp
    title: test/rerooting.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/rerooting.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class vertex,\
    \ class edge>\nclass rerooting {\nprivate:\n\tvertex identity;\n\tstd::vector<edge>\
    \ edges;\n\tstd::vector<std::pair<int, int>> pos;\n\tstd::vector<vertex> vertices;\n\
    \tint edgeNum = 0;\n\tint N;\n\npublic:\n\tstruct edgeInfo {\n\t\tint u, v;\n\t\
    \tedge dat;\n\t\tedgeInfo(int _u, int _v, const edge& _dat) : u(_u), v(_v), dat(_dat)\
    \ {}\n\t};\n\n\trerooting(const vertex& _identity, std::size_t _N) \n\t\t: identity(_identity),\
    \ edges(_N - 1), pos(_N - 1), vertices(_N), N(_N) {\n\t\t\tassert(0 < _N);\n\t\
    }\t\n\n\tvoid addEdge(int u, int v, const edge& e) {\n\t\tassert(edgeNum < N -\
    \ 1);\n\t\tassert(0 <= u and u < N);\n\t\tassert(0 <= v and v < N);\n\t\tpos[edgeNum]\
    \ = { u, v };\n\t\tedges[edgeNum] = e;\n\t\tedgeNum++;\n\t}\n\n\tinline edgeInfo\
    \ getEdge(int i) const {\n\t\tassert(i < edgeNum);\n\t\treturn edgeInfo{ pos[i].first,\
    \ pos[i].second, edges[i] };\n\t}\n\n\tinline vertex get(int i) const {\n\t\t\
    assert(0 <= i and i < N);\n\t\treturn vertices[i];\n\t}\n\n\tvoid changeEdge(int\
    \ i, const edge& e) {\n\t\tassert(i < edgeNum);\n\t\tedges[i] = e;\n\t}\n\n\t\
    void assign(int i, const vertex& v) {\n\t\tassert(0 <= i and i < N);\n\t\tvertices[i]\
    \ = v;\n\t}\n\n\ttemplate <class F1, class F2>\n\tstd::vector<vertex> run(const\
    \ F1& merge, const F2& walk) {\n\t\tassert(edgeNum == N - 1);\n\t\tstd::vector<std::vector<std::pair<int,\
    \ int>>> G(N);\n\t\tfor (int i = 0 ; i < N - 1 ; i++) {\n\t\t\tconst auto& [u,\
    \ v] = pos[i];\n\t\t\tG[u].emplace_back(v, i);\n\t\t\tG[v].emplace_back(u, i);\n\
    \t\t}\n\t\tauto dfs = [&](auto dfs, int v, int p) -> vertex {\n\t\t\tfor (const\
    \ auto& [x, i] : G[v]) if (x != p)\n\t\t\t\tvertices[v] = merge(vertices[v], walk(dfs(dfs,\
    \ x, v), edges[i], x, v), x, v);\n\t\t\treturn vertices[v];\n\t\t};\n\t\tdfs(dfs,\
    \ 0, -1);\n\t\tstd::vector<vertex> res(N, identity);\n\t\tauto reroot = [&](auto\
    \ reroot, int v, int p, const vertex& propagating) -> void {\n\t\t\tstd::vector<vertex>\
    \ prefix(G[v].size() + 1, identity), suffix = prefix;\n\t\t\tfor (int i = 0 ;\
    \ i < (int)G[v].size() ; i++) {\n\t\t\t\tconst auto& [x, j] = G[v][i];\n\t\t\t\
    \tprefix[i + 1] = merge(prefix[i], walk((x == p ? propagating : vertices[x]),\
    \ edges[j], x, v), x, v);\n\t\t\t}\n\t\t\tfor (int i = (int)G[v].size() ; i >\
    \ 0 ; i--) {\n\t\t\t\tconst auto& [x, j] = G[v][i - 1];\n\t\t\t\tsuffix[i - 1]\
    \ = merge(suffix[i], walk((x == p ? propagating : vertices[x]), edges[j], x, v),\
    \ x, v);\n\t\t\t}\n\t\t\tres[v] = prefix.back();\n\t\t\tfor (int i = 0 ; i < (int)G[v].size()\
    \ ; i++) {\n\t\t\t\tauto [x, _] = G[v][i];\n\t\t\t\tif (x != p) reroot(reroot,\
    \ x, v, merge(prefix[i], suffix[i + 1], x, v));\n\t\t\t}\n\t\t};\n\t\treroot(reroot,\
    \ 0, -1, identity);\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <cassert>\n\
    \nnamespace zawa {\n\ntemplate <class vertex, class edge>\nclass rerooting {\n\
    private:\n\tvertex identity;\n\tstd::vector<edge> edges;\n\tstd::vector<std::pair<int,\
    \ int>> pos;\n\tstd::vector<vertex> vertices;\n\tint edgeNum = 0;\n\tint N;\n\n\
    public:\n\tstruct edgeInfo {\n\t\tint u, v;\n\t\tedge dat;\n\t\tedgeInfo(int _u,\
    \ int _v, const edge& _dat) : u(_u), v(_v), dat(_dat) {}\n\t};\n\n\trerooting(const\
    \ vertex& _identity, std::size_t _N) \n\t\t: identity(_identity), edges(_N - 1),\
    \ pos(_N - 1), vertices(_N), N(_N) {\n\t\t\tassert(0 < _N);\n\t}\t\n\n\tvoid addEdge(int\
    \ u, int v, const edge& e) {\n\t\tassert(edgeNum < N - 1);\n\t\tassert(0 <= u\
    \ and u < N);\n\t\tassert(0 <= v and v < N);\n\t\tpos[edgeNum] = { u, v };\n\t\
    \tedges[edgeNum] = e;\n\t\tedgeNum++;\n\t}\n\n\tinline edgeInfo getEdge(int i)\
    \ const {\n\t\tassert(i < edgeNum);\n\t\treturn edgeInfo{ pos[i].first, pos[i].second,\
    \ edges[i] };\n\t}\n\n\tinline vertex get(int i) const {\n\t\tassert(0 <= i and\
    \ i < N);\n\t\treturn vertices[i];\n\t}\n\n\tvoid changeEdge(int i, const edge&\
    \ e) {\n\t\tassert(i < edgeNum);\n\t\tedges[i] = e;\n\t}\n\n\tvoid assign(int\
    \ i, const vertex& v) {\n\t\tassert(0 <= i and i < N);\n\t\tvertices[i] = v;\n\
    \t}\n\n\ttemplate <class F1, class F2>\n\tstd::vector<vertex> run(const F1& merge,\
    \ const F2& walk) {\n\t\tassert(edgeNum == N - 1);\n\t\tstd::vector<std::vector<std::pair<int,\
    \ int>>> G(N);\n\t\tfor (int i = 0 ; i < N - 1 ; i++) {\n\t\t\tconst auto& [u,\
    \ v] = pos[i];\n\t\t\tG[u].emplace_back(v, i);\n\t\t\tG[v].emplace_back(u, i);\n\
    \t\t}\n\t\tauto dfs = [&](auto dfs, int v, int p) -> vertex {\n\t\t\tfor (const\
    \ auto& [x, i] : G[v]) if (x != p)\n\t\t\t\tvertices[v] = merge(vertices[v], walk(dfs(dfs,\
    \ x, v), edges[i], x, v), x, v);\n\t\t\treturn vertices[v];\n\t\t};\n\t\tdfs(dfs,\
    \ 0, -1);\n\t\tstd::vector<vertex> res(N, identity);\n\t\tauto reroot = [&](auto\
    \ reroot, int v, int p, const vertex& propagating) -> void {\n\t\t\tstd::vector<vertex>\
    \ prefix(G[v].size() + 1, identity), suffix = prefix;\n\t\t\tfor (int i = 0 ;\
    \ i < (int)G[v].size() ; i++) {\n\t\t\t\tconst auto& [x, j] = G[v][i];\n\t\t\t\
    \tprefix[i + 1] = merge(prefix[i], walk((x == p ? propagating : vertices[x]),\
    \ edges[j], x, v), x, v);\n\t\t\t}\n\t\t\tfor (int i = (int)G[v].size() ; i >\
    \ 0 ; i--) {\n\t\t\t\tconst auto& [x, j] = G[v][i - 1];\n\t\t\t\tsuffix[i - 1]\
    \ = merge(suffix[i], walk((x == p ? propagating : vertices[x]), edges[j], x, v),\
    \ x, v);\n\t\t\t}\n\t\t\tres[v] = prefix.back();\n\t\t\tfor (int i = 0 ; i < (int)G[v].size()\
    \ ; i++) {\n\t\t\t\tauto [x, _] = G[v][i];\n\t\t\t\tif (x != p) reroot(reroot,\
    \ x, v, merge(prefix[i], suffix[i + 1], x, v));\n\t\t\t}\n\t\t};\n\t\treroot(reroot,\
    \ 0, -1, identity);\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/rerooting.hpp
  requiredBy: []
  timestamp: '2023-04-04 17:31:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rerooting.test.cpp
  - test/AOJ1595.test.cpp
  - test/ABC220-F.test.cpp
  - test/ABC222-F.test.cpp
documentation_of: src/graph/rerooting.hpp
layout: document
title: "rerooting (\u5168\u65B9\u4F4D\u6728DP)"
---

## 概要

 与えられた木に対する動的計画法を全ての頂点についてその頂点が木全体の根だった時の結果を計算します。

具体的には、結合則を持つ二項演算 $\oplus$ について

$\displaystyle f(v) = \bigoplus_{x \in \text{child of v}} f(x)$

各 $v$ が根の時の $f(v)$ を求めます。

この説明間違ってそう

## 機能

#### コンストラクタ
```
(1) zawa::rerooting<vertex, edge>(const vertex& _identity, std::size_t _N)
```
グラフを $N$ 頂点 $0$ 辺で初期化します。

テンプレート引数`vertex`: 二項演算の要素を表す構造体です。 $f(v)$ を計算する時に必要なデータを取り入れてください

テンプレート引数: `edge`: 辺にもたせるデータの構造体です。 辺の移動によって $f(v)$ に影響を及ぼすなら、そのデータを取り入れてください

`_identity`: は二項演算の単位元です。必ず指定してください

`_N`: は木の頂点数です

#### メンバ

**addEdge**
```
void addEdge(int u, int v, const edge& e)
```

グラフの辺集合に $(u, v)$ をデータに`e`をもたせた状態で追加します(無向)。

**制約**  
グラフは木である必要があります。$N - 1$ 回より多くの`addEdge`を呼び出すと`assert`に引っかかります。サイクルが存在するかの判定は行いません (追加予定?)

**計算量**  
`e`の空間計算量に依存

<br/>

**changeEdge**
```
void changeEdge(int i, const edge& e)
```
`i`番目に追加した辺のデータを `e`に変更します。

**未テストです**

**制約**  
`i`に`addEdge`の呼び出し回数以上の値を指定すると`assert`にひっかかります

**計算量**  
`e`の空間計算量に依存

<br />

**getEdge**
```
inline edgeinfo getEdge(int i) const 
```
`i`番目に`addEdge`で追加した辺の情報を得ます。

`edgeinfo`は以下のメンバをもつ構造体です。  
```
edgeinfo
	: int u
	: int v それぞれ隣接する頂点
	: edge dat 格納されているデータ
```

**制約**  
`i`に`addEdge`の呼び出し回数以上の値を指定すると`assert`にひっかかります

**計算量**  
`e`の空間計算量に依存

<br />

**get**
```
inline vertex get(int i) const
```
頂点 $i$ のデータを返します。

**制約**

$0\ \le\ i\ <\ N$


<br/>

**assign**
```
void assign(int i, const vertex& v)
```

頂点 $i$ のデータに`v`を代入します。

**制約**

$0\ \le\ i\ <\ N$

<br />

**run**
```
std::vector<vertex> run<F1, F2>(const F1& merge, const F2& walk)
```

全方位木DPを実行します。

`merge`は $u\oplus v$ を行う関数です。 
```
vertex merge(vertex a, vertex b, int x, int v)
```
頂点`v`のデータ `a`に頂点`x`のデータ`b`をマージします。順番がカス！！

無名引数でも動作します。

`walk`は辺を渡った時の`vertex`のデータの変更を行う関数です。
```
vertex edge(vertex a, edge e, int x, int v)
```
頂点`x` のデータ `a` が辺 `e` を渡って頂点 `v`へ移動する。

無名引数でも動作します。

**制約**

以前に`addEdge`を丁度 $N - 1$ 回実行している。グラフは木である

**計算量**

`merge`や`walk`が $O(f)$ で動作するとして、 $O(fN)$

ドキュメントの書き方わからん！test.cppで使い方を確認してくれ未来の自分！！！

## 参考

- [ABC222 editorial](https://atcoder.jp/contests/abc222/editorial/2749)
- [もうひとつの全方位木DP](https://ei1333.hateblo.jp/entry/2018/12/21/004022)

