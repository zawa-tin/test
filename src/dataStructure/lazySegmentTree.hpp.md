---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ALPC-L.test.cpp
    title: test/ALPC-L.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
    title: test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
    title: test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
    title: test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30CE\u30FC\u30C9v\u306E\u5DE6\u5B50\u306E\u6DFB\u5B57\u3092\
      \u8FD4\u3059"
    links: []
  bundledCode: "#line 2 \"src/dataStructure/lazySegmentTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass lazySegmentTree\
    \ {\n\t// valueMonoid prod\u306E\u6642\u306E\u6F14\u7B97\n\tusing V = typename\
    \ structure::valueMonoid::valueType;\n\t// operatorMonoid update\u306E\u6642\u306E\
    \u6F14\u7B97\n\tusing O = typename structure::operatorMonoid::valueType;\nprivate:\n\
    \t// prod\u306E\u5358\u4F4D\u5143\n\tstatic constexpr V vId = structure::valueMonoid::identity;\n\
    \t// update\u306E\u5358\u4F4D\u5143\n\tstatic constexpr O oId = structure::operatorMonoid::identity;\n\
    \n\tstruct node {\n\t\tV value;\n\t\tO lazy;\n\t\tnode() : value(vId), lazy(oId)\
    \ {}\n\t};\n\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u5DE6\u5B50\u306E\u6DFB\u5B57\
    \u3092\u8FD4\u3059\n\tconstexpr std::size_t left(std::size_t v) const {\n\t\t\
    return v << 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u53F3\u5B50\u306E\u6DFB\
    \u5B57\u3092\u8FD4\u3059\n\tconstexpr std::size_t right(std::size_t v) const {\n\
    \t\treturn v << 1 | 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u89AA\u306E\
    \u6DFB\u5B57\u3092\u8FD4\u3059\u3002\n\tconstexpr std::size_t parent(std::size_t\
    \ v) const {\n\t\treturn (v >> 1);\n\t}\n\n\tstd::size_t N;\n\tstd::size_t powTwo;\n\
    \tstd::vector<node> dat;\n\n\t// @brief \u9045\u5EF6\u3057\u305F\u5024\u3092\u5B50\
    \u306B\u4F1D\u64AD\u3059\u308B\n\tvoid propagate(std::size_t v) {\n\t\tif (dat[v].lazy\
    \ == oId) {\n\t\t\treturn;\n\t\t}\n\t\tdat[v].value = structure::mapping(dat[v].value,\
    \ dat[v].lazy);\n\t\tif (right(v) < dat.size()) {\n\t\t\tdat[left(v)].lazy = structure::operatorMonoid::operation(dat[left(v)].lazy,\
    \ dat[v].lazy);\n\t\t\tdat[right(v)].lazy = structure::operatorMonoid::operation(dat[right(v)].lazy,\
    \ dat[v].lazy);\n\t\t}\n\t\tdat[v].lazy = oId;\n\t}\n\n\t// @brief \u5185\u90E8\
    \u66F4\u65B0\u7528\n\t// LR\u304C\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3001lr\u304C\
    v\u306E\u6301\u3064\u7BC4\u56F2\n\tvoid update(std::size_t L, std::size_t R, std::size_t\
    \ l, std::size_t r, std::size_t v, const O& value) {\n\t\t// \u5148\u5EF6\u3070\
    \u3057\u3057\u3066\u3044\u305F\u3082\u306E\u3092\u8A55\u4FA1\u3059\u308B\n\t\t\
    propagate(v);\n\n\t\t// \u307E\u3063\u305F\u304F\u304B\u3076\u3063\u3066\u306A\
    \u3044\u6642\u3001\u7279\u306B\u4F55\u3082\u3057\u306A\u3044\n\t\tif (R <= l or\
    \ r <= L) {\n\t\t\treturn;\n\t\t}\n\n\t\t// lr\u304CLR\u306B\u307E\u305F\u304C\
    \u3063\u3066\u3044\u308B\u6642\u3001\u5148\u5EF6\u3070\u3057\u306B\u3059\u308B\
    \n\t\tif (L <= l and r <= R) {\n\t\t\tdat[v].lazy = structure::operatorMonoid::operation(dat[v].lazy,\
    \ value);\n\t\t\tpropagate(v);\n\t\t}\n\t\t// \u5B50\u3092\u8A08\u7B97\u3059\u308B\
    \u5834\u5408\n\t\telse {\n\t\t\tassert(right(v) < dat.size());\n\t\t\tstd::size_t\
    \ childRange = (r - l) >> 1;\n\t\t\tupdate(L, R, l, l + childRange, left(v), value);\n\
    \t\t\tupdate(L, R, l + childRange, r, right(v), value);\n\t\t\tdat[v].value =\
    \ structure::valueMonoid::operation(dat[left(v)].value, dat[right(v)].value);\n\
    \t\t}\n\t}\n\n\t// @brief \u5185\u90E8\u8A08\u7B97\u7528\n\t// LR\u304C\u30AF\u30A8\
    \u30EA\u306E\u7BC4\u56F2\u3001lr\u304Cv\u306E\u6301\u3064\u7BC4\u56F2\n\tV prod(std::size_t\
    \ L, std::size_t R, std::size_t l, std::size_t r, std::size_t v) {\n\n\t\t// \u533A\
    \u9593\u304C\u88AB\u3063\u3066\u306A\u3044\u6642\u3001\u5358\u4F4D\u5143\u3092\
    \u8FD4\u3059\n\t\tif (R <= l or r <= L) {\n\t\t\treturn vId;\n\t\t}\n\n\t\t//\
    \ \u5148\u5EF6\u3070\u3057\u304C\u8A31\u3055\u308C\u306A\u304F\u306A\u3063\u305F\
    \u306E\u3067\u9045\u5EF6\u8A55\u4FA1\u3059\u308B\n\t\tpropagate(v);\n\n\t\t//\
    \ lr\u304CLR\u306B\u3059\u3063\u307D\u308A\u304A\u3055\u307E\u3063\u3066\u3044\
    \u308B\u6642\u3001\u305D\u306E\u30CE\u30FC\u30C9\u306E\u5024\u3092\u639B\u3051\
    \u5408\u308F\u305B\u308B\n\t\tif (L <= l and r <= R) {\n\t\t\treturn dat[v].value;\n\
    \t\t}\n\t\t// \u5B50\u3092\u8FBF\u308B\n\t\telse {\n\t\t\tV res = vId;\n\t\t\t\
    std::size_t childRange = (r - l) >> 1;\n\t\t\tassert(right(v) < dat.size());\n\
    \t\t\tres = structure::valueMonoid::operation(res, prod(L, R, l, l + childRange,\
    \ left(v)));\n\t\t\tres = structure::valueMonoid::operation(res, prod(L, R, l\
    \ + childRange, r, right(v)));\n\t\t\treturn res;\n\t\t}\n\t}\n\npublic:\n\t//\
    \ @brief A = ( vId, vId, ... , vId ), |A| = N\u3068\u3059\u308B\n\t// @param N\
    \ |A|\n\tlazySegmentTree(std::size_t _N) : N(_N) {\n\t\tstd::size_t sz = 1;\n\t\
    \twhile (sz < N) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tpowTwo = sz;\n\t\tdat.resize((sz\
    \ << 1));\n\t}\n\n\t// @brief A\u3092\u5F15\u6570\u306E\u5217\u3067\u521D\u671F\
    \u5316\u3059\u308B\n\t// @param A \u6271\u3046\u5217\n\tlazySegmentTree(const\
    \ std::vector<V>& A) : N(A.size()) {\n\t\tstd::size_t sz = 1;\n\t\twhile (sz <\
    \ N) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tpowTwo = sz;\n\t\tdat.resize((sz << 1));\n\
    \t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + powTwo].value\
    \ = A[i];\n\t\t}\n\t\tfor (std::size_t i = powTwo - 1 ; i > 0 ; i--) {\n\t\t\t\
    dat[i].value = structure::valueMonoid::operation(dat[left(i)].value, dat[right(i)].value);\n\
    \t\t}\n\t}\t\n\t\n\t// @brief A_l .. A_{r - 1}\u306Bvalue\u3067\u5217\u3092\u66F4\
    \u65B0\u3059\u308B\n\t// @param L \u5DE6\n\t// @param R \u53F3\u3001\u534A\u958B\
    \u533A\u9593\u3067\u4E0E\u3048\u308B\u5FC5\u8981\u304C\u3042\u308B\n\t// @param\
    \ value \u66F4\u65B0\u3055\u305B\u308B\u5024\n\tvoid update(std::size_t L, std::size_t\
    \ R, const O& value) {\n\t\tassert(0 <= L and R <= N);\n\t\tassert(L < R);\n\t\
    \tupdate(L, R, 0, powTwo, 1, value);\n\t}\n\n\t// @brief A_l .. A_R \u306E\u7DCF\
    \u7A4D(\u7DCFvalueMonoid::operation)\u3092\u5F97\u308B\n\t// @param L \u5DE6\n\
    \t// @param R \u53F3\u3001\u534A\u958B\u533A\u9593\u3067\u4E0E\u3048\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\n\t// @return \u8A08\u7B97\u7D50\u679C\n\tV prod(std::size_t\
    \ L, std::size_t R) {\n\t\tassert(0 <= L and R <= N);\n\t\tif (L == R) {\n\t\t\
    \treturn vId;\n\t\t}\n\t\treturn prod(L, R, 0, powTwo, 1);\n\t}\n\n\t// @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u3001dat\u3092\u8FD4\u3059\n\t// @return dat\n\
    \tinline std::vector<node> _dat() const {\n\t\treturn dat;\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\
    \ntemplate <class structure>\nclass lazySegmentTree {\n\t// valueMonoid prod\u306E\
    \u6642\u306E\u6F14\u7B97\n\tusing V = typename structure::valueMonoid::valueType;\n\
    \t// operatorMonoid update\u306E\u6642\u306E\u6F14\u7B97\n\tusing O = typename\
    \ structure::operatorMonoid::valueType;\nprivate:\n\t// prod\u306E\u5358\u4F4D\
    \u5143\n\tstatic constexpr V vId = structure::valueMonoid::identity;\n\t// update\u306E\
    \u5358\u4F4D\u5143\n\tstatic constexpr O oId = structure::operatorMonoid::identity;\n\
    \n\tstruct node {\n\t\tV value;\n\t\tO lazy;\n\t\tnode() : value(vId), lazy(oId)\
    \ {}\n\t};\n\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u5DE6\u5B50\u306E\u6DFB\u5B57\
    \u3092\u8FD4\u3059\n\tconstexpr std::size_t left(std::size_t v) const {\n\t\t\
    return v << 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u53F3\u5B50\u306E\u6DFB\
    \u5B57\u3092\u8FD4\u3059\n\tconstexpr std::size_t right(std::size_t v) const {\n\
    \t\treturn v << 1 | 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u89AA\u306E\
    \u6DFB\u5B57\u3092\u8FD4\u3059\u3002\n\tconstexpr std::size_t parent(std::size_t\
    \ v) const {\n\t\treturn (v >> 1);\n\t}\n\n\tstd::size_t N;\n\tstd::size_t powTwo;\n\
    \tstd::vector<node> dat;\n\n\t// @brief \u9045\u5EF6\u3057\u305F\u5024\u3092\u5B50\
    \u306B\u4F1D\u64AD\u3059\u308B\n\tvoid propagate(std::size_t v) {\n\t\tif (dat[v].lazy\
    \ == oId) {\n\t\t\treturn;\n\t\t}\n\t\tdat[v].value = structure::mapping(dat[v].value,\
    \ dat[v].lazy);\n\t\tif (right(v) < dat.size()) {\n\t\t\tdat[left(v)].lazy = structure::operatorMonoid::operation(dat[left(v)].lazy,\
    \ dat[v].lazy);\n\t\t\tdat[right(v)].lazy = structure::operatorMonoid::operation(dat[right(v)].lazy,\
    \ dat[v].lazy);\n\t\t}\n\t\tdat[v].lazy = oId;\n\t}\n\n\t// @brief \u5185\u90E8\
    \u66F4\u65B0\u7528\n\t// LR\u304C\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3001lr\u304C\
    v\u306E\u6301\u3064\u7BC4\u56F2\n\tvoid update(std::size_t L, std::size_t R, std::size_t\
    \ l, std::size_t r, std::size_t v, const O& value) {\n\t\t// \u5148\u5EF6\u3070\
    \u3057\u3057\u3066\u3044\u305F\u3082\u306E\u3092\u8A55\u4FA1\u3059\u308B\n\t\t\
    propagate(v);\n\n\t\t// \u307E\u3063\u305F\u304F\u304B\u3076\u3063\u3066\u306A\
    \u3044\u6642\u3001\u7279\u306B\u4F55\u3082\u3057\u306A\u3044\n\t\tif (R <= l or\
    \ r <= L) {\n\t\t\treturn;\n\t\t}\n\n\t\t// lr\u304CLR\u306B\u307E\u305F\u304C\
    \u3063\u3066\u3044\u308B\u6642\u3001\u5148\u5EF6\u3070\u3057\u306B\u3059\u308B\
    \n\t\tif (L <= l and r <= R) {\n\t\t\tdat[v].lazy = structure::operatorMonoid::operation(dat[v].lazy,\
    \ value);\n\t\t\tpropagate(v);\n\t\t}\n\t\t// \u5B50\u3092\u8A08\u7B97\u3059\u308B\
    \u5834\u5408\n\t\telse {\n\t\t\tassert(right(v) < dat.size());\n\t\t\tstd::size_t\
    \ childRange = (r - l) >> 1;\n\t\t\tupdate(L, R, l, l + childRange, left(v), value);\n\
    \t\t\tupdate(L, R, l + childRange, r, right(v), value);\n\t\t\tdat[v].value =\
    \ structure::valueMonoid::operation(dat[left(v)].value, dat[right(v)].value);\n\
    \t\t}\n\t}\n\n\t// @brief \u5185\u90E8\u8A08\u7B97\u7528\n\t// LR\u304C\u30AF\u30A8\
    \u30EA\u306E\u7BC4\u56F2\u3001lr\u304Cv\u306E\u6301\u3064\u7BC4\u56F2\n\tV prod(std::size_t\
    \ L, std::size_t R, std::size_t l, std::size_t r, std::size_t v) {\n\n\t\t// \u533A\
    \u9593\u304C\u88AB\u3063\u3066\u306A\u3044\u6642\u3001\u5358\u4F4D\u5143\u3092\
    \u8FD4\u3059\n\t\tif (R <= l or r <= L) {\n\t\t\treturn vId;\n\t\t}\n\n\t\t//\
    \ \u5148\u5EF6\u3070\u3057\u304C\u8A31\u3055\u308C\u306A\u304F\u306A\u3063\u305F\
    \u306E\u3067\u9045\u5EF6\u8A55\u4FA1\u3059\u308B\n\t\tpropagate(v);\n\n\t\t//\
    \ lr\u304CLR\u306B\u3059\u3063\u307D\u308A\u304A\u3055\u307E\u3063\u3066\u3044\
    \u308B\u6642\u3001\u305D\u306E\u30CE\u30FC\u30C9\u306E\u5024\u3092\u639B\u3051\
    \u5408\u308F\u305B\u308B\n\t\tif (L <= l and r <= R) {\n\t\t\treturn dat[v].value;\n\
    \t\t}\n\t\t// \u5B50\u3092\u8FBF\u308B\n\t\telse {\n\t\t\tV res = vId;\n\t\t\t\
    std::size_t childRange = (r - l) >> 1;\n\t\t\tassert(right(v) < dat.size());\n\
    \t\t\tres = structure::valueMonoid::operation(res, prod(L, R, l, l + childRange,\
    \ left(v)));\n\t\t\tres = structure::valueMonoid::operation(res, prod(L, R, l\
    \ + childRange, r, right(v)));\n\t\t\treturn res;\n\t\t}\n\t}\n\npublic:\n\t//\
    \ @brief A = ( vId, vId, ... , vId ), |A| = N\u3068\u3059\u308B\n\t// @param N\
    \ |A|\n\tlazySegmentTree(std::size_t _N) : N(_N) {\n\t\tstd::size_t sz = 1;\n\t\
    \twhile (sz < N) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tpowTwo = sz;\n\t\tdat.resize((sz\
    \ << 1));\n\t}\n\n\t// @brief A\u3092\u5F15\u6570\u306E\u5217\u3067\u521D\u671F\
    \u5316\u3059\u308B\n\t// @param A \u6271\u3046\u5217\n\tlazySegmentTree(const\
    \ std::vector<V>& A) : N(A.size()) {\n\t\tstd::size_t sz = 1;\n\t\twhile (sz <\
    \ N) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tpowTwo = sz;\n\t\tdat.resize((sz << 1));\n\
    \t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + powTwo].value\
    \ = A[i];\n\t\t}\n\t\tfor (std::size_t i = powTwo - 1 ; i > 0 ; i--) {\n\t\t\t\
    dat[i].value = structure::valueMonoid::operation(dat[left(i)].value, dat[right(i)].value);\n\
    \t\t}\n\t}\t\n\t\n\t// @brief A_l .. A_{r - 1}\u306Bvalue\u3067\u5217\u3092\u66F4\
    \u65B0\u3059\u308B\n\t// @param L \u5DE6\n\t// @param R \u53F3\u3001\u534A\u958B\
    \u533A\u9593\u3067\u4E0E\u3048\u308B\u5FC5\u8981\u304C\u3042\u308B\n\t// @param\
    \ value \u66F4\u65B0\u3055\u305B\u308B\u5024\n\tvoid update(std::size_t L, std::size_t\
    \ R, const O& value) {\n\t\tassert(0 <= L and R <= N);\n\t\tassert(L < R);\n\t\
    \tupdate(L, R, 0, powTwo, 1, value);\n\t}\n\n\t// @brief A_l .. A_R \u306E\u7DCF\
    \u7A4D(\u7DCFvalueMonoid::operation)\u3092\u5F97\u308B\n\t// @param L \u5DE6\n\
    \t// @param R \u53F3\u3001\u534A\u958B\u533A\u9593\u3067\u4E0E\u3048\u308B\u5FC5\
    \u8981\u304C\u3042\u308B\n\t// @return \u8A08\u7B97\u7D50\u679C\n\tV prod(std::size_t\
    \ L, std::size_t R) {\n\t\tassert(0 <= L and R <= N);\n\t\tif (L == R) {\n\t\t\
    \treturn vId;\n\t\t}\n\t\treturn prod(L, R, 0, powTwo, 1);\n\t}\n\n\t// @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u3001dat\u3092\u8FD4\u3059\n\t// @return dat\n\
    \tinline std::vector<node> _dat() const {\n\t\treturn dat;\n\t}\n};\n\n} // namespace\
    \ zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/lazySegmentTree.hpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/lazySegmentTree-AOJ-RAQRmQ.test.cpp
  - test/lazySegmentTree-AOJ-RUQRmQ.test.cpp
  - test/lazySegmentTree-AOJ-RUQRSQ.test.cpp
  - test/ALPC-L.test.cpp
  - test/lazySegmentTree-AOJ-RAQRSQ.test.cpp
documentation_of: src/dataStructure/lazySegmentTree.hpp
layout: document
title: "lazySegmentTree (\u533A\u9593\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
  \u6728)"
---

## 概要

セグメント木を用いて列上のクエリを処理します。

#### セグメント木について

2冪の区間についての総積を常に保持して置くことで更新に $\log$ かけるかわりに区間総積取得も $\log$ で可能にする
- 詳しくはTODO？

#### クエリについて

**言葉の定義**

- $N$ : 正整数

- $A$ : 長さ $N$ の列、 $A$ 上でクエリを処理する

- $V$ : $A$ の各要素 $A_i (0\ \le\ i\ <\ n)$ が属する集合

- $\oplus$ : $V$ 上の演算

- $\text{id}_V$ : $V$ の要素、 $\oplus$ の単位元

- $O$ : ある集合

- $f_x\ :\ V\ \rightarrow\ V$ : $x\ \in\ O$ で定義される写像

- $\times$ : $O$ 上で定義される演算

- $\text{id}_O$ : $O$ の要素、 $\times$ の単位元

**要件**

- $(V, \oplus, \text{id}_V)$ は[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) を成す

- $(O, \times, \text{id}_O)$ はモノイドを成す

- $f_{\text{id}_O} (v)\ =\ v$ $(v\ \in\ V)$

- $f_x(v_1\oplus v_2)\ =\ f_x(v_1)\ \oplus\ f_x(v_2)$ を満たす(自己準同型)

- $f_{x_1}(f_{x_2}(v))\ =\ f_{x_1\times x_2} (v)$ を満たす

**処理できるクエリ**

- `update l r x` : $l\ \le\ i\ <\ r$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_x(A_i)$

- `prod l r`: $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を求める

##  機能

計算量の表記について、 $\oplus$ や $\times$ が定数時間で計算できることを仮定しています。 (例えば $\oplus$ や $\times$ が $O(\text{hoge})$ なら計算量が $\text{hoge}$ 倍されます)

以下の略称を使います
```
structure::value_monoid -> VM
structure::value_monoid::value_type -> Vtype
structure::operator_monoid -> OM
structure::operator_monoid::value_type -> Otype
```

#### コンストラクタ

```
(1) lazySegmentTree<structure>(std::size_t _N)
(2) lazySegmentTree<structure>(const std::vector<Vtype>& A)
```

(1) $A$ を長さ $N$ の各要素が`VM::identity`である列で初期化します

**制約**: $0\ <\ N$

**計算量** : $O(N)$

(2) $A$ を引数の列`A`で初期化します。

**制約**: `A.empty()`が`false`

**計算量** : $O(N)$

<br />

#### テンプレート引数structureについて

以下の要件を満たす構造体を入れてください
- `using valueMonoid`: $(V, \oplus, \text{id}_V)$ を表現した構造体(後述)
- `using operatorMonoid`:  $(O, \times, \text{id}_O)$ を表現した構造体(後述)
- `static VM mapping(const VM& a, const OM& b)`: $f_b (a)$ を返す関数

`valueMonoid`や`operatorMonoid`を表現する構造体として以下の機能を要求します。
- `using vale_type`: $V$ や $O$ の型
- `static constexpr valueType identity`: $\text{id}_V$ や $\text{id}_O$
- `static valueType operation(const valueType& a, const valueType& b)`: $a \oplus b$ や $a \times b$ を返す関数

実装例はテスト等を確認ください

<br />

#### メンバ

**update**
```
void update(std::size_t L, std::size_t R, const Otype& value)
```

$L\ \le\ i\ <\ R$ を満たす整数 $i$ について $A_i\ \leftarrow\ f_{\text{value}}(A_i)$ とする

**制約** : $0\ \le\ L\ <\ R\ \le\ N$

**計算量** : $O(\log N)$

<br />

**prod**
```
Vtype prod(std::size_t L, std:;size_t R)
```

$\displaystyle \bigoplus_{i = L}^{R - 1} A_i$ を求める

**制約**: 

$0\ \le\ L\ <\ N$

$L\ \le\ R\ \le\ N$

**計算量**: $O(\log N)$

<br />

**maxRight**

TODO

<br />

**minLeft**

TODO

<br />

## 参考

[SegmentTreeに載る代数的構造について](https://qiita.com/keymoon/items/0f929a19ed30f34ae6e8)

[遅延評価セグメント木をソラで書きたいあなたに](https://tsutaj.hatenablog.com/entry/2017/03/30/224339)

[AC Library](https://atcoder.github.io/ac-library/document_ja/lazysegtree.html)
