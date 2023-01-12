---
title: sparsetable gcd-structure
documentation_of: //src/utility/sparse-table/gcd.hpp
---

## 概要

Sparse Tableで区間最小公倍数クエリを処理したい時に、`zawa::sparse_table<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::gcd_structure<dat_type>`
- `dat_type`
	- `int`や`long long`など、`std::gcd`に突っ込むことができる型
