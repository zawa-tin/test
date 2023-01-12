---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    private:\n\tstd::vector<T> arr;\n\tstd::vector<int> dat;\n\tstd::vector<T> invs;\n\
    \npublic:\n\tcompression(const std::vector<T>& arr) : arr(arr), dat(arr.size()),\
    \ invs(arr.size()) {\n\t\tstd::vector cp = arr;\n\t\tstd::sort(cp.begin(), cp.end());\t\
    \n\t\tcp.erase(std::unique(cp.begin(), cp.end()), cp.end());\n\t\tfor (std::size_t\
    \ i = 0 ; i < arr.size() ; i++) {\n\t\t\tdat[i] = std::lower_bound(cp.begin(),\
    \ cp.end(), arr[i]) - cp.begin();\n\t\t}\n\t\tfor (std::size_t i = 0 ; i < arr.size()\
    \ ; i++) {\n\t\t\tinvs[dat[i]] = arr[i];\n\t\t}\n\t}\n\n\tint operator [](int\
    \ i) {\n\t\treturn dat[i];\n\t}\n\n\tT inv(int i) {\n\t\treturn invs[i];\n\t}\n\
    \n\tstd::vector<int> get() {\n\t\treturn dat;\n\t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\ntemplate <class T>\nclass compression {\nprivate:\n\tstd::vector<T> arr;\n\
    \tstd::vector<int> dat;\n\tstd::vector<T> invs;\n\npublic:\n\tcompression(const\
    \ std::vector<T>& arr) : arr(arr), dat(arr.size()), invs(arr.size()) {\n\t\tstd::vector\
    \ cp = arr;\n\t\tstd::sort(cp.begin(), cp.end());\t\n\t\tcp.erase(std::unique(cp.begin(),\
    \ cp.end()), cp.end());\n\t\tfor (std::size_t i = 0 ; i < arr.size() ; i++) {\n\
    \t\t\tdat[i] = std::lower_bound(cp.begin(), cp.end(), arr[i]) - cp.begin();\n\t\
    \t}\n\t\tfor (std::size_t i = 0 ; i < arr.size() ; i++) {\n\t\t\tinvs[dat[i]]\
    \ = arr[i];\n\t\t}\n\t}\n\n\tint operator [](int i) {\n\t\treturn dat[i];\n\t\
    }\n\n\tT inv(int i) {\n\t\treturn invs[i];\n\t}\n\n\tstd::vector<int> get() {\n\
    \t\treturn dat;\n\t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/compression.hpp
  requiredBy: []
  timestamp: '2023-01-12 15:11:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/compression.test.cpp
documentation_of: src/algorithm/compression.hpp
layout: document
title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
---

## 概要
長さ $N$ の数列 $A$ について以下の条件を満たす長さ $N$ の数列 $B$ を生成します。
- $A_i$ が $A$ の中で $p$ 番目に小さいなら $B_i\ =\ p - 1$

## 機能

`zawa::compression<T> (const std::vector<T>& arr)`
- `arr`を $A$ として $B$ を生成します（コンストラクタ）。
	- `T` は`std::sort`や`std::lower_bound`などが使える型である必要があります。
- **計算量** : $O(N\log N)$

`compression operator[]`
- $B_i$ を返します
- 書き換え不可です

`T compression::inv(int i)`
- $A_{B_i}$ を返します
- **単体テストをまだしていません**

`std::vector<int> compression::get()`
- $B$ を返します
- **単体テストをまだしていません**
