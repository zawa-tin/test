#pragma once

#include <vector>
#include <stack>

namespace zawa {

class topological_sort {
private:
	std::vector<std::vector<int>> G;
	std::vector<int> Ord;
	bool is_dag;

	bool build() {
		std::vector<int> In(G.size(), 0);
		for (std::size_t i = 0 ; i < G.size() ; i++) {
			for (const auto& v : G[i]) {
				In[v]++;
			}
		}
		std::stack<int> S;
		for (std::size_t i = 0 ; i < G.size() ; i++) {
			if (!In[i]) {
				S.push(i);
			}
		}
		while (S.size()) {
			int v = S.top();
			S.pop();
			Ord.push_back(v);
			for (auto x : G[v]) {
				In[x]--;
				if (!In[x]) {
					S.push(x);
				}
			}
		}
		return Ord.size() == G.size();
	}

public:
	topological_sort(const std::vector<std::vector<int>>& _G) : G(_G), is_dag(build()) {}	

	template <class cost_type>
	topological_sort(const std::vector<std::vector<std::pair<int, cost_type>>>& _G) :  G(_G.size()) {
		for (std::size_t i = 0 ; i < _G.size() ; i++) {
			for (auto [v, _] : _G[i]) {
				G[i].push_back(v);
			}
		}	
		is_dag = build();
	}

	inline bool ok() const {
		return is_dag;
	}

	int operator[](int i) {
		return Ord[i];
	}

	inline std::vector<int> get() const {
		return Ord;
	}

	bool unique() const {
		if (!is_dag) {
			return false;
		}
		bool res = true;
		for (std::size_t i = 0 ; i + 1 < G.size() ; i++) {
			bool ok = false;
			for (const auto& v : G[Ord[i]]) {
				ok |= v == Ord[i + 1];
			}
			res &= ok;
		}
		return res;
	}
};

} // namespace zawa
