---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_dsl_5_a.test.cpp
    title: test/aoj_dsl_5_a.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Accum-1D.hpp\"\n\n#include <vector>\n\n\
    namespace zawa {\n\n    template <class T>\n    class Accum_1D {\n    private:\n\
    \        std::vector<T> container;\n        std::vector<T> accum;\n\n    public:\n\
    \        Accum_1D(const std::vector<T>& arr) \n            : container(arr.begin(),\
    \ arr.end())\n            , accum(std::vector<T>(arr.size() + 1)) {\n\n      \
    \          for (int i = 0 ; i < (int)arr.size() ; i++) {\n                   \
    \ accum[i + 1] = accum[i] + container[i];\n                }\n        }\n    \
    \    \n        Accum_1D(const std::vector<T>& arr, T elem)\n            : container(arr.begin(),\
    \ arr.end())\n            , accum(std::vector<T>(arr.size() + 1, elem)) {\n  \
    \              \n                for (int i = 0 ; i < (int)arr.size() ; i++) {\n\
    \                    accum[i + 1] = accum[i] + container[i];\n               \
    \ }\n        }\n\n        T get(int idx) {\n            return container[idx];\n\
    \        }\n\n        T query(int l, int r) {\n            return accum[r] - accum[l];\n\
    \        }\n        \n    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    template <class\
    \ T>\n    class Accum_1D {\n    private:\n        std::vector<T> container;\n\
    \        std::vector<T> accum;\n\n    public:\n        Accum_1D(const std::vector<T>&\
    \ arr) \n            : container(arr.begin(), arr.end())\n            , accum(std::vector<T>(arr.size()\
    \ + 1)) {\n\n                for (int i = 0 ; i < (int)arr.size() ; i++) {\n \
    \                   accum[i + 1] = accum[i] + container[i];\n                }\n\
    \        }\n        \n        Accum_1D(const std::vector<T>& arr, T elem)\n  \
    \          : container(arr.begin(), arr.end())\n            , accum(std::vector<T>(arr.size()\
    \ + 1, elem)) {\n                \n                for (int i = 0 ; i < (int)arr.size()\
    \ ; i++) {\n                    accum[i + 1] = accum[i] + container[i];\n    \
    \            }\n        }\n\n        T get(int idx) {\n            return container[idx];\n\
    \        }\n\n        T query(int l, int r) {\n            return accum[r] - accum[l];\n\
    \        }\n        \n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Accum-1D.hpp
  requiredBy: []
  timestamp: '2022-08-16 09:38:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_dsl_5_a.test.cpp
documentation_of: src/dataStructure/Accum-1D.hpp
layout: document
title: "Accum 1D (1\u6B21\u5143\u7D2F\u7A4D\u548C)"
---

## 概要
```
Accum_1D(const std::vector<T>& arr)
```

一次元配列に対して累積和を構築します。数列`A`の累積和`S`とは、 $\displaystyle S_i\ =\ \sum_{i = 1}^{i - 1} A_i$ を満たす数列のことです。

~正直自分で書いたほうが早いです~


### 機能
* `コンストラクタ`: 累積和を構築したい配列`A`を引数に取ります。第二引数に初期値 $S_0$ を指定することも可能です。

* `get(int idx)`: 元の列の`idx`番目の要素を取得します。

* `query(int l, int r)`: $\displaystyle \sum_{i = l}^{r - 1} A_i$ を返します。


### 計算量
* `コンストラクタ`・・・ 配列の長さを $N$ として、 $O(N)$

* `get()`・・・定数時間

* `query()`・・・定数時間
