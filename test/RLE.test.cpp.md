---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/RLE.hpp
    title: "RLE (\u9023\u9577\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc259/submissions/35168404
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/RLE.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n// #include <algorithm>\n\n#line 2 \"src/algorithm/RLE.hpp\"\
    \n\n#include <vector>\n#include <utility>\n#include <string>\n\nnamespace zawa\
    \ {\n\ntemplate <typename T>\nstd::vector<std::pair<T, int>> rle(const std::vector<T>&\
    \ ins) {\n    std::vector<std::pair<T, int>> res;\n    for (size_t i = 0 ; i <\
    \ ins.size() ; i++) {\n        if (res.empty() or res.back().first != ins[i])\
    \ {\n            res.emplace_back(ins[i], 1);\n        }\n        else {\n   \
    \         res.back().second++;\n        }\n    }\n    return res;\n}\n\nstd::vector<std::pair<char,\
    \ int>> rle(const std::string& s) {\n    std::vector<char> in(s.begin(), s.end());\n\
    \    return rle(in);\n}\n\n} // namespace zawa\n#line 7 \"test/RLE.test.cpp\"\n\
    \nint main() {\n\n    // https://atcoder.jp/contests/abc259/submissions/35168404\n\
    \n    // std::string s, t;\n    // std::cin >> s >> t;\n    // auto rs = zawa::rle(s),\
    \ ts = zawa::rle(t);\n    // bool ans = rs.size() == ts.size();\n    // for (size_t\
    \ i = 0 ; i < std::min(rs.size(), ts.size()) ; i++) {\n    //     if (rs[i] ==\
    \ ts[i]) {\n    //         continue;\n    //     }\n    //     if (rs[i].first\
    \ != ts[i].first or rs[i].second == 1 or rs[i].second > ts[i].second) {\n    //\
    \         ans = false;\n    //     }\n    // }\n    // std::cout << (ans ? \"\
    Yes\" : \"No\") << std::endl;\n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include <iostream>\n// #include <algorithm>\n\n#include \"../src/algorithm/RLE.hpp\"\
    \n\nint main() {\n\n    // https://atcoder.jp/contests/abc259/submissions/35168404\n\
    \n    // std::string s, t;\n    // std::cin >> s >> t;\n    // auto rs = zawa::rle(s),\
    \ ts = zawa::rle(t);\n    // bool ans = rs.size() == ts.size();\n    // for (size_t\
    \ i = 0 ; i < std::min(rs.size(), ts.size()) ; i++) {\n    //     if (rs[i] ==\
    \ ts[i]) {\n    //         continue;\n    //     }\n    //     if (rs[i].first\
    \ != ts[i].first or rs[i].second == 1 or rs[i].second > ts[i].second) {\n    //\
    \         ans = false;\n    //     }\n    // }\n    // std::cout << (ans ? \"\
    Yes\" : \"No\") << std::endl;\n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/algorithm/RLE.hpp
  isVerificationFile: true
  path: test/RLE.test.cpp
  requiredBy: []
  timestamp: '2022-09-26 05:14:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/RLE.test.cpp
layout: document
redirect_from:
- /verify/test/RLE.test.cpp
- /verify/test/RLE.test.cpp.html
title: test/RLE.test.cpp
---
