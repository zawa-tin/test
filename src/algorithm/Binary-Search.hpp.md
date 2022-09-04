---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Binary-Search.test.cpp
    title: test/Binary-Search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Binary-Search.hpp\"\n\n#include <cmath>\n\n\
    namespace zawa {\n    \n    template <class T, class F>\n    T binary_search(T\
    \ ac, T wa, const F& judge) {\n        while (abs(ac - wa) > 1) {\n          \
    \  T mid = (ac + wa) >> 1;\n            if (judge(mid)) {\n                ac\
    \ = mid; \n            }\n            else {\n                wa = mid;\n    \
    \        }\n        }\n\n        return ac;\n    }\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace zawa {\n    \n    template\
    \ <class T, class F>\n    T binary_search(T ac, T wa, const F& judge) {\n    \
    \    while (abs(ac - wa) > 1) {\n            T mid = (ac + wa) >> 1;\n       \
    \     if (judge(mid)) {\n                ac = mid; \n            }\n         \
    \   else {\n                wa = mid;\n            }\n        }\n\n        return\
    \ ac;\n    }\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Binary-Search.hpp
  requiredBy: []
  timestamp: '2022-09-04 21:33:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Binary-Search.test.cpp
documentation_of: src/algorithm/Binary-Search.hpp
layout: document
title: "Binary Search (\u4E8C\u5206\u63A2\u7D22)"
---

## 概要
```
T binary_search(T ac, T wa, const F& judge)
```
第三引数`judge`が`true`を返す範囲と`false`を返す値の範囲の境界値を返します。

実装はめぐる式二分探索を参考にしています。

## 制約
- 第一引数`ac`は`judge(ac)`が`true`を返す値である必要があります。
- 第二引数`wa`は`judge(wa)`が`false`を返す値で有る必要があります。
- 第三引数`judge`は`T`を引数に一つ持ち、`bool`値を返す関数である必要があります。
	- 二分探索なので、単調性が無いと正常に動作しません

## 計算量
`judge`関数をおおよそ $log_2 (\mid ac - wa \mid )$ 回呼び出す。
