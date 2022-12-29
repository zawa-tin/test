---
title: input (標準入力)
documentation_of: //src/template/input.hpp
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
