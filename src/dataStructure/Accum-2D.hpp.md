---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_dsl_5_b.test.cpp
    title: test/aoj_dsl_5_b.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Accum-2D.hpp\"\n\n#include <iostream>\n\
    #include <utility>\n#include <vector>\n\nnamespace zawa {\n\n    template <class\
    \ T>\n    class Accum_2D {\n    private:\n        std::vector<std::vector<T>>\
    \ container;\n        std::vector<std::vector<T>> accum;\n\n    public:\n    \
    \    Accum_2D(const std::vector<std::vector<T>>& arr)\n            : container(arr.begin(),\
    \ arr.end())\n            , accum(std::vector<std::vector<T>>(arr.size() + 1,\
    \ std::vector<T>(arr[0].size() + 1))) {}\n\n        Accum_2D(const std::vector<std::vector<T>>&\
    \ arr, T elem)\n            : container(arr.begin(), arr.end())\n            ,\
    \ accum(std::vector<std::vector<T>>(arr.size() + 1, std::vector<T>(arr[0].size()\
    \ + 1, elem))) {}\n\n        Accum_2D(int h, int w)\n            : container(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w)))\n            , accum(std::vector<std::vector<T>>(h + 1,\
    \ std::vector<T>(w + 1))) {}\n\n        Accum_2D(int h, int w, T elem)\n     \
    \       : container(std::vector<std::vector<T>>(h, std::vector<T>(w)))\n     \
    \       , accum(std::vector<std::vector<T>>(h + 1, std::vector<T>(w + 1, elem)))\
    \ {}\n\n        void set(int y, int x, T val) {\n            container[y][x] =\
    \ val;\n        }\n\n        void add(int y, int x, T val) {\n            container[y][x]\
    \ += val;\n        }\n\n        void build() {\n            for (int i = 0 ; i\
    \ < (int)container.size() ; i++) {\n                for (int j = 0 ; j < (int)container[i].size()\
    \ ; j++) {\n                    accum[i + 1][j + 1] = accum[i][j + 1] + accum[i\
    \ + 1][j] - accum[i][j] + container[i][j];\n                }\n            }\n\
    \        }\n\n        T get(int y, int x) {\n            return container[y][x];\n\
    \        }\n\n        T query(int y1, int x1, int y2, int x2) {\n            return\
    \ accum[y2][x2] - accum[y1][x2] - accum[y2][x1] + accum[y1][x1];\n        }\n\n\
    \        T query(std::pair<int, int> p1, std::pair<int, int> p2) {\n         \
    \   return query(p1.first, p1.second, p2.first, p2.second);\n        }\n\n   \
    \     void print() {\n            for (auto y : accum) {\n                for\
    \ (int i = 0 ; i < (int)y.size() ; i++) std::cout << y[i] << (i == (int)y.size()\
    \ - 1 ? '\\n' : ' ');\n                std::cout << std::endl;\n            }\n\
    \        }\n\n    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\n    template <class T>\n    class Accum_2D {\n    private:\n\
    \        std::vector<std::vector<T>> container;\n        std::vector<std::vector<T>>\
    \ accum;\n\n    public:\n        Accum_2D(const std::vector<std::vector<T>>& arr)\n\
    \            : container(arr.begin(), arr.end())\n            , accum(std::vector<std::vector<T>>(arr.size()\
    \ + 1, std::vector<T>(arr[0].size() + 1))) {}\n\n        Accum_2D(const std::vector<std::vector<T>>&\
    \ arr, T elem)\n            : container(arr.begin(), arr.end())\n            ,\
    \ accum(std::vector<std::vector<T>>(arr.size() + 1, std::vector<T>(arr[0].size()\
    \ + 1, elem))) {}\n\n        Accum_2D(int h, int w)\n            : container(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w)))\n            , accum(std::vector<std::vector<T>>(h + 1,\
    \ std::vector<T>(w + 1))) {}\n\n        Accum_2D(int h, int w, T elem)\n     \
    \       : container(std::vector<std::vector<T>>(h, std::vector<T>(w)))\n     \
    \       , accum(std::vector<std::vector<T>>(h + 1, std::vector<T>(w + 1, elem)))\
    \ {}\n\n        void set(int y, int x, T val) {\n            container[y][x] =\
    \ val;\n        }\n\n        void add(int y, int x, T val) {\n            container[y][x]\
    \ += val;\n        }\n\n        void build() {\n            for (int i = 0 ; i\
    \ < (int)container.size() ; i++) {\n                for (int j = 0 ; j < (int)container[i].size()\
    \ ; j++) {\n                    accum[i + 1][j + 1] = accum[i][j + 1] + accum[i\
    \ + 1][j] - accum[i][j] + container[i][j];\n                }\n            }\n\
    \        }\n\n        T get(int y, int x) {\n            return container[y][x];\n\
    \        }\n\n        T query(int y1, int x1, int y2, int x2) {\n            return\
    \ accum[y2][x2] - accum[y1][x2] - accum[y2][x1] + accum[y1][x1];\n        }\n\n\
    \        T query(std::pair<int, int> p1, std::pair<int, int> p2) {\n         \
    \   return query(p1.first, p1.second, p2.first, p2.second);\n        }\n\n   \
    \     void print() {\n            for (auto y : accum) {\n                for\
    \ (int i = 0 ; i < (int)y.size() ; i++) std::cout << y[i] << (i == (int)y.size()\
    \ - 1 ? '\\n' : ' ');\n                std::cout << std::endl;\n            }\n\
    \        }\n\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Accum-2D.hpp
  requiredBy: []
  timestamp: '2022-08-16 22:51:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_dsl_5_b.test.cpp
documentation_of: src/dataStructure/Accum-2D.hpp
layout: document
title: "Accum 2D (2\u6B21\u5143\u7D2F\u7A4D\u548C)"
---

## 概要
```
Accum_2D(const std::vector<std::vector<T>>& arr)
```

二次元配列(行列)に対して累積和を構築します。行列`A`の累積和`S`とは、 $\displaystyle S_{ij}\ =\ \sum_{p = 1}^{i - 1} \sum_{q = 1}^{j - 1} A_{pq}$ を満たす行列のことです。


### 機能
* `コンストラクタ`: 累積和を取りたい配列 $A$ の参照をとる。もしくはサイズのみを指定する。第二引数に32bit整数を入れると $S_{00}$ を指定するることが可能です。

* `set(int y, int x, T val)`: $A_{yx}$ に`val`を代入します。

* `add(int y, int x, T val)`: $A_{yx}$ に`val` を可算します。

  * `set, add`は`build`前に行ってください。
 
* `build()` 累積和を`S`構築します。

* `get(int y, int x)`: $A_{yx}$ を取得します。

* `query(int y1, int x1, int y2, int x2)`: $\displaystyle \sum_{i = y_1}^{y_2 - 1} \sum_{j = x_1}^{x_2 - 1} A_{ij}$ を得ます。


### 計算量
* `build`・・・行列のサイズを $N \times M$ として $O(NM)$
* 他・・・定数時間
