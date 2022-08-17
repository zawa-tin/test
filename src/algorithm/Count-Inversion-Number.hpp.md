---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_alds_5_d.test.cpp
    title: test/aoj_alds_5_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Count-Inversion-Number.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\n    template <typename T>\n    class Count_Inversion_Number\
    \ {\n    private:\n        std::vector<T> arr;\n        long long count_inversion_number\
    \ = 0;\n\n        long long sort(int left, int right) {\n            if (right\
    \ - left == 1) return 0LL;\n\n            long long res = 0;\n            int\
    \ mid = left + (right - left) / 2;\n            \n            res += sort(left,\
    \ mid);\n            res += sort(mid, right);\n\n            std::vector<T> fronts(arr.begin()\
    \ + left, arr.begin() + mid);\n            std::vector<T> backs(arr.begin() +\
    \ mid, arr.begin() + right);\n\n            int front_idx = 0, back_idx = 0;\n\
    \            for (int i = left ; i < right ; i++) {\n                if (front_idx\
    \ < (int)fronts.size() and \n                        (back_idx == (int)backs.size()\
    \ or fronts[front_idx] <= backs[back_idx])) {\n                    arr[i] = fronts[front_idx++];\n\
    \                }\n                else {\n                    arr[i] = backs[back_idx++];\n\
    \                    res += mid - left - front_idx;\n                }\n     \
    \       }\n\n            return res;\n        }\n    \n    public:\n        Count_Inversion_Number(std::vector<T>&\
    \ arr) : arr(arr.begin(), arr.end()) {}\n\n        void build() {\n          \
    \  count_inversion_number = sort(0, (int)arr.size());\n        }\n\n        long\
    \ long get() {\n            return count_inversion_number;\n        }\n\n    \
    \    std::vector<T> get_sorted() {\n            return arr;\n        }\n    };\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    template <typename\
    \ T>\n    class Count_Inversion_Number {\n    private:\n        std::vector<T>\
    \ arr;\n        long long count_inversion_number = 0;\n\n        long long sort(int\
    \ left, int right) {\n            if (right - left == 1) return 0LL;\n\n     \
    \       long long res = 0;\n            int mid = left + (right - left) / 2;\n\
    \            \n            res += sort(left, mid);\n            res += sort(mid,\
    \ right);\n\n            std::vector<T> fronts(arr.begin() + left, arr.begin()\
    \ + mid);\n            std::vector<T> backs(arr.begin() + mid, arr.begin() + right);\n\
    \n            int front_idx = 0, back_idx = 0;\n            for (int i = left\
    \ ; i < right ; i++) {\n                if (front_idx < (int)fronts.size() and\
    \ \n                        (back_idx == (int)backs.size() or fronts[front_idx]\
    \ <= backs[back_idx])) {\n                    arr[i] = fronts[front_idx++];\n\
    \                }\n                else {\n                    arr[i] = backs[back_idx++];\n\
    \                    res += mid - left - front_idx;\n                }\n     \
    \       }\n\n            return res;\n        }\n    \n    public:\n        Count_Inversion_Number(std::vector<T>&\
    \ arr) : arr(arr.begin(), arr.end()) {}\n\n        void build() {\n          \
    \  count_inversion_number = sort(0, (int)arr.size());\n        }\n\n        long\
    \ long get() {\n            return count_inversion_number;\n        }\n\n    \
    \    std::vector<T> get_sorted() {\n            return arr;\n        }\n    };\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Count-Inversion-Number.hpp
  requiredBy: []
  timestamp: '2022-07-25 00:17:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_alds_5_d.test.cpp
documentation_of: src/algorithm/Count-Inversion-Number.hpp
layout: document
title: "Count-Inversion-Number(\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u306B\u3088\u308B\
  \u8EE2\u5012\u6570\u306E\u6570\u3048\u4E0A\u3052)"
---

## 概要
```
Count_Inversion_Number(std::vector< T >& as)
```


一次元配列に対して転倒数を求めます。配列$A$の転倒数とは$i < j$かつ$A_i > A_j$を満たす順序対$(i, j)$の総数を指します。


### 機能
* `コンストラクタ`: 転倒数を求めたい配列の参照を引数にとります。

* `build()`: 転倒数を計算し、`count_inversion_number`に計算結果を代入します

* `get()`: 転倒数を返します。事前に`build()`を実行してください

* `get_sorted()`: ソートした配列を返します。使いどころが多分無いです


### 計算量
* `build()`・・・ $O(NlogN)$ ( $N$ は配列の要素数)
