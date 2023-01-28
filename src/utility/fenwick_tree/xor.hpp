#pragma once

namespace zawa {

template <class dat_type>
struct xor_structure {
	using T = dat_type;
	static constexpr T id{};
	static T add(const T& a, const T& b) {
		return a ^ b;
	}
	static T inverse(const T& a) {
		return a;
	}
};

} // namespace zawa
