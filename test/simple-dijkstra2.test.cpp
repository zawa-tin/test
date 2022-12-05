#include <vector>
#include <queue>
#include <utility>
#include <limits>

namespace zawa {

template <class cost_type>
std::vector<cost_type> dijkstra(const std::vector<std::vector<std::pair<int, cost_type>>>& G, 
        int s, cost_type inf = std::numeric_limits<cost_type>::max()) {
    std::vector<cost_type> res(G.size(), inf);
    res[s] = 0;
    std::priority_queue<
        std::pair<cost_type, int>, 
        std::vector<std::pair<cost_type, int>>, 
        std::greater<std::pair<cost_type, int>>
            > que;
    que.push({ 0, s }); 
    while (que.size()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > res[v]) {
            continue;
        }
        for (auto [x, w] : G[v]) {
            if (res[x] > d + w) {
                res[x] = d + w;
                que.push({ d + w, x });
            }
        }
    }
    return res;
}

} // namespace zawa

#include <iostream>

namespace zawa {

template <typename T>
std::vector<std::vector<std::pair<int, T>>> read_weighted_graph(int n, int m, bool undirect = true, bool minus = true) {
    std::vector<std::vector<std::pair<int, T>>> res(n, std::vector(0, std::pair<int, T>()));
    for (int _ = 0 ; _ < m ; _++) {
        int u, v; std::cin >> u >> v;
        T c; std::cin >> c;
        res[u - minus].emplace_back(v - minus, c);
        if (undirect) {
            res[v - minus].emplace_back(u - minus, c);
        }
    }
    return res;
}

template <typename T>
std::vector<std::vector<std::pair<int, T>>> read_weighted_tree(int n, bool undirect = true) {
    return read_weighted_graph<T>(n, n - 1, undirect);
}

} // namespace zawa

int main() {
    int n, m; std::cin >> n >> m;
    auto G = zawa::read_weighted_graph<int>(n, m);
    const int inf = 2e9;
    auto fs = zawa::dijkstra<int>(G, 0, inf);
    auto bs = zawa::dijkstra<int>(G, n - 1, inf);
    for (int i = 0 ; i < n ; i++) {
        std::cout << fs[i] + bs[i] << std::endl;
    }
}
