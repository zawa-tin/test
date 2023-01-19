---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/persistent-array.hpp
    title: "persistent array (\u5168\u6C38\u7D9A\u914D\u5217)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A
  bundledCode: "#line 1 \"test/persistent-array.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A\"\
    \n\n#line 2 \"src/dataStructure/persistent-array.hpp\"\n\n#include <vector>\n\
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
    \t}\n};\n\n} // namespace zawa\n#line 4 \"test/persistent-array.test.cpp\"\n\n\
    #include <iostream>\n\nint main() {\n\tint n; std::cin >> n;\n\tzawa::persistent_array<int>\
    \ pa(n);\n\tfor (int i = 0 ; i < n ; i++) {\n\t\tint a; std::cin >> a;\n\t\tpa.set(pa.size()\
    \ - 1, i, a);\n\t}\n\tfor (int i = 0 ; i < (n + 1) / 2 ; i++) {\n\t\tint f = pa.get(pa.size()\
    \ - 1, i);\n\t\tint b = pa.get(pa.size() - 1, n - i - 1);\n\t\tpa.set(pa.size()\
    \ - 1, i, b);\n\t\tpa.set(pa.size() - 1, n - i - 1, f);\n\t}\n\tfor (int i = 0\
    \ ; i < n ; i++) {\n\t\tstd::cout << pa.get(pa.size() - 1, i) << (i + 1 == n ?\
    \ '\\n' : ' ');\n\t}\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/6/ITP1_6_A\"\
    \n\n#include \"../src/dataStructure/persistent-array.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n\tint n; std::cin >> n;\n\tzawa::persistent_array<int> pa(n);\n\
    \tfor (int i = 0 ; i < n ; i++) {\n\t\tint a; std::cin >> a;\n\t\tpa.set(pa.size()\
    \ - 1, i, a);\n\t}\n\tfor (int i = 0 ; i < (n + 1) / 2 ; i++) {\n\t\tint f = pa.get(pa.size()\
    \ - 1, i);\n\t\tint b = pa.get(pa.size() - 1, n - i - 1);\n\t\tpa.set(pa.size()\
    \ - 1, i, b);\n\t\tpa.set(pa.size() - 1, n - i - 1, f);\n\t}\n\tfor (int i = 0\
    \ ; i < n ; i++) {\n\t\tstd::cout << pa.get(pa.size() - 1, i) << (i + 1 == n ?\
    \ '\\n' : ' ');\n\t}\n}\n"
  dependsOn:
  - src/dataStructure/persistent-array.hpp
  isVerificationFile: true
  path: test/persistent-array.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 08:52:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/persistent-array.test.cpp
layout: document
redirect_from:
- /verify/test/persistent-array.test.cpp
- /verify/test/persistent-array.test.cpp.html
title: test/persistent-array.test.cpp
---
