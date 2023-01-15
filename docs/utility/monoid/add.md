---
title: 加法モノイド
documentation_of: //src/utility/monoid/add.hpp
---

## 概要

加法の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::add_monoid<dat_type>`
- `dat_type`: `int` `long long` `modint`など0が代入できるもの

`static constexpr dat_type zawa::add_monoid<dat_type>::id`
- 加法単位元、0

`static dat_type zawa::add_monoid<dat_type>::op(const dat_type& a, const dat_type& b)`
- 加法 a + bを返す
