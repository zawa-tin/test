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
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/projection.hpp
    title: "projection (\u5C04\u5F71)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/reflection.test.cpp
    title: test/reflection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometryR2/reflection.hpp\"\n\n#line 2 \"src/geometryR2/projection.hpp\"\
    \n\n#line 2 \"src/geometryR2/line.hpp\"\n\n#line 2 \"src/geometryR2/point.hpp\"\
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
    #line 4 \"src/geometryR2/line.hpp\"\n\n#include <cassert>\n\nnamespace geoR2 {\n\
    \nstruct line {\n\tpoint a, b;\n\n\tline() : a(0, 0), b(0, 0) {}\n\tline(const\
    \ point& _a, const point& _b) : a(_a), b(_b) {}\n\n\tinline bool isValid() const\
    \ {\n\t\treturn !equals(a, b);\n\t}\n\n};\n\n} // namespace geo2d\n#line 5 \"\
    src/geometryR2/projection.hpp\"\n\n#line 7 \"src/geometryR2/projection.hpp\"\n\
    \nnamespace geoR2 {\n\npoint projection(const point& p, const line& l) {\n\tassert(l.isValid());\n\
    \treal coeff = dot(l.b - l.a, p - l.a) / vec2(l.b - l.a).squareDistance();\n\t\
    return coeff * l.b + (static_cast<real>(1) - coeff) * l.a;\n}\n\n} // namespace\
    \ geoR2\n#line 4 \"src/geometryR2/reflection.hpp\"\n\nnamespace geoR2 {\n\npoint\
    \ reflection(const point& p, const line& l) {\n\treturn -p + static_cast<real>(2)\
    \ * projection(p, l);\n}\n\n} // namespace geoR2\n"
  code: "#pragma once\n\n#include \"./projection.hpp\"\n\nnamespace geoR2 {\n\npoint\
    \ reflection(const point& p, const line& l) {\n\treturn -p + static_cast<real>(2)\
    \ * projection(p, l);\n}\n\n} // namespace geoR2\n"
  dependsOn:
  - src/geometryR2/projection.hpp
  - src/geometryR2/line.hpp
  - src/geometryR2/point.hpp
  - src/geometryR2/base.hpp
  isVerificationFile: false
  path: src/geometryR2/reflection.hpp
  requiredBy: []
  timestamp: '2023-03-08 21:36:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/reflection.test.cpp
documentation_of: src/geometryR2/reflection.hpp
layout: document
title: "reflection (\u53CD\u5C04)"
---

## 概要

直線 $l$ に対する点 $p$ の反射、すなわち $l$ を軸とした $p$ と対称な点の座標を求めます。

## 機能

**reflection**
```
geoR2::point reflection(const geoR2::point& p, const geoR2::line& l)
```

第一引数が $p$ 、第二引数が $l$ です。

## 導出

TODO
