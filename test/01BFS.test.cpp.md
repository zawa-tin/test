---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/01BFS.hpp
    title: "01BFS (\u5E45\u512A\u5148\u63A2\u7D22)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    - https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3528/judge/7100637/C++17
  bundledCode: "#line 1 \"test/01BFS.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/01BFS.hpp\"\n\n#include <vector>\n#include <deque>\n#include\
    \ <limits>\n#include <utility>\n#include <algorithm>\n\nnamespace zawa {\n\nclass\
    \ Zero_One_BFS {\npublic:\n\n    struct edge {\n        int from, to;\n      \
    \  bool cost;\n    };\n\n    Zero_One_BFS(std::size_t n)\n        : G(n, std::vector(0,\
    \ 0))\n        , edges(0, edge())\n        , dist(n, _inf)\n        , prevs(n,\
    \ -1)\n        , route(n, -1) {}\n\n    int add_zero_edge(int from, int to) {\n\
    \        return add_edge(from, to, false);\n    }\n\n    int add_one_edge(int\
    \ from, int to) {\n        return add_edge(from, to, true);\n    }\n\n    inline\
    \ edge get_edge(int id) {\n        return edges[id];\n    }\n\n    void build(int\
    \ s) {\n        std::fill(dist.begin(), dist.end(), _inf);\n        std::fill(prevs.begin(),\
    \ prevs.end(), -1);\n        std::fill(route.begin(), route.end(), -1);\n    \
    \    dist[s] = 0;\n        std::deque<int> deq({ s });\n        while (deq.size())\
    \ {\n            int v = deq.front();\n            deq.pop_front();\n        \
    \    for (auto x : G[v]) {\n                auto [_, t, cost] = edges[x];\n  \
    \              if (dist[t] > dist[v] + (int)cost) {\n                    dist[t]\
    \ = dist[v] + (int)cost;\n                    prevs[t] = v;\n                \
    \    route[t] = x;\n                    if (cost) {\n                        deq.push_back(t);\n\
    \                    }\n                    else {\n                        deq.push_front(t);\n\
    \                    }\n                }\n            }\n        }\n    }\n\n\
    \    int inf() {\n        return _inf;\n    }\n\n    int get_dist(int v) {\n \
    \       return dist[v];\n    }\n\n    int get_prev(int v) {\n        return prevs[v];\n\
    \    }\n\n    int get_route(int v) {\n        return route[v];\n    }\n\nprivate:\n\
    \    static constexpr int _inf = std::numeric_limits<int>::max();\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<edge> edges;\n    std::vector<int> dist;\n    std::vector<int>\
    \ prevs;\n    std::vector<int> route;\n    \n    int add_edge(int from, int to,\
    \ bool cost) {\n        int res = (int)edges.size();\n        edges.push_back({\
    \ from, to, cost });\n        G[from].push_back(res);\n        return res;\n \
    \   }\n};\n\n}// namespace zawa\n#line 4 \"test/01BFS.test.cpp\"\n\n#include <iostream>\n\
    // #include <string>\n\nint main() {\n    /*\n    int h, w; std::cin >> h >> w;\n\
    \    std::vector grid(h, std::string());\n    for (auto& g : grid) {\n       \
    \ std::cin >> g;\n    }\n    std::vector<std::pair<int, int>> ds = { { 1, 0 },\
    \ { -1, 0 }, { 0, 1 }, { 0, -1 } };\n    zawa::Zero_One_BFS bfs(h * w);\n    int\
    \ dy[] = { 0, 1, 0, -1 };\n    int dx[] = { 1, 0, -1, 0 };\n    for (int i = 0\
    \ ; i < h ; i++) {\n        for (int j = 0 ; j < w ; j++) {\n            if (grid[i][j]\
    \ == '#') {\n                continue;\n            }\n            for (int d\
    \ = 0 ; d < 4 ; d++) {\n                if (grid[i][j] == 'R' and d != 0) {\n\
    \                    continue;\n                }\n                if (grid[i][j]\
    \ == 'D' and d != 1) {\n                    continue;\n                }\n   \
    \             if (grid[i][j] == 'L' and d != 2) {\n                    continue;\n\
    \                }\n                if (grid[i][j] == 'U' and d != 3) {\n    \
    \                continue;\n                }\n                int ny = i + dy[d],\
    \ nx = j + dx[d];\n                if (!(0 <= ny and ny < h and 0 <= nx and nx\
    \ < w)) {\n                    continue;\n                }\n                if\
    \ (grid[ny][nx] == '#') {\n                    continue;\n                }\n\
    \                if (grid[i][j] == 'S' or grid[i][j] == 'G' or grid[i][j] == '.')\
    \ {\n                    bfs.add_one_edge(i * w + j, ny * w + nx);\n         \
    \       }\n                else {\n                    bfs.add_zero_edge(i * w\
    \ + j, ny * w + nx);\n                }\n            }\n        }\n    }\n   \
    \ int s = -1, g = -1;\n    for (int i = 0 ; i < h ; i++) {\n        for (int j\
    \ = 0 ; j < w ; j++) {\n            if (grid[i][j] == 'S') {\n               \
    \ s = i * w + j;\n            }\n            if (grid[i][j] == 'G') {\n      \
    \          g = i * w + j;\n            }\n        }\n    }\n    bfs.build(s);\n\
    \    int ans = bfs.get_dist(g);\n    std::cout << (ans == bfs.inf() ? -1 : ans)\
    \ << std::endl;\n    */\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\
    \n/*\n * AOJ 3528 Belt Conveyor Maze\n * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3528/judge/7100637/C++17\n\
    \ */\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/01BFS.hpp\"\n\n#include <iostream>\n// #include <string>\n\
    \nint main() {\n    /*\n    int h, w; std::cin >> h >> w;\n    std::vector grid(h,\
    \ std::string());\n    for (auto& g : grid) {\n        std::cin >> g;\n    }\n\
    \    std::vector<std::pair<int, int>> ds = { { 1, 0 }, { -1, 0 }, { 0, 1 }, {\
    \ 0, -1 } };\n    zawa::Zero_One_BFS bfs(h * w);\n    int dy[] = { 0, 1, 0, -1\
    \ };\n    int dx[] = { 1, 0, -1, 0 };\n    for (int i = 0 ; i < h ; i++) {\n \
    \       for (int j = 0 ; j < w ; j++) {\n            if (grid[i][j] == '#') {\n\
    \                continue;\n            }\n            for (int d = 0 ; d < 4\
    \ ; d++) {\n                if (grid[i][j] == 'R' and d != 0) {\n            \
    \        continue;\n                }\n                if (grid[i][j] == 'D' and\
    \ d != 1) {\n                    continue;\n                }\n              \
    \  if (grid[i][j] == 'L' and d != 2) {\n                    continue;\n      \
    \          }\n                if (grid[i][j] == 'U' and d != 3) {\n          \
    \          continue;\n                }\n                int ny = i + dy[d], nx\
    \ = j + dx[d];\n                if (!(0 <= ny and ny < h and 0 <= nx and nx <\
    \ w)) {\n                    continue;\n                }\n                if\
    \ (grid[ny][nx] == '#') {\n                    continue;\n                }\n\
    \                if (grid[i][j] == 'S' or grid[i][j] == 'G' or grid[i][j] == '.')\
    \ {\n                    bfs.add_one_edge(i * w + j, ny * w + nx);\n         \
    \       }\n                else {\n                    bfs.add_zero_edge(i * w\
    \ + j, ny * w + nx);\n                }\n            }\n        }\n    }\n   \
    \ int s = -1, g = -1;\n    for (int i = 0 ; i < h ; i++) {\n        for (int j\
    \ = 0 ; j < w ; j++) {\n            if (grid[i][j] == 'S') {\n               \
    \ s = i * w + j;\n            }\n            if (grid[i][j] == 'G') {\n      \
    \          g = i * w + j;\n            }\n        }\n    }\n    bfs.build(s);\n\
    \    int ans = bfs.get_dist(g);\n    std::cout << (ans == bfs.inf() ? -1 : ans)\
    \ << std::endl;\n    */\n\n    std::cout << \"Hello World\" << std::endl;\n}\n\
    \n/*\n * AOJ 3528 Belt Conveyor Maze\n * https://onlinejudge.u-aizu.ac.jp/status/users/zawakasu/submissions/1/3528/judge/7100637/C++17\n\
    \ */\n"
  dependsOn:
  - src/graph/01BFS.hpp
  isVerificationFile: true
  path: test/01BFS.test.cpp
  requiredBy: []
  timestamp: '2022-11-14 21:43:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/01BFS.test.cpp
layout: document
redirect_from:
- /verify/test/01BFS.test.cpp
- /verify/test/01BFS.test.cpp.html
title: test/01BFS.test.cpp
---
