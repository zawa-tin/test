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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc278/submissions/38162869
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC278-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    } // namespace zawa\n#line 4 \"test/ABC278-E.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/ABC278-E.test.cpp\"\n\nint main() {\n\t// int H, W, N, h, w; std::cin\
    \ >> H >> W >> N >> h >> w;\n\t// std::vector A(N, std::vector(H, std::vector(W,\
    \ 0)));\n\t// for (int i = 0 ; i < H ; i++) {\n\t// \tfor (int j = 0 ; j < W ;\
    \ j++) {\n\t// \t\tint a; std::cin >> a;\n\t// \t\tA[a - 1][i][j]++;\n\t// \t\
    }\n\t// }\n\t// std::vector<zawa::accum2d<int>> S(N);\n\t// for (int i = 0 ; i\
    \ < N ; i++) {\n\t// \tS[i] = zawa::accum2d(A[i]);\n\t// }\n\t// for (int i =\
    \ 0 ; i + h <= H ; i++) {\n\t// \tfor (int j = 0 ; j + w <= W ; j++) {\n\t// \t\
    \tint ans = 0;\n\t// \t\tfor (int k = 0 ; k < N ; k++) {\n\t// \t\t\tans += (S[k].sum(0,\
    \ 0, H, W) - S[k].sum(i, j, i + h, j + w) > 0);\n\t// \t\t}\n\t// \t\tstd::cout\
    \ << ans << (j + w == W ? '\\n' : ' ');\n\t// \t}\n\t// }\n\tstd::cout << \"Hello\
    \ World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 278 - E Grid Filling\n\
    \ * https://atcoder.jp/contests/abc278/submissions/38162869\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/accum2d.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\t// int H, W, N, h, w; std::cin >> H >> W >> N >>\
    \ h >> w;\n\t// std::vector A(N, std::vector(H, std::vector(W, 0)));\n\t// for\
    \ (int i = 0 ; i < H ; i++) {\n\t// \tfor (int j = 0 ; j < W ; j++) {\n\t// \t\
    \tint a; std::cin >> a;\n\t// \t\tA[a - 1][i][j]++;\n\t// \t}\n\t// }\n\t// std::vector<zawa::accum2d<int>>\
    \ S(N);\n\t// for (int i = 0 ; i < N ; i++) {\n\t// \tS[i] = zawa::accum2d(A[i]);\n\
    \t// }\n\t// for (int i = 0 ; i + h <= H ; i++) {\n\t// \tfor (int j = 0 ; j +\
    \ w <= W ; j++) {\n\t// \t\tint ans = 0;\n\t// \t\tfor (int k = 0 ; k < N ; k++)\
    \ {\n\t// \t\t\tans += (S[k].sum(0, 0, H, W) - S[k].sum(i, j, i + h, j + w) >\
    \ 0);\n\t// \t\t}\n\t// \t\tstd::cout << ans << (j + w == W ? '\\n' : ' ');\n\t\
    // \t}\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 278 - E Grid Filling\n * https://atcoder.jp/contests/abc278/submissions/38162869\n\
    \ */\n"
  dependsOn:
  - src/dataStructure/accum2d.hpp
  isVerificationFile: true
  path: test/ABC278-E.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 10:35:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC278-E.test.cpp
layout: document
redirect_from:
- /verify/test/ABC278-E.test.cpp
- /verify/test/ABC278-E.test.cpp.html
title: test/ABC278-E.test.cpp
---
