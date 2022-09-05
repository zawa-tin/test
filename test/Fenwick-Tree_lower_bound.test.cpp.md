---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/Fenwick-Tree.hpp
    title: "Fenwick Tree (\u4E00\u70B9\u53EF\u7B97\u30FB\u533A\u9593\u548C\u53D6\u5F97\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/arc033/submissions/34641757
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Fenwick-Tree_lower_bound.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#include\
    \ <iostream>\n#line 2 \"src/dataStructure/Fenwick-Tree.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass Fenwick_Tree {\nprivate:\n   \
    \ std::vector<T> container;\n    int size;\n    int pow_two;\n\n    inline int\
    \ lsb(int x) {\n        return x & -x;\n    }\n\n    T sum(int id) {\n       \
    \ T res = 0;\n        for (int x = id ; x > 0 ; x -= lsb(x)) {\n            res\
    \ += container[x];\n        }\n\n        return res;\n    }\n\npublic:\n    Fenwick_Tree(int\
    \ n)\n        : container(n + 1, T())\n        , size(n + 1)\n        , pow_two(1\
    \ << (std::__lg(n) + 1)) {}\n\n    void add(int id, T val) {\n        for (int\
    \ x = id + 1 ; x <= size ; x += lsb(x)) {\n            container[x] += val;\n\
    \        }\n    }\n    \n    T query(int l, int r) {\n        return sum(r) -\
    \ sum(l); \n    }\n\n    int lower_bound(T val) {\n        int res = 0;\n    \
    \    for (int x = pow_two ; x > 0 ; x >>= 1) {\n            if (res + x <= size\
    \ and container[res + x] < val) {\n                val -= container[res + x];\n\
    \                res += x;\n            }\n        }\n\n        return res;\n\
    \    }\n\n    T get(int id) {\n        return container[id];\n    }\n\n};\n\n\
    }// namespace zawa\n#line 5 \"test/Fenwick-Tree_lower_bound.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n    // https://atcoder.jp/contests/arc033/submissions/34641757\n\
    \    cout << \"Hello World\" << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n#include \"../src/dataStructure/Fenwick-Tree.hpp\"\n\n\
    using namespace std;\n\nint main() {\n    // https://atcoder.jp/contests/arc033/submissions/34641757\n\
    \    cout << \"Hello World\" << endl;\n}\n"
  dependsOn:
  - src/dataStructure/Fenwick-Tree.hpp
  isVerificationFile: true
  path: test/Fenwick-Tree_lower_bound.test.cpp
  requiredBy: []
  timestamp: '2022-09-06 00:26:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Fenwick-Tree_lower_bound.test.cpp
layout: document
redirect_from:
- /verify/test/Fenwick-Tree_lower_bound.test.cpp
- /verify/test/Fenwick-Tree_lower_bound.test.cpp.html
title: test/Fenwick-Tree_lower_bound.test.cpp
---
