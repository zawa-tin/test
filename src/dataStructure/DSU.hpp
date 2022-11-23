#pragma once

#include <vector>
#include <utility>
#include <algorithm>

namespace zawa {

class DSU {
private:
    std::vector<int> parents;
    std::vector<int> sizes;

public:
    DSU(std::size_t n) : parents(n, 0), sizes(n, 1) {
        for (std::size_t i = 0 ; i < n ; i++) {
            parents[i] = i;
        }
    }

    int leader(int x) {
        if (x == parents[x]) {
            return x;
        }
        else {
            return parents[x] = leader(parents[x]);
        }
    }

    bool same(int x, int y) {
        return leader(x) == leader(y);
    }

    void merge(int x, int y) {
        if (leader(x) == leader(y)) {
            return;
        }
        if (sizes[leader(x)] < sizes[leader(y)]) {
            std::swap(x, y);
        }
        sizes[leader(x)] += sizes[leader(y)]; 
        parents[leader(y)] = leader(x);
    }

    inline int size(int x) {
        return sizes[leader(x)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector res(parents.size(), std::vector(0, 0));
        for (int i = 0 ; i < (int)parents.size() ; i++) {
            res[leader(i)].push_back(i);
        }
        res.erase(std::remove_if(res.begin(), res.end(), 
                    [](std::vector<int> x) { return x.empty(); }), res.end());
        return res;
    }
};

}// namespace zawa
