---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/segment_tree.hpp
    title: "segment_tree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u548C\u30BB\u30B0\
      \u6728)"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A
  bundledCode: "#line 1 \"test/segment_tree-AOJRmQ.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\n\n#line 2\
    \ \"src/utility/monoid/min_monoid.hpp\"\n\n#include <algorithm>\n#include <limits>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nstruct min_monoid {\n\tusing value_type\
    \ = T;\n\tstatic constexpr T identity = std::numeric_limits<T>::max();\n\tstatic\
    \ T operation(const T& a, const T& b) {\n\t\treturn std::min(a, b);\n\t}\n};\n\
    \n};\n#line 2 \"src/dataStructure/segment_tree.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n\nnamespace zawa {\n\ntemplate <class monoid>\nclass segment_tree\
    \ {\nprivate:\n\tusing T = typename monoid::value_type;\n\tstd::size_t N;\n\t\
    std::vector<T> dat;\n\npublic:\n\tsegment_tree() {}\n\tsegment_tree(int _N) :\
    \ N(_N), dat(2 * _N, monoid::identity) {}\n\tsegment_tree(const std::vector<T>&\
    \ A) : N(A.size()), dat(2 * N, monoid::identity) {\n\t\tfor (std::size_t i = 0\
    \ ; i < A.size() ; i++) {\n\t\t\tdat[i + N] = A[i];\n\t\t}\n\t\tfor (std::size_t\
    \ i = N - 1 ; i > 0 ; i--) {\n\t\t\tdat[i] = monoid::operation(dat[i << 1], dat[i\
    \ << 1 | 1]);\t\t\n\t\t}\n\t}\n\n\tvoid set(std::size_t pos, const T& value) {\n\
    \t\tpos += N;\n\t\tdat[pos] = value;\n\t\twhile (pos >>= 1) {\n\t\t\tdat[pos]\
    \ = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\tT action(std::size_t\
    \ pos, const T& value) {\n\t\tpos += N;\n\t\tdo {\n\t\t\tdat[pos] = monoid::operation(dat[pos],\
    \ value);\n\t\t} while (pos >>= 1);\n\t\treturn dat[pos];\n\t}\n\n\tT prod(std::size_t\
    \ l, std::size_t r) const {\n\t\tT left = monoid::identity, right = monoid::identity;\n\
    \t\tfor (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) {\n\t\t\
    \t\tleft = monoid::operation(left, dat[l++]);\t\n\t\t\t}\n\t\t\tif (r & 1) {\n\
    \t\t\t\tright = monoid::operation(dat[--r], right);\n\t\t\t}\n\t\t}\n\t\treturn\
    \ monoid::operation(left, right);\n\t}\n\n\ttemplate <class function_type>\n\t\
    int max_right(int l, const function_type& f) const {\n\t\tint L = l + N, w = 1;\n\
    \t\tT v = monoid::identity;\n\t\tfor ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {\n\
    \t\t\tif (L & 1) {\n\t\t\t   \tif (f(monoid::operation(v, dat[L]))) {\n\t\t\t\t\
    \tv = monoid::operation(v, dat[L++]);\n\t\t\t\t\tl += w;\n\t\t\t\t}\n\t\t\t\t\
    else {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\twhile (L <<= 1, w >>=\
    \ 1) {\n\t\t\tif (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {\n\t\t\
    \t\tv = monoid::operation(v, dat[L++]);\n\t\t\t\tl += w;\n\t\t\t}\n\t\t}\n\t\t\
    return l;\n\t}\n\n\ttemplate <class function_type>\n\tint min_left(int r, const\
    \ function_type& f) const {\t\n\t\tint R = r + N, w = 1;\n\t\tT v = monoid::identity;\n\
    \t\tfor ( ; r - w >= 0 ; R >>= 1, w <<= 1) {\n\t\t\tif (R & 1) {\n\t\t\t\tif (f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\t\tr -=\
    \ w;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\twhile (R <<= 1, w >>= 1) {\n\t\t\tif (r - w >= 0 and f(monoid::operation(dat[R\
    \ - 1], v))) {\n\t\t\t\tv = monoid::operation(dat[--R], v);\n\t\t\t\tr -= w;\n\
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n#line 5 \"test/segment_tree-AOJRmQ.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::segment_tree<zawa::min_monoid<int>>\
    \ seg(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint com; std::cin >> com;\n\t\
    \tif (com == 0) {\n\t\t\tint x, y; std::cin >> x >> y;\n\t\t\tseg.set(x, y);\n\
    \t\t}\n\t\tif (com == 1) {\n\t\t\tint x, y; std::cin >> x >> y;\n\t\t\tstd::cout\
    \ << seg.prod(x, y + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../src/utility/monoid/min_monoid.hpp\"\n#include \"../src/dataStructure/segment_tree.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\tint n, q; std::cin >> n >> q;\n\tzawa::segment_tree<zawa::min_monoid<int>>\
    \ seg(n);\n\tfor (int _ = 0 ; _ < q ; _++) {\n\t\tint com; std::cin >> com;\n\t\
    \tif (com == 0) {\n\t\t\tint x, y; std::cin >> x >> y;\n\t\t\tseg.set(x, y);\n\
    \t\t}\n\t\tif (com == 1) {\n\t\t\tint x, y; std::cin >> x >> y;\n\t\t\tstd::cout\
    \ << seg.prod(x, y + 1) << std::endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - src/utility/monoid/min_monoid.hpp
  - src/dataStructure/segment_tree.hpp
  isVerificationFile: true
  path: test/segment_tree-AOJRmQ.test.cpp
  requiredBy: []
  timestamp: '2023-02-18 05:16:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment_tree-AOJRmQ.test.cpp
layout: document
redirect_from:
- /verify/test/segment_tree-AOJRmQ.test.cpp
- /verify/test/segment_tree-AOJRmQ.test.cpp.html
title: test/segment_tree-AOJRmQ.test.cpp
---
