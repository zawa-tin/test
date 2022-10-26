#pragma once

#include <vector>
#include <iostream>

namespace zawa {

std::vector<std::vector<int>> readGraph(int n, int m, bool undirect = true, bool minus = true) {
    std::vector<std::vector<int>> res(n, std::vector(0, 0));
    for (int _ = 0 ; _ < m ; _++) {
        int u, v;
        std::cin >> u >> v;
        res[u - minus].emplace_back(v - minus);
        if (undirect) {
            res[v - minus].emplace_back(u - minus);
        }
    }
    return res;
}

std::vector<std::vector<int>> readTree(int n, bool undirect = true, bool minus = true) {
    return readGraph(n, n - 1, undirect, minus);
}

}
