#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

namespace zawa {

template <class structure>
class lazy_sqdecomp {
	using T = typename structure::value_monoid::value_type;
	using S = typename structure::operator_monoid::value_type;

private:
	static constexpr T T_id = structure::value_monoid::identity;
	static constexpr S S_id = structure::operator_monoid::identity;
	struct node {
		T value;
		S lazy;
		node() : value(T_id), lazy(S_id) {}
	};
	int square;
	std::vector<T> dat;
	std::vector<node> bucket;

	void propagate(int pos) {
		int l = square * pos;
		for (int i = 0 ; i < square ; i++) {
			dat[l + i] = structure::mapping(dat[l + i], bucket[pos].lazy);	
		}
		bucket[pos].lazy = S_id;
	}

	void update(int pos) {
		bucket[pos].value = T_id;
		int l = square * pos;
		for (int i = 0 ; i < square and l + i < (int)dat.size() ; i++) {
			bucket[pos].value = structure::value_monoid::operation(bucket[pos].value, dat[l + i]);
		}
	}
	
public:
	lazy_sqdecomp(int n) : square(std::sqrt(n + 1)), dat(n, T_id), bucket((n + square - 1) / square) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			bucket[i / square].value = structure::value_monoid::operation(bucket[i / square].value, dat[i]);
		}
	}
	lazy_sqdecomp(const std::vector<T>& A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1) / square) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			bucket[i / square].value = structure::value_monoid::operation(bucket[i / square].value, dat[i]);
		}
	}

	void update(int pos, const S& value) {
		if (bucket[pos / square].lazy != S_id) {
			propagate(pos / square);
		}
		dat[pos] = structure::mapping(dat[pos], value);
		update(pos / square);
	}	

	void update(int l, int r, const S& value) {	
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (r <= p or q <= l) {
				continue;
			}
			if (l <= p and q <= r) {
				bucket[i].lazy = structure::operator_monoid::operation(bucket[i].lazy, value);
			}
			else {
				if (bucket[i].lazy != S_id) {
					propagate(i);
				}
				for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {
					dat[j] = structure::mapping(dat[j], value);
				}
				update(i);
			}
		}
	}

	T prod(int l, int r) {
		T res = T_id;
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (r <= p or q <= l) {
				continue;
			}
			if (l <= p and q <= r) {
				if (bucket[i].lazy != S_id) {
					res = structure::value_monoid::operation(res, structure::mapping(bucket[i].value, bucket[i].lazy));
				}
				else {
					res = structure::value_monoid::operation(res, bucket[i].value);
				}
			}
			else {
				if (bucket[i].lazy != S_id) {
					propagate(i);
					update(i);
				}
				for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {
					res = structure::value_monoid::operation(res, dat[j]);
				}
			}
		}
		return res;
	}
};

} // namespace zawa
