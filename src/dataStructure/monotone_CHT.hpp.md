---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/ABC289-G.test.cpp
    title: test/ABC289-G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/EDPC-Z.test.cpp
    title: test/EDPC-Z.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/monotone_CHT.hpp\"\n\n#include <deque>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class T, bool min>\nclass\
    \ monotone_CHT {\nprivate:\n\tstruct line {\n\t\tT coeff, intercept;\n\t\tline(T\
    \ _coeff, T _intercept) : coeff(_coeff), intercept(_intercept) {}\n\t\tT map(T\
    \ x) {\n\t\t\treturn coeff * x + intercept;\n\t\t}\n\t};\n\n\tstd::deque<line>\
    \ dat;\n\n\tbool is_need(const line& l1, const line& l2, const line& l3) {\n\t\
    \tassert(l1.coeff >= l2.coeff and l2.coeff >= l3.coeff);\n\t\treturn (l1.coeff\
    \ - l2.coeff) * (l2.intercept - l3.intercept) < (l2.coeff - l3.coeff) * (l1.intercept\
    \ - l2.intercept);\n\t}\n\n\tbool manage_front(const line& l) {\n\t\tif (l.coeff\
    \ == dat.front().coeff and l.intercept >= dat.front().intercept) {\n\t\t\treturn\
    \ false;\n\t\t}\n\t\twhile (size() >= 2 and !is_need(l, dat.front(), dat[1]))\
    \ {\n\t\t\tdat.pop_front();\n\t\t}\n\t\treturn true;\n\t}\n\n\tbool manage_back(const\
    \ line& l) {\n\t\tif (l.coeff == dat.back().coeff and l.intercept >= dat.back().intercept)\
    \ {\n\t\t\treturn false;\n\t\t}\n\t\twhile (size() >= 2 and !is_need(dat[size()\
    \ - 2], dat.back(), l)) {\n\t\t\tdat.pop_back();\n\t\t}\n\t\treturn true;\n\t\
    }\n\n\tvoid add(const line& l) {\n\t\tif (empty()) {\n\t\t\tdat.push_back(l);\n\
    \t\t\treturn;\n\t\t}\n\t\tif (l.coeff >= dat.front().coeff) {\n\t\t\tif (manage_front(l))\
    \ {\n\t\t\t\tdat.push_front(l);\n\t\t\t}\n\t\t}\n\t\telse if (dat.back().coeff\
    \ >= l.coeff) {\n\t\t\tif (manage_back(l)) {\n\t\t\t\tdat.push_back(l);\n\t\t\t\
    }\n\t\t}\n\t\telse {\n\t\t\tassert(false);\n\t\t}\n\t}\n\npublic:\n\n\tmonotone_CHT()\
    \ {}\n\n\tinline bool empty() {\n\t\treturn dat.empty();\n\t}\n\n\tinline std::size_t\
    \ size() {\n\t\treturn dat.size();\n\t}\n\n\tinline std::deque<line> _dat() {\n\
    \t\treturn dat;\n\t}\n\n\tvoid add(T coeff, T intercept) {\n\t\tif (!min) {\n\t\
    \t\tcoeff *= -1;\n\t\t\tintercept *= -1;\n\t\t}\n\t\tadd(line(coeff, intercept));\n\
    \t}\n\n\tT incremental_query(T x) {\n\t\tassert(!empty());\n\t\twhile (dat.size()\
    \ >= 2 and dat.front().map(x) >= dat[1].map(x)) {\n\t\t\tdat.pop_front();\n\t\t\
    }\n\t\treturn (min ? 1 : -1) * dat.front().map(x);\n\t}\n\n\tT decremental_query(T\
    \ x) {\n\t\tassert(!empty());\n\t\twhile (dat.size() >= 2 and dat.back().map(x)\
    \ >= dat[size() - 2].map(x)) {\n\t\t\tdat.pop_back();\n\t\t}\n\t\treturn (min\
    \ ? 1 : -1) * dat.back().map(x);\n\t}\n\n\tT query(T x) {\n\t\tassert(!empty());\n\
    \t\tint left = -1, right = size() - 1;\n\t\twhile (right - left > 1) {\n\t\t\t\
    int mid = (left + right) >> 1;\n\t\t\tif (dat[mid].map(x) >= dat[mid + 1].map(x))\
    \ {\n\t\t\t\tleft = mid;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tright = mid;\n\t\t\t\
    }\n\t\t}\n\t\treturn (min ? 1 : -1) * dat[right].map(x);\n\t}\n\t\n};\n\n} //\
    \ namespace zawa\n"
  code: "#pragma once\n\n#include <deque>\n#include <cassert>\n\nnamespace zawa {\n\
    \ntemplate <class T, bool min>\nclass monotone_CHT {\nprivate:\n\tstruct line\
    \ {\n\t\tT coeff, intercept;\n\t\tline(T _coeff, T _intercept) : coeff(_coeff),\
    \ intercept(_intercept) {}\n\t\tT map(T x) {\n\t\t\treturn coeff * x + intercept;\n\
    \t\t}\n\t};\n\n\tstd::deque<line> dat;\n\n\tbool is_need(const line& l1, const\
    \ line& l2, const line& l3) {\n\t\tassert(l1.coeff >= l2.coeff and l2.coeff >=\
    \ l3.coeff);\n\t\treturn (l1.coeff - l2.coeff) * (l2.intercept - l3.intercept)\
    \ < (l2.coeff - l3.coeff) * (l1.intercept - l2.intercept);\n\t}\n\n\tbool manage_front(const\
    \ line& l) {\n\t\tif (l.coeff == dat.front().coeff and l.intercept >= dat.front().intercept)\
    \ {\n\t\t\treturn false;\n\t\t}\n\t\twhile (size() >= 2 and !is_need(l, dat.front(),\
    \ dat[1])) {\n\t\t\tdat.pop_front();\n\t\t}\n\t\treturn true;\n\t}\n\n\tbool manage_back(const\
    \ line& l) {\n\t\tif (l.coeff == dat.back().coeff and l.intercept >= dat.back().intercept)\
    \ {\n\t\t\treturn false;\n\t\t}\n\t\twhile (size() >= 2 and !is_need(dat[size()\
    \ - 2], dat.back(), l)) {\n\t\t\tdat.pop_back();\n\t\t}\n\t\treturn true;\n\t\
    }\n\n\tvoid add(const line& l) {\n\t\tif (empty()) {\n\t\t\tdat.push_back(l);\n\
    \t\t\treturn;\n\t\t}\n\t\tif (l.coeff >= dat.front().coeff) {\n\t\t\tif (manage_front(l))\
    \ {\n\t\t\t\tdat.push_front(l);\n\t\t\t}\n\t\t}\n\t\telse if (dat.back().coeff\
    \ >= l.coeff) {\n\t\t\tif (manage_back(l)) {\n\t\t\t\tdat.push_back(l);\n\t\t\t\
    }\n\t\t}\n\t\telse {\n\t\t\tassert(false);\n\t\t}\n\t}\n\npublic:\n\n\tmonotone_CHT()\
    \ {}\n\n\tinline bool empty() {\n\t\treturn dat.empty();\n\t}\n\n\tinline std::size_t\
    \ size() {\n\t\treturn dat.size();\n\t}\n\n\tinline std::deque<line> _dat() {\n\
    \t\treturn dat;\n\t}\n\n\tvoid add(T coeff, T intercept) {\n\t\tif (!min) {\n\t\
    \t\tcoeff *= -1;\n\t\t\tintercept *= -1;\n\t\t}\n\t\tadd(line(coeff, intercept));\n\
    \t}\n\n\tT incremental_query(T x) {\n\t\tassert(!empty());\n\t\twhile (dat.size()\
    \ >= 2 and dat.front().map(x) >= dat[1].map(x)) {\n\t\t\tdat.pop_front();\n\t\t\
    }\n\t\treturn (min ? 1 : -1) * dat.front().map(x);\n\t}\n\n\tT decremental_query(T\
    \ x) {\n\t\tassert(!empty());\n\t\twhile (dat.size() >= 2 and dat.back().map(x)\
    \ >= dat[size() - 2].map(x)) {\n\t\t\tdat.pop_back();\n\t\t}\n\t\treturn (min\
    \ ? 1 : -1) * dat.back().map(x);\n\t}\n\n\tT query(T x) {\n\t\tassert(!empty());\n\
    \t\tint left = -1, right = size() - 1;\n\t\twhile (right - left > 1) {\n\t\t\t\
    int mid = (left + right) >> 1;\n\t\t\tif (dat[mid].map(x) >= dat[mid + 1].map(x))\
    \ {\n\t\t\t\tleft = mid;\n\t\t\t}\n\t\t\telse {\n\t\t\t\tright = mid;\n\t\t\t\
    }\n\t\t}\n\t\treturn (min ? 1 : -1) * dat[right].map(x);\n\t}\n\t\n};\n\n} //\
    \ namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/monotone_CHT.hpp
  requiredBy: []
  timestamp: '2023-02-22 23:27:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/ABC289-G.test.cpp
  - test/EDPC-Z.test.cpp
documentation_of: src/dataStructure/monotone_CHT.hpp
layout: document
title: "monotone_CHT (\u8FFD\u52A0\u76F4\u7DDA\u306E\u50BE\u304D\u304C\u5358\u8ABF\
  \u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u305FCHT)"
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
