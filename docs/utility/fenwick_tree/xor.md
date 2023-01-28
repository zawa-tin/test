---
title: fenwick tree xor structure
documentation_of: //src/utility/fenwick_tree/xor.hpp
---

## 概要

`zawa::fenwick_tree`にのせる構造体です。bitwise xorを提供します。


## 機能

- `dat_type`: 型です。 `T`とエイリアスされます
- `static constexpr T id`: `T{}` です
- `static T add(const T& a, const T& b)`: `a xor b`を返します
- `static T inverse(const T& a)` : `a`を返します
