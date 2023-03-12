---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/sorted.hpp
    title: "sorted (\u30BD\u30FC\u30C8\u5217\u3092\u8FD4\u3059)"
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
  bundledCode: "#line 1 \"test/sorted.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#line 2 \"src/template/sorted.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    #include <string>\n\nnamespace zawa::util {\n\ntemplate <class T>\nstd::vector<T>\
    \ sorted(std::vector<T> A) {\n\tstd::sort(A.begin(), A.end());\n\treturn A;\n\
    }\n\nstd::string sorted(std::string s) {\n\tstd::sort(s.begin(), s.end());\n\t\
    return s;\n}\n\n} // namespace zawa::util\n#line 4 \"test/sorted.test.cpp\"\n\n\
    #include <iostream>\n#line 8 \"test/sorted.test.cpp\"\n#include <cassert>\n\n\
    using namespace zawa::util;\n\nint main() {\n\tstd::ios::sync_with_stdio(false);\n\
    \tstd::cin.tie(nullptr);\n\tint N; std::cin >> N;\n\tstd::vector vec(N, 0);\n\t\
    for (int i = 0 ; i < N ; i++) std::cin >> vec[i];\n\tauto sv = sorted(vec);\n\t\
    for (int i = 0 ; i < N ; i++) {\n\t\tstd::cout << sv[i] << (i + 1 == N ? '\\n'\
    \ : ' ');\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#include \"../src/template/sorted.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    #include <string>\n#include <cassert>\n\nusing namespace zawa::util;\n\nint main()\
    \ {\n\tstd::ios::sync_with_stdio(false);\n\tstd::cin.tie(nullptr);\n\tint N; std::cin\
    \ >> N;\n\tstd::vector vec(N, 0);\n\tfor (int i = 0 ; i < N ; i++) std::cin >>\
    \ vec[i];\n\tauto sv = sorted(vec);\n\tfor (int i = 0 ; i < N ; i++) {\n\t\tstd::cout\
    \ << sv[i] << (i + 1 == N ? '\\n' : ' ');\n\t}\n}\n"
  dependsOn:
  - src/template/sorted.hpp
  isVerificationFile: true
  path: test/sorted.test.cpp
  requiredBy: []
  timestamp: '2023-03-12 16:57:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sorted.test.cpp
layout: document
redirect_from:
- /verify/test/sorted.test.cpp
- /verify/test/sorted.test.cpp.html
title: test/sorted.test.cpp
---
