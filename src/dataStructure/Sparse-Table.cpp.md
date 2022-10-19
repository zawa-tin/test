---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Sparse-Table.test.cpp
    title: test/Sparse-Table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/dataStructure/Sparse-Table.cpp\"\n#include <vector>\n\
    \nnamespace zawa {\n\ntemplate <class T, T (*op)(T, T)>\nclass Sparse_Table {\n\
    private:\n    std::vector<std::vector<T>> table;\n\npublic:\n    Sparse_Table(std::vector<T>\
    \ as) \n        : table(std::__lg(as.size()) + 1, std::vector(as.size(), 0)) {\n\
    \            \n        for (std::size_t i = 0 ; i < as.size() ; i++) {\n     \
    \       table[0][i] = as[i];\n        }\n\n        for (std::size_t i = 1 ; i\
    \ < table.size() ; i++) {\n            std::size_t pt = (1 << i);\n          \
    \  for (std::size_t j = 0 ; j + pt - 1 < table[i].size() ; j++) {\n          \
    \      table[i][j] = op(table[i - 1][j], table[i - 1][j + (pt >> 1)]);\n     \
    \       }\n        }\n    }\n\n    T query(int l, int r) {\n        int lg = std::__lg(r\
    \ - l);\n        return op(table[lg][l], table[lg][r - (1 << lg)]);\n    }\n\n\
    \    std::vector<std::vector<T>> hoge() {\n        return table;\n    }\n\n};\n\
    \n} // namespace zawa\n"
  code: "#pragma once\n#include <vector>\n\nnamespace zawa {\n\ntemplate <class T,\
    \ T (*op)(T, T)>\nclass Sparse_Table {\nprivate:\n    std::vector<std::vector<T>>\
    \ table;\n\npublic:\n    Sparse_Table(std::vector<T> as) \n        : table(std::__lg(as.size())\
    \ + 1, std::vector(as.size(), 0)) {\n            \n        for (std::size_t i\
    \ = 0 ; i < as.size() ; i++) {\n            table[0][i] = as[i];\n        }\n\n\
    \        for (std::size_t i = 1 ; i < table.size() ; i++) {\n            std::size_t\
    \ pt = (1 << i);\n            for (std::size_t j = 0 ; j + pt - 1 < table[i].size()\
    \ ; j++) {\n                table[i][j] = op(table[i - 1][j], table[i - 1][j +\
    \ (pt >> 1)]);\n            }\n        }\n    }\n\n    T query(int l, int r) {\n\
    \        int lg = std::__lg(r - l);\n        return op(table[lg][l], table[lg][r\
    \ - (1 << lg)]);\n    }\n\n    std::vector<std::vector<T>> hoge() {\n        return\
    \ table;\n    }\n\n};\n\n} // namespace zawa\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dataStructure/Sparse-Table.cpp
  requiredBy: []
  timestamp: '2022-10-20 00:33:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Sparse-Table.test.cpp
documentation_of: src/dataStructure/Sparse-Table.cpp
layout: document
redirect_from:
- /library/src/dataStructure/Sparse-Table.cpp
- /library/src/dataStructure/Sparse-Table.cpp.html
title: src/dataStructure/Sparse-Table.cpp
---
