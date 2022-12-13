---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/range-edge-graph.hpp
    title: "range edge graph (\u533A\u9593\u306B\u8FBA\u3092\u8CBC\u308B\u30C6\u30AF\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://codeforces.com/contest/786/submission/185125317
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/range-edge-graph2.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/range-edge-graph.hpp\"\n\n#include <vector>\n#include\
    \ <queue>\n#include <utility>\n#include <limits>\n\nnamespace zawa {\n\ntemplate\
    \ <class cost_type>\nclass range_edge_graph {\nprivate:\n    int n;\n    std::vector<std::vector<std::pair<int,\
    \ cost_type>>> G;\n\n    void add_edge(int u, int v, cost_type cost) {\n     \
    \   if (u >= 3 * n) {\n            u -= 2 * n;\n        }\n        G[u].emplace_back(v,\
    \ cost);\n    }\n\npublic:\n    range_edge_graph(int n) : n(n), G(3 * n) {\n \
    \       for (int i = 1 ; i < n ; i++) {\n            int child_l = ((i << 1) |\
    \ 0), child_r = ((i << 1 | 1));\n            add_edge(i, child_l, 0);\n      \
    \      add_edge(i, child_r, 0);\n            add_edge(child_l + 2 * n, i + 2 *\
    \ n, 0);\n            add_edge(child_r + 2 * n, i + 2 * n, 0);\n        }\n  \
    \  }\n\n    void add_edge(int ul, int ur, int vl, int vr, cost_type cost) {\n\
    \        int id = G.size();\n        for (int l = ul + n, r = ur + n ; l < r ;\
    \ l >>= 1, r >>= 1) {\n            if (l & 1) {\n                add_edge(l +\
    \ 2 * n, id, 0);\n                l++;\n            }\n            if (r & 1)\
    \ {\n                r--;\n                add_edge(r + 2 * n, id, 0);\n     \
    \       }\n        }\n        std::vector<std::pair<int, cost_type>> node;\n \
    \       for (int l = vl + n, r = vr + n ; l < r ; l >>= 1, r >>= 1) {\n      \
    \      if (l & 1) {\n                node.emplace_back(l, cost);\n           \
    \     l++;\n            }\n            if (r & 1) {\n                r--;\n  \
    \              node.emplace_back(r, cost);\n            }\n        }\n       \
    \ G.push_back(node);\n    }\n\n    std::vector<cost_type> dijkstra(int s, cost_type\
    \ sup = std::numeric_limits<cost_type>::max()) {\n        std::priority_queue<\n\
    \            std::pair<cost_type, int>, \n            std::vector<std::pair<cost_type,\
    \ int>>, \n            std::greater<std::pair<cost_type, int>>\n             \
    \   > que;\n        que.emplace((cost_type)0, s + n);\n        std::vector<cost_type>\
    \ dist(G.size(), sup);\n        dist[s + n] = (cost_type)0;\n        while (que.size())\
    \ {\n            auto [d, v] = que.top();\n            que.pop();\n          \
    \  if (d > dist[v]) {\n                continue;\n            }\n            for\
    \ (auto [x, cost] : G[v]) {\n                if (dist[x] > d + cost) {\n     \
    \               dist[x] = d + cost;\n                    que.emplace(d + cost,\
    \ x);\n                }\n            }\n        }\n        return std::vector<cost_type>(dist.begin()\
    \ + n, dist.begin() + 2 * n);\n    }\n\n};\n\n} // namespace zawa\n#line 4 \"\
    test/range-edge-graph2.test.cpp\"\n\n#include <iostream>\n#include <ios>\n\nint\
    \ main() {\n    // std::ios::sync_with_stdio(false);\n    // std::cin.tie(nullptr);\n\
    \    // \n    // int n, q, s; std::cin >> n >> q >> s;\n    // zawa::range_edge_graph<long\
    \ long> reg(n);\n    // for (int _ = 0 ; _ < q ; _++) {\n    //     int t; std::cin\
    \ >> t;\n    //     if (t == 1) {\n    //         int v, u, w; std::cin >> v >>\
    \ u >> w;\n    //         reg.add_edge(v - 1, v, u - 1, u, w);\n    //     }\n\
    \    //     if (t == 2) {\n    //         int v, l, r, w; std::cin >> v >> l >>\
    \ r >> w;\n    //         reg.add_edge(v - 1, v, l - 1, r, w);\n    //     }\n\
    \    //     if (t == 3) {\n    //         int v, l, r, w; std::cin >> v >> l >>\
    \ r >> w;\n    //         reg.add_edge(l - 1, r, v - 1, v, w);\n    //     }\n\
    \    // }\n    // \n    // const long long sup = (1LL << 60);\n    // auto ds\
    \ = reg.dijkstra(s - 1, sup);\n    // for (int i = 0 ; i < n ; i++) {\n    //\
    \     std::cout << (ds[i] == sup ? -1LL : ds[i]) << (i + 1 == n ? '\\n' : ' ');\n\
    \    // }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * Codeforces\
    \ Round #406 B. Legacy\n * https://codeforces.com/contest/786/submission/185125317\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/range-edge-graph.hpp\"\n\n#include <iostream>\n#include\
    \ <ios>\n\nint main() {\n    // std::ios::sync_with_stdio(false);\n    // std::cin.tie(nullptr);\n\
    \    // \n    // int n, q, s; std::cin >> n >> q >> s;\n    // zawa::range_edge_graph<long\
    \ long> reg(n);\n    // for (int _ = 0 ; _ < q ; _++) {\n    //     int t; std::cin\
    \ >> t;\n    //     if (t == 1) {\n    //         int v, u, w; std::cin >> v >>\
    \ u >> w;\n    //         reg.add_edge(v - 1, v, u - 1, u, w);\n    //     }\n\
    \    //     if (t == 2) {\n    //         int v, l, r, w; std::cin >> v >> l >>\
    \ r >> w;\n    //         reg.add_edge(v - 1, v, l - 1, r, w);\n    //     }\n\
    \    //     if (t == 3) {\n    //         int v, l, r, w; std::cin >> v >> l >>\
    \ r >> w;\n    //         reg.add_edge(l - 1, r, v - 1, v, w);\n    //     }\n\
    \    // }\n    // \n    // const long long sup = (1LL << 60);\n    // auto ds\
    \ = reg.dijkstra(s - 1, sup);\n    // for (int i = 0 ; i < n ; i++) {\n    //\
    \     std::cout << (ds[i] == sup ? -1LL : ds[i]) << (i + 1 == n ? '\\n' : ' ');\n\
    \    // }\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\n/*\n * Codeforces\
    \ Round #406 B. Legacy\n * https://codeforces.com/contest/786/submission/185125317\n\
    \ */\n"
  dependsOn:
  - src/graph/range-edge-graph.hpp
  isVerificationFile: true
  path: test/range-edge-graph2.test.cpp
  requiredBy: []
  timestamp: '2022-12-14 06:58:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/range-edge-graph2.test.cpp
layout: document
redirect_from:
- /verify/test/range-edge-graph2.test.cpp
- /verify/test/range-edge-graph2.test.cpp.html
title: test/range-edge-graph2.test.cpp
---
