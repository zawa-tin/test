---
title: rerooting (全方位木DP)
documentation_of: //src/graph/rerooting.hpp
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

