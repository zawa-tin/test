#pragma once

#include <vector>
#include <algorithm>
#include <string>

namespace zawa::util {

template <class T>
std::vector<T> reversed(std::vector<T> A) {
	std::reverse(A.begin(), A.end());
	return A;
}

std::string reversed(std::string s) {
	std::reverse(s.begin(), s.end());
	return s;
}

} // namespace zawa::util
