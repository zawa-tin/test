---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/rerooting.hpp
    title: "rerooting (\u5168\u65B9\u4F4D\u6728DP)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
  bundledCode: "#line 1 \"test/rerooting.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#line 2 \"src/graph/rerooting.hpp\"\n\n#include <vector>\n#include <utility>\n\
    #include <cassert>\n\nnamespace zawa {\n\ntemplate <class vertex, class edge>\n\
    class rerooting {\nprivate:\n\tvertex identity;\n\tstd::vector<edge> edges;\n\t\
    std::vector<std::pair<int, int>> pos;\n\tstd::vector<vertex> vertices;\n\tint\
    \ edgeNum = 0;\n\tint N;\n\npublic:\n\tstruct edgeInfo {\n\t\tint u, v;\n\t\t\
    edge dat;\n\t\tedgeInfo(int _u, int _v, const edge& _dat) : u(_u), v(_v), dat(_dat)\
    \ {}\n\t};\n\n\trerooting(const vertex& _identity, std::size_t _N) \n\t\t: identity(_identity),\
    \ edges(_N - 1), pos(_N - 1), vertices(_N), N(_N) {\n\t\t\tassert(0 < _N);\n\t\
    }\t\n\n\tvoid addEdge(int u, int v, const edge& e) {\n\t\tassert(edgeNum < N -\
    \ 1);\n\t\tassert(0 <= u and u < N);\n\t\tassert(0 <= v and v < N);\n\t\tpos[edgeNum]\
    \ = { u, v };\n\t\tedges[edgeNum] = e;\n\t\tedgeNum++;\n\t}\n\n\tinline edgeInfo\
    \ getEdge(int i) const {\n\t\tassert(i < edgeNum);\n\t\treturn edgeInfo{ pos[i].first,\
    \ pos[i].second, edges[i] };\n\t}\n\n\tinline vertex get(int i) const {\n\t\t\
    assert(0 <= i and i < N);\n\t\treturn vertices[i];\n\t}\n\n\tvoid changeEdge(int\
    \ i, const edge& e) {\n\t\tassert(i < edgeNum);\n\t\tedges[i] = e;\n\t}\n\n\t\
    void assign(int i, const vertex& v) {\n\t\tassert(0 <= i and i < N);\n\t\tvertices[i]\
    \ = v;\n\t}\n\n\ttemplate <class F1, class F2>\n\tstd::vector<vertex> run(const\
    \ F1& merge, const F2& walk) {\n\t\tassert(edgeNum == N - 1);\n\t\tstd::vector<std::vector<std::pair<int,\
    \ int>>> G(N);\n\t\tfor (int i = 0 ; i < N - 1 ; i++) {\n\t\t\tconst auto& [u,\
    \ v] = pos[i];\n\t\t\tG[u].emplace_back(v, i);\n\t\t\tG[v].emplace_back(u, i);\n\
    \t\t}\n\t\tauto dfs = [&](auto dfs, int v, int p) -> vertex {\n\t\t\tfor (const\
    \ auto& [x, i] : G[v]) if (x != p)\n\t\t\t\tvertices[v] = merge(vertices[v], walk(dfs(dfs,\
    \ x, v), edges[i], x, v), x, v);\n\t\t\treturn vertices[v];\n\t\t};\n\t\tdfs(dfs,\
    \ 0, -1);\n\t\tstd::vector<vertex> res(N, identity);\n\t\tauto reroot = [&](auto\
    \ reroot, int v, int p, const vertex& propagating) -> void {\n\t\t\tstd::vector<vertex>\
    \ prefix(G[v].size() + 1, identity), suffix = prefix;\n\t\t\tfor (int i = 0 ;\
    \ i < (int)G[v].size() ; i++) {\n\t\t\t\tconst auto& [x, j] = G[v][i];\n\t\t\t\
    \tprefix[i + 1] = merge(prefix[i], walk((x == p ? propagating : vertices[x]),\
    \ edges[j], x, v), x, v);\n\t\t\t}\n\t\t\tfor (int i = (int)G[v].size() ; i >\
    \ 0 ; i--) {\n\t\t\t\tconst auto& [x, j] = G[v][i - 1];\n\t\t\t\tsuffix[i - 1]\
    \ = merge(suffix[i], walk((x == p ? propagating : vertices[x]), edges[j], x, v),\
    \ x, v);\n\t\t\t}\n\t\t\tres[v] = prefix.back();\n\t\t\tfor (int i = 0 ; i < (int)G[v].size()\
    \ ; i++) {\n\t\t\t\tauto [x, _] = G[v][i];\n\t\t\t\tif (x != p) reroot(reroot,\
    \ x, v, merge(prefix[i], suffix[i + 1], x, v));\n\t\t\t}\n\t\t};\n\t\treroot(reroot,\
    \ 0, -1, identity);\n\t\treturn res;\n\t}\n};\n\n} // namespace zawa\n#line 4\
    \ \"test/rerooting.test.cpp\"\n\n#include <cstdio>\n#line 7 \"test/rerooting.test.cpp\"\
    \n#include <algorithm>\n#include <functional>\n\nint main() {\n\tint n; std::scanf(\"\
    %d\", &n);\n\tstruct V {\n\t\tint fir, sec;\n\t\tV(int _fir = 0, int _sec = 0)\
    \ : fir(_fir), sec(_sec) {}\n\t};\t\n\tstruct E {\n\t\tint w;\n\t\tE(int _w =\
    \ 0) : w(_w) {}\n\t};\n\tzawa::rerooting<V, E> dp(V(), n);\n\tfor (int i = 0 ;\
    \ i < n - 1 ; i++) {\n\t\tint u, v, w; std::scanf(\"%d%d%d\", &u, &v, &w);\n\t\
    \tdp.addEdge(u, v, E(w));\n\t}\n\tauto merge = [&](V a, V b, int, int) -> V {\n\
    \t\tstd::vector<int> tmp{ a.fir, a.sec, b.fir, b.sec };\n\t\tstd::sort(tmp.begin(),\
    \ tmp.end(), std::greater<int>());\t\n\t\treturn V{ tmp[0], tmp[1] };\n\t};\n\t\
    auto walk = [&](V v, E e, int, int) -> V {\n\t\treturn V{ v.fir + e.w, 0 };\n\t\
    };\n\tint ans = 0;\n\tfor (auto v : dp.run(merge, walk)) {\n\t\tans = std::max(ans,\
    \ v.fir + v.sec);\n\t}\n\tstd::printf(\"%d\\n\", ans);\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include \"../src/graph/rerooting.hpp\"\n\n#include <cstdio>\n#include <vector>\n\
    #include <algorithm>\n#include <functional>\n\nint main() {\n\tint n; std::scanf(\"\
    %d\", &n);\n\tstruct V {\n\t\tint fir, sec;\n\t\tV(int _fir = 0, int _sec = 0)\
    \ : fir(_fir), sec(_sec) {}\n\t};\t\n\tstruct E {\n\t\tint w;\n\t\tE(int _w =\
    \ 0) : w(_w) {}\n\t};\n\tzawa::rerooting<V, E> dp(V(), n);\n\tfor (int i = 0 ;\
    \ i < n - 1 ; i++) {\n\t\tint u, v, w; std::scanf(\"%d%d%d\", &u, &v, &w);\n\t\
    \tdp.addEdge(u, v, E(w));\n\t}\n\tauto merge = [&](V a, V b, int, int) -> V {\n\
    \t\tstd::vector<int> tmp{ a.fir, a.sec, b.fir, b.sec };\n\t\tstd::sort(tmp.begin(),\
    \ tmp.end(), std::greater<int>());\t\n\t\treturn V{ tmp[0], tmp[1] };\n\t};\n\t\
    auto walk = [&](V v, E e, int, int) -> V {\n\t\treturn V{ v.fir + e.w, 0 };\n\t\
    };\n\tint ans = 0;\n\tfor (auto v : dp.run(merge, walk)) {\n\t\tans = std::max(ans,\
    \ v.fir + v.sec);\n\t}\n\tstd::printf(\"%d\\n\", ans);\n}\n"
  dependsOn:
  - src/graph/rerooting.hpp
  isVerificationFile: true
  path: test/rerooting.test.cpp
  requiredBy: []
  timestamp: '2023-04-04 17:31:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/rerooting.test.cpp
layout: document
redirect_from:
- /verify/test/rerooting.test.cpp
- /verify/test/rerooting.test.cpp.html
title: test/rerooting.test.cpp
---
