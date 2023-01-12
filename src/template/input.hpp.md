---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/input1.test.cpp
    title: test/input1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/input2.test.cpp
    title: test/input2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/input3.test.cpp
    title: test/input3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/input4.test.cpp
    title: test/input4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/input5.test.cpp
    title: test/input5.test.cpp
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
  bundledCode: "#line 2 \"src/template/input.hpp\"\n\n#include <iostream>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace zawa::input {\n\ntemplate <typename\
    \ T> \nvoid in(T& res) { std::cin >> res; }\n\ntemplate <typename Head, typename...\
    \ Tail>\nvoid in(Head& head, Tail&... tail) { in(head); in(tail...); }\n\ntemplate\
    \ <typename T, typename U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second);\
    \ }\n\ntemplate <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res)\
    \ { in(r); } }\n\n} // namespace zawa::input\n"
  code: "#pragma once\n\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \nnamespace zawa::input {\n\ntemplate <typename T> \nvoid in(T& res) { std::cin\
    \ >> res; }\n\ntemplate <typename Head, typename... Tail>\nvoid in(Head& head,\
    \ Tail&... tail) { in(head); in(tail...); }\n\ntemplate <typename T, typename\
    \ U>\nvoid in(std::pair<T, U>& res) { in(res.first); in(res.second); }\n\ntemplate\
    \ <typename T>\nvoid in(std::vector<T>& res) { for (auto& r : res) { in(r); }\
    \ }\n\n} // namespace zawa::input\n"
  dependsOn: []
  isVerificationFile: false
  path: src/template/input.hpp
  requiredBy: []
  timestamp: '2022-12-29 21:37:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/output3.test.cpp
  - test/input2.test.cpp
  - test/input1.test.cpp
  - test/output2.test.cpp
  - test/input5.test.cpp
  - test/input3.test.cpp
  - test/input4.test.cpp
documentation_of: src/template/input.hpp
layout: document
title: "input (\u6A19\u6E96\u5165\u529B)"
---

## 概要

標準入力を受け取ります。

`using namespace zawa::input;`することを前提にしています。

## 機能

`void zawa::input<T> in(T& res)`
- `int`型や`double`型、`string`等の入力を受け取ります

`void zawa::input<T, U> in(std::pair<T, U>& res)`
- `std::pair`型の入力を受け取ります。`first`->`second` の順で代入します

`void zawa::input<T> in(std::vector<T>& res)`
- `std::vector`型の入力を受け取ります。添字に対して昇順に値を代入します。
- 二次元配列に対して使いたい場合は`for (auto a : as) in(a);`みたいにしてください

`void zawa::input<Head, Tail...> in(Head& head, Tail&... tail)`
- 可変長引数版も実装しているので`in(a, b, c, d)`みたいなことができます。

使用例は`test/input~.test.cpp`を参照してください
