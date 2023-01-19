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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A
  bundledCode: "#line 1 \"test/accum1d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A\"\
    \n\n#line 2 \"src/template/accum1d.hpp\"\n\n#include <vector>\n#include <numeric>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct accum1d : std::vector<T> {\n\t\
    using vector = std::vector<T>;\n\taccum1d() {\n\t\t(*this).push_back(T());\n\t\
    }\n\taccum1d(const std::vector<T>& A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(),\
    \ A.end(), std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\
    \taccum1d(InputIterator begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\
    \t\tstd::partial_sum(begin, end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t\
    \ l, std::size_t r) {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 4 \"test/accum1d.test.cpp\"\n\n#include <iostream>\n#line 7 \"test/accum1d.test.cpp\"\
    \n#include <algorithm>\n\nint main() {\n\tint N, T; std::cin >> N >> T;\n\tstd::vector\
    \ A(T + 1, 0);\n\tfor (int _ = 0 ; _ < N ; _++) {\n\t\tint l, r; std::cin >> l\
    \ >> r;\n\t\tA[l]++;\n\t\tA[r]--;\n\t}\n\tzawa::accum1d<int> imos(A.begin(), A.end());\n\
    \tstd::cout << *std::max_element(imos.begin(), imos.end()) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A\"\
    \n\n#include \"../src/template/accum1d.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n\nint main() {\n\tint N, T; std::cin >> N >>\
    \ T;\n\tstd::vector A(T + 1, 0);\n\tfor (int _ = 0 ; _ < N ; _++) {\n\t\tint l,\
    \ r; std::cin >> l >> r;\n\t\tA[l]++;\n\t\tA[r]--;\n\t}\n\tzawa::accum1d<int>\
    \ imos(A.begin(), A.end());\n\tstd::cout << *std::max_element(imos.begin(), imos.end())\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/template/accum1d.hpp
  isVerificationFile: true
  path: test/accum1d.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 16:07:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/accum1d.test.cpp
layout: document
redirect_from:
- /verify/test/accum1d.test.cpp
- /verify/test/accum1d.test.cpp.html
title: test/accum1d.test.cpp
---
