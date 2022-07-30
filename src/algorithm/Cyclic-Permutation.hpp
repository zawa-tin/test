#pragma once

#include <vector>
#include <algorithm>

namespace zawa {

    template <typename T>
    std::vector<std::vector<int>> decomp_cyclic_permutation(std::vector<T>& arr) {
        std::vector<std::pair<T, int>> cp(arr.size());
        for (int i = 0 ; i < (int)arr.size() ; i++) {
            cp[i] = {arr[i], i};
        }
        sort(cp.begin(), cp.end());

        std::vector<std::vector<int>> res;
        std::vector<int> used(arr.size());
        for (int i = 0 ; i < (int)arr.size() ; i++) {
            if (used[i]) continue;
            std::vector<int> cycle;
            int now = i;
            while(!used[now]) {
                cycle.emplace_back(now);
                used[now] = 1;
                now = cp[now].second;
            }
            res.emplace_back(cycle);
        }

        return res;
    }

}// namespace zawa
