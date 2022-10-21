---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/LCS.hpp
    title: "LCS(\u6700\u9577\u5171\u901A\u90E8\u5206\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
    links:
    - https://atcoder.jp/contests/dp/submissions/35825710
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
  bundledCode: "#line 1 \"test/LCS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#line 2 \"src/algorithm/LCS.hpp\"\n#include <string>\n#include <vector>\n\
    #include <algorithm>\n\nnamespace zawa::impl {\n\ntemplate <class T>\nstd::vector<T>\
    \ lcs(const std::vector<T>& a, const std::vector<T>& b) {\n    std::vector dp(a.size()\
    \ + 1, std::vector(b.size() + 1, 0));\n    for (std::size_t i = 0 ; i < a.size()\
    \ ; i++) {\n        for (std::size_t j = 0 ; j < b.size() ; j++) {\n         \
    \   if (a[i] == b[j]) {\n                dp[i + 1][j + 1] = dp[i][j] + 1;\n  \
    \          }\n            else {\n                dp[i + 1][j + 1] = std::max(dp[i\
    \ + 1][j], dp[i][j + 1]);\n            }\n        }\n    }\n    std::vector<T>\
    \ res;\n    std::size_t i = a.size(), j = b.size();\n    while (dp[i][j] > 0)\
    \ {\n        if (dp[i - 1][j] == dp[i][j]) {\n            i--;\n        }\n  \
    \      else if (dp[i][j - 1] == dp[i][j]) {\n            j--;\n        }\n   \
    \     else {\n            i--;\n            j--;\n            res.emplace_back(a[i]);\n\
    \        }\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n\n}\n\nnamespace zawa {\n\ntemplate <class T>\nstd::vector<T> lcs(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    return impl::lcs(a, b);\n}\n\nstd::string\
    \ lcs(const std::string& a, const std::string& b) {\n    std::vector<char> newa(a.begin(),\
    \ a.end()), newb(b.begin(), b.end());\n    std::vector<char> reschar = impl::lcs(newa,\
    \ newb);\n    return std::string(reschar.begin(), reschar.end());\n}\n\n} // namespace\
    \ zawa\n#line 4 \"test/LCS.test.cpp\"\n#include <iostream>\n\nint main() {\n \
    \   int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        std::string\
    \ a, b; std::cin >> a >> b;\n        std::cout << zawa::lcs(a, b).size() << std::endl;\n\
    \    }\n}\n\n/*\n * EDPC-F LCS\n * https://atcoder.jp/contests/dp/submissions/35825710\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include \"../src/algorithm/LCS.hpp\"\n#include <iostream>\n\nint main() {\n\
    \    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        std::string\
    \ a, b; std::cin >> a >> b;\n        std::cout << zawa::lcs(a, b).size() << std::endl;\n\
    \    }\n}\n\n/*\n * EDPC-F LCS\n * https://atcoder.jp/contests/dp/submissions/35825710\n\
    \ */\n"
  dependsOn:
  - src/algorithm/LCS.hpp
  isVerificationFile: true
  path: test/LCS.test.cpp
  requiredBy: []
  timestamp: '2022-10-21 15:11:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/LCS.test.cpp
layout: document
redirect_from:
- /verify/test/LCS.test.cpp
- /verify/test/LCS.test.cpp.html
title: test/LCS.test.cpp
---
