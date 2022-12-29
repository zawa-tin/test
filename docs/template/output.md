---
title: output (標準出力)
documentation_of: //src/template/output.hpp
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
