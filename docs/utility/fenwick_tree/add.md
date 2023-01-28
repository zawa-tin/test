---
title: fenwick tree add structure
documentation_of: //src/utility/fenwick_tree/add.hpp
---

## 概要

`zawa::fenwick_tree`にのせる構造体です。一般的な加法を提供します。


## 機能

- `dat_type`: 型です。 `T`とエイリアスされます
- `static constexpr T id`: `T{}` です
- `static T add(const T& a, const T& b)`: `a + b`を返します
- `static T inverse(const T& a)` : `-a`を返します
