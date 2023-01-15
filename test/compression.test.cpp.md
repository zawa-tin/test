---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/compression.hpp
    title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc036/submissions/38081572
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/compression.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/algorithm/compression.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass compression {\nprivate:\n\tstd::vector<T>\
    \ as;\n\tstd::vector<T> uniqued;\n\npublic:\n\tcompression(const std::vector<T>&\
    \ as) : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(), uniqued.end());\n\
    \t\tuniqued.erase(std::unique(uniqued.begin(), uniqued.end()), uniqued.end());\n\
    \t}\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n#line 4 \"test/compression.test.cpp\"\n\n#line\
    \ 6 \"test/compression.test.cpp\"\n#include <iostream>\n\nint main() {\n\t// int\
    \ n; std::cin >> n;\n\t// std::vector as(n, 0);\n\t// for (auto& a : as) {\n\t\
    // \tstd::cin >> a;\n\t// }\n\t// zawa::compression comp(as);\n\t// for (int i\
    \ = 0 ; i < n ; i++) {\n\t// \tstd::cout << comp.get(i) << std::endl;\n\t// }\n\
    \tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest\
    \ 036 - C \u5EA7\u5727\n * https://atcoder.jp/contests/abc036/submissions/38081572\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/compression.hpp\"\n\n#include <vector>\n#include\
    \ <iostream>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector as(n,\
    \ 0);\n\t// for (auto& a : as) {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::compression\
    \ comp(as);\n\t// for (int i = 0 ; i < n ; i++) {\n\t// \tstd::cout << comp.get(i)\
    \ << std::endl;\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 036 - C \u5EA7\u5727\n * https://atcoder.jp/contests/abc036/submissions/38081572\n\
    \ */\n"
  dependsOn:
  - src/algorithm/compression.hpp
  isVerificationFile: true
  path: test/compression.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 00:44:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/compression.test.cpp
layout: document
redirect_from:
- /verify/test/compression.test.cpp
- /verify/test/compression.test.cpp.html
title: test/compression.test.cpp
---
