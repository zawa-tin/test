#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

namespace zawa {

template <class monoid>
class squareDecomp {
private:
	using T = typename monoid::valueType;
	int square;
	std::vector<T> dat;
	std::vector<T> bucket;

	void update(int id) {
		T val = monoid::identity;
		int l = id * square;
		for (int i = 0 ; i < square and l + i < (int)dat.size()  ; i++) {
			val = monoid::operation(dat[l + i], val);
		}
		bucket[id] = val;
	}

public:
	squareDecomp(const std::vector<T>& A) : square(std::sqrt(A.size() + 1)), dat(A), bucket(((int)A.size() + square - 1) / square, monoid::identity)  {
		for (int i = 0 ; i < (int)dat.size() ; i++) {
			bucket[i / square] = monoid::operation(dat[i], bucket[i / square]);
		}
	}
	squareDecomp(int n) : square(std::sqrt(n + 1)), dat(n, monoid::identity), bucket((n + square - 1) / square, monoid::identity) {}

	void set(int i, const T& x) {
		dat[i] = x;
		update(i / square);
	}

	T update(int i, const T& x) {
		dat[i] = monoid::operation(dat[i], x);
		update(i / square);
		return dat[i];
	}

	T prod(int l, int r) const {
		T res = monoid::identity;
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (q <= l or r <= p) {
				continue;
			}
			if (l <= p and q <= r) {
				res = monoid::operation(res, bucket[i]);
			}
			else {
				for (int j = std::max(p, l) ; j < std::min({ (int)dat.size(), q, r }) ; j++) {
					res = monoid::operation(res, dat[j]);
				}
			}
		}
		return res;
	}

	inline std::vector<T> _dat() const {
		return dat;
	}
	
	inline std::vector<T> _bucket() const {
		return bucket;
	}

};

} // namespace zawa
