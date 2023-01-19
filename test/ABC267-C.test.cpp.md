---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/accum1d.hpp
    title: "accum1d (\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc267/submissions/38149627
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC267-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/template/accum1d.hpp\"\n\n#include <vector>\n#include <numeric>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct accum1d : std::vector<T> {\n\t\
    using vector = std::vector<T>;\n\taccum1d() {\n\t\t(*this).push_back(T());\n\t\
    }\n\taccum1d(const std::vector<T>& A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(),\
    \ A.end(), std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\
    \taccum1d(InputIterator begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\
    \t\tstd::partial_sum(begin, end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t\
    \ l, std::size_t r) {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 4 \"test/ABC267-C.test.cpp\"\n\n#include <iostream>\n#line 7 \"\
    test/ABC267-C.test.cpp\"\n#include <algorithm>\n\nint main() {\n\t// int N, M;\
    \ std::cin >> N >> M;\n\t// std::vector A(N, 0LL);\n\t// for (long long& a : A)\
    \ {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::accum1d sum(A);\n\t// long long\
    \ ans = 0;\n\t// for (int i = 0 ; i < M ; i++) {\n\t// \tans += A[i] * (i + 1);\n\
    \t// }\n\t// long long now = ans;\n\t// for (int i = 0 ; i + M < N ; i++) {\n\t\
    // \tnow -= A[i];\n\t// \tnow -= sum.sum(i + 1, i + M);\n\t// \tnow += M * A[i\
    \ + M];\n\t// \tans = std::max(ans, now);\n\t// }\n\t// std::cout << ans << std::endl;\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 267 - C Index x A(Continuous ver.)\n * https://atcoder.jp/contests/abc267/submissions/38149627\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/template/accum1d.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n\nint main() {\n\t// int N, M; std::cin >> N\
    \ >> M;\n\t// std::vector A(N, 0LL);\n\t// for (long long& a : A) {\n\t// \tstd::cin\
    \ >> a;\n\t// }\n\t// zawa::accum1d sum(A);\n\t// long long ans = 0;\n\t// for\
    \ (int i = 0 ; i < M ; i++) {\n\t// \tans += A[i] * (i + 1);\n\t// }\n\t// long\
    \ long now = ans;\n\t// for (int i = 0 ; i + M < N ; i++) {\n\t// \tnow -= A[i];\n\
    \t// \tnow -= sum.sum(i + 1, i + M);\n\t// \tnow += M * A[i + M];\n\t// \tans\
    \ = std::max(ans, now);\n\t// }\n\t// std::cout << ans << std::endl;\n\tstd::cout\
    \ << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 267 -\
    \ C Index x A(Continuous ver.)\n * https://atcoder.jp/contests/abc267/submissions/38149627\n\
    \ */\n"
  dependsOn:
  - src/template/accum1d.hpp
  isVerificationFile: true
  path: test/ABC267-C.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 16:07:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC267-C.test.cpp
layout: document
redirect_from:
- /verify/test/ABC267-C.test.cpp
- /verify/test/ABC267-C.test.cpp.html
title: test/ABC267-C.test.cpp
---
