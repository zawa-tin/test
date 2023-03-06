#pragma once

#include <algorithm>

namespace zawa {

template <class T>
struct maxStructure {
	using valueType = T;
	static valueType operation(const valueType& a, const valueType& b) {
		return std::max(a, b);
	}
};

} // namespace zawa
