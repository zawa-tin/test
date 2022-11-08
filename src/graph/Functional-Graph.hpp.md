---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Functional_Graph.test.cpp
    title: test/Functional_Graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/Functional-Graph.hpp\"\n\n#include <vector>\n\
    #include <tuple>\n\nnamespace zawa {\n\ntemplate <std::size_t log = 63>\nclass\
    \ Functional_Graph {\nprivate:\n    std::vector<int> fs;\n    std::vector<std::vector<int>>\
    \ table;\n\npublic:\n    Functional_Graph(const std::vector<int>& as)\n      \
    \  : fs(as.begin(), as.end())\n        , table(log, std::vector(as.size(), -1))\
    \ {\n        table[0] = as;\n        for (std::size_t i = 0 ; i + 1 < 63 ; i++)\
    \ {\n            for (std::size_t j = 0 ; j < fs.size() ; j++) {\n           \
    \     table[i + 1][j] = table[i][table[i][j]];\n            }\n        }\n   \
    \ }\n\n    inline int f(int x) {\n        return fs[x];\n    }\n\n    int walk(int\
    \ start, long long step) {\n        int res = start;\n        for (std::size_t\
    \ i = 0 ; i < log ; i++) {\n            if (step & 1) {\n                res =\
    \ table[i][res];\n            }\n            step >>= 1;\n        }\n        return\
    \ res;\n    }\n\n    std::tuple<int, int, int> detect(int start) {\n        std::vector\
    \ used(fs.size(), -1);\n        int step = 0;\n        int now = start;\n    \
    \    for ( ; ; step++) {\n            if (~used[now]) {\n                break;\n\
    \            }\n            used[now] = step;\n            now = f(now);\n   \
    \     }\n        return std::tuple(used[now], now, step - used[now]);\n    }\n\
    \n};\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <tuple>\n\nnamespace zawa {\n\
    \ntemplate <std::size_t log = 63>\nclass Functional_Graph {\nprivate:\n    std::vector<int>\
    \ fs;\n    std::vector<std::vector<int>> table;\n\npublic:\n    Functional_Graph(const\
    \ std::vector<int>& as)\n        : fs(as.begin(), as.end())\n        , table(log,\
    \ std::vector(as.size(), -1)) {\n        table[0] = as;\n        for (std::size_t\
    \ i = 0 ; i + 1 < 63 ; i++) {\n            for (std::size_t j = 0 ; j < fs.size()\
    \ ; j++) {\n                table[i + 1][j] = table[i][table[i][j]];\n       \
    \     }\n        }\n    }\n\n    inline int f(int x) {\n        return fs[x];\n\
    \    }\n\n    int walk(int start, long long step) {\n        int res = start;\n\
    \        for (std::size_t i = 0 ; i < log ; i++) {\n            if (step & 1)\
    \ {\n                res = table[i][res];\n            }\n            step >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    std::tuple<int, int, int> detect(int\
    \ start) {\n        std::vector used(fs.size(), -1);\n        int step = 0;\n\
    \        int now = start;\n        for ( ; ; step++) {\n            if (~used[now])\
    \ {\n                break;\n            }\n            used[now] = step;\n  \
    \          now = f(now);\n        }\n        return std::tuple(used[now], now,\
    \ step - used[now]);\n    }\n\n};\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/Functional-Graph.hpp
  requiredBy: []
  timestamp: '2022-11-08 10:32:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Functional_Graph.test.cpp
documentation_of: src/graph/Functional-Graph.hpp
layout: document
title: "Functional Graph (\u30C0\u30D6\u30EA\u30F3\u30B0K\u56DE\u884C\u52D5)"
---

## 概要
```
zawa::Functional_Graph<std::size_t log = 64> (const std::vector<int>& as)
```

Functional Graph を扱います。

**Functional Graphとは**
> $N$ 頂点 $N$ 辺で自己ループを持たない有向グラフ。どの辺も出次数が1である。

## 機能
 - `コンストラクタ`: 各頂点について伸びている辺の向かう先を保存した`std::vector<int>`の参照をとります
 - `inline int f(int x)`: `x`から出る辺の行く先を返します
 - `int walk(int start, long long step)`: 頂点`start`から`step`回辺を辿って移動することを繰り返した後にいる頂点を返します。
 - `std::tuple<int, int, int> detect(int start)`: 頂点`start`を含むグラフの連結成分からサイクルを検出します。返り値の`std::tuple`の中身はそれぞれ「`start`から移動を開始してサイクルに入るまでの最小移動回数」「`start`から移動を開始して最初に辿り着くサイクルの頂点」「サイクルの頂点数」です

## 計算量
- `コンストラクタ`: $O(N\log N)$
- `f`: $O(1)$
- `walk`: $O(\log N)$
- `detect`: $O(N)$

## メモ
ダブリングしゅごい

## TODO?
- あらかじめ連結成分に分解する -> `detect`を高速にする


