#pragma once

#include <algorithm>
#include <climits>

namespace zawa {

template <class dat_type>
struct maxplus_semiring {
	using T = dat_type;
	static constexpr T id_add = -std::numeric_limits<T>::max();
	static constexpr T id_mul = 0;
	static T add(const T& a, const T& b) {
		return std::max(a, b);
	}
	static T mul(const T& a, const T& b) {
		if (b > 0 or a > id_add - b) {
			return a + b;
		}
		else {
			return id_add;
		}
	}
};

} // namespace zawa
