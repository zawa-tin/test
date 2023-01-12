---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sparse-table.hpp
    title: "sparse-table ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\
      \u89E3\u7B54 )"
  - icon: ':heavy_check_mark:'
    path: src/utility/sparse-table/gcd.hpp
    title: sparsetable gcd-structure
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc125/submissions/37954413
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC125C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/sparse-table.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class structure>\nclass sparse_table {\nprivate:\n\tusing\
    \ T = typename structure::T;\n\tstd::vector<int> ls;\n\tstd::vector<std::vector<T>>\
    \ dat;\n\npublic:\n\n\tsparse_table(const std::vector<T>& as) : ls(as.size() +\
    \ 1, 0) {\n\t\tfor (int i = 1 ; i < (int)ls.size() ; i++) {\n\t\t\tls[i] = ls[i\
    \ - 1] + (i >> (ls[i - 1] + 1));\n\t\t}\n\t\tdat = std::vector(ls.back() + 1,\
    \ as);\n\t\tdat[0] = as;\n\t\tfor (int i = 1 ; i < (int)dat.size() ; i++) {\n\t\
    \t\tint pt = (1 << i);\n\t\t\tfor (int j = 0 ; j + pt - 1 < (int)dat[i].size()\
    \ ; j++) {\n\t\t\t\tdat[i][j] = structure::op(dat[i - 1][j], dat[i - 1][j + (pt\
    \ >> 1)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tT query(int l, int r) {\n\t\tint now = ls[r\
    \ - l];\n\t\treturn structure::op(dat[now][l], dat[now][r - (1 << now)]);\n\t\
    }\n\n\tconst std::vector<std::vector<T>>& get() {\n\t\treturn dat;\n\t}\n\n};\n\
    \n} // namespace zawa\n#line 1 \"src/utility/sparse-table/gcd.hpp\"\n#include\
    \ <numeric>\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct gcd_structure\
    \ {\n\tusing T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn std::gcd(a,\
    \ b);\n\t}\n};\n\n} // namespace zawa\n#line 5 \"test/ABC125C.test.cpp\"\n\n#line\
    \ 7 \"test/ABC125C.test.cpp\"\n#include <iostream>\n#include <algorithm>\n#line\
    \ 10 \"test/ABC125C.test.cpp\"\n\nint main() {\n\t// int n; std::cin >> n;\n\t\
    // std::vector as(n, 0);\n\t// for (auto& a : as) {\n\t// \tstd::cin >> a;\n\t\
    // }\n\t// zawa::sparse_table<zawa::gcd_structure<int>> spt(as);\n\t// int ans\
    \ = spt.query(0, n);\n\t// ans = std::max(ans, spt.query(1, n));\n\t// for (int\
    \ i = 0 ; i < n - 1 ; i++) {\n\t// \tans = std::max(ans, std::gcd(spt.query(0,\
    \ i), spt.query(i + 1, n)));\n\t// }\n\t// ans = std::max(ans, spt.query(0, n\
    \ - 1));\n\t// std::cout << ans << std::endl;\n\t\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 125 - C GCD on Blackboard\n\
    \ * https://atcoder.jp/contests/abc125/submissions/37954413\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/sparse-table.hpp\"\n#include \"../src/utility/sparse-table/gcd.hpp\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <numeric>\n\
    \nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector as(n, 0);\n\t// for\
    \ (auto& a : as) {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::sparse_table<zawa::gcd_structure<int>>\
    \ spt(as);\n\t// int ans = spt.query(0, n);\n\t// ans = std::max(ans, spt.query(1,\
    \ n));\n\t// for (int i = 0 ; i < n - 1 ; i++) {\n\t// \tans = std::max(ans, std::gcd(spt.query(0,\
    \ i), spt.query(i + 1, n)));\n\t// }\n\t// ans = std::max(ans, spt.query(0, n\
    \ - 1));\n\t// std::cout << ans << std::endl;\n\t\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 125 - C GCD on Blackboard\n\
    \ * https://atcoder.jp/contests/abc125/submissions/37954413\n */\n"
  dependsOn:
  - src/dataStructure/sparse-table.hpp
  - src/utility/sparse-table/gcd.hpp
  isVerificationFile: true
  path: test/ABC125C.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 13:45:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC125C.test.cpp
layout: document
redirect_from:
- /verify/test/ABC125C.test.cpp
- /verify/test/ABC125C.test.cpp.html
title: test/ABC125C.test.cpp
---
