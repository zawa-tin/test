#pragma once

#include <algorithm>

namespace zawa {

template <class dat_type>
struct min_structure {
	using T = dat_type;
	static T op(T a, T b) {
		return std::min(a, b);
	}
};

} // namespace zawa
