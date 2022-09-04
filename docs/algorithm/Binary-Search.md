---
title: Binary Search (二分探索)
documentation_of: //src/algorithm/Binary-Search.hpp
---

## 概要
```
T binary_search(T ac, T wa, const F& judge)
```
第三引数`judge`が`true`を返す範囲と`false`を返す値の範囲の境界値を返します。

実装はめぐる式二分探索を参考にしています。

## 制約
- 第一引数`ac`は`judge(ac)`が`true`を返す値である必要があります。
- 第二引数`wa`は`judge(wa)`が`false`を返す値で有る必要があります。
- 第三引数`judge`は`T`を引数に一つ持ち、`bool`値を返す関数である必要があります。
	- 二分探索なので、単調性が無いと正常に動作しません

## 計算量
`judge`関数をおおよそ $log_2 (\mid ac - wa \mid )$ 回呼び出す。
