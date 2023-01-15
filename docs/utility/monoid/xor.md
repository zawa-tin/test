---
title: 排他的論理和モノイド
documentation_of: //src/utility/monoid/xor.hpp
---

## 概要

xor演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::xor_monoid<dat_type>`
- `dat_type`: `int` `long long` など`operator ^`が定義されているもの、0が代入できるもの

`static constexpr dat_type zawa::xor_monoid<dat_type>::id`
- 単位元、0

`static dat_type zawa::xor_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- `a ^ b`
