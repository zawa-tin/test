---
title: xor-and-semiring (^&)
documentation_of: //src/utility/semiring/xor-and-semiring.hpp
---

## 概要

$\Z$ 上での `bitwise-xor` と `bitwise-and`についての[半環](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%92%B0) を扱う構造体。

## 機能

`zawa::normal_semiring<T>`
- `T` 扱いたい集合

`T id_add`
- 0

`T id_mul`
- -1

`T add(const T& a, const T& b)`
- `a xor b`

`T mul(const T& a, const T& b)`
- `a and b`
