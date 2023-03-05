#pragma once

#include <vector>
#include <cassert>

namespace zawa {

template <class monoid>
class dualSegmentTree {
private:
	using O = typename monoid::value_type;
	int N;
	std::vector<O> dat;

	constexpr int left(int v) const {
		return v << 1;
	}

	constexpr int right(int v) const {
		return v << 1 | 1;
	}

	constexpr int parent(int v) const {
		return v >> 1;
	}

	inline void propagate(int v) {
		if (left(v) < (int)dat.size()) {
			dat[left(v)] = monoid::operation(dat[left(v)], dat[v]);
		}
		if (right(v) < (int)dat.size()) {
			dat[right(v)] = monoid::operation(dat[right(v)], dat[v]);
		}
		dat[v] = monoid::identity;
	}

	void push(int v) {
		int height = 31 - __builtin_clz(v);
		for (int i = height ; i >= 1 ; i--) {
			propagate(v >> i);
		}
	}

public:
	dualSegmentTree() {}
	dualSegmentTree(int _N) : N(_N), dat(_N << 1, monoid::identity) {}
	dualSegmentTree(const std::vector<O>& A) : N((int)A.size()), dat(A.size() << 1, monoid::identity) {
		for (int i = 0 ; i < (int)A.size() ; i++) {
			dat[i + N] = A[i];
		}
	}

	O operator[](int i) {
		assert(0 <= i and i < N);
		i += N;
		push(i);
		return dat[i];
	}

	void set(int i, const O& value) {
		assert(0 <= i and i < N);
		i += N;
		push(i);
		dat[i] = value;
	}

	void update(int i, const O& value) {
		assert(0 <= i and i < N);
		i += N;
		push(i);
		dat[i] = monoid::operation(dat[i], value);
	}

	void update(int l, int r, const O& value) {
		assert(0 <= l and l < N);
		assert(l <= r and r <= N);
		if (l == r) {
			return;
		}
		l += N; r += N;
		push(l); push(r - 1);
		for ( ; l < r ; l = parent(l), r = parent(r)) {
			if (l & 1) {
				dat[l] = monoid::operation(dat[l], value);
				l++;
			}
			if (r & 1) {
				r--;
				dat[r] = monoid::operation(dat[r], value);
			}
		}
	}

	inline std::vector<O> _dat() const {
		return dat;
	}
};

} // namespace 
