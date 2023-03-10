---
title: rangeAddMonoid (区間和モノイド)
documentation_of: //src/utility/monoid/rangeAddMonoid.hpp
---

## 概要

加法のモノイドを表現した構造体です。RAQで利用できます

作用を表現する構造体で`a.value + a.size * hoge`とするといい感じになります。

## 機能


#### dat

`テンプレート引数 T`: 型、`operator +`が定義されているもの

`T value`: 保持している値

`std::size_t size`: 保持している区間の長さ


#### range_add_monoid

`テンプレート引数 T` : `dat`の`T`に利用される

`using valueType = dat<T>`
- データ構造で利用するために必要なエイリアス

`static constexpr valueType identity`
- 単位元、 `value = 0`、`size = 0ULL`

`static valueType opration(const valueType& a, const valueType& b)`
- 加法
- `value = a.value + b.value`
- `size = a.size + b.size`
