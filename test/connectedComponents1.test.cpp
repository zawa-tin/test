#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D"

#include "../src/graph/simple/connectedComponents.hpp"

#include <cassert>
#include <vector>
#include <iostream>

int main() {
    int n, m; std::cin >> n >> m;
    std::vector G1(n, std::vector(0, 0));
    std::vector G2(n, std::vector(0, std::pair(0, 0)));
    for (int _ = 0 ; _ < m ; _++) {
        int s, t; std::cin >> s >> t;
        G1[s].push_back(t);
        G1[t].push_back(s);
        G2[s].emplace_back(t, 0);
        G2[t].emplace_back(s, 0);
    }
    zawa::connectedComponents cc1(G1);
	zawa::connectedComponents cc2(G2);
    int q; std::cin >> q;
    for (int _ = 0 ; _ < q ; _++) {
        int s, t; std::cin >> s >> t;
        assert(cc1.same(s, t) == cc2.same(s, t));
        assert(cc1.same(s, t) == (cc1[s] == cc1[t]));
        assert(cc2.same(s, t) == (cc2[s] == cc2[t]));
        std::cout << (cc1.same(s, t) ? "yes" : "no") << std::endl;
    }
}
