#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class T>
struct maxMonoid {
	using valueType = T;
	static constexpr valueType identity = std::numeric_limits<valueType>::min();
	static valueType operation(const valueType& a, const valueType& b) {
		return std::max(a, b);
	}
};

};
