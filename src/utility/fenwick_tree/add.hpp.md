---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_multiset.hpp
    title: "fenwick_multiset (\u52D5\u7684\u591A\u91CD\u96C6\u5408)"
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_set.hpp
    title: "fenwick_set (\u52D5\u7684\u96C6\u5408)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC186-F.test.cpp
    title: test/ABC186-F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ARC033-C.test.cpp
    title: test/ARC033-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ARC075-E.test.cpp
    title: test/ARC075-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fenwick_tree.test.cpp
    title: test/fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/utility/fenwick_tree/add.hpp\"\n\nnamespace zawa {\n\
    \ntemplate <class dat_type>\nstruct add_structure {\n\tusing T = dat_type;\n\t\
    static constexpr T id = T{};\n\tstatic T add(const T& a, const T& b) {\n\t\treturn\
    \ a + b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\treturn -a;\n\t}\n};\n\n}\
    \ // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct add_structure\
    \ {\n\tusing T = dat_type;\n\tstatic constexpr T id = T{};\n\tstatic T add(const\
    \ T& a, const T& b) {\n\t\treturn a + b;\n\t}\n\tstatic T inverse(const T& a)\
    \ {\n\t\treturn -a;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/fenwick_tree/add.hpp
  requiredBy:
  - src/dataStructure/fenwick_multiset.hpp
  - src/dataStructure/fenwick_set.hpp
  timestamp: '2023-01-29 05:23:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fenwick_tree.test.cpp
  - test/ABC186-F.test.cpp
  - test/ARC075-E.test.cpp
  - test/ARC033-C.test.cpp
documentation_of: src/utility/fenwick_tree/add.hpp
layout: document
title: fenwick tree add structure
---

## 概要

`zawa::fenwick_tree`にのせる構造体です。一般的な加法を提供します。


## 機能

- `dat_type`: 型です。 `T`とエイリアスされます
- `static constexpr T id`: `T{}` です
- `static T add(const T& a, const T& b)`: `a + b`を返します
- `static T inverse(const T& a)` : `-a`を返します
