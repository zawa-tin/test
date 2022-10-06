---
title: Floyd's Cycle Detection (フロイドの循環検出法)
documentation_of: //src/algorithm/Floyd-Cycle-Detection.hpp
---

## 概要
```
impl::Cycle_Info<T> floyd(T s, const F& nxt, int limit = 50000000)
```

有限集合 $A$ の写像 $f$ に関する数列 $s,\ f(s),\ f(f(s)),\ \cdots$ の循環を検出する

## 機能

- 第一引数: 数列の初項
- 第二引数: 写像
- 第三引数: 循環が存在しないと決め打つ項数
	- 鳩の巣原理から $limit\ >\ \mid A \mid$ にしておけばまぁ問題ないはず

- 返り値
	- `T Cycle_Info::start`: 循環開始地点の数列の値
	- `int Cycle_Info::length`: 循環の長さ

## 計算量
$O(\mid A \mid)$
