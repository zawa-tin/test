---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC236-E.test.cpp
    title: test/ABC236-E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/binary-search-ld.hpp\"\n\n#include <cstddef>\n\
    \nnamespace zawa {\n\ntemplate <class T, class F, std::size_t up = 80>\nT binary_search_ld(T\
    \ ok, T ng, const F& f) {\n\tfor (std::size_t _ = 0 ; _ < up ; _++) {\n\t\tT mid\
    \ = (ok + ng) / 2;\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\
    \tng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n"
  code: "#pragma once\n\n#include <cstddef>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, class F, std::size_t up = 80>\nT binary_search_ld(T ok, T ng, const F& f)\
    \ {\n\tfor (std::size_t _ = 0 ; _ < up ; _++) {\n\t\tT mid = (ok + ng) / 2;\n\t\
    \tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t\
    }\n\treturn ok;\n}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/binary-search-ld.hpp
  requiredBy: []
  timestamp: '2023-01-21 19:38:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC236-E.test.cpp
documentation_of: src/template/binary-search-ld.hpp
layout: document
title: "binary-seach-ld (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u4E8C\u5206\u63A2\u7D22\
  )"
---

## 概要

与えられた範囲 $l, r$ と単調性関数 $f\ :\ \{\ p\ \mid\ p\ \in\ \mathbb{R},\ l\ \le\ p\ \le\ r\ \} \rightarrow\ \{\ \text{false},\ \text{true}\ \}$ について $f(p)$ の値が変化する境界値を発見します。


## 機能

**関数**

`T zawa::binary_search<T, F, up = 80>(T ok, T ng, const F& f)`
- `T`: $l, r$ の型、`double`、`long double` などの整数型以外での使用を想定していない
- `F`: `std::function<bool(T)>` が入ることになる。 $p$ を引数にとり、`false`か`true`を返す関数。以下の条件を満たす必要がある。
	- $\text{ok}\ <\ \text{ng}$ の場合、 $\text{ok}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{true}$ が成り立つかつ $x\ <\ p\ \le\ \text{ng}$ なる $p$ について $f(p)\ =\ \text{false}$ となる $x$ が存在する
	- $\text{ok}\ >\ \text{ng}$ の場合、 $\text{ng}\ \le\ p\ \le\ x$ なる $p$ について $f(p)\ =\ \text{false}$ となりかつ、 $x\ <\ p\ \le\ \text{ok}$ となる $p$ について $f(p)\ =\ \text{true}$ となる $x$ が存在する
- `up`: $f$ を呼び出す回数。デフォルトで80回となっている。呼び出すほど精度が上がるが、必要以上に呼び出しても無駄なだけなので注意
- `ok`: $f(p)\ =\ \text{true}$ となる値なら良い
- `ng`: $f(p)\ =\ \text{false}$ となる値なら良い
- `f` : $f$
- 上の条件式にでてくる $x$ の値を返します。
- **計算量** : $f(p)$ を`up`回呼び出す。

## 参考

[tweet by @meguru_comp](https://twitter.com/meguru_comp/status/697008509376835584)
