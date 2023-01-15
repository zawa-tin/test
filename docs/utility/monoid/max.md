---
title: maxモノイド
documentation_of: //src/utility/monoid/max.hpp
---

## 概要

max演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::max_monoid<dat_type>`
- `dat_type`: `int` `long long` など`std::numeric_limits`が定義されているもの

`static constexpr dat_type zawa::max_monoid<dat_type>::id`
- 単位元、`std::numeric_limits<T>::min()`

`static dat_type zawa::max_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- `std::max(a, b)`
