#pragma once

namespace zawa {

template <class T>
struct bitwiseOrStructure {
	using valueType = T;
	static valueType operation(const valueType& a, const valueType& b) {
		return (a | b);
	}
};

} // namespace zawa
