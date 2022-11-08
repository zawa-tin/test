---
title: Functional Graph (ダブリングK回行動)
documentation_of: //src/graph/Functional-Graph.hpp
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


