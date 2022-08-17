---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj_alds_10_c.test.cpp
    title: test/aoj_alds_10_c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/LCS.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\n    template <typename T>\n    class LCS {\n\n    private:\n     \
    \   std::vector<T> a, b;\n        std::vector<T> res;\n        std::vector<std::vector<int>>\
    \ dp;\n        std::vector<std::vector<int>> dir;\n\n        void make(int i,\
    \ int j) {\n            if (i == 0 or j == 0) {\n                return;\n   \
    \         }\n\n            if (dir[i][j] == 3) {\n                make(i - 1,\
    \ j - 1);\n                res.emplace_back(a[i - 1]);\n            }\n      \
    \      else if (dir[i][j] == 2) {\n                make(i - 1, j);\n         \
    \   }\n            else {\n                make(i, j - 1);\n            }\n  \
    \      }\n\n    public:\n        LCS(std::vector<T>& a, std::vector<T>& b)\n \
    \           : a(a.begin(), a.end()), \n              b(b.begin(), b.end()), \n\
    \              dp(a.size() + 1, std::vector<int>(b.size() + 1)), \n          \
    \    dir(a.size() + 1, std::vector<int>(b.size() + 1)) {}\n\n        void build()\
    \ {\n            for (int i = 1 ; i < (int)a.size() + 1 ; i++) {\n           \
    \     for (int j = 1 ; j < (int)b.size() + 1 ; j++) {\n                    if\
    \ (a[i - 1] == b[j - 1]) {\n                        dp[i][j] = dp[i - 1][j - 1]\
    \ + 1;\n                        dir[i][j] = 3;\n                    }\n      \
    \              else if (dp[i - 1][j] >= dp[i][j - 1]) {\n                    \
    \    dp[i][j] = dp[i - 1][j];\n                        dir[i][j] = 2;\n      \
    \              }\n                    else {\n                        dp[i][j]\
    \ = dp[i][j - 1];\n                        dir[i][j] = 1;\n                  \
    \  }\n                }\n            }\n\n            make((int)a.size(), (int)b.size());\n\
    \        }\n\n        std::vector<T> get() {\n            return res;\n      \
    \  }\n\n        int get_size() {\n            return dp[a.size()][b.size()];\n\
    \        }\n\n    };\n\n}// namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\n    template <typename\
    \ T>\n    class LCS {\n\n    private:\n        std::vector<T> a, b;\n        std::vector<T>\
    \ res;\n        std::vector<std::vector<int>> dp;\n        std::vector<std::vector<int>>\
    \ dir;\n\n        void make(int i, int j) {\n            if (i == 0 or j == 0)\
    \ {\n                return;\n            }\n\n            if (dir[i][j] == 3)\
    \ {\n                make(i - 1, j - 1);\n                res.emplace_back(a[i\
    \ - 1]);\n            }\n            else if (dir[i][j] == 2) {\n            \
    \    make(i - 1, j);\n            }\n            else {\n                make(i,\
    \ j - 1);\n            }\n        }\n\n    public:\n        LCS(std::vector<T>&\
    \ a, std::vector<T>& b)\n            : a(a.begin(), a.end()), \n             \
    \ b(b.begin(), b.end()), \n              dp(a.size() + 1, std::vector<int>(b.size()\
    \ + 1)), \n              dir(a.size() + 1, std::vector<int>(b.size() + 1)) {}\n\
    \n        void build() {\n            for (int i = 1 ; i < (int)a.size() + 1 ;\
    \ i++) {\n                for (int j = 1 ; j < (int)b.size() + 1 ; j++) {\n  \
    \                  if (a[i - 1] == b[j - 1]) {\n                        dp[i][j]\
    \ = dp[i - 1][j - 1] + 1;\n                        dir[i][j] = 3;\n          \
    \          }\n                    else if (dp[i - 1][j] >= dp[i][j - 1]) {\n \
    \                       dp[i][j] = dp[i - 1][j];\n                        dir[i][j]\
    \ = 2;\n                    }\n                    else {\n                  \
    \      dp[i][j] = dp[i][j - 1];\n                        dir[i][j] = 1;\n    \
    \                }\n                }\n            }\n\n            make((int)a.size(),\
    \ (int)b.size());\n        }\n\n        std::vector<T> get() {\n            return\
    \ res;\n        }\n\n        int get_size() {\n            return dp[a.size()][b.size()];\n\
    \        }\n\n    };\n\n}// namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/LCS.hpp
  requiredBy: []
  timestamp: '2022-07-30 03:20:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj_alds_10_c.test.cpp
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
* `コンストラクタ`: 最大共通部分列を求めたい二つの列の参照を引数にとります。(`string`は`vector<char>`にしなければならないことに注意してください)
  
* `build()`: 最大共通部分列を計算し、`res`に結果を保存します
  
* `get()`: 最大共通部分列を返します。`build()`を先に実行してください
  
* `get_size()`: 最大共通部分列の長さを返します

  
### 計算量
* `build()` ・・・ $O(NM)$ ( $N,\  M$ はそれぞれの列の長さ)
