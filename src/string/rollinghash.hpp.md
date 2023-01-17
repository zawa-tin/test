---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC284f.test.cpp
    title: test/ABC284f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/rollinghash.test.cpp
    title: test/rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/rollinghash.hpp\"\n\n#include <random>\n#include\
    \ <iostream>\n#include <algorithm>\n#include <string>\n\nnamespace zawa {\n\n\
    template <std::size_t max_length>\nclass rollinghash {\nprivate:\n\tusing hash_type\
    \ = long long;\n\n\tstd::random_device seed_gen;\n\tstd::mt19937_64 mt;\n\thash_type\
    \ base;\n\tconst hash_type mod = (1ULL << 61ULL) - 1;\n\tstd::vector<hash_type>\
    \ pows;\n\npublic:\n\n\tstruct info {\n\t\tstd::size_t len;\n\t\thash_type hash;\n\
    \t\tinfo() : len(0), hash(0) {}\n\t\tbool operator==(const info& a) {\n\t\t\t\
    return len == a.len and hash == a.hash;\n\t\t}\n\t};\n\n\trollinghash() : mt(seed_gen()),\
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
    \ namespace zawa\n"
  code: "#pragma once\n\n#include <random>\n#include <iostream>\n#include <algorithm>\n\
    #include <string>\n\nnamespace zawa {\n\ntemplate <std::size_t max_length>\nclass\
    \ rollinghash {\nprivate:\n\tusing hash_type = long long;\n\n\tstd::random_device\
    \ seed_gen;\n\tstd::mt19937_64 mt;\n\thash_type base;\n\tconst hash_type mod =\
    \ (1ULL << 61ULL) - 1;\n\tstd::vector<hash_type> pows;\n\npublic:\n\n\tstruct\
    \ info {\n\t\tstd::size_t len;\n\t\thash_type hash;\n\t\tinfo() : len(0), hash(0)\
    \ {}\n\t\tbool operator==(const info& a) {\n\t\t\treturn len == a.len and hash\
    \ == a.hash;\n\t\t}\n\t};\n\n\trollinghash() : mt(seed_gen()), pows(max_length\
    \ + 1, 1LL) {\n\t\tbase = std::clamp((hash_type)mt() % mod, (hash_type)1e9, mod\
    \ - 1);\n\t\tfor (std::size_t i = 0 ; i < max_length ; i++) {\n\t\t\tpows[i +\
    \ 1] = ((__int128_t)pows[i] * base) % mod;\n\t\t}\n\t}\n\n\ttemplate <class T>\n\
    \tstd::vector<info> build(const std::vector<T>& A) {\n\t\tstd::vector<info> res(A.size()\
    \ + 1, info());\t\n\t\tfor (std::size_t i = 0 ; i < A.size() ; i++) {\n\t\t\t\
    res[i + 1].len = i + 1;\n\t\t\tres[i + 1].hash = ((__int128_t)base * res[i].hash\
    \ + (__int128_t)A[i]) % mod;\n\t\t}\n\t\treturn res;\n\t}\n\n\tstd::vector<info>\
    \ build(const std::string& s) {\n\t\treturn build(std::vector(s.begin(), s.end()));\n\
    \t}\n\n\tinfo hash(const std::vector<info>& H, int l, int r) {\n\t\tinfo res =\
    \ H[r];\n\t\tres.len -= H[l].len;\n\t\tres.hash -= ((__int128_t)H[l].hash * pows[r\
    \ - l]) % mod;\n\t\tif (res.hash < 0) {\n\t\t\tres.hash += mod;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tinfo concate(const info& h1, const info& h2) { \n\t\tinfo res;\n\
    \t\tres.len = h1.len + h2.len;\n\t\tres.hash = ((((__int128_t)h1.hash * pows[h2.len])\
    \ % mod) + h2.hash) % mod;\n\t\treturn res;\n\t}\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-01-18 06:37:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/rollinghash.test.cpp
  - test/ABC284f.test.cpp
documentation_of: src/string/rollinghash.hpp
layout: document
title: "rollinghash (\u30ED\u30EA\u30CF)"
---

## 概要

[ローリングハッシュ](https://en.wikipedia.org/wiki/Rolling_hash) をします。

modは $2^{61} - 1$ 、基数は $10^9$ 以上 $\text{mod}$ 未満です。

## 機能

`zawa::rollinghash<max_length>()`
- コンストラクタ
- 高々`max_length`のサイズの列のハッシュをとることができる
- `max_length`
	- `std::size_t`型
- **計算量**: $O(\text{maxlength})$

`struct info`
- ハッシュに関する構造体
- `std::size_t info::len`: ハッシュした列の長さ
- `long long info::hash`: ハッシュ値
- `bool info::operator==(const info& a)`: 等しいかを確認する`operator`

`std::vector<info> zawa::rollinghash<max_length>::build<T>(const std::vector<T>& A)`
- `A`のローリングハッシュを返します。
- `std::string`にも対応しています。
- **計算量** : $O(\mid A\mid)$

`info zawa::rollinghash<max_length>::hash(const std::vector<info>& H, int l, int r)`
- ローリングハッシュ`H`の`l`から`r - 1`までのハッシュを返す。
- **計算量** : $O(1)$

`info zawa::rollinghash<max_length>::concate(const info& a, const info& b)`
- ハッシュ`a`にハッシュ`b`を後ろから連結したハッシュを返す。
- 連結後の列の長さがうっかり`max_length`を超えないように気をつけること
- **計算量** : $O(1)$

## メモ
[安全で爆足なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6) の $2^{61} - 1$ modを高速に行う方法を妥協してやってないので現状`zawa::rollinghash`は遅い
