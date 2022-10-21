---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/LCS.test.cpp
    title: test/LCS.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/LCS.hpp\"\n#include <string>\n#include <vector>\n\
    #include <algorithm>\n\nnamespace zawa::impl {\n\ntemplate <class T>\nstd::vector<T>\
    \ lcs(const std::vector<T>& a, const std::vector<T>& b) {\n    std::vector dp(a.size()\
    \ + 1, std::vector(b.size() + 1, 0));\n    for (std::size_t i = 0 ; i < a.size()\
    \ ; i++) {\n        for (std::size_t j = 0 ; j < b.size() ; j++) {\n         \
    \   if (a[i] == b[j]) {\n                dp[i + 1][j + 1] = dp[i][j] + 1;\n  \
    \          }\n            else {\n                dp[i + 1][j + 1] = std::max(dp[i\
    \ + 1][j], dp[i][j + 1]);\n            }\n        }\n    }\n    std::vector<T>\
    \ res;\n    std::size_t i = a.size(), j = b.size();\n    while (dp[i][j] > 0)\
    \ {\n        if (dp[i - 1][j] == dp[i][j]) {\n            i--;\n        }\n  \
    \      else if (dp[i][j - 1] == dp[i][j]) {\n            j--;\n        }\n   \
    \     else {\n            i--;\n            j--;\n            res.emplace_back(a[i]);\n\
    \        }\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n\n}\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<T> lcs(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    return impl::lcs(a, b);\n}\n\nstd::string\
    \ lcs(const std::string& a, const std::string& b) {\n    std::vector<char> newa(a.begin(),\
    \ a.end()), newb(b.begin(), b.end());\n    std::vector<char> reschar = impl::lcs(newa,\
    \ newb);\n    return std::string(reschar.begin(), reschar.end());\n}\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa::impl {\n\ntemplate <class T>\nstd::vector<T> lcs(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    std::vector dp(a.size() + 1, std::vector(b.size()\
    \ + 1, 0));\n    for (std::size_t i = 0 ; i < a.size() ; i++) {\n        for (std::size_t\
    \ j = 0 ; j < b.size() ; j++) {\n            if (a[i] == b[j]) {\n           \
    \     dp[i + 1][j + 1] = dp[i][j] + 1;\n            }\n            else {\n  \
    \              dp[i + 1][j + 1] = std::max(dp[i + 1][j], dp[i][j + 1]);\n    \
    \        }\n        }\n    }\n    std::vector<T> res;\n    std::size_t i = a.size(),\
    \ j = b.size();\n    while (dp[i][j] > 0) {\n        if (dp[i - 1][j] == dp[i][j])\
    \ {\n            i--;\n        }\n        else if (dp[i][j - 1] == dp[i][j]) {\n\
    \            j--;\n        }\n        else {\n            i--;\n            j--;\n\
    \            res.emplace_back(a[i]);\n        }\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\n}\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstd::vector<T> lcs(const std::vector<T>& a, const std::vector<T>& b) {\n\
    \    return impl::lcs(a, b);\n}\n\nstd::string lcs(const std::string& a, const\
    \ std::string& b) {\n    std::vector<char> newa(a.begin(), a.end()), newb(b.begin(),\
    \ b.end());\n    std::vector<char> reschar = impl::lcs(newa, newb);\n    return\
    \ std::string(reschar.begin(), reschar.end());\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/LCS.hpp
  requiredBy: []
  timestamp: '2022-10-21 15:10:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/LCS.test.cpp
documentation_of: src/algorithm/LCS.hpp
layout: document
title: "LCS(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
---

## 概要
```
LCS(std::vector<T>& a, std::vector<T>& b)
```

二つの列に対して最大共通部分列を求めます。

列$A$、$B$の共通部分列とは$A$、$B$両方の部分列である列を指します。部分列は元の列から0個以上の要素を省き残ったものを元の順序を保って並べたものです。

最大共通部分列は共通部分列の中で長さが最大のものです。


### 機能

* 関数に二つぶちこみましょう。`std::string`にも対応しています。
* 共通部分列の中で長さが最大のものを一つ返します
    * 一般に最大共通部分列は一つに定まらないことに注意してください

  
### 計算量
* $O(NM)$ ( $N,\  M$ はそれぞれの列の長さ)
