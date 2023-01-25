---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/makebuc.test.cpp
    title: test/makebuc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/makebuc.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<int> makebuc(const\
    \ std::vector<T>& A, const T& sup) {\n\tstd::vector<int> res(sup, 0);\n\tfor (const\
    \ auto& a : A) {\n\t\tres[a]++;\n\t}\n\treturn res;\n}\n\nstd::vector<int> makebuc(const\
    \ std::string& S, bool lower = true) {\n\tstd::vector<int> res(26, 0);\n\tint\
    \ minus = (lower ? (int)'a' : (int)'A');\n\tfor (const auto& c : S) {\n\t\tres[c\
    \ - minus]++;\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace zawa {\n\
    \ntemplate <class T>\nstd::vector<int> makebuc(const std::vector<T>& A, const\
    \ T& sup) {\n\tstd::vector<int> res(sup, 0);\n\tfor (const auto& a : A) {\n\t\t\
    res[a]++;\n\t}\n\treturn res;\n}\n\nstd::vector<int> makebuc(const std::string&\
    \ S, bool lower = true) {\n\tstd::vector<int> res(26, 0);\n\tint minus = (lower\
    \ ? (int)'a' : (int)'A');\n\tfor (const auto& c : S) {\n\t\tres[c - minus]++;\n\
    \t}\n\treturn res;\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/makebuc.hpp
  requiredBy: []
  timestamp: '2023-01-26 05:44:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/makebuc.test.cpp
documentation_of: src/template/makebuc.hpp
layout: document
title: "makebuc (\u30D0\u30B1\u30C3\u30C8)"
---

## 概要

入力で与えた列 $A$ に対して $B_i\ =\ \text{cnt} (i)$ を満たす $B$ を生成して返す。ここで $\text{cnt}(i)$ とは $A_j\ =\ i$ を満たす $j$ の数とする。


## 機能

**関数**

`std::vector<int> zawa::makebuc<T>(const std::vector<T>& A, const T& sup)`
- $A$ のバケットを生成します。
- `T`は`int`以外での使用を想定されていません
- `sup` はバケットのサイズであり、 $\max(A)$ より**真に大きい値**である必要があります。
- **計算量** : $O(\max(\mid A\mid, \text{sup}))$

`std::vector<int> zawa::makebuc(const std::string& S, bool lower = true)`
- 英文字列 $S$ から各文字が出現する回数を保存したバケットを返します。
- $S$ が英小文字の場合引数`lower`に`false`を入れてください
- **計算量** : $O(\mid S\mid)$


## 改修案？

- `std::map<T, int>`でも返せるようにする
- 勝手に座圧してくれるようにする
