---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Count-Inversion-Number.hpp
    title: "Count-Inversion-Number(\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u306B\u3088\
      \u308B\u8EE2\u5012\u6570\u306E\u6570\u3048\u4E0A\u3052)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D
  bundledCode: "#line 1 \"test/aoj_alds_5_d.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\
    \n\n#line 2 \"src/algorithm/Count-Inversion-Number.hpp\"\n\n#include <vector>\n\
    \nnamespace zawa {\n\n    template <typename T>\n    class Count_Inversion_Number\
    \ {\n    private:\n        std::vector<T> arr;\n        long long count_inversion_number\
    \ = 0;\n\n        long long sort(int left, int right) {\n            if (right\
    \ - left == 1) return 0LL;\n\n            long long res = 0;\n            int\
    \ mid = left + (right - left) / 2;\n            \n            res += sort(left,\
    \ mid);\n            res += sort(mid, right);\n\n            std::vector<T> fronts(arr.begin()\
    \ + left, arr.begin() + mid);\n            std::vector<T> backs(arr.begin() +\
    \ mid, arr.begin() + right);\n\n            int front_idx = 0, back_idx = 0;\n\
    \            for (int i = left ; i < right ; i++) {\n                if (front_idx\
    \ < (int)fronts.size() and \n                        (back_idx == (int)backs.size()\
    \ or fronts[front_idx] <= backs[back_idx])) {\n                    arr[i] = fronts[front_idx++];\n\
    \                }\n                else {\n                    arr[i] = backs[back_idx++];\n\
    \                    res += mid - left - front_idx;\n                }\n     \
    \       }\n\n            return res;\n        }\n    \n    public:\n        Count_Inversion_Number(std::vector<T>&\
    \ arr) : arr(arr.begin(), arr.end()) {}\n\n        void build() {\n          \
    \  count_inversion_number = sort(0, (int)arr.size());\n        }\n\n        long\
    \ long get() {\n            return count_inversion_number;\n        }\n\n    \
    \    std::vector<T> get_sorted() {\n            return arr;\n        }\n    };\n\
    \n} // namespace zawa\n#line 4 \"test/aoj_alds_5_d.test.cpp\"\n#include <iostream>\n\
    \nint main() {\n    int n; std::cin >> n;\n    std::vector<int> as(n);\n    for\
    \ (auto& a : as) std::cin >> a;\n    zawa::Count_Inversion_Number inv(as);\n \
    \   inv.build();\n    std::cout << inv.get() << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D\"\n\
    \n#include \"../src/algorithm/Count-Inversion-Number.hpp\"\n#include <iostream>\n\
    \nint main() {\n    int n; std::cin >> n;\n    std::vector<int> as(n);\n    for\
    \ (auto& a : as) std::cin >> a;\n    zawa::Count_Inversion_Number inv(as);\n \
    \   inv.build();\n    std::cout << inv.get() << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Count-Inversion-Number.hpp
  isVerificationFile: true
  path: test/aoj_alds_5_d.test.cpp
  requiredBy: []
  timestamp: '2022-07-25 00:17:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj_alds_5_d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj_alds_5_d.test.cpp
- /verify/test/aoj_alds_5_d.test.cpp.html
title: test/aoj_alds_5_d.test.cpp
---
