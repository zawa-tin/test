#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class dat_type>
struct min_monoid {
	using T = dat_type;
	static constexpr T id = std::numeric_limits<T>::max();
	static T op(const T& a, const T& b) {
		return std::min(a, b);
	}
};

};
