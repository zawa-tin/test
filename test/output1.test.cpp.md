---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/output1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/template/output.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    #include <string>\n\nnamespace zawa::output {\n\nvoid out() { \n    std::cout\
    \ << std::endl; \n}\n\ntemplate <class T>\nvoid out(const T& a) { \n    std::cout\
    \ << a << std::endl; \n}\n\ntemplate <class T>\nvoid out(const std::vector<T>&\
    \ as) { \n    for (std::size_t i = 0 ; i < as.size() ; i++) { \n        std::cout\
    \ << as[i] << (i + 1 == as.size() ? '\\n' : ' '); \n    } \n}\n\ntemplate <class\
    \ Head, class... Tail>\nvoid out(const Head& head, const Tail&... tail) { \n \
    \   std::cout << head; \n    if (sizeof...(tail)) { \n        std::cout << ' ';\
    \ \n    } \n    out(tail...);\n}\n\nvoid yesno(bool flag, std::string yes = \"\
    Yes\", std::string no = \"No\") {\n    std::cout << (flag ? yes : no) << std::endl;\n\
    }\n\n} // namespace zawa::output\n#line 4 \"test/output1.test.cpp\"\nusing namespace\
    \ zawa::output;\n\nint main() {\n    out(\"Hello World\");\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/template/output.hpp\"\nusing namespace zawa::output;\n\n\
    int main() {\n    out(\"Hello World\");\n}\n"
  dependsOn:
  - src/template/output.hpp
  isVerificationFile: true
  path: test/output1.test.cpp
  requiredBy: []
  timestamp: '2022-12-29 22:41:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/output1.test.cpp
layout: document
redirect_from:
- /verify/test/output1.test.cpp
- /verify/test/output1.test.cpp.html
title: test/output1.test.cpp
---
