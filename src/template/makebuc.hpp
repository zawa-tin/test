#pragma once

#include <vector>
#include <string>

namespace zawa {

template <class T>
std::vector<int> makebuc(const std::vector<T>& A, const T& sup) {
	std::vector<int> res(sup, 0);
	for (const auto& a : A) {
		res[a]++;
	}
	return res;
}

std::vector<int> makebuc(const std::string& S, bool lower = true) {
	std::vector<int> res(26, 0);
	int minus = (lower ? (int)'a' : (int)'A');
	for (const auto& c : S) {
		res[c - minus]++;
	}
	return res;
}

} // namespace zawa
