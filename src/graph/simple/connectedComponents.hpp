#pragma once

#include <vector>
#include <stack>

namespace zawa {

class connectedComponents {
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

	connectedComponents(const std::vector<std::vector<int>>& G) : ids(G.size(), -1) {
		build(G);
	}

	template <class cost_type>
	connectedComponents(const std::vector<std::vector<std::pair<int, cost_type>>>& G) : ids(G.size(), -1) {
		std::vector tmpG(G.size(), std::vector(0, 0));
		for (int i = 0 ; i < (int)G.size() ; i++) {
			for (auto [x, _] : G[i]) {
				tmpG[i].push_back(x);
			}
		}
		build(tmpG);
	}

	inline int operator [](int i) const {
		return ids[i];
	}

	inline std::size_t size() const {
		return groups.size();
	}

	inline std::size_t size(int x) const {
		return groups[ids[x]].size();
	}

	inline std::vector<std::vector<int>> comps() const {
		return groups;
	}

	inline std::vector<int> comp(int id) const {
		return groups[id];
	}

	bool same(int i, int j) const {
		return ids[i] == ids[j];
	}
};

} // namespace zawa
