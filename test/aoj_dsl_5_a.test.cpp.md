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
    \ + 1)) {}\n        \n        Accum_1D(const std::vector<T>& arr, T elem)\n  \
    \          : container(arr.begin(), arr.end())\n            , accum(std::vector<T>(arr.size()\
    \ + 1, elem)) {}\n\n        Accum_1D(int n)\n            : container(n)\n    \
    \        , accum(n + 1) {}\n\n        Accum_1D(int n, T elem)\n            : container(n)\n\
    \            , accum(n + 1, elem) {}\n\n        void set(int idx, T val) {\n \
    \           container[idx] = val;\n        }\n\n        void add(int idx, T val)\
    \ {\n            container[idx] += val;\n        }\n\n        void build() {\n\
    \            for (int i = 0 ; i < (int)container.size() ; i++) {\n           \
    \     accum[i + 1] = accum[i] + container[i];\n            }\n        }\n\n  \
    \      T get(int idx) {\n            return container[idx];\n        }\n\n   \
    \     T query(int l, int r) {\n            return accum[r] - accum[l];\n     \
    \   }\n        \n    };\n\n}// namespace zawa\n#line 6 \"test/aoj_dsl_5_a.test.cpp\"\
    \n\nint main() {\n    int n, t;\n    std::cin >> n >> t;\n    std::vector<int>\
    \ ls(n), rs(n);\n    for (int i = 0 ; i < n ; i++) std::cin >> ls[i] >> rs[i];\n\
    \n    zawa::Accum_1D<int> test1(t + 1), test2(t + 1, 0);\n    std::vector<int>\
    \ customers(t + 1);\n\n    for (int i = 0 ; i < n ; i++) {\n        test1.add(ls[i],\
    \ 1);\n        test1.add(rs[i], -1);\n\n        test2.set(ls[i], test2.get(ls[i])\
    \ + 1);\n        test2.set(rs[i], test2.get(rs[i]) - 1);\n\n        customers[ls[i]]++;\n\
    \        customers[rs[i]]--;\n    }\n\n    zawa::Accum_1D<int> test3(customers),\
    \ test4(customers, 0);\n\n    test1.build();\n    test2.build();\n    test3.build();\n\
    \    test4.build();\n\n    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;\n    for\
    \ (int i = 0 ; i <= t + 1 ; i++) {\n        ans1 = std::max(ans1, test1.query(0,\
    \ i));\n        ans2 = std::max(ans2, test2.query(0, i));\n        ans3 = std::max(ans3,\
    \ test3.query(0, i));\n        ans4 = std::max(ans4, test4.query(0, i));\n   \
    \ }\n\n    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);\n\n    std::cout\
    \ << ans1 << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_A\"\
    \n\n#include <iostream>\n#include <cassert>\n#include \"../src/dataStructure/Accum-1D.hpp\"\
    \n\nint main() {\n    int n, t;\n    std::cin >> n >> t;\n    std::vector<int>\
    \ ls(n), rs(n);\n    for (int i = 0 ; i < n ; i++) std::cin >> ls[i] >> rs[i];\n\
    \n    zawa::Accum_1D<int> test1(t + 1), test2(t + 1, 0);\n    std::vector<int>\
    \ customers(t + 1);\n\n    for (int i = 0 ; i < n ; i++) {\n        test1.add(ls[i],\
    \ 1);\n        test1.add(rs[i], -1);\n\n        test2.set(ls[i], test2.get(ls[i])\
    \ + 1);\n        test2.set(rs[i], test2.get(rs[i]) - 1);\n\n        customers[ls[i]]++;\n\
    \        customers[rs[i]]--;\n    }\n\n    zawa::Accum_1D<int> test3(customers),\
    \ test4(customers, 0);\n\n    test1.build();\n    test2.build();\n    test3.build();\n\
    \    test4.build();\n\n    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;\n    for\
    \ (int i = 0 ; i <= t + 1 ; i++) {\n        ans1 = std::max(ans1, test1.query(0,\
    \ i));\n        ans2 = std::max(ans2, test2.query(0, i));\n        ans3 = std::max(ans3,\
    \ test3.query(0, i));\n        ans4 = std::max(ans4, test4.query(0, i));\n   \
    \ }\n\n    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);\n\n    std::cout\
    \ << ans1 << std::endl;\n}\n"
  dependsOn:
  - src/dataStructure/Accum-1D.hpp
  isVerificationFile: true
  path: test/aoj_dsl_5_a.test.cpp
  requiredBy: []
  timestamp: '2022-08-16 15:43:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_dsl_5_a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_dsl_5_a.test.cpp
- /verify/test/aoj_dsl_5_a.test.cpp.html
title: test/aoj_dsl_5_a.test.cpp
---
