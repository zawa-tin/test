---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/Arithmetic-Progression.hpp
    title: "Arithmetic Progression (\u7B49\u5DEE\u6570\u5217)"
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
  bundledCode: "#line 1 \"test/Arithmetic-Progression.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line\
    \ 2 \"src/math/Arithmetic-Progression.hpp\"\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nclass Arithmetic_Progression {\nprivate:\n    T first_term;\n    T common_difference;\n\
    \n    T term(T n) {\n        return first_term + (n - 1) * common_difference;\n\
    \    }\n    \n    T sum(T n) {\n        T end_term = term(n);\n        if (n &\
    \ 1) {\n            return ((first_term + end_term) / 2) * n;\n        }\n   \
    \     else {\n            return (n / 2) * (first_term + end_term);\n        }\n\
    \    }\n\npublic:\n    Arithmetic_Progression(T s, T d)\n        : first_term(s),\
    \ common_difference(d) {}\n\n    T get(T n) {\n        if (n <= 0) {\n       \
    \     return 0;\n        }\n        return term(n);\n    }\n\n    T accumulate(T\
    \ l, T r) {\n        return sum(r) - sum(l - 1);\n    }\n\n};\n\n} // namespace\
    \ zawa\n#line 4 \"test/Arithmetic-Progression.test.cpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nint main() {\n    zawa::Arithmetic_Progression arh(1, 2);\n\
    \    assert(arh.get(1) == 1);\n    assert(arh.get(2) == 3);\n    assert(arh.get(4)\
    \ == 7);\n    assert(arh.accumulate(1, 5) == 1 + 3 + 5 + 7 + 9);\n    assert(arh.accumulate(2,\
    \ 4) == 3 + 5 + 7);\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/math/Arithmetic-Progression.hpp\"\n\n#include <iostream>\n\
    #include <cassert>\n\nint main() {\n    zawa::Arithmetic_Progression arh(1, 2);\n\
    \    assert(arh.get(1) == 1);\n    assert(arh.get(2) == 3);\n    assert(arh.get(4)\
    \ == 7);\n    assert(arh.accumulate(1, 5) == 1 + 3 + 5 + 7 + 9);\n    assert(arh.accumulate(2,\
    \ 4) == 3 + 5 + 7);\n    std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/Arithmetic-Progression.hpp
  isVerificationFile: true
  path: test/Arithmetic-Progression.test.cpp
  requiredBy: []
  timestamp: '2022-10-21 16:30:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Arithmetic-Progression.test.cpp
layout: document
redirect_from:
- /verify/test/Arithmetic-Progression.test.cpp
- /verify/test/Arithmetic-Progression.test.cpp.html
title: test/Arithmetic-Progression.test.cpp
---
