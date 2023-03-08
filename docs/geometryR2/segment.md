---
title: segment (線分)
documentation_of: //src/geometryR2/segment.hpp
---

## 概要

線分を管理する構造体

## 機能

`namespace geoR2`上で定義される

#### メンバ変数

**e1**
```
point e1
```
端点

<br />

**e2**
```
point e2
```

端点

<br />

#### コンストラクタ

```
(1) segment()
(2) segment(const point& _e1, const point& _e2)
```

**(1)**

端点を両方とも原点で初期化する。これは線分として有効では無いので利用する際は値の再代入が必要です

<br />

**(2)**

端点を $e_1, e_2$ で初期化する。$e_1\ =\ e_2$ である時は線分として有効で無いため色んな関数で`assert`に引っかかりまくります。かわいそう

<br />

#### メンバ関数

**isValid**
```
bool isValid() const
```

線分が有効かを判定する。

$e_1 \ne e_2$ なら`true`を返す。
