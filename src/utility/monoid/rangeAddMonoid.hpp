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
struct rangeAddMonoid {
	using valueType = dat<T>;
	static constexpr valueType identity{};
	static valueType operation(const valueType& a, const valueType& b) {
		return valueType(a.value + b.value, a.size + b.size);
	}
};

} // namespace zawa
