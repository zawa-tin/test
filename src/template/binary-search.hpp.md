---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC203-E.test.cpp
    title: test/ABC203-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC236-E.test.cpp
    title: test/ABC236-E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/ABC250.test.cpp
    title: test/ABC250.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/binary-search.test.cpp
    title: test/binary-search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/binary-search.hpp\"\n\n#include <cmath>\n\n\
    namespace zawa {\n\ntemplate <class T, class F>\nT binary_search(T ok, T ng, const\
    \ F& f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\
    \tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t\
    }\n\treturn ok;\n}\n\n}\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace zawa {\n\ntemplate <class T,\
    \ class F>\nT binary_search(T ok, T ng, const F& f) {\n\twhile (std::abs(ok -\
    \ ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\
    \t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/binary-search.hpp
  requiredBy: []
  timestamp: '2023-01-21 14:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search.test.cpp
  - test/ABC236-E.test.cpp
  - test/ABC203-E.test.cpp
  - test/ABC250.test.cpp
documentation_of: src/template/binary-search.hpp
layout: document
title: "binary-seach (\u6574\u6570\u4E8C\u5206\u63A2\u7D22)"
---

## 概要

与えられた範囲 $l, r$ と単調性関数 $f\ :\ \{\ p\ \mid\ p\ \in\ \mathbb{Z},\ l\ \le\ p\ \le\ r\ \} \rightarrow\ \{\ \text{false},\ \text{true}\ \}$ について $f(p)$ の値が変化する境界値を発見します。


## 機能

**関数**

`T zawa::binary_search<T, F>(T ok, T ng, const F& f)`
- `T`: $l, r$ の型、`int` `long` `long long` などの整数型以外での使用を想定していない
- `F`: `std::function<bool(T)>` が入ることになる。 $p$ を引数にとり、`false`か`true`を返す関数。以下の条件を満たす必要がある。
	- $\text{ok}\ <\ \text{ng}$ の場合、 $\text{ok}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{true}$ が成り立つかつ $x\ <\ p\ \le\ \text{ng}$ なる $p$ について $f(p)\ =\ \text{false}$ となる $x$ が存在する
	- $\text{ok}\ >\ \text{ng}$ の場合、 $\text{ng}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{false}$ となりかつ、 $x\ <\ p\ \le\ \text{ok}$ となる $p$ について $f(p)\ =\ \text{true}$ となる $x$ が存在する
- `ok`: $f(p)\ =\ \text{true}$ となる値なら良い
- `ng`: $f(p)\ =\ \text{false}$ となる値なら良い
- `f` : $f$
- 上の条件式にでてくる $x$ の値を返します。
- **計算量** : $f(p)$ をおおよそ $\log_2 \mid \text{ok}\ -\ \text{ng}\ \mid$ 回呼び出す。

## 参考

[tweet by @meguru_comp](https://twitter.com/meguru_comp/status/697008509376835584)
