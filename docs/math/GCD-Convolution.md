---
title: GCD Convlution (添字gcd畳み込み、約数集合の高速ゼータ/メビウス変換)
documentation_of: //src/math/GCD-Convolution.hpp
---

## 概要
```
GCD_Convolution<T>
```

列`f`、`g`に対して $\displaystyle h_i\ =\ \sum_{gcd(j, k)=i} f_j\times g_k$ を満たす列 $h$ を求めます。

内部で約数集合の高速ゼータ変換、約数集合における高速メビウス変換をしているのでそちらを使いたい際もこれをincludeしてください。

約数集合の高速ゼータ変換とは列`f`に対して $\displaystyle F_i\ =\ \sum_{i\mid j} f_j$ を満たす`F`を求めることです。

約数集合の高速メビウス変換とは列`F`に対して $f_i\ =\ \sum_{i\mid j} \mu (\frac{j}{i}) F_j$ を求めることです。 $\mu$ はメビウス関数を表します。この操作は約数集合の高速ゼータ変換の逆変換です。


## 機能

- `コンストラクタ`: 内部で使用するエラトステネスの篩を初期化します。変換したい列のサイズの最大数を超える値を引数に入れてください(32bit)

- `fast_zeta_transform`: 約数集合の高速ゼータ変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

- `fast_mobius_transform`: 約数集合の高速メビウス変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

- `convolution`: 添字gcd畳み込みを行います。結果を`std::vector<T>`の型で返します。畳み込みを行いたい二つの列の参照を引数にとります。

## 計算量

- `コンストラクタ`: 引数 $N$ に対して $O(N log(log\ N))$
- `fast_zeta_transform、fast_mobius_transform`: 列の長さを $N$ として $O(Nlog(log\ N))$
- `convolution`: 列の長さをそれぞれ $N, M$ として $O(max(N, M) log (log\ max(N, M)))$

## これは結局なんなの
TODO:: NOTE


## 参考
[https://qiita.com/drken/items/3beb679e54266f20ab63]
