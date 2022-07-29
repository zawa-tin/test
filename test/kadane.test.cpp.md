---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Kadane.hpp
    title: "Kadane's Algorithm (\u6700\u5927\u9023\u7D9A\u90E8\u5206\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/kadane.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/algorithm/Kadane.hpp\"\n\n#include <vector>\n\nnamespace zawa\
    \ {\n\n    template <typename T>\n    class Kadane {\n\n    private:\n       \
    \ std::vector<T> arr;\n        std::pair<int, int> segment;\n        T res;\n\n\
    \    public:\n        Kadane(std::vector<T>& arr, T init) \n            : arr(arr.begin(),\
    \ arr.end()), \n              res(init) {}\n\n        void build() {\n       \
    \     T dp = res;\n            int left = 0;\n            for (int right = 0 ;\
    \ right < (int)arr.size() ; right++) {\n                if (dp + arr[right] <\
    \ arr[right]) {\n                    left = right;\n                }\n      \
    \          dp = std::max(dp + arr[right], arr[right]);\n\n                if (res\
    \ < dp) {\n                    segment = {left, right};\n                }\n \
    \               res = std::max(res, dp);\n            }\n            segment.second++;\n\
    \        }\n\n        T get() {\n            return res;\n        }\n\n      \
    \  std::pair<int, int> get_seg() {\n            return segment;\n        }\n \
    \   };\n\n}// namespace zawa\n#line 4 \"test/kadane.test.cpp\"\n#include <iostream>\n\
    #include <cassert>\n\nint main() {\n    std::vector<int> ins = {-5, -1, 6, 4,\
    \ 9, -6, -6, -7};\n    zawa::Kadane<int> kadane(ins, -100);\n    kadane.build();\n\
    \    \n    int ans = 19;\n    int left = 2, right = 5;\n    assert(left == kadane.get_seg().first);\n\
    \    assert(right == kadane.get_seg().second);\n    assert(ans == kadane.get());\n\
    \n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/Kadane.hpp\"\n#include <iostream>\n#include <cassert>\n\
    \nint main() {\n    std::vector<int> ins = {-5, -1, 6, 4, 9, -6, -6, -7};\n  \
    \  zawa::Kadane<int> kadane(ins, -100);\n    kadane.build();\n    \n    int ans\
    \ = 19;\n    int left = 2, right = 5;\n    assert(left == kadane.get_seg().first);\n\
    \    assert(right == kadane.get_seg().second);\n    assert(ans == kadane.get());\n\
    \n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Kadane.hpp
  isVerificationFile: true
  path: test/kadane.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 02:10:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/kadane.test.cpp
layout: document
redirect_from:
- /verify/test/kadane.test.cpp
- /verify/test/kadane.test.cpp.html
title: test/kadane.test.cpp
---
