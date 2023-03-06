---
title: sparsetable bitwiseAndStructure (Sparse Table)
documentation_of: //src/utility/sparseTable/bitwiseAndStructure.hpp
---

## 概要

Sparse Tableで区間bitwise andクエリを処理したい時に、`zawa::sparseTable<structure>`の`structure`に入れる構造体です。

## 機能

`zawa::bitwiseAndStructure<T>`
- `T`
	- `int`や`long long`など、`operator &`が定義されているもの
- **単体テストをまだしていません**
