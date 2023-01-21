---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/binary-search.hpp
    title: "binary-seach (\u6574\u6570\u4E8C\u5206\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D
  bundledCode: "#line 1 \"test/binary-search.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D\"\
    \n\n#line 2 \"src/template/binary-search.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class F>\nT binary_search(T ok, T ng, const F&\
    \ f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\t\
    if (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t\
    }\n\treturn ok;\n}\n\n}\n#line 4 \"test/binary-search.test.cpp\"\n\n#include <iostream>\n\
    #include <vector>\n#include <functional>\n\nint main() {\n\tint n, k; std::cin\
    \ >> n >> k;\n\tstd::vector ws(n, 0);\n\tfor (auto& w : ws) {\n\t\tstd::cin >>\
    \ w;\n\t}\n\tauto f = [&](int p) -> bool {\n\t\tint iter = 0, now = 0, used =\
    \ 1;\n\t\twhile ((std::size_t)iter < ws.size()) {\n\t\t\tif (used > k) {\n\t\t\
    \t\treturn false;\n\t\t\t}\n\t\t\tif (now + ws[iter] <= p) {\n\t\t\t\tnow += ws[iter++];\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tnow = 0;\n\t\t\t\tused++;\n\t\t\t}\n\t\t}\n\t\t\
    return true;\n\t};\n\tconst int sup = 1e9 + 100;\n\tstd::cout << zawa::binary_search(sup,\
    \ 0, f) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D\"\
    \n\n#include \"../src/template/binary-search.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <functional>\n\nint main() {\n\tint n, k; std::cin >> n >>\
    \ k;\n\tstd::vector ws(n, 0);\n\tfor (auto& w : ws) {\n\t\tstd::cin >> w;\n\t\
    }\n\tauto f = [&](int p) -> bool {\n\t\tint iter = 0, now = 0, used = 1;\n\t\t\
    while ((std::size_t)iter < ws.size()) {\n\t\t\tif (used > k) {\n\t\t\t\treturn\
    \ false;\n\t\t\t}\n\t\t\tif (now + ws[iter] <= p) {\n\t\t\t\tnow += ws[iter++];\n\
    \t\t\t}\n\t\t\telse {\n\t\t\t\tnow = 0;\n\t\t\t\tused++;\n\t\t\t}\n\t\t}\n\t\t\
    return true;\n\t};\n\tconst int sup = 1e9 + 100;\n\tstd::cout << zawa::binary_search(sup,\
    \ 0, f) << std::endl;\n}\n"
  dependsOn:
  - src/template/binary-search.hpp
  isVerificationFile: true
  path: test/binary-search.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 14:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/binary-search.test.cpp
layout: document
redirect_from:
- /verify/test/binary-search.test.cpp
- /verify/test/binary-search.test.cpp.html
title: test/binary-search.test.cpp
---
