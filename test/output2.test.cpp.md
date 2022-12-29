---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/input.hpp
    title: "input (\u6A19\u6E96\u5165\u529B)"
  - icon: ':heavy_check_mark:'
    path: src/template/output.hpp
    title: "output (\u6A19\u6E96\u51FA\u529B)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A
  bundledCode: "#line 1 \"test/output2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#line 2 \"src/template/input.hpp\"\n\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa::input {\n\ntemplate <typename T> \nvoid in(T&\
    \ res) { std::cin >> res; }\n\ntemplate <typename Head, typename... Tail>\nvoid\
    \ in(Head& head, Tail&... tail) { in(head); in(tail...); }\n\ntemplate <typename\
    \ T, typename U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second);\
    \ }\n\ntemplate <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res)\
    \ { in(r); } }\n\n} // namespace zawa::input\n#line 4 \"test/output2.test.cpp\"\
    \nusing namespace zawa::input;\n\n#line 2 \"src/template/output.hpp\"\n\n#line\
    \ 5 \"src/template/output.hpp\"\n#include <string>\n\nnamespace zawa::output {\n\
    \nvoid out() { \n    std::cout << std::endl; \n}\n\ntemplate <class T>\nvoid out(const\
    \ T& a) { \n    std::cout << a << std::endl; \n}\n\ntemplate <class T>\nvoid out(const\
    \ std::vector<T>& as) { \n    for (std::size_t i = 0 ; i < as.size() ; i++) {\
    \ \n        std::cout << as[i] << (i + 1 == as.size() ? '\\n' : ' '); \n    }\
    \ \n}\n\ntemplate <class Head, class... Tail>\nvoid out(const Head& head, const\
    \ Tail&... tail) { \n    std::cout << head; \n    if (sizeof...(tail)) { \n  \
    \      std::cout << ' '; \n    } \n    out(tail...);\n}\n\nvoid yesno(bool flag,\
    \ std::string yes = \"Yes\", std::string no = \"No\") {\n    std::cout << (flag\
    \ ? yes : no) << std::endl;\n}\n\n} // namespace zawa::output\n#line 7 \"test/output2.test.cpp\"\
    \nusing namespace zawa::output;\n\nint main() {\n    int n; in(n);\n    std::vector\
    \ as(n, 0); in(as);\n    std::vector buc(10001, 0);\n    for (auto a : as) {\n\
    \        buc[a]++;\n    }\n    std::vector bs(0, 0);\n    for (int i = 0 ; i <\
    \ 10001 ; i++) {\n        for (int j = 0 ; j < buc[i] ; j++) {\n            bs.push_back(i);\n\
    \        }\n    }\n    out(bs);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#include \"../src/template/input.hpp\"\nusing namespace zawa::input;\n\n#include\
    \ \"../src/template/output.hpp\"\nusing namespace zawa::output;\n\nint main()\
    \ {\n    int n; in(n);\n    std::vector as(n, 0); in(as);\n    std::vector buc(10001,\
    \ 0);\n    for (auto a : as) {\n        buc[a]++;\n    }\n    std::vector bs(0,\
    \ 0);\n    for (int i = 0 ; i < 10001 ; i++) {\n        for (int j = 0 ; j < buc[i]\
    \ ; j++) {\n            bs.push_back(i);\n        }\n    }\n    out(bs);\n}\n"
  dependsOn:
  - src/template/input.hpp
  - src/template/output.hpp
  isVerificationFile: true
  path: test/output2.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 22:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/output2.test.cpp
layout: document
redirect_from:
- /verify/test/output2.test.cpp
- /verify/test/output2.test.cpp.html
title: test/output2.test.cpp
---
