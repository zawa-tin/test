---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/simple-wf1.test.cpp
    title: test/simple-wf1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/simple/wf.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n#include <limits>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate\
    \ <class cost_type>\nstd::vector<std::vector<cost_type>> wf(const std::vector<std::vector<std::pair<int,\
    \ cost_type>>>& G, cost_type inf = std::numeric_limits<cost_type>::max() / 3)\
    \ {\n    std::vector res(G.size(), std::vector(G.size(), inf));\n    for (std::size_t\
    \ i = 0 ; i < G.size() ; i++) {\n        res[i][i] = 0;\n    }\n    for (std::size_t\
    \ i = 0 ; i < G.size() ; i++) {\n        for (auto [x, w] : G[i]) {\n        \
    \    res[i][x] = std::min(res[i][x], w);\n        }\n    }\n    for (std::size_t\
    \ k = 0 ; k < G.size() ; k++) {\n        for (std::size_t i = 0 ; i < G.size()\
    \ ; i++) {\n            for (std::size_t j = 0 ; j < G.size() ; j++) {\n     \
    \           res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);\n        \
    \    }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <limits>\n\
    #include <algorithm>\n\nnamespace zawa {\n\ntemplate <class cost_type>\nstd::vector<std::vector<cost_type>>\
    \ wf(const std::vector<std::vector<std::pair<int, cost_type>>>& G, cost_type inf\
    \ = std::numeric_limits<cost_type>::max() / 3) {\n    std::vector res(G.size(),\
    \ std::vector(G.size(), inf));\n    for (std::size_t i = 0 ; i < G.size() ; i++)\
    \ {\n        res[i][i] = 0;\n    }\n    for (std::size_t i = 0 ; i < G.size()\
    \ ; i++) {\n        for (auto [x, w] : G[i]) {\n            res[i][x] = std::min(res[i][x],\
    \ w);\n        }\n    }\n    for (std::size_t k = 0 ; k < G.size() ; k++) {\n\
    \        for (std::size_t i = 0 ; i < G.size() ; i++) {\n            for (std::size_t\
    \ j = 0 ; j < G.size() ; j++) {\n                res[i][j] = std::min(res[i][j],\
    \ res[i][k] + res[k][j]);\n            }\n        }\n    }\n    return res;\n\
    }\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/simple/wf.hpp
  requiredBy: []
  timestamp: '2022-12-07 03:13:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/simple-wf1.test.cpp
documentation_of: src/graph/simple/wf.hpp
layout: document
title: "wf (\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9 simple ver)"
---

## 概要

辺重み付きグラフ $G(V, E)$ の全対間最短経路を計算します。

## 機能

`std::vector<std::vector<cost_type>> wf<cost_type>(const std::vector<std::vector<std::pair<int, cost_type>>>& G, cost_type inf = std::numeric_limits<cost_type>::max() / 3)`

- `cost_type`: 辺の重みの型(テンプレート引数)
	- `int`、`long`、`long long`以外での使用を想定していません。

- `G`: グラフの隣接リストを表す二次元`vector`
	- `u`から`v`へのコスト`w`の有向辺 $(u, v, w) \in E$ について、`G[u]`に`std::pair(v, w)`が存在するようにしてください
	- AtCoder等では、`zawa::read_weighted_graph`を用いて標準入力から対応する`G`を生成できます。

- `inf`: テーブル更新の初期値
	- デフォルトで`std::numeric_limits<cost_type>::max() / 3`が定められていますが、自分で指定することを強く推奨します。

- `返り値`: 全対間最短経路を表す二次元`vector`
	- `res[i][j]`に頂点`i`から頂点`j`への最短経路の総コストが入ります。
	- 頂点`i`から頂点`j`に到達できない時に、`res[i][j] == inf`とは**限らない**ことに注意してください(チェックの仕方は例えば`test/simple-wf1.test.cpp`を確認してください)

- **計算量**: $O(\mid V \mid^3)$
	- $O(\mid V \mid^3\ +\ \mid E \mid)$ なのかなと思ったけど、そもそも $\mid E\mid < \mid V \mid^2$ なので....
		- 多重辺？知らない子ですね....
