#pragma once

#include <vector>
#include <numeric>

namespace zawa {

template <class T>
struct accum1d : std::vector<T> {
	using vector = std::vector<T>;
	accum1d() {
		(*this).push_back(T());
	}
	accum1d(const std::vector<T>& A) {
		(*this).push_back(T());
		std::partial_sum(A.begin(), A.end(), std::back_inserter(*this));
	}	
	template <class InputIterator>
	accum1d(InputIterator begin, InputIterator end) {
		(*this).push_back(T());
		std::partial_sum(begin, end, std::back_inserter(*this));
	}
	T sum(std::size_t l, std::size_t r) {
		return (*this)[r] - (*this)[l];
	}
};

} // namespace zawa
