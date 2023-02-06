#pragma once

#include <cstddef>

namespace zawa {

template <class T>
struct dat {
	T value;
	std::size_t size;
	constexpr dat(const T& value = 0, const std::size_t& size = 0ULL) : value(value), size(size) {}
};

template <class T>
struct range_add_monoid {
	using value_type = dat<T>;
	static constexpr value_type identity{};
	static value_type operation(const value_type& a, const value_type& b) {
		return value_type(a.value + b.value, a.size + b.size);
	}
};

} // namespace zawa
