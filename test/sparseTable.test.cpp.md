---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sparseTable.hpp
    title: "sparseTable ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\
      \u89E3\u7B54 )"
  - icon: ':heavy_check_mark:'
    path: src/utility/sparseTable/minStructure.hpp
    title: minStructure (Sparse Table)
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
  bundledCode: "#line 1 \"test/sparseTable.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"src/dataStructure/sparseTable.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass sparseTable\
    \ {\nprivate:\n\tusing T = typename structure::valueType;\n\tstd::vector<int>\
    \ L;\n\tstd::vector<std::vector<T>> dat;\n\npublic:\n\n\tsparseTable(const std::vector<T>&\
    \ A) : L(A.size() + 1, 0) {\n\t\tfor (int i = 1 ; i < (int)L.size() ; i++) {\n\
    \t\t\tL[i] = L[i - 1] + (i >> (L[i - 1] + 1));\n\t\t}\n\t\tdat = std::vector(L.back()\
    \ + 1, A);\n\t\tfor (int i = 1 ; i < (int)dat.size() ; i++) {\n\t\t\tint pt =\
    \ (1 << i);\n\t\t\tfor (int j = 0 ; j + pt - 1 < (int)dat[i].size() ; j++) {\n\
    \t\t\t\tdat[i][j] = structure::operation(dat[i - 1][j], dat[i - 1][j + (pt >>\
    \ 1)]);\n\t\t\t}\n\t\t}\n\t}\n\n\tT query(int l, int r) {\n\t\tassert(0 <= l and\
    \ l < (int)dat[0].size());\n\t\tassert(l <= r and r <= (int)dat[0].size());\n\t\
    \tint now = L[r - l];\n\t\treturn structure::operation(dat[now][l], dat[now][r\
    \ - (1 << now)]);\n\t}\n\n\tinline std::vector<std::vector<T>> _dat() const {\n\
    \t\treturn dat;\n\t}\n\n};\n\n} // namespace zawa\n#line 2 \"src/utility/sparseTable/minStructure.hpp\"\
    \n\n#include <algorithm>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct minStructure\
    \ {\n\tusing valueType = T;\n\tstatic valueType operation(const valueType& a,\
    \ const valueType& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 5 \"test/sparseTable.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n\tint N, Q; std::cin >> N >> Q;\n\tstd::vector<int> A(N, 0);\n\tfor (auto&\
    \ a : A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sparseTable<zawa::minStructure<int>>\
    \ S(A);\n\tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint l, r; std::cin >> l >> r;\n\
    \t\tstd::cout << S.query(l, r) << std::endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../src/dataStructure/sparseTable.hpp\"\n#include \"../src/utility/sparseTable/minStructure.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint N, Q; std::cin >> N >> Q;\n\tstd::vector<int>\
    \ A(N, 0);\n\tfor (auto& a : A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::sparseTable<zawa::minStructure<int>>\
    \ S(A);\n\tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint l, r; std::cin >> l >> r;\n\
    \t\tstd::cout << S.query(l, r) << std::endl;\n\t}\n}\n"
  dependsOn:
  - src/dataStructure/sparseTable.hpp
  - src/utility/sparseTable/minStructure.hpp
  isVerificationFile: true
  path: test/sparseTable.test.cpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sparseTable.test.cpp
layout: document
redirect_from:
- /verify/test/sparseTable.test.cpp
- /verify/test/sparseTable.test.cpp.html
title: test/sparseTable.test.cpp
---
