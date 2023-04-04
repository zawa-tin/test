#pragma once

#include <vector>
#include <utility>
#include <cassert>

namespace zawa {

template <class vertex, class edge>
class rerooting {
private:
	vertex identity;
	std::vector<edge> edges;
	std::vector<std::pair<int, int>> pos;
	std::vector<vertex> vertices;
	int edgeNum = 0;
	int N;

public:
	struct edgeInfo {
		int u, v;
		edge dat;
		edgeInfo(int _u, int _v, const edge& _dat) : u(_u), v(_v), dat(_dat) {}
	};

	rerooting(const vertex& _identity, std::size_t _N) 
		: identity(_identity), edges(_N - 1), pos(_N - 1), vertices(_N), N(_N) {
			assert(0 < _N);
	}	

	void addEdge(int u, int v, const edge& e) {
		assert(edgeNum < N - 1);
		assert(0 <= u and u < N);
		assert(0 <= v and v < N);
		pos[edgeNum] = { u, v };
		edges[edgeNum] = e;
		edgeNum++;
	}

	inline edgeInfo getEdge(int i) const {
		assert(i < edgeNum);
		return edgeInfo{ pos[i].first, pos[i].second, edges[i] };
	}

	inline vertex get(int i) const {
		assert(0 <= i and i < N);
		return vertices[i];
	}

	void changeEdge(int i, const edge& e) {
		assert(i < edgeNum);
		edges[i] = e;
	}

	void assign(int i, const vertex& v) {
		assert(0 <= i and i < N);
		vertices[i] = v;
	}

	template <class F1, class F2>
	std::vector<vertex> run(const F1& merge, const F2& walk) {
		assert(edgeNum == N - 1);
		std::vector<std::vector<std::pair<int, int>>> G(N);
		for (int i = 0 ; i < N - 1 ; i++) {
			const auto& [u, v] = pos[i];
			G[u].emplace_back(v, i);
			G[v].emplace_back(u, i);
		}
		auto dfs = [&](auto dfs, int v, int p) -> vertex {
			for (const auto& [x, i] : G[v]) if (x != p)
				vertices[v] = merge(vertices[v], walk(dfs(dfs, x, v), edges[i], x, v), x, v);
			return vertices[v];
		};
		dfs(dfs, 0, -1);
		std::vector<vertex> res(N, identity);
		auto reroot = [&](auto reroot, int v, int p, const vertex& propagating) -> void {
			std::vector<vertex> prefix(G[v].size() + 1, identity), suffix = prefix;
			for (int i = 0 ; i < (int)G[v].size() ; i++) {
				const auto& [x, j] = G[v][i];
				prefix[i + 1] = merge(prefix[i], walk((x == p ? propagating : vertices[x]), edges[j], x, v), x, v);
			}
			for (int i = (int)G[v].size() ; i > 0 ; i--) {
				const auto& [x, j] = G[v][i - 1];
				suffix[i - 1] = merge(suffix[i], walk((x == p ? propagating : vertices[x]), edges[j], x, v), x, v);
			}
			res[v] = prefix.back();
			for (int i = 0 ; i < (int)G[v].size() ; i++) {
				auto [x, _] = G[v][i];
				if (x != p) reroot(reroot, x, v, merge(prefix[i], suffix[i + 1], x, v));
			}
		};
		reroot(reroot, 0, -1, identity);
		return res;
	}
};

} // namespace zawa
