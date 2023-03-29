---
title: mo (Mo's Algorithm)
documentation_of: //src/algorithm/mo.hpp
---

## 概要

静的な列 $A$ 上で区間 $[l, r)$ 上のなにかを聞くクエリが沢山飛んでくる状況で、クエリの順番をいい感じに並び替えることで愚直より計算量を改善するテクニック

区間 $[a, b)$ でのクエリの解がわかっている状況で $[a - 1, b)$ $[a + 1, b)$ $[a, b - 1)$ $[a, b + 1)$ のクエリの解が $O(f)$ で求まる時、 $Q$ 個のクエリを全体で $O(fN\sqrt{Q})$ で処理できるようになる。

## 機能

#### mo
```
std::vector<std::tuple<int, int, int>> mo(int N, const std::vector<std::pair<int, int>>& Q)
```

クエリの順番を並び替えて、元のindexを記憶した状態で提供する

`N` は数列の長さ。

引数の `Q` は`first`に $l$ 、 `second` に $r$ を保管した `std::pair<int, int>`の`std::vector`である。**0-indexedの半開区間で取り扱う**ことに注意

返り値は `l, r, index`の順番に保管された `std::vector<std::tuple<int, int, int>>`である。この順番にクエリを処理すれば良い。

## メモ

例えば以下の疑似コードの様に利用する
```
L = 0, R = 0
ans = [0, 0)でのクエリの解
for ([l, r, index] : zawa::mo(Query)):
	while (R < r) (1)
		ansを[L, R)解から[L, R + 1)解に変更する
		R <- R + 1
	while (L > l) (2)
		ansを[L, R)解から[L - 1, R)解に変更する
		L <- L - 1
	while (R > r) (3)
		ansを[L, R)解から[L, R - 1)解に変更する
		R <- R - 1
	while (L < l) (4)
		ansを[L, R)解から[L + 1, R)解に変更する
		L <- L + 1
	index番目のクエリの解答がansに格納されている
```

詳しい実装例はverifyのコードを見ること。`mo.test.cpp`はRSQを処理しているため、例にちょうどよい

## 参考

- [Mo's Algorithmを理解する](https://qiita.com/rp523/items/444966255b9a6c8c4c8e)
- [Mo's algorithm](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
