#pragma once

#include <vector>
#include <queue>

namespace zawa {

class topo_sort {
private:
	std::vector<int> sorted;
	bool is_dag;

	bool build(const std::vector<std::vector<int>>& G) {
		std::vector<int> ins(G.size(), 0);
		for (const auto& g : G) {
			for (auto x : g) {
				ins[x]++;
			}
		}
		std::queue<int> que;
		for (int i = 0 ; i < (int)ins.size() ; i++) {
			if (ins[i] == 0) {
				que.push(i);
			}
		}
		while (que.size()) {
			int v = que.front();
			que.pop();
			sorted.push_back(v);
			for (auto x : G[v]) {
				ins[x]--;
				if (ins[x] == 0) {
					que.push(x);
				}
			}
		}
		return sorted.size() == G.size();
	}

public:
	topo_sort(const std::vector<std::vector<int>>& G) {
		is_dag = build(G);	
	}

	template <class cost_type>
	topo_sort(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {
		std::vector tmp_G(G.size(), std::vector(0, 0));
		for (int i = 0 ; i < (int)G.size() ; i++) {
			for (auto [x, _] : G[i]) {
				tmp_G[i].push_back(x);
			}
		}
		is_dag = build(tmp_G);
	}

	int operator [](int i) {
		return sorted[i];
	}
	
	std::vector<int> get() {
		return sorted;
	}

	bool ok() {
		return is_dag;	
	}
};

}// namespace zawa
