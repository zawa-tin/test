---
title: rollinghash (ロリハ)
documentation_of: //src/string/rollinghash.hpp
---

## 概要

[ローリングハッシュ](https://en.wikipedia.org/wiki/Rolling_hash) をします。

modは $2^{61} - 1$ 、基数は $10^9$ 以上 $\text{mod}$ 未満です。

## 機能

`zawa::rollinghash<max_length>()`
- コンストラクタ
- 高々`max_length`のサイズの列のハッシュをとることができる
- `max_length`
	- `std::size_t`型
- **計算量**: $O(\text{maxlength})$

`struct info`
- ハッシュに関する構造体
- `std::size_t info::len`: ハッシュした列の長さ
- `long long info::hash`: ハッシュ値
- `bool info::operator==(const info& a)`: 等しいかを確認する`operator`

`std::vector<info> zawa::rollinghash<max_length>::build<T>(const std::vector<T>& A)`
- `A`のローリングハッシュを返します。
- `std::string`にも対応しています。
- **計算量** : $O(\mid A\mid)$

`info zawa::rollinghash<max_length>::hash(const std::vector<info>& H, int l, int r)`
- ローリングハッシュ`H`の`l`から`r - 1`までのハッシュを返す。
- **計算量** : $O(1)$

`info zawa::rollinghash<max_length>::concate(const info& a, const info& b)`
- ハッシュ`a`にハッシュ`b`を後ろから連結したハッシュを返す。
- 連結後の列の長さがうっかり`max_length`を超えないように気をつけること
- **計算量** : $O(1)$

## メモ
[安全で爆足なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6) の $2^{61} - 1$ modを高速に行う方法を妥協してやってないので現状`zawa::rollinghash`は遅い
