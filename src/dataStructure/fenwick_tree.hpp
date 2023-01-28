#pragma once

#include <vector>

namespace zawa {

template <class structure>
class fenwick_tree {
private:
	using T = typename structure::T;
	std::vector<T> dat;
	int pow_two;

	inline int lsb(int x) {
		return x & -x;
	}

	T sum(int r) {
		T res = 0;
		while (r > 0) {
			res = structure::add(res, dat[r]);
			r -= lsb(r);
		}
		return res;
	}
	
public:

	fenwick_tree(std::size_t n) : dat(n + 1, structure::id), pow_two(std::__lg(n) + 1) {}
	
	fenwick_tree(const std::vector<T>& A) : dat(A.size() + 1, structure::id), pow_two(std::__lg(A.size()) + 1) {
		for (int i = 0 ; i < (int)A.size() ; i++) {
			add(i, A[i]);
		}
	}


	T sum(int l, int r) {
		return structure::add(sum(r), structure::inverse(sum(l)));
	}

	void add(int pos, const T& v) {
		pos++;
		while (pos < (int)dat.size()) {
			dat[pos] = structure::add(dat[pos], v);
			pos += lsb(pos);
		}
	}

	int lower_bound(T val) {
		int res = 0;
		T now = structure::id;
		for (int x = (1 << pow_two) ; x > 0 ; x >>= 1) {
			if (res + x < (int)dat.size()) {
				T nxt = structure::add(now, dat[res + x]);
				if (nxt < val) {
					res += x;
					now = nxt;
				}
			}
		}
		return res;
	}
};

} // namespace zawa
