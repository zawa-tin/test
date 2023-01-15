---
title: min-plus-semiring (min+)
documentation_of: //src/utility/semiring/min-plus-semiring.hpp
---

## 概要

$\R\ \cup\ \{\infin \}$ 上での $\min$ と $+$ についての[半環](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%92%B0) を扱う構造体。[トロピカル半環](https://en.wikipedia.org/wiki/Tropical_semiring) とも呼ばれる。

## 機能

`zawa::normal_semiring<T>`
- `T` 扱いたい集合

`T id_add`
- `std::numeric_limits<T>::max`

`T id_mul`
- 0

`T add(const T& a, const T& b)`
- $\min (a, b)$

`T mul(const T& a, const T& b)`
- $a\ +\ b$
- $\infin$ を`id_add`としているため、丸めこみが発生します。
