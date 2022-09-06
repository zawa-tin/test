---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Compression.hpp
    title: "Compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc036/submissions/34650039
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Compression.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/algorithm/Compression.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass Compression {\nprivate:\n    std::vector<T>\
    \ arr;\n\npublic:\n    Compression(const std::vector<T>& in)\n        : arr(in.begin(),\
    \ in.end()) {\n            std::sort(arr.begin(), arr.end());\n            arr.erase(std::unique(arr.begin(),\
    \ arr.end()), arr.end());\n    }\n\n    int get(T x) {\n        return std::lower_bound(arr.begin(),\
    \ arr.end(), x) - arr.begin();\n    }\n};\n    \n}// namespace zawa\n#line 4 \"\
    test/Compression.test.cpp\"\n\n#include <iostream>\n\nint main() {\n    // https://atcoder.jp/contests/abc036/submissions/34650039\n\
    \    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/Compression.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    // https://atcoder.jp/contests/abc036/submissions/34650039\n \
    \   std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Compression.hpp
  isVerificationFile: true
  path: test/Compression.test.cpp
  requiredBy: []
  timestamp: '2022-09-06 15:47:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Compression.test.cpp
layout: document
redirect_from:
- /verify/test/Compression.test.cpp
- /verify/test/Compression.test.cpp.html
title: test/Compression.test.cpp
---
