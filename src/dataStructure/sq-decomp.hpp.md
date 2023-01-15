---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sq-decomp-RSQ.test.cpp
    title: test/sq-decomp-RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sq-decomp-RmQ.test.cpp
    title: test/sq-decomp-RmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/sq-decomp.hpp\"\n\n#include <vector>\n\
    #include <cmath>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ monoid>\nclass sq_decomp {\nprivate:\n\tusing T = typename monoid::T;\n\tint\
    \ square;\n\tstd::vector<T> dat;\n\tstd::vector<T> bucket;\n\n\tvoid update(int\
    \ id) {\n\t\tT val = monoid::id;\n\t\tint l = id * square;\n\t\tfor (int i = 0\
    \ ; i < square and l + i < (int)dat.size()  ; i++) {\n\t\t\tval = monoid::op(dat[l\
    \ + i], val);\n\t\t}\n\t\tbucket[id] = val;\n\t}\n\npublic:\n\tsq_decomp(const\
    \ std::vector<T>& as) : square(std::sqrt(as.size() + 1)), dat(as), bucket(((int)as.size()\
    \ + square - 1) / square, monoid::id)  {\n\t\tfor (int i = 0 ; i < (int)dat.size()\
    \ ; i++) {\n\t\t\tbucket[i / square] = monoid::op(dat[i], bucket[i / square]);\n\
    \t\t}\n\t}\n\tsq_decomp(int n) : square(std::sqrt(n + 1)), dat(n, monoid::id),\
    \ bucket((n + square - 1) / square, monoid::id) {}\n\n\tvoid update(int i, const\
    \ T& x) {\n\t\tdat[i] = x;\n\t\tupdate(i / square);\n\t}\n\n\tT action(int i,\
    \ const T& x) {\n\t\tdat[i] = monoid::op(dat[i], x);\n\t\tupdate(i / square);\n\
    \t\treturn dat[i];\n\t}\n\n\tT prod(int l, int r) {\n\t\tT res = monoid::id;\n\
    \t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint p = i * square,\
    \ q = (i + 1) * square;\n\t\t\tif (q <= l or r <= p) {\n\t\t\t\tcontinue;\n\t\t\
    \t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tres = monoid::op(res, bucket[i]);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tfor (int j = std::max(p, l) ; j < std::min({ (int)dat.size(),\
    \ q, r }) ; j++) {\n\t\t\t\t\tres = monoid::op(res, dat[j]);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> get_dat() {\n\t\treturn dat;\n\
    \t}\n\t\n\tstd::vector<T> get_bucket(std::size_t i) {\n\t\treturn bucket[i];\n\
    \t}\n\n};\n\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class monoid>\nclass sq_decomp {\nprivate:\n\t\
    using T = typename monoid::T;\n\tint square;\n\tstd::vector<T> dat;\n\tstd::vector<T>\
    \ bucket;\n\n\tvoid update(int id) {\n\t\tT val = monoid::id;\n\t\tint l = id\
    \ * square;\n\t\tfor (int i = 0 ; i < square and l + i < (int)dat.size()  ; i++)\
    \ {\n\t\t\tval = monoid::op(dat[l + i], val);\n\t\t}\n\t\tbucket[id] = val;\n\t\
    }\n\npublic:\n\tsq_decomp(const std::vector<T>& as) : square(std::sqrt(as.size()\
    \ + 1)), dat(as), bucket(((int)as.size() + square - 1) / square, monoid::id) \
    \ {\n\t\tfor (int i = 0 ; i < (int)dat.size() ; i++) {\n\t\t\tbucket[i / square]\
    \ = monoid::op(dat[i], bucket[i / square]);\n\t\t}\n\t}\n\tsq_decomp(int n) :\
    \ square(std::sqrt(n + 1)), dat(n, monoid::id), bucket((n + square - 1) / square,\
    \ monoid::id) {}\n\n\tvoid update(int i, const T& x) {\n\t\tdat[i] = x;\n\t\t\
    update(i / square);\n\t}\n\n\tT action(int i, const T& x) {\n\t\tdat[i] = monoid::op(dat[i],\
    \ x);\n\t\tupdate(i / square);\n\t\treturn dat[i];\n\t}\n\n\tT prod(int l, int\
    \ r) {\n\t\tT res = monoid::id;\n\t\tfor (int i = 0 ; i < (int)bucket.size() ;\
    \ i++) {\n\t\t\tint p = i * square, q = (i + 1) * square;\n\t\t\tif (q <= l or\
    \ r <= p) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\
    \tres = monoid::op(res, bucket[i]);\n\t\t\t}\n\t\t\telse {\n\t\t\t\tfor (int j\
    \ = std::max(p, l) ; j < std::min({ (int)dat.size(), q, r }) ; j++) {\n\t\t\t\t\
    \tres = monoid::op(res, dat[j]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tstd::vector<T> get_dat() {\n\t\treturn dat;\n\t}\n\t\n\tstd::vector<T>\
    \ get_bucket(std::size_t i) {\n\t\treturn bucket[i];\n\t}\n\n};\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/sq-decomp.hpp
  requiredBy: []
  timestamp: '2023-01-16 02:42:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sq-decomp-RSQ.test.cpp
  - test/sq-decomp-RmQ.test.cpp
documentation_of: src/dataStructure/sq-decomp.hpp
layout: document
title: "sq-decomp (\u5E73\u65B9\u5206\u5272\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\
  \u30EA)"
---

## 概要

平方分割によって区間クエリに答えます。

モノイド $(S, \oplus)$ に対して、 列 $A\ =\ \{ A_1, A_2, \dots,\ A_n\}$ について ( $A_i\ \in S$ ) 以下の二種類のクエリ

- $A_i\ \leftarrow\ x\ (x\in S)$
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

に回答することができます。


## 機能

`zawa::sq_decomp<monoid>(std::size_t n)`
- $A$ をサイズ $n$ で各要素が `monoid::id` の列で初期化します。
- `monoid`: 以下の要素を持つ構造体、モノイドを表現する
	- `using T`: $S$ となる型
	- `static constexpr T id`: $\oplus$ の単位元
	- `static T add(const T& a, const T& b)`: $a\  \oplus\ b$ を返り値とする関数
	- 実装例はsrc/utility/monoid/を確認ください
- **計算量** : $O(n)$

`zawa::sq_decomp<monoid>(const std::vector<monoid::T>& as)`
- $A$ を `as`で初期化します。
- **計算量** : $O(n)$

`void zawa::sq_decomp<monoid>::update(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::T zawa::sq_decomp<monoid>::action(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ A_i\ \oplus\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::T zawa::sq_decomp<monoid>::prod(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます。
- **計算量** : $O(\sqrt{n})$
