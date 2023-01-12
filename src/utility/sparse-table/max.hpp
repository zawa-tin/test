#pragma once

#include <algorithm>

namespace zawa {

template <class dat_type>
struct max_structure {
	using T = dat_type;
	static T op(T a, T b) {
		return std::max(a, b);
	}
};

} // namespace zawa
