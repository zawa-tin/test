---
title: gcdConvlution (添字gcd畳み込み・約数系の高速ゼータ/メビウス変換)
documentation_of: //src/math/gcdConvolution.hpp
---

## 概要

列`f`、`g`に対して $\displaystyle h_i\ =\ \sum_{\gcd(j, k)=i} f_j\times g_k$ を満たす列 $h$ を求めます。

内部で約数集合の高速ゼータ変換、約数集合における高速メビウス変換をしているのでそちらを使いたい際もこれをincludeしてください。

約数集合の高速ゼータ変換とは列`f`に対して $\displaystyle F_i\ =\ \sum_{i\mid j} f_j$ を満たす`F`を求めることです。

約数集合の高速メビウス変換とは列`F`に対して $f_i\ =\ \sum_{i\mid j} \mu (\frac{j}{i}) F_j$ を求めることです。 $\mu$ はメビウス関数を表します。この操作は約数集合の高速ゼータ変換の逆変換です。


## 機能

#### コンストラクタ

```
zawa::gcdConvolution<T>(std::size_t n)
```

内部で使用するエラトステネスの篩を初期化します。変換したい列のサイズの最大数を超える値を引数`n`に入れてください

**計算量**

$O(n\log (\log n))$

<br />

#### メンバ

**fastZetaTransform**
```
std::vector<T> fastZetaTransform(const std::vector<T>& f) const
```

約数集合の高速ゼータ変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

**計算量**

 $O(n\log (\log n))$

<br />

**fastMobiusTransform**
```
std::vector<T> fastMobiusTransform(const std::vector<T>& F) const
```
約数集合の高速メビウス変換を行います。変換後の列が`std::vector<T>`の型で返されます。変換を行いたい`std::vector`の参照を引数にとります。

**計算量**

$O(n\log (\log n))$

<br />

**convolution**
```
std::vector<T> convolution(const std::vector<T>& f, const std::vector<T>& f) const
```

添字gcd畳み込みを行います。結果を`std::vector<T>`の型で返します。畳み込みを行いたい二つの列の参照を引数にとります。

**計算量**

$O(n\log (\log n))$


## これは結局なんなの
TODO: NOTE

## 参考

[# エラトステネスの篩の活用法を総特集！ 〜 高速素因数分解・メビウスの反転公式 〜](https://qiita.com/drken/items/3beb679e54266f20ab63)
