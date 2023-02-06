---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/lazy_sqdecomp.hpp
    title: "lazy_sqdecomp (\u533A\u9593\u66F4\u65B0\u53EF\u80FD\u5E73\u65B9\u5206\u5272\
      )"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/add.hpp
    title: "\u52A0\u6CD5\u30E2\u30CE\u30A4\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/min.hpp
    title: "min\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\n\n#line\
    \ 2 \"src/utility/monoid/min.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct min_monoid {\n\tusing value_type\
    \ = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::max();\n\tstatic\
    \ T operation(const T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\
    \n};\n#line 2 \"src/utility/monoid/add.hpp\"\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct add_monoid {\n\tusing value_type = T;\n\tstatic constexpr T identity{};\n\
    \tstatic T operation(const T& a, const T& b) {\n\t\treturn a + b;\n\t}\n};\n\n\
    } // namespace zawa\n#line 5 \"test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp\"\n\nstruct\
    \ action {\n\tusing value_monoid = zawa::min_monoid<long long>;\n\tusing operator_monoid\
    \ = zawa::add_monoid<long long>;\n\tstatic value_monoid::value_type mapping(const\
    \ value_monoid::value_type& a, const operator_monoid::value_type& b) {\n\t\treturn\
    \ a + b;\n\t}\n};\n\n#line 2 \"src/dataStructure/lazy_sqdecomp.hpp\"\n\n#include\
    \ <vector>\n#include <cmath>\n#line 6 \"src/dataStructure/lazy_sqdecomp.hpp\"\n\
    \nnamespace zawa {\n\ntemplate <class structure>\nclass lazy_sqdecomp {\n\tusing\
    \ T = typename structure::value_monoid::value_type;\n\tusing S = typename structure::operator_monoid::value_type;\n\
    \nprivate:\n\tstatic constexpr T T_id = structure::value_monoid::identity;\n\t\
    static constexpr S S_id = structure::operator_monoid::identity;\n\tstruct node\
    \ {\n\t\tT value;\n\t\tS lazy;\n\t\tnode() : value(T_id), lazy(S_id) {}\n\t};\n\
    \tint square;\n\tstd::vector<T> dat;\n\tstd::vector<node> bucket;\n\n\tvoid propagate(int\
    \ pos) {\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ; i < square ; i++) {\n\
    \t\t\tdat[l + i] = structure::mapping(dat[l + i], bucket[pos].lazy);\t\n\t\t}\n\
    \t\tbucket[pos].lazy = S_id;\n\t}\n\n\tvoid update(int pos) {\n\t\tbucket[pos].value\
    \ = T_id;\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ; i < square and l +\
    \ i < (int)dat.size() ; i++) {\n\t\t\tbucket[pos].value = structure::value_monoid::operation(bucket[pos].value,\
    \ dat[l + i]);\n\t\t}\n\t}\n\t\npublic:\n\tlazy_sqdecomp(int n) : square(std::sqrt(n\
    \ + 1)), dat(n, T_id), bucket((n + square - 1) / square) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i / square].value = structure::value_monoid::operation(bucket[i\
    \ / square].value, dat[i]);\n\t\t}\n\t}\n\tlazy_sqdecomp(const std::vector<T>&\
    \ A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1)\
    \ / square) {\n\t\tfor (std::size_t i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i\
    \ / square].value = structure::value_monoid::operation(bucket[i / square].value,\
    \ dat[i]);\n\t\t}\n\t}\n\n\tvoid update(int pos, const S& value) {\n\t\tif (bucket[pos\
    \ / square].lazy != S_id) {\n\t\t\tpropagate(pos / square);\n\t\t}\n\t\tdat[pos]\
    \ = structure::mapping(dat[pos], value);\n\t\tupdate(pos / square);\n\t}\t\n\n\
    \tvoid update(int l, int r, const S& value) {\t\n\t\tfor (int i = 0 ; i < (int)bucket.size()\
    \ ; i++) {\n\t\t\tint p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p\
    \ or q <= l) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\
    \t\t\tbucket[i].lazy = structure::operator_monoid::operation(bucket[i].lazy, value);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy != S_id) {\n\t\t\t\t\tpropagate(i);\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size()\
    \ }) ; j++) {\n\t\t\t\t\tdat[j] = structure::mapping(dat[j], value);\n\t\t\t\t\
    }\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\t}\n\n\tT prod(int l, int r) {\n\t\tT\
    \ res = T_id;\n\t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint\
    \ p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p or q <= l) {\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tif (bucket[i].lazy\
    \ != S_id) {\n\t\t\t\t\tres = structure::value_monoid::operation(res, structure::mapping(bucket[i].value,\
    \ bucket[i].lazy));\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres = structure::value_monoid::operation(res,\
    \ bucket[i].value);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy\
    \ != S_id) {\n\t\t\t\t\tpropagate(i);\n\t\t\t\t\tupdate(i);\n\t\t\t\t}\n\t\t\t\
    \tfor (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++)\
    \ {\n\t\t\t\t\tres = structure::value_monoid::operation(res, dat[j]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n#line 15 \"\
    test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp\"\n\n#include <iostream>\n#line 18 \"test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp\"\
    \n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::lazy_sqdecomp<action>\
    \ sq(std::vector(n, (action::value_monoid::value_type)0));\n\tfor (int _ = 0 ;\
    \ _ < q ; _++) {\n\t\tint type; std::cin >> type;\n\t\tif (type == 0) {\n\t\t\t\
    int s, t, x; std::cin >> s >> t >> x;\n\t\t\tsq.update(s, t + 1, x);\n\t\t}\n\t\
    \tif (type == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\t\t\tstd::cout << sq.prod(s,\
    \ t + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#include \"../src/utility/monoid/min.hpp\"\n#include \"../src/utility/monoid/add.hpp\"\
    \n\nstruct action {\n\tusing value_monoid = zawa::min_monoid<long long>;\n\tusing\
    \ operator_monoid = zawa::add_monoid<long long>;\n\tstatic value_monoid::value_type\
    \ mapping(const value_monoid::value_type& a, const operator_monoid::value_type&\
    \ b) {\n\t\treturn a + b;\n\t}\n};\n\n#include \"../src/dataStructure/lazy_sqdecomp.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n\tint n, q; std::cin\
    \ >> n >> q;\n\tzawa::lazy_sqdecomp<action> sq(std::vector(n, (action::value_monoid::value_type)0));\n\
    \tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint type; std::cin >> type;\n\t\tif (type\
    \ == 0) {\n\t\t\tint s, t, x; std::cin >> s >> t >> x;\n\t\t\tsq.update(s, t +\
    \ 1, x);\n\t\t}\n\t\tif (type == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\t\
    \t\tstd::cout << sq.prod(s, t + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/min.hpp
  - src/utility/monoid/add.hpp
  - src/dataStructure/lazy_sqdecomp.hpp
  isVerificationFile: true
  path: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 23:27:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
layout: document
redirect_from:
- /verify/test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
- /verify/test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp.html
title: test/lazy_sqdecomp-AOJ-RAQRmQ.test.cpp
---
