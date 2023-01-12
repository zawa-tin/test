---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sparse-table.hpp
    title: "sparse-table ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\
      \u89E3\u7B54 )"
  - icon: ':heavy_check_mark:'
    path: src/utility/sparse-table/min.hpp
    title: sparsetable min-structure
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/sparse-table.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
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
    \n} // namespace zawa\n#line 2 \"src/utility/sparse-table/min.hpp\"\n\n#include\
    \ <algorithm>\n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct min_structure\
    \ {\n\tusing T = dat_type;\n\tstatic T op(T a, T b) {\n\t\treturn std::min(a,\
    \ b);\n\t}\n};\n\n} // namespace zawa\n#line 5 \"test/sparse-table.test.cpp\"\n\
    \n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tstd::vector<int>\
    \ as(n, 0);\n\tfor (auto& a : as) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sparse_table<zawa::min_structure<int>>\
    \ spt(as);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint l, r; std::cin >> l >>\
    \ r;\n\t\tstd::cout << spt.query(l, r) << std::endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../src/dataStructure/sparse-table.hpp\"\n#include \"../src/utility/sparse-table/min.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tstd::vector<int>\
    \ as(n, 0);\n\tfor (auto& a : as) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sparse_table<zawa::min_structure<int>>\
    \ spt(as);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint l, r; std::cin >> l >>\
    \ r;\n\t\tstd::cout << spt.query(l, r) << std::endl;\n\t}\n}\n"
  dependsOn:
  - src/dataStructure/sparse-table.hpp
  - src/utility/sparse-table/min.hpp
  isVerificationFile: true
  path: test/sparse-table.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 14:36:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sparse-table.test.cpp
layout: document
redirect_from:
- /verify/test/sparse-table.test.cpp
- /verify/test/sparse-table.test.cpp.html
title: test/sparse-table.test.cpp
---
