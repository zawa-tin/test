---
title: 加法モノイド
documentation_of: //src/utility/monoid/add.hpp
---

## 概要

加法の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。
- RSQの時にでもどうぞ

## 機能

`zawa::add_monoid<T>`
- `T`: `int` `long long` `modint`など0が単位元で加法が定義できるもの

`using value_type = T`
- データ構造で使うために必要なやつ

**メンバ**

`static constexpr value_type identity
- 加法単位元、0

`static value_type operation(const value_type& a, const value_type& b)`
- 加法、a + bを返す
