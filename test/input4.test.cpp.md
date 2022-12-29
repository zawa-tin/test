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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/9/INFO1/4/INFO1_04_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/9/INFO1/4/INFO1_04_A
  bundledCode: "#line 1 \"test/input4.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/9/INFO1/4/INFO1_04_A\"\
    \n\n#line 2 \"src/template/input.hpp\"\n\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa::input {\n\ntemplate <typename T> \nvoid in(T&\
    \ res) { std::cin >> res; }\n\ntemplate <typename Head, typename... Tail>\nvoid\
    \ in(Head& head, Tail&... tail) { in(head); in(tail...); }\n\ntemplate <typename\
    \ T, typename U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second);\
    \ }\n\ntemplate <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res)\
    \ { in(r); } }\n\n} // namespace zawa::input\n#line 4 \"test/input4.test.cpp\"\
    \n\nusing namespace zawa::input;\n\nint main() {\n    std::pair p(0, 0); in(p);\n\
    \    std::cout << p.first + p.second << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/9/INFO1/4/INFO1_04_A\"\
    \n\n#include \"../src/template/input.hpp\"\n\nusing namespace zawa::input;\n\n\
    int main() {\n    std::pair p(0, 0); in(p);\n    std::cout << p.first + p.second\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/template/input.hpp
  isVerificationFile: true
  path: test/input4.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 21:38:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/input4.test.cpp
layout: document
redirect_from:
- /verify/test/input4.test.cpp
- /verify/test/input4.test.cpp.html
title: test/input4.test.cpp
---
