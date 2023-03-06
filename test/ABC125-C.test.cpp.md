---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/sparseTable.hpp
    title: "sparseTable ( $x \\oplus x\\ =\\ x$ \u306E\u533A\u9593\u30AF\u30A8\u30EA\
      \u89E3\u7B54 )"
  - icon: ':heavy_check_mark:'
    path: src/utility/sparseTable/gcdStructure.hpp
    title: gcdStructure (Sparse Table)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc125/submissions/39483132
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC125-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    \t\treturn dat;\n\t}\n\n};\n\n} // namespace zawa\n#line 1 \"src/utility/sparseTable/gcdStructure.hpp\"\
    \n#include <numeric>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct gcdStructure\
    \ {\n\tusing valueType = T;\n\tstatic valueType operation(const valueType& a,\
    \ const valueType& b) {\n\t\treturn std::gcd(a, b);\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 5 \"test/ABC125-C.test.cpp\"\n\n#line 7 \"test/ABC125-C.test.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n#line 10 \"test/ABC125-C.test.cpp\"\
    \n\nint main() {\n\t// int N; std::cin >> N;\n\t// std::vector A(N, 0);\n\t//\
    \ for (auto& a : A) {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::sparseTable<zawa::gcdStructure<int>>\
    \ S(A);\n\t// int ans = S.query(0, N);\n\t// ans = std::max(ans, S.query(1, N));\n\
    \t// for (int i = 0 ; i < N - 1 ; i++) {\n\t// \tans = std::max(ans, std::gcd(S.query(0,\
    \ i), S.query(i + 1, N)));\n\t// }\n\t// ans = std::max(ans, S.query(0, N - 1));\n\
    \t// std::cout << ans << std::endl;\n\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 125 - C GCD on Blackboard\n * https://atcoder.jp/contests/abc125/submissions/39483132\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/sparseTable.hpp\"\n#include \"../src/utility/sparseTable/gcdStructure.hpp\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <numeric>\n\
    \nint main() {\n\t// int N; std::cin >> N;\n\t// std::vector A(N, 0);\n\t// for\
    \ (auto& a : A) {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::sparseTable<zawa::gcdStructure<int>>\
    \ S(A);\n\t// int ans = S.query(0, N);\n\t// ans = std::max(ans, S.query(1, N));\n\
    \t// for (int i = 0 ; i < N - 1 ; i++) {\n\t// \tans = std::max(ans, std::gcd(S.query(0,\
    \ i), S.query(i + 1, N)));\n\t// }\n\t// ans = std::max(ans, S.query(0, N - 1));\n\
    \t// std::cout << ans << std::endl;\n\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 125 - C GCD on Blackboard\n * https://atcoder.jp/contests/abc125/submissions/39483132\n\
    \ */\n"
  dependsOn:
  - src/dataStructure/sparseTable.hpp
  - src/utility/sparseTable/gcdStructure.hpp
  isVerificationFile: true
  path: test/ABC125-C.test.cpp
  requiredBy: []
  timestamp: '2023-03-06 15:21:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC125-C.test.cpp
layout: document
redirect_from:
- /verify/test/ABC125-C.test.cpp
- /verify/test/ABC125-C.test.cpp.html
title: test/ABC125-C.test.cpp
---
