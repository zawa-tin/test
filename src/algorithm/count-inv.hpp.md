---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/count-inv.test.cpp
    title: test/count-inv.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/count-inv.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa::impl {\n\ntemplate <class T>\nlong long sort(std::vector<T>& arr, int\
    \ left, int right) {\n\tif (right - left == 1) {\n\t\treturn 0LL;\n\t}\n\tlong\
    \ long res = 0LL;\n\tint mid = left + ((right - left) >> 1);\n\tres += sort(arr,\
    \ left, mid);\n\tres += sort(arr, mid, right);\n\tstd::vector<T> fronts(arr.begin()\
    \ + left, arr.begin() + mid);\n\tstd::vector<T> backs(arr.begin() + mid, arr.begin()\
    \ + right);\n\tint front_idx = 0, back_idx = 0;\n\tfor (int i = left ; i < right\
    \ ; i++) {\n\t\tif (front_idx < (int)fronts.size() and \n\t\t\t\t(back_idx ==\
    \ (int)backs.size() or fronts[front_idx] <= backs[back_idx])) {\n\t\t\tarr[i]\
    \ = fronts[front_idx++];\n\t\t}\n\t\telse {\n\t\t\tarr[i] = backs[back_idx++];\n\
    \t\t\tres += mid - left - front_idx;\n\t\t}\n\t}\n\treturn res;\n}\n\n} // namespace\
    \ zawa\n\nnamespace zawa {\n\ntemplate <class T>\nlong long count_inv(const std::vector<T>&\
    \ in) {\n\tstd::vector arr = in;\n\treturn impl::sort(arr, 0, (int)arr.size());\n\
    }\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa::impl {\n\ntemplate <class\
    \ T>\nlong long sort(std::vector<T>& arr, int left, int right) {\n\tif (right\
    \ - left == 1) {\n\t\treturn 0LL;\n\t}\n\tlong long res = 0LL;\n\tint mid = left\
    \ + ((right - left) >> 1);\n\tres += sort(arr, left, mid);\n\tres += sort(arr,\
    \ mid, right);\n\tstd::vector<T> fronts(arr.begin() + left, arr.begin() + mid);\n\
    \tstd::vector<T> backs(arr.begin() + mid, arr.begin() + right);\n\tint front_idx\
    \ = 0, back_idx = 0;\n\tfor (int i = left ; i < right ; i++) {\n\t\tif (front_idx\
    \ < (int)fronts.size() and \n\t\t\t\t(back_idx == (int)backs.size() or fronts[front_idx]\
    \ <= backs[back_idx])) {\n\t\t\tarr[i] = fronts[front_idx++];\n\t\t}\n\t\telse\
    \ {\n\t\t\tarr[i] = backs[back_idx++];\n\t\t\tres += mid - left - front_idx;\n\
    \t\t}\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nlong long count_inv(const std::vector<T>& in) {\n\tstd::vector arr\
    \ = in;\n\treturn impl::sort(arr, 0, (int)arr.size());\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/count-inv.hpp
  requiredBy: []
  timestamp: '2023-01-09 21:32:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/count-inv.test.cpp
documentation_of: src/algorithm/count-inv.hpp
layout: document
title: "count-inv (\u8EE2\u5012\u6570)"
---

## 概要

列に対して転倒数を求めます。配列$A$の転倒数とは$i < j$かつ$A_i > A_j$を満たす順序対$(i, j)$の総数を指します。

内部実装にマージソートを用いています。


### 機能
`long long count_inv<T>(const std::vector<T>& ins)`
- `ins`の転倒数を求めます。
- **計算量** : $O(N\log N)$
	- (`ins`の長さを $N$ とする)
