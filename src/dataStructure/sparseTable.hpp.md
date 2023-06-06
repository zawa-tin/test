---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC125-C.test.cpp
    title: test/ABC125-C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sparseTable.test.cpp
    title: test/sparseTable.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/sparseTable.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass sparseTable\
    \ {\nprivate:\n\tusing T = typename structure::valueType;\n\tstd::vector<int>\
    \ L;\n\tstd::vector<std::vector<T>> dat;\n\npublic:\n\n\tsparseTable(const std::vector<T>&\
    \ A) : L(A.size() + 1, 0) {\n\t\tfor (int i = 1 ; i < (int)L.size() ; i++) {\n\
    \t\t\tL[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n\t\t}\n\t\tdat = std::vector(L.back()\
    \ + 1, A);\n\t\tfor (int i = 1 ; i < (int)dat.size() ; i++) {\n\t\t\tint pt =\
    \ (1 << i);\n\t\t\tfor (int j = 0 ; j + pt - 1 < (int)dat[i].size() ; j++) {\n\
    \t\t\t\tdat[i][j] = structure::operation(dat[i - 1][j], dat[i - 1][j + (pt >>\
    \ 1)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tT query(int l, int r) {\n\t\tassert(0 <= l and\
    \ l < (int)dat[0].size());\n\t\tassert(l <= r and r <= (int)dat[0].size());\n\t\
    \tint now = L[r - l];\n\t\treturn structure::operation(dat[now][l], dat[now][r\
    \ - (1 << now)]);\n\t}\n\n\tinline std::vector<std::vector<T>> _dat() const {\n\
    \t\treturn dat;\n\t}\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\
    \ntemplate <class structure>\nclass sparseTable {\nprivate:\n\tusing T = typename\
    \ structure::valueType;\n\tstd::vector<int> L;\n\tstd::vector<std::vector<T>>\
    \ dat;\n\npublic:\n\n\tsparseTable(const std::vector<T>& A) : L(A.size() + 1,\
    \ 0) {\n\t\tfor (int i = 1 ; i < (int)L.size() ; i++) {\n\t\t\tL[i] = L[i - 1]\
    \ + (i >> (L[i - 1] + 1));\n\t\t}\n\t\tdat = std::vector(L.back() + 1, A);\n\t\
    \tfor (int i = 1 ; i < (int)dat.size() ; i++) {\n\t\t\tint pt = (1 << i);\n\t\t\
    \tfor (int j = 0 ; j + pt - 1 < (int)dat[i].size() ; j++) {\n\t\t\t\tdat[i][j]\
    \ = structure::operation(dat[i - 1][j], dat[i - 1][j + (pt >> 1)]);\n\t\t\t}\n\
    \t\t}\n\t}\n\n\tT query(int l, int r) {\n\t\tassert(0 <= l and l < (int)dat[0].size());\n\
    \t\tassert(l <= r and r <= (int)dat[0].size());\n\t\tint now = L[r - l];\n\t\t\
    return structure::operation(dat[now][l], dat[now][r - (1 << now)]);\n\t}\n\n\t\
    inline std::vector<std::vector<T>> _dat() const {\n\t\treturn dat;\n\t}\n\n};\n\
    \n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/sparseTable.hpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparseTable.test.cpp
  - test/ABC125-C.test.cpp
documentation_of: src/dataStructure/sparseTable.hpp
layout: document
title: "sparseTable ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\u89E3\
  \u7B54 )"
---

## 概要

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

例: `min`、`max`、`gcd`

## 機能

**コンストラクタ**

以下、`structure::valueType`を`T`と省略する。
```
sparseTable<structure>(const std::vector<T>& A)
```
$A$ を引数の`std::vector<T>`で初期化する

テンプレート引数`structure`は以下を満たす構造体にしてください
- $A$ の型を`using valueType = `でエイリアスする
- 演算 $\oplus$ を表現する`static valueType operation(const valueType& a, const valueType& b)` 関数

**計算量**

$O(\mid A\mid \log \mid A \mid)$

<br />

**メンバ**

**query**
```
T query(int l, int r)
```

$\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

**制約**

$0\ \le\ l\ <\ r\ \le\ \mid A\mid$

**計算量**

$O(1)$

<br />

**_dat**
```
const std::vector<std::vector<T>>& _dat()
```
- 内部のコンテナを返します。デバッグにでも
