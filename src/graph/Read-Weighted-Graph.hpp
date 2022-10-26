#pragma once

#include <utility>
#include <vector>
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
