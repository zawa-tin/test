---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/segmentTree.hpp
    title: "segmentTree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u6F14\u7B97\u30BB\
      \u30B0\u6728)"
  - icon: ':heavy_check_mark:'
    path: src/utility/monoid/xorMonoid.hpp
    title: "xorMonoid (\u6392\u4ED6\u7684\u8AD6\u7406\u548C\u30E2\u30CE\u30A4\u30C9\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc185/tasks/abc185_f
    links:
    - https://atcoder.jp/contests/abc185/tasks/abc185_f
  bundledCode: "#line 1 \"test/segmentTree-RXQ.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc185/tasks/abc185_f\"\
    \n\n#line 2 \"src/utility/monoid/xorMonoid.hpp\"\n\nnamespace zawa {\n\ntemplate\
    \ <class T>\nstruct xorMonoid {\n\tusing valueType = T;\n\tstatic constexpr valueType\
    \ identity{};\n\tstatic valueType operation(const valueType& a, const valueType&\
    \ b) {\n\t\treturn (a ^ b);\n\t}\n};\n\n} // namespace zawa\n#line 2 \"src/dataStructure/segmentTree.hpp\"\
    \n\n#include <vector>\n#include <functional>\n\nnamespace zawa {\n\ntemplate <class\
    \ monoid>\nclass segmentTree {\nprivate:\n\tusing V = typename monoid::valueType;\n\
    \tstd::size_t N;\n\tstd::vector<V> dat;\n\npublic:\n\tsegmentTree() {}\n\tsegmentTree(int\
    \ _N) : N(_N), dat(2 * _N, monoid::identity) {}\n\tsegmentTree(const std::vector<V>&\
    \ A) : N(A.size()), dat(2 * N, monoid::identity) {\n\t\tfor (std::size_t i = 0\
    \ ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t\tfor (std::size_t\
    \ i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i << 1], dat[i\
    \ << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const V& value) {\n\
    \t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\t\t\tdat[pos]\
    \ = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\tV update(std::size_t\
    \ pos, const V& value) {\n\t\tpos += N;\n\t\tdo {\n\t\t\tdat[pos] = monoid::operation(dat[pos],\
    \ value);\n\t\t} while (pos >>= 1);\n\t\treturn dat[pos];\n\t}\n\n\tV prod(std::size_t\
    \ l, std::size_t r) const {\n\t\tV left = monoid::identity, right = monoid::identity;\n\
    \t\tfor (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tleft = monoid::operation(left, dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\
    \t\t\t\tright = monoid::operation(dat[--r], right);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ monoid::operation(left, right);\n\t}\n\n\ttemplate <class functionType>\n\t\
    int maxRight(int l, const functionType& f) const {\n\t\tint L = l + N, w = 1;\n\
    \t\tV v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\
    \t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\
    \tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile (L <<= 1, w >>=\
    \ 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {\n\t\t\
    \t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\t}\n\t\t\
    return l;\n\t}\n\n\ttemplate <class functionType>\n\tint minLeft(int r, const\
    \ functionType& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tV v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n#line 5 \"test/segmentTree-RXQ.test.cpp\"\
    \n\n#include <iostream>\n#line 8 \"test/segmentTree-RXQ.test.cpp\"\n\nint main()\
    \ {\n\tint N, Q; std::cin >> N >> Q;\n\tstd::vector A(N, 0);\n\tfor (auto& a :\
    \ A) {\n\t\tstd::cin >> a;\n\t}\n\tzawa::segmentTree<zawa::xorMonoid<int>> seg(A);\n\
    \tfor (int _ = 0 ; _ < Q ; _++) {\n\t\tint T, X, Y; std::cin >> T >> X >> Y;\n\
    \t\tif (T == 1) {\n\t\t\tseg.update(X - 1, Y);\n\t\t}\n\t\tif (T == 2) {\n\t\t\
    \tstd::cout << seg.prod(X - 1, Y) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc185/tasks/abc185_f\"\n\n\
    #include \"../src/utility/monoid/xorMonoid.hpp\"\n#include \"../src/dataStructure/segmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n\tint N, Q; std::cin\
    \ >> N >> Q;\n\tstd::vector A(N, 0);\n\tfor (auto& a : A) {\n\t\tstd::cin >> a;\n\
    \t}\n\tzawa::segmentTree<zawa::xorMonoid<int>> seg(A);\n\tfor (int _ = 0 ; _ <\
    \ Q ; _++) {\n\t\tint T, X, Y; std::cin >> T >> X >> Y;\n\t\tif (T == 1) {\n\t\
    \t\tseg.update(X - 1, Y);\n\t\t}\n\t\tif (T == 2) {\n\t\t\tstd::cout << seg.prod(X\
    \ - 1, Y) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/xorMonoid.hpp
  - src/dataStructure/segmentTree.hpp
  isVerificationFile: true
  path: test/segmentTree-RXQ.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 16:51:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segmentTree-RXQ.test.cpp
layout: document
redirect_from:
- /verify/test/segmentTree-RXQ.test.cpp
- /verify/test/segmentTree-RXQ.test.cpp.html
title: test/segmentTree-RXQ.test.cpp
---
