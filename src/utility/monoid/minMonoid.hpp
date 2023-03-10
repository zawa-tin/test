#pragma once

#include <algorithm>
#include <limits>

namespace zawa {

template <class T>
struct minMonoid {
	using valueType = T;
	static constexpr valueType identity = std::numeric_limits<valueType>::max();
	static valueType operation(const valueType& a, const valueType& b) {
		return std::min(a, b);
	}
};

};
