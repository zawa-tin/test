---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_alds_6_D.test.cpp
    title: test/aoj_alds_6_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Cyclic-Permutation.hpp\"\n\n#include <vector>\n\
    #include <algorithm>\n\nnamespace zawa {\n\n    template <typename T>\n    std::vector<std::vector<int>>\
    \ decomp_cyclic_permutation(std::vector<T>& arr) {\n        std::vector<std::pair<T,\
    \ int>> cp(arr.size());\n        for (int i = 0 ; i < (int)arr.size() ; i++) {\n\
    \            cp[i] = {arr[i], i};\n        }\n        sort(cp.begin(), cp.end());\n\
    \n        std::vector<std::vector<int>> res;\n        std::vector<int> used(arr.size());\n\
    \        for (int i = 0 ; i < (int)arr.size() ; i++) {\n            if (used[i])\
    \ continue;\n            std::vector<int> cycle;\n            int now = i;\n \
    \           while(!used[now]) {\n                cycle.emplace_back(now);\n  \
    \              used[now] = 1;\n                now = cp[now].second;\n       \
    \     }\n            res.emplace_back(cycle);\n        }\n\n        return res;\n\
    \    }\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n\nnamespace zawa\
    \ {\n\n    template <typename T>\n    std::vector<std::vector<int>> decomp_cyclic_permutation(std::vector<T>&\
    \ arr) {\n        std::vector<std::pair<T, int>> cp(arr.size());\n        for\
    \ (int i = 0 ; i < (int)arr.size() ; i++) {\n            cp[i] = {arr[i], i};\n\
    \        }\n        sort(cp.begin(), cp.end());\n\n        std::vector<std::vector<int>>\
    \ res;\n        std::vector<int> used(arr.size());\n        for (int i = 0 ; i\
    \ < (int)arr.size() ; i++) {\n            if (used[i]) continue;\n           \
    \ std::vector<int> cycle;\n            int now = i;\n            while(!used[now])\
    \ {\n                cycle.emplace_back(now);\n                used[now] = 1;\n\
    \                now = cp[now].second;\n            }\n            res.emplace_back(cycle);\n\
    \        }\n\n        return res;\n    }\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Cyclic-Permutation.hpp
  requiredBy: []
  timestamp: '2022-07-30 20:12:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_alds_6_D.test.cpp
documentation_of: src/algorithm/Cyclic-Permutation.hpp
layout: document
title: "Cyclic Permutation(\u5DE1\u56DE\u7F6E\u63DB\u5206\u89E3)"
---

## 概要
```
std::vector<std::vector<int>> decomp_cyclic_permutation(std::vector<T>& arr)
```

引数の配列からソート済の列への置換を巡回置換の積で表現します。

### 機能
* `decomp_cyclic_permutation(std::vector<T>& arr)`: 巡回置換に分解し、`std::vector<std::vector<int>>`の形で返します。0-indexedです。

###  使いどころ
* 列をソートするために必要な二項間swapの最小回数は`N - 連結成分の数`です。

* 他にも[このメモ](https://scrapbox.io/zawakasupublic/%E8%AA%AD%E3%81%BF%E3%83%A1%E3%83%A2_%E7%AB%B6%E3%83%97%E3%83%ADer%E3%81%AE%E3%81%9F%E3%82%81%E3%81%AE%E7%BE%A4%E8%AB%96(swap%E3%81%A8%E9%A0%86%E5%88%97%E3%81%A8%E5%AF%BE%E7%A7%B0%E7%BE%A4))のようなな使いみちがあります

* [元記事](https://koboshi-kyopro.hatenablog.com/entry/2020/08/21/211615)

### 計算量
配列の長さを$N$として$O(N)$
