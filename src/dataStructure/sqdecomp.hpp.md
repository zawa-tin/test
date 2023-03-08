---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-AOJRSQ.test.cpp
    title: test/sqdecomp-AOJRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-AOJRmQ.test.cpp
    title: test/sqdecomp-AOJRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/sqdecomp-LCRSQ.test.cpp
    title: test/sqdecomp-LCRSQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/sqdecomp.hpp\"\n\n#include <vector>\n\
    #include <cmath>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class\
    \ monoid>\nclass sqdecomp {\nprivate:\n\tusing T = typename monoid::value_type;\n\
    \tint square;\n\tstd::vector<T> dat;\n\tstd::vector<T> bucket;\n\n\tvoid update(int\
    \ id) {\n\t\tT val = monoid::identity;\n\t\tint l = id * square;\n\t\tfor (int\
    \ i = 0 ; i < square and l + i < (int)dat.size()  ; i++) {\n\t\t\tval = monoid::operation(dat[l\
    \ + i], val);\n\t\t}\n\t\tbucket[id] = val;\n\t}\n\npublic:\n\tsqdecomp(const\
    \ std::vector<T>& as) : square(std::sqrt(as.size() + 1)), dat(as), bucket(((int)as.size()\
    \ + square - 1) / square, monoid::identity)  {\n\t\tfor (int i = 0 ; i < (int)dat.size()\
    \ ; i++) {\n\t\t\tbucket[i / square] = monoid::operation(dat[i], bucket[i / square]);\n\
    \t\t}\n\t}\n\tsqdecomp(int n) : square(std::sqrt(n + 1)), dat(n, monoid::identity),\
    \ bucket((n + square - 1) / square, monoid::identity) {}\n\n\tvoid update(int\
    \ i, const T& x) {\n\t\tdat[i] = x;\n\t\tupdate(i / square);\n\t}\n\n\tT action(int\
    \ i, const T& x) {\n\t\tdat[i] = monoid::operation(dat[i], x);\n\t\tupdate(i /\
    \ square);\n\t\treturn dat[i];\n\t}\n\n\tT prod(int l, int r) {\n\t\tT res = monoid::identity;\n\
    \t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint p = i * square,\
    \ q = (i + 1) * square;\n\t\t\tif (q <= l or r <= p) {\n\t\t\t\tcontinue;\n\t\t\
    \t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tres = monoid::operation(res, bucket[i]);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tfor (int j = std::max(p, l) ; j < std::min({ (int)dat.size(),\
    \ q, r }) ; j++) {\n\t\t\t\t\tres = monoid::operation(res, dat[j]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> get_dat() {\n\t\t\
    return dat;\n\t}\n\t\n\tstd::vector<T> get_bucket(std::size_t i) {\n\t\treturn\
    \ bucket[i];\n\t}\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class monoid>\nclass sqdecomp {\nprivate:\n\t\
    using T = typename monoid::value_type;\n\tint square;\n\tstd::vector<T> dat;\n\
    \tstd::vector<T> bucket;\n\n\tvoid update(int id) {\n\t\tT val = monoid::identity;\n\
    \t\tint l = id * square;\n\t\tfor (int i = 0 ; i < square and l + i < (int)dat.size()\
    \  ; i++) {\n\t\t\tval = monoid::operation(dat[l + i], val);\n\t\t}\n\t\tbucket[id]\
    \ = val;\n\t}\n\npublic:\n\tsqdecomp(const std::vector<T>& as) : square(std::sqrt(as.size()\
    \ + 1)), dat(as), bucket(((int)as.size() + square - 1) / square, monoid::identity)\
    \  {\n\t\tfor (int i = 0 ; i < (int)dat.size() ; i++) {\n\t\t\tbucket[i / square]\
    \ = monoid::operation(dat[i], bucket[i / square]);\n\t\t}\n\t}\n\tsqdecomp(int\
    \ n) : square(std::sqrt(n + 1)), dat(n, monoid::identity), bucket((n + square\
    \ - 1) / square, monoid::identity) {}\n\n\tvoid update(int i, const T& x) {\n\t\
    \tdat[i] = x;\n\t\tupdate(i / square);\n\t}\n\n\tT action(int i, const T& x) {\n\
    \t\tdat[i] = monoid::operation(dat[i], x);\n\t\tupdate(i / square);\n\t\treturn\
    \ dat[i];\n\t}\n\n\tT prod(int l, int r) {\n\t\tT res = monoid::identity;\n\t\t\
    for (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint p = i * square, q\
    \ = (i + 1) * square;\n\t\t\tif (q <= l or r <= p) {\n\t\t\t\tcontinue;\n\t\t\t\
    }\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tres = monoid::operation(res, bucket[i]);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tfor (int j = std::max(p, l) ; j < std::min({ (int)dat.size(),\
    \ q, r }) ; j++) {\n\t\t\t\t\tres = monoid::operation(res, dat[j]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> get_dat() {\n\t\t\
    return dat;\n\t}\n\t\n\tstd::vector<T> get_bucket(std::size_t i) {\n\t\treturn\
    \ bucket[i];\n\t}\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/sqdecomp.hpp
  requiredBy: []
  timestamp: '2023-02-06 18:33:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sqdecomp-AOJRmQ.test.cpp
  - test/sqdecomp-LCRSQ.test.cpp
  - test/sqdecomp-AOJRSQ.test.cpp
documentation_of: src/dataStructure/sqdecomp.hpp
layout: document
title: "sqdecomp (\u5E73\u65B9\u5206\u5272\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\
  \u30EA)"
---

## 概要

平方分割によって区間クエリに答えます。

モノイド $(S, \oplus)$ に対して、 列 $A\ =\ \{ A_1, A_2, \dots,\ A_n\}$ について ( $A_i\ \in S$ ) 以下の二種類のクエリ

- $A_i\ \leftarrow\ x\ (x\in S)$
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

に回答することができます。


## 機能

**コンストラクタ**

`zawa::sqdecomp<monoid>(std::size_t n)`
- $A$ をサイズ $n$ で各要素が `monoid::identity` の列で初期化します。
- `monoid`: 以下の要素を持つ構造体、モノイドを表現する
	- `テンプレート引数`: `S`となる型
	- `using value_type`: $S$ となる型(`T`と同じ)
	- `static constexpr value_type identity`: $\oplus$ の単位元
	- `static T operation(const T& a, const T& b)`: $a\  \oplus\ b$ を返り値とする関数
	- 実装例はsrc/utility/monoid/を確認ください
- **計算量** : $O(n)$

`zawa::sqdecomp<monoid>(const std::vector<monoid::T>& as)`
- $A$ を `as`で初期化します。
- **計算量** : $O(n)$

**メンバ関数**

`void update(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::value_type action(int i, const monoid::T& x)`
- $A_i\ \leftarrow\ A_i\ \oplus\ x$ とします。
- **計算量** : $O(\sqrt{n})$

`monoid::value_type prod(int l, int r)`
- $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求めます。
- **計算量** : $O(\sqrt{n})$
