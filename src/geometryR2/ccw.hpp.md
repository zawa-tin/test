---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/base.hpp
    title: "base (\u30D9\u30FC\u30B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/line.hpp
    title: "line (\u76F4\u7DDA)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/point.hpp
    title: "point (\u70B9)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/relation.hpp
    title: "relation (\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u540C\u58EB\u306E\u4F4D\
      \u7F6E\u95A2\u4FC2)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/segment.hpp
    title: "segment (\u7DDA\u5206)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJCGL-2A.test.cpp
    title: test/AOJCGL-2A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJCGL-2B.test.cpp
    title: test/AOJCGL-2B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ccw.test.cpp
    title: test/ccw.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometryR2/ccw.hpp\"\n\n#line 2 \"src/geometryR2/point.hpp\"\
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
    #line 2 \"src/geometryR2/line.hpp\"\n\n#line 4 \"src/geometryR2/line.hpp\"\n\n\
    #include <cassert>\n\nnamespace geoR2 {\n\nstruct line {\n\tpoint a, b;\n\n\t\
    line() : a(0, 0), b(0, 0) {}\n\tline(const point& _a, const point& _b) : a(_a),\
    \ b(_b) {}\n\n\tinline bool isValid() const {\n\t\treturn !equals(a, b);\n\t}\n\
    \n};\n\n} // namespace geo2d\n#line 6 \"src/geometryR2/ccw.hpp\"\n\nnamespace\
    \ geoR2 {\n\nenum class CCW {\n\tCOUNTER_CLOCKWISE,\n\tCLOCKWISE,\n\tONLINE_BACK,\n\
    \tONLINE_FRONT,\n\tON_SEGMENT,\n};\n\nCCW ccw(const vec2& a, const vec2& b) {\n\
    \tint outer = sgn(cross(a, b));\n\tif (outer == 1) {\n\t\treturn CCW::COUNTER_CLOCKWISE;\n\
    \t}\n\telse if (outer == -1) {\n\t\treturn CCW::CLOCKWISE;\n\t}\n\telse if (sgn(dot(a,\
    \ b)) == -1) {\n\t\treturn CCW::ONLINE_BACK;\n\t}\n\telse if (a.squareDistance()\
    \ < b.squareDistance()) {\n\t\treturn CCW::ONLINE_FRONT;\n\t}\n\telse {\n\t\t\
    return CCW::ON_SEGMENT;\n\t}\n}\n\n} // namespace geoR2\n"
  code: "#pragma once\n\n#include \"./point.hpp\"\n#include \"./line.hpp\"\n#include\
    \ \"./base.hpp\"\n\nnamespace geoR2 {\n\nenum class CCW {\n\tCOUNTER_CLOCKWISE,\n\
    \tCLOCKWISE,\n\tONLINE_BACK,\n\tONLINE_FRONT,\n\tON_SEGMENT,\n};\n\nCCW ccw(const\
    \ vec2& a, const vec2& b) {\n\tint outer = sgn(cross(a, b));\n\tif (outer == 1)\
    \ {\n\t\treturn CCW::COUNTER_CLOCKWISE;\n\t}\n\telse if (outer == -1) {\n\t\t\
    return CCW::CLOCKWISE;\n\t}\n\telse if (sgn(dot(a, b)) == -1) {\n\t\treturn CCW::ONLINE_BACK;\n\
    \t}\n\telse if (a.squareDistance() < b.squareDistance()) {\n\t\treturn CCW::ONLINE_FRONT;\n\
    \t}\n\telse {\n\t\treturn CCW::ON_SEGMENT;\n\t}\n}\n\n} // namespace geoR2\n"
  dependsOn:
  - src/geometryR2/point.hpp
  - src/geometryR2/base.hpp
  - src/geometryR2/line.hpp
  isVerificationFile: false
  path: src/geometryR2/ccw.hpp
  requiredBy:
  - src/geometryR2/segment.hpp
  - src/geometryR2/relation.hpp
  timestamp: '2023-03-08 21:36:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJCGL-2A.test.cpp
  - test/ccw.test.cpp
  - test/AOJCGL-2B.test.cpp
documentation_of: src/geometryR2/ccw.hpp
layout: document
title: "ccw (\u30D9\u30AF\u30C8\u30EB\u306E\u4F4D\u7F6E\u95A2\u4FC2)"
---

## 概要

二次元平面上の２つのベクトル $\vec{a}, \vec{b}$ の位置関係を調べます。

## 機能

`namespace geoR2`上で定義されています。

#### enum class

**CCW**
```
enum class CCW {
	COUNTER_CLOCKWISE,
	CLOCKWISE,
	ONLINE_BACK,
	LNLINE_FRONT,
	ON_SEGMENT,
};
```

位置関係をこの5種類に分類します。意味はそれぞれ以下の通りです。

**COUNTER_CLOCKWISE**

$\vec{a}$ を反時計周りに $\theta\ (0\ <\ \theta\ <\ \pi )$ 回転すると$\vec{b}$ と向きが一致する


**CLOCKWISE**

$\vec{a}$ を時計周りに $\theta\ (0\ <\ \theta\ <\ \pi )$ 回転すると$\vec{b}$ と向きが一致する

**ONLINE_BACK**

$\vec{a}$ を $\pi$ 回転すると $\vec{b}$ と向きが一致する


**ONLINE_FRONT**

$k\vec{a} = \vec{b}\ (k > 1, k\in \mathbb{R})$ を満たす $k$ が存在する

**ON_SEGMENT**

$k\vec{a} = \vec{b}\ (0\ \le\ k\ \le\ 1, k\in \mathbb{R})$ を満たす $k$ が存在する

<br />

#### 関数

**ccw**
```
CCW ccw(const vec2& a, const vec2& b)
```

$\vec{a}$ と $\vec{b}$ が前述の`CCW`でどの関係にあるかを返す。
