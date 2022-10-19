---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../src/dataStructure/Sparse-Table.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/dataStructure/Sparse-Table.cpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n\n// namespace sp {\n//     int op(int a, int b) {\n// \
    \        return std::max(a, b);\n//     }\n// }\n\n// using SpT = zawa::Sparse_Table<int,\
    \ sp::op>;\n\nint main() {\n    std::cout << \"Hello World\" << std::endl;\n \
    \   // int n; std::cin >> n;\n    // std::vector as(n, 0);\n    // for (auto&\
    \ a : as) {\n    //     std::cin >> a;\n    // }\n    // SpT spt(as);\n    //\
    \ int d; std::cin >> d;\n    // for (int _ = 0 ; _ < d ; _++) {\n    //     int\
    \ l, r; std::cin >> l >> r;\n    //     std::cout << std::max(spt.query(0, l -\
    \ 1), spt.query(r, n)) << std::endl;\n    // }\n}\n\n/*\n *\n * \n * https://atcoder.jp/contests/tessoku-book/submissions/35794247\n\
    \ *\n */\n"
  dependsOn: []
  isVerificationFile: true
  path: test/Sparse-Table.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/Sparse-Table.test.cpp
layout: document
redirect_from:
- /verify/test/Sparse-Table.test.cpp
- /verify/test/Sparse-Table.test.cpp.html
title: test/Sparse-Table.test.cpp
---
