---
title: makebuc (バケット)
documentation_of: //src/template/makebuc.hpp
---

## 概要

入力で与えた列 $A$ に対して $B_i\ =\ \text{cnt} (i)$ を満たす $B$ を生成して返す。ここで $\text{cnt}(i)$ とは $A_j\ =\ i$ を満たす $j$ の数とする。


## 機能

**関数**

`std::vector<int> zawa::makebuc<T>(const std::vector<T>& A, const T& sup)`
- $A$ のバケットを生成します。
- `T`は`int`以外での使用を想定されていません
- `sup` はバケットのサイズであり、 $\max(A)$ より**真に大きい値**である必要があります。
- **計算量** : $O(\max(\mid A\mid, \text{sup}))$

`std::vector<int> zawa::makebuc(const std::string& S, bool lower = true)`
- 英文字列 $S$ から各文字が出現する回数を保存したバケットを返します。
- $S$ が英小文字の場合引数`lower`に`false`を入れてください
- **計算量** : $O(\mid S\mid)$


## 改修案？

- `std::map<T, int>`でも返せるようにする
- 勝手に座圧してくれるようにする
