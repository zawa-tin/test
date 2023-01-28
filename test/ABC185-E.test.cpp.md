---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_tree.hpp
    title: "fenwick_tree (\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u548C\u53D6\u5F97\
      )"
  - icon: ':heavy_check_mark:'
    path: src/utility/fenwick_tree/xor.hpp
    title: fenwick tree xor structure
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc185/submissions/38434342
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC185-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/fenwick_tree.hpp\"\n\n#include <vector>\n\nnamespace\
    \ zawa {\n\ntemplate <class structure>\nclass fenwick_tree {\nprivate:\n\tusing\
    \ T = typename structure::T;\n\tstd::vector<T> dat;\n\tint pow_two;\n\n\tinline\
    \ int lsb(int x) {\n\t\treturn x & -x;\n\t}\n\n\tT sum(int r) {\n\t\tT res = 0;\n\
    \t\twhile (r > 0) {\n\t\t\tres = structure::add(res, dat[r]);\n\t\t\tr -= lsb(r);\n\
    \t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\n\tfenwick_tree(std::size_t n) : dat(n\
    \ + 1, structure::id), pow_two(std::__lg(n) + 1) {}\n\t\n\tfenwick_tree(const\
    \ std::vector<T>& A) : dat(A.size() + 1, structure::id), pow_two(std::__lg(A.size())\
    \ + 1) {\n\t\tfor (int i = 0 ; i < (int)A.size() ; i++) {\n\t\t\tadd(i, A[i]);\n\
    \t\t}\n\t}\n\n\n\tT sum(int l, int r) {\n\t\treturn structure::add(sum(r), structure::inverse(sum(l)));\n\
    \t}\n\n\tvoid add(int pos, const T& v) {\n\t\tpos++;\n\t\twhile (pos < (int)dat.size())\
    \ {\n\t\t\tdat[pos] = structure::add(dat[pos], v);\n\t\t\tpos += lsb(pos);\n\t\
    \t}\n\t}\n\n\tint lower_bound(T val) {\n\t\tint res = 0;\n\t\tT now = structure::id;\n\
    \t\tfor (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {\n\t\t\tif (res + x < (int)dat.size())\
    \ {\n\t\t\t\tT nxt = structure::add(now, dat[res + x]);\n\t\t\t\tif (nxt < val)\
    \ {\n\t\t\t\t\tres += x;\n\t\t\t\t\tnow = nxt;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 2 \"src/utility/fenwick_tree/xor.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct xor_structure {\n\t\
    using T = dat_type;\n\tstatic constexpr T id{};\n\tstatic T add(const T& a, const\
    \ T& b) {\n\t\treturn a ^ b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\treturn\
    \ a;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"test/ABC185-E.test.cpp\"\n\n#include\
    \ <iostream>\n#line 8 \"test/ABC185-E.test.cpp\"\n\nint main() {\n\t// int N,\
    \ Q; std::cin >> N >> Q;\n\t// std::vector A(N, 0);\n\t// for (auto& a : A) {\n\
    \t// \tstd::cin >> a;\n\t// }\n\t// zawa::fenwick_tree<zawa::xor_structure<int>>\
    \ fen(A);\n\t// for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T, X, Y; std::cin\
    \ >> T >> X >> Y;\n\t// \tif (T == 1) {\n\t// \t\tfen.add(X - 1, Y);\n\t// \t\
    }\n\t// \tif (T == 2) {\n\t// \t\tstd::cout << fen.sum(X - 1, Y) << std::endl;\n\
    \t// \t}\n\t// }\t\n\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 185 - F Range Xor Query\n * https://atcoder.jp/contests/abc185/submissions/38434342\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/fenwick_tree.hpp\"\n#include \"../src/utility/fenwick_tree/xor.hpp\"\
    \n\n#include <iostream>\n#include <vector>\n\nint main() {\n\t// int N, Q; std::cin\
    \ >> N >> Q;\n\t// std::vector A(N, 0);\n\t// for (auto& a : A) {\n\t// \tstd::cin\
    \ >> a;\n\t// }\n\t// zawa::fenwick_tree<zawa::xor_structure<int>> fen(A);\n\t\
    // for (int _ = 0 ; _ < Q ; _++) {\n\t// \tint T, X, Y; std::cin >> T >> X >>\
    \ Y;\n\t// \tif (T == 1) {\n\t// \t\tfen.add(X - 1, Y);\n\t// \t}\n\t// \tif (T\
    \ == 2) {\n\t// \t\tstd::cout << fen.sum(X - 1, Y) << std::endl;\n\t// \t}\n\t\
    // }\t\n\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner\
    \ Contest 185 - F Range Xor Query\n * https://atcoder.jp/contests/abc185/submissions/38434342\n\
    \ */\n"
  dependsOn:
  - src/dataStructure/fenwick_tree.hpp
  - src/utility/fenwick_tree/xor.hpp
  isVerificationFile: true
  path: test/ABC185-E.test.cpp
  requiredBy: []
  timestamp: '2023-01-29 05:23:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC185-E.test.cpp
layout: document
redirect_from:
- /verify/test/ABC185-E.test.cpp
- /verify/test/ABC185-E.test.cpp.html
title: test/ABC185-E.test.cpp
---
