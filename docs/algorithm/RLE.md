---
title: RLE (連長圧縮)
documentation_of: //src/algorithm/RLE.hpp
---


## 概要
```
std::vector<std::pair<T, int>> rle(const std::vector<T>& ins)
```

引数に入れた`vector`を連長圧縮します。

例えば、`aaabbcdaddd`は`(a, 3)(b, 2)(c, 1)(d, 1)(a, 1)(d, 3)`になります。


## 機能

`std::vector<T>`か`std::string`を引数にとることができます。

`std::string`を引数に入れた場合、`std::vector<std::pair<char, int>>`が返ります。


## 計算量

配列の長さを $N$ として $O(N)$
