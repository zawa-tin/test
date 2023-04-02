#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <cassert>

namespace zawa {

class disjointSetUnion {
private:
	std::vector<int> parents;
	std::vector<int> sizes;

public:
	disjointSetUnion(std::size_t n) : parents(n, 0), sizes(n, 1) {
		std::iota(parents.begin(), parents.end(), 0);
	}

	int leader(int x) {
		assert(0 <= x and x < (int)parents.size());
		return (parents[x] == x ? x : parents[x] = leader(parents[x]));
	}

	bool same(int x, int y) {
		return leader(x) == leader(y);
	}

	void merge(int x, int y) {
		int lx = leader(x), ly = leader(y);
		if (lx == ly) return;
		if (sizes[lx] < sizes[ly]) std::swap(lx, ly);
		sizes[lx] += sizes[ly]; 
		parents[ly] = lx;
	}

	int size(int x) {
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
