---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/input3.test.cpp
    title: test/input3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/input5.test.cpp
    title: test/input5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/output1.test.cpp
    title: test/output1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/output2.test.cpp
    title: test/output2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/output3.test.cpp
    title: test/output3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template/output.hpp\"\n\n#include <iostream>\n#include\
    \ <vector>\n#include <string>\n\nnamespace zawa::output {\n\nvoid out() { \n \
    \   std::cout << std::endl; \n}\n\ntemplate <class T>\nvoid out(const T& a) {\
    \ \n    std::cout << a << std::endl; \n}\n\ntemplate <class T>\nvoid out(const\
    \ std::vector<T>& as) { \n    for (std::size_t i = 0 ; i < as.size() ; i++) {\
    \ \n        std::cout << as[i] << (i + 1 == as.size() ? '\\n' : ' '); \n    }\
    \ \n}\n\ntemplate <class Head, class... Tail>\nvoid out(const Head& head, const\
    \ Tail&... tail) { \n    std::cout << head; \n    if (sizeof...(tail)) { \n  \
    \      std::cout << ' '; \n    } \n    out(tail...);\n}\n\nvoid yesno(bool flag,\
    \ std::string yes = \"Yes\", std::string no = \"No\") {\n    std::cout << (flag\
    \ ? yes : no) << std::endl;\n}\n\n} // namespace zawa::output\n"
  code: "#pragma once\n\n#include <iostream>\n#include <vector>\n#include <string>\n\
    \nnamespace zawa::output {\n\nvoid out() { \n    std::cout << std::endl; \n}\n\
    \ntemplate <class T>\nvoid out(const T& a) { \n    std::cout << a << std::endl;\
    \ \n}\n\ntemplate <class T>\nvoid out(const std::vector<T>& as) { \n    for (std::size_t\
    \ i = 0 ; i < as.size() ; i++) { \n        std::cout << as[i] << (i + 1 == as.size()\
    \ ? '\\n' : ' '); \n    } \n}\n\ntemplate <class Head, class... Tail>\nvoid out(const\
    \ Head& head, const Tail&... tail) { \n    std::cout << head; \n    if (sizeof...(tail))\
    \ { \n        std::cout << ' '; \n    } \n    out(tail...);\n}\n\nvoid yesno(bool\
    \ flag, std::string yes = \"Yes\", std::string no = \"No\") {\n    std::cout <<\
    \ (flag ? yes : no) << std::endl;\n}\n\n} // namespace zawa::output\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/output.hpp
  requiredBy: []
  timestamp: '2022-12-29 22:40:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/output1.test.cpp
  - test/input3.test.cpp
  - test/input5.test.cpp
  - test/output2.test.cpp
  - test/output3.test.cpp
documentation_of: src/template/output.hpp
layout: document
title: "output (\u6A19\u6E96\u51FA\u529B)"
---

## 概要

標準出力まわりを扱います。

`using namespace zawa::output`をすることを想定しています。

## 機能

`void zawa::output::out<T>(const T& a)`
- `std::cout << a << std::endl;`します

`void zawa::output::out()`
- `std::cout << std::endl;`します

`void zawa::output::out<Head, Tail...>(const Head& head, const Tail&... tail)`
- 可変長引数verです。空白区切りで出力し、最後は空白を入れず改行します。

`void zawa::output::out<T>(const std::vector<T>& as)`
- `std::vector`を出力します。末尾に空白が入りません。
