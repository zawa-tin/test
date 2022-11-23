#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../src/dataStructure/DSU.hpp"

#include <iostream>

int main() {
    int N, Q; std::cin >> N >> Q;
    zawa::DSU uf(N);
    for (int _ = 0 ; _ < Q ; _++) {
        int t, u, v; std::cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        }
        if (t == 1) {
            std::cout << uf.same(u, v) << std::endl;
        }
    }
}
