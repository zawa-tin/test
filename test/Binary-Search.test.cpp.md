---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Binary-Search.hpp
    title: "Binary Search (\u4E8C\u5206\u63A2\u7D22)"
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
  bundledCode: "#line 1 \"test/Binary-Search.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D\"\
    \n\n#line 2 \"src/algorithm/Binary-Search.hpp\"\n\n#include <cmath>\n\nnamespace\
    \ zawa {\n    \n    template <class T, class F>\n    T binary_search(T ac, T wa,\
    \ const F& judge) {\n        while (abs(ac - wa) > 1) {\n            T mid = (ac\
    \ + wa) >> 1;\n            if (judge(mid)) {\n                ac = mid; \n   \
    \         }\n            else {\n                wa = mid;\n            }\n  \
    \      }\n\n        return ac;\n    }\n\n}// namespace zawa\n#line 4 \"test/Binary-Search.test.cpp\"\
    \n#include <iostream>\n#include <vector>\n\nint main() {\n    int n, k;\n    std::cin\
    \ >> n >> k;\n    std::vector<int> ws(n);\n    for (auto& w : ws) std::cin >>\
    \ w;\n\n    constexpr int sup = 100000 * 10000 + 100;\n    \n    std::cout <<\
    \ zawa::binary_search(sup, 0, [&](int p) -> bool {\n                int iter =\
    \ 0, now = 0, used = 1; \n                while (iter < (int)ws.size()) {\n  \
    \                  if (used > k) return false;       \n                    if\
    \ (now + ws[iter] <= p) {\n                        now += ws[iter++];\n      \
    \              }\n                    else {\n                        now = 0;\n\
    \                        used++;\n                    }\n                }\n\n\
    \                return true;\n\n            }) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_D\"\
    \n\n#include \"../src/algorithm/Binary-Search.hpp\"\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n    int n, k;\n    std::cin >> n >> k;\n    std::vector<int>\
    \ ws(n);\n    for (auto& w : ws) std::cin >> w;\n\n    constexpr int sup = 100000\
    \ * 10000 + 100;\n    \n    std::cout << zawa::binary_search(sup, 0, [&](int p)\
    \ -> bool {\n                int iter = 0, now = 0, used = 1; \n             \
    \   while (iter < (int)ws.size()) {\n                    if (used > k) return\
    \ false;       \n                    if (now + ws[iter] <= p) {\n            \
    \            now += ws[iter++];\n                    }\n                    else\
    \ {\n                        now = 0;\n                        used++;\n     \
    \               }\n                }\n\n                return true;\n\n     \
    \       }) << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Binary-Search.hpp
  isVerificationFile: true
  path: test/Binary-Search.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 21:33:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Binary-Search.test.cpp
layout: document
redirect_from:
- /verify/test/Binary-Search.test.cpp
- /verify/test/Binary-Search.test.cpp.html
title: test/Binary-Search.test.cpp
---
