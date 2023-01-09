---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/count-inv.hpp
    title: "count-inv (\u8EE2\u5012\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D
  bundledCode: "#line 1 \"test/count-inv.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#line 2 \"src/algorithm/count-inv.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa::impl {\n\ntemplate <class T>\nlong long sort(std::vector<T>& arr, int\
    \ left, int right) {\n\tif (right - left == 1) {\n\t\treturn 0LL;\n\t}\n\tlong\
    \ long res = 0LL;\n\tint mid = left + ((right - left) >> 1);\n\tres += sort(arr,\
    \ left, mid);\n\tres += sort(arr, mid, right);\n\tstd::vector<T> fronts(arr.begin()\
    \ + left, arr.begin() + mid);\n\tstd::vector<T> backs(arr.begin() + mid, arr.begin()\
    \ + right);\n\tint front_idx = 0, back_idx = 0;\n\tfor (int i = left ; i < right\
    \ ; i++) {\n\t\tif (front_idx < (int)fronts.size() and \n\t\t\t\t(back_idx ==\
    \ (int)backs.size() or fronts[front_idx] <= backs[back_idx])) {\n\t\t\tarr[i]\
    \ = fronts[front_idx++];\n\t\t}\n\t\telse {\n\t\t\tarr[i] = backs[back_idx++];\n\
    \t\t\tres += mid - left - front_idx;\n\t\t}\n\t}\n\treturn res;\n}\n\n} // namespace\
    \ zawa\n\nnamespace zawa {\n\ntemplate <class T>\nlong long count_inv(const std::vector<T>&\
    \ in) {\n\tstd::vector arr = in;\n\treturn impl::sort(arr, 0, (int)arr.size());\n\
    }\n\n} // namespace zawa\n#line 4 \"test/count-inv.test.cpp\"\n\n#include <iostream>\n\
    #line 7 \"test/count-inv.test.cpp\"\n\nint main() {\n\tint n; std::cin >> n;\n\
    \tstd::vector as(n, 0);\n\tfor (auto& a : as) {\n\t\tstd::cin >> a;\n\t}\n\tstd::cout\
    \ << zawa::count_inv(as) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_D\"\
    \n\n#include \"../src/algorithm/count-inv.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\tint n; std::cin >> n;\n\tstd::vector as(n, 0);\n\
    \tfor (auto& a : as) {\n\t\tstd::cin >> a;\n\t}\n\tstd::cout << zawa::count_inv(as)\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/count-inv.hpp
  isVerificationFile: true
  path: test/count-inv.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 21:34:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/count-inv.test.cpp
layout: document
redirect_from:
- /verify/test/count-inv.test.cpp
- /verify/test/count-inv.test.cpp.html
title: test/count-inv.test.cpp
---
