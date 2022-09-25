---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/RLE.test.cpp
    title: test/RLE.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/RLE.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <string>\n\nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::pair<T,\
    \ int>> rle(const std::vector<T>& ins) {\n    std::vector<std::pair<T, int>> res;\n\
    \    for (size_t i = 0 ; i < ins.size() ; i++) {\n        if (res.empty() or res.back().first\
    \ != ins[i]) {\n            res.emplace_back(ins[i], 1);\n        }\n        else\
    \ {\n            res.back().second++;\n        }\n    }\n    return res;\n}\n\n\
    std::vector<std::pair<char, int>> rle(const std::string& s) {\n    std::vector<char>\
    \ in(s.begin(), s.end());\n    return rle(in);\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <utility>\n#include <string>\n\
    \nnamespace zawa {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> rle(const\
    \ std::vector<T>& ins) {\n    std::vector<std::pair<T, int>> res;\n    for (size_t\
    \ i = 0 ; i < ins.size() ; i++) {\n        if (res.empty() or res.back().first\
    \ != ins[i]) {\n            res.emplace_back(ins[i], 1);\n        }\n        else\
    \ {\n            res.back().second++;\n        }\n    }\n    return res;\n}\n\n\
    std::vector<std::pair<char, int>> rle(const std::string& s) {\n    std::vector<char>\
    \ in(s.begin(), s.end());\n    return rle(in);\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/RLE.hpp
  requiredBy: []
  timestamp: '2022-09-26 05:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/RLE.test.cpp
documentation_of: src/algorithm/RLE.hpp
layout: document
title: "RLE (\u9023\u9577\u5727\u7E2E)"
---


## 概要
```
std::vector<std::pair<T, int>> rle(const std::vector<T>& ins)
```

引数に入れた`vector`を連長圧縮します。

例えば、`aaabbcdaddd`は`(a, 3)(b, 2)(c, 1)(d, 1)(a, 1)(d, 3)`になります。


## 機能

`std::vector<T>`か`std::string`を引数にとることができます。

`std::string`を引数に入れた場合、`std::vector<std::pair<char, int>>`が返ります。


## 計算量

配列の長さを $N$ として $O(N)$
