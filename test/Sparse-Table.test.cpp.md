---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/Sparse-Table.hpp
    title: "Sparse-Table ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\
      \u89E3\u7B54 )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/tessoku-book/submissions/35794247
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Sparse-Table.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/Sparse-Table.hpp\"\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, T (*op)(T, T)>\nclass Sparse_Table {\nprivate:\n\
    \    std::vector<std::vector<T>> table;\n\npublic:\n    Sparse_Table(std::vector<T>\
    \ as) \n        : table(std::__lg(as.size()) + 1, std::vector(as.size(), 0)) {\n\
    \            \n        for (std::size_t i = 0 ; i < as.size() ; i++) {\n     \
    \       table[0][i] = as[i];\n        }\n\n        for (std::size_t i = 1 ; i\
    \ < table.size() ; i++) {\n            std::size_t pt = (1 << i);\n          \
    \  for (std::size_t j = 0 ; j + pt - 1 < table[i].size() ; j++) {\n          \
    \      table[i][j] = op(table[i - 1][j], table[i - 1][j + (pt >> 1)]);\n     \
    \       }\n        }\n    }\n\n    T query(int l, int r) {\n        int lg = std::__lg(r\
    \ - l);\n        return op(table[lg][l], table[lg][r - (1 << lg)]);\n    }\n\n\
    \    std::vector<std::vector<T>> hoge() {\n        return table;\n    }\n\n};\n\
    \n} // namespace zawa\n#line 4 \"test/Sparse-Table.test.cpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n\n// namespace sp {\n//     int op(int a, int b) {\n// \
    \        return std::max(a, b);\n//     }\n// }\n\n// using SpT = zawa::Sparse_Table<int,\
    \ sp::op>;\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n \
    \   // int n; std::cin >> n;\n    // std::vector as(n, 0);\n    // for (auto&\
    \ a : as) {\n    //     std::cin >> a;\n    // }\n    // SpT spt(as);\n    //\
    \ int d; std::cin >> d;\n    // for (int _ = 0 ; _ < d ; _++) {\n    //     int\
    \ l, r; std::cin >> l >> r;\n    //     std::cout << std::max(spt.query(0, l -\
    \ 1), spt.query(r, n)) << std::endl;\n    // }\n}\n\n/*\n *\n * \n * https://atcoder.jp/contests/tessoku-book/submissions/35794247\n\
    \ *\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/Sparse-Table.hpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n\n// namespace sp {\n//     int op(int a, int b) {\n// \
    \        return std::max(a, b);\n//     }\n// }\n\n// using SpT = zawa::Sparse_Table<int,\
    \ sp::op>;\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n \
    \   // int n; std::cin >> n;\n    // std::vector as(n, 0);\n    // for (auto&\
    \ a : as) {\n    //     std::cin >> a;\n    // }\n    // SpT spt(as);\n    //\
    \ int d; std::cin >> d;\n    // for (int _ = 0 ; _ < d ; _++) {\n    //     int\
    \ l, r; std::cin >> l >> r;\n    //     std::cout << std::max(spt.query(0, l -\
    \ 1), spt.query(r, n)) << std::endl;\n    // }\n}\n\n/*\n *\n * \n * https://atcoder.jp/contests/tessoku-book/submissions/35794247\n\
    \ *\n */\n"
  dependsOn:
  - src/dataStructure/Sparse-Table.hpp
  isVerificationFile: true
  path: test/Sparse-Table.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 01:06:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Sparse-Table.test.cpp
layout: document
redirect_from:
- /verify/test/Sparse-Table.test.cpp
- /verify/test/Sparse-Table.test.cpp.html
title: test/Sparse-Table.test.cpp
---
