---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC125C.test.cpp
    title: test/ABC125C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sparse-table.test.cpp
    title: test/sparse-table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/sparse-table.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class structure>\nclass sparse_table {\nprivate:\n\
    \tusing T = typename structure::T;\n\tstd::vector<int> ls;\n\tstd::vector<std::vector<T>>\
    \ dat;\n\npublic:\n\n\tsparse_table(const std::vector<T>& as) : ls(as.size() +\
    \ 1, 0) {\n\t\tfor (int i = 1 ; i < (int)ls.size() ; i++) {\n\t\t\tls[i] = ls[i\
    \ - 1] + (i >> (ls[i - 1] + 1));\n\t\t}\n\t\tdat = std::vector(ls.back() + 1,\
    \ as);\n\t\tdat[0] = as;\n\t\tfor (int i = 1 ; i < (int)dat.size() ; i++) {\n\t\
    \t\tint pt = (1 << i);\n\t\t\tfor (int j = 0 ; j + pt - 1 < (int)dat[i].size()\
    \ ; j++) {\n\t\t\t\tdat[i][j] = structure::op(dat[i - 1][j], dat[i - 1][j + (pt\
    \ >> 1)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tT query(int l, int r) {\n\t\tint now = ls[r\
    \ - l];\n\t\treturn structure::op(dat[now][l], dat[now][r - (1 << now)]);\n\t\
    }\n\n\tconst std::vector<std::vector<T>>& get() {\n\t\treturn dat;\n\t}\n\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class\
    \ structure>\nclass sparse_table {\nprivate:\n\tusing T = typename structure::T;\n\
    \tstd::vector<int> ls;\n\tstd::vector<std::vector<T>> dat;\n\npublic:\n\n\tsparse_table(const\
    \ std::vector<T>& as) : ls(as.size() + 1, 0) {\n\t\tfor (int i = 1 ; i < (int)ls.size()\
    \ ; i++) {\n\t\t\tls[i] = ls[i - 1] + (i >> (ls[i - 1] + 1));\n\t\t}\n\t\tdat\
    \ = std::vector(ls.back() + 1, as);\n\t\tdat[0] = as;\n\t\tfor (int i = 1 ; i\
    \ < (int)dat.size() ; i++) {\n\t\t\tint pt = (1 << i);\n\t\t\tfor (int j = 0 ;\
    \ j + pt - 1 < (int)dat[i].size() ; j++) {\n\t\t\t\tdat[i][j] = structure::op(dat[i\
    \ - 1][j], dat[i - 1][j + (pt >> 1)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tT query(int l,\
    \ int r) {\n\t\tint now = ls[r - l];\n\t\treturn structure::op(dat[now][l], dat[now][r\
    \ - (1 << now)]);\n\t}\n\n\tconst std::vector<std::vector<T>>& get() {\n\t\treturn\
    \ dat;\n\t}\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/sparse-table.hpp
  requiredBy: []
  timestamp: '2023-01-12 12:07:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC125C.test.cpp
  - test/sparse-table.test.cpp
documentation_of: src/dataStructure/sparse-table.hpp
layout: document
title: "sparse-table ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\u89E3\
  \u7B54 )"
---

## 概要

**更新の無い列** $A$ に対して以下の条件を満たす演算 $\oplus$ に対するクエリ $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める

- 結合則 $(a \oplus b) \oplus c\ =\ a \oplus (b \oplus c)$
- 等冪則 $a \oplus a\ =\ a$

例: `min`、`max`、`gcd`

## 機能
`sparse_table<structure>(const std::vector<structure::T>& as)`
- コンストラクタ
- `structure`
	- 以下の条件を満たす構造体
		- `using T = OOO`が存在する(演算の型)
		- ２つの`T`型の変数`a, b`を引数にとり、 $a\ \oplus\ b$ を返す`static`メンバ関数`T op(T a, T b)`を持つ
	- 実装例は`test/sparse-table.test.cpp`を確認ください
- `as`
	- クエリを処理したい`structure::T`型の列
- **計算量**: $O(\mid A\mid\log \mid A\mid)$

`structure::T sparse_table::query(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1}A_i$ を求める
- **制約**: $0\ \le\ l\ <\ r\ \le\ \mid A\mid$
- **計算量**: $O(1)$

`const std::vector<std::vector<structure::T>>& sparse_table::get()`
- `private`にある`dat`を返します。
- デバッグ用
