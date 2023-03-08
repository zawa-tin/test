---
title: ccw (ベクトルの位置関係)
documentation_of: //src/geometryR2/ccw.hpp
---

## 概要

二次元平面上の２つのベクトル $\vec{a}, \vec{b}$ の位置関係を調べます。

## 機能

`namespace geoR2`上で定義されています。

#### enum class

**CCW**
```
enum class CCW {
	COUNTER_CLOCKWISE,
	CLOCKWISE,
	ONLINE_BACK,
	LNLINE_FRONT,
	ON_SEGMENT,
};
```

位置関係をこの5種類に分類します。意味はそれぞれ以下の通りです。

**COUNTER_CLOCKWISE**

$\vec{a}$ を反時計周りに $\theta\ (0\ <\ \theta\ <\ \pi )$ 回転すると$\vec{b}$ と向きが一致する


**CLOCKWISE**

$\vec{a}$ を時計周りに $\theta\ (0\ <\ \theta\ <\ \pi )$ 回転すると$\vec{b}$ と向きが一致する

**ONLINE_BACK**

$\vec{a}$ を $\pi$ 回転すると $\vec{b}$ と向きが一致する


**ONLINE_FRONT**

$k\vec{a} = \vec{b}\ (k > 1, k\in \mathbb{R})$ を満たす $k$ が存在する

**ON_SEGMENT**

$k\vec{a} = \vec{b}\ (0\ \le\ k\ \le\ 1, k\in \mathbb{R})$ を満たす $k$ が存在する

<br />

#### 関数

**ccw**
```
CCW ccw(const vec2& a, const vec2& b)
```

$\vec{a}$ と $\vec{b}$ が前述の`CCW`でどの関係にあるかを返す。
