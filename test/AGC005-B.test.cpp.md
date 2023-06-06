---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/segmentTree.hpp
    title: "segmentTree (\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u6F14\u7B97\u30BB\
      \u30B0\u6728)"
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
    - https://atcoder.jp/contests/agc005/submissions/39569912
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/AGC005-B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/utility/monoid/minMonoid.hpp\"\n\n#include <algorithm>\n#include\
    \ <limits>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct minMonoid {\n\tusing\
    \ valueType = T;\n\tstatic constexpr valueType identity = std::numeric_limits<valueType>::max();\n\
    \tstatic valueType operation(const valueType& a, const valueType& b) {\n\t\treturn\
    \ std::min(a, b);\n\t}\n};\n\n};\n#line 2 \"src/dataStructure/segmentTree.hpp\"\
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
    \t\t\t}\n\t\t}\n\t\treturn r;\n\t}\t\n};\n\n} // namespace zawa\n#line 5 \"test/AGC005-B.test.cpp\"\
    \n\n#include <iostream>\n#line 9 \"test/AGC005-B.test.cpp\"\n\nint main() {\n\t\
    // int N; std::cin >> N;\n\t// std::vector a(N, 0);\n\t// for (auto& ai : a) {\n\
    \t// \tstd::cin >> ai;\n\t// }\n\t// zawa::segmentTree<zawa::minMonoid<int>> seg(a);\n\
    \t// long long ans = 0LL;\n\t// for (int i = 0 ; i < N ; i++) {\n\t// \tauto f\
    \ = [&](int p) -> bool {\n\t// \t\treturn p >= a[i];\n\t// \t};\n\t// \tint l\
    \ = seg.minLeft(i, f), r = seg.maxRight(i, f);\n\t// \tans += (long long)(i -\
    \ l + 1) * (r - i) * a[i];\n\t// }\n\t// std::cout << ans << std::endl;\n\n\t\
    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Grand Contest\
    \ 005 - B Minimum Sum\n * https://atcoder.jp/contests/agc005/submissions/39569912\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/utility/monoid/minMonoid.hpp\"\n#include \"../src/dataStructure/segmentTree.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n#include <functional>\n\nint main()\
    \ {\n\t// int N; std::cin >> N;\n\t// std::vector a(N, 0);\n\t// for (auto& ai\
    \ : a) {\n\t// \tstd::cin >> ai;\n\t// }\n\t// zawa::segmentTree<zawa::minMonoid<int>>\
    \ seg(a);\n\t// long long ans = 0LL;\n\t// for (int i = 0 ; i < N ; i++) {\n\t\
    // \tauto f = [&](int p) -> bool {\n\t// \t\treturn p >= a[i];\n\t// \t};\n\t\
    // \tint l = seg.minLeft(i, f), r = seg.maxRight(i, f);\n\t// \tans += (long long)(i\
    \ - l + 1) * (r - i) * a[i];\n\t// }\n\t// std::cout << ans << std::endl;\n\n\t\
    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Grand Contest\
    \ 005 - B Minimum Sum\n * https://atcoder.jp/contests/agc005/submissions/39569912\n\
    \ */\n"
  dependsOn:
  - src/utility/monoid/minMonoid.hpp
  - src/dataStructure/segmentTree.hpp
  isVerificationFile: true
  path: test/AGC005-B.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 17:05:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AGC005-B.test.cpp
layout: document
redirect_from:
- /verify/test/AGC005-B.test.cpp
- /verify/test/AGC005-B.test.cpp.html
title: test/AGC005-B.test.cpp
---