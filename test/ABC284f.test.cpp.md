---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rollinghash.hpp
    title: "rollinghash (\u30ED\u30EA\u30CF)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc284/submissions/38126429
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC284f.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/string/rollinghash.hpp\"\n\n#include <random>\n#include <iostream>\n\
    #include <algorithm>\n#include <string>\n\nnamespace zawa {\n\ntemplate <std::size_t\
    \ max_length>\nclass rollinghash {\nprivate:\n\tusing hash_type = long long;\n\
    \n\tstd::random_device seed_gen;\n\tstd::mt19937_64 mt;\n\thash_type base;\n\t\
    const hash_type mod = (1ULL << 61ULL) - 1;\n\tstd::vector<hash_type> pows;\n\n\
    public:\n\n\tstruct info {\n\t\tstd::size_t len;\n\t\thash_type hash;\n\t\tinfo()\
    \ : len(0), hash(0) {}\n\t\tbool operator==(const info& a) {\n\t\t\treturn len\
    \ == a.len and hash == a.hash;\n\t\t}\n\t};\n\n\trollinghash() : mt(seed_gen()),\
    \ pows(max_length + 1, 1LL) {\n\t\tbase = std::clamp((hash_type)mt() % mod, (hash_type)1e9,\
    \ mod - 1);\n\t\tfor (std::size_t i = 0 ; i < max_length ; i++) {\n\t\t\tpows[i\
    \ + 1] = ((__int128_t)pows[i] * base) % mod;\n\t\t}\n\t}\n\n\ttemplate <class\
    \ T>\n\tstd::vector<info> build(const std::vector<T>& A) {\n\t\tstd::vector<info>\
    \ res(A.size() + 1, info());\t\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++)\
    \ {\n\t\t\tres[i + 1].len = i + 1;\n\t\t\tres[i + 1].hash = ((__int128_t)base\
    \ * res[i].hash + (__int128_t)A[i]) % mod;\n\t\t}\n\t\treturn res;\n\t}\n\n\t\
    std::vector<info> build(const std::string& s) {\n\t\treturn build(std::vector(s.begin(),\
    \ s.end()));\n\t}\n\n\tinfo hash(const std::vector<info>& H, int l, int r) {\n\
    \t\tinfo res = H[r];\n\t\tres.len -= H[l].len;\n\t\tres.hash -= ((__int128_t)H[l].hash\
    \ * pows[r - l]) % mod;\n\t\tif (res.hash < 0) {\n\t\t\tres.hash += mod;\n\t\t\
    }\n\t\treturn res;\n\t}\n\n\tinfo concate(const info& h1, const info& h2) { \n\
    \t\tinfo res;\n\t\tres.len = h1.len + h2.len;\n\t\tres.hash = ((((__int128_t)h1.hash\
    \ * pows[h2.len]) % mod) + h2.hash) % mod;\n\t\treturn res;\n\t}\n\n};\n\n} //\
    \ namespace zawa\n#line 4 \"test/ABC284f.test.cpp\"\n\n#line 8 \"test/ABC284f.test.cpp\"\
    \n\nint main() {\n\t// int n; std::cin >> n;\n\t// std::string t; std::cin >>\
    \ t;\n\t// std::string r = t;\n\t// std::reverse(r.begin(), r.end());\n\t// zawa::rollinghash<1000000>\
    \ roll;\n\t// auto rht = roll.build(t);\n\t// auto rhr = roll.build(r);\n\t//\
    \ for (int i = 0 ; i < n ; i++) {\n\t// \tauto f = roll.hash(rht, 0, i);\n\t//\
    \ \tauto c = roll.hash(rhr, n - i, 2 * n - i);\n\t// \tauto b = roll.hash(rht,\
    \ i + n, 2 * n);\n\t// \tauto cc = roll.concate(f, b);\n\t// \tif (c == cc) {\n\
    \t// \t\tstd::cout << r.substr(n - i, n) << std::endl;\n\t// \t\tstd::cout <<\
    \ i << std::endl;\n\t// \t\treturn 0;\n\t// \t}\n\t// }\n\t// std::cout << -1\
    \ << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * AtCoder\
    \ Beginner Contest 284 - F ABCBAC\n * https://atcoder.jp/contests/abc284/submissions/38126429\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/string/rollinghash.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <algorithm>\n\nint main() {\n\t// int n; std::cin >> n;\n\
    \t// std::string t; std::cin >> t;\n\t// std::string r = t;\n\t// std::reverse(r.begin(),\
    \ r.end());\n\t// zawa::rollinghash<1000000> roll;\n\t// auto rht = roll.build(t);\n\
    \t// auto rhr = roll.build(r);\n\t// for (int i = 0 ; i < n ; i++) {\n\t// \t\
    auto f = roll.hash(rht, 0, i);\n\t// \tauto c = roll.hash(rhr, n - i, 2 * n -\
    \ i);\n\t// \tauto b = roll.hash(rht, i + n, 2 * n);\n\t// \tauto cc = roll.concate(f,\
    \ b);\n\t// \tif (c == cc) {\n\t// \t\tstd::cout << r.substr(n - i, n) << std::endl;\n\
    \t// \t\tstd::cout << i << std::endl;\n\t// \t\treturn 0;\n\t// \t}\n\t// }\n\t\
    // std::cout << -1 << std::endl;\n\tstd::cout << \"Hello World\" << std::endl;\n\
    }\n\n/*\n * AtCoder Beginner Contest 284 - F ABCBAC\n * https://atcoder.jp/contests/abc284/submissions/38126429\n\
    \ */\n"
  dependsOn:
  - src/string/rollinghash.hpp
  isVerificationFile: true
  path: test/ABC284f.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 06:37:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC284f.test.cpp
layout: document
redirect_from:
- /verify/test/ABC284f.test.cpp
- /verify/test/ABC284f.test.cpp.html
title: test/ABC284f.test.cpp
---
