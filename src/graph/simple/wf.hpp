#pragma once

#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

namespace zawa {

template <class cost_type>
std::vector<std::vector<cost_type>> wf(const std::vector<std::vector<std::pair<int, cost_type>>>& G, cost_type inf = std::numeric_limits<cost_type>::max() / 3) {
    std::vector res(G.size(), std::vector(G.size(), inf));
    for (std::size_t i = 0 ; i < G.size() ; i++) {
        res[i][i] = 0;
    }
    for (std::size_t i = 0 ; i < G.size() ; i++) {
        for (auto [x, w] : G[i]) {
            res[i][x] = std::min(res[i][x], w);
        }
    }
    for (std::size_t k = 0 ; k < G.size() ; k++) {
        for (std::size_t i = 0 ; i < G.size() ; i++) {
            for (std::size_t j = 0 ; j < G.size() ; j++) {
                res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }
    return res;
}

} // namespace zawa
