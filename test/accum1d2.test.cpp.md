---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/accum1d.hpp
    title: "accum1d (\u7D2F\u7A4D\u548C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/accum1d2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \n\n#line 2 \"src/template/accum1d.hpp\"\n\n#include <vector>\n#include <numeric>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct accum1d : std::vector<T> {\n\t\
    using vector = std::vector<T>;\n\taccum1d() {\n\t\t(*this).push_back(T());\n\t\
    }\n\taccum1d(const std::vector<T>& A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(),\
    \ A.end(), std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\
    \taccum1d(InputIterator begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\
    \t\tstd::partial_sum(begin, end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t\
    \ l, std::size_t r) {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 4 \"test/accum1d2.test.cpp\"\n\n#include <iostream>\n#line 7 \"\
    test/accum1d2.test.cpp\"\n\nint main() {\n\tstd::ios::sync_with_stdio(false);\n\
    \tstd::cin.tie(nullptr);\t\n\tint N, Q; std::cin >> N >> Q;\n\tstd::vector A(N,\
    \ 0LL);\n\tfor (auto& a : A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::accum1d S(A);\n\
    \tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint l, r; std::cin >> l >> r;\n\t\tstd::cout\
    \ << S.sum(l, r) << std::endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../src/template/accum1d.hpp\"\n\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n\tstd::ios::sync_with_stdio(false);\n\tstd::cin.tie(nullptr);\t\
    \n\tint N, Q; std::cin >> N >> Q;\n\tstd::vector A(N, 0LL);\n\tfor (auto& a :\
    \ A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::accum1d S(A);\n\tfor (int _ = 0 ; _ <\
    \ Q ; _++) {\n\t\tint l, r; std::cin >> l >> r;\n\t\tstd::cout << S.sum(l, r)\
    \ << std::endl;\n\t}\n}\n"
  dependsOn:
  - src/template/accum1d.hpp
  isVerificationFile: true
  path: test/accum1d2.test.cpp
  requiredBy: []
  timestamp: '2023-01-20 11:39:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/accum1d2.test.cpp
layout: document
redirect_from:
- /verify/test/accum1d2.test.cpp
- /verify/test/accum1d2.test.cpp.html
title: test/accum1d2.test.cpp
---
