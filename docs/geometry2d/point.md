---
title: point (点)
documentation_of: //src/geometry2d/point.hpp
---

## 概要

二次元平面上の点や位置ベクトルを扱うヘッダ

## 機能

`namespace geo2d`下で定義されている

**エイリアス**
```
using point = std::complex<realType>;
```
点や位置ベクトルを複素数で管理する


<br />


#### operator

```
point operator *(const double& a, const realType& k)
```

点`a`の $x, y$ 座標を $k$ 倍する

<br />

**>>**
```
std::istream &operator >>(std::istream& is, point& p)
```

$x$ 座標、 $y$ 座標の順番で標準入力を受け取る。具体的には
```
std::cin >> p.real() >> p.imag()
```
を
```
std::cin >> p;
```
と書いてよい

<br />

**<<**
```
std::ostream &operator <<(ostream& os, const point& p)
```
 $x$ 座標、 $y$ 座標の順番で標準出力する。具体的には
 ```
 std::cout << p.real() << ' ' << p.imag();
 ```
を
```
std::cout << p;
```
と書いて良い

<br />

#### 関数

**rotate**
```
point rotate(const point& p, const realType& theta)
```
点`p`を原点を中心に`theta`rad回転したものを返す
- 反時計周り

rad変換で頭壊れそうな時は`base.hpp`の`toRadian`等を使ってください(`point.hpp`は`base.hpp`をインクルードするので何もせずとも使えます)

<br />

**dot**
```
inline realType dot(const point& a, const point& b)
```
`a`と`b`の内積を返す

$ a_x \times b_x + a_y \times b_y$ と同義です。

<br />

**norm**
```
inline realTYpe norm(const point& a)
```

`a`の絶対値の二乗を返す。`std::norm(a)`を返すだけ

<br />

**equals**
```
bool equals(const point& a, const point& b)
```
`a`と`b`が等しいか判定する
