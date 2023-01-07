#pragma once

#include <vector>
#include <stack>

namespace zawa {

class connected_components {
private:
    std::vector<int> ids;
    std::vector<std::vector<int>> groups;    

	void build(const std::vector<std::vector<int>>& G) {
		int id = 0;
		for (int i = 0 ; i < (int)G.size() ; i++) {
			if (ids[i] == -1) {
				ids[i] = id;
				std::stack<int> stk({ i });		
				while (stk.size()) {
					int v = stk.top();
					stk.pop();
					for (auto x : G[v]) {
						if (ids[x] == -1) {
							ids[x] = id;
							stk.push(x);
						}
					}
				}
				id++;
			}
		}
		groups = std::vector(id, std::vector(0, 0));
		for (int i = 0 ; i < (int)ids.size() ; i++) {
			groups[ids[i]].push_back(i);
		}
	}

public:

    connected_components(const std::vector<std::vector<int>>& G) : ids(G.size(), -1) {
		build(G);
    }

	template <class cost_type>
	connected_components(const std::vector<std::vector<std::pair<int, cost_type>>>& G) : ids(G.size(), -1) {
		std::vector tmp_G(G.size(), std::vector(0, 0));
		for (int i = 0 ; i < (int)G.size() ; i++) {
			for (auto [x, _] : G[i]) {
				tmp_G[i].push_back(x);
			}
		}
		build(tmp_G);
	}

    int &operator [](int i) {
        return ids[i];
    }

	std::size_t size() {
		return groups.size();
	}

	std::size_t size(int x) {
		return groups[ids[x]].size();
	}

    const std::vector<std::vector<int>> &comps() {
        return groups;
    }

    const std::vector<int> &comp(int id) {
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
