---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/binary-search.test.cpp
    title: test/binary-search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/binary-search.hpp\"\n\n#include <cmath>\n\n\
    namespace zawa {\n\ntemplate <class T, class F>\nT binary_search(T ok, T ng, const\
    \ F& f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\
    \tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t\
    }\n\treturn ok;\n}\n\n}\n"
  code: "#pragma once\n\n#include <cmath>\n\nnamespace zawa {\n\ntemplate <class T,\
    \ class F>\nT binary_search(T ok, T ng, const F& f) {\n\twhile (std::abs(ok -\
    \ ng) > 1) {\n\t\tT mid = ((ok + ng) >> 1);\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\
    \t\t}\n\t\telse {\n\t\t\tng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/binary-search.hpp
  requiredBy: []
  timestamp: '2023-01-21 14:21:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/binary-search.test.cpp
documentation_of: src/template/binary-search.hpp
layout: document
redirect_from:
- /library/src/template/binary-search.hpp
- /library/src/template/binary-search.hpp.html
title: src/template/binary-search.hpp
---
