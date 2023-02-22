---
title: monotone_CHT (追加直線の傾きが単調であることを仮定したCHT)
documentation_of: //src/dataStructure/monotone_CHT.hpp
---

## 概要

巷でConvex Hull Trickと言われているテクニック(?)です

一次関数 $f(x) = ax + b$ の集合 $S$ に関して以下のクエリを処理します

- $S$ に $f(x)$ を追加
- $\displaystyle \min_{f\in S} (f(x))$ を得る( $\max$ も可)


## 機能

#### コンストラクタ

```
zawa::monotone_CHT<T, min>()
```
$S\ =\ \phi$ とする
- `T`: $ax + b$ の型
- `min`: `bool`値、`get` クエリで最小値を求めたい場合は `true`、最大値を求めたい場合は`false`を入れること

**計算量** : $O(1)$
<br />

#### メンバ関数

```
inline bool empty()
```
$S\ =\phi$ かどうかを返す
- 直線が存在しないなら`true`、存在するなら`false`を返す

**計算量** : $O(1)$

<br />

```
inline std::size_t size()
```
現在の $\mid S\mid$ を返す。
- ただし、`incremental_query`や`decremental_query`を使用している場合、追加した直線の数が入っているとは限らないです。なぜなら、もう取得クエリが飛んでこないと保証されている区間のみで最小値を取る直線が破棄されているからです。

**計算量** : $O(1)$

<br />

```
inline std::deque<line> _dat()
```
内部で使用しているコンテナを返します。

 `line`・・・ $f(x)\ =\ ax + b$ を表現している構造体

```
struct line {
	T coeff, intercept;
	T map(T x) {
		return coeff * x + intercept;
	}
};
```
- `coeff`: $a$
- `intercept`: $b$
- `map(x)`: $f(x)$ を得ます

**計算量** : $O(\mid S\mid)$

<br />

```
void add(T a, T b)
```
$S$ に $f(x)\ =\ ax + b$ を追加します
- `T a`: $a$
- `T b`: $b$

**制約**

**全ての $(a'x\ +\ b')\in S$ について $a\ \le\ a'$ が成り立つ、または全ての $(a'x\ +\ b')\in S$ について $a\ \ge\ a'$ が成り立つ。**

**計算量**: $O(1)$ (ならし計算量? 作った当時の自分はよく分かってないです)

<br />

```
T incremental_query(T x)
```

$\displaystyle \min_{f\in S} (f(x))$ を得ます
- コンストラクタでテンプレート引数の`min`を`false`にしていた場合は $\displaystyle \max_{f\in S} (f(x))$ を得ます

**制約**
- `add`を一回以上呼び出している
	- そうでないと $S\ =\phi$ より最小値が定義できないので`assert`に引っかかって死にます
- 以前の取得クエリの $x$ より、 $x$ の値が大きい(等しくてもOK)
- `decremental_query`を呼び出していない
	- どちらかでも満たされない場合、正しい値を返すとは限りません

**計算量** : ならし $O(1)$ ?

<br />

```
T decremental_query(T x)
```

$\displaystyle \min_{f\in S} (f(x))$ を得ます
- コンストラクタでテンプレート引数の`min`を`false`にしていた場合は $\displaystyle \max_{f\in S} (f(x))$ を得ます

**制約**
- `add`を一回以上呼び出している
	- そうでないと $S\ =\phi$ より最小値が定義できないので`assert`に引っかかって死にます
- 以前の取得クエリの $x$ より、 $x$ の値が小さい(等しくてもOK)
- `incremental_query`を呼び出していない
	- どちらかでも満たされない場合、正しい値を返すとは限りません

**このメンバはまだ未テストです**

**計算量** : ならし $O(1)$ ?

<br />

```
T query(T x)
```

$\displaystyle \min_{f\in S} (f(x))$ を得ます
- コンストラクタでテンプレート引数の`min`を`false`にしていた場合は $\displaystyle \max_{f\in S} (f(x))$ を得ます

**制約**
- `add`を一回以上呼び出している
	- そうでないと $S\ =\phi$ より最小値が定義できないので`assert`に引っかかって死にます
- `incremental_query`、`decremental_query`を呼び出していない
	- 呼び出していると正しい値を返すとは限りません

`ABC289-G`で`incremental_query`ではなく`query`を用いた場合でもACすることを確認しています。

**計算量** : $O(\log \mid S\mid)$
