---
title: Square Decomposition (平方分割)
documentation_of: //src/dataStructure/Square-Decomposition.hpp
---

## 概要
```
Square_Decomposition<T, T (*op)(T, T), T (*e)()>
```

平方分割によって区間クエリに答えます。

$a \oplus (b \oplus c)\ =\ (a \oplus b) \oplus c$ を満たす演算 $\oplus$ と $e \oplus a\ =\ a$ を満たす元 $e$ が存在するものなら正常に動作します。


## 機能

- `テンプレート引数`: [atcoder::segtree](https://atcoder.github.io/ac-library/document_ja/segtree.html)と同じノリでお願いします
	- 型`T`、演算`op`、単位元`e`

- `コンストラクタ`: 要素数(`int`型、`size_t`は知らん <- カス！) を入れると単位元で配列を初期化します。普通に`T`型の`std::vector`で初期化することもできます

- `update(int id, T value)`: `id`(0-indexed)番目の要素を`value`にします。
	- TODO: `id`番目に`op`を作用させるタイプのupdateを実装する
	- 更新されるバケットの値を返すようにしています

- `query(int l, int r)` $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を返します

- `print_...`: デバッグプリントにお使いください
	- `data`では範囲を、`bucket`では一要素のみを指定することが可能です
	- ただし、`.at()`を使っているので配列外参照をすると死にます(それはいつでもそうか)


## 計算量

- `コンストラクタ`: $O(N)$
- `update`: $O(\sqrt{N})$
- `query`: $O(\sqrt{N})$
