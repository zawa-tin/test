---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC285D.test.cpp
    title: test/ABC285D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/compression.test.cpp
    title: test/compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/compression.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass compression {\n\
    private:\n\tstd::vector<T> as;\n\tstd::vector<T> uniqued;\n\npublic:\n\tcompression(const\
    \ std::vector<T>& as) : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(),\
    \ uniqued.end());\n\t\tuniqued.erase(std::unique(uniqued.begin(), uniqued.end()),\
    \ uniqued.end());\n\t}\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass compression {\nprivate:\n\tstd::vector<T> as;\n\
    \tstd::vector<T> uniqued;\n\npublic:\n\tcompression(const std::vector<T>& as)\
    \ : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(), uniqued.end());\n\t\t\
    uniqued.erase(std::unique(uniqued.begin(), uniqued.end()), uniqued.end());\n\t\
    }\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/compression.hpp
  requiredBy: []
  timestamp: '2023-01-16 00:44:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC285D.test.cpp
  - test/compression.test.cpp
documentation_of: src/algorithm/compression.hpp
layout: document
title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
---

## 概要
長さ $N$ の列 $A$ について以下の情報を管理します
- 要素 $v$ が $A$ の中で何番目に小さいか。

## 機能

`zawa::compression<T>(const std::vector<T>& as)`
- コンストラクタ
- `as` 入力
- **計算量** : $O(N\log N)$

`int zawa::compression<T>::operator[](const T& val)`
- `val`が $A$ の要素で何番目に小さいかを返す。0-indexed
- **計算量** : $O(\log N)$

`int zawa::compression<T>::get(std::size_t i)`
- $A_i$ が $A$ の要素で何番目に小さいかを返す。0-indexed
- **計算量** : $O(\log N)$

`std::size_t zawa::compression<T>::size()`
- $A$ に含まれる要素の種類数を返す
- **計算量** : $O(1)$
