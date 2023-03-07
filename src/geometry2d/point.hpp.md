---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/base.hpp
    title: src/geometry2d/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/line.hpp
    title: "line (\u76F4\u7DDA)"
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/projection.hpp
    title: "projection (\u5C04\u5F71)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC259-B.test.cpp
    title: test/ABC259-B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/projection.test.cpp
    title: test/projection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry2d/point.hpp\"\n\n#line 2 \"src/geometry2d/base.hpp\"\
    \n\n#include <cmath>\n\nnamespace geo2d {\n\nusing realType = long double;\n\n\
    const realType PI = acosl(-1);\n\ninline realType &eps() {\n\tstatic realType\
    \ EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const realType& EPS = 1e-14)\
    \ {\n\teps() = EPS;\n}\n\ninline int sgn(const realType& value) {\n\treturn (value\
    \ < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\ninline bool equals(const realType&\
    \ a, const realType& b) {\n\treturn sgn(a - b) == 0;\n}\n\ninline realType toRadian(const\
    \ realType& value) {\n\treturn (value * PI) / static_cast<realType>(180);\n}\n\
    \n} // namespace geo2d\n\nnamespace literals {\n\ngeo2d::realType operator\"\"\
    \ _rad(unsigned long long value) {\n\treturn (static_cast<geo2d::realType>(value)\
    \ * geo2d::PI) / static_cast<geo2d::realType>(180);\n}\n\n} // namespace literals\n\
    \nusing namespace literals;\n#line 4 \"src/geometry2d/point.hpp\"\n\n#include\
    \ <complex>\n#line 7 \"src/geometry2d/point.hpp\"\n#include <istream>\n#include\
    \ <ostream>\n\nnamespace geo2d {\n\nusing point = std::complex<realType>;\n\n\
    point operator *(const point& a, const realType& k) {\n\treturn point(a.real()\
    \ * k, a.imag() * k);\n}\n\nstd::istream &operator >>(std::istream& is, point&\
    \ p) {\n\trealType x, y; is >> x >> y;\n\tp = point(x, y);\n\treturn is;\n}\n\n\
    std::ostream &operator <<(std::ostream& os, const point& p) {\n\treturn os <<\
    \ p.real() << ' ' << p.imag();\n}\n\npoint rotate(const point& p, const realType&\
    \ theta) {\n\treturn point(p.real() * cosl(theta) - p.imag() * sinl(theta), p.real()\
    \ * sinl(theta) + p.imag() * cosl(theta));\n}\n\ninline realType dot(const point&\
    \ a, const point& b) {\n\treturn a.real() * b.real() + a.imag() * b.imag();\n\
    }\n\ninline realType norm(const point& a) {\n\treturn std::norm(a);\n}\n\nbool\
    \ equals(const point& a, const point& b) {\n\treturn equals(a.real(), b.real())\
    \ and equals(a.imag(), b.imag());\n}\n\n} // namespace geo2d\n"
  code: "#pragma once\n\n#include \"./base.hpp\"\n\n#include <complex>\n#include <cmath>\n\
    #include <istream>\n#include <ostream>\n\nnamespace geo2d {\n\nusing point = std::complex<realType>;\n\
    \npoint operator *(const point& a, const realType& k) {\n\treturn point(a.real()\
    \ * k, a.imag() * k);\n}\n\nstd::istream &operator >>(std::istream& is, point&\
    \ p) {\n\trealType x, y; is >> x >> y;\n\tp = point(x, y);\n\treturn is;\n}\n\n\
    std::ostream &operator <<(std::ostream& os, const point& p) {\n\treturn os <<\
    \ p.real() << ' ' << p.imag();\n}\n\npoint rotate(const point& p, const realType&\
    \ theta) {\n\treturn point(p.real() * cosl(theta) - p.imag() * sinl(theta), p.real()\
    \ * sinl(theta) + p.imag() * cosl(theta));\n}\n\ninline realType dot(const point&\
    \ a, const point& b) {\n\treturn a.real() * b.real() + a.imag() * b.imag();\n\
    }\n\ninline realType norm(const point& a) {\n\treturn std::norm(a);\n}\n\nbool\
    \ equals(const point& a, const point& b) {\n\treturn equals(a.real(), b.real())\
    \ and equals(a.imag(), b.imag());\n}\n\n} // namespace geo2d\n"
  dependsOn:
  - src/geometry2d/base.hpp
  isVerificationFile: false
  path: src/geometry2d/point.hpp
  requiredBy:
  - src/geometry2d/line.hpp
  - src/geometry2d/projection.hpp
  timestamp: '2023-03-08 02:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/projection.test.cpp
  - test/ABC259-B.test.cpp
documentation_of: src/geometry2d/point.hpp
layout: document
title: "point (\u70B9)"
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
