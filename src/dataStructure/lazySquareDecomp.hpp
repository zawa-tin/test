#pragma once

#include <vector>
#include <cmath>
#include <algorithm>

namespace zawa {

template <class structure>
class lazySquareDecomp {
	using V = typename structure::valueMonoid::valueType;
	using O = typename structure::operatorMonoid::valueType;

private:
	static constexpr V vId = structure::valueMonoid::identity;
	static constexpr O oId = structure::operatorMonoid::identity;
	struct node {
		V value;
		O lazy;
		node() : value(vId), lazy(oId) {}
	};
	int square;
	std::vector<V> dat;
	std::vector<node> bucket;

	void propagate(int pos) {
		int l = square * pos;
		for (int i = 0 ; i < square ; i++) {
			dat[l + i] = structure::mapping(dat[l + i], bucket[pos].lazy);	
		}
		bucket[pos].lazy = oId;
	}

	void update(int pos) {
		bucket[pos].value = vId;
		int l = square * pos;
		for (int i = 0 ; i < square and l + i < (int)dat.size() ; i++) {
			bucket[pos].value = structure::valueMonoid::operation(bucket[pos].value, dat[l + i]);
		}
	}
	
public:
	lazySquareDecomp(int n) : square(std::sqrt(n + 1)), dat(n, vId), bucket((n + square - 1) / square) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			bucket[i / square].value = structure::valueMonoid::operation(bucket[i / square].value, dat[i]);
		}
	}
	lazySquareDecomp(const std::vector<V>& A) : square(std::sqrt(A.size() + 1)), dat(A), bucket((A.size() + square - 1) / square) {
		for (std::size_t i = 0 ; i < dat.size() ; i++) {
			bucket[i / square].value = structure::valueMonoid::operation(bucket[i / square].value, dat[i]);
		}
	}

	void update(int pos, const O& value) {
		if (bucket[pos / square].lazy != oId) {
			propagate(pos / square);
		}
		dat[pos] = structure::mapping(dat[pos], value);
		update(pos / square);
	}	

	void update(int l, int r, const O& value) {	
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (r <= p or q <= l) {
				continue;
			}
			if (l <= p and q <= r) {
				bucket[i].lazy = structure::operatorMonoid::operation(bucket[i].lazy, value);
			}
			else {
				if (bucket[i].lazy != oId) {
					propagate(i);
				}
				for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {
					dat[j] = structure::mapping(dat[j], value);
				}
				update(i);
			}
		}
	}

	V prod(int l, int r) {
		V res = vId;
		for (int i = 0 ; i < (int)bucket.size() ; i++) {
			int p = i * square, q = (i + 1) * square;
			if (r <= p or q <= l) {
				continue;
			}
			if (l <= p and q <= r) {
				if (bucket[i].lazy != oId) {
					res = structure::valueMonoid::operation(res, structure::mapping(bucket[i].value, bucket[i].lazy));
				}
				else {
					res = structure::valueMonoid::operation(res, bucket[i].value);
				}
			}
			else {
				if (bucket[i].lazy != oId) {
					propagate(i);
					update(i);
				}
				for (int j = std::max(l, p) ; j < std::min({ q, r, (int)dat.size() }) ; j++) {
					res = structure::valueMonoid::operation(res, dat[j]);
				}
			}
		}
		return res;
	}
};

} // namespace zawa
