---
title: sparsetable bitwise_or-structure
documentation_of: //src/utility/sparse-table/bitwise_or.hpp
---

## 概要

Sparse Tableで区間bitwise orクエリを処理したい時に、`zawa::sparse_table<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::bitwise_or_structure<dat_type>`
- `dat_type`
	- `int`や`long long`など、`operator |`が定義されているもの
- **単体テストをまだしていません**
