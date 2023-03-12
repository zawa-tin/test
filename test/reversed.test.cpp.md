---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/reversed.hpp
    title: reversed (reverse)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc198/tasks/abc198_b
    links:
    - https://atcoder.jp/contests/abc198/tasks/abc198_b
  bundledCode: "#line 1 \"test/reversed.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc198/tasks/abc198_b\"\
    \n\n#line 2 \"src/template/reversed.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    #include <string>\n\nnamespace zawa::util {\n\ntemplate <class T>\nstd::vector<T>\
    \ reversed(std::vector<T> A) {\n\tstd::reverse(A.begin(), A.end());\n\treturn\
    \ A;\n}\n\nstd::string reversed(std::string s) {\n\tstd::reverse(s.begin(), s.end());\n\
    \treturn s;\n}\n\n} // namespace zawa::util\n#line 4 \"test/reversed.test.cpp\"\
    \n\n#include <iostream>\n#line 8 \"test/reversed.test.cpp\"\n\nusing namespace\
    \ zawa::util;\n\nint main() {\n\tint N; std::cin >> N;\t\n\tif (N == 0) {\n\t\t\
    std::cout << \"Yes\" << std::endl;\n\t\treturn 0;\n\t}\n\tstd::vector vec(0, 0);\n\
    \tstd::string str;\n\twhile (N % 10 == 0) N /= 10;\n\twhile (N) {\n\t\tvec.push_back(N\
    \ % 10);\n\t\tstr.push_back((N % 10) + '0');\n\t\tN /= 10;\n\t}\n\tbool ok = (vec\
    \ == reversed(vec)) and (str == reversed(str));\n\tstd::cout << (ok ? \"Yes\"\
    \ : \"No\") << std::endl;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc198/tasks/abc198_b\"\n\n\
    #include \"../src/template/reversed.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    #include <string>\n\nusing namespace zawa::util;\n\nint main() {\n\tint N; std::cin\
    \ >> N;\t\n\tif (N == 0) {\n\t\tstd::cout << \"Yes\" << std::endl;\n\t\treturn\
    \ 0;\n\t}\n\tstd::vector vec(0, 0);\n\tstd::string str;\n\twhile (N % 10 == 0)\
    \ N /= 10;\n\twhile (N) {\n\t\tvec.push_back(N % 10);\n\t\tstr.push_back((N %\
    \ 10) + '0');\n\t\tN /= 10;\n\t}\n\tbool ok = (vec == reversed(vec)) and (str\
    \ == reversed(str));\n\tstd::cout << (ok ? \"Yes\" : \"No\") << std::endl;\n}\n"
  dependsOn:
  - src/template/reversed.hpp
  isVerificationFile: true
  path: test/reversed.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 16:57:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/reversed.test.cpp
layout: document
redirect_from:
- /verify/test/reversed.test.cpp
- /verify/test/reversed.test.cpp.html
title: test/reversed.test.cpp
---
