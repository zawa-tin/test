#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../src/graph/Read-Weighted-Graph.hpp"

#include <queue>

int main() {
    int n, m, r; std::cin >> n >> m >> r;
    auto G = zawa::read_weighted_graph<int>(n, m, false, false); 
    std::vector dists(n, (1LL << 60));
    dists[r] = 0;
    std::priority_queue<std::pair<long long, int>> que;
    que.emplace(0LL, r);
    while (que.size()) {
        auto [d, v] = que.top();
        d *= -1;
        que.pop();
        if (d > dists[v]) {
            continue;
        }
        for (auto [x, w] : G[v]) {
            if (d + w < dists[x]) {
                dists[x] = d + w;
                que.emplace(-dists[x], x);
            }
        }
    }
    for (auto d : dists) {
        if (d == (1LL << 60)) {
            std::cout << "INF" << std::endl;
        }
        else {
            std::cout << d << std::endl;
        }
    }
}
