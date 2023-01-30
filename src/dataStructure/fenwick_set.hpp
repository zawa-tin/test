#pragma once

#include "../utility/fenwick_tree/add.hpp"
#include "fenwick_tree.hpp"

#include <vector>

namespace zawa {

class fenwick_set {
private:
	std::vector<bool> dat;
	fenwick_tree<add_structure<int>> fen;

public:
	fenwick_set(std::size_t n) : dat(n, false), fen(n) {}

	bool contain(int x) {
		return dat[x];
	}

	void insert(int x) {
		if (!dat[x]) {
			dat[x] = true;
			fen.add(x, 1);
		}
	}

	int count(int l, int r) {
		return fen.sum(l, r);
	}

	bool erase(int x) {
		if (dat[x]) {
			dat[x] = false;
			fen.add(x, -1);
			return true;
		}
		else {
			return false;
		}
	}	

	int kth_element(int k) {
		return fen.lower_bound(k);
	}
};

};
