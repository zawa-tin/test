---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/input.hpp
    title: "input (\u6A19\u6E96\u5165\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D
  bundledCode: "#line 1 \"test/input2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D\"\
    \n\n#line 2 \"src/template/input.hpp\"\n\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa::input {\n\ntemplate <typename T> \nvoid in(T&\
    \ res) { std::cin >> res; }\n\ntemplate <typename Head, typename... Tail>\nvoid\
    \ in(Head& head, Tail&... tail) { in(head); in(tail...); }\n\ntemplate <typename\
    \ T, typename U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second);\
    \ }\n\ntemplate <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res)\
    \ { in(r); } }\n\n} // namespace zawa::input\n#line 4 \"test/input2.test.cpp\"\
    \n\nusing namespace zawa::input;\n\nint main() {\n    int n, m, l; \n    in(n,\
    \ m, l);\n    std::vector as(n, std::vector(m, 0));\n    for (auto& a : as) {\n\
    \        in(a);\n    }\n    std::vector bs(m, std::vector(l, 0));\n    for (auto&\
    \ b : bs) {\n        in(b);\n    }\n    for (int i = 0 ; i < n ; i++) {\n    \
    \    for (int j = 0 ; j < l ; j++) {\n            long long val = 0;\n       \
    \     for (int k = 0 ; k < m ; k++) {\n                val += as[i][k] * bs[k][j];\n\
    \            }\n            std::cout << val << (j + 1 == l ? '\\n' : ' ');\n\
    \        }\n    }\n}\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/7/ITP1_7_D\"\
    \n\n#include \"../src/template/input.hpp\"\n\nusing namespace zawa::input;\n\n\
    int main() {\n    int n, m, l; \n    in(n, m, l);\n    std::vector as(n, std::vector(m,\
    \ 0));\n    for (auto& a : as) {\n        in(a);\n    }\n    std::vector bs(m,\
    \ std::vector(l, 0));\n    for (auto& b : bs) {\n        in(b);\n    }\n    for\
    \ (int i = 0 ; i < n ; i++) {\n        for (int j = 0 ; j < l ; j++) {\n     \
    \       long long val = 0;\n            for (int k = 0 ; k < m ; k++) {\n    \
    \            val += as[i][k] * bs[k][j];\n            }\n            std::cout\
    \ << val << (j + 1 == l ? '\\n' : ' ');\n        }\n    }\n}\n\n"
  dependsOn:
  - src/template/input.hpp
  isVerificationFile: true
  path: test/input2.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 21:38:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/input2.test.cpp
layout: document
redirect_from:
- /verify/test/input2.test.cpp
- /verify/test/input2.test.cpp.html
title: test/input2.test.cpp
---
