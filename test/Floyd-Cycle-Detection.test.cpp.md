---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/Floyd-Cycle-Detection.hpp
    title: "Floyd's Cycle Detection (\u30D5\u30ED\u30A4\u30C9\u306E\u5FAA\u74B0\u691C\
      \u51FA\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc167/submissions/35438785
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/Floyd-Cycle-Detection.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line 2\
    \ \"src/algorithm/Floyd-Cycle-Detection.hpp\"\n\nnamespace zawa::impl {\n\ntemplate\
    \ <class T>\nstruct Cycle_Info {\n    T start;\n    int length;\n};\n\n} // namespace\
    \ zawa::impl\n\nnamespace zawa {\n\ntemplate <class T, class F>\nimpl::Cycle_Info<T>\
    \ floyd(T s, const F& nxt, int limit = 50000000) {\n    T turtle = s, rabbit =\
    \ s;\n    int check = 0;\n    for ( ; check < limit ; check++) {\n        turtle\
    \ = nxt(turtle);\n        rabbit = nxt(nxt(rabbit));\n        if (turtle == rabbit)\
    \ {\n            break;\n        }\n    }\n    if (check == limit) {\n       \
    \ return { s, -1 };\n    }\n    rabbit = s;\n    while (1) {\n        rabbit =\
    \ nxt(rabbit);\n        turtle = nxt(turtle);\n        if (rabbit == turtle) {\n\
    \            break;\n        }\n    }\n    T start = turtle;\n    int length =\
    \ 0;\n    while (1) {\n        length++;\n        turtle = nxt(turtle);\n    \
    \    rabbit = nxt(nxt(rabbit));\n        if (turtle == rabbit) {\n           \
    \ break;\n        }\n    }\n    return { start, length };\n}\n\n} // namespace\
    \ zawa\n#line 4 \"test/Floyd-Cycle-Detection.test.cpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    // https://atcoder.jp/contests/abc167/submissions/35438785\n\
    \n    // int n;\n    // std::cin >> n;\n    // long long k;\n    // std::cin >>\
    \ k;\n    // std::vector as(n, 0);\n    // for (auto& a : as) {\n    //     std::cin\
    \ >> a;\n    //     a--;\n    // }\n    // auto nxt = [&](int now) {\n    // \
    \    return as[now];\n    // };\n    // auto info = zawa::floyd(0, nxt);\n   \
    \ // int ans = 0;\n    // while (k--) {\n    //     if (ans == info.start) {\n\
    \    //         k %= info.length;\n    //     }\n    //     ans = nxt(ans);\n\
    \    // }\n    // std::cout << ans + 1 << std::endl;\n\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/algorithm/Floyd-Cycle-Detection.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    // https://atcoder.jp/contests/abc167/submissions/35438785\n\
    \n    // int n;\n    // std::cin >> n;\n    // long long k;\n    // std::cin >>\
    \ k;\n    // std::vector as(n, 0);\n    // for (auto& a : as) {\n    //     std::cin\
    \ >> a;\n    //     a--;\n    // }\n    // auto nxt = [&](int now) {\n    // \
    \    return as[now];\n    // };\n    // auto info = zawa::floyd(0, nxt);\n   \
    \ // int ans = 0;\n    // while (k--) {\n    //     if (ans == info.start) {\n\
    \    //         k %= info.length;\n    //     }\n    //     ans = nxt(ans);\n\
    \    // }\n    // std::cout << ans + 1 << std::endl;\n\n    std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/algorithm/Floyd-Cycle-Detection.hpp
  isVerificationFile: true
  path: test/Floyd-Cycle-Detection.test.cpp
  requiredBy: []
  timestamp: '2022-10-07 03:05:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/Floyd-Cycle-Detection.test.cpp
layout: document
redirect_from:
- /verify/test/Floyd-Cycle-Detection.test.cpp
- /verify/test/Floyd-Cycle-Detection.test.cpp.html
title: test/Floyd-Cycle-Detection.test.cpp
---
