---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/lazySquareDecomp.hpp
    title: "lazySquareDecomp (\u533A\u9593\u66F4\u65B0\u53EF\u80FD\u5E73\u65B9\u5206\
      \u5272)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/minMonoid.hpp
    title: "minMonoid (\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F
  bundledCode: "#line 1 \"test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\n\n#line\
    \ 2 \"src/utility/monoid/minMonoid.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct minMonoid {\n\tusing valueType\
    \ = T;\n\tstatic constexpr valueType identity = std::numeric_limits<valueType>::max();\n\
    \tstatic valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ std::min(a, b);\n\t}\n};\n\n};\n#line 4 \"test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp\"\
    \n\nusing vM = zawa::minMonoid<int>;\n\nstruct oM {\n\tusing valueType = int;\n\
    \tstatic constexpr int identity = -1;\n\tstatic int operation(const int& a, const\
    \ int& b) {\n\t\treturn b;\n\t}\n};\n\nstruct action {\n\tusing valueMonoid =\
    \ vM;\n\tusing operatorMonoid = oM;\n\tstatic const int mapping(const int& a,\
    \ const int& b) {\n\t\treturn b;\n\t}\n};\n\n#line 2 \"src/dataStructure/lazySquareDecomp.hpp\"\
    \n\n#include <vector>\n#include <cmath>\n#line 6 \"src/dataStructure/lazySquareDecomp.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class structure>\nclass lazySquareDecomp {\n\
    \tusing V = typename structure::valueMonoid::valueType;\n\tusing O = typename\
    \ structure::operatorMonoid::valueType;\n\nprivate:\n\tstatic constexpr V vId\
    \ = structure::valueMonoid::identity;\n\tstatic constexpr O oId = structure::operatorMonoid::identity;\n\
    \tstruct node {\n\t\tV value;\n\t\tO lazy;\n\t\tnode() : value(vId), lazy(oId)\
    \ {}\n\t};\n\tint square;\n\tstd::vector<V> dat;\n\tstd::vector<node> bucket;\n\
    \n\tvoid propagate(int pos) {\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ;\
    \ i < square ; i++) {\n\t\t\tdat[l + i] = structure::mapping(dat[l + i], bucket[pos].lazy);\t\
    \n\t\t}\n\t\tbucket[pos].lazy = oId;\n\t}\n\n\tvoid update(int pos) {\n\t\tbucket[pos].value\
    \ = vId;\n\t\tint l = square * pos;\n\t\tfor (int i = 0 ; i < square and l + i\
    \ < (int)dat.size() ; i++) {\n\t\t\tbucket[pos].value = structure::valueMonoid::operation(bucket[pos].value,\
    \ dat[l + i]);\n\t\t}\n\t}\n\t\npublic:\n\tlazySquareDecomp(int n) : square(std::sqrt(n\
    \ + 1)), dat(n, vId), bucket((n + square - 1) / square) {\n\t\tfor (std::size_t\
    \ i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i / square].value = structure::valueMonoid::operation(bucket[i\
    \ / square].value, dat[i]);\n\t\t}\n\t}\n\tlazySquareDecomp(const std::vector<V>&\
    \ A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1)\
    \ / square) {\n\t\tfor (std::size_t i = 0 ; i < dat.size() ; i++) {\n\t\t\tbucket[i\
    \ / square].value = structure::valueMonoid::operation(bucket[i / square].value,\
    \ dat[i]);\n\t\t}\n\t}\n\n\tvoid update(int pos, const O& value) {\n\t\tif (bucket[pos\
    \ / square].lazy != oId) {\n\t\t\tpropagate(pos / square);\n\t\t}\n\t\tdat[pos]\
    \ = structure::mapping(dat[pos], value);\n\t\tupdate(pos / square);\n\t}\t\n\n\
    \tvoid update(int l, int r, const O& value) {\t\n\t\tfor (int i = 0 ; i < (int)bucket.size()\
    \ ; i++) {\n\t\t\tint p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p\
    \ or q <= l) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\
    \t\t\tbucket[i].lazy = structure::operatorMonoid::operation(bucket[i].lazy, value);\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy != oId) {\n\t\t\t\t\tpropagate(i);\n\
    \t\t\t\t}\n\t\t\t\tfor (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size()\
    \ }) ; j++) {\n\t\t\t\t\tdat[j] = structure::mapping(dat[j], value);\n\t\t\t\t\
    }\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n\t}\n\n\tV prod(int l, int r) {\n\t\tV\
    \ res = vId;\n\t\tfor (int i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint\
    \ p = i * square, q = (i + 1) * square;\n\t\t\tif (r <= p or q <= l) {\n\t\t\t\
    \tcontinue;\n\t\t\t}\n\t\t\tif (l <= p and q <= r) {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tres = structure::valueMonoid::operation(res, structure::mapping(bucket[i].value,\
    \ bucket[i].lazy));\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres = structure::valueMonoid::operation(res,\
    \ bucket[i].value);\n\t\t\t\t}\n\t\t\t}\n\t\t\telse {\n\t\t\t\tif (bucket[i].lazy\
    \ != oId) {\n\t\t\t\t\tpropagate(i);\n\t\t\t\t\tupdate(i);\n\t\t\t\t}\n\t\t\t\t\
    for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {\n\
    \t\t\t\t\tres = structure::valueMonoid::operation(res, dat[j]);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t}\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n#line 24 \"test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::lazySquareDecomp<action>\
    \ sq(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint type; std::cin >> type;\n\
    \t\tif (type == 0) {\n\t\t\tint s, t, x; std::cin >> s >> t >> x;\n\t\t\tsq.update(s,\
    \ t + 1, x);\n\t\t}\n\t\tif (type == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\
    \t\t\tstd::cout << sq.prod(s, t + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F\"\
    \n\n#include \"../src/utility/monoid/minMonoid.hpp\"\n\nusing vM = zawa::minMonoid<int>;\n\
    \nstruct oM {\n\tusing valueType = int;\n\tstatic constexpr int identity = -1;\n\
    \tstatic int operation(const int& a, const int& b) {\n\t\treturn b;\n\t}\n};\n\
    \nstruct action {\n\tusing valueMonoid = vM;\n\tusing operatorMonoid = oM;\n\t\
    static const int mapping(const int& a, const int& b) {\n\t\treturn b;\n\t}\n};\n\
    \n#include \"../src/dataStructure/lazySquareDecomp.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::lazySquareDecomp<action>\
    \ sq(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint type; std::cin >> type;\n\
    \t\tif (type == 0) {\n\t\t\tint s, t, x; std::cin >> s >> t >> x;\n\t\t\tsq.update(s,\
    \ t + 1, x);\n\t\t}\n\t\tif (type == 1) {\n\t\t\tint s, t; std::cin >> s >> t;\n\
    \t\t\tstd::cout << sq.prod(s, t + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/minMonoid.hpp
  - src/dataStructure/lazySquareDecomp.hpp
  isVerificationFile: true
  path: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 16:33:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
layout: document
redirect_from:
- /verify/test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
- /verify/test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp.html
title: test/lazySquareDecomp-AOJ-RUQRmQ.test.cpp
---
