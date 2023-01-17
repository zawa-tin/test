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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "#line 1 \"test/rollinghash.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
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
    \ namespace zawa\n#line 4 \"test/rollinghash.test.cpp\"\n\n#line 7 \"test/rollinghash.test.cpp\"\
    \n\nint main() {\n\tstd::string t, p; std::cin >> t >> p;\n\tzawa::rollinghash<1000000>\
    \ roll;\n\tauto h1 = roll.build(t), h2 = roll.build(p);\n\tfor (std::size_t i\
    \ = 0 ; i + p.size() <= t.size() ; i++) {\n\t\tif (roll.hash(h1, i, i + p.size())\
    \ == roll.hash(h2, 0, p.size())) {\n\t\t\tstd::cout << i << std::endl;\n\t\t}\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"../src/string/rollinghash.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nint main() {\n\tstd::string t, p; std::cin >> t >> p;\n\tzawa::rollinghash<1000000>\
    \ roll;\n\tauto h1 = roll.build(t), h2 = roll.build(p);\n\tfor (std::size_t i\
    \ = 0 ; i + p.size() <= t.size() ; i++) {\n\t\tif (roll.hash(h1, i, i + p.size())\
    \ == roll.hash(h2, 0, p.size())) {\n\t\t\tstd::cout << i << std::endl;\n\t\t}\n\
    \t}\n}\n"
  dependsOn:
  - src/string/rollinghash.hpp
  isVerificationFile: true
  path: test/rollinghash.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 06:37:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rollinghash.test.cpp
layout: document
redirect_from:
- /verify/test/rollinghash.test.cpp
- /verify/test/rollinghash.test.cpp.html
title: test/rollinghash.test.cpp
---
