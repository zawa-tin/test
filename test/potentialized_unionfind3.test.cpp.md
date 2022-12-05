---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/potentialized_unionfind.hpp
    title: "potentialized_unionfind (\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\
      Union Find\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc280/submissions/37034669
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/potentialized_unionfind3.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\n\n#line\
    \ 2 \"src/dataStructure/potentialized_unionfind.hpp\"\n\n#include <vector>\n#include\
    \ <utility>\n\nnamespace zawa {\n\ntemplate <class cost_type>\nclass potentialized_unionfind\
    \ {\nprivate:\n    std::vector<int> parents;\n    std::vector<int> sizes;\n  \
    \  std::vector<cost_type> weights;\n\n    int rooting(int x) {\n        if (parents[x]\
    \ == x) {\n            return x;\n        }\n        else {\n            int root\
    \ = rooting(parents[x]);\n            weights[x] += weights[parents[x]];\n   \
    \         return parents[x] = root;\n        }\n    }\n\n    cost_type get_weight(int\
    \ x) {\n        rooting(x);\n        return weights[x];\n    }\n\npublic:\n\n\
    \    potentialized_unionfind(std::size_t n) : parents(n, 0), sizes(n, 1), weights(n)\
    \ {\n        for (std::size_t i = 0 ; i < n ; i++) {\n            parents[i] =\
    \ i;\n        }\n    }\n\n    int leader(int x) {\n        return rooting(x);\n\
    \    }\n\n    bool same(int x, int y) {\n        return rooting(x) == rooting(y);\n\
    \    }\n\n    bool merge(int x, int y, cost_type w) {\n        w += get_weight(x);\n\
    \        w -= get_weight(y);\n        int rx = rooting(x), ry = rooting(y);\n\
    \        if (rx == ry) {\n            return false;\n        }\n        if (sizes[rx]\
    \ < sizes[ry]) {\n            std::swap(rx, ry);\n            w *= -1;\n     \
    \   }\n        sizes[rx] += sizes[ry];\n        parents[ry] = rx;\n        weights[ry]\
    \ = w;\n        return true;\n    }\n\n    cost_type diff(int y, int x) {\n  \
    \      return get_weight(y) - get_weight(x);\n    }\n};\n\n} // namespace zawa\n\
    #line 4 \"test/potentialized_unionfind3.test.cpp\"\n\n#include <iostream>\n\n\
    int main() {\n    // int n, m, q; std::cin >> n >> m >> q;\n    // zawa::potentialized_unionfind<long\
    \ long> uf(n);\n    // std::vector infs(n, false);\n    // for (int _ = 0 ; _\
    \ < m ; _++) {\n    //     int a, b, c; std::cin >> a >> b >> c;\n    //     a--;\
    \ b--;\n    //     if (uf.same(a, b)) {\n    //         if (uf.diff(b, a) != c)\
    \ {\n    //             infs[uf.leader(a)] = true;\n    //         }\n    // \
    \    }\n    //     else {\n    //         bool ng = false;\n    //         if\
    \ (infs[uf.leader(a)] or infs[uf.leader(b)]) {\n    //             ng = true;\n\
    \    //         }\n    //         uf.merge(a, b, c);\n    //         if (ng) {\n\
    \    //             infs[uf.leader(a)] = true;\n    //         }\n    //     }\n\
    \    // }\n    // for (int _ = 0 ; _ < q ; _++) {\n    //     int x, y; std::cin\
    \ >> x >> y;\n    //     x--; y--;\n    //     if (!uf.same(x, y)) {\n    // \
    \        std::cout << \"nan\" << std::endl;\n    //     }\n    //     else if\
    \ (infs[uf.leader(x)]) {\n    //         std::cout << \"inf\" << std::endl;\n\
    \    //     }\n    //     else {\n    //         std::cout << uf.diff(y, x) <<\
    \ std::endl;\n    //     }\n    // }\n\n    std::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 280 - F Pay or Receive\n * https://atcoder.jp/contests/abc280/submissions/37034669\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/potentialized_unionfind.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    // int n, m, q; std::cin >> n >> m >> q;\n \
    \   // zawa::potentialized_unionfind<long long> uf(n);\n    // std::vector infs(n,\
    \ false);\n    // for (int _ = 0 ; _ < m ; _++) {\n    //     int a, b, c; std::cin\
    \ >> a >> b >> c;\n    //     a--; b--;\n    //     if (uf.same(a, b)) {\n   \
    \ //         if (uf.diff(b, a) != c) {\n    //             infs[uf.leader(a)]\
    \ = true;\n    //         }\n    //     }\n    //     else {\n    //         bool\
    \ ng = false;\n    //         if (infs[uf.leader(a)] or infs[uf.leader(b)]) {\n\
    \    //             ng = true;\n    //         }\n    //         uf.merge(a, b,\
    \ c);\n    //         if (ng) {\n    //             infs[uf.leader(a)] = true;\n\
    \    //         }\n    //     }\n    // }\n    // for (int _ = 0 ; _ < q ; _++)\
    \ {\n    //     int x, y; std::cin >> x >> y;\n    //     x--; y--;\n    //  \
    \   if (!uf.same(x, y)) {\n    //         std::cout << \"nan\" << std::endl;\n\
    \    //     }\n    //     else if (infs[uf.leader(x)]) {\n    //         std::cout\
    \ << \"inf\" << std::endl;\n    //     }\n    //     else {\n    //         std::cout\
    \ << uf.diff(y, x) << std::endl;\n    //     }\n    // }\n\n    std::cout << \"\
    Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 280 - F Pay\
    \ or Receive\n * https://atcoder.jp/contests/abc280/submissions/37034669\n */\n"
  dependsOn:
  - src/dataStructure/potentialized_unionfind.hpp
  isVerificationFile: true
  path: test/potentialized_unionfind3.test.cpp
  requiredBy: []
  timestamp: '2022-12-05 12:46:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/potentialized_unionfind3.test.cpp
layout: document
redirect_from:
- /verify/test/potentialized_unionfind3.test.cpp
- /verify/test/potentialized_unionfind3.test.cpp.html
title: test/potentialized_unionfind3.test.cpp
---
