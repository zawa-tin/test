---
title: xor_monoid (排他的論理和モノイド)
documentation_of: //src/utility/monoid/xor_monoid.hpp
---

## 概要

xor演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::xor_monoid<T>`
- `T`: `int` `long long` など`operator ^`が定義されているもの、0が代入できるもの

**メンバなど**

`using value_type = T`
- データ構造で利用するために必要なエイリアス

`static constexpr T identity`
- 単位元、0

`static value_type operation(const value_type& a, const value_type& b)`
- `a ^ b`
