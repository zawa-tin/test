#pragma once

namespace zawa {

template <class dat_type>
struct bitwise_and_structure {
	using T = dat_type;
	static T op(T a, T b) {
		return (a & b);
	}
};

} // namespace zawa
