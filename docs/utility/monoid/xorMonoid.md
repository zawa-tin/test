---
title: xorMonoid (排他的論理和モノイド)
documentation_of: //src/utility/monoid/xorMonoid.hpp
---

## 概要

xor演算の[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89)を表現した構造体です。

## 機能

`zawa::xorMonoid<T>`
- `T`: `int` `long long` など`operator ^`が定義されているもの、0が代入できるもの

**メンバ**

`using valueType = T`
- データ構造で利用するために必要なエイリアス

`static constexpr valueType identity`
- 単位元、0

`static valueType operation(const valueType& a, const valueType& b)`
- `a ^ b`
