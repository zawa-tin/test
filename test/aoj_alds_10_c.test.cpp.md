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
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj_alds_10_c.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n#include <cassert>\n\n#line 2 \"src/algorithm/LCS.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\n    template <typename T>\n    class\
    \ LCS {\n\n    private:\n        std::vector<T> a, b;\n        std::vector<T>\
    \ res;\n        std::vector<std::vector<int>> dp;\n        std::vector<std::vector<int>>\
    \ dir;\n\n        void make(int i, int j) {\n            if (i == 0 or j == 0)\
    \ {\n                return;\n            }\n\n            if (dir[i][j] == 3)\
    \ {\n                make(i - 1, j - 1);\n                res.emplace_back(a[i\
    \ - 1]);\n            }\n            else if (dir[i][j] == 2) {\n            \
    \    make(i - 1, j);\n            }\n            else {\n                make(i,\
    \ j - 1);\n            }\n        }\n\n    public:\n        LCS(std::vector<T>&\
    \ a, std::vector<T>& b)\n            : a(a.begin(), a.end()), \n             \
    \ b(b.begin(), b.end()), \n              dp(a.size() + 1, std::vector<int>(b.size()\
    \ + 1)), \n              dir(a.size() + 1, std::vector<int>(b.size() + 1)) {}\n\
    \n        void build() {\n            for (int i = 1 ; i < (int)a.size() + 1 ;\
    \ i++) {\n                for (int j = 1 ; j < (int)b.size() + 1 ; j++) {\n  \
    \                  if (a[i - 1] == b[j - 1]) {\n                        dp[i][j]\
    \ = dp[i - 1][j - 1] + 1;\n                        dir[i][j] = 3;\n          \
    \          }\n                    else if (dp[i - 1][j] >= dp[i][j - 1]) {\n \
    \                       dp[i][j] = dp[i - 1][j];\n                        dir[i][j]\
    \ = 2;\n                    }\n                    else {\n                  \
    \      dp[i][j] = dp[i][j - 1];\n                        dir[i][j] = 1;\n    \
    \                }\n                }\n            }\n\n            make((int)a.size(),\
    \ (int)b.size());\n        }\n\n        std::vector<T> get() {\n            return\
    \ res;\n        }\n\n        int get_size() {\n            return dp[a.size()][b.size()];\n\
    \        }\n\n    };\n\n}// namespace zawa\n#line 8 \"test/aoj_alds_10_c.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    for (int _ = 0 ; _ < n ;\
    \ _++) {\n        std::string s, t;\n        std::cin >> s >> t;\n        std::vector<char>\
    \ vs(s.size()), vt(t.size());\n        for (int i = 0 ; i < s.size() ; i++) vs[i]\
    \ = s[i];\n        for (int i = 0 ; i < t.size() ; i++) vt[i] = t[i];\n      \
    \  zawa::LCS<char> lcs(vs, vt);\n        lcs.build();\n\n        assert(lcs.get_size()\
    \ == lcs.get().size());\n\n        std::cout << lcs.get().size() << std::endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n#include <cassert>\n\n#include \"\
    ../src/algorithm/LCS.hpp\"\n\nint main() {\n    int n;\n    std::cin >> n;\n \
    \   for (int _ = 0 ; _ < n ; _++) {\n        std::string s, t;\n        std::cin\
    \ >> s >> t;\n        std::vector<char> vs(s.size()), vt(t.size());\n        for\
    \ (int i = 0 ; i < s.size() ; i++) vs[i] = s[i];\n        for (int i = 0 ; i <\
    \ t.size() ; i++) vt[i] = t[i];\n        zawa::LCS<char> lcs(vs, vt);\n      \
    \  lcs.build();\n\n        assert(lcs.get_size() == lcs.get().size());\n\n   \
    \     std::cout << lcs.get().size() << std::endl;\n    }\n}\n"
  dependsOn:
  - src/algorithm/LCS.hpp
  isVerificationFile: true
  path: test/aoj_alds_10_c.test.cpp
  requiredBy: []
  timestamp: '2022-07-30 03:20:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_alds_10_c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_alds_10_c.test.cpp
- /verify/test/aoj_alds_10_c.test.cpp.html
title: test/aoj_alds_10_c.test.cpp
---
