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
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A
  bundledCode: "#line 1 \"test/AOJCGL-2A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A\"\
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
    \ {\n\t\treturn !equals(a, b);\n\t}\n\n};\n\nbool isOrthogonal(const line& l1,\
    \ const line& l2) {\n\tassert(l1.isValid());\n\tassert(l2.isValid());\n\treturn\
    \ sgn(dot(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n\nbool isParallel(const line& l1,\
    \ const line& l2) {\n\tassert(l1.isValid());\n\tassert(l2.isValid());\n\treturn\
    \ sgn(cross(l1.b - l1.a, l2.b - l2.a)) == 0;\n}\n\n} // namespace geo2d\n#line\
    \ 4 \"test/AOJCGL-2A.test.cpp\"\n\n#include <iostream>\n\nint main() {\n\tusing\
    \ namespace geoR2;\n\tint q; std::cin >> q;\n\tfor (int _ = 0 ; _ < q ; _++) {\n\
    \t\tline l1, l2;\n\t\tstd::cin >> l1.a >> l1.b >> l2.a >> l2.b;\n\t\tif (isParallel(l1,\
    \ l2)) {\n\t\t\tstd::cout << 2 << std::endl;\n\t\t}\n\t\telse if (isOrthogonal(l1,\
    \ l2)) {\n\t\t\tstd::cout << 1 << std::endl;\n\t\t}\n\t\telse {\n\t\t\tstd::cout\
    \ << 0 << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A\"\
    \n\n#include \"../src/geometryR2/line.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\tusing namespace geoR2;\n\tint q; std::cin >> q;\n\tfor (int _ = 0 ; _ <\
    \ q ; _++) {\n\t\tline l1, l2;\n\t\tstd::cin >> l1.a >> l1.b >> l2.a >> l2.b;\n\
    \t\tif (isParallel(l1, l2)) {\n\t\t\tstd::cout << 2 << std::endl;\n\t\t}\n\t\t\
    else if (isOrthogonal(l1, l2)) {\n\t\t\tstd::cout << 1 << std::endl;\n\t\t}\n\t\
    \telse {\n\t\t\tstd::cout << 0 << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/geometryR2/line.hpp
  - src/geometryR2/point.hpp
  - src/geometryR2/base.hpp
  isVerificationFile: true
  path: test/AOJCGL-2A.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 19:51:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJCGL-2A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJCGL-2A.test.cpp
- /verify/test/AOJCGL-2A.test.cpp.html
title: test/AOJCGL-2A.test.cpp
---
