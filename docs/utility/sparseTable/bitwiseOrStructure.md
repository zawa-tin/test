---
title: bitwiseOrStructure (Sparse Table)
documentation_of: //src/utility/sparseTable/bitwiseOrStructure.hpp
---

## 概要

Sparse Tableで区間bitwise orクエリを処理したい時に、`zawa::sparseTable<T>`の`structure`に入れる構造体です。

## 機能

`zawa::bitwiseOrStructure<T>`
- `T`
	- `int`や`long long`など、`operator |`が定義されているもの
- **単体テストをまだしていません**
