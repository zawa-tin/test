---
title: Factorize(素因数分解)
documentation_of: //src/math/factorize.hpp
---

## 概要
```
std::vector<std::pair<long long, int>> factorize(long long x)
```

試し割りを用いた素朴な素因素分解を行います。

### 機能
* `std::vector<std::pair<long long, int>> factorize(long long x)`: 素因素分解をします。

* 返り値はfirstが素因数、secondが次数です

### 制約
$0\ \le\ x$  (上限は$10^{12}$くらいが適切です。多分)

### 計算量
$O(\sqrt{x})$
