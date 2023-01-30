#pragma once

#include "../utility/fenwick_tree/add.hpp"
#include "fenwick_tree.hpp"

#include <vector>
#include <algorithm>

namespace zawa {

template <class T>
class fenwick_multiset {
private:
	std::vector<T> dat;
	fenwick_tree<add_structure<T>> fen;

public:

	fenwick_multiset(std::size_t n) : dat(n), fen(n) {}

	T count(int x) {
		return dat[x];
	}

	T count(int l, int r) {
		return fen.sum(l, r);
	}

	void insert(int x) {
		dat[x] += 1;
		fen.add(x, 1);
	}

	void insert(int x, const T& cnt) {
		dat[x] += cnt;
		fen.add(x, cnt);
	}

	T erase(int x) {
		if (dat[x]) {
			dat[x] -= 1;
			fen.add(x, -1);
			return 1;
		}
		else {
			return 0;
		}
	}

	T erase(int x, const T& cnt) {
		T res = std::min(dat[x], cnt);	
		dat[x] -= res;
		fen.add(x, -res);
		return res;
	}

	int kth_element(const T& k) {
		return fen.lower_bound(k);
	}
};

} // namespace zawa
