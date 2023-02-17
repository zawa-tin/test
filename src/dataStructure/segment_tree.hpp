#pragma once

#include <vector>
#include <functional>

namespace zawa {

template <class monoid>
class segment_tree {
private:
	using T = typename monoid::value_type;
	std::size_t N;
	std::vector<T> dat;

public:
	segment_tree() {}
	segment_tree(int _N) : N(_N), dat(2 * _N, monoid::identity) {}
	segment_tree(const std::vector<T>& A) : N(A.size()), dat(2 * N, monoid::identity) {
		for (std::size_t i = 0 ; i < A.size() ; i++) {
			dat[i + N] = A[i];
		}
		for (std::size_t i = N - 1 ; i > 0 ; i--) {
			dat[i] = monoid::operation(dat[i << 1], dat[i << 1 | 1]);		
		}
	}

	void set(std::size_t pos, const T& value) {
		pos += N;
		dat[pos] = value;
		while (pos >>= 1) {
			dat[pos] = monoid::operation(dat[pos << 1], dat[pos << 1 | 1]);
		}
	}

	T action(std::size_t pos, const T& value) {
		pos += N;
		do {
			dat[pos] = monoid::operation(dat[pos], value);
		} while (pos >>= 1);
		return dat[pos];
	}

	T prod(std::size_t l, std::size_t r) const {
		T left = monoid::identity, right = monoid::identity;
		for (l += N, r += N ; l < r ; l >>= 1, r >>= 1) {
			if (l & 1) {
				left = monoid::operation(left, dat[l++]);	
			}
			if (r & 1) {
				right = monoid::operation(dat[--r], right);
			}
		}
		return monoid::operation(left, right);
	}

	template <class function_type>
	int max_right(int l, const function_type& f) const {
		int L = l + N, w = 1;
		T v = monoid::identity;
		for ( ; l + w <= (int)N ; L >>= 1, w <<= 1) {
			if (L & 1) {
			   	if (f(monoid::operation(v, dat[L]))) {
					v = monoid::operation(v, dat[L++]);
					l += w;
				}
				else {
					break;
				}
			}
		}
		while (L <<= 1, w >>= 1) {
			if (l + w <= (int)N and f(monoid::operation(v, dat[L]))) {
				v = monoid::operation(v, dat[L++]);
				l += w;
			}
		}
		return l;
	}

	template <class function_type>
	int min_left(int r, const function_type& f) const {	
		int R = r + N, w = 1;
		T v = monoid::identity;
		for ( ; r - w >= 0 ; R >>= 1, w <<= 1) {
			if (R & 1) {
				if (f(monoid::operation(dat[R - 1], v))) {
					v = monoid::operation(dat[--R], v);
					r -= w;
				}
				else {
					break;
				}
			}
		}
		while (R <<= 1, w >>= 1) {
			if (r - w >= 0 and f(monoid::operation(dat[R - 1], v))) {
				v = monoid::operation(dat[--R], v);
				r -= w;
			}
		}
		return r;
	}	
};

} // namespace zawa
