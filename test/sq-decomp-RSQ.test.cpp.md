---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sq-decomp.hpp
    title: "sq-decomp (\u5E73\u65B9\u5206\u5272\u306B\u3088\u308B\u533A\u9593\u30AF\
      \u30A8\u30EA)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/add.hpp
    title: "\u52A0\u6CD5\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/sq-decomp-RSQ.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#line 2 \"src/dataStructure/sq-decomp.hpp\"\n\n#include <vector>\n#include\
    \ <cmath>\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class monoid>\n\
    class sq_decomp {\nprivate:\n\tusing T = typename monoid::T;\n\tint square;\n\t\
    std::vector<T> dat;\n\tstd::vector<T> bucket;\n\n\tvoid update(int id) {\n\t\t\
    T val = monoid::id;\n\t\tint l = id * square;\n\t\tfor (int i = 0 ; i < square\
    \ and l + i < (int)dat.size()  ; i++) {\n\t\t\tval = monoid::op(dat[l + i], val);\n\
    \t\t}\n\t\tbucket[id] = val;\n\t}\n\npublic:\n\tsq_decomp(const std::vector<T>&\
    \ as) : square(std::sqrt(as.size() + 1)), dat(as), bucket(((int)as.size() + square\
    \ - 1) / square, monoid::id)  {\n\t\tfor (int i = 0 ; i < (int)dat.size() ; i++)\
    \ {\n\t\t\tbucket[i / square] = monoid::op(dat[i], bucket[i / square]);\n\t\t\
    }\n\t}\n\tsq_decomp(int n) : square(std::sqrt(n + 1)), dat(n, monoid::id), bucket((n\
    \ + square - 1) / square, monoid::id) {}\n\n\tvoid update(int i, const T& x) {\n\
    \t\tdat[i] = x;\n\t\tupdate(i / square);\n\t}\n\n\tT action(int i, const T& x)\
    \ {\n\t\tdat[i] = monoid::op(dat[i], x);\n\t\tupdate(i / square);\n\t\treturn\
    \ dat[i];\n\t}\n\n\tT prod(int l, int r) {\n\t\tT res = monoid::id;\n\t\tfor (int\
    \ i = 0 ; i < (int)bucket.size() ; i++) {\n\t\t\tint p = i * square, q = (i +\
    \ 1) * square;\n\t\t\tif (q <= l or r <= p) {\n\t\t\t\tcontinue;\n\t\t\t}\n\t\t\
    \tif (l <= p and q <= r) {\n\t\t\t\tres = monoid::op(res, bucket[i]);\n\t\t\t\
    }\n\t\t\telse {\n\t\t\t\tfor (int j = std::max(p, l) ; j < std::min({ (int)dat.size(),\
    \ q, r }) ; j++) {\n\t\t\t\t\tres = monoid::op(res, dat[j]);\n\t\t\t\t}\n\t\t\t\
    }\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<T> get_dat() {\n\t\treturn dat;\n\
    \t}\n\t\n\tstd::vector<T> get_bucket(std::size_t i) {\n\t\treturn bucket[i];\n\
    \t}\n\n};\n\n};\n#line 2 \"src/utility/monoid/add.hpp\"\n\nnamespace zawa {\n\n\
    template <class dat_type>\nstruct add_monoid {\n\tusing T = dat_type;\n\tstatic\
    \ constexpr T id = 0;\n\tstatic T op(const T& a, const T& b) {\n\t\treturn a +\
    \ b;\n\t}\n};\n\n};\n#line 5 \"test/sq-decomp-RSQ.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::sq_decomp<zawa::add_monoid<int>>\
    \ sq(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint com, x, y; std::cin >> com\
    \ >> x >> y;\n\t\tif (com == 0) {\n\t\t\tsq.action(x - 1, y);\n\t\t}\n\t\tif (com\
    \ == 1) {\n\t\t\tstd::cout << sq.prod(x - 1, y) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../src/dataStructure/sq-decomp.hpp\"\n#include \"../src/utility/monoid/add.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::sq_decomp<zawa::add_monoid<int>>\
    \ sq(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint com, x, y; std::cin >> com\
    \ >> x >> y;\n\t\tif (com == 0) {\n\t\t\tsq.action(x - 1, y);\n\t\t}\n\t\tif (com\
    \ == 1) {\n\t\t\tstd::cout << sq.prod(x - 1, y) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/dataStructure/sq-decomp.hpp
  - src/utility/monoid/add.hpp
  isVerificationFile: true
  path: test/sq-decomp-RSQ.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 02:42:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sq-decomp-RSQ.test.cpp
layout: document
redirect_from:
- /verify/test/sq-decomp-RSQ.test.cpp
- /verify/test/sq-decomp-RSQ.test.cpp.html
title: test/sq-decomp-RSQ.test.cpp
---
