---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC259-B.test.cpp
    title: test/ABC259-B.test.cpp
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
  bundledCode: "#line 2 \"src/geometry2d/base.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ geo2d {\n\nusing realType = long double;\n\nconst realType PI = acosl(-1);\n\
    \ninline realType &eps() {\n\tstatic realType EPS = 1e-14;\n\treturn EPS;\n}\n\
    \ninline void setEps(const realType& EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline\
    \ int sgn(const realType& value) {\n\treturn (value < -eps() ? -1 : (value > +eps()\
    \ ? 1 : 0));\n}\n\ninline bool equals(const realType& a, const realType& b) {\n\
    \treturn sgn(a - b) == 0;\n}\n\ninline realType toRadian(const realType& value)\
    \ {\n\treturn (value * PI) / static_cast<realType>(180);\n}\n\n} // namespace\
    \ geo2d\n\nnamespace literals {\n\ngeo2d::realType operator\"\" _rad(unsigned\
    \ long long value) {\n\treturn (static_cast<geo2d::realType>(value) * geo2d::PI)\
    \ / static_cast<geo2d::realType>(180);\n}\n\n} // namespace literals\n\nusing\
    \ namespace literals;\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace geo2d {\n\nusing realType =\
    \ long double;\n\nconst realType PI = acosl(-1);\n\ninline realType &eps() {\n\
    \tstatic realType EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const realType&\
    \ EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline int sgn(const realType& value) {\n\
    \treturn (value < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\ninline bool equals(const\
    \ realType& a, const realType& b) {\n\treturn sgn(a - b) == 0;\n}\n\ninline realType\
    \ toRadian(const realType& value) {\n\treturn (value * PI) / static_cast<realType>(180);\n\
    }\n\n} // namespace geo2d\n\nnamespace literals {\n\ngeo2d::realType operator\"\
    \" _rad(unsigned long long value) {\n\treturn (static_cast<geo2d::realType>(value)\
    \ * geo2d::PI) / static_cast<geo2d::realType>(180);\n}\n\n} // namespace literals\n\
    \nusing namespace literals;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry2d/base.hpp
  requiredBy:
  - src/geometry2d/point.hpp
  - src/geometry2d/line.hpp
  - src/geometry2d/projection.hpp
  - src/geometry2d/reflection.hpp
  timestamp: '2023-03-08 02:25:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/projection.test.cpp
  - test/reflection.test.cpp
  - test/ABC259-B.test.cpp
documentation_of: src/geometry2d/base.hpp
layout: document
redirect_from:
- /library/src/geometry2d/base.hpp
- /library/src/geometry2d/base.hpp.html
title: src/geometry2d/base.hpp
---
