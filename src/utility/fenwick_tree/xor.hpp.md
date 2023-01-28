---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC185-E.test.cpp
    title: test/ABC185-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/fenwick_tree/xor.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class dat_type>\nstruct xor_structure {\n\tusing T = dat_type;\n\t\
    static constexpr T id{};\n\tstatic T add(const T& a, const T& b) {\n\t\treturn\
    \ a ^ b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\treturn a;\n\t}\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct xor_structure\
    \ {\n\tusing T = dat_type;\n\tstatic constexpr T id{};\n\tstatic T add(const T&\
    \ a, const T& b) {\n\t\treturn a ^ b;\n\t}\n\tstatic T inverse(const T& a) {\n\
    \t\treturn a;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/fenwick_tree/xor.hpp
  requiredBy: []
  timestamp: '2023-01-29 05:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC185-E.test.cpp
documentation_of: src/utility/fenwick_tree/xor.hpp
layout: document
title: fenwick tree xor structure
---

## 概要

`zawa::fenwick_tree`にのせる構造体です。bitwise xorを提供します。


## 機能

- `dat_type`: 型です。 `T`とエイリアスされます
- `static constexpr T id`: `T{}` です
- `static T add(const T& a, const T& b)`: `a xor b`を返します
- `static T inverse(const T& a)` : `a`を返します
