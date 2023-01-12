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
    - https://atcoder.jp/contests/abc036/submissions/37955739
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/compression.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/algorithm/compression.hpp\"\n\n#include <vector>\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass compression {\nprivate:\n\tstd::vector<T>\
    \ arr;\n\tstd::vector<int> dat;\n\tstd::vector<T> invs;\n\npublic:\n\tcompression(const\
    \ std::vector<T>& arr) : arr(arr), dat(arr.size()), invs(arr.size()) {\n\t\tstd::vector\
    \ cp = arr;\n\t\tstd::sort(cp.begin(), cp.end());\t\n\t\tcp.erase(std::unique(cp.begin(),\
    \ cp.end()), cp.end());\n\t\tfor (std::size_t i = 0 ; i < arr.size() ; i++) {\n\
    \t\t\tdat[i] = std::lower_bound(cp.begin(), cp.end(), arr[i]) - cp.begin();\n\t\
    \t}\n\t\tfor (std::size_t i = 0 ; i < arr.size() ; i++) {\n\t\t\tinvs[dat[i]]\
    \ = arr[i];\n\t\t}\n\t}\n\n\tint operator [](int i) {\n\t\treturn dat[i];\n\t\
    }\n\n\tT inv(int i) {\n\t\treturn invs[i];\n\t}\n\n\tstd::vector<int> get() {\n\
    \t\treturn dat;\n\t}\n};\n\n} // namespace zawa\n#line 4 \"test/compression.test.cpp\"\
    \n\n#line 6 \"test/compression.test.cpp\"\n#include <iostream>\n\nint main() {\n\
    \t// int n; std::cin >> n;\n\t// std::vector as(n, 0);\n\t// for (auto& a : as)\
    \ {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::compression comp(as);\n\t// for\
    \ (int i = 0 ; i < n ; i++) {\n\t// \tstd::cout << comp[i] << std::endl;\n\t//\
    \ }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner\
    \ Contest 036 - C \u5EA7\u5727\n * https://atcoder.jp/contests/abc036/submissions/37955739\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/compression.hpp\"\n\n#include <vector>\n#include\
    \ <iostream>\n\nint main() {\n\t// int n; std::cin >> n;\n\t// std::vector as(n,\
    \ 0);\n\t// for (auto& a : as) {\n\t// \tstd::cin >> a;\n\t// }\n\t// zawa::compression\
    \ comp(as);\n\t// for (int i = 0 ; i < n ; i++) {\n\t// \tstd::cout << comp[i]\
    \ << std::endl;\n\t// }\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 036 - C \u5EA7\u5727\n * https://atcoder.jp/contests/abc036/submissions/37955739\n\
    \ */\n"
  dependsOn:
  - src/algorithm/compression.hpp
  isVerificationFile: true
  path: test/compression.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 15:11:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/compression.test.cpp
layout: document
redirect_from:
- /verify/test/compression.test.cpp
- /verify/test/compression.test.cpp.html
title: test/compression.test.cpp
---
