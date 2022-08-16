---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/Accum-1D.hpp
    title: "Accum 1D (1\u6B21\u5143\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A
  bundledCode: "#line 1 \"test/aoj_dsl_5_a.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#line 2 \"src/dataStructure/Accum-1D.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\n    template <class T>\n    class\
    \ Accum_1D {\n    private:\n        std::vector<T> container;\n        std::vector<T>\
    \ accum;\n\n    public:\n        Accum_1D(const std::vector<T>& arr) \n      \
    \      : container(arr.begin(), arr.end())\n            , accum(std::vector<T>(arr.size()\
    \ + 1)) {\n\n                for (int i = 0 ; i < (int)arr.size() ; i++) {\n \
    \                   accum[i + 1] = accum[i] + container[i];\n                }\n\
    \        }\n        \n        Accum_1D(const std::vector<T>& arr, T elem)\n  \
    \          : container(arr.begin(), arr.end())\n            , accum(std::vector<T>(arr.size()\
    \ + 1, elem)) {\n                \n                for (int i = 0 ; i < (int)arr.size()\
    \ ; i++) {\n                    accum[i + 1] = accum[i] + container[i];\n    \
    \            }\n        }\n\n        T get(int idx) {\n            return container[idx];\n\
    \        }\n\n        T query(int l, int r) {\n            return accum[r] - accum[l];\n\
    \        }\n        \n    };\n\n}// namespace zawa\n#line 6 \"test/aoj_dsl_5_a.test.cpp\"\
    \n\nint main() {\n    int n, t;\n    std::cin >> n >> t;\n    std::vector<int>\
    \ customers(t + 1);\n    for (int i = 0 ; i < n ; i++) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        customers[l]++;\n        customers[r]--;\n\
    \    }\n\n    zawa::Accum_1D<int> accum(customers);\n    int ans = 0;\n    for\
    \ (int i = 1 ; i <= t + 1 ; i++) {\n        ans = std::max(ans, accum.query(0,\
    \ i));\n    }\n    std::cout << ans << std::endl;\n\n\n    // unit test?\n   \
    \ zawa::Accum_1D<int> acm(customers, 0);\n    int a = 0;\n    for (int i = 1 ;\
    \ i <= t + 1 ; i++) {\n        a = std::max(a, acm.query(0, i));\n    }\n    assert(a\
    \ == ans);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include \"../src/dataStructure/Accum-1D.hpp\"\
    \n\nint main() {\n    int n, t;\n    std::cin >> n >> t;\n    std::vector<int>\
    \ customers(t + 1);\n    for (int i = 0 ; i < n ; i++) {\n        int l, r;\n\
    \        std::cin >> l >> r;\n        customers[l]++;\n        customers[r]--;\n\
    \    }\n\n    zawa::Accum_1D<int> accum(customers);\n    int ans = 0;\n    for\
    \ (int i = 1 ; i <= t + 1 ; i++) {\n        ans = std::max(ans, accum.query(0,\
    \ i));\n    }\n    std::cout << ans << std::endl;\n\n\n    // unit test?\n   \
    \ zawa::Accum_1D<int> acm(customers, 0);\n    int a = 0;\n    for (int i = 1 ;\
    \ i <= t + 1 ; i++) {\n        a = std::max(a, acm.query(0, i));\n    }\n    assert(a\
    \ == ans);\n}\n"
  dependsOn:
  - src/dataStructure/Accum-1D.hpp
  isVerificationFile: true
  path: test/aoj_dsl_5_a.test.cpp
  requiredBy: []
  timestamp: '2022-08-16 09:38:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_dsl_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_dsl_5_a.test.cpp
- /verify/test/aoj_dsl_5_a.test.cpp.html
title: test/aoj_dsl_5_a.test.cpp
---
