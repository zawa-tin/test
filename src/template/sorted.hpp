#pragma once

#include <vector>
#include <algorithm>
#include <string>

namespace zawa::util {

template <class T>
std::vector<T> sorted(std::vector<T> A) {
	std::sort(A.begin(), A.end());
	return A;
}

std::string sorted(std::string s) {
	std::sort(s.begin(), s.end());
	return s;
}

} // namespace zawa::util
