---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/Accum-2D.hpp
    title: "Accum 2D (\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "#line 1 \"test/aoj_dsl_5_b.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include <cassert>\n#include <iostream>\n\n#line 2 \"src/dataStructure/Accum-2D.hpp\"\
    \n\n#line 4 \"src/dataStructure/Accum-2D.hpp\"\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa {\n\n    template <class T>\n    class Accum_2D {\n    private:\n\
    \        std::vector<std::vector<T>> container;\n        std::vector<std::vector<T>>\
    \ accum;\n\n    public:\n        Accum_2D(const std::vector<std::vector<T>>& arr)\n\
    \            : container(arr.begin(), arr.end())\n            , accum(std::vector<std::vector<T>>(arr.size()\
    \ + 1, std::vector<T>(arr[0].size() + 1))) {}\n\n        Accum_2D(const std::vector<std::vector<T>>&\
    \ arr, T elem)\n            : container(arr.begin(), arr.end())\n            ,\
    \ accum(std::vector<std::vector<T>>(arr.size() + 1, std::vector<T>(arr[0].size()\
    \ + 1, elem))) {}\n\n        Accum_2D(int h, int w)\n            : container(std::vector<std::vector<T>>(h,\
    \ std::vector<T>(w)))\n            , accum(std::vector<std::vector<T>>(h + 1,\
    \ std::vector<T>(w + 1))) {}\n\n        Accum_2D(int h, int w, T elem)\n     \
    \       : container(std::vector<std::vector<T>>(h, std::vector<T>(w)))\n     \
    \       , accum(std::vector<std::vector<T>>(h + 1, std::vector<T>(w + 1, elem)))\
    \ {}\n\n        void set(int y, int x, T val) {\n            container[y][x] =\
    \ val;\n        }\n\n        void add(int y, int x, T val) {\n            container[y][x]\
    \ += val;\n        }\n\n        void build() {\n            for (int i = 0 ; i\
    \ < (int)container.size() ; i++) {\n                for (int j = 0 ; j < (int)container[i].size()\
    \ ; j++) {\n                    accum[i + 1][j + 1] = accum[i][j + 1] + accum[i\
    \ + 1][j] - accum[i][j] + container[i][j];\n                }\n            }\n\
    \        }\n\n        T get(int y, int x) {\n            return container[y][x];\n\
    \        }\n\n        T query(int y1, int x1, int y2, int x2) {\n            return\
    \ accum[y2][x2] - accum[y1][x2] - accum[y2][x1] + accum[y1][x1];\n        }\n\n\
    \        T query(std::pair<int, int> p1, std::pair<int, int> p2) {\n         \
    \   return query(p1.first, p1.second, p2.first, p2.second);\n        }\n\n   \
    \     void print() {\n            for (auto y : accum) {\n                for\
    \ (int i = 0 ; i < (int)y.size() ; i++) std::cout << y[i] << (i == (int)y.size()\
    \ - 1 ? '\\n' : ' ');\n                std::cout << std::endl;\n            }\n\
    \        }\n\n    };\n\n}// namespace zawa\n#line 7 \"test/aoj_dsl_5_b.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector ps(1001, std::vector<int>(1001));\n\
    \    std::vector x1s(n, 0), y1s(n, 0), x2s(n, 0), y2s(n, 0);\n    zawa::Accum_2D<int>\
    \ accum1(1001, 1001), accum2(1001, 1001, 0);\n    for (int _ = 0 ; _ < n ; _++)\
    \ {\n        int x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n\n\
    \        accum1.add(y1, x1, 1);\n        accum2.set(y1, x1, accum2.get(y1, x1)\
    \ + 1);\n        ps[y1][x1]++;\n\n        accum1.add(y1, x2, -1);\n        accum2.set(y1,\
    \ x2, accum2.get(y1, x2) - 1);\n        ps[y1][x2]--;\n\n        accum1.add(y2,\
    \ x1, -1);\n        accum2.set(y2, x1, accum2.get(y2, x1) - 1);\n        ps[y2][x1]--;\n\
    \n        accum1.add(y2, x2, 1);\n        accum2.set(y2, x2, accum2.get(y2, x2)\
    \ + 1);\n        ps[y2][x2]++;\n    }\n\n    zawa::Accum_2D<int> accum3(ps), accum4(ps,\
    \ 0);\n    accum1.build();\n    accum2.build();\n    accum3.build();\n    accum4.build();\n\
    \    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;\n    for (int i = 0 ; i <= 1001\
    \ ; i++) {\n        for (int j = 0 ; j <= 1001 ; j++) {\n            ans1 = std::max(ans1,\
    \ accum1.query(0, 0, i, j));\n            ans2 = std::max(ans2, accum2.query(0,\
    \ 0, i, j));\n            ans3 = std::max(ans3, accum3.query(0, 0, i, j));\n \
    \           ans4 = std::max(ans4, accum4.query(0, 0, i, j));\n        }\n    }\n\
    \n    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);\n    std::cout <<\
    \ ans1 << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include <cassert>\n#include <iostream>\n\n#include \"../src/dataStructure/Accum-2D.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector ps(1001, std::vector<int>(1001));\n\
    \    std::vector x1s(n, 0), y1s(n, 0), x2s(n, 0), y2s(n, 0);\n    zawa::Accum_2D<int>\
    \ accum1(1001, 1001), accum2(1001, 1001, 0);\n    for (int _ = 0 ; _ < n ; _++)\
    \ {\n        int x1, y1, x2, y2;\n        std::cin >> x1 >> y1 >> x2 >> y2;\n\n\
    \        accum1.add(y1, x1, 1);\n        accum2.set(y1, x1, accum2.get(y1, x1)\
    \ + 1);\n        ps[y1][x1]++;\n\n        accum1.add(y1, x2, -1);\n        accum2.set(y1,\
    \ x2, accum2.get(y1, x2) - 1);\n        ps[y1][x2]--;\n\n        accum1.add(y2,\
    \ x1, -1);\n        accum2.set(y2, x1, accum2.get(y2, x1) - 1);\n        ps[y2][x1]--;\n\
    \n        accum1.add(y2, x2, 1);\n        accum2.set(y2, x2, accum2.get(y2, x2)\
    \ + 1);\n        ps[y2][x2]++;\n    }\n\n    zawa::Accum_2D<int> accum3(ps), accum4(ps,\
    \ 0);\n    accum1.build();\n    accum2.build();\n    accum3.build();\n    accum4.build();\n\
    \    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;\n    for (int i = 0 ; i <= 1001\
    \ ; i++) {\n        for (int j = 0 ; j <= 1001 ; j++) {\n            ans1 = std::max(ans1,\
    \ accum1.query(0, 0, i, j));\n            ans2 = std::max(ans2, accum2.query(0,\
    \ 0, i, j));\n            ans3 = std::max(ans3, accum3.query(0, 0, i, j));\n \
    \           ans4 = std::max(ans4, accum4.query(0, 0, i, j));\n        }\n    }\n\
    \n    assert(ans1 == ans2 and ans2 == ans3 and ans3 == ans4);\n    std::cout <<\
    \ ans1 << std::endl;\n}\n"
  dependsOn:
  - src/dataStructure/Accum-2D.hpp
  isVerificationFile: true
  path: test/aoj_dsl_5_b.test.cpp
  requiredBy: []
  timestamp: '2022-08-16 22:51:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_dsl_5_b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_dsl_5_b.test.cpp
- /verify/test/aoj_dsl_5_b.test.cpp.html
title: test/aoj_dsl_5_b.test.cpp
---
