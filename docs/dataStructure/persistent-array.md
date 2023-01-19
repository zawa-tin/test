---
title: persistent array
documentation_of: //src/dataStructure/persistent-array.hpp
---

## 概要

$M$ 分木によって実装された完全永続配列です。

列 $A$ に対して、 $i$ 番目のバージョンを $A^i$ と表現するとして、
- $A^t_i$ を $p$ に変更したものを新バージョンとする
- $A^t_i$ を求める

というクエリをすべてのバックアップを取る愚直な手法より高速に求めることが可能です。

## 機能 

**コンストラクタ**

`persistent_array<T, M = 20>(const std::vector<T>& as)`
- 列 `as` で $A$ を初期化する。  $A^0\ =$ `as` となる
- `T`: `as` の型
- `M`: $M$ 分木によって永続配列を表現する
	- 特に指定がない場合、 $M\ =\ 20$ とする
- **計算量** $O(N\log N)$

`persistent_array<T, M = 20>(std::size_t n)`
- $A$ を要素数 $n$ ですべての要素が `T()` である列で初期化する。
- 他、同上計算量

**メンバ関数**

`T get(int time, std::size_t idx)`
- $A^{\text{time}}$ の`idx`番目の要素を取得する。
	- `time` が現行バージョンを超えないように注意
- **計算量** : $O(\log N)$ 

`void set(int time, std::size_t idx, const T& val)`
- $A^\text{time}$ の`idx`番目の要素を`val`に変更したものを最新バージョンとする
- `time`が現行バージョンを超えないように注意
- **計算量** : $O(M\log N)$

`std::size_t size()`
- バージョンの数を取得する
- 最新バージョンは`size() - 1`であるといえる
- **計算量** : $O(1)$
