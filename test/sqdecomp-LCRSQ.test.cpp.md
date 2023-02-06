---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sqdecomp.hpp
    title: "sqdecomp (\u5E73\u65B9\u5206\u5272\u306B\u3088\u308B\u533A\u9593\u30AF\
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/sqdecomp-LCRSQ.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 2 \"src/utility/monoid/add.hpp\"\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct add_monoid {\n\tusing value_type = T;\n\tstatic constexpr T identity{};\n\
    \tstatic T operation(const T& a, const T& b) {\n\t\treturn a + b;\n\t}\n};\n\n\
    } // namespace zawa\n#line 2 \"src/dataStructure/sqdecomp.hpp\"\n\n#include <vector>\n\
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
    \ bucket[i];\n\t}\n\n};\n\n} // namespace zawa\n#line 5 \"test/sqdecomp-LCRSQ.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tstd::cin.tie(nullptr);\n\tstd::ios::sync_with_stdio(false);\n\
    \tint N, Q; std::cin >> N >> Q;\n\tstd::vector<long long> A(N);\n\tfor (auto&\
    \ a : A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sqdecomp<zawa::add_monoid<long long>>\
    \ sq(A);\n\tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint t; std::cin >> t;\n\t\tif\
    \ (t == 0) {\n\t\t\tint p, x; std::cin >> p >> x;\n\t\t\tsq.action(p, x);\n\t\t\
    }\n\t\tif (t == 1) {\n\t\t\tint l, r; std::cin >> l >> r;\n\t\t\tstd::cout <<\
    \ sq.prod(l, r) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../src/utility/monoid/add.hpp\"\n#include \"../src/dataStructure/sqdecomp.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tstd::cin.tie(nullptr);\n\tstd::ios::sync_with_stdio(false);\n\
    \tint N, Q; std::cin >> N >> Q;\n\tstd::vector<long long> A(N);\n\tfor (auto&\
    \ a : A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sqdecomp<zawa::add_monoid<long long>>\
    \ sq(A);\n\tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint t; std::cin >> t;\n\t\tif\
    \ (t == 0) {\n\t\t\tint p, x; std::cin >> p >> x;\n\t\t\tsq.action(p, x);\n\t\t\
    }\n\t\tif (t == 1) {\n\t\t\tint l, r; std::cin >> l >> r;\n\t\t\tstd::cout <<\
    \ sq.prod(l, r) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/add.hpp
  - src/dataStructure/sqdecomp.hpp
  isVerificationFile: true
  path: test/sqdecomp-LCRSQ.test.cpp
  requiredBy: []
  timestamp: '2023-02-06 18:33:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sqdecomp-LCRSQ.test.cpp
layout: document
redirect_from:
- /verify/test/sqdecomp-LCRSQ.test.cpp
- /verify/test/sqdecomp-LCRSQ.test.cpp.html
title: test/sqdecomp-LCRSQ.test.cpp
---
