---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/segmentTree.hpp
    title: "segmentTree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
      \u6728)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/max.hpp
    title: "max\u30E2\u30CE\u30A4\u30C9"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/practice2/submissions/38935945
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ALPC-J.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/utility/monoid/max.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct max_monoid {\n\tusing value_type\
    \ = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::min();\n\tstatic\
    \ T operation(const T& a, const T& b) {\n\t\treturn std::max(a, b);\n\t}\n};\n\
    \n};\n#line 2 \"src/dataStructure/segmentTree.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class monoid>\nclass segmentTree {\nprivate:\n\tusing T\
    \ = typename monoid::value_type;\n\tstd::size_t N;\n\tstd::vector<T> dat;\n\n\
    public:\n\tsegmentTree() {}\n\tsegmentTree(int _N) : N(_N), dat(2 * _N, monoid::identity)\
    \ {}\n\tsegmentTree(const std::vector<T>& A) : N(A.size()), dat(2 * N, monoid::identity)\
    \ {\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\
    \t\t}\n\t\tfor (std::size_t i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i\
    \ << 1], dat[i << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const\
    \ T& value) {\n\t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\
    \t\t\tdat[pos] = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\
    \t}\n\n\tT action(std::size_t pos, const T& value) {\n\t\tpos += N;\n\t\tdo {\n\
    \t\t\tdat[pos] = monoid::operation(dat[pos], value);\n\t\t} while (pos >>= 1);\n\
    \t\treturn dat[pos];\n\t}\n\n\tT prod(std::size_t l, std::size_t r) const {\n\t\
    \tT left = monoid::identity, right = monoid::identity;\n\t\tfor (l += N, r +=\
    \ N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\t\tleft = monoid::operation(left,\
    \ dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\t\t\t\tright = monoid::operation(dat[--r],\
    \ right);\n\t\t\t}\n\t\t}\n\t\treturn monoid::operation(left, right);\n\t}\n\n\
    \ttemplate <class func>\n\tint maxRight(int l, const func& f) const {\n\t\tint\
    \ L = l + N, w = 1;\n\t\tT v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N\
    \ ; L >>= 1, w <<= 1) {\n\t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v,\
    \ dat[L]))) {\n\t\t\t\t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile\
    \ (L <<= 1, w >>= 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L])))\
    \ {\n\t\t\t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\
    \t}\n\t\treturn l;\n\t}\n\n\ttemplate <class func>\n\tint minLeft(int r, const\
    \ func& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tT v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n#line 5 \"test/ALPC-J.test.cpp\"\
    \n\n#include <iostream>\n#line 8 \"test/ALPC-J.test.cpp\"\n#include <functional>\n\
    \nint main() {\n\t// std::cin.tie(nullptr);\n\t// std::ios::sync_with_stdio(false);\n\
    \t// int N, Q; std::cin >> N >> Q;\n\t// std::vector A(N, 0);\n\t// for (auto&\
    \ Ai : A) {\n\t// \tstd::cin >> Ai;\n\t// }\n\t// zawa::segmentTree<zawa::max_monoid<int>>\
    \ seg(A);\n\t// for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T; std::cin >> T;\n\
    \t// \tif (T == 1) {\n\t// \t\tint X, V; std::cin >> X >> V;\n\t// \t\tseg.set(X\
    \ - 1, V);\n\t// \t}\n\t// \tif (T == 2) {\n\t// \t\tint L, R; std::cin >> L >>\
    \ R;\n\t// \t\tstd::cout << seg.prod(L - 1, R) << std::endl;\n\t// \t}\n\t// \t\
    if (T == 3) {\n\t// \t\tint X, V; std::cin >> X >> V;\n\t// \t\tauto f = [&](int\
    \ p) -> bool {\n\t// \t\t\treturn p < V;\n\t// \t\t};\n\t// \t\tstd::cout << seg.maxRight(X\
    \ - 1, f) + 1 << std::endl;\n\t// \t}\n\t// }\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Library Practice Contest - J Segment Tree\n\
    \ * https://atcoder.jp/contests/practice2/submissions/38935945\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/utility/monoid/max.hpp\"\n#include \"../src/dataStructure/segmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n\nint main()\
    \ {\n\t// std::cin.tie(nullptr);\n\t// std::ios::sync_with_stdio(false);\n\t//\
    \ int N, Q; std::cin >> N >> Q;\n\t// std::vector A(N, 0);\n\t// for (auto& Ai\
    \ : A) {\n\t// \tstd::cin >> Ai;\n\t// }\n\t// zawa::segmentTree<zawa::max_monoid<int>>\
    \ seg(A);\n\t// for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T; std::cin >> T;\n\
    \t// \tif (T == 1) {\n\t// \t\tint X, V; std::cin >> X >> V;\n\t// \t\tseg.set(X\
    \ - 1, V);\n\t// \t}\n\t// \tif (T == 2) {\n\t// \t\tint L, R; std::cin >> L >>\
    \ R;\n\t// \t\tstd::cout << seg.prod(L - 1, R) << std::endl;\n\t// \t}\n\t// \t\
    if (T == 3) {\n\t// \t\tint X, V; std::cin >> X >> V;\n\t// \t\tauto f = [&](int\
    \ p) -> bool {\n\t// \t\t\treturn p < V;\n\t// \t\t};\n\t// \t\tstd::cout << seg.maxRight(X\
    \ - 1, f) + 1 << std::endl;\n\t// \t}\n\t// }\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Library Practice Contest - J Segment Tree\n\
    \ * https://atcoder.jp/contests/practice2/submissions/38935945\n */\n"
  dependsOn:
  - src/utility/monoid/max.hpp
  - src/dataStructure/segmentTree.hpp
  isVerificationFile: true
  path: test/ALPC-J.test.cpp
  requiredBy: []
  timestamp: '2023-02-17 11:08:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ALPC-J.test.cpp
layout: document
redirect_from:
- /verify/test/ALPC-J.test.cpp
- /verify/test/ALPC-J.test.cpp.html
title: test/ALPC-J.test.cpp
---
