---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/kadane.test.cpp
    title: test/kadane.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Kadane.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\n    template <typename T>\n    class Kadane {\n\n    private:\n  \
    \      std::vector<T> arr;\n        std::pair<int, int> segment;\n        T res;\n\
    \n    public:\n        Kadane(std::vector<T>& arr, T init) \n            : arr(arr.begin(),\
    \ arr.end()), \n              res(init) {}\n\n        void build() {\n       \
    \     T dp = res;\n            int left = 0;\n            for (int right = 0 ;\
    \ right < (int)arr.size() ; right++) {\n                if (dp + arr[right] <\
    \ arr[right]) {\n                    left = right;\n                }\n      \
    \          dp = std::max(dp + arr[right], arr[right]);\n\n                if (res\
    \ < dp) {\n                    segment = {left, right};\n                }\n \
    \               res = std::max(res, dp);\n            }\n            segment.second++;\n\
    \        }\n\n        T get() {\n            return res;\n        }\n\n      \
    \  std::pair<int, int> get_seg() {\n            return segment;\n        }\n \
    \   };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    template <typename\
    \ T>\n    class Kadane {\n\n    private:\n        std::vector<T> arr;\n      \
    \  std::pair<int, int> segment;\n        T res;\n\n    public:\n        Kadane(std::vector<T>&\
    \ arr, T init) \n            : arr(arr.begin(), arr.end()), \n              res(init)\
    \ {}\n\n        void build() {\n            T dp = res;\n            int left\
    \ = 0;\n            for (int right = 0 ; right < (int)arr.size() ; right++) {\n\
    \                if (dp + arr[right] < arr[right]) {\n                    left\
    \ = right;\n                }\n                dp = std::max(dp + arr[right],\
    \ arr[right]);\n\n                if (res < dp) {\n                    segment\
    \ = {left, right};\n                }\n                res = std::max(res, dp);\n\
    \            }\n            segment.second++;\n        }\n\n        T get() {\n\
    \            return res;\n        }\n\n        std::pair<int, int> get_seg() {\n\
    \            return segment;\n        }\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Kadane.hpp
  requiredBy: []
  timestamp: '2022-07-28 02:52:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/kadane.test.cpp
documentation_of: src/algorithm/Kadane.hpp
layout: document
title: "Kadane's Algorithm (\u6700\u5927\u9023\u7D9A\u90E8\u5206\u548C)"
---

## 概要
```
Kadane(std::vector<T>& arr, T init)
```

一次元配列に対して最大連続部分和を求めます。

サイズ$N$の数列$A$の最大連続部分和とは$1 \le l \le N$と$i \le r \le N$を満たす$(l, r)$の組の中で$\displaystyle \sum_{i=l}^{r} A_i$の最大値を指します。

トロピカル半環に対して正常に動作する <- (夏なのか代数なのか)


### 機能
* `コンストラクタ`: 最大連続部分和を求めたい配列の参照と下限値を引数にとります。下限値は配列の最小値より小さい数をとるようにしてください

* `build()`: 最大連続部分和を計算し、 `res`に和を、`segment`に最大連続部分和をとる区間（半開区間）を代入します。

* `get()`: `res`を得ます

* `get_seg()`: `segment`を得ます


### 計算量
* `build()`・・・$O(N)$
