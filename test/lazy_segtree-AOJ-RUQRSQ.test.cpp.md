---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/lazy_segtree.hpp
    title: "lazy_segtree (\u533A\u9593\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/range_add_monoid.hpp
    title: "range_add_monoid (\u533A\u9593\u548C\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "#line 1 \"test/lazy_segtree-AOJ-RUQRSQ.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\n\n#line\
    \ 2 \"src/utility/monoid/range_add_monoid.hpp\"\n\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\ntemplate <class T>\nstruct dat {\n\tT value;\n\tstd::size_t size;\n\
    \tconstexpr dat(const T& value = 0, const std::size_t& size = 0ULL) : value(value),\
    \ size(size) {}\n};\n\ntemplate <class T>\nstruct range_add_monoid {\n\tusing\
    \ value_type = dat<T>;\n\tstatic constexpr value_type identity{};\n\tstatic value_type\
    \ operation(const value_type& a, const value_type& b) {\n\t\treturn value_type(a.value\
    \ + b.value, a.size + b.size);\n\t}\n};\n\n} // namespace zawa\n#line 4 \"test/lazy_segtree-AOJ-RUQRSQ.test.cpp\"\
    \n\nstruct o_m {\n\tusing value_type = long long;\n\tstatic constexpr value_type\
    \ identity = -1001;\n\tstatic value_type operation(const value_type& a, const\
    \ value_type& b) {\n\t\treturn b;\n\t}\n};\n\nstruct action {\n\tusing value_monoid\
    \ = zawa::range_add_monoid<long long>;\n\tusing operator_monoid = o_m;\n\tstatic\
    \ value_monoid::value_type mapping(const value_monoid::value_type& a, const operator_monoid::value_type&\
    \ b) {\n\t\treturn value_monoid::value_type(a.size * b, a.size);\n\t}\n};\n\n\
    #line 2 \"src/dataStructure/lazy_segtree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass lazy_segtree\
    \ {\n\t// value_monoid prod\u306E\u6642\u306E\u6F14\u7B97\n\tusing V = typename\
    \ structure::value_monoid::value_type;\n\t// operator_monoid update\u306E\u6642\
    \u306E\u6F14\u7B97\n\tusing O = typename structure::operator_monoid::value_type;\n\
    private:\n\t// prod\u306E\u5358\u4F4D\u5143\n\tstatic constexpr V v_id = structure::value_monoid::identity;\n\
    \t// update\u306E\u5358\u4F4D\u5143\n\tstatic constexpr O o_id = structure::operator_monoid::identity;\n\
    \n\tstruct node {\n\t\tV value;\n\t\tO lazy;\n\t\tnode() : value(v_id), lazy(o_id)\
    \ {}\n\t};\n\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u5DE6\u5B50\u306E\u6DFB\u5B57\
    \u3092\u8FD4\u3059\n\tinline std::size_t left(std::size_t v) const {\n\t\treturn\
    \ v << 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u53F3\u5B50\u306E\u6DFB\u5B57\
    \u3092\u8FD4\u3059\n\tinline std::size_t right(std::size_t v) const {\n\t\treturn\
    \ v << 1 | 1;\n\t}\n\t// @brief \u30CE\u30FC\u30C9v\u306E\u89AA\u306E\u6DFB\u5B57\
    \u3092\u8FD4\u3059\u3002\n\tinline std::size_t parent(std::size_t v) const {\n\
    \t\treturn (v >> 1);\n\t}\n\n\tstd::size_t N;\n\tstd::size_t pow_two;\n\tstd::vector<node>\
    \ dat;\n\n\t// @brief \u9045\u5EF6\u3057\u305F\u5024\u3092\u5B50\u306B\u4F1D\u64AD\
    \u3059\u308B\n\tvoid propagate(std::size_t v) {\n\t\tif (dat[v].lazy == o_id)\
    \ {\n\t\t\treturn;\n\t\t}\n\t\tdat[v].value = structure::mapping(dat[v].value,\
    \ dat[v].lazy);\n\t\tif (right(v) < dat.size()) {\n\t\t\tdat[left(v)].lazy = structure::operator_monoid::operation(dat[left(v)].lazy,\
    \ dat[v].lazy);\n\t\t\tdat[right(v)].lazy = structure::operator_monoid::operation(dat[right(v)].lazy,\
    \ dat[v].lazy);\n\t\t}\n\t\tdat[v].lazy = o_id;\n\t}\n\n\t// @brief \u5185\u90E8\
    \u66F4\u65B0\u7528\n\t// LR\u304C\u30AF\u30A8\u30EA\u306E\u7BC4\u56F2\u3001lr\u304C\
    v\u306E\u6301\u3064\u7BC4\u56F2\n\tvoid update(std::size_t L, std::size_t R, std::size_t\
    \ l, std::size_t r, std::size_t v, const O& value) {\n\t\t// \u5148\u5EF6\u3070\
    \u3057\u3057\u3066\u3044\u305F\u3082\u306E\u3092\u8A55\u4FA1\u3059\u308B\n\t\t\
    propagate(v);\n\n\t\t// \u307E\u3063\u305F\u304F\u304B\u3076\u3063\u3066\u306A\
    \u3044\u6642\u3001\u7279\u306B\u4F55\u3082\u3057\u306A\u3044\n\t\tif (R <= l or\
    \ r <= L) {\n\t\t\treturn;\n\t\t}\n\n\t\t// lr\u304CLR\u306B\u307E\u305F\u304C\
    \u3063\u3066\u3044\u308B\u6642\u3001\u5148\u5EF6\u3070\u3057\u306B\u3059\u308B\
    \n\t\tif (L <= l and r <= R) {\n\t\t\tdat[v].lazy = structure::operator_monoid::operation(dat[v].lazy,\
    \ value);\n\t\t\tpropagate(v);\n\t\t}\n\t\t// \u5B50\u3092\u8A08\u7B97\u3059\u308B\
    \u5834\u5408\n\t\telse {\n\t\t\tassert(right(v) < dat.size());\n\t\t\tstd::size_t\
    \ child_range = (r - l) >> 1;\n\t\t\tupdate(L, R, l, l + child_range, left(v),\
    \ value);\n\t\t\tupdate(L, R, l + child_range, r, right(v), value);\n\t\t\tdat[v].value\
    \ = structure::value_monoid::operation(dat[left(v)].value, dat[right(v)].value);\n\
    \t\t}\n\t}\n\n\t// @brief \u5185\u90E8\u8A08\u7B97\u7528\n\t// LR\u304C\u30AF\u30A8\
    \u30EA\u306E\u7BC4\u56F2\u3001lr\u304Cv\u306E\u6301\u3064\u7BC4\u56F2\n\tV prod(std::size_t\
    \ L, std::size_t R, std::size_t l, std::size_t r, std::size_t v) {\n\n\t\t// \u533A\
    \u9593\u304C\u88AB\u3063\u3066\u306A\u3044\u6642\u3001\u5358\u4F4D\u5143\u3092\
    \u8FD4\u3059\n\t\tif (R <= l or r <= L) {\n\t\t\treturn v_id;\n\t\t}\n\n\n\t\t\
    // \u5148\u5EF6\u3070\u3057\u304C\u8A31\u3055\u308C\u306A\u304F\u306A\u3063\u305F\
    \u306E\u3067\u9045\u5EF6\u8A55\u4FA1\u3059\u308B\n\t\tpropagate(v);\n\n\t\t//\
    \ lr\u304CLR\u306B\u3059\u3063\u307D\u308A\u304A\u3055\u307E\u3063\u3066\u3044\
    \u308B\u6642\u3001\u305D\u306E\u30CE\u30FC\u30C9\u306E\u5024\u3092\u639B\u3051\
    \u5408\u308F\u305B\u308B\n\t\tif (L <= l and r <= R) {\n\t\t\treturn dat[v].value;\n\
    \t\t}\n\t\t// \u5B50\u3092\u8FBF\u308B\n\t\telse {\n\t\t\tV res = v_id;\n\t\t\t\
    std::size_t child_range = (r - l) >> 1;\n\t\t\tassert(right(v) < dat.size());\n\
    \t\t\tres = structure::value_monoid::operation(res, prod(L, R, l, l + child_range,\
    \ left(v)));\n\t\t\tres = structure::value_monoid::operation(res, prod(L, R, l\
    \ + child_range, r, right(v)));\n\t\t\treturn res;\n\t\t}\n\t}\n\npublic:\n\t\
    // @brief A = ( v_id, v_id, ... , v_id ), |A| = N\u3068\u3059\u308B\n\t// @param\
    \ N |A|\n\tlazy_segtree(std::size_t _N) : N(_N) {\n\t\tstd::size_t sz = 1;\n\t\
    \twhile (sz < N) {\n\t\t\tsz <<= 1;\n\t\t}\n\t\tpow_two = sz;\n\t\tdat.resize((sz\
    \ << 1));\n\t}\n\n\t// @brief A\u3092\u5F15\u6570\u306E\u5217\u3067\u521D\u671F\
    \u5316\u3059\u308B\n\t// @param A \u6271\u3046\u5217\n\tlazy_segtree(const std::vector<V>&\
    \ A) : N(A.size()) {\n\t\tstd::size_t sz = 1;\n\t\twhile (sz < N) {\n\t\t\tsz\
    \ <<= 1;\n\t\t}\n\t\tpow_two = sz;\n\t\tdat.resize((sz << 1));\n\t\tfor (std::size_t\
    \ i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + pow_two].value = A[i];\n\t\t}\n\
    \t\tfor (std::size_t i = pow_two - 1 ; i > 0 ; i--) {\n\t\t\tdat[i].value = structure::value_monoid::operation(dat[left(i)].value,\
    \ dat[right(i)].value);\n\t\t}\n\t}\t\n\t\n\t// @brief A_l .. A_{r - 1}\u306B\
    value\u3067\u5217\u3092\u66F4\u65B0\u3059\u308B\n\t// @param L \u5DE6\n\t// @param\
    \ R \u53F3\u3001\u534A\u958B\u533A\u9593\u3067\u4E0E\u3048\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n\t// @param value \u66F4\u65B0\u3055\u305B\u308B\u5024\n\tvoid update(std::size_t\
    \ L, std::size_t R, const O& value) {\n\t\tassert(0 <= L and R <= N);\n\t\tassert(L\
    \ < R);\n\t\tupdate(L, R, 0, pow_two, 1, value);\n\t}\n\n\t// @brief A_l .. A_R\
    \ \u306E\u7DCF\u7A4D(\u7DCFvalue_monoid::operation)\u3092\u5F97\u308B\n\t// @param\
    \ L \u5DE6\n\t// @param R \u53F3\u3001\u534A\u958B\u533A\u9593\u3067\u4E0E\u3048\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n\t// @return \u8A08\u7B97\u7D50\u679C\n\t\
    V prod(std::size_t L, std::size_t R) {\n\t\tassert(0 <= L and R <= N);\n\t\tif\
    \ (L == R) {\n\t\t\treturn v_id;\n\t\t}\n\t\treturn prod(L, R, 0, pow_two, 1);\n\
    \t}\n\n\t// @brief \u30C7\u30D0\u30C3\u30B0\u7528\u3001dat\u3092\u8FD4\u3059\n\
    \t// @return dat\n\tinline std::vector<node> _dat() const {\n\t\treturn dat;\n\
    \t}\n};\n\n} // namespace zawa\n#line 22 \"test/lazy_segtree-AOJ-RUQRSQ.test.cpp\"\
    \n\n#include <iostream>\n#line 25 \"test/lazy_segtree-AOJ-RUQRSQ.test.cpp\"\n\n\
    int main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::lazy_segtree<action> S(std::vector(n,\
    \ action::value_monoid::value_type(0LL, 1ULL)));\n\tfor (int _ = 0 ; _ < q ; _++)\
    \ {\n\t\tint type; std::cin >> type;\n\t\tif (type == 0) {\n\t\t\tint s, t, x;\
    \ std::cin >> s >> t >> x;\n\t\t\tS.update(s, t + 1, x);\n\t\t}\n\t\tif (type\
    \ == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\t\t\tstd::cout << S.prod(s, t\
    \ + 1).value << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n#include \"../src/utility/monoid/range_add_monoid.hpp\"\n\nstruct o_m {\n\t\
    using value_type = long long;\n\tstatic constexpr value_type identity = -1001;\n\
    \tstatic value_type operation(const value_type& a, const value_type& b) {\n\t\t\
    return b;\n\t}\n};\n\nstruct action {\n\tusing value_monoid = zawa::range_add_monoid<long\
    \ long>;\n\tusing operator_monoid = o_m;\n\tstatic value_monoid::value_type mapping(const\
    \ value_monoid::value_type& a, const operator_monoid::value_type& b) {\n\t\treturn\
    \ value_monoid::value_type(a.size * b, a.size);\n\t}\n};\n\n#include \"../src/dataStructure/lazy_segtree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n\tint n, q; std::cin\
    \ >> n >> q;\n\tzawa::lazy_segtree<action> S(std::vector(n, action::value_monoid::value_type(0LL,\
    \ 1ULL)));\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint type; std::cin >> type;\n\
    \t\tif (type == 0) {\n\t\t\tint s, t, x; std::cin >> s >> t >> x;\n\t\t\tS.update(s,\
    \ t + 1, x);\n\t\t}\n\t\tif (type == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\
    \t\t\tstd::cout << S.prod(s, t + 1).value << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/range_add_monoid.hpp
  - src/dataStructure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/lazy_segtree-AOJ-RUQRSQ.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 09:34:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy_segtree-AOJ-RUQRSQ.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_segtree-AOJ-RUQRSQ.test.cpp
- /verify/test/lazy_segtree-AOJ-RUQRSQ.test.cpp.html
title: test/lazy_segtree-AOJ-RUQRSQ.test.cpp
---
