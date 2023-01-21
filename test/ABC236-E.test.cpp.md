---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template/binary-search-ld.hpp
    title: "binary-seach-ld (\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u4E8C\u5206\u63A2\
      \u7D22)"
  - icon: ':heavy_check_mark:'
    path: src/template/binary-search.hpp
    title: "binary-seach (\u6574\u6570\u4E8C\u5206\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc236/submissions/38188196
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC236-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/template/binary-search-ld.hpp\"\n\n#include <cstddef>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class F, std::size_t up = 80>\nT binary_search_ld(T\
    \ ok, T ng, const F& f) {\n\tfor (std::size_t _ = 0 ; _ < up ; _++) {\n\t\tT mid\
    \ = (ok + ng) / 2;\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\
    \tng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n#line 2 \"src/template/binary-search.hpp\"\
    \n\n#include <cmath>\n\nnamespace zawa {\n\ntemplate <class T, class F>\nT binary_search(T\
    \ ok, T ng, const F& f) {\n\twhile (std::abs(ok - ng) > 1) {\n\t\tT mid = ((ok\
    \ + ng) >> 1);\n\t\tif (f(mid)) {\n\t\t\tok = mid;\n\t\t}\n\t\telse {\n\t\t\t\
    ng = mid;\n\t\t}\n\t}\n\treturn ok;\n}\n\n}\n#line 5 \"test/ABC236-E.test.cpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n#include <algorithm>\n\
    #include <functional>\n\n// const int sup = 1e9 + 10;\n// \n// template <class\
    \ T>\n// T maximize(const std::vector<T>& A) {\n// \tT s = 0, t = 0;\n// \tfor\
    \ (const T& a : A) {\n// \t\tconst T u = std::max(s, t) + a;\n// \t\ts = t;\n\
    // \t\tt = u;\n// \t}\n// \treturn std::max(s, t);\n// }\n\nint main() {\n\t//\
    \ int N; std::cin >> N;\n\t// std::vector A(N, 0);\n\t// for (auto& a : A) {\n\
    \t// \tstd::cin >> a;\n\t// }\n\t// auto f = [&](long double p) -> bool {\n\t\
    // \tstd::vector B(N, (long double)0.0);\n\t// \tfor (int i = 0 ; i < N ; i++)\
    \ {\n\t// \t\tB[i] = A[i] - p;\n\t// \t}\n\t// \treturn maximize(B) >= 0.0l;\n\
    \t// };\n\t// std::cout << std::fixed << std::setprecision(4);\n\t// std::cout\
    \ << zawa::binary_search_ld(1.0l, 1e9 + 1.0l, f) << std::endl;\n\t// auto g =\
    \ [&](int p) -> bool {\n\t// \tstd::vector B(N, 0);\n\t// \tfor (int i = 0 ; i\
    \ < N ; i++) {\n\t// \t\tB[i] = (A[i] >= p ? 1 : -1);\n\t// \t}\n\t// \treturn\
    \ maximize(B) > 0;\n\t// };\n\t// std::cout << zawa::binary_search(1, (int)1e9\
    \ + 1, g) << std::endl;\n\t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\
    \n/*\n * AtCoder Beginner Contest 236\n * https://atcoder.jp/contests/abc236/submissions/38188196\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/template/binary-search-ld.hpp\"\n#include \"../src/template/binary-search.hpp\"\
    \n\n#include <iostream>\n#include <iomanip>\n#include <vector>\n#include <algorithm>\n\
    #include <functional>\n\n// const int sup = 1e9 + 10;\n// \n// template <class\
    \ T>\n// T maximize(const std::vector<T>& A) {\n// \tT s = 0, t = 0;\n// \tfor\
    \ (const T& a : A) {\n// \t\tconst T u = std::max(s, t) + a;\n// \t\ts = t;\n\
    // \t\tt = u;\n// \t}\n// \treturn std::max(s, t);\n// }\n\nint main() {\n\t//\
    \ int N; std::cin >> N;\n\t// std::vector A(N, 0);\n\t// for (auto& a : A) {\n\
    \t// \tstd::cin >> a;\n\t// }\n\t// auto f = [&](long double p) -> bool {\n\t\
    // \tstd::vector B(N, (long double)0.0);\n\t// \tfor (int i = 0 ; i < N ; i++)\
    \ {\n\t// \t\tB[i] = A[i] - p;\n\t// \t}\n\t// \treturn maximize(B) >= 0.0l;\n\
    \t// };\n\t// std::cout << std::fixed << std::setprecision(4);\n\t// std::cout\
    \ << zawa::binary_search_ld(1.0l, 1e9 + 1.0l, f) << std::endl;\n\t// auto g =\
    \ [&](int p) -> bool {\n\t// \tstd::vector B(N, 0);\n\t// \tfor (int i = 0 ; i\
    \ < N ; i++) {\n\t// \t\tB[i] = (A[i] >= p ? 1 : -1);\n\t// \t}\n\t// \treturn\
    \ maximize(B) > 0;\n\t// };\n\t// std::cout << zawa::binary_search(1, (int)1e9\
    \ + 1, g) << std::endl;\n\t\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\
    \n/*\n * AtCoder Beginner Contest 236\n * https://atcoder.jp/contests/abc236/submissions/38188196\n\
    \ */\n"
  dependsOn:
  - src/template/binary-search-ld.hpp
  - src/template/binary-search.hpp
  isVerificationFile: true
  path: test/ABC236-E.test.cpp
  requiredBy: []
  timestamp: '2023-01-21 19:38:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC236-E.test.cpp
layout: document
redirect_from:
- /verify/test/ABC236-E.test.cpp
- /verify/test/ABC236-E.test.cpp.html
title: test/ABC236-E.test.cpp
---
