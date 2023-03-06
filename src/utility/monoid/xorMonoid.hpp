#pragma once

namespace zawa {

template <class T>
struct xorMonoid {
	using value_type = T;
	static constexpr value_type identity{};
	static value_type operation(const value_type& a, const value_type& b) {
		return (a ^ b);
	}
};

} // namespace zawa
