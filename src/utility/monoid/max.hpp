#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class T>
struct max_monoid {
	using value_type = T;
	static constexpr T identity = std::numeric_limits<T>::min();
	static T operation(const T& a, const T& b) {
		return std::max(a, b);
	}
};

};
