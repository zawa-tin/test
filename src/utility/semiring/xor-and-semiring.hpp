#pragma once

namespace zawa {

template <class dat_type>
struct xorand_semiring {
	using T = dat_type;
	static constexpr T id_add = 0;
	static constexpr T id_mul = (~0);
	static T add(const T& a, const T& b) {
		return (a ^ b);
	}
	static T mul(const T& a, const T& b) {
		return (a & b);
	}
};

} // namespace zawa
