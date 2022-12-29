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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C
  bundledCode: "#line 1 \"test/input3.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C\"\
    \n\n#line 2 \"src/template/input.hpp\"\n\n#include <iostream>\n#include <utility>\n\
    #include <vector>\n\nnamespace zawa::input {\n\ntemplate <typename T> \nvoid in(T&\
    \ res) { std::cin >> res; }\n\ntemplate <typename Head, typename... Tail>\nvoid\
    \ in(Head& head, Tail&... tail) { in(head); in(tail...); }\n\ntemplate <typename\
    \ T, typename U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second);\
    \ }\n\ntemplate <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res)\
    \ { in(r); } }\n\n} // namespace zawa::input\n#line 4 \"test/input3.test.cpp\"\
    \n\nusing namespace zawa::input;\n\n#include <set>\n#include <string>\n\nint main()\
    \ {\n    int n;\n    in(n);\n    std::set<std::string> st;\n    for (int _ = 0\
    \ ; _ < n ; _++) {\n        std::string q, s; in(q, s);\n        if (q[0] == 'i')\
    \ {\n            st.insert(s);\n        }\n        else {\n            std::cout\
    \ << (st.count(s) ? \"yes\" : \"no\") << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_C\"\
    \n\n#include \"../src/template/input.hpp\"\n\nusing namespace zawa::input;\n\n\
    #include <set>\n#include <string>\n\nint main() {\n    int n;\n    in(n);\n  \
    \  std::set<std::string> st;\n    for (int _ = 0 ; _ < n ; _++) {\n        std::string\
    \ q, s; in(q, s);\n        if (q[0] == 'i') {\n            st.insert(s);\n   \
    \     }\n        else {\n            std::cout << (st.count(s) ? \"yes\" : \"\
    no\") << std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/template/input.hpp
  isVerificationFile: true
  path: test/input3.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 21:38:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/input3.test.cpp
layout: document
redirect_from:
- /verify/test/input3.test.cpp
- /verify/test/input3.test.cpp.html
title: test/input3.test.cpp
---
