---
title: line (直線)
documentation_of: //src/geometryR2/line.hpp
---

## 概要

二次元平面上の直線を扱う構造体

２つの異なる点 $a, b$ によって直線を定義する

## 機能

`namespace geoR2`下で定義されている

#### コンストラクタ
```
(1)line()
(2)line(const point& _a, const point& _b)
```

**(1)**

$a$ と $b$ を原点で初期化する。これは直線として有効でないので利用する際は値の再代入が必要である。

<br />

**(2)**

$a$ と $b$ を引数の値で初期化する

<br />

#### メンバ関数

**isValid**
```
bool isValid() cosnt
```

直線が正しく定義されているかを判定する。すなわち $a\ne b$ だと`true`を返す。

<br />

#### 関数

**isOrthogonal**
```
bool isOrthogonal(const line& l1, const line& l2)
```

直線 $l1, l2$ が直交するかを判定する

**制約**
- `l1.isValid()`がTrue
- `l2.isValid()`がTrue

<br />

**isParallel**
```
bool isParallel(const line& l1, const line& l2)
```

直線 $l1, l2$ が平行であるかを判定する

**制約**
- `l1.isValid()`がTrue
- `l2.isValid()`がTrue
