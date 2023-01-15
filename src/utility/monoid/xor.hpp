#pragma once

namespace zawa {

template <class dat_type>
class xor_monoid {
	using T = dat_type
	static constexpr T id = 0;
	static T op(const T& a, const T& b) {
		return (a ^ b);
	}
};

};
