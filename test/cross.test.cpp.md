---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/base.hpp
    title: "base (\u30D9\u30FC\u30B9)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
  bundledCode: "#line 1 \"test/cross.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#line 2 \"src/geometryR2/point.hpp\"\n\n#line 2 \"src/geometryR2/base.hpp\"\
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
    \ b.x) and equals(a.y, b.y);\n}\n\nusing vec2 = point;\n\n} // namespace geoR2\n\
    #line 4 \"test/cross.test.cpp\"\n\n#include <iostream>\n#include <iomanip>\n\n\
    int main() {\n\tusing namespace geoR2;\n\tpoint p0, p1; std::cin >> p0 >> p1;\n\
    \tint q; std::cin >> q;\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tpoint p2; std::cin\
    \ >> p2;\n\t\treal outer = cross(p1 - p0, p2 - p0);\n\t\treal inner = dot(p1 -\
    \ p0, p2 - p0);\n\t\tif (sgn(outer) == 1) {\n\t\t\tstd::cout << \"COUNTER_CLOCKWISE\"\
    \ << std::endl;\n\t\t}\n\t\telse if (sgn(outer) == -1) {\n\t\t\tstd::cout << \"\
    CLOCKWISE\" << std::endl;\n\t\t}\n\t\telse if (sgn(inner) == -1) {\n\t\t\tstd::cout\
    \ << \"ONLINE_BACK\" << std::endl;\n\t\t}\n\t\telse if (point(p1 - p0).squareDistance()\
    \ < point(p2 - p0).squareDistance()) {\n\t\t\tstd::cout << \"ONLINE_FRONT\" <<\
    \ std::endl;\n\t\t}\n\t\telse {\n\t\t\tstd::cout << \"ON_SEGMENT\" << std::endl;\n\
    \t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#include \"../src/geometryR2/point.hpp\"\n\n#include <iostream>\n#include\
    \ <iomanip>\n\nint main() {\n\tusing namespace geoR2;\n\tpoint p0, p1; std::cin\
    \ >> p0 >> p1;\n\tint q; std::cin >> q;\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\
    \tpoint p2; std::cin >> p2;\n\t\treal outer = cross(p1 - p0, p2 - p0);\n\t\treal\
    \ inner = dot(p1 - p0, p2 - p0);\n\t\tif (sgn(outer) == 1) {\n\t\t\tstd::cout\
    \ << \"COUNTER_CLOCKWISE\" << std::endl;\n\t\t}\n\t\telse if (sgn(outer) == -1)\
    \ {\n\t\t\tstd::cout << \"CLOCKWISE\" << std::endl;\n\t\t}\n\t\telse if (sgn(inner)\
    \ == -1) {\n\t\t\tstd::cout << \"ONLINE_BACK\" << std::endl;\n\t\t}\n\t\telse\
    \ if (point(p1 - p0).squareDistance() < point(p2 - p0).squareDistance()) {\n\t\
    \t\tstd::cout << \"ONLINE_FRONT\" << std::endl;\n\t\t}\n\t\telse {\n\t\t\tstd::cout\
    \ << \"ON_SEGMENT\" << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/geometryR2/point.hpp
  - src/geometryR2/base.hpp
  isVerificationFile: true
  path: test/cross.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 19:12:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/cross.test.cpp
layout: document
redirect_from:
- /verify/test/cross.test.cpp
- /verify/test/cross.test.cpp.html
title: test/cross.test.cpp
---
