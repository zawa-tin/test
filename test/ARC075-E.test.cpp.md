---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/compression.hpp
    title: "compression (\u5EA7\u6A19\u5727\u7E2E)"
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_multiset.hpp
    title: "fenwick_multiset (\u52D5\u7684\u591A\u91CD\u96C6\u5408)"
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/fenwick_tree.hpp
    title: "fenwick_tree (\u4E00\u70B9\u52A0\u7B97\u3001\u533A\u9593\u548C\u53D6\u5F97\
      )"
  - icon: ':heavy_check_mark:'
    path: src/template/accum1d.hpp
    title: "accum1d (\u7D2F\u7A4D\u548C)"
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
    - https://atcoder.jp/contests/arc075/submissions/38473188
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ARC075-E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \ \n\n#line 2 \"src/dataStructure/fenwick_multiset.hpp\"\n\n#line 2 \"src/utility/fenwick_tree/add.hpp\"\
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
    return res;\n\t}\n};\n\n} // namespace zawa\n#line 5 \"src/dataStructure/fenwick_multiset.hpp\"\
    \n\n#line 7 \"src/dataStructure/fenwick_multiset.hpp\"\n#include <algorithm>\n\
    \nnamespace zawa {\n\ntemplate <class T>\nclass fenwick_multiset {\nprivate:\n\
    \tstd::vector<T> dat;\n\tfenwick_tree<add_structure<T>> fen;\n\npublic:\n\n\t\
    fenwick_multiset(std::size_t n) : dat(n), fen(n) {}\n\n\tT count(int x) {\n\t\t\
    return dat[x];\n\t}\n\n\tT count(int l, int r) {\n\t\treturn fen.sum(l, r);\n\t\
    }\n\n\tvoid insert(int x) {\n\t\tdat[x] += 1;\n\t\tfen.add(x, 1);\n\t}\n\n\tvoid\
    \ insert(int x, const T& cnt) {\n\t\tdat[x] += cnt;\n\t\tfen.add(x, cnt);\n\t\
    }\n\n\tT erase(int x) {\n\t\tif (dat[x]) {\n\t\t\tdat[x] -= 1;\n\t\t\tfen.add(x,\
    \ -1);\n\t\t\treturn 1;\n\t\t}\n\t\telse {\n\t\t\treturn 0;\n\t\t}\n\t}\n\n\t\
    T erase(int x, const T& cnt) {\n\t\tT res = std::min(dat[x], cnt);\t\n\t\tdat[x]\
    \ -= res;\n\t\tfen.add(x, -res);\n\t\treturn res;\n\t}\n\n\tint kth_element(const\
    \ T& k) {\n\t\treturn fen.lower_bound(k);\n\t}\n};\n\n} // namespace zawa\n#line\
    \ 2 \"src/template/accum1d.hpp\"\n\n#line 4 \"src/template/accum1d.hpp\"\n#include\
    \ <numeric>\n\nnamespace zawa {\n\ntemplate <class T>\nstruct accum1d : std::vector<T>\
    \ {\n\tusing vector = std::vector<T>;\n\taccum1d() {\n\t\t(*this).push_back(T());\n\
    \t}\n\taccum1d(const std::vector<T>& A) {\n\t\t(*this).push_back(T());\n\t\tstd::partial_sum(A.begin(),\
    \ A.end(), std::back_inserter(*this));\n\t}\t\n\ttemplate <class InputIterator>\n\
    \taccum1d(InputIterator begin, InputIterator end) {\n\t\t(*this).push_back(T());\n\
    \t\tstd::partial_sum(begin, end, std::back_inserter(*this));\n\t}\n\tT sum(std::size_t\
    \ l, std::size_t r) {\n\t\treturn (*this)[r] - (*this)[l];\n\t}\n};\n\n} // namespace\
    \ zawa\n#line 2 \"src/algorithm/compression.hpp\"\n\n#line 5 \"src/algorithm/compression.hpp\"\
    \n\nnamespace zawa {\n\ntemplate <class T>\nclass compression {\nprivate:\n\t\
    std::vector<T> as;\n\tstd::vector<T> uniqued;\n\npublic:\n\tcompression(const\
    \ std::vector<T>& as) : as(as), uniqued(as) {\n\t\tstd::sort(uniqued.begin(),\
    \ uniqued.end());\n\t\tuniqued.erase(std::unique(uniqued.begin(), uniqued.end()),\
    \ uniqued.end());\n\t}\n\n\tint operator[](const T& val) {\n\t\treturn std::lower_bound(uniqued.begin(),\
    \ uniqued.end(), val) - uniqued.begin();\n\t}\n\n\tint get(std::size_t i) {\n\t\
    \treturn (*this)[as[i]];\n\t}\n\n\tstd::size_t size() {\n\t\treturn uniqued.size();\n\
    \t}\n};\n\n} // namespace zawa\n#line 6 \"test/ARC075-E.test.cpp\"\n\n#include\
    \ <iostream>\n#line 9 \"test/ARC075-E.test.cpp\"\n\nint main() {\n\t// int N,\
    \ K; std::cin >> N >> K;\n\t// std::vector<long long> a(N);\n\t// for (auto& ai\
    \ : a) {\n\t// \tstd::cin >> ai;\n\t// \tai -= K;\n\t// }\n\t// zawa::accum1d\
    \ S(a);\n\t// zawa::compression comp(S);\n\t// zawa::fenwick_multiset<int> set(comp.size());\n\
    \t// long long ans = 0LL;\n\t// for (auto s : S) {\n\t// \tans += set.count(0,\
    \ comp[s] + 1);\n\t// \tset.insert(comp[s]);\n\t// }\n\t// std::cout << ans <<\
    \ std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Regular Contest 075\n * https://atcoder.jp/contests/arc075/submissions/38473188\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \ \n\n#include \"../src/dataStructure/fenwick_multiset.hpp\"\n#include \"../src/template/accum1d.hpp\"\
    \n#include \"../src/algorithm/compression.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n\nint main() {\n\t// int N, K; std::cin >> N >> K;\n\t// std::vector<long\
    \ long> a(N);\n\t// for (auto& ai : a) {\n\t// \tstd::cin >> ai;\n\t// \tai -=\
    \ K;\n\t// }\n\t// zawa::accum1d S(a);\n\t// zawa::compression comp(S);\n\t//\
    \ zawa::fenwick_multiset<int> set(comp.size());\n\t// long long ans = 0LL;\n\t\
    // for (auto s : S) {\n\t// \tans += set.count(0, comp[s] + 1);\n\t// \tset.insert(comp[s]);\n\
    \t// }\n\t// std::cout << ans << std::endl;\n\tstd::cout << \"Hello World\" <<\
    \ std::endl;\n}\n\n/*\n * AtCoder Regular Contest 075\n * https://atcoder.jp/contests/arc075/submissions/38473188\n\
    \ */\n"
  dependsOn:
  - src/dataStructure/fenwick_multiset.hpp
  - src/utility/fenwick_tree/add.hpp
  - src/dataStructure/fenwick_tree.hpp
  - src/template/accum1d.hpp
  - src/algorithm/compression.hpp
  isVerificationFile: true
  path: test/ARC075-E.test.cpp
  requiredBy: []
  timestamp: '2023-01-30 11:10:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ARC075-E.test.cpp
layout: document
redirect_from:
- /verify/test/ARC075-E.test.cpp
- /verify/test/ARC075-E.test.cpp.html
title: test/ARC075-E.test.cpp
---
