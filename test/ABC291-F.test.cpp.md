---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/dualSegmentTree.hpp
    title: "dualSegmentTree (\u533A\u9593\u66F4\u65B0\u4E00\u70B9\u53D6\u5F97\u30BB\
      \u30B0\u6728)"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/bfs.hpp
    title: bfs (simple ver)
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/minMonoid.hpp
    title: "minMonoid (\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc291/submissions/39569307
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC291-F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/utility/monoid/minMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct minMonoid {\n\tusing\
    \ valueType = T;\n\tstatic constexpr valueType identity = std::numeric_limits<valueType>::max();\n\
    \tstatic valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ std::min(a, b);\n\t}\n};\n\n};\n#line 2 \"src/dataStructure/dualSegmentTree.hpp\"\
    \n\n#include <vector>\n#include <cassert>\n\nnamespace zawa {\n\ntemplate <class\
    \ monoid>\nclass dualSegmentTree {\nprivate:\n\tusing O = typename monoid::valueType;\n\
    \tint N;\n\tstd::vector<O> dat;\n\n\tconstexpr int left(int v) const {\n\t\treturn\
    \ v << 1;\n\t}\n\n\tconstexpr int right(int v) const {\n\t\treturn v << 1 | 1;\n\
    \t}\n\n\tconstexpr int parent(int v) const {\n\t\treturn v >> 1;\n\t}\n\n\tinline\
    \ void propagate(int v) {\n\t\tif (left(v) < (int)dat.size()) {\n\t\t\tdat[left(v)]\
    \ = monoid::operation(dat[left(v)], dat[v]);\n\t\t}\n\t\tif (right(v) < (int)dat.size())\
    \ {\n\t\t\tdat[right(v)] = monoid::operation(dat[right(v)], dat[v]);\n\t\t}\n\t\
    \tdat[v] = monoid::identity;\n\t}\n\n\tvoid push(int v) {\n\t\tint height = 31\
    \ - __builtin_clz(v);\n\t\tfor (int i = height ; i >= 1 ; i--) {\n\t\t\tpropagate(v\
    \ >> i);\n\t\t}\n\t}\n\npublic:\n\tdualSegmentTree() {}\n\tdualSegmentTree(int\
    \ _N) : N(_N), dat(_N << 1, monoid::identity) {}\n\tdualSegmentTree(const std::vector<O>&\
    \ A) : N((int)A.size()), dat(A.size() << 1, monoid::identity) {\n\t\tfor (int\
    \ i = 0 ; i < (int)A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t}\n\n\
    \tO operator[](int i) {\n\t\tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\
    \t\treturn dat[i];\n\t}\n\n\tvoid set(int i, const O& value) {\n\t\tassert(0 <=\
    \ i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\tdat[i] = value;\n\t}\n\n\tvoid\
    \ update(int i, const O& value) {\n\t\tassert(0 <= i and i < N);\n\t\ti += N;\n\
    \t\tpush(i);\n\t\tdat[i] = monoid::operation(dat[i], value);\n\t}\n\n\tvoid update(int\
    \ l, int r, const O& value) {\n\t\tassert(0 <= l and l < N);\n\t\tassert(l <=\
    \ r and r <= N);\n\t\tif (l == r) {\n\t\t\treturn;\n\t\t}\n\t\tl += N; r += N;\n\
    \t\tpush(l); push(r - 1);\n\t\tfor ( ; l < r ; l = parent(l), r = parent(r)) {\n\
    \t\t\tif (l & 1) {\n\t\t\t\tdat[l] = monoid::operation(dat[l], value);\n\t\t\t\
    \tl++;\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tdat[r] = monoid::operation(dat[r],\
    \ value);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline std::vector<O> _dat() const {\n\t\t\
    return dat;\n\t}\n};\n\n} // namespace \n#line 2 \"src/graph/simple/bfs.hpp\"\n\
    \n#line 4 \"src/graph/simple/bfs.hpp\"\n#include <queue>\n\nnamespace zawa {\n\
    \nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int s, int inf\
    \ = 2e9) {\n    std::vector<int> res(G.size(), inf);\n    res[s] = 0;\n    std::queue<int>\
    \ que({ s });\n    while (que.size()) {\n        int v = que.front();\n      \
    \  que.pop();\n        for (auto x : G[v]) {\n            if (res[x] > res[v]\
    \ + 1) {\n                res[x] = res[v] + 1;\n                que.push(x);\n\
    \            }\n        }\n    }\n    return res;\n}\n\n} // namespace zawa\n\
    #line 6 \"test/ABC291-F.test.cpp\"\n\n#include <iostream>\n#include <string>\n\
    #line 10 \"test/ABC291-F.test.cpp\"\n\nint main() {\n\t// int N, M; std::cin >>\
    \ N >> M;\n\t// std::vector G(N, std::vector(0, 0));\n\t// std::vector R(N, std::vector(0,\
    \ 0));\n\t// for (int i = 0 ; i < N ; i++) {\n\t// \tstd::string S; std::cin >>\
    \ S;\n\t// \tfor (int j = 0 ; j < M ; j++) {\n\t// \t\tif (S[j] == '1') {\n\t\
    // \t\t\tG[i].push_back(i + j + 1);\n\t// \t\t\tR[i + j + 1].push_back(i);\n\t\
    // \t\t}\n\t// \t}\n\t// }\n\t// const int sup = 1e7;\n\t// auto F = zawa::bfs(G,\
    \ 0, sup);\n\t// auto B = zawa::bfs(R, N - 1, sup);\n\t// zawa::dualSegmentTree<zawa::minMonoid<int>>\
    \ S(std::vector(N, sup));\n\t// for (int v = 0 ; v < N ; v++) {\n\t// \tfor (auto\
    \ x : G[v]) {\n\t// \t\tS.update(v + 1, x, F[v] + B[x] + 1);\n\t// \t}\n\t// }\n\
    \t// for (int i = 1 ; i + 1 < N ; i++) {\n\t// \tstd::cout << (S[i] == sup ? -1\
    \ : S[i])  << (i + 1 == N - 1 ? '\\n' : ' ');\n\t// }\n\n\tstd::cout << \"Hello\
    \ World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 291 - F Teleporter\
    \ and Closed off\n * https://atcoder.jp/contests/abc291/submissions/39569307\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/utility/monoid/minMonoid.hpp\"\n#include \"../src/dataStructure/dualSegmentTree.hpp\"\
    \n#include \"../src/graph/simple/bfs.hpp\"\n\n#include <iostream>\n#include <string>\n\
    #include <vector>\n\nint main() {\n\t// int N, M; std::cin >> N >> M;\n\t// std::vector\
    \ G(N, std::vector(0, 0));\n\t// std::vector R(N, std::vector(0, 0));\n\t// for\
    \ (int i = 0 ; i < N ; i++) {\n\t// \tstd::string S; std::cin >> S;\n\t// \tfor\
    \ (int j = 0 ; j < M ; j++) {\n\t// \t\tif (S[j] == '1') {\n\t// \t\t\tG[i].push_back(i\
    \ + j + 1);\n\t// \t\t\tR[i + j + 1].push_back(i);\n\t// \t\t}\n\t// \t}\n\t//\
    \ }\n\t// const int sup = 1e7;\n\t// auto F = zawa::bfs(G, 0, sup);\n\t// auto\
    \ B = zawa::bfs(R, N - 1, sup);\n\t// zawa::dualSegmentTree<zawa::minMonoid<int>>\
    \ S(std::vector(N, sup));\n\t// for (int v = 0 ; v < N ; v++) {\n\t// \tfor (auto\
    \ x : G[v]) {\n\t// \t\tS.update(v + 1, x, F[v] + B[x] + 1);\n\t// \t}\n\t// }\n\
    \t// for (int i = 1 ; i + 1 < N ; i++) {\n\t// \tstd::cout << (S[i] == sup ? -1\
    \ : S[i])  << (i + 1 == N - 1 ? '\\n' : ' ');\n\t// }\n\n\tstd::cout << \"Hello\
    \ World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 291 - F Teleporter\
    \ and Closed off\n * https://atcoder.jp/contests/abc291/submissions/39569307\n\
    \ */\n"
  dependsOn:
  - src/utility/monoid/minMonoid.hpp
  - src/dataStructure/dualSegmentTree.hpp
  - src/graph/simple/bfs.hpp
  isVerificationFile: true
  path: test/ABC291-F.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 16:58:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC291-F.test.cpp
layout: document
redirect_from:
- /verify/test/ABC291-F.test.cpp
- /verify/test/ABC291-F.test.cpp.html
title: test/ABC291-F.test.cpp
---
