#pragma once

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
