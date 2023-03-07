---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/base.hpp
    title: src/geometry2d/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/point.hpp
    title: "point (\u70B9)"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/projection.hpp
    title: "projection (\u5C04\u5F71)"
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/reflection.hpp
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
  bundledCode: "#line 2 \"src/geometry2d/line.hpp\"\n\n#line 2 \"src/geometry2d/point.hpp\"\
    \n\n#line 2 \"src/geometry2d/base.hpp\"\n\n#include <cmath>\n\nnamespace geo2d\
    \ {\n\nusing realType = long double;\n\nconst realType PI = acosl(-1);\n\ninline\
    \ realType &eps() {\n\tstatic realType EPS = 1e-14;\n\treturn EPS;\n}\n\ninline\
    \ void setEps(const realType& EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline int\
    \ sgn(const realType& value) {\n\treturn (value < -eps() ? -1 : (value > +eps()\
    \ ? 1 : 0));\n}\n\ninline bool equals(const realType& a, const realType& b) {\n\
    \treturn sgn(a - b) == 0;\n}\n\ninline realType toRadian(const realType& value)\
    \ {\n\treturn (value * PI) / static_cast<realType>(180);\n}\n\n} // namespace\
    \ geo2d\n\nnamespace literals {\n\ngeo2d::realType operator\"\" _rad(unsigned\
    \ long long value) {\n\treturn (static_cast<geo2d::realType>(value) * geo2d::PI)\
    \ / static_cast<geo2d::realType>(180);\n}\n\n} // namespace literals\n\nusing\
    \ namespace literals;\n#line 4 \"src/geometry2d/point.hpp\"\n\n#include <complex>\n\
    #line 7 \"src/geometry2d/point.hpp\"\n#include <istream>\n#include <ostream>\n\
    \nnamespace geo2d {\n\nusing point = std::complex<realType>;\n\npoint operator\
    \ *(const point& a, const realType& k) {\n\treturn point(a.real() * k, a.imag()\
    \ * k);\n}\n\nstd::istream &operator >>(std::istream& is, point& p) {\n\trealType\
    \ x, y; is >> x >> y;\n\tp = point(x, y);\n\treturn is;\n}\n\nstd::ostream &operator\
    \ <<(std::ostream& os, const point& p) {\n\treturn os << p.real() << ' ' << p.imag();\n\
    }\n\npoint rotate(const point& p, const realType& theta) {\n\treturn point(p.real()\
    \ * cosl(theta) - p.imag() * sinl(theta), p.real() * sinl(theta) + p.imag() *\
    \ cosl(theta));\n}\n\ninline realType dot(const point& a, const point& b) {\n\t\
    return a.real() * b.real() + a.imag() * b.imag();\n}\n\ninline realType norm(const\
    \ point& a) {\n\treturn std::norm(a);\n}\n\nbool equals(const point& a, const\
    \ point& b) {\n\treturn equals(a.real(), b.real()) and equals(a.imag(), b.imag());\n\
    }\n\n} // namespace geo2d\n#line 4 \"src/geometry2d/line.hpp\"\n\n#include <cassert>\n\
    \nnamespace geo2d {\n\nstruct line {\n\tpoint a, b;\n\tline(const point& _a, const\
    \ point& _b) : a(_a), b(_b) {\n\t\tassert(!equals(a, b));\n\t}\n};\n\n} // namespace\
    \ geo2d\n"
  code: "#pragma once\n\n#include \"./point.hpp\"\n\n#include <cassert>\n\nnamespace\
    \ geo2d {\n\nstruct line {\n\tpoint a, b;\n\tline(const point& _a, const point&\
    \ _b) : a(_a), b(_b) {\n\t\tassert(!equals(a, b));\n\t}\n};\n\n} // namespace\
    \ geo2d\n"
  dependsOn:
  - src/geometry2d/point.hpp
  - src/geometry2d/base.hpp
  isVerificationFile: false
  path: src/geometry2d/line.hpp
  requiredBy:
  - src/geometry2d/projection.hpp
  - src/geometry2d/reflection.hpp
  timestamp: '2023-03-08 02:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/projection.test.cpp
  - test/reflection.test.cpp
documentation_of: src/geometry2d/line.hpp
layout: document
title: "line (\u76F4\u7DDA)"
---

## 概要

二次元平面上の直線を扱う構造体

２つの異なる点によって直線を定義する

## 機能

`namespace geo2d`下で定義されている

**コンストラクタ**
```
line(const point& _a, const point& _b)
```

**制約**

`_a`と`_b`が異なる。すなわち`equals(_a, _b)`が`false`
