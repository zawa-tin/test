#pragma once

#include <vector>

namespace zawa {

class connected_components {
private:
    std::vector<int> ids;
    std::vector<std::vector<int>> groups;    

    void dfs(std::size_t v, int id, std::vector<bool>& used, const std::vector<std::vector<int>>& G) {
        used[v] = true;
        ids[v] = id;
        for (auto x : G[v]) {
            if (!used[x]) {
                dfs(x, id, used, G);
            }
        }
    }

public:

    connected_components(const std::vector<std::vector<int>>& G) : ids(G.size(), -1) {
        std::vector used(G.size(), false);
        int id = -1;
        for (std::size_t i = 0 ; i < G.size() ; i++) {
            if (!used[i]) {
                dfs(i, ++id, used, G);
            }
        }
        groups = std::vector(id + 1, std::vector(0, 0));
        for (std::size_t i = 0 ; i < G.size() ; i++) {
            groups[ids[i]].push_back((int)i);
        }
    }

    int &operator [](int i) {
        return ids[i];
    }

    inline std::vector<std::vector<int>> &comps() {
        return groups;
    }

    inline std::vector<int> &comp(int id) {
        return groups[id];
    }

    bool same(int i, int j) {
        return ids[i] == ids[j];
    }
};

template <class cost_type>
connected_components weighted_cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {
    std::vector tmp_G(G.size(), std::vector(0, 0));
    for (std::size_t i = 0 ; i < G.size() ; i++) {
        for (auto x : G[i]) {
            tmp_G[i].push_back(x.first);
        }
    }
    return connected_components(tmp_G);
}

} // namespace zawa
