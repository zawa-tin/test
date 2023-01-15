#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

namespace zawa {

template <class monoid>
class sq_decomp {
private:
	using T = typename monoid::T;
	int square;
	std::vector<T> dat;
	std::vector<T> bucket;

	void update(int id) {
		T val = monoid::id;
		int l = id * square;
		for (int i = 0 ; i < square and l + i < (int)dat.size()  ; i++) {
			val = monoid::op(dat[l + i], val);
		}
		bucket[id] = val;
	}

public:
	sq_decomp(const std::vector<T>& as) : square(std::sqrt(as.size() + 1)), dat(as), bucket(((int)as.size() + square - 1) / square, monoid::id)  {
		for (int i = 0 ; i < (int)dat.size() ; i++) {
			bucket[i / square] = monoid::op(dat[i], bucket[i / square]);
		}
	}
	sq_decomp(int n) : square(std::sqrt(n + 1)), dat(n, monoid::id), bucket((n + square - 1) / square, monoid::id) {}

	void update(int i, const T& x) {
		dat[i] = x;
		update(i / square);
	}

	T action(int i, const T& x) {
		dat[i] = monoid::op(dat[i], x);
		update(i / square);
		return dat[i];
	}

	T prod(int l, int r) {
		T res = monoid::id;
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (q <= l or r <= p) {
				continue;
			}
			if (l <= p and q <= r) {
				res = monoid::op(res, bucket[i]);
			}
			else {
				for (int j = std::max(p, l) ; j < std::min({ (int)dat.size(), q, r }) ; j++) {
					res = monoid::op(res, dat[j]);
				}
			}
		}
		return res;
	}

	std::vector<T> get_dat() {
		return dat;
	}
	
	std::vector<T> get_bucket(std::size_t i) {
		return bucket[i];
	}

};

};
