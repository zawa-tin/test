---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sorted.test.cpp
    title: test/sorted.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/sorted.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <string>\n\nnamespace zawa::util {\n\ntemplate <class\
    \ T>\nstd::vector<T> sorted(std::vector<T> A) {\n\tstd::sort(A.begin(), A.end());\n\
    \treturn A;\n}\n\nstd::string sorted(std::string s) {\n\tstd::sort(s.begin(),\
    \ s.end());\n\treturn s;\n}\n\n} // namespace zawa::util\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <string>\n\
    \nnamespace zawa::util {\n\ntemplate <class T>\nstd::vector<T> sorted(std::vector<T>\
    \ A) {\n\tstd::sort(A.begin(), A.end());\n\treturn A;\n}\n\nstd::string sorted(std::string\
    \ s) {\n\tstd::sort(s.begin(), s.end());\n\treturn s;\n}\n\n} // namespace zawa::util\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/sorted.hpp
  requiredBy: []
  timestamp: '2023-03-12 16:57:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sorted.test.cpp
documentation_of: src/template/sorted.hpp
layout: document
title: "sorted (\u30BD\u30FC\u30C8\u5217\u3092\u8FD4\u3059)"
---

## 概要

引数で与えた列に対してソートした列を返します。引数で与えた列は破壊されません

## 機能

```
std::vector<T> zawa::util::sorted<T>(std::vector<T> A)
std::string zawa::util::sorted(std::string s)
```

`using namespace zawa::util`することを前提としています。
