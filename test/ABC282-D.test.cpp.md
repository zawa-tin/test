---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/Read-Graph.hpp
    title: "Read-Graph (\u30B0\u30E9\u30D5\u5165\u529B)"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/bipartiteJudge.hpp
    title: "bipartiteJudge (\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A)"
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/connectedComponents.hpp
    title: "connectedComponents (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
    links:
    - https://atcoder.jp/contests/abc282/submissions/39400340
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A
  bundledCode: "#line 1 \"test/ABC282-D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#line 2 \"src/graph/Read-Graph.hpp\"\n\n#include <vector>\n#include <iostream>\n\
    \nnamespace zawa {\n\nstd::vector<std::vector<int>> read_graph(int n, int m, bool\
    \ undirect = true, bool minus = true) {\n    std::vector<std::vector<int>> res(n,\
    \ std::vector(0, 0));\n    for (int _ = 0 ; _ < m ; _++) {\n        int u, v;\n\
    \        std::cin >> u >> v;\n        res[u - minus].emplace_back(v - minus);\n\
    \        if (undirect) {\n            res[v - minus].emplace_back(u - minus);\n\
    \        }\n    }\n    return res;\n}\n\nstd::vector<std::vector<int>> read_tree(int\
    \ n, bool undirect = true, bool minus = true) {\n    return read_graph(n, n -\
    \ 1, undirect, minus);\n}\n\n}\n#line 2 \"src/graph/simple/connectedComponents.hpp\"\
    \n\n#line 4 \"src/graph/simple/connectedComponents.hpp\"\n#include <stack>\n\n\
    namespace zawa {\n\nclass connectedComponents {\nprivate:\n\tstd::vector<int>\
    \ ids;\n\tstd::vector<std::vector<int>> groups;    \n\n\tvoid build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tint id = 0;\n\t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\
    \tif (ids[i] == -1) {\n\t\t\t\tids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\
    \t\n\t\t\t\twhile (stk.size()) {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\
    \t\t\t\t\tfor (auto x : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\
    \tids[x] = id;\n\t\t\t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\
    \t}\n\t\t\t\tid++;\n\t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0,\
    \ 0));\n\t\tfor (int i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\
    \t\t}\n\t}\n\npublic:\n\n\tconnectedComponents(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\
    \tconnectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\t}\n\n\t\
    inline int operator [](int i) const {\n\t\treturn ids[i];\n\t}\n\n\tinline std::size_t\
    \ size() const {\n\t\treturn groups.size();\n\t}\n\n\tinline std::size_t size(int\
    \ x) const {\n\t\treturn groups[ids[x]].size();\n\t}\n\n\tinline std::vector<std::vector<int>>\
    \ comps() const {\n\t\treturn groups;\n\t}\n\n\tinline std::vector<int> comp(int\
    \ id) const {\n\t\treturn groups[id];\n\t}\n\n\tbool same(int i, int j) const\
    \ {\n\t\treturn ids[i] == ids[j];\n\t}\n};\n\n} // namespace zawa\n#line 2 \"\
    src/graph/simple/bipartiteJudge.hpp\"\n\n#line 5 \"src/graph/simple/bipartiteJudge.hpp\"\
    \n#include <utility>\n\nnamespace zawa {\n\nclass bipartiteJudge {\nprivate:\n\
    \tstd::vector<bool> colors;\n\tbool isBipartiteGraph;\n\n\tvoid build(const std::vector<std::vector<int>>&\
    \ G) {\n\t\tif (G.empty()) {\n\t\t\treturn;\n\t\t}\n\t\tstd::stack<std::pair<int,\
    \ bool>> S;\n\t\tstd::vector<bool> used(G.size(), false);\n\t\tfor (int i = 0\
    \ ; i < (int)G.size() ; i++) {\n\t\t\tif (!used[i]) {\n\t\t\t\tS.emplace(i, true);\n\
    \t\t\t\tused[i] = true;\n\t\t\t\tcolors[i] = true;\n\t\t\t\twhile (S.size()) {\n\
    \t\t\t\t\tauto [v, col] = S.top();\n\t\t\t\t\tS.pop();\n\t\t\t\t\tfor (const auto&\
    \ x : G[v]) {\n\t\t\t\t\t\tif (used[x]) {\n\t\t\t\t\t\t\tisBipartiteGraph &= colors[x]\
    \ != col;\n\t\t\t\t\t\t}\n\t\t\t\t\t\telse {\n\t\t\t\t\t\t\tused[x] = true;\n\t\
    \t\t\t\t\t\tcolors[x] = !col;\n\t\t\t\t\t\t\tS.emplace(x, !col);\n\t\t\t\t\t\t\
    }\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\npublic:\n\t\n\tbipartiteJudge(const\
    \ std::vector<std::vector<int>>& G) : colors(G.size()), isBipartiteGraph(true)\
    \ {\n\t\tbuild(G);\n\t}\n\n\ttemplate <class cost_type>\n\tbipartiteJudge(const\
    \ std::vector<std::vector<std::pair<int, cost_type>>>& G) : colors(G.size()),\
    \ isBipartiteGraph(true) {\n\t\tstd::vector tmpG(G.size(), std::vector(0, 0));\n\
    \t\tfor (std::size_t i = 0 ; i < G.size() ; i++) {\n\t\t\tfor (const auto& [x,\
    \ _] : G[i]) {\n\t\t\t\ttmpG[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmpG);\n\
    \t}\n\n\tinline const bool ok() const {\n\t\treturn isBipartiteGraph;\n\t}\n\n\
    \tinline bool operator[](int i) const {\n\t\treturn colors[i];\n\t}\n};\n\n} //\
    \ namespace zawa\n#line 6 \"test/ABC282-D.test.cpp\"\n\n#line 9 \"test/ABC282-D.test.cpp\"\
    \n\ninline long long nC2(int value) {\n\treturn (long long)value * (value - 1)\
    \ / 2;\n}\n\nint main() {\n\t// int N, M; std::cin >> N >> M;\n //   \tauto G\
    \ = zawa::read_graph(N, M); \n\t// auto colors = zawa::bipartiteJudge(G);\n\t\
    // if (colors.ok()) {\n\t// \tauto groups = zawa::connectedComponents(G).comps();\n\
    \t// \tlong long ans = nC2(N) - M;\n\t// \tfor (auto group : groups) {\n\t// \t\
    \tint c1 = 0;\n\t// \t\tfor (auto x : group) {\n\t// \t\t\tc1 += colors[x];\n\t\
    // \t\t}\n\t// \t\tans -= nC2(c1) + nC2(group.size() - c1);\n\t// \t}\n\t// \t\
    std::cout << ans << std::endl;\n\t// }\n\t// else {\n\t// \tstd::cout << 0 <<\
    \ std::endl;\n\t// }\n\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 282 D- Make Bipartite 2\n * https://atcoder.jp/contests/abc282/submissions/39400340\n\
    \ */\n\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A\"\
    \n\n#include \"../src/graph/Read-Graph.hpp\"\n#include \"../src/graph/simple/connectedComponents.hpp\"\
    \n#include \"../src/graph/simple/bipartiteJudge.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\ninline long long nC2(int value) {\n\treturn (long long)value\
    \ * (value - 1) / 2;\n}\n\nint main() {\n\t// int N, M; std::cin >> N >> M;\n\
    \ //   \tauto G = zawa::read_graph(N, M); \n\t// auto colors = zawa::bipartiteJudge(G);\n\
    \t// if (colors.ok()) {\n\t// \tauto groups = zawa::connectedComponents(G).comps();\n\
    \t// \tlong long ans = nC2(N) - M;\n\t// \tfor (auto group : groups) {\n\t// \t\
    \tint c1 = 0;\n\t// \t\tfor (auto x : group) {\n\t// \t\t\tc1 += colors[x];\n\t\
    // \t\t}\n\t// \t\tans -= nC2(c1) + nC2(group.size() - c1);\n\t// \t}\n\t// \t\
    std::cout << ans << std::endl;\n\t// }\n\t// else {\n\t// \tstd::cout << 0 <<\
    \ std::endl;\n\t// }\n\n\tstd::cout << \"Hello World\" << std::endl;\n}\n\n/*\n\
    \ * AtCoder Beginner Contest 282 D- Make Bipartite 2\n * https://atcoder.jp/contests/abc282/submissions/39400340\n\
    \ */\n\n\n"
  dependsOn:
  - src/graph/Read-Graph.hpp
  - src/graph/simple/connectedComponents.hpp
  - src/graph/simple/bipartiteJudge.hpp
  isVerificationFile: true
  path: test/ABC282-D.test.cpp
  requiredBy: []
  timestamp: '2023-03-04 20:28:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/ABC282-D.test.cpp
layout: document
redirect_from:
- /verify/test/ABC282-D.test.cpp
- /verify/test/ABC282-D.test.cpp.html
title: test/ABC282-D.test.cpp
---
