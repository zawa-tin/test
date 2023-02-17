---
title: max_monoid (最大値モノイド)
documentation_of: //src/utility/monoid/max_monoid.hpp
---

## 概要

max演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RMQでどうぞ

## 機能

`zawa::max_monoid<T>`
- `T`: `int` `long long` など`std::numeric_limits`が定義されているもの

**メンバなど**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr value_type identity`
- 単位元、`std::numeric_limits<T>::min()`

`static value_type operation(const value_type& a, const value_type& b)`
- `std::max(a, b)`
