---
title: relation (オブジェクト同士の位置関係)
documentation_of: //src/geometryR2/relation.hpp
---

## 概要

線分や点、直線等の関係を評価する関数をまとめたヘッダです。

## 機能

全て`namespace geometryR2`上で定義されていｒます。

**isOrthogonal**
```
(1) bool isOrthogonal(const line& l1, const line& l2)
```

**(1)**

直線 $l_1, l_2$ が直交しているかを判定する

<br />

**isParallel**
```
(1) bool isParallel(const line& l1, const line& l2)
```

**(1)**

直線 $l_1, l_2$ が平行であるかを判定する

<br />

**isIntersect**
```
(1) bool isIntersect(const segment& s1, const segment& s2)
```

線分 $s_1, s_2$ が交点を持つかを判定する
