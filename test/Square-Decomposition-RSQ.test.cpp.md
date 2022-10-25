---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/query/Square-Decomposition.hpp
    title: "Square Decomposition (\u5E73\u65B9\u5206\u5272)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B
  bundledCode: "#line 1 \"test/Square-Decomposition-RSQ.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\n\n#line\
    \ 2 \"src/query/Square-Decomposition.hpp\"\n\n#include <vector>\n#include <cmath>\n\
    #include <algorithm>\n#include <iostream>\n\nnamespace zawa {\n\ntemplate <class\
    \ T, T (*op)(T, T), T (*e)()>\nclass Sqrt_Decomposition {\n\nprivate:\n    int\
    \ square;\n    int size;\n    std::vector<T> data;\n    std::vector<T> bucket;\n\
    \n    T update(int id) {\n        T res = e();\n        for (int i = id * square\
    \ ; i < std::min((int)data.size(), (id + 1) * square) ; i++) {\n            res\
    \ = op(res, data[i]);\n        }\n        bucket[id] = res;\n        return res;\n\
    \    }\n\npublic:\n    Sqrt_Decomposition(int n)\n        : square(std::sqrt(n\
    \ + 1))\n        , size((n + square - 1) / square)\n        , data(n, e())\n \
    \       , bucket(size, e()) {}\n\n    Sqrt_Decomposition(std::vector<T> as)\n\
    \        : square(std::sqrt((int)as.size() + 1))\n        , size(((int)as.size()\
    \ + square - 1) / square)\n        , data(as.begin(), as.end())\n        , bucket(size,\
    \ e()) {\n\n        for (int i = 0 ; i < size ; i++) {\n            update(i);\n\
    \        }\n    }\n\n    T update(int pos, T value) {\n        data[pos] = value;\n\
    \        return update(pos / square);\n    }\n\n    T query(int l, int r) {\n\
    \        T res = e(); \n        for (int i = 0 ; i < size ; i++) {\n         \
    \   int p = i * square, q = (i + 1) * square;\n            if (q <= l and r <=\
    \ p) {\n                continue;\n            }\n            if (l <= p and q\
    \ <= r) {\n                res = op(res, bucket[i]);\n            }\n        \
    \    else {\n                for (int j = std::max(l, p) ; j < std::min(r, q)\
    \ ; j++) {\n                    res = op(res, data[j]);\n                }\n \
    \           }\n        }\n        return res;\n    }\n\n    void print_data()\
    \ {\n        for (size_t i = 0 ; i < data.size() ; i++) {\n            std::cout\
    \ << data[i] << (i == data.size() - 1 ? '\\n' : ' ');\n        }\n    }\n\n  \
    \  void print_date(int l, int r) {\n        for (int i = l ; i < r ; i++) {\n\
    \            std::cout << data.at(i) << (i == r - 1 ? '\\n' : ' ');\n        }\n\
    \    }\n    \n    void print_bucket() {\n        for (auto buc : bucket) {\n \
    \           std::cout << buc << ' ';\n        }\n        std::cout << std::endl;\n\
    \    }\n    \n    void print_bucket(int id) {\n        std::cout << bucket.at(id)\
    \ << std::endl;\n    }\n\n};\n\n} // namespace zawa\n#line 4 \"test/Square-Decomposition-RSQ.test.cpp\"\
    \n\nnamespace monoid {\n\nint op(int a, int b) {\n    return a + b;\n}\n\nint\
    \ e() {\n    return 0;\n}\n\n}\n\nusing RSQ = zawa::Sqrt_Decomposition<int, monoid::op,\
    \ monoid::e>;\n\n#line 20 \"test/Square-Decomposition-RSQ.test.cpp\"\n\nint main()\
    \ {\n    int n, q; std::cin >> n >> q;\n    std::vector<int> as(n, 0);\n    RSQ\
    \ rsq(as);\n    for (int _ = 0 ; _ < q ; _++) {\n        int com, x, y; std::cin\
    \ >> com >> x >> y;\n        if (com == 0) {\n            int nxt = as[x - 1]\
    \ + y;\n            as[x - 1] = nxt;\n            rsq.update(x - 1, nxt);\n  \
    \      }\n        if (com == 1) {\n            std::cout << rsq.query(x - 1, y)\
    \ << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B\"\
    \n\n#include \"../src/query/Square-Decomposition.hpp\"\n\nnamespace monoid {\n\
    \nint op(int a, int b) {\n    return a + b;\n}\n\nint e() {\n    return 0;\n}\n\
    \n}\n\nusing RSQ = zawa::Sqrt_Decomposition<int, monoid::op, monoid::e>;\n\n#include\
    \ <iostream>\n\nint main() {\n    int n, q; std::cin >> n >> q;\n    std::vector<int>\
    \ as(n, 0);\n    RSQ rsq(as);\n    for (int _ = 0 ; _ < q ; _++) {\n        int\
    \ com, x, y; std::cin >> com >> x >> y;\n        if (com == 0) {\n           \
    \ int nxt = as[x - 1] + y;\n            as[x - 1] = nxt;\n            rsq.update(x\
    \ - 1, nxt);\n        }\n        if (com == 1) {\n            std::cout << rsq.query(x\
    \ - 1, y) << std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/query/Square-Decomposition.hpp
  isVerificationFile: true
  path: test/Square-Decomposition-RSQ.test.cpp
  requiredBy: []
  timestamp: '2022-10-25 20:06:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Square-Decomposition-RSQ.test.cpp
layout: document
redirect_from:
- /verify/test/Square-Decomposition-RSQ.test.cpp
- /verify/test/Square-Decomposition-RSQ.test.cpp.html
title: test/Square-Decomposition-RSQ.test.cpp
---
