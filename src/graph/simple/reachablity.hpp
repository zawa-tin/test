#pragma once

#include <vector>
#include <stack>
#include <utility>

namespace zawa {

bool reachability(const std::vector<std::vector<int>>& G, int from, int to) {
	std::stack<int> stk;
	std::vector visited(G.size(), false);
	visited[from] = true;
	stk.emplace(from);
	while (stk.size()) {
		int v = stk.top();
		stk.pop();
		if (v == to) {
			return true;
		}
		for (const auto& x : G[v]) {
			if (!visited[x]) {
				visited[x] = true;
				stk.emplace(x);
			}
		}
	}
	return false;
}

template <class cost_type>
bool reachability(const std::vector<std::vector<std::pair<int, cost_type>>>& G, int from, int to) {
	std::vector tmp(G.size(), std::vector(0, 0));
	for (int i = 0 ; i < (int)G.size() ; i++) {
		for (auto [x, _] : G[i]) {
			tmp[i].emplace(x);
		}
	}
	return reachability(tmp, from, to);
}

} // namespace zawa
