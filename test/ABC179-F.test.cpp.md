---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/dualSegmentTree.hpp
    title: "dualSegmentTree (\u533A\u9593\u66F4\u65B0\u4E00\u70B9\u53D6\u5F97\u30BB\
      \u30B0\u6728)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/min_monoid.hpp
    title: "min_monoid (\u6700\u5C0F\u5024\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc179/submissions/39476714
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC179-F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/utility/monoid/min_monoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct min_monoid {\n\t\
    using value_type = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::max();\n\
    \tstatic T operation(const T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t\
    }\n};\n\n};\n#line 2 \"src/dataStructure/dualSegmentTree.hpp\"\n\n#include <vector>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass dualSegmentTree\
    \ {\nprivate:\n\tusing O = typename monoid::value_type;\n\tint N;\n\tstd::vector<O>\
    \ dat;\n\n\tconstexpr int left(int v) const {\n\t\treturn v << 1;\n\t}\n\n\tconstexpr\
    \ int right(int v) const {\n\t\treturn v << 1 | 1;\n\t}\n\n\tconstexpr int parent(int\
    \ v) const {\n\t\treturn v >> 1;\n\t}\n\n\tinline void propagate(int v) {\n\t\t\
    if (left(v) < (int)dat.size()) {\n\t\t\tdat[left(v)] = monoid::operation(dat[left(v)],\
    \ dat[v]);\n\t\t}\n\t\tif (right(v) < (int)dat.size()) {\n\t\t\tdat[right(v)]\
    \ = monoid::operation(dat[right(v)], dat[v]);\n\t\t}\n\t\tdat[v] = monoid::identity;\n\
    \t}\n\n\tvoid push(int v) {\n\t\tint height = 31 - __builtin_clz(v);\n\t\tfor\
    \ (int i = height ; i >= 1 ; i--) {\n\t\t\tpropagate(v >> i);\n\t\t}\n\t}\n\n\
    public:\n\tdualSegmentTree() {}\n\tdualSegmentTree(int _N) : N(_N), dat(_N <<\
    \ 1, monoid::identity) {}\n\tdualSegmentTree(const std::vector<O>& A) : N((int)A.size()),\
    \ dat(A.size() << 1, monoid::identity) {\n\t\tfor (int i = 0 ; i < (int)A.size()\
    \ ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t}\n\n\tO operator[](int i) {\n\t\
    \tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\treturn dat[i];\n\t\
    }\n\n\tvoid set(int i, const O& value) {\n\t\tassert(0 <= i and i < N);\n\t\t\
    i += N;\n\t\tpush(i);\n\t\tdat[i] = value;\n\t}\n\n\tvoid update(int i, const\
    \ O& value) {\n\t\tassert(0 <= i and i < N);\n\t\ti += N;\n\t\tpush(i);\n\t\t\
    dat[i] = monoid::operation(dat[i], value);\n\t}\n\n\tvoid update(int l, int r,\
    \ const O& value) {\n\t\tassert(0 <= l and l < N);\n\t\tassert(l <= r and r <=\
    \ N);\n\t\tif (l == r) {\n\t\t\treturn;\n\t\t}\n\t\tl += N; r += N;\n\t\tpush(l);\
    \ push(r - 1);\n\t\tfor ( ; l < r ; l = parent(l), r = parent(r)) {\n\t\t\tif\
    \ (l & 1) {\n\t\t\t\tdat[l] = monoid::operation(dat[l], value);\n\t\t\t\tl++;\n\
    \t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tr--;\n\t\t\t\tdat[r] = monoid::operation(dat[r],\
    \ value);\n\t\t\t}\n\t\t}\n\t}\n\n\tinline std::vector<O> _dat() const {\n\t\t\
    return dat;\n\t}\n};\n\n} // namespace \n#line 5 \"test/ABC179-F.test.cpp\"\n\n\
    #include <iostream>\n#line 8 \"test/ABC179-F.test.cpp\"\n\nusing seg = zawa::dualSegmentTree<zawa::min_monoid<int>>;\n\
    \nint main() {\n\t// int N, Q; std::cin >> N >> Q;\n\t// seg R(std::vector(N -\
    \ 1, N - 1)), C(std::vector(N - 1, N - 1));\n\t// long long ans = (long long)(N\
    \ - 2) * (N - 2);\n\t// for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T, X; std::cin\
    \ >> T >> X;\n\t// \tX -= 2;\n\t// \tif (T == 1) {\n\t// \t\tans -= C[X] - 1;\n\
    \t// \t\tR.update(0, C[X], X + 1);\n\t// \t}\n\t// \telse {\n\t// \t\tans -= R[X]\
    \ - 1;\n\t// \t\tC.update(0, R[X], X + 1);\n\t// \t}\n\t// }\n\t// std::cout <<\
    \ ans << std::endl;\n\n\tstd::cout << \"Hello World\\n\";\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 179 - F Simplified Reversi\n * https://atcoder.jp/contests/abc179/submissions/39476714\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/utility/monoid/min_monoid.hpp\"\n#include \"../src/dataStructure/dualSegmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nusing seg = zawa::dualSegmentTree<zawa::min_monoid<int>>;\n\
    \nint main() {\n\t// int N, Q; std::cin >> N >> Q;\n\t// seg R(std::vector(N -\
    \ 1, N - 1)), C(std::vector(N - 1, N - 1));\n\t// long long ans = (long long)(N\
    \ - 2) * (N - 2);\n\t// for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T, X; std::cin\
    \ >> T >> X;\n\t// \tX -= 2;\n\t// \tif (T == 1) {\n\t// \t\tans -= C[X] - 1;\n\
    \t// \t\tR.update(0, C[X], X + 1);\n\t// \t}\n\t// \telse {\n\t// \t\tans -= R[X]\
    \ - 1;\n\t// \t\tC.update(0, R[X], X + 1);\n\t// \t}\n\t// }\n\t// std::cout <<\
    \ ans << std::endl;\n\n\tstd::cout << \"Hello World\\n\";\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 179 - F Simplified Reversi\n * https://atcoder.jp/contests/abc179/submissions/39476714\n\
    \ */\n"
  dependsOn:
  - src/utility/monoid/min_monoid.hpp
  - src/dataStructure/dualSegmentTree.hpp
  isVerificationFile: true
  path: test/ABC179-F.test.cpp
  requiredBy: []
  timestamp: '2023-03-06 03:03:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC179-F.test.cpp
layout: document
redirect_from:
- /verify/test/ABC179-F.test.cpp
- /verify/test/ABC179-F.test.cpp.html
title: test/ABC179-F.test.cpp
---
