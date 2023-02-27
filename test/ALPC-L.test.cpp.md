---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/lazy_segtree.hpp
    title: "lazy_segtree (\u533A\u9593\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
      \u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/practice2/submissions/39280259
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ALPC-L.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n// struct v_data {\n// \tlong long zero, one, inv;\n// \tconstexpr v_data(long\
    \ long _zero = 0LL, long long _one = 0LL, long long _inv = 0LL) : zero(_zero),\
    \ one(_one), inv(_inv) {}\n// };\n// \n// struct v_m {\n// \tusing value_type\
    \ = v_data;\n// \tstatic constexpr value_type identity{};\n// \tstatic value_type\
    \ operation(const value_type& a, const value_type& b) {\n// \t\treturn value_type{\n\
    // \t\t\ta.zero + b.zero, \n// \t\t\ta.one + b.one,\n// \t\t\ta.inv + b.inv +\
    \ a.one * b.zero\n// \t\t};\n// \t}\n// };\n// \n// struct o_m {\n// \tusing value_type\
    \ = bool;\n// \tstatic constexpr value_type identity{};\n// \tstatic value_type\
    \ operation(const value_type& a, const value_type& b) {\n// \t\treturn (a and\
    \ !b) or (!a and b);\n// \t}\n// };\n// \n// struct action {\n// \tusing value_monoid\
    \ = v_m;\n// \tusing operator_monoid = o_m;\n// \tstatic v_data mapping(const\
    \ v_data& a, const bool& b) {\n// \t\tif (!b) {\n// \t\t\treturn a;\n// \t\t}\n\
    // \t\telse {\n// \t\t\treturn v_data{\n// \t\t\t\ta.one,\n// \t\t\t\ta.zero,\n\
    // \t\t\t\ta.one * a.zero - a.inv\n// \t\t\t};\n// \t\t}\n// \t}\n// };\n\n\n\
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
    \t}\n};\n\n} // namespace zawa\n#line 47 \"test/ALPC-L.test.cpp\"\n\n#include\
    \ <iostream>\n#line 50 \"test/ALPC-L.test.cpp\"\n\nint main() {\n\t// std::cin.tie(nullptr);\n\
    \t// std::ios::sync_with_stdio;\n\t// int n, q; std::cin >> n >> q;\n\t// std::vector<v_data>\
    \ A(n);\n\t// for (int i = 0 ; i < n ; i++) {\n\t// \tint x; std::cin >> x;\n\t\
    // \tif (x == 0) {\n\t// \t\tA[i] = v_data{ 1, 0, 0 };\n\t// \t}\n\t// \telse\
    \ {\n\t// \t\tA[i] = v_data{ 0, 1, 0 };\n\t// \t}\n\t// }\n\t// zawa::lazy_segtree<action>\
    \ S(A);\n\t// for (int _ = 0 ; _ < q ; _++) {\n\t// \tint t, l, r; std::cin >>\
    \ t >> l >> r;\n\t// \tl--;\n\t// \tif (t == 1) {\n\t// \t\tS.update(l, r, true);\n\
    \t// \t}\n\t// \telse {\n\t// \t\tstd::cout << S.prod(l, r).inv << std::endl;\n\
    \t// \t}\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Library Practice Contest -L Lazy Segment Tree\n * https://atcoder.jp/contests/practice2/submissions/39280259\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n// struct v_data {\n// \tlong long zero, one, inv;\n// \tconstexpr v_data(long\
    \ long _zero = 0LL, long long _one = 0LL, long long _inv = 0LL) : zero(_zero),\
    \ one(_one), inv(_inv) {}\n// };\n// \n// struct v_m {\n// \tusing value_type\
    \ = v_data;\n// \tstatic constexpr value_type identity{};\n// \tstatic value_type\
    \ operation(const value_type& a, const value_type& b) {\n// \t\treturn value_type{\n\
    // \t\t\ta.zero + b.zero, \n// \t\t\ta.one + b.one,\n// \t\t\ta.inv + b.inv +\
    \ a.one * b.zero\n// \t\t};\n// \t}\n// };\n// \n// struct o_m {\n// \tusing value_type\
    \ = bool;\n// \tstatic constexpr value_type identity{};\n// \tstatic value_type\
    \ operation(const value_type& a, const value_type& b) {\n// \t\treturn (a and\
    \ !b) or (!a and b);\n// \t}\n// };\n// \n// struct action {\n// \tusing value_monoid\
    \ = v_m;\n// \tusing operator_monoid = o_m;\n// \tstatic v_data mapping(const\
    \ v_data& a, const bool& b) {\n// \t\tif (!b) {\n// \t\t\treturn a;\n// \t\t}\n\
    // \t\telse {\n// \t\t\treturn v_data{\n// \t\t\t\ta.one,\n// \t\t\t\ta.zero,\n\
    // \t\t\t\ta.one * a.zero - a.inv\n// \t\t\t};\n// \t\t}\n// \t}\n// };\n\n\n\
    #include \"../src/dataStructure/lazy_segtree.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\t// std::cin.tie(nullptr);\n\t// std::ios::sync_with_stdio;\n\
    \t// int n, q; std::cin >> n >> q;\n\t// std::vector<v_data> A(n);\n\t// for (int\
    \ i = 0 ; i < n ; i++) {\n\t// \tint x; std::cin >> x;\n\t// \tif (x == 0) {\n\
    \t// \t\tA[i] = v_data{ 1, 0, 0 };\n\t// \t}\n\t// \telse {\n\t// \t\tA[i] = v_data{\
    \ 0, 1, 0 };\n\t// \t}\n\t// }\n\t// zawa::lazy_segtree<action> S(A);\n\t// for\
    \ (int _ = 0 ; _ < q ; _++) {\n\t// \tint t, l, r; std::cin >> t >> l >> r;\n\t\
    // \tl--;\n\t// \tif (t == 1) {\n\t// \t\tS.update(l, r, true);\n\t// \t}\n\t\
    // \telse {\n\t// \t\tstd::cout << S.prod(l, r).inv << std::endl;\n\t// \t}\n\t\
    // }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Library\
    \ Practice Contest -L Lazy Segment Tree\n * https://atcoder.jp/contests/practice2/submissions/39280259\n\
    \ */\n"
  dependsOn:
  - src/dataStructure/lazy_segtree.hpp
  isVerificationFile: true
  path: test/ALPC-L.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 09:34:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALPC-L.test.cpp
layout: document
redirect_from:
- /verify/test/ALPC-L.test.cpp
- /verify/test/ALPC-L.test.cpp.html
title: test/ALPC-L.test.cpp
---
