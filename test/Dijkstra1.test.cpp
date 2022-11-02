#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../src/graph/Dijkstra.hpp"

#include <iostream>

int main() {
    int v, e, r;
    std::cin >> v >> e >> r;
    zawa::Dijkstra<long long> da(v);
    for (int _ = 0 ; _ < e ; _++) {
        int s, t; std::cin >> s >> t;
        long long d; std::cin >> d;
        da.add_edge(s, t, d);
    }
    da.build(r);
    for (int i = 0 ; i < v ; i++) {
        auto ans = da.get_dist(i);
        if (ans == da.inf()) {
            std::cout << "INF" << std::endl;
        }
        else {
            std::cout << ans << std::endl;
        }
    }
}
