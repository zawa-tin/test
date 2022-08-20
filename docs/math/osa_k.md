---
title: osa_k (複数要素の約数列挙・素因数分解)
documentation_of: //src/math/osa_k.hpp
---

## 概要
```
osa_k(int n)
```

エラトステネスの篩のアルゴリズムを用いた前準備を行うことで $N$ 以下の要素の約数列挙・素因数分解を（試し割りを用いたアルゴリズムより）高速に行う。

エラトステネスの篩を行うと同時にそれぞれの数の最小素因数を記録することで実現している。

## 機能
* `コンストラクタ`: 最小素因数を記録するテーブルを構築する

* `factorize(int x)`: 素因数分解を`std::vector<std::pair<int, int>>`の型で返す。`first`が素因数、`second`が次数です。

* `divisor(int x)`: 約数列挙を`std::vector<int>`の型で返す。

$0 \ \le\ x\ \le\ N$ を満たさない数は空列を返すように実装している。（実装した後に思ったけどバグってもらったほうが良い気がしてきた)

## 計算量

* `コンストラクタ`: $O(Nlog(log\ N))$

* `factorize`、`divisor`: $O(log\ x)$

## 参考
 
https://qiita.com/drken/items/3beb679e54266f20ab63

https://osak.jp/diary/diary_201310.html#20131017
