---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Cyclic-Permutation.hpp
    title: "Cyclic Permutation(\u5DE1\u56DE\u7F6E\u63DB\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D
  bundledCode: "#line 1 \"test/aoj_alds_6_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D\"\
    \n\n#include <iostream>\n#line 2 \"src/algorithm/Cyclic-Permutation.hpp\"\n\n\
    #include <vector>\n#include <algorithm>\n\nnamespace zawa {\n\n    template <typename\
    \ T>\n    std::vector<std::vector<int>> decomp_cyclic_permutation(std::vector<T>&\
    \ arr) {\n        std::vector<std::pair<T, int>> cp(arr.size());\n        for\
    \ (int i = 0 ; i < (int)arr.size() ; i++) {\n            cp[i] = {arr[i], i};\n\
    \        }\n        sort(cp.begin(), cp.end());\n\n        std::vector<std::vector<int>>\
    \ res;\n        std::vector<int> used(arr.size());\n        for (int i = 0 ; i\
    \ < (int)arr.size() ; i++) {\n            if (used[i]) continue;\n           \
    \ std::vector<int> cycle;\n            int now = i;\n            while(!used[now])\
    \ {\n                cycle.emplace_back(now);\n                used[now] = 1;\n\
    \                now = cp[now].second;\n            }\n            res.emplace_back(cycle);\n\
    \        }\n\n        return res;\n    }\n\n}// namespace zawa\n#line 5 \"test/aoj_alds_6_D.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> ws(n);\n\
    \    for (auto& w : ws) std::cin >> w;\n    int allmin = 1000000;\n    for (auto\
    \ w : ws) allmin = std::min(allmin, w);\n    auto cycles = zawa::decomp_cyclic_permutation(ws);\n\
    \    int ans = 0;\n\n    for (auto cycle : cycles) {\n        int inval = 0;\n\
    \        int outval = 0;\n        int inmin = 1000000;\n        for (auto c :\
    \ cycle) inmin = std::min(inmin, ws[c]);\n        for (auto c : cycle) inval +=\
    \ ws[c];\n        inval += inmin * (cycle.size() - 2);\n        for (auto c :\
    \ cycle) outval += ws[c];\n        outval -= inmin;\n        outval += allmin\
    \ * (cycle.size() - 1);\n        outval += 2 * (allmin + inmin);\n        ans\
    \ += std::min(outval, inval);\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/6/ALDS1_6_D\"\
    \n\n#include <iostream>\n#include \"../src/algorithm/Cyclic-Permutation.hpp\"\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> ws(n);\n\
    \    for (auto& w : ws) std::cin >> w;\n    int allmin = 1000000;\n    for (auto\
    \ w : ws) allmin = std::min(allmin, w);\n    auto cycles = zawa::decomp_cyclic_permutation(ws);\n\
    \    int ans = 0;\n\n    for (auto cycle : cycles) {\n        int inval = 0;\n\
    \        int outval = 0;\n        int inmin = 1000000;\n        for (auto c :\
    \ cycle) inmin = std::min(inmin, ws[c]);\n        for (auto c : cycle) inval +=\
    \ ws[c];\n        inval += inmin * (cycle.size() - 2);\n        for (auto c :\
    \ cycle) outval += ws[c];\n        outval -= inmin;\n        outval += allmin\
    \ * (cycle.size() - 1);\n        outval += 2 * (allmin + inmin);\n        ans\
    \ += std::min(outval, inval);\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Cyclic-Permutation.hpp
  isVerificationFile: true
  path: test/aoj_alds_6_D.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 20:12:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_alds_6_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_alds_6_D.test.cpp
- /verify/test/aoj_alds_6_D.test.cpp.html
title: test/aoj_alds_6_D.test.cpp
---
