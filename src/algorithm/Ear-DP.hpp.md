---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Ear-DP.test.cpp
    title: test/Ear-DP.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Ear-DP.hpp\"\n\n#include <vector>\n#include\
    \ <string>\n\nnamespace zawa::impl {\n\ntemplate<typename T, typename RES>\nRES\
    \ ear_dp(const std::vector<T>& a, const std::vector<T>& b) {\n    std::vector<std::vector<RES>>\
    \ dp(a.size() + 1, std::vector<RES>(b.size() + 1));\n    for (std::size_t i =\
    \ 0 ; i < a.size() + 1 ; i++) {\n        dp[i][0] = 1;\n    }\n\n    for (size_t\
    \ i = 1 ; i < a.size() + 1 ; i++) {\n        for (size_t j = 1 ; j < b.size()\
    \ + 1 ; j++) {\n            dp[i][j] += dp[i - 1][j];\n            if (a[i - 1]\
    \ == b[j - 1]) {\n                dp[i][j] += dp[i][j - 1];\n            }\n \
    \       }\n    }\n\n    return dp.back().back();\n}\n\n} // namespace zawa::impl\n\
    \nnamespace zawa {\n\ntemplate<typename T, typename RES>\nRES ear_dp(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    return impl::ear_dp<T, RES>(a, b);\n}\n\n\
    template<typename RES>\nRES ear_dp(const std::string& a, const std::string& b)\
    \ {\n    std::vector<char> newa(a.begin(), a.end()), newb(b.begin(), b.end());\n\
    \    return impl::ear_dp<char, RES>(newa, newb);\n}\n\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\nnamespace zawa::impl\
    \ {\n\ntemplate<typename T, typename RES>\nRES ear_dp(const std::vector<T>& a,\
    \ const std::vector<T>& b) {\n    std::vector<std::vector<RES>> dp(a.size() +\
    \ 1, std::vector<RES>(b.size() + 1));\n    for (std::size_t i = 0 ; i < a.size()\
    \ + 1 ; i++) {\n        dp[i][0] = 1;\n    }\n\n    for (size_t i = 1 ; i < a.size()\
    \ + 1 ; i++) {\n        for (size_t j = 1 ; j < b.size() + 1 ; j++) {\n      \
    \      dp[i][j] += dp[i - 1][j];\n            if (a[i - 1] == b[j - 1]) {\n  \
    \              dp[i][j] += dp[i][j - 1];\n            }\n        }\n    }\n\n\
    \    return dp.back().back();\n}\n\n} // namespace zawa::impl\n\nnamespace zawa\
    \ {\n\ntemplate<typename T, typename RES>\nRES ear_dp(const std::vector<T>& a,\
    \ const std::vector<T>& b) {\n    return impl::ear_dp<T, RES>(a, b);\n}\n\ntemplate<typename\
    \ RES>\nRES ear_dp(const std::string& a, const std::string& b) {\n    std::vector<char>\
    \ newa(a.begin(), a.end()), newb(b.begin(), b.end());\n    return impl::ear_dp<char,\
    \ RES>(newa, newb);\n}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Ear-DP.hpp
  requiredBy: []
  timestamp: '2022-10-21 15:36:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Ear-DP.test.cpp
documentation_of: src/algorithm/Ear-DP.hpp
layout: document
title: "Ear-DP (\u8033DP)"
---

## 概要
```
RES ear_dp<T, RES>(std::vector<T> as, std::vector<T> bs)
```


列asに対して、列bsと一致する部分列の取り出し方の数mod 1e9 + 7を求めます。


### 機能
- テンプレート引数は、引数の型、返り値の型の順番です
    - `std::string`の時は一つ目はいらないです

### 計算量
asの長さを $N$ 、bsの長さを $M$ として $O(NM)$
