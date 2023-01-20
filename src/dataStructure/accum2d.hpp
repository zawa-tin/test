#pragma once

#include <vector>
#include <utility>

namespace zawa {

template <class T>
struct accum2d : std::vector<std::vector<T>> {
	accum2d() {
		(*this).push_back({ T() });
	}
	accum2d(const std::vector<std::vector<T>>& A) : std::vector<std::vector<T>>(A.size() + 1, std::vector<T>(A[0].size() + 1, T())) {
		for (std::size_t i = 0 ; i < A.size() ; i++) {
			for (std::size_t j = 0 ; j < A[i].size() ; j++) {
				(*this)[i + 1][j + 1] = (*this)[i][j + 1] + (*this)[i + 1][j] - (*this)[i][j] + A[i][j];
			}
		}
	}
	T sum(std::size_t y1, std::size_t x1, std::size_t y2, std::size_t x2) {
		return (*this)[y2][x2] - (*this)[y1][x2] - (*this)[y2][x1] + (*this)[y1][x1];
	}
	T sum(std::pair<std::size_t, std::size_t> p1, std::pair<std::size_t, std::size_t> p2) {
		return sum(p1.first, p1.second, p2.first, p2.second);
	}
};

} // namespace zawa
