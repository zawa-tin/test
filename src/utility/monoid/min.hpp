#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class T>
struct min_monoid {
	using value_type = T;
	static constexpr T identity = std::numeric_limits<T>::max();
	static T operation(const T& a, const T& b) {
		return std::min(a, b);
	}
};

};
