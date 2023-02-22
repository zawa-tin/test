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
redirect_from:
- /library/src/dataStructure/monotone_CHT.hpp
- /library/src/dataStructure/monotone_CHT.hpp.html
title: src/dataStructure/monotone_CHT.hpp
---
