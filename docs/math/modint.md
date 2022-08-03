---
title: modint
documentation_of: //src/math/modint.hpp
---

## 概要
```
modint(int x)
```
素数で割った余りを取り続ける

### 機能
* `using mint = modint<mod>;`とすると便利です
* modは必ず素数を入れるようにしてください
* `コンストラクタ`: 引数をとらないと、0が代入されます
* 四則演算、累乗に対応しています(TODO: 対数、平方剰余)


### 計算量
* たしひきかけが定数、わりが$O(logmod)$
