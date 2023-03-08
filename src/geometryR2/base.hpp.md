---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/line.hpp
    title: "line (\u76F4\u7DDA)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/point.hpp
    title: "point (\u70B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/projection.hpp
    title: "projection (\u5C04\u5F71)"
  - icon: ':heavy_check_mark:'
    path: src/geometryR2/reflection.hpp
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
  bundledCode: "#line 2 \"src/geometryR2/base.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ geoR2 {\n\nusing real = long double;\n\nconst real PI = acosl(-1);\n\ninline\
    \ real &eps() {\n\tstatic real EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const\
    \ real& EPS = 1e-14) {\n\teps() = EPS;\n}\n\ninline int sgn(const real& value)\
    \ {\n\treturn (value < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\ninline bool\
    \ equals(const real& a, const real& b) {\n\treturn sgn(a - b) == 0;\n}\n\ninline\
    \ real toRadian(const real& value) {\n\treturn (value * PI) / 180;\n}\n\n} //\
    \ namespace geoR2\n\nnamespace literals {\n\ngeoR2::real operator\"\" _rad(unsigned\
    \ long long value) {\n\treturn (static_cast<geoR2::real>(value) * geoR2::PI) /\
    \ static_cast<geoR2::real>(180);\n}\n\n} // namespace literals\n\nusing namespace\
    \ literals;\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace geoR2 {\n\nusing real = long\
    \ double;\n\nconst real PI = acosl(-1);\n\ninline real &eps() {\n\tstatic real\
    \ EPS = 1e-14;\n\treturn EPS;\n}\n\ninline void setEps(const real& EPS = 1e-14)\
    \ {\n\teps() = EPS;\n}\n\ninline int sgn(const real& value) {\n\treturn (value\
    \ < -eps() ? -1 : (value > +eps() ? 1 : 0));\n}\n\ninline bool equals(const real&\
    \ a, const real& b) {\n\treturn sgn(a - b) == 0;\n}\n\ninline real toRadian(const\
    \ real& value) {\n\treturn (value * PI) / 180;\n}\n\n} // namespace geoR2\n\n\
    namespace literals {\n\ngeoR2::real operator\"\" _rad(unsigned long long value)\
    \ {\n\treturn (static_cast<geoR2::real>(value) * geoR2::PI) / static_cast<geoR2::real>(180);\n\
    }\n\n} // namespace literals\n\nusing namespace literals;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometryR2/base.hpp
  requiredBy:
  - src/geometryR2/point.hpp
  - src/geometryR2/line.hpp
  - src/geometryR2/projection.hpp
  - src/geometryR2/reflection.hpp
  timestamp: '2023-03-08 17:47:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/projection.test.cpp
  - test/reflection.test.cpp
  - test/ABC259-B.test.cpp
documentation_of: src/geometryR2/base.hpp
layout: document
title: "base (\u30D9\u30FC\u30B9)"
---

## 概要

`geometryR2`に属するのほぼ全ての関数、classで利用されるであろうエイリアスや関数をまとめたファイル


## 機能

`namespace geo2d`内で定義される。実際にコンテストで利用する時は`using namespace geo2d`することをおすすめする

**エイリアス**
```
using real = long double
```

値の型

<br />

**定数**
```
const realType PI = acosl(-1);
```
円周率

<br />

**関数**

**eps**
```
inline real &eps()
```
現在のEPSを返します。初期状態では $10^{-14}$ に設定されています。

<br />

**setEps**
```
inline void &setEps(real value = 1e-14)
```
EPSを`value`の値に変更します

<br />

**sgn**
```
inline int sgn(real value)
```
`value`が負なら`-1`を正なら`1`を零なら`0`を返す

<br />

**equals**
```
inline bool equals(const real& a, const real& b)
```

引数に与えた実数`a, b`が等しいか判定する

<br />

**toRadian**
```
real toRadian(const real& value)
```
引数`value`を弧度法にしたものを返す。

<br />

#### ユーザー定義リテラル

`namespace literal`上で定義されている。include時点で`using namespace literal`が適用される

**_rad**
```
geoR2::real operator"" _rad(unsigned long long value)
```

`value`を弧度法にしたものを返す。
