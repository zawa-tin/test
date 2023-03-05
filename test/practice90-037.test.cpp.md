---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/dualSegmentTree.hpp
    title: "dualSegmentTree (\u533A\u9593\u66F4\u65B0\u4E00\u70B9\u53D6\u5F97\u30BB\
      \u30B0\u6728)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/max_monoid.hpp
    title: "max_monoid (\u6700\u5927\u5024\u30E2\u30CE\u30A4\u30C9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/typical90/submissions/39476719
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/practice90-037.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/dualSegmentTree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass dualSegmentTree\
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
    return dat;\n\t}\n};\n\n} // namespace \n#line 2 \"src/utility/monoid/max_monoid.hpp\"\
    \n\n#include <algorithm>\n#include <limits>\n\nnamespace zawa {\n\ntemplate <class\
    \ T>\nstruct max_monoid {\n\tusing value_type = T;\n\tstatic constexpr T identity\
    \ = std::numeric_limits<T>::min();\n\tstatic T operation(const T& a, const T&\
    \ b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\n};\n#line 5 \"test/practice90-037.test.cpp\"\
    \n\n#line 7 \"test/practice90-037.test.cpp\"\n#include <iostream>\n#line 9 \"\
    test/practice90-037.test.cpp\"\n\nusing seg = zawa::dualSegmentTree<zawa::max_monoid<long\
    \ long>>;\nconst long long inf = zawa::max_monoid<long long>::identity;\n\nint\
    \ main() {\n\t// int W, N; std::cin >> W >> N;\n\t// std::vector dp(W + 1, inf);\n\
    \t// dp[0] = 0LL;\n\t// for (int _ = 0 ; _ < N ; _++) {\n\t// \tint L, R, V; std::cin\
    \ >> L >> R >> V;\n\t// \tR++;\n\t// \tseg S(W + 1);\n\t// \tfor (int i = 0 ;\
    \ i + L <= W ; i++) {\n\t// \t\tif (dp[i] != inf) {\n\t// \t\t\tS.update(i + L,\
    \ std::min(i + R, W + 1), dp[i] + V);\n\t// \t\t}\n\t// \t}\n\t// \tfor (int i\
    \ = 0 ; i <= W ; i++) {\n\t// \t\tdp[i] = std::max(dp[i], S[i]);\n\t// \t}\n\t\
    // }\n\t// std::cout << (dp[W] == inf ? -1LL : dp[W]) << std::endl;\n\n\tstd::cout\
    \ << \"Hello World\" << std::endl;\n}\n\n/*\n * \u7AF6\u30D7\u30ED\u5178\u578B\
    90\u554F - 037 Don't Leave the Spice\n * https://atcoder.jp/contests/typical90/submissions/39476719\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/dualSegmentTree.hpp\"\n#include \"../src/utility/monoid/max_monoid.hpp\"\
    \n\n#include <vector>\n#include <iostream>\n#include <algorithm>\n\nusing seg\
    \ = zawa::dualSegmentTree<zawa::max_monoid<long long>>;\nconst long long inf =\
    \ zawa::max_monoid<long long>::identity;\n\nint main() {\n\t// int W, N; std::cin\
    \ >> W >> N;\n\t// std::vector dp(W + 1, inf);\n\t// dp[0] = 0LL;\n\t// for (int\
    \ _ = 0 ; _ < N ; _++) {\n\t// \tint L, R, V; std::cin >> L >> R >> V;\n\t// \t\
    R++;\n\t// \tseg S(W + 1);\n\t// \tfor (int i = 0 ; i + L <= W ; i++) {\n\t//\
    \ \t\tif (dp[i] != inf) {\n\t// \t\t\tS.update(i + L, std::min(i + R, W + 1),\
    \ dp[i] + V);\n\t// \t\t}\n\t// \t}\n\t// \tfor (int i = 0 ; i <= W ; i++) {\n\
    \t// \t\tdp[i] = std::max(dp[i], S[i]);\n\t// \t}\n\t// }\n\t// std::cout << (dp[W]\
    \ == inf ? -1LL : dp[W]) << std::endl;\n\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * \u7AF6\u30D7\u30ED\u5178\u578B90\u554F - 037 Don't Leave the Spice\n\
    \ * https://atcoder.jp/contests/typical90/submissions/39476719\n */\n"
  dependsOn:
  - src/dataStructure/dualSegmentTree.hpp
  - src/utility/monoid/max_monoid.hpp
  isVerificationFile: true
  path: test/practice90-037.test.cpp
  requiredBy: []
  timestamp: '2023-03-06 03:03:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/practice90-037.test.cpp
layout: document
redirect_from:
- /verify/test/practice90-037.test.cpp
- /verify/test/practice90-037.test.cpp.html
title: test/practice90-037.test.cpp
---
