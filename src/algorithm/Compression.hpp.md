---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Compression.test.cpp
    title: test/Compression.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Compression.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nclass Compression {\n\
    private:\n    std::vector<T> arr;\n\npublic:\n    Compression(const std::vector<T>&\
    \ in)\n        : arr(in.begin(), in.end()) {\n            std::sort(arr.begin(),\
    \ arr.end());\n            arr.erase(std::unique(arr.begin(), arr.end()), arr.end());\n\
    \    }\n\n    int get(T x) {\n        return std::lower_bound(arr.begin(), arr.end(),\
    \ x) - arr.begin();\n    }\n};\n    \n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass Compression {\nprivate:\n    std::vector<T> arr;\n\
    \npublic:\n    Compression(const std::vector<T>& in)\n        : arr(in.begin(),\
    \ in.end()) {\n            std::sort(arr.begin(), arr.end());\n            arr.erase(std::unique(arr.begin(),\
    \ arr.end()), arr.end());\n    }\n\n    int get(T x) {\n        return std::lower_bound(arr.begin(),\
    \ arr.end(), x) - arr.begin();\n    }\n};\n    \n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Compression.hpp
  requiredBy: []
  timestamp: '2022-09-06 15:47:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Compression.test.cpp
documentation_of: src/algorithm/Compression.hpp
layout: document
title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
---

## 概要
```
Compression<T>(const std::vector<T>& in)
```
座標圧縮します。

配列`A`からなる集合から集合 $\{\ 0,\ 1,\ 2,\ \cdots,\ K - 1\}$ ( $K$ は`A`に出現する要素の種類数) への全射 $F$ を構築します。
-	`A_i`が`A`の中で $p$ 番目に小さいなら $F(A_i)\ =\ p - 1$ 

## 機能

- `コンストラクタ`: 座標圧縮します。

- `get(T val)`: $F(val)$ を取得します。
	- `val` は`A`に出現する値である必要があります。そうじゃない値を入れる使い方があるかもしれない？

## 計算量
- `コンストラクタ`: 配列の要素数を $N$ として $O(N log N)$
- `get`: $O(logK)$
