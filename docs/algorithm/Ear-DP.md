---
title: Ear-DP (耳DP)
documentation_of: //src/algorithm/Ear-DP.hpp
---

## 概要
```
RES ear_dp<T, RES>(std::vector<T> as, std::vector<T> bs)
```


列asに対して、列bsと一致する部分列の取り出し方の数mod 1e9 + 7を求めます。


### 機能
- テンプレート引数は、引数の型、返り値の型の順番です
    - `std::string`の時は一つ目はいらないです

### 計算量
asの長さを $N$ 、bsの長さを $M$ として $O(NM)$
