#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C"

#include "../src/graph/BFS.hpp"

#include <iostream>

int main() {
    int n; std::cin >> n;
    zawa::BFS bfs(n);
    for (int _ = 0 ; _ < n ; _++) {
        int u; std::cin >> u;
        int k; std::cin >> k;
        for (int __ = 0 ; __ < k ; __++) {
            int v; std::cin >> v;
            bfs.add_edge(u - 1, v - 1);
        }
    }
    bfs.build(0);
    for (int i = 0 ; i < n ; i++) {
        int ans = bfs.get_dist(i);
        std::cout << i + 1 << ' ' << (ans == bfs.inf() ? -1 : ans) << std::endl;
    }
}
