---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/base.hpp
    title: "base (\u30D9\u30FC\u30B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/point.hpp
    title: "point (\u70B9)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/projection.hpp
    title: "projection (\u5C04\u5F71)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/reflection.hpp
    title: "reflection (\u53CD\u5C04)"
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"src/geometryR2/line.hpp\"\n\n#line 2 \"src/geometryR2/point.hpp\"\
    \n\n#line 2 \"src/geometryR2/base.hpp\"\n\n#include <cmath>\n\nnamespace geoR2\
    \ {\n\nusing real = long double;\n\nconst real PI = acosl(-1);\n\ninline real\
    \ &eps() {\n\tstatic real EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const\
    \ real& EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline int sgn(const real& value)\
    \ {\n\treturn (value < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\ninline bool\
    \ equals(const real& a, const real& b) {\n\treturn sgn(a - b) == 0;\n}\n\ninline\
    \ real toRadian(const real& value) {\n\treturn (value * PI) / 180;\n}\n\n} //\
    \ namespace geoR2\n\nnamespace literals {\n\ngeoR2::real operator\"\" _rad(unsigned\
    \ long long value) {\n\treturn (static_cast<geoR2::real>(value) * geoR2::PI) /\
    \ static_cast<geoR2::real>(180);\n}\n\n} // namespace literals\n\nusing namespace\
    \ literals;\n#line 4 \"src/geometryR2/point.hpp\"\n\n#line 6 \"src/geometryR2/point.hpp\"\
    \n#include <istream>\n#include <ostream>\n\nnamespace geoR2 {\n\nstruct point\
    \ {\n\treal x, y;\n\t\n\tpoint() : x(0), y(0) {}\n\tpoint(const real& _x, const\
    \ real& _y) : x(_x), y(_y) {}\n\n\tfriend std::ostream &operator <<(std::ostream&\
    \ os, const point& p) {\n\t\treturn os << p.x << ' ' << p.y;\n\t}\n\tfriend std::istream\
    \ &operator >>(std::istream& is, point& p) {\n\t\tis >> p.x >> p.y;\n\t\treturn\
    \ is;\n\t}\n\t\n\tpoint &operator +=(const point& p) {\n\t\tx += p.x; y += p.y;\n\
    \t\treturn *this;\n\t}\n\tpoint &operator -=(const point& p) {\n\t\tx -= p.x;\
    \ y -= p.y;\n\t\treturn *this;\n\t}\n\tpoint &operator *=(const real& k) {\n\t\
    \tx *= k; y *= k;\n\t\treturn *this;\n\t}\n\tpoint &operator /=(const real& k)\
    \ {\n\t\tx /= k; y /= k;\n\t\treturn *this;\n\t}\n\n\tpoint operator +(const point&\
    \ p) const {\n\t\treturn point(*this) += p;\t\n\t}\n\tpoint operator -(const point&\
    \ p) const {\n\t\treturn point(*this) -= p;\n\t}\n\tpoint operator *(const real&\
    \ k) const {\n\t\treturn point(*this) *= k;\n\t}\n\tfriend point operator *(const\
    \ real& r, const point& p) {\n\t\treturn point(p) *= r;\n\t}\n\tpoint operator\
    \ /(const real& k) const {\n\t\treturn point(*this) /= k;\n\t}\n\tpoint operator\
    \ +() const {\n\t\treturn point(*this);\n\t}\n\tpoint operator -() const {\n\t\
    \treturn point(-x, -y);\n\t}\n\n\treal squareDistance() const {\n\t\treturn x\
    \ * x + y * y;\n\t}\n\n\treal distance() const {\n\t\treturn sqrtl(x * x + y +\
    \ y);\n\t}\n\n\tpoint rotated(const real& theta) const {\n\t\treturn point(x *\
    \ cosl(theta) - y * sinl(theta), x * sinl(theta) + y * cosl(theta));\n\t}\n};\n\
    \nreal dot(const point& a, const point& b) {\n\treturn a.x * b.x + a.y * b.y;\n\
    }\n\nreal cross(const point& a, const point& b) {\n\treturn a.x * b.y - a.y *\
    \ b.x;\n}\n\nbool equals(const point& a, const point& b) {\n\treturn equals(a.x,\
    \ b.x) and equals(a.y, b.y);\n}\n\nusing vec2 = point;\n\n} // namespace geoR2\n\
    #line 4 \"src/geometryR2/line.hpp\"\n\nnamespace geoR2 {\n\nstruct line {\n\t\
    point a, b;\n\tline() : a(0, 0), b(0, 0) {}\n\tline(const point& _a, const point&\
    \ _b) : a(_a), b(_b) {}\n\tbool isValid() const {\n\t\treturn !equals(a, b);\n\
    \t}\n};\n\n} // namespace geo2d\n"
  code: "#pragma once\n\n#include \"./point.hpp\"\n\nnamespace geoR2 {\n\nstruct line\
    \ {\n\tpoint a, b;\n\tline() : a(0, 0), b(0, 0) {}\n\tline(const point& _a, const\
    \ point& _b) : a(_a), b(_b) {}\n\tbool isValid() const {\n\t\treturn !equals(a,\
    \ b);\n\t}\n};\n\n} // namespace geo2d\n"
  dependsOn:
  - src/geometryR2/point.hpp
  - src/geometryR2/base.hpp
  isVerificationFile: false
  path: src/geometryR2/line.hpp
  requiredBy:
  - src/geometryR2/projection.hpp
  - src/geometryR2/reflection.hpp
  timestamp: '2023-03-08 19:12:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/projection.test.cpp
  - test/reflection.test.cpp
documentation_of: src/geometryR2/line.hpp
layout: document
title: "line (\u76F4\u7DDA)"
---

## 概要

二次元平面上の直線を扱う構造体

２つの異なる点 $a, b$ によって直線を定義する

## 機能

`namespace geoR2`下で定義されている

#### コンストラクタ
```
(1)line()
(2)line(const point& _a, const point& _b)
```

**(1)**

$a$ と $b$ を原点で初期化する。これは直線として有効でないので利用する際は値の再代入が必要である。

<br />

**(2)**

$a$ と $b$ を引数の値で初期化する

<br />

#### メンバ関数

**isValid**
```
bool isValid() cosnt
```

直線が正しく定義されているかを判定する。すなわち $a\ne b$ だと`true`を返す。
