#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../src/graph/simple/wf.hpp"
#include "../src/graph/Read-Weighted-Graph.hpp"

#include <iostream>

int main() {
    int n, m; std::cin >> n >> m;
    const long long inf = 1e15;
    auto G = zawa::wf<long long>(zawa::read_weighted_graph<long long>(n, m, false, false), inf);
    bool neg = false;
    for (int i = 0 ; i < n ; i++) {
        neg |= G[i][i] < 0;
    }
    if (neg) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
    }
    else {
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (G[i][j] > 1e12) {
                    std::cout << "INF";
                }
                else {
                    std::cout << G[i][j];
                }
                std::cout << (j == n - 1 ? '\n' : ' ');
            }
        }
    }
}
