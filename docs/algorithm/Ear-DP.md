---
title: Ear-DP (耳DP)
documentation_of: //src/algorithm/Ear-DP.hpp
---

## 概要
```
zawa::modint<1000000007> ear_dp(std::vector<T> as, std::vector<T> bs)
```


列asに対して、列bsと一致する部分列の取り出し方の数mod 1e9 + 7を求めます。


### 機能
modを変えたいなら実装の
`using mint = zawa::modint<1000000007>`を書き換えてください

### 計算量
asの長さを $N$ 、bsの長さを $M$ として $O(NM)$
