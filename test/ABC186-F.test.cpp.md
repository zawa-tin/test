---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_set.hpp
    title: "fenwick_set (\u52D5\u7684\u96C6\u5408)"
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
    - https://atcoder.jp/contests/abc186/submissions/38472515
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC186-F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/dataStructure/fenwick_set.hpp\"\n\n#line 2 \"src/utility/fenwick_tree/add.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class dat_type>\nstruct add_structure {\n\t\
    using T = dat_type;\n\tstatic constexpr T id = T{};\n\tstatic T add(const T& a,\
    \ const T& b) {\n\t\treturn a + b;\n\t}\n\tstatic T inverse(const T& a) {\n\t\t\
    return -a;\n\t}\n};\n\n} // namespace zawa\n#line 2 \"src/dataStructure/fenwick_tree.hpp\"\
    \n\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class structure>\nclass\
    \ fenwick_tree {\nprivate:\n\tusing T = typename structure::T;\n\tstd::vector<T>\
    \ dat;\n\tint pow_two;\n\n\tinline int lsb(int x) {\n\t\treturn x & -x;\n\t}\n\
    \n\tT sum(int r) {\n\t\tT res = 0;\n\t\twhile (r > 0) {\n\t\t\tres = structure::add(res,\
    \ dat[r]);\n\t\t\tr -= lsb(r);\n\t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\n\t\
    fenwick_tree(std::size_t n) : dat(n + 1, structure::id), pow_two(std::__lg(n)\
    \ + 1) {}\n\t\n\tfenwick_tree(const std::vector<T>& A) : dat(A.size() + 1, structure::id),\
    \ pow_two(std::__lg(A.size()) + 1) {\n\t\tfor (int i = 0 ; i < (int)A.size() ;\
    \ i++) {\n\t\t\tadd(i, A[i]);\n\t\t}\n\t}\n\n\n\tT sum(int l, int r) {\n\t\treturn\
    \ structure::add(sum(r), structure::inverse(sum(l)));\n\t}\n\n\tvoid add(int pos,\
    \ const T& v) {\n\t\tpos++;\n\t\twhile (pos < (int)dat.size()) {\n\t\t\tdat[pos]\
    \ = structure::add(dat[pos], v);\n\t\t\tpos += lsb(pos);\n\t\t}\n\t}\n\n\tint\
    \ lower_bound(T val) {\n\t\tint res = 0;\n\t\tT now = structure::id;\n\t\tfor\
    \ (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {\n\t\t\tif (res + x < (int)dat.size())\
    \ {\n\t\t\t\tT nxt = structure::add(now, dat[res + x]);\n\t\t\t\tif (nxt < val)\
    \ {\n\t\t\t\t\tres += x;\n\t\t\t\t\tnow = nxt;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"src/dataStructure/fenwick_set.hpp\"\
    \n\n#line 7 \"src/dataStructure/fenwick_set.hpp\"\n\nnamespace zawa {\n\nclass\
    \ fenwick_set {\nprivate:\n\tstd::vector<bool> dat;\n\tfenwick_tree<add_structure<int>>\
    \ fen;\n\npublic:\n\tfenwick_set(std::size_t n) : dat(n, false), fen(n) {}\n\n\
    \tbool contain(int x) {\n\t\treturn dat[x];\n\t}\n\n\tvoid insert(int x) {\n\t\
    \tif (!dat[x]) {\n\t\t\tdat[x] = true;\n\t\t\tfen.add(x, 1);\n\t\t}\n\t}\n\n\t\
    int count(int l, int r) {\n\t\treturn fen.sum(l, r);\n\t}\n\n\tbool erase(int\
    \ x) {\n\t\tif (dat[x]) {\n\t\t\tdat[x] = false;\n\t\t\tfen.add(x, -1);\n\t\t\t\
    return true;\n\t\t}\n\t\telse {\n\t\t\treturn false;\n\t\t}\n\t}\t\n\n\tint kth_element(int\
    \ k) {\n\t\treturn fen.lower_bound(k);\n\t}\n};\n\n};\n#line 4 \"test/ABC186-F.test.cpp\"\
    \n\n#include <iostream>\n// #include <vector>\n// #include <algorithm>\n#include\
    \ <cassert>\n\nint main() {\n\t// int H, W, M; std::cin >> H >> W >> M;\n\t//\
    \ std::vector R(H, std::vector(1, W)), C(W, std::vector(1, H));\n\t// for (int\
    \ _ = 0 ; _ < M ; _++) {\n\t// \tint Y, X; std::cin >> Y >> X;\n\t// \tY--; X--;\n\
    \t// \tR[Y].push_back(X);\n\t// \tC[X].push_back(Y);\n\t// }\n\t// for (auto&\
    \ r : R) {\n\t// \tstd::sort(r.begin(), r.end());\n\t// }\n\t// for (auto& c :\
    \ C) {\n\t// \tstd::sort(c.begin(), c.end());\n\t// }\n\t// long long ans = 0LL;\n\
    \t// for (const auto& r : R) {\n\t// \tif (r[0] == 0) {\n\t// \t\tbreak;\n\t//\
    \ \t}\n\t// \tans += r[0];\n\t// }\n\t// for (const auto& c : C) {\n\t// \tif\
    \ (c[0] == 0) {\n\t// \t\tbreak;\n\t// \t}\n\t// \tans += c[0];\n\t// }\n\t//\
    \ zawa::fenwick_set S(W + 1);\n\t// S.insert(W);\n\t// for (const auto& r : R)\
    \ {\n\t// \tif (r.front() == 0) {\n\t// \t\tbreak;\n\t// \t}\n\t// \tint line\
    \ = std::min(R[0][0], r[0]);\n\t// \tans -= line - S.count(0, line);\n\t// \t\
    for (const auto& v : r) {\n\t// \t\tS.insert(v);\n\t// \t}\n\t// }\n\t// std::cout\
    \ << ans << std::endl;\n\n\tzawa::fenwick_set set(10);\n\tset.insert(2);\n\tset.insert(5);\n\
    \tset.insert(7);\n\tset.insert(9);\n\tassert(set.kth_element(2) == 5);\n\tset.erase(2);\n\
    \tassert(set.kth_element(2) == 7);\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 186 - F Rook on Grid\n * https://atcoder.jp/contests/abc186/submissions/38472515\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/fenwick_set.hpp\"\n\n#include <iostream>\n\
    // #include <vector>\n// #include <algorithm>\n#include <cassert>\n\nint main()\
    \ {\n\t// int H, W, M; std::cin >> H >> W >> M;\n\t// std::vector R(H, std::vector(1,\
    \ W)), C(W, std::vector(1, H));\n\t// for (int _ = 0 ; _ < M ; _++) {\n\t// \t\
    int Y, X; std::cin >> Y >> X;\n\t// \tY--; X--;\n\t// \tR[Y].push_back(X);\n\t\
    // \tC[X].push_back(Y);\n\t// }\n\t// for (auto& r : R) {\n\t// \tstd::sort(r.begin(),\
    \ r.end());\n\t// }\n\t// for (auto& c : C) {\n\t// \tstd::sort(c.begin(), c.end());\n\
    \t// }\n\t// long long ans = 0LL;\n\t// for (const auto& r : R) {\n\t// \tif (r[0]\
    \ == 0) {\n\t// \t\tbreak;\n\t// \t}\n\t// \tans += r[0];\n\t// }\n\t// for (const\
    \ auto& c : C) {\n\t// \tif (c[0] == 0) {\n\t// \t\tbreak;\n\t// \t}\n\t// \t\
    ans += c[0];\n\t// }\n\t// zawa::fenwick_set S(W + 1);\n\t// S.insert(W);\n\t\
    // for (const auto& r : R) {\n\t// \tif (r.front() == 0) {\n\t// \t\tbreak;\n\t\
    // \t}\n\t// \tint line = std::min(R[0][0], r[0]);\n\t// \tans -= line - S.count(0,\
    \ line);\n\t// \tfor (const auto& v : r) {\n\t// \t\tS.insert(v);\n\t// \t}\n\t\
    // }\n\t// std::cout << ans << std::endl;\n\n\tzawa::fenwick_set set(10);\n\t\
    set.insert(2);\n\tset.insert(5);\n\tset.insert(7);\n\tset.insert(9);\n\tassert(set.kth_element(2)\
    \ == 5);\n\tset.erase(2);\n\tassert(set.kth_element(2) == 7);\n\tstd::cout <<\
    \ \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder Beginner Contest 186 - F\
    \ Rook on Grid\n * https://atcoder.jp/contests/abc186/submissions/38472515\n */\n"
  dependsOn:
  - src/dataStructure/fenwick_set.hpp
  - src/utility/fenwick_tree/add.hpp
  - src/dataStructure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/ABC186-F.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 10:01:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC186-F.test.cpp
layout: document
redirect_from:
- /verify/test/ABC186-F.test.cpp
- /verify/test/ABC186-F.test.cpp.html
title: test/ABC186-F.test.cpp
---
