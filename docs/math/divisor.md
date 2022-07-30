---
title: Divisor(約数列挙)
documentation_of: //src/math/divisor.hpp
---

## 概要
```
std::vector<int> divisor(int x)
```

試し割りを用いた素朴な約数列挙


### 機能
* `divisor(int x)`: xを約数列挙します。xは32ビットに収まる0以上の整数である必要があります。


### 計算量
- $O(\sqrt(x))$ 
