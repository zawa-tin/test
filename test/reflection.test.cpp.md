---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/base.hpp
    title: src/geometry2d/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/line.hpp
    title: "line (\u76F4\u7DDA)"
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/point.hpp
    title: "point (\u70B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/projection.hpp
    title: "projection (\u5C04\u5F71)"
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/reflection.hpp
    title: "reflection (\u53CD\u5C04)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"test/reflection.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 0.00000001\n\n#line 2 \"src/geometry2d/reflection.hpp\"\n\n#line\
    \ 2 \"src/geometry2d/projection.hpp\"\n\n#line 2 \"src/geometry2d/point.hpp\"\n\
    \n#line 2 \"src/geometry2d/base.hpp\"\n\n#include <cmath>\n\nnamespace geo2d {\n\
    \nusing realType = long double;\n\nconst realType PI = acosl(-1);\n\ninline realType\
    \ &eps() {\n\tstatic realType EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const\
    \ realType& EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline int sgn(const realType&\
    \ value) {\n\treturn (value < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\n\
    inline bool equals(const realType& a, const realType& b) {\n\treturn sgn(a - b)\
    \ == 0;\n}\n\ninline realType toRadian(const realType& value) {\n\treturn (value\
    \ * PI) / static_cast<realType>(180);\n}\n\n} // namespace geo2d\n\nnamespace\
    \ literals {\n\ngeo2d::realType operator\"\" _rad(unsigned long long value) {\n\
    \treturn (static_cast<geo2d::realType>(value) * geo2d::PI) / static_cast<geo2d::realType>(180);\n\
    }\n\n} // namespace literals\n\nusing namespace literals;\n#line 4 \"src/geometry2d/point.hpp\"\
    \n\n#include <complex>\n#line 7 \"src/geometry2d/point.hpp\"\n#include <istream>\n\
    #include <ostream>\n\nnamespace geo2d {\n\nusing point = std::complex<realType>;\n\
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
    \ and equals(a.imag(), b.imag());\n}\n\n} // namespace geo2d\n#line 2 \"src/geometry2d/line.hpp\"\
    \n\n#line 4 \"src/geometry2d/line.hpp\"\n\n#include <cassert>\n\nnamespace geo2d\
    \ {\n\nstruct line {\n\tpoint a, b;\n\tline(const point& _a, const point& _b)\
    \ : a(_a), b(_b) {\n\t\tassert(!equals(a, b));\n\t}\n};\n\n} // namespace geo2d\n\
    #line 5 \"src/geometry2d/projection.hpp\"\n\nnamespace geo2d {\n\npoint projection(const\
    \ point& p, const line& l) {\n\trealType r = dot(l.b - l.a, p - l.a)  / norm(l.b\
    \ - l.a);\n\treturn r * l.b + (static_cast<realType>(1) - r) * l.a;\n}\n\n} //\
    \ namespace geo2d\n#line 4 \"src/geometry2d/reflection.hpp\"\n\nnamespace geo2d\
    \ {\n\npoint reflection(const point& p, const line& l) {\n\treturn -p + static_cast<realType>(2)\
    \ * projection(p, l);\n}\n\n} // namespace geo2d\n#line 5 \"test/reflection.test.cpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nint main() {\n\tusing namespace\
    \ geo2d;\n\tpoint p1, p2; std::cin >> p1 >> p2;\n\tconst line l(p1, p2);\n\tint\
    \ q; std::cin >> q;\n\tstd::cout << std::fixed << std::setprecision(10);\n\tfor\
    \ (int _ = 0 ; _ < q ; _++) {\n\t\tpoint p; std::cin >> p;\n\t\tstd::cout << reflection(p,\
    \ l) << std::endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n#define ERROR 0.00000001\n\n#include \"../src/geometry2d/reflection.hpp\"\n\n\
    #include <iostream>\n#include <iomanip>\n\nint main() {\n\tusing namespace geo2d;\n\
    \tpoint p1, p2; std::cin >> p1 >> p2;\n\tconst line l(p1, p2);\n\tint q; std::cin\
    \ >> q;\n\tstd::cout << std::fixed << std::setprecision(10);\n\tfor (int _ = 0\
    \ ; _ < q ; _++) {\n\t\tpoint p; std::cin >> p;\n\t\tstd::cout << reflection(p,\
    \ l) << std::endl;\n\t}\n}\n"
  dependsOn:
  - src/geometry2d/reflection.hpp
  - src/geometry2d/projection.hpp
  - src/geometry2d/point.hpp
  - src/geometry2d/base.hpp
  - src/geometry2d/line.hpp
  isVerificationFile: true
  path: test/reflection.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 03:07:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/reflection.test.cpp
layout: document
redirect_from:
- /verify/test/reflection.test.cpp
- /verify/test/reflection.test.cpp.html
title: test/reflection.test.cpp
---
