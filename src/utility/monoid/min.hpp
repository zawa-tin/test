#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class dat_type>
class min_monoid {
	using T = dat_type;
	static constexpr T id = std::numeric_limits<T>::min();
	static T op(const T& a, const T& b) {
		return std::min(a, b);
	}
};

};
