---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Floyd-Cycle-Detection.test.cpp
    title: test/Floyd-Cycle-Detection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/Floyd-Cycle-Detection.hpp\"\n\nnamespace zawa::impl\
    \ {\n\ntemplate <class T>\nstruct Cycle_Info {\n    T start;\n    int length;\n\
    };\n\n} // namespace zawa::impl\n\nnamespace zawa {\n\ntemplate <class T, class\
    \ F>\nimpl::Cycle_Info<T> floyd(T s, const F& nxt, int limit = 50000000) {\n \
    \   T turtle = s, rabbit = s;\n    int check = 0;\n    for ( ; check < limit ;\
    \ check++) {\n        turtle = nxt(turtle);\n        rabbit = nxt(nxt(rabbit));\n\
    \        if (turtle == rabbit) {\n            break;\n        }\n    }\n    if\
    \ (check == limit) {\n        return { s, -1 };\n    }\n    rabbit = s;\n    while\
    \ (1) {\n        rabbit = nxt(rabbit);\n        turtle = nxt(turtle);\n      \
    \  if (rabbit == turtle) {\n            break;\n        }\n    }\n    T start\
    \ = turtle;\n    int length = 0;\n    while (1) {\n        length++;\n       \
    \ turtle = nxt(turtle);\n        rabbit = nxt(nxt(rabbit));\n        if (turtle\
    \ == rabbit) {\n            break;\n        }\n    }\n    return { start, length\
    \ };\n}\n\n} // namespace zawa\n"
  code: "#pragma once\n\nnamespace zawa::impl {\n\ntemplate <class T>\nstruct Cycle_Info\
    \ {\n    T start;\n    int length;\n};\n\n} // namespace zawa::impl\n\nnamespace\
    \ zawa {\n\ntemplate <class T, class F>\nimpl::Cycle_Info<T> floyd(T s, const\
    \ F& nxt, int limit = 50000000) {\n    T turtle = s, rabbit = s;\n    int check\
    \ = 0;\n    for ( ; check < limit ; check++) {\n        turtle = nxt(turtle);\n\
    \        rabbit = nxt(nxt(rabbit));\n        if (turtle == rabbit) {\n       \
    \     break;\n        }\n    }\n    if (check == limit) {\n        return { s,\
    \ -1 };\n    }\n    rabbit = s;\n    while (1) {\n        rabbit = nxt(rabbit);\n\
    \        turtle = nxt(turtle);\n        if (rabbit == turtle) {\n            break;\n\
    \        }\n    }\n    T start = turtle;\n    int length = 0;\n    while (1) {\n\
    \        length++;\n        turtle = nxt(turtle);\n        rabbit = nxt(nxt(rabbit));\n\
    \        if (turtle == rabbit) {\n            break;\n        }\n    }\n    return\
    \ { start, length };\n}\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/Floyd-Cycle-Detection.hpp
  requiredBy: []
  timestamp: '2022-10-07 02:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Floyd-Cycle-Detection.test.cpp
documentation_of: src/algorithm/Floyd-Cycle-Detection.hpp
layout: document
title: "Floyd's Cycle Detection (\u30D5\u30ED\u30A4\u30C9\u306E\u5FAA\u74B0\u691C\u51FA\
  \u6CD5)"
---

## 概要
```
impl::Cycle_Info<T> floyd(T s, const F& nxt, int limit = 50000000)
```

有限集合 $A$ の写像 $f$ に関する数列 $s,\ f(s),\ f(f(s)),\ \cdots$ の循環を検出する

## 機能

- 第一引数: 数列の初項
- 第二引数: 写像
- 第三引数: 循環が存在しないと決め打つ項数
	- 鳩の巣原理から $limit\ >\ \mid A \mid$ にしておけばまぁ問題ないはず

- 返り値
	- `T Cycle_Info::start`: 循環開始地点の数列の値
	- `int Cycle_Info::length`: 循環の長さ

## 計算量
$O(\mid A \mid)$
