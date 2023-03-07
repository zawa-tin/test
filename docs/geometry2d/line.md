---
title: line (直線)
documentation_of: //src/geometry2d/line.hpp
---

## 概要

二次元平面上の直線を扱う構造体

２つの異なる点によって直線を定義する

## 機能

`namespace geo2d`下で定義されている

**コンストラクタ**
```
line(const point& _a, const point& _b)
```

**制約**

`_a`と`_b`が異なる。すなわち`equals(_a, _b)`が`false`
