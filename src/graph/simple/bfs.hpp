#pragma once

#include <vector>
#include <queue>

namespace zawa {

std::vector<int> bfs(const std::vector<std::vector<int>>& G, int s, int inf = 2e9) {
    std::vector<int> res(G.size(), inf);
    res[s] = 0;
    std::queue<int> que({ s });
    while (que.size()) {
        int v = que.front();
        que.pop();
        for (auto x : G[v]) {
            if (res[x] > res[v] + 1) {
                res[x] = res[v] + 1;
                que.push(x);
            }
        }
    }
    return res;
}

} // namespace zawa
