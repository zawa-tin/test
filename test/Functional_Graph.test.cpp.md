---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Functional-Graph.hpp
    title: "Functional Graph (\u30C0\u30D6\u30EA\u30F3\u30B0K\u56DE\u884C\u52D5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc030/submissions/36315830
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Functional_Graph.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/Functional-Graph.hpp\"\n\n#include <vector>\n#include\
    \ <tuple>\n\nnamespace zawa {\n\ntemplate <std::size_t log = 63>\nclass Functional_Graph\
    \ {\nprivate:\n    std::vector<int> fs;\n    std::vector<std::vector<int>> table;\n\
    \npublic:\n    Functional_Graph(const std::vector<int>& as)\n        : fs(as.begin(),\
    \ as.end())\n        , table(log, std::vector(as.size(), -1)) {\n        table[0]\
    \ = as;\n        for (std::size_t i = 0 ; i + 1 < 63 ; i++) {\n            for\
    \ (std::size_t j = 0 ; j < fs.size() ; j++) {\n                table[i + 1][j]\
    \ = table[i][table[i][j]];\n            }\n        }\n    }\n\n    inline int\
    \ f(int x) {\n        return fs[x];\n    }\n\n    int walk(int start, long long\
    \ step) {\n        int res = start;\n        for (std::size_t i = 0 ; i < log\
    \ ; i++) {\n            if (step & 1) {\n                res = table[i][res];\n\
    \            }\n            step >>= 1;\n        }\n        return res;\n    }\n\
    \n    std::tuple<int, int, int> detect(int start) {\n        std::vector used(fs.size(),\
    \ -1);\n        int step = 0;\n        int now = start;\n        for ( ; ; step++)\
    \ {\n            if (~used[now]) {\n                break;\n            }\n  \
    \          used[now] = step;\n            now = f(now);\n        }\n        return\
    \ std::tuple(used[now], now, step - used[now]);\n    }\n\n};\n\n}// namespace\
    \ zawa\n#line 4 \"test/Functional_Graph.test.cpp\"\n\n#include <iostream>\n//\
    \ #include <string>\n\nint main() {\n    // int n, a;\n    // std::cin >> n >>\
    \ a;\n    // a--;\n    // std::string k;\n    // std::cin >> k;\n    // std::vector\
    \ bs(n, 0);\n    // for (auto& b : bs) {\n    //     std::cin >> b;\n    //  \
    \   b--;\n    // }\n    // zawa::Functional_Graph fg(bs);\n    // if (k.size()\
    \ <= (size_t)18) {\n    //     std::cout << fg.walk(a, std::stoll(k)) + 1 << std::endl;\n\
    \    // }\n    // else {\n    //     auto [prev, start, size] = fg.detect(a);\n\
    \    //     int mod = 0;\n    //     for (std::size_t i = 0 ; i < k.size() ; i++)\
    \ {\n    //         mod = (10 * mod + (k[i] - '0')) % size;\n    //     }\n  \
    \  //     mod += (n / size) * size;\n    //     mod -= prev;\n    //     mod %=\
    \ size;\n    //     std::cout << fg.walk(start, mod) + 1 << std::endl;\n    //\
    \ }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Begginer\
    \ Contest 030 D \u3078\u3093\u3066\u3053\u8F9E\u66F8\n * https://atcoder.jp/contests/abc030/submissions/36315830\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/Functional-Graph.hpp\"\n\n#include <iostream>\n//\
    \ #include <string>\n\nint main() {\n    // int n, a;\n    // std::cin >> n >>\
    \ a;\n    // a--;\n    // std::string k;\n    // std::cin >> k;\n    // std::vector\
    \ bs(n, 0);\n    // for (auto& b : bs) {\n    //     std::cin >> b;\n    //  \
    \   b--;\n    // }\n    // zawa::Functional_Graph fg(bs);\n    // if (k.size()\
    \ <= (size_t)18) {\n    //     std::cout << fg.walk(a, std::stoll(k)) + 1 << std::endl;\n\
    \    // }\n    // else {\n    //     auto [prev, start, size] = fg.detect(a);\n\
    \    //     int mod = 0;\n    //     for (std::size_t i = 0 ; i < k.size() ; i++)\
    \ {\n    //         mod = (10 * mod + (k[i] - '0')) % size;\n    //     }\n  \
    \  //     mod += (n / size) * size;\n    //     mod -= prev;\n    //     mod %=\
    \ size;\n    //     std::cout << fg.walk(start, mod) + 1 << std::endl;\n    //\
    \ }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Begginer\
    \ Contest 030 D \u3078\u3093\u3066\u3053\u8F9E\u66F8\n * https://atcoder.jp/contests/abc030/submissions/36315830\n\
    \ */\n"
  dependsOn:
  - src/graph/Functional-Graph.hpp
  isVerificationFile: true
  path: test/Functional_Graph.test.cpp
  requiredBy: []
  timestamp: '2022-11-08 10:55:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Functional_Graph.test.cpp
layout: document
redirect_from:
- /verify/test/Functional_Graph.test.cpp
- /verify/test/Functional_Graph.test.cpp.html
title: test/Functional_Graph.test.cpp
---
