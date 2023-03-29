---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/base.hpp
    title: "base (\u30D9\u30FC\u30B9)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/ccw.hpp
    title: "ccw (\u30D9\u30AF\u30C8\u30EB\u306E\u4F4D\u7F6E\u95A2\u4FC2)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/line.hpp
    title: "line (\u76F4\u7DDA)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/projection.hpp
    title: "projection (\u5C04\u5F71)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/reflection.hpp
    title: "reflection (\u53CD\u5C04)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/relation.hpp
    title: "relation (\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u540C\u58EB\u306E\u4F4D\
      \u7F6E\u95A2\u4FC2)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/segment.hpp
    title: "segment (\u7DDA\u5206)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC259-B.test.cpp
    title: test/ABC259-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJCGL-2A.test.cpp
    title: test/AOJCGL-2A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJCGL-2B.test.cpp
    title: test/AOJCGL-2B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ccw.test.cpp
    title: test/ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/projection.test.cpp
    title: test/projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/reflection.test.cpp
    title: test/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometryR2/point.hpp\"\n\n#line 2 \"src/geometryR2/base.hpp\"\
    \n\n#include <cmath>\n\nnamespace geoR2 {\n\nusing real = long double;\n\nconst\
    \ real PI = acosl(-1);\n\ninline real &eps() {\n\tstatic real EPS = 1e-14;\n\t\
    return EPS;\n}\n\ninline void setEps(const real& EPS = 1e-14) {\n\teps() = EPS;\n\
    }\n\ninline int sgn(const real& value) {\n\treturn (value < -eps() ? -1 : (value\
    \ > +eps() ? 1 : 0));\n}\n\ninline bool equals(const real& a, const real& b) {\n\
    \treturn sgn(a - b) == 0;\n}\n\ninline real toRadian(const real& value) {\n\t\
    return (value * PI) / 180;\n}\n\n} // namespace geoR2\n\nnamespace literals {\n\
    \ngeoR2::real operator\"\" _rad(unsigned long long value) {\n\treturn (static_cast<geoR2::real>(value)\
    \ * geoR2::PI) / static_cast<geoR2::real>(180);\n}\n\n} // namespace literals\n\
    \nusing namespace literals;\n#line 4 \"src/geometryR2/point.hpp\"\n\n#line 6 \"\
    src/geometryR2/point.hpp\"\n#include <istream>\n#include <ostream>\n\nnamespace\
    \ geoR2 {\n\nstruct point {\n\treal x, y;\n\t\n\tpoint() : x(0), y(0) {}\n\tpoint(const\
    \ real& _x, const real& _y) : x(_x), y(_y) {}\n\n\tfriend std::ostream &operator\
    \ <<(std::ostream& os, const point& p) {\n\t\treturn os << p.x << ' ' << p.y;\n\
    \t}\n\tfriend std::istream &operator >>(std::istream& is, point& p) {\n\t\tis\
    \ >> p.x >> p.y;\n\t\treturn is;\n\t}\n\t\n\tpoint &operator +=(const point& p)\
    \ {\n\t\tx += p.x; y += p.y;\n\t\treturn *this;\n\t}\n\tpoint &operator -=(const\
    \ point& p) {\n\t\tx -= p.x; y -= p.y;\n\t\treturn *this;\n\t}\n\tpoint &operator\
    \ *=(const real& k) {\n\t\tx *= k; y *= k;\n\t\treturn *this;\n\t}\n\tpoint &operator\
    \ /=(const real& k) {\n\t\tx /= k; y /= k;\n\t\treturn *this;\n\t}\n\n\tpoint\
    \ operator +(const point& p) const {\n\t\treturn point(*this) += p;\t\n\t}\n\t\
    point operator -(const point& p) const {\n\t\treturn point(*this) -= p;\n\t}\n\
    \tpoint operator *(const real& k) const {\n\t\treturn point(*this) *= k;\n\t}\n\
    \tfriend point operator *(const real& r, const point& p) {\n\t\treturn point(p)\
    \ *= r;\n\t}\n\tpoint operator /(const real& k) const {\n\t\treturn point(*this)\
    \ /= k;\n\t}\n\tpoint operator +() const {\n\t\treturn point(*this);\n\t}\n\t\
    point operator -() const {\n\t\treturn point(-x, -y);\n\t}\n\n\treal squareDistance()\
    \ const {\n\t\treturn x * x + y * y;\n\t}\n\n\treal distance() const {\n\t\treturn\
    \ sqrtl(x * x + y + y);\n\t}\n\n\tpoint rotated(const real& theta) const {\n\t\
    \treturn point(x * cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta));\n\
    \t}\n};\n\nreal dot(const point& a, const point& b) {\n\treturn a.x * b.x + a.y\
    \ * b.y;\n}\n\nreal cross(const point& a, const point& b) {\n\treturn a.x * b.y\
    \ - a.y * b.x;\n}\n\nbool equals(const point& a, const point& b) {\n\treturn equals(a.x,\
    \ b.x) and equals(a.y, b.y);\n}\n\nusing vec2 = point;\n\n} // namespace geoR2\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <cmath>\n#include <istream>\n\
    #include <ostream>\n\nnamespace geoR2 {\n\nstruct point {\n\treal x, y;\n\t\n\t\
    point() : x(0), y(0) {}\n\tpoint(const real& _x, const real& _y) : x(_x), y(_y)\
    \ {}\n\n\tfriend std::ostream &operator <<(std::ostream& os, const point& p) {\n\
    \t\treturn os << p.x << ' ' << p.y;\n\t}\n\tfriend std::istream &operator >>(std::istream&\
    \ is, point& p) {\n\t\tis >> p.x >> p.y;\n\t\treturn is;\n\t}\n\t\n\tpoint &operator\
    \ +=(const point& p) {\n\t\tx += p.x; y += p.y;\n\t\treturn *this;\n\t}\n\tpoint\
    \ &operator -=(const point& p) {\n\t\tx -= p.x; y -= p.y;\n\t\treturn *this;\n\
    \t}\n\tpoint &operator *=(const real& k) {\n\t\tx *= k; y *= k;\n\t\treturn *this;\n\
    \t}\n\tpoint &operator /=(const real& k) {\n\t\tx /= k; y /= k;\n\t\treturn *this;\n\
    \t}\n\n\tpoint operator +(const point& p) const {\n\t\treturn point(*this) +=\
    \ p;\t\n\t}\n\tpoint operator -(const point& p) const {\n\t\treturn point(*this)\
    \ -= p;\n\t}\n\tpoint operator *(const real& k) const {\n\t\treturn point(*this)\
    \ *= k;\n\t}\n\tfriend point operator *(const real& r, const point& p) {\n\t\t\
    return point(p) *= r;\n\t}\n\tpoint operator /(const real& k) const {\n\t\treturn\
    \ point(*this) /= k;\n\t}\n\tpoint operator +() const {\n\t\treturn point(*this);\n\
    \t}\n\tpoint operator -() const {\n\t\treturn point(-x, -y);\n\t}\n\n\treal squareDistance()\
    \ const {\n\t\treturn x * x + y * y;\n\t}\n\n\treal distance() const {\n\t\treturn\
    \ sqrtl(x * x + y + y);\n\t}\n\n\tpoint rotated(const real& theta) const {\n\t\
    \treturn point(x * cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta));\n\
    \t}\n};\n\nreal dot(const point& a, const point& b) {\n\treturn a.x * b.x + a.y\
    \ * b.y;\n}\n\nreal cross(const point& a, const point& b) {\n\treturn a.x * b.y\
    \ - a.y * b.x;\n}\n\nbool equals(const point& a, const point& b) {\n\treturn equals(a.x,\
    \ b.x) and equals(a.y, b.y);\n}\n\nusing vec2 = point;\n\n} // namespace geoR2\n"
  dependsOn:
  - src/geometryR2/base.hpp
  isVerificationFile: false
  path: src/geometryR2/point.hpp
  requiredBy:
  - src/geometryR2/segment.hpp
  - src/geometryR2/projection.hpp
  - src/geometryR2/reflection.hpp
  - src/geometryR2/line.hpp
  - src/geometryR2/relation.hpp
  - src/geometryR2/ccw.hpp
  timestamp: '2023-03-08 19:12:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJCGL-2A.test.cpp
  - test/ccw.test.cpp
  - test/projection.test.cpp
  - test/ABC259-B.test.cpp
  - test/AOJCGL-2B.test.cpp
  - test/reflection.test.cpp
documentation_of: src/geometryR2/point.hpp
layout: document
title: "point (\u70B9)"
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

**cross**
```
real cross(const point& a, const point& b)
```
`a` と `b` の外積の大きさを返す。

<br />

**equals**
```
bool equals(const point& a, const point& b)
```
`a`と`b`が同じ座標にあるかを(`EPS`を考慮して)判定する。
