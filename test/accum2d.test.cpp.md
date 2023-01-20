---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/accum2d.hpp
    title: "accum2d (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"test/accum2d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#line 2 \"src/dataStructure/accum2d.hpp\"\n\n#include <vector>\n#include <utility>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct accum2d : std::vector<std::vector<T>>\
    \ {\n\taccum2d() {\n\t\t(*this).push_back({ T() });\n\t}\n\taccum2d(const std::vector<std::vector<T>>&\
    \ A) : std::vector<std::vector<T>>(A.size() + 1, std::vector<T>(A[0].size() +\
    \ 1, T())) {\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tfor (std::size_t\
    \ j = 0 ; j < A[i].size() ; j++) {\n\t\t\t\t(*this)[i + 1][j + 1] = (*this)[i][j\
    \ + 1] + (*this)[i + 1][j] - (*this)[i][j] + A[i][j];\n\t\t\t}\n\t\t}\n\t}\n\t\
    T sum(std::size_t y1, std::size_t x1, std::size_t y2, std::size_t x2) {\n\t\t\
    return (*this)[y2][x2] - (*this)[y1][x2] - (*this)[y2][x1] + (*this)[y1][x1];\n\
    \t}\n\tT sum(std::pair<std::size_t, std::size_t> p1, std::pair<std::size_t, std::size_t>\
    \ p2) {\n\t\treturn sum(p1.first, p1.second, p2.first, p2.second);\n\t}\n};\n\n\
    } // namespace zawa\n#line 4 \"test/accum2d.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/accum2d.test.cpp\"\n#include <algorithm>\n\nint main() {\n\tint\
    \ N; std::cin >> N;\n\tstd::vector A(1001, std::vector(1001, 0));\n\tfor (int\
    \ _ = 0 ; _ < N ; _++) {\n\t\tint x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >>\
    \ y2;\n\t\tA[y1][x1]++;\n\t\tA[y1][x2]--;\n\t\tA[y2][x1]--;\n\t\tA[y2][x2]++;\n\
    \t}\n\tzawa::accum2d S(A);\n\tint ans = 0;\n\tfor (const auto& s : S) {\n\t\t\
    ans = std::max(ans, *max_element(s.begin(), s.end()));\n\t}\n\tstd::cout << ans\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../src/dataStructure/accum2d.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <algorithm>\n\nint main() {\n\tint N; std::cin >> N;\n\t\
    std::vector A(1001, std::vector(1001, 0));\n\tfor (int _ = 0 ; _ < N ; _++) {\n\
    \t\tint x1, y1, x2, y2; std::cin >> x1 >> y1 >> x2 >> y2;\n\t\tA[y1][x1]++;\n\t\
    \tA[y1][x2]--;\n\t\tA[y2][x1]--;\n\t\tA[y2][x2]++;\n\t}\n\tzawa::accum2d S(A);\n\
    \tint ans = 0;\n\tfor (const auto& s : S) {\n\t\tans = std::max(ans, *max_element(s.begin(),\
    \ s.end()));\n\t}\n\tstd::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/dataStructure/accum2d.hpp
  isVerificationFile: true
  path: test/accum2d.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 10:35:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/accum2d.test.cpp
layout: document
redirect_from:
- /verify/test/accum2d.test.cpp
- /verify/test/accum2d.test.cpp.html
title: test/accum2d.test.cpp
---
