#pragma once

#include <vector>
#include <stack>
#include <utility>

namespace zawa {

class bipartiteJudge {
private:
	std::vector<bool> colors;
	bool isBipartiteGraph;

	void build(const std::vector<std::vector<int>>& G) {
		if (G.empty()) {
			return;
		}
		std::stack<std::pair<int, bool>> S;
		std::vector<bool> used(G.size(), false);
		for (int i = 0 ; i < (int)G.size() ; i++) {
			if (!used[i]) {
				S.emplace(i, true);
				used[i] = true;
				colors[i] = true;
				while (S.size()) {
					auto [v, col] = S.top();
					S.pop();
					for (const auto& x : G[v]) {
						if (used[x]) {
							isBipartiteGraph &= colors[x] != col;
						}
						else {
							used[x] = true;
							colors[x] = !col;
							S.emplace(x, !col);
						}
					}
				}
			}
		}
	}

public:
	
	bipartiteJudge(const std::vector<std::vector<int>>& G) : colors(G.size()), isBipartiteGraph(true) {
		build(G);
	}

	template <class cost_type>
	bipartiteJudge(const std::vector<std::vector<std::pair<int, cost_type>>>& G) : colors(G.size()), isBipartiteGraph(true) {
		std::vector tmpG(G.size(), std::vector(0, 0));
		for (std::size_t i = 0 ; i < G.size() ; i++) {
			for (const auto& [x, _] : G[i]) {
				tmpG[i].push_back(x);
			}
		}
		build(tmpG);
	}

	inline const bool ok() const {
		return isBipartiteGraph;
	}

	inline bool operator[](int i) const {
		return colors[i];
	}
};

} // namespace zawa
