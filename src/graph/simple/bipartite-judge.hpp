#pragma once

#include <vector>

namespace zawa::impl {
    
bool dfs(const std::vector<std::vector<int>>& G, int v,
        int color, std::vector<int>& colors, std::vector<bool>& used) {
    used[v] = true;
    colors[v] = color;
    for (auto x : G[v]) {
        if (used[x]) {
            if (colors[x] == colors[v]) {
                return false;
            }
        }
        else {
            if (!dfs(G, x, 1 - color, colors, used)) {
                return false;
            }
        }
    }
    return true;
}

} // namespace zawa::impl

namespace zawa {

std::vector<int> bipartite_judge(const std::vector<std::vector<int>>& G) {
    bool ok = true;    
    std::vector used(G.size(), false);
    std::vector colors(G.size(), -1);
    for (int i = 0 ; i < (int)G.size() ; i++) {
        if (!used[i]) {
            ok &= impl::dfs(G, i, 0, colors, used);
        }
    }
    if (ok) {
        return colors;
    }
    else {
        return std::vector<int>(G.size(), -1);
    }
}

template <class cost_type>
std::vector<int> bipartite_judge(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {
    std::vector tmp_G(G.size(), std::vector(0, 0));
    for (int i = 0 ; i < (int)G.size() ; i++) {
        for (auto [x, _] : G[i]) {
            tmp_G[i].push_back(x);
        }
    }
    return bipartite_judge(tmp_G);
}

} // namespace zawa
