---
title: sorted (ソート列を返す)
documentation_of: //src/template/sorted.hpp
---

## 概要

引数で与えた列に対してソートした列を返します。引数で与えた列は破壊されません

## 機能

```
std::vector<T> zawa::util::sorted<T>(std::vector<T> A)
std::string zawa::util::sorted(std::string s)
```

`using namespace zawa::util`することを前提としています。
