---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/semiring/max-plus-semiring.hpp\"\n\n#include\
    \ <algorithm>\n#include <climits>\n\nnamespace zawa {\n\ntemplate <class dat_type>\n\
    struct maxplus_semiring {\n\tusing T = dat_type;\n\tstatic constexpr T id_add\
    \ = -std::numeric_limits<T>::max();\n\tstatic constexpr T id_mul = 0;\n\tstatic\
    \ T add(const T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n\tstatic T\
    \ mul(const T& a, const T& b) {\n\t\tif (b > 0 or a > id_add - b) {\n\t\t\treturn\
    \ a + b;\n\t\t}\n\t\telse {\n\t\t\treturn id_add;\n\t\t}\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <climits>\n\nnamespace zawa\
    \ {\n\ntemplate <class dat_type>\nstruct maxplus_semiring {\n\tusing T = dat_type;\n\
    \tstatic constexpr T id_add = -std::numeric_limits<T>::max();\n\tstatic constexpr\
    \ T id_mul = 0;\n\tstatic T add(const T& a, const T& b) {\n\t\treturn std::max(a,\
    \ b);\n\t}\n\tstatic T mul(const T& a, const T& b) {\n\t\tif (b > 0 or a > id_add\
    \ - b) {\n\t\t\treturn a + b;\n\t\t}\n\t\telse {\n\t\t\treturn id_add;\n\t\t}\n\
    \t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/semiring/max-plus-semiring.hpp
  requiredBy: []
  timestamp: '2023-01-15 13:12:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/utility/semiring/max-plus-semiring.hpp
layout: document
title: max-plus-semiring (max+)
---

## 概要

$\R\ \cup\ \{-\infin \}$ 上での $\max$ と $+$ についての[半環](https://ja.wikipedia.org/wiki/%E5%8D%8A%E7%92%B0) を扱う構造体。[トロピカル半環](https://en.wikipedia.org/wiki/Tropical_semiring) とも呼ばれる。

## 機能

`zawa::normal_semiring<T>`
- `T` 扱いたい集合

`T id_add`
- `-std::numeric_limits<T>::max`

`T id_mul`
- 0

`T add(const T& a, const T& b)`
- $\max (a, b)$

`T mul(const T& a, const T& b)`
- $a\ +\ b$
- $\infin$ を`id_add`としているため、丸めこみが発生します。
