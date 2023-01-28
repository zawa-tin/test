---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_tree.hpp
    title: "fenwick_tree (\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u548C\u53D6\u5F97\
      )"
  - icon: ':heavy_check_mark:'
    path: src/utility/fenwick_tree/add.hpp
    title: fenwick tree add structure
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/arc033/submissions/38434277
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ARC033-C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
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
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 2 \"src/utility/fenwick_tree/add.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct add_structure {\n\t\
    using T = dat_type;\n\tstatic constexpr T id = T{};\n\tstatic T add(const T& a,\
    \ const T& b) {\n\t\treturn a + b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\t\
    return -a;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"test/ARC033-C.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n\t// const std::size_t size = 200001;\n\
    \t// zawa::fenwick_tree<zawa::add_structure<int>> fen(size);\n\t// int q; std::cin\
    \ >> q;\n\t// for (int _ = 0 ; _ < q ; _++) {\n\t// \tint t, x; std::cin >> t\
    \ >> x;\n\t// \tif (t == 1) {\n\t// \t\tfen.add(x, 1);\n\t// \t}\n\t// \tif (t\
    \ == 2) {\n\t// \t\tauto f = [&](int p) -> bool {\n\t// \t\t\treturn p < x;\n\t\
    // \t\t};\n\t// \t\tint v = fen.lower_bound(x);\n\t// \t\tstd::cout << v << std::endl;\n\
    \t// \t\tfen.add(v, -1);\n\t// \t}\n\t// }\n\t\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Regular Contest 033 - C \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * https://atcoder.jp/contests/arc033/submissions/38434277\n */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/fenwick_tree.hpp\"\n#include \"../src/utility/fenwick_tree/add.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n\t// const std::size_t size = 200001;\n\
    \t// zawa::fenwick_tree<zawa::add_structure<int>> fen(size);\n\t// int q; std::cin\
    \ >> q;\n\t// for (int _ = 0 ; _ < q ; _++) {\n\t// \tint t, x; std::cin >> t\
    \ >> x;\n\t// \tif (t == 1) {\n\t// \t\tfen.add(x, 1);\n\t// \t}\n\t// \tif (t\
    \ == 2) {\n\t// \t\tauto f = [&](int p) -> bool {\n\t// \t\t\treturn p < x;\n\t\
    // \t\t};\n\t// \t\tint v = fen.lower_bound(x);\n\t// \t\tstd::cout << v << std::endl;\n\
    \t// \t\tfen.add(v, -1);\n\t// \t}\n\t// }\n\t\n\tstd::cout << \"Hello World\"\
    \ << std::endl;\n}\n\n/*\n * AtCoder Regular Contest 033 - C \u30C7\u30FC\u30BF\
    \u69CB\u9020\n * https://atcoder.jp/contests/arc033/submissions/38434277\n */\n"
  dependsOn:
  - src/dataStructure/fenwick_tree.hpp
  - src/utility/fenwick_tree/add.hpp
  isVerificationFile: true
  path: test/ARC033-C.test.cpp
  requiredBy: []
  timestamp: '2023-01-29 05:23:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ARC033-C.test.cpp
layout: document
redirect_from:
- /verify/test/ARC033-C.test.cpp
- /verify/test/ARC033-C.test.cpp.html
title: test/ARC033-C.test.cpp
---
