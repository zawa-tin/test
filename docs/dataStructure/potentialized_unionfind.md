---
title: potentialized_unionfind (ポテンシャル付きUnion Find木)
documentation_of: //src/dataStructure/potentialized_unionfind.hpp
---

## 概要
直線上の`N`個の点について、点`A`が点`B`より正方向に`d`だけ離れているといった情報を保持できるデータ構造です。

UnionFindアルゴリズムを応用することで実装しています。

## 機能
- `potentialized_unionfind<cost_type> (std::size_t n)`
	- コンストラクタ
	- `cost_type`: `d`の型
		- 加法単位元と加法逆元が存在する必要があります
		- 0 と *= -1があればコンパイルは通るはず（？）
	- `n`:点数`N`
	- **計算量**: $O(n)$

- `int leader(int x)`
	- 点`x`が属する根付き木の根を返します
	- `x`: $0\ \le\ x\ \le\ n$
	- **計算量**: 

- `bool same(int x, int y)`
	- 点`x`と点`y`が連結かを返します
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- **計算量**: 

- `bool merge(int x, int y, cost_type w)`
	- 「点`x`から正方向に`w`離れた所に点`y`がある」という情報を追加します。
		- 矛盾した情報を与えた場合の動作は未定義です。
		- クエリに矛盾する情報があるかもしれない時は`test/potentialized_unionfind3.test.cpp`みたいな感じで別途処理してください
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- `same(x, y) == false`の時この関数は`true`を返します
	- **計算量**: 

- `cost_type diff(int y, int x)`
	- 点`x`から点`y`へ正方向にどれだけ離れているかを返します。
		- `same(x, y) == false`の時の動作は未定義です。
	- `x`: $0\ \le\ x\ \le\ n$
	- `y`: $0\ \le\ y\ \le\ n$
	- **計算量**: 

## 参考

[重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
