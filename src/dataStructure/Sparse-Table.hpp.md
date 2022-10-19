---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Sparse-Table.hpp\"\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T, T (*op)(T, T)>\nclass Sparse_Table {\n\
    private:\n    std::vector<std::vector<T>> table;\n\npublic:\n    Sparse_Table(std::vector<T>\
    \ as) \n        : table(std::__lg(as.size()) + 1, std::vector(as.size(), 0)) {\n\
    \            \n        for (std::size_t i = 0 ; i < as.size() ; i++) {\n     \
    \       table[0][i] = as[i];\n        }\n\n        for (std::size_t i = 1 ; i\
    \ < table.size() ; i++) {\n            std::size_t pt = (1 << i);\n          \
    \  for (std::size_t j = 0 ; j + pt - 1 < table[i].size() ; j++) {\n          \
    \      table[i][j] = op(table[i - 1][j], table[i - 1][j + (pt >> 1)]);\n     \
    \       }\n        }\n    }\n\n    T query(int l, int r) {\n        int lg = std::__lg(r\
    \ - l);\n        return op(table[lg][l], table[lg][r - (1 << lg)]);\n    }\n\n\
    \    std::vector<std::vector<T>> hoge() {\n        return table;\n    }\n\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T,\
    \ T (*op)(T, T)>\nclass Sparse_Table {\nprivate:\n    std::vector<std::vector<T>>\
    \ table;\n\npublic:\n    Sparse_Table(std::vector<T> as) \n        : table(std::__lg(as.size())\
    \ + 1, std::vector(as.size(), 0)) {\n            \n        for (std::size_t i\
    \ = 0 ; i < as.size() ; i++) {\n            table[0][i] = as[i];\n        }\n\n\
    \        for (std::size_t i = 1 ; i < table.size() ; i++) {\n            std::size_t\
    \ pt = (1 << i);\n            for (std::size_t j = 0 ; j + pt - 1 < table[i].size()\
    \ ; j++) {\n                table[i][j] = op(table[i - 1][j], table[i - 1][j +\
    \ (pt >> 1)]);\n            }\n        }\n    }\n\n    T query(int l, int r) {\n\
    \        int lg = std::__lg(r - l);\n        return op(table[lg][l], table[lg][r\
    \ - (1 << lg)]);\n    }\n\n    std::vector<std::vector<T>> hoge() {\n        return\
    \ table;\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Sparse-Table.hpp
  requiredBy: []
  timestamp: '2022-10-20 01:04:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/dataStructure/Sparse-Table.hpp
layout: document
title: "Sparse-Table ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\u89E3\
  \u7B54 )"
---

## 概要

```
template<class T, T (*op)(T, T)>
Sparse_Table(std::vector<T>)
```

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

## 機能
 - `コンストラクタ`: テンプレート引数に型と演算 $\oplus$ を入れてくだださい（関数ポインタってやつ？、ACLのsegtreeと同じノリ)
- `query(int int)`:  半開区間で入れてください

## 計算量

- `コンストラクタ`: $O(N \log N)$
- `query`: $O(\log N)$ <-は？
	- TODO: $O(1)$ にする
