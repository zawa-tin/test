#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_C"

#include "../src/graph/simple/bfs.hpp"

#include <iostream>

int main() {
    int n; std::cin >> n;
    std::vector G(n, std::vector(0, 0));
    for (int _ = 0 ; _ < n ; _++) {
        int id; std::cin >> id;
        int k; std::cin >> k;
        for (int __ = 0 ; __ < k ; __++) {
            int v; std::cin >> v;
            G[id - 1].push_back(v - 1);
        }
    }
    const int inf = 1e9;
    auto table = zawa::bfs(G, 0, inf);
    for (int i = 0 ; i < n ; i++) {
        std::cout << i + 1 << ' ';
        std::cout << (table[i] == inf ? -1 : table[i]) << std::endl;
    }
}
