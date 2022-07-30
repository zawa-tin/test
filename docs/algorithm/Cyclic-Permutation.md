---
title: Cyclic Permutation(巡回置換分解)
documentation_of: //src/algorithm/Cyclic-Permutation.hpp
---

## 概要
```
std::vector<std::vector<int>> decomp_cyclic_permutation(std::vector<T>& arr)
```

引数の配列からソート済の列への置換を巡回置換の積で表現します。

### 機能
* `decomp_cyclic_permutation(std::vector<T>& arr)`: 巡回置換に分解し、`std::vector<std::vector<int>>`の形で返します。0-indexedです。

###  使いどころ
* 列をソートするために必要な二項間swapの最小回数は`N - 連結成分の数`です。

* 他にも[このメモ](https://scrapbox.io/zawakasupublic/%E8%AA%AD%E3%81%BF%E3%83%A1%E3%83%A2_%E7%AB%B6%E3%83%97%E3%83%ADer%E3%81%AE%E3%81%9F%E3%82%81%E3%81%AE%E7%BE%A4%E8%AB%96(swap%E3%81%A8%E9%A0%86%E5%88%97%E3%81%A8%E5%AF%BE%E7%A7%B0%E7%BE%A4))のようなな使いみちがあります

* [元記事](https://koboshi-kyopro.hatenablog.com/entry/2020/08/21/211615)

### 計算量
配列の長さを$N$として$O(N)$
