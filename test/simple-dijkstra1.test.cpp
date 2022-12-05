#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../src/graph/simple/dijkstra.hpp"
#include "../src/graph/Read-Weighted-Graph.hpp"

int main() {
    int v, e, r; std::cin >> v >> e >> r;
    const long long inf = 1e15;
    auto G = zawa::read_weighted_graph<long long>(v, e, false, false);
    auto table = zawa::dijkstra<long long>(G, r, inf);
    for (auto ans : table) {
        if (ans == inf) {
            std::cout << "INF" << std::endl;
        }
        else {
            std::cout << ans << std::endl;
        }
    }
}
