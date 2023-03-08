---
title: point (点)
documentation_of: //src/geometryR2/point.hpp
---

## 概要

二次元平面上の点や位置ベクトルを扱うヘッダ

## 機能

`namespace geoR2`下で定義されている。`real`は`geoR2`上での値を扱う型`(= long double)`である。(`base.hpp`でエイリアスされている)

#### エイリアス
```
using vec2 = point;
```

`vec2`でも`point`と同じことができる。状況に応じて頭に優しい方の名前を使うこと

<br />

#### コンストラクタ
```
(1) point()
(2) point(const real& _x, const real& _y) 
```

**(1)**

原点 $(0, 0)$ を代入する

<br />

**(2)**

点 $(x, y)$ を代入する

<br />

#### メンバ変数

**x**
```
real x
```
$x$ 座標

<br />

**y**
```
real y
```
$y$  座標

<br />

#### operator

**<<**
```
friend std::ostream &operator <<(std::ostream& os, const point& p)
```
```
std::cout << p.x << ' ' << p.y;
```
と同義

<br />

**>>**
```
friend std::istream &operator >>(std::istream& is, point& p)
```
```
std::cin >> p.x >> p.y;
```
と同義

**+=, +**
```
point &operator +=(const point& p)
point operator +(const point& p) const
point operator +() const
```

`p`の位置ベクトルを足す `+()`は自身のコピーを返す。

<br />

**-=, -**
```
point &operator -=(const point& p)
point operator -(const point& p) const
```

`p`の位置ベクトルを引く。`-()`は自身を $-1$ した座標のコピーを返す。

<br />

<b>*=, *</b>
```
point &operator *=(const real& k)
```

自身の $x$ 座標と $y$ 座標を $k$ 倍する

<br />

**/=, /**
```
point &operator /=(const real& k)
point operator /(const real& k) const
```

自身の $x$ 座標と $y$ 座標を $k$ で割る

<br />

#### メンバ関数

**squareDistance**
```
real squareDistance() const
```

`L2`ノルム（原点からのユークリッド距離）の二乗を返す。

<br />

**distance**
```
real distance() const
```

`L2`ノルム（原点からのユークリッド距離）を返す。

<br />

**rotated**
```
point rotated(const real& theta) const
```
原点を中心に`theta` rad回転したものを返す。

<br />

### 関数

**dot**
```
real dot(const point& a, const point& b)
```
`a`と`b`の内積を返す。

<br />

**equals**
```
bool equals(const point& a, const point& b)
```
`a`と`b`が同じ座標にあるかを(`EPS`を考慮して)判定する。
