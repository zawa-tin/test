#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../src/graph/Dijkstra.hpp"

#include <iostream>

int main() {
    int n, m; std::cin >> n >> m;
    int s, t; std::cin >> s >> t;
    zawa::Dijkstra<long long> da(n);
    for (int _ = 0 ; _ < m ; _++) {
        int a, b; std::cin >> a >> b;
        long long c; std::cin >> c;
        da.add_edge(a, b, c);
    }
    da.build(s);
    if (da.get_dist(t) == da.inf()) {
        std::cout << -1 << std::endl;
        return 0;
    }
    int now = t;
    std::vector ps(0, 0);
    while (now != s) {
        ps.emplace_back(da.get_route(now));
        now = da.get_prev(now);
    }
    std::cout << da.get_dist(t) << ' ' << ps.size() << std::endl;
    for (int i = ps.size() - 1 ; i >= 0 ; i--) {
        auto e = da.get_edge(ps[i]);
        std::cout << e.from << ' ' << e.to << std::endl;
    }
}
