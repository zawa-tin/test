---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/accum2d.hpp
    title: "accum2d (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
  - icon: ':heavy_check_mark:'
    path: src/template/binary-search.hpp
    title: "binary-seach (\u6574\u6570\u4E8C\u5206\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc203/submissions/38188430
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC203-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/template/binary-search.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class F>\nT binary_search(T ok, T ng, const F&\
    \ f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\t\
    if (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t\
    }\n\treturn ok;\n}\n\n}\n#line 2 \"src/dataStructure/accum2d.hpp\"\n\n#include\
    \ <vector>\n#include <utility>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct\
    \ accum2d : std::vector<std::vector<T>> {\n\taccum2d() {\n\t\t(*this).push_back({\
    \ T() });\n\t}\n\taccum2d(const std::vector<std::vector<T>>& A) : std::vector<std::vector<T>>(A.size()\
    \ + 1, std::vector<T>(A[0].size() + 1, T())) {\n\t\tfor (std::size_t i = 0 ; i\
    \ < A.size() ; i++) {\n\t\t\tfor (std::size_t j = 0 ; j < A[i].size() ; j++) {\n\
    \t\t\t\t(*this)[i + 1][j + 1] = (*this)[i][j + 1] + (*this)[i + 1][j] - (*this)[i][j]\
    \ + A[i][j];\n\t\t\t}\n\t\t}\n\t}\n\tT sum(std::size_t y1, std::size_t x1, std::size_t\
    \ y2, std::size_t x2) {\n\t\treturn (*this)[y2][x2] - (*this)[y1][x2] - (*this)[y2][x1]\
    \ + (*this)[y1][x1];\n\t}\n\tT sum(std::pair<std::size_t, std::size_t> p1, std::pair<std::size_t,\
    \ std::size_t> p2) {\n\t\treturn sum(p1.first, p1.second, p2.first, p2.second);\n\
    \t}\n};\n\n} // namespace zawa\n#line 5 \"test/ABC203-E.test.cpp\"\n\n#include\
    \ <iostream>\n#line 8 \"test/ABC203-E.test.cpp\"\n\nint main() {\n\t// int N,\
    \ K; std::cin >> N >> K;\n\t// std::vector A(N, std::vector(N, 0));\n\t// for\
    \ (auto& a : A) {\n\t// \tfor (auto& x : a) {\n\t// \t\tstd::cin >> x;\n\t// \t\
    }\n\t// }\n\t// auto f = [&](int p) -> bool {\n\t// \tstd::vector B(N, std::vector(N,\
    \ 0));\n\t// \tfor (int i = 0 ; i < N ; i++) {\n\t// \t\tfor (int j = 0 ; j <\
    \ N ; j++) {\n\t// \t\t\tB[i][j] = (A[i][j] <= p);\n\t// \t\t}\n\t// \t}\n\t//\
    \ \tzawa::accum2d S(B);\n\t// \tbool res = false;\n\t// \tfor (int i = 0 ; i +\
    \ K <= N ; i++) {\n\t// \t\tfor (int j = 0 ; j + K <= N ; j++) {\n\t// \t\t\t\
    res |= S.sum(i, j, i + K, j + K) >= (K * K + 1) / 2;\n\t// \t\t}\n\t// \t}\n\t\
    // \treturn res;\n\t// };\n\t// std::cout << zawa::binary_search((int)1e9, -1,\
    \ f) << std::endl;\n\t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 203 - D Pond\n * https://atcoder.jp/contests/abc203/submissions/38188430\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/template/binary-search.hpp\"\n#include \"../src/dataStructure/accum2d.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n\t// int N, K; std::cin\
    \ >> N >> K;\n\t// std::vector A(N, std::vector(N, 0));\n\t// for (auto& a : A)\
    \ {\n\t// \tfor (auto& x : a) {\n\t// \t\tstd::cin >> x;\n\t// \t}\n\t// }\n\t\
    // auto f = [&](int p) -> bool {\n\t// \tstd::vector B(N, std::vector(N, 0));\n\
    \t// \tfor (int i = 0 ; i < N ; i++) {\n\t// \t\tfor (int j = 0 ; j < N ; j++)\
    \ {\n\t// \t\t\tB[i][j] = (A[i][j] <= p);\n\t// \t\t}\n\t// \t}\n\t// \tzawa::accum2d\
    \ S(B);\n\t// \tbool res = false;\n\t// \tfor (int i = 0 ; i + K <= N ; i++) {\n\
    \t// \t\tfor (int j = 0 ; j + K <= N ; j++) {\n\t// \t\t\tres |= S.sum(i, j, i\
    \ + K, j + K) >= (K * K + 1) / 2;\n\t// \t\t}\n\t// \t}\n\t// \treturn res;\n\t\
    // };\n\t// std::cout << zawa::binary_search((int)1e9, -1, f) << std::endl;\n\t\
    \n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 203 - D Pond\n * https://atcoder.jp/contests/abc203/submissions/38188430\n */\n"
  dependsOn:
  - src/template/binary-search.hpp
  - src/dataStructure/accum2d.hpp
  isVerificationFile: true
  path: test/ABC203-E.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 19:38:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC203-E.test.cpp
layout: document
redirect_from:
- /verify/test/ABC203-E.test.cpp
- /verify/test/ABC203-E.test.cpp.html
title: test/ABC203-E.test.cpp
---
