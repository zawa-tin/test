---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC267-C.test.cpp
    title: test/ABC267-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/accum1d.test.cpp
    title: test/accum1d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/accum1d.hpp\"\n\n#include <vector>\n#include\
    \ <numeric>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct accum1d : std::vector<T>\
    \ {\n\tusing vector = std::vector<T>;\n\taccum1d() {\n\t\t(*this).push_back(T());\n\
    \t}\n\taccum1d(const std::vector<T>& A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(),\
    \ A.end(), std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\
    \taccum1d(InputIterator begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\
    \t\tstd::partial_sum(begin, end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t\
    \ l, std::size_t r) {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <numeric>\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstruct accum1d : std::vector<T> {\n\tusing vector = std::vector<T>;\n\
    \taccum1d() {\n\t\t(*this).push_back(T());\n\t}\n\taccum1d(const std::vector<T>&\
    \ A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(), A.end(),\
    \ std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\taccum1d(InputIterator\
    \ begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(begin,\
    \ end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t l, std::size_t r)\
    \ {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/accum1d.hpp
  requiredBy: []
  timestamp: '2023-01-19 16:06:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/accum1d.test.cpp
  - test/ABC267-C.test.cpp
documentation_of: src/template/accum1d.hpp
layout: document
title: "accum1d (\u7D2F\u7A4D\u548C)"
---

## 概要

1次元列の累積和をとります。

詳しくいうと、与えられた列 $A$ に対して、 $\displaystyle S_0\ =\ 0\land S_i\ =\ \sum_{j = 0}^{i - 1} A_j (i > 0)$ を満たす列 $S$ を構築します。

## 機能

**コンストラクタ**
`zawa::accum1d<T>()`
- `T()`**1要素のみの列を構築します**。
- 累積和そのものを考えると0があったほうがいいかなって。困ったら消す。

`zawa::accum1d<T>(const std::vector<T>& A)`
- `A` から $S$ を構築します。
- `std::partial_sum`を内部で利用しています。

`zawa::accum1d<T>(InputIterator begin, InputIterator end)`
- `begin`から`end`までの要素から`S`を構築します。

それぞれ**計算量は**: $O(\mid A\mid)$

**メンバ関数**

`T sum(std::size_t l, std::size_t r)`
- $\displaystyle \sum_{i = l}^{r - i} A_i$ を返す
- $S_r - S_l$ と同義です
- **計算量** : $O(1)$

`std::vector<T>`を継承しているので、`std::vector`の機能がそのまま使えます。

## メモ
- 区間で考えると頭が壊れるので、「左端」と「要素数」を利用して`sum`を呼び出そう。ex) `sum(l, l + p)`

## TODO

- `int`型の列から`long long`型の`accum1d`を構築できるようにする
