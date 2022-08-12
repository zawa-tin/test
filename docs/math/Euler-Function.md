---
title: Euler Function(オイラー関数)
documentation_of: //src/math/Euler-Function.hpp
---

## 概要

```
long long euler_function(long long x)
```

引数 $x$ に対して $x$ 以下の正整数の中で $x$ と互いに素なものの個数を返します。


## 機能
64bit整数に収まる正整数をいれてください。

内部で `zawa::factorize(x)`を呼び出しています。

## 計算量
$O(\sqrt{x})$
