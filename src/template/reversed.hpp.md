---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/reversed.test.cpp
    title: test/reversed.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/reversed.hpp\"\n\n#include <vector>\n#include\
    \ <algorithm>\n#include <string>\n\nnamespace zawa::util {\n\ntemplate <class\
    \ T>\nstd::vector<T> reversed(std::vector<T> A) {\n\tstd::reverse(A.begin(), A.end());\n\
    \treturn A;\n}\n\nstd::string reversed(std::string s) {\n\tstd::reverse(s.begin(),\
    \ s.end());\n\treturn s;\n}\n\n} // namespace zawa::util\n"
  code: "#pragma once\n\n#include <vector>\n#include <algorithm>\n#include <string>\n\
    \nnamespace zawa::util {\n\ntemplate <class T>\nstd::vector<T> reversed(std::vector<T>\
    \ A) {\n\tstd::reverse(A.begin(), A.end());\n\treturn A;\n}\n\nstd::string reversed(std::string\
    \ s) {\n\tstd::reverse(s.begin(), s.end());\n\treturn s;\n}\n\n} // namespace\
    \ zawa::util\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/reversed.hpp
  requiredBy: []
  timestamp: '2023-03-12 16:57:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/reversed.test.cpp
documentation_of: src/template/reversed.hpp
layout: document
title: reversed (reverse)
---

## 概要

引数で与えた列を反転して返します。与えた列は破壊されません

## 機能

`using namespace zawa::util`しましょう

```
(1) std::vector<T> zawa::util::reversed<T>(std::vector<T> A)
(2) std::string zawa::util::reversed(std::string s)
```
