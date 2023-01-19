---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/persistent-array.test.cpp
    title: test/persistent-array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/persistent-array.hpp\"\n\n#include <vector>\n\
    #include <cstring>\n\nnamespace zawa {\n\ntemplate <class T, std::size_t M = 20>\n\
    class persistent_array {\nprivate:\n\tstruct node;\n\tusing nodeptr = node*;\n\
    \tstruct node {\n\t\tT value;\n\t\tnodeptr children[M];\n\t};\n\tstd::vector<nodeptr>\
    \ roots;\n\n\tvoid build(std::size_t idx, const T& value, nodeptr now) {\n\t\t\
    if (idx == 0) {\n\t\t\tnow->value = value;\n\t\t\treturn;\n\t\t}\n\t\tif (now->children[idx\
    \ % M] == nullptr) {\n\t\t\tnow->children[idx % M] = new node();\n\t\t}\n\t\t\
    build(idx / M, value, now->children[idx % M]);\n\t}\n\n\tT get(std::size_t idx,\
    \ const nodeptr& now) {\n\t\tif (idx == 0) {\n\t\t\treturn now->value;\n\t\t}\n\
    \t\treturn get(idx / M, now->children[idx % M]);\n\t}\n\n\tnodeptr set(const nodeptr&\
    \ comp, std::size_t idx, const T& value) {\n\t\tnodeptr res = new node();\n\t\t\
    if (comp != nullptr) {\n\t\t\tstd::memcpy(res->children, comp->children, sizeof(comp->children));\n\
    \t\t}\n\t\tres->value = (idx == (std::size_t)0 ? value : comp->value);\n\t\tif\
    \ (idx != (std::size_t)0) {\n\t\t\tres->children[idx % M] = set(comp->children[idx\
    \ % M], idx / M, value);\n\t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\tpersistent_array(const\
    \ std::vector<T>& as) {\n\t\troots.push_back(new node());\n\t\tfor (std::size_t\
    \ i = 0 ; i < as.size() ; i++) {\n\t\t\tbuild(i, as[i], roots.front());\n\t\t\
    }\n\t}\n\n\tpersistent_array(std::size_t n) {\n\t\troots.push_back(new node());\n\
    \t\tfor (std::size_t i = 0 ; i < n ; i++) {\n\t\t\tbuild(i, T(), roots.front());\n\
    \t\t}\n\t}\n\n\tT get(int time, std::size_t idx) {\n\t\treturn get(idx, roots[time]);\n\
    \t}\n\n\tvoid set(int time, std::size_t idx, const T& val) {\n\t\troots.push_back(set(roots[time],\
    \ idx, val));\n\t\treturn;\n\t}\n\n\tstd::size_t size() {\n\t\treturn roots.size();\n\
    \t}\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cstring>\n\nnamespace zawa {\n\
    \ntemplate <class T, std::size_t M = 20>\nclass persistent_array {\nprivate:\n\
    \tstruct node;\n\tusing nodeptr = node*;\n\tstruct node {\n\t\tT value;\n\t\t\
    nodeptr children[M];\n\t};\n\tstd::vector<nodeptr> roots;\n\n\tvoid build(std::size_t\
    \ idx, const T& value, nodeptr now) {\n\t\tif (idx == 0) {\n\t\t\tnow->value =\
    \ value;\n\t\t\treturn;\n\t\t}\n\t\tif (now->children[idx % M] == nullptr) {\n\
    \t\t\tnow->children[idx % M] = new node();\n\t\t}\n\t\tbuild(idx / M, value, now->children[idx\
    \ % M]);\n\t}\n\n\tT get(std::size_t idx, const nodeptr& now) {\n\t\tif (idx ==\
    \ 0) {\n\t\t\treturn now->value;\n\t\t}\n\t\treturn get(idx / M, now->children[idx\
    \ % M]);\n\t}\n\n\tnodeptr set(const nodeptr& comp, std::size_t idx, const T&\
    \ value) {\n\t\tnodeptr res = new node();\n\t\tif (comp != nullptr) {\n\t\t\t\
    std::memcpy(res->children, comp->children, sizeof(comp->children));\n\t\t}\n\t\
    \tres->value = (idx == (std::size_t)0 ? value : comp->value);\n\t\tif (idx !=\
    \ (std::size_t)0) {\n\t\t\tres->children[idx % M] = set(comp->children[idx % M],\
    \ idx / M, value);\n\t\t}\n\t\treturn res;\n\t}\n\t\npublic:\n\tpersistent_array(const\
    \ std::vector<T>& as) {\n\t\troots.push_back(new node());\n\t\tfor (std::size_t\
    \ i = 0 ; i < as.size() ; i++) {\n\t\t\tbuild(i, as[i], roots.front());\n\t\t\
    }\n\t}\n\n\tpersistent_array(std::size_t n) {\n\t\troots.push_back(new node());\n\
    \t\tfor (std::size_t i = 0 ; i < n ; i++) {\n\t\t\tbuild(i, T(), roots.front());\n\
    \t\t}\n\t}\n\n\tT get(int time, std::size_t idx) {\n\t\treturn get(idx, roots[time]);\n\
    \t}\n\n\tvoid set(int time, std::size_t idx, const T& val) {\n\t\troots.push_back(set(roots[time],\
    \ idx, val));\n\t\treturn;\n\t}\n\n\tstd::size_t size() {\n\t\treturn roots.size();\n\
    \t}\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/persistent-array.hpp
  requiredBy: []
  timestamp: '2023-01-19 08:51:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/persistent-array.test.cpp
documentation_of: src/dataStructure/persistent-array.hpp
layout: document
title: persistent array
---

## 概要

$M$ 分木によって実装された完全永続配列です。

列 $A$ に対して、 $i$ 番目のバージョンを $A^i$ と表現するとして、
- $A^t_i$ を $p$ に変更したものを新バージョンとする
- $A^t_i$ を求める

というクエリをすべてのバックアップを取る愚直な手法より高速に求めることが可能です。

## 機能 

**コンストラクタ**

`persistent_array<T, M = 20>(const std::vector<T>& as)`
- 列 `as` で $A$ を初期化する。  $A^0\ =$ `as` となる
- `T`: `as` の型
- `M`: $M$ 分木によって永続配列を表現する
	- 特に指定がない場合、 $M\ =\ 20$ とする
- **計算量** $O(N\log N)$

`persistent_array<T, M = 20>(std::size_t n)`
- $A$ を要素数 $n$ ですべての要素が `T()` である列で初期化する。
- 他、同上計算量

**メンバ関数**

`T get(int time, std::size_t idx)`
- $A^{\text{time}}$ の`idx`番目の要素を取得する。
	- `time` が現行バージョンを超えないように注意
- **計算量** : $O(\log N)$ 

`void set(int time, std::size_t idx, const T& val)`
- $A^\text{time}$ の`idx`番目の要素を`val`に変更したものを最新バージョンとする
- `time`が現行バージョンを超えないように注意
- **計算量** : $O(M\log N)$

`std::size_t size()`
- バージョンの数を取得する
- 最新バージョンは`size() - 1`であるといえる
- **計算量** : $O(1)$
