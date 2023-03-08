---
title: base (ベース)
documentation_of: //src/geometryR2/base.hpp
---

## 概要

`geometryR2`に属するのほぼ全ての関数、classで利用されるであろうエイリアスや関数をまとめたファイル


## 機能

`namespace geo2d`内で定義される。実際にコンテストで利用する時は`using namespace geo2d`することをおすすめする

**エイリアス**
```
using real = long double
```

値の型

<br />

**定数**
```
const realType PI = acosl(-1);
```
円周率

<br />

**関数**

**eps**
```
inline real &eps()
```
現在のEPSを返します。初期状態では $10^{-14}$ に設定されています。

<br />

**setEps**
```
inline void &setEps(real value = 1e-14)
```
EPSを`value`の値に変更します

<br />

**sgn**
```
inline int sgn(real value)
```
`value`が負なら`-1`を正なら`1`を零なら`0`を返す

<br />

**equals**
```
inline bool equals(const real& a, const real& b)
```

引数に与えた実数`a, b`が等しいか判定する

<br />

**toRadian**
```
real toRadian(const real& value)
```
引数`value`を弧度法にしたものを返す。

<br />

#### ユーザー定義リテラル

`namespace literal`上で定義されている。include時点で`using namespace literal`が適用される

**_rad**
```
geoR2::real operator"" _rad(unsigned long long value)
```

`value`を弧度法にしたものを返す。
