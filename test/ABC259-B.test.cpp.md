---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/base.hpp
    title: src/geometry2d/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry2d/point.hpp
    title: "point (\u70B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc259/submissions/39521262
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC259-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/geometry2d/point.hpp\"\n\n#line 2 \"src/geometry2d/base.hpp\"\
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
    \ and equals(a.imag(), b.imag());\n}\n\n} // namespace geo2d\n#line 4 \"test/ABC259-B.test.cpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n\nint main() {\n\t// using namespace\
    \ geo2d;\n\t// int a, b, c; std::cin >> a >> b >> c;\n\t// std::cout << std::fixed\
    \ << std::setprecision(8);\n\t// std::cout << rotate(point(a, b), toRadian(c))\
    \ << std::endl;\n\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginnet Contest 259 - B Counterclockwise Rotation\n * https://atcoder.jp/contests/abc259/submissions/39521262\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/geometry2d/point.hpp\"\n\n#include <iostream>\n#include\
    \ <iomanip>\n\nint main() {\n\t// using namespace geo2d;\n\t// int a, b, c; std::cin\
    \ >> a >> b >> c;\n\t// std::cout << std::fixed << std::setprecision(8);\n\t//\
    \ std::cout << rotate(point(a, b), toRadian(c)) << std::endl;\n\n\tstd::cout <<\
    \ \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginnet Contest 259 - B\
    \ Counterclockwise Rotation\n * https://atcoder.jp/contests/abc259/submissions/39521262\n\
    \ */\n"
  dependsOn:
  - src/geometry2d/point.hpp
  - src/geometry2d/base.hpp
  isVerificationFile: true
  path: test/ABC259-B.test.cpp
  requiredBy: []
  timestamp: '2023-03-08 02:25:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC259-B.test.cpp
layout: document
redirect_from:
- /verify/test/ABC259-B.test.cpp
- /verify/test/ABC259-B.test.cpp.html
title: test/ABC259-B.test.cpp
---
