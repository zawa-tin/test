---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/makebuc.hpp
    title: "makebuc (\u30D0\u30B1\u30C3\u30C8)"
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
  bundledCode: "#line 1 \"test/makebuc.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#line 2 \"src/template/makebuc.hpp\"\n\n#include <vector>\n#include <string>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstd::vector<int> makebuc(const std::vector<T>&\
    \ A, const T& sup) {\n\tstd::vector<int> res(sup, 0);\n\tfor (const auto& a :\
    \ A) {\n\t\tres[a]++;\n\t}\n\treturn res;\n}\n\nstd::vector<int> makebuc(const\
    \ std::string& S, bool lower = true) {\n\tstd::vector<int> res(26, 0);\n\tint\
    \ minus = (lower ? (int)'a' : (int)'A');\n\tfor (const auto& c : S) {\n\t\tres[c\
    \ - minus]++;\n\t}\n\treturn res;\n}\n\n} // namespace zawa\n#line 4 \"test/makebuc.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/makebuc.test.cpp\"\n\nint main() {\n\t\
    int n; std::cin >> n;\n\tstd::vector A(n, 0);\n\tfor (auto& a : A) {\n\t\tstd::cin\
    \ >> a;\n\t}\n\tauto buc = zawa::makebuc(A, 10001);\n\tstd::vector res(0, 0);\n\
    \tfor (int i = 0 ; i < 10001 ; i++) {\n\t\tfor (int _ = 0 ; _ < buc[i] ; _++)\
    \ {\n\t\t\tres.push_back(i);\n\t\t}\n\t}\n\tfor (int i = 0 ; i < n ; i++) {\n\t\
    \tstd::cout << res[i] << (i + 1 == n ? '\\n' : ' ');\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_A\"\
    \n\n#include \"../src/template/makebuc.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\tint n; std::cin >> n;\n\tstd::vector A(n, 0);\n\t\
    for (auto& a : A) {\n\t\tstd::cin >> a;\n\t}\n\tauto buc = zawa::makebuc(A, 10001);\n\
    \tstd::vector res(0, 0);\n\tfor (int i = 0 ; i < 10001 ; i++) {\n\t\tfor (int\
    \ _ = 0 ; _ < buc[i] ; _++) {\n\t\t\tres.push_back(i);\n\t\t}\n\t}\n\tfor (int\
    \ i = 0 ; i < n ; i++) {\n\t\tstd::cout << res[i] << (i + 1 == n ? '\\n' : ' ');\n\
    \t}\n}\n"
  dependsOn:
  - src/template/makebuc.hpp
  isVerificationFile: true
  path: test/makebuc.test.cpp
  requiredBy: []
  timestamp: '2023-01-26 05:44:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/makebuc.test.cpp
layout: document
redirect_from:
- /verify/test/makebuc.test.cpp
- /verify/test/makebuc.test.cpp.html
title: test/makebuc.test.cpp
---
