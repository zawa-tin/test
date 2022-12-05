#pragma once

#include <vector>
#include <utility>

namespace zawa {

template <class cost_type>
class potentialized_unionfind {
private:
    std::vector<int> parents;
    std::vector<int> sizes;
    std::vector<cost_type> weights;

    int rooting(int x) {
        if (parents[x] == x) {
            return x;
        }
        else {
            int root = rooting(parents[x]);
            weights[x] += weights[parents[x]];
            return parents[x] = root;
        }
    }

    cost_type get_weight(int x) {
        rooting(x);
        return weights[x];
    }

public:

    potentialized_unionfind(std::size_t n) : parents(n, 0), sizes(n, 1), weights(n) {
        for (std::size_t i = 0 ; i < n ; i++) {
            parents[i] = i;
        }
    }

    int leader(int x) {
        return rooting(x);
    }

    bool same(int x, int y) {
        return rooting(x) == rooting(y);
    }

    bool merge(int x, int y, cost_type w) {
        w += get_weight(x);
        w -= get_weight(y);
        int rx = rooting(x), ry = rooting(y);
        if (rx == ry) {
            return false;
        }
        if (sizes[rx] < sizes[ry]) {
            std::swap(rx, ry);
            w *= -1;
        }
        sizes[rx] += sizes[ry];
        parents[ry] = rx;
        weights[ry] = w;
        return true;
    }

    cost_type diff(int y, int x) {
        return get_weight(y) - get_weight(x);
    }
};

} // namespace zawa
