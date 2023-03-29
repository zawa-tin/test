---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC285-D.test.cpp
    title: test/ABC285-D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ0519.test.cpp
    title: test/AOJ0519.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/simple-topological_sort.test.cpp
    title: test/simple-topological_sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/topological_sort.hpp\"\n\n#include <vector>\n\
    #include <stack>\n\nnamespace zawa {\n\nclass topological_sort {\nprivate:\n\t\
    std::vector<std::vector<int>> G;\n\tstd::vector<int> Ord;\n\tbool is_dag;\n\n\t\
    bool build() {\n\t\tstd::vector<int> In(G.size(), 0);\n\t\tfor (std::size_t i\
    \ = 0 ; i < G.size() ; i++) {\n\t\t\tfor (const auto& v : G[i]) {\n\t\t\t\tIn[v]++;\n\
    \t\t\t}\n\t\t}\n\t\tstd::stack<int> S;\n\t\tfor (std::size_t i = 0 ; i < G.size()\
    \ ; i++) {\n\t\t\tif (!In[i]) {\n\t\t\t\tS.push(i);\n\t\t\t}\n\t\t}\n\t\twhile\
    \ (S.size()) {\n\t\t\tint v = S.top();\n\t\t\tS.pop();\n\t\t\tOrd.push_back(v);\n\
    \t\t\tfor (auto x : G[v]) {\n\t\t\t\tIn[x]--;\n\t\t\t\tif (!In[x]) {\n\t\t\t\t\
    \tS.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn Ord.size() == G.size();\n\t\
    }\n\npublic:\n\ttopological_sort(const std::vector<std::vector<int>>& _G) : G(_G),\
    \ is_dag(build()) {}\t\n\n\ttemplate <class cost_type>\n\ttopological_sort(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& _G) :  G(_G.size()) {\n\
    \t\tfor (std::size_t i = 0 ; i < _G.size() ; i++) {\n\t\t\tfor (auto [v, _] :\
    \ _G[i]) {\n\t\t\t\tG[i].push_back(v);\n\t\t\t}\n\t\t}\t\n\t\tis_dag = build();\n\
    \t}\n\n\tinline bool ok() const {\n\t\treturn is_dag;\n\t}\n\n\tint operator[](int\
    \ i) {\n\t\treturn Ord[i];\n\t}\n\n\tinline std::vector<int> get() const {\n\t\
    \treturn Ord;\n\t}\n\n\tbool unique() const {\n\t\tif (!is_dag) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tbool res = true;\n\t\tfor (std::size_t i = 0 ; i + 1 < G.size()\
    \ ; i++) {\n\t\t\tbool ok = false;\n\t\t\tfor (const auto& v : G[Ord[i]]) {\n\t\
    \t\t\tok |= v == Ord[i + 1];\n\t\t\t}\n\t\t\tres &= ok;\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <stack>\n\nnamespace zawa {\n\
    \nclass topological_sort {\nprivate:\n\tstd::vector<std::vector<int>> G;\n\tstd::vector<int>\
    \ Ord;\n\tbool is_dag;\n\n\tbool build() {\n\t\tstd::vector<int> In(G.size(),\
    \ 0);\n\t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tfor (const auto&\
    \ v : G[i]) {\n\t\t\t\tIn[v]++;\n\t\t\t}\n\t\t}\n\t\tstd::stack<int> S;\n\t\t\
    for (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tif (!In[i]) {\n\t\t\t\t\
    S.push(i);\n\t\t\t}\n\t\t}\n\t\twhile (S.size()) {\n\t\t\tint v = S.top();\n\t\
    \t\tS.pop();\n\t\t\tOrd.push_back(v);\n\t\t\tfor (auto x : G[v]) {\n\t\t\t\tIn[x]--;\n\
    \t\t\t\tif (!In[x]) {\n\t\t\t\t\tS.push(x);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn\
    \ Ord.size() == G.size();\n\t}\n\npublic:\n\ttopological_sort(const std::vector<std::vector<int>>&\
    \ _G) : G(_G), is_dag(build()) {}\t\n\n\ttemplate <class cost_type>\n\ttopological_sort(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& _G) :  G(_G.size()) {\n\
    \t\tfor (std::size_t i = 0 ; i < _G.size() ; i++) {\n\t\t\tfor (auto [v, _] :\
    \ _G[i]) {\n\t\t\t\tG[i].push_back(v);\n\t\t\t}\n\t\t}\t\n\t\tis_dag = build();\n\
    \t}\n\n\tinline bool ok() const {\n\t\treturn is_dag;\n\t}\n\n\tint operator[](int\
    \ i) {\n\t\treturn Ord[i];\n\t}\n\n\tinline std::vector<int> get() const {\n\t\
    \treturn Ord;\n\t}\n\n\tbool unique() const {\n\t\tif (!is_dag) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\tbool res = true;\n\t\tfor (std::size_t i = 0 ; i + 1 < G.size()\
    \ ; i++) {\n\t\t\tbool ok = false;\n\t\t\tfor (const auto& v : G[Ord[i]]) {\n\t\
    \t\t\tok |= v == Ord[i + 1];\n\t\t\t}\n\t\t\tres &= ok;\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-02-27 01:26:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-topological_sort.test.cpp
  - test/AOJ0519.test.cpp
  - test/ABC285-D.test.cpp
documentation_of: src/graph/simple/topological_sort.hpp
layout: document
title: "topological_sort (\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8)"
---

## 概要

入力で与えられた有向グラフ $G(V, E)$ を[トポロジカルソート](https://ja.wikipedia.org/wiki/%E3%83%88%E3%83%9D%E3%83%AD%E3%82%B8%E3%82%AB%E3%83%AB%E3%82%BD%E3%83%BC%E3%83%88) します。


## 機能

#### コンストラクタ

```
(1) zawa::topological_sort(const std::vector<std::vector<int>>& _G)
(2) zawa::topological_sort<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& _G)
```

**(1)**

`_G` $G$ の隣接リスト表現です。正確には以下の条件を満たす `std::vector<std::vector<int>>` です


頂点 $u$ から頂点 $v$ への有向辺が存在する時、その時に限り `G[u][i] = v` なる $i$ が存在する

AtCoder等のグラフの一般的な入力形式
```
N M
u_1 v_1
...
u_M v_M
```

に対して `read_graph(n, m, false)` とすることで対応する `_G` を作成することが可能です。しかし、第三引数をデフォルト引数の `true` から `false`に変えるという注意が必要なため、自身で `G` を作成することをおすすめします

<br />

**(2)**

辺重みがある $G$ に対してはこちらを利用します。

頂点 $u$ から頂点 $v$ へのコスト`c`の有向辺が存在する時、その時に限り `G[u][i] = std::pair<int, cost_type>(v, c)` なる $i$ が存在する

ことが`_G`の条件です

**このコンストラクタは未テストです**

**計算量**: (1)(2)共に $O(\mid V\mid + \mid E\mid)$

<br />

#### operator

**[]**
```
int operator[](int i)
```
トポロジカルソート列 $A$ について $A_i$ を返します。

**制約**

$0\ \le\ i\ <\ \mid V\mid$

$G$ はトポロジカルソートが可能なグラフである
- 後述のメンバ関数、`ok`等で確認できます

<br />

#### メンバ

**ok**
```
inline bool ok() const 
```

トポロジカルソート列が構築できたかの是非を返します。

トポロジカルソート列が構築できる時、 $G$ は [DAG](https://ja.wikipedia.org/wiki/%E6%9C%89%E5%90%91%E9%9D%9E%E5%B7%A1%E5%9B%9E%E3%82%B0%E3%83%A9%E3%83%95) であると言えます。(美味い性質やDAGであることを利用した典型テクがいくつかある）

**計算量** : 

$O(1)$

<br />

**get**
```
inline std::vector<int> get() const
```

トポロジカルソート列を返します。

**制約**

$G$ はトポロジカルソートが可能なグラフである
- `ok`等で確認できます

**計算量**

$O(\mid V\mid)$

<br />

**unique**
```
bool unique() const
```
 $G$ のトポロジカルソートが一意に定まるかを判定します。(そもそもトポロジカルソート列が構築できない場合、`false`が返ります)

**計算量**

$O(\mid V\mid + \mid E\mid)$
