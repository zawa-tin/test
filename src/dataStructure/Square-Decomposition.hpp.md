---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Square-Decomposition-RSQ.test.cpp
    title: test/Square-Decomposition-RSQ.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/Square-Decomposition-RmQ.test.cpp
    title: test/Square-Decomposition-RmQ.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Square-Decomposition.hpp\"\n\n#include\
    \ <vector>\n#include <cmath>\n#include <algorithm>\n#include <iostream>\n\nnamespace\
    \ zawa {\n\ntemplate <class T, T (*op)(T, T), T (*e)()>\nclass Square_Decomposition\
    \ {\n\nprivate:\n    int square;\n    int size;\n    std::vector<T> data;\n  \
    \  std::vector<T> bucket;\n\n    T update(int id) {\n        T res = e();\n  \
    \      for (int i = id * square ; i < std::min((int)data.size(), (id + 1) * square)\
    \ ; i++) {\n            res = op(res, data[i]);\n        }\n        bucket[id]\
    \ = res;\n        return res;\n    }\n\npublic:\n    Square_Decomposition(int\
    \ n)\n        : square(std::sqrt(n + 1))\n        , size((n + square - 1) / square)\n\
    \        , data(n, e())\n        , bucket(size, e()) {}\n\n    Square_Decomposition(std::vector<T>\
    \ as)\n        : square(std::sqrt((int)as.size() + 1))\n        , size(((int)as.size()\
    \ + square - 1) / square)\n        , data(as.begin(), as.end())\n        , bucket(size,\
    \ e()) {\n\n        for (int i = 0 ; i < size ; i++) {\n            update(i);\n\
    \        }\n    }\n\n    T update(int pos, T value) {\n        data[pos] = value;\n\
    \        return update(pos / square);\n    }\n\n    T query(int l, int r) {\n\
    \        T res = e(); \n        for (int i = 0 ; i < size ; i++) {\n         \
    \   int p = i * square, q = (i + 1) * square;\n            if (q <= l and r <=\
    \ p) {\n                continue;\n            }\n            if (l <= p and q\
    \ <= r) {\n                res = op(res, bucket[i]);\n            }\n        \
    \    else {\n                for (int j = std::max(l, p) ; j < std::min(r, q)\
    \ ; j++) {\n                    res = op(res, data[j]);\n                }\n \
    \           }\n        }\n        return res;\n    }\n\n    void print_data()\
    \ {\n        for (size_t i = 0 ; i < data.size() ; i++) {\n            std::cout\
    \ << data[i] << (i == data.size() - 1 ? '\\n' : ' ');\n        }\n    }\n\n  \
    \  void print_data(int l, int r) {\n        for (int i = l ; i < r ; i++) {\n\
    \            std::cout << data.at(i) << (i == r - 1 ? '\\n' : ' ');\n        }\n\
    \    }\n    \n    void print_bucket() {\n        for (auto buc : bucket) {\n \
    \           std::cout << buc << ' ';\n        }\n        std::cout << std::endl;\n\
    \    }\n    \n    void print_bucket(int id) {\n        std::cout << bucket.at(id)\
    \ << std::endl;\n    }\n\n};\n\n} // namespace zawa\n"
  code: "#pragma once\n\n#include <vector>\n#include <cmath>\n#include <algorithm>\n\
    #include <iostream>\n\nnamespace zawa {\n\ntemplate <class T, T (*op)(T, T), T\
    \ (*e)()>\nclass Square_Decomposition {\n\nprivate:\n    int square;\n    int\
    \ size;\n    std::vector<T> data;\n    std::vector<T> bucket;\n\n    T update(int\
    \ id) {\n        T res = e();\n        for (int i = id * square ; i < std::min((int)data.size(),\
    \ (id + 1) * square) ; i++) {\n            res = op(res, data[i]);\n        }\n\
    \        bucket[id] = res;\n        return res;\n    }\n\npublic:\n    Square_Decomposition(int\
    \ n)\n        : square(std::sqrt(n + 1))\n        , size((n + square - 1) / square)\n\
    \        , data(n, e())\n        , bucket(size, e()) {}\n\n    Square_Decomposition(std::vector<T>\
    \ as)\n        : square(std::sqrt((int)as.size() + 1))\n        , size(((int)as.size()\
    \ + square - 1) / square)\n        , data(as.begin(), as.end())\n        , bucket(size,\
    \ e()) {\n\n        for (int i = 0 ; i < size ; i++) {\n            update(i);\n\
    \        }\n    }\n\n    T update(int pos, T value) {\n        data[pos] = value;\n\
    \        return update(pos / square);\n    }\n\n    T query(int l, int r) {\n\
    \        T res = e(); \n        for (int i = 0 ; i < size ; i++) {\n         \
    \   int p = i * square, q = (i + 1) * square;\n            if (q <= l and r <=\
    \ p) {\n                continue;\n            }\n            if (l <= p and q\
    \ <= r) {\n                res = op(res, bucket[i]);\n            }\n        \
    \    else {\n                for (int j = std::max(l, p) ; j < std::min(r, q)\
    \ ; j++) {\n                    res = op(res, data[j]);\n                }\n \
    \           }\n        }\n        return res;\n    }\n\n    void print_data()\
    \ {\n        for (size_t i = 0 ; i < data.size() ; i++) {\n            std::cout\
    \ << data[i] << (i == data.size() - 1 ? '\\n' : ' ');\n        }\n    }\n\n  \
    \  void print_data(int l, int r) {\n        for (int i = l ; i < r ; i++) {\n\
    \            std::cout << data.at(i) << (i == r - 1 ? '\\n' : ' ');\n        }\n\
    \    }\n    \n    void print_bucket() {\n        for (auto buc : bucket) {\n \
    \           std::cout << buc << ' ';\n        }\n        std::cout << std::endl;\n\
    \    }\n    \n    void print_bucket(int id) {\n        std::cout << bucket.at(id)\
    \ << std::endl;\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Square-Decomposition.hpp
  requiredBy: []
  timestamp: '2022-10-26 10:25:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Square-Decomposition-RmQ.test.cpp
  - test/Square-Decomposition-RSQ.test.cpp
documentation_of: src/dataStructure/Square-Decomposition.hpp
layout: document
title: "Square Decomposition (\u5E73\u65B9\u5206\u5272)"
---

## 概要
```
Square_Decomposition<T, T (*op)(T, T), T (*e)()>
```

平方分割によって区間クエリに答えます。

$a \oplus (b \oplus c)\ =\ (a \oplus b) \oplus c$ を満たす演算 $\oplus$ と $e \oplus a\ =\ a$ を満たす元 $e$ が存在するものなら正常に動作します。


## 機能

- `テンプレート引数`: [atcoder::segtree](https://atcoder.github.io/ac-library/document_ja/segtree.html)と同じノリでお願いします
	- 型`T`、演算`op`、単位元`e`

- `コンストラクタ`: 要素数(`int`型、`size_t`は知らん <- カス！) を入れると単位元で配列を初期化します。普通に`T`型の`std::vector`で初期化することもできます

- `update(int id, T value)`: `id`(0-indexed)番目の要素を`value`にします。
	- TODO: `id`番目に`op`を作用させるタイプのupdateを実装する
	- 更新されるバケットの値を返すようにしています

- `query(int l, int r)` $\displaystyle \bigoplus_{i = l}^{r - 1} A_i$ を返します

- `print_...`: デバッグプリントにお使いください
	- `data`では範囲を、`bucket`では一要素のみを指定することが可能です
	- ただし、`.at()`を使っているので配列外参照をすると死にます(それはいつでもそうか)


## 計算量

- `コンストラクタ`: $O(N)$
- `update`: $O(\sqrt{N})$
- `query`: $O(\sqrt{N})$
